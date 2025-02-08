%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

extern int yylex();
extern FILE* yyin;
int line_number;

FILE* asm_out;
char* filename;
int label_count = 0;
#define MAX 1000
char declarations[MAX][MAX], sourceCode[MAX][MAX], imports[MAX][MAX];
int lenDeclarations = 0, lenSourceCode = 0, lenImports = 0;

char expressions[MAX][MAX];
int lenExpressions = 0;

bool found(char col[][MAX], int n, char* var);
void parseExpression(char* element);
void printImports();
void printDeclarationSegment();
void printCodeSegment();

char if_body[MAX][MAX];
char else_body[MAX][MAX];
int lenIfBody = 0, lenElseBody = 0;

#define MAX_LABELS 100
char label_stack[MAX_LABELS][20];
int label_top = -1;

void push_label(const char* label) {
    if (label_top < MAX_LABELS - 1) {
        strcpy(label_stack[++label_top], label);
    } else {
        fprintf(stderr, "Label stack overflow!\n");
        exit(1);
    }
}

char* pop_label() {
    if (label_top >= 0) {
        return label_stack[label_top--];
    } else {
        fprintf(stderr, "Label stack underflow!\n");
        exit(1);
    }
}

char* peek_label() {
    if (label_top >= 0) {
        return label_stack[label_top];
    } else {
        return NULL;
    }
}

void insertSourceCode(int index, const char* instruction) {
    if (lenSourceCode >= MAX) {
        fprintf(stderr, "Source code array overflow!\n");
        exit(EXIT_FAILURE);
    }

    if (index < 0 || index > lenSourceCode) {
        fprintf(stderr, "Error: Invalid index %d for source code insertion!\n", index);
        return;
    }

    if (instruction == NULL || strlen(instruction) == 0) {
        return;
    }

    for (int i = lenSourceCode; i > index; i--) {
        strcpy(sourceCode[i], sourceCode[i - 1]);
    }

    strcpy(sourceCode[index], instruction);
    lenSourceCode++;
}


void yyerror(const char* s) {
    fprintf(stderr, "Syntax error: %s at line %d\n", s, line_number);
    exit(1);
}


%}


%union {
    char* strval;
   
}



%token <strval> ID CONST_STRING
%token <strval> CONST_INT
%token REL_OP CIN COUT IF ELSE WHILE RETURN ENDL
%token INT FLOAT STRING CHAR VOID
%token ASSIGN
%token LBRACE RBRACE LPAREN RPAREN SEMICOLON DO
%token PLUS MINUS MULTIPLY DIVIDE MODULO
%token GT LT GE LE EQ NE INCLUDE IO_STREAM MATH_H DOT RSHIFT LSHIFT
%token <strval> CONST_FLOAT
%type <strval> arithmetic_expression term 
%type <strval> return_statement
%type <strval> body
%type <strval> if_body condition


%%

program
    : header declaration_or_function_list
    ;

header
    : library_inclusions
    ;

library_inclusions
    : INCLUDE IO_STREAM
    | INCLUDE MATH_H
    ;

declaration_or_function_list
    : declaration_or_function_list declaration_or_function
    | declaration_or_function
    ;

declaration_or_function
    : function
    | variable_declaration
 
    ;


variable_declaration
    : simple_type ID SEMICOLON
    {
        char temp[1000];
        sprintf(temp, "\t%s times 4 db 0", $2);
        if (!found(declarations, lenDeclarations, temp)) {
            strcpy(declarations[lenDeclarations++], temp);
        }
    }
    ;

function
    : simple_type ID LPAREN parameter_list RPAREN body
    {
        // char func[100];
        // sprintf(func, "global %s\n%s:", $2, $2);
        // strcpy(sourceCode[lenSourceCode++], func);
    }
    ;

parameter_list
    : parameter_list ',' parameter
    | parameter
    | /* epsilon */
    ;

parameter
    : simple_type ID
    ;

body
    : LBRACE instruction_list RBRACE
    {
        $$=strdup("");
    }
    ;

instruction_list
    : instruction_list instruction
    | instruction
    ;

instruction
    : variable_declaration
    | assignment
    | input_instruction
    | output_instruction
    | if_statement
    | return_statement
    ;

input_instruction
    : CIN RSHIFT ID SEMICOLON
    {
        if (!found(imports, lenImports, "scanf")) {
            strcpy(imports[lenImports++], "scanf");
        }
        char input[100];
        sprintf(input, "push dword %s\n\tpush dword format\n\tcall scanf\n\tadd esp, 8\n", $3);
        strcpy(sourceCode[lenSourceCode++], input);
    }
    ;

output_instruction
    : COUT LSHIFT arithmetic_expression SEMICOLON
    {
        if (!found(imports, lenImports, "printf")) {
            strcpy(imports[lenImports++], "printf");
        }

        // Load the expression result into eax
        parseExpression(NULL);
    lenExpressions = 0;
        // Generate the printf call
        sprintf(sourceCode[lenSourceCode++], "push dword eax");
        sprintf(sourceCode[lenSourceCode++], "push dword format");
        sprintf(sourceCode[lenSourceCode++], "call printf");
        sprintf(sourceCode[lenSourceCode++], "add esp, 8\n");
    }
    ;

assignments : assignment
    | assignments assignment
    ;

if_body
    : LBRACE assignments RBRACE
    {
        int startIndex = lenSourceCode;
        int instructionsCount = lenSourceCode - startIndex;

        for (int i = 0; i < instructionsCount; i++) {
            strcpy(if_body[lenIfBody++], sourceCode[startIndex + i]);
        }

        lenSourceCode = startIndex;

        // Format the string as "startIndex:endIndex"
        char* rangeStr = (char*)malloc(20);
        sprintf(rangeStr, "%d:%d", startIndex, startIndex + instructionsCount);
         $$ = strdup(""); 
        $$ = rangeStr;
    }
    ;


assignment
    : ID ASSIGN arithmetic_expression SEMICOLON
    {
        printf("HERE");
        printf("%s\n", $1);
        fflush(stdout);
        // for(int i=0;i<lenDeclarations;i++)
        // {
        //     printf("%s\n",declarations[i]);
        //     fflush(stdout);
        // }
        if ($1 != NULL && !found(declarations, lenDeclarations, $1)) {
            yyerror("Variable not declared before assignment.");
        }

    if ($1 != NULL) {
        printf("Parsing expression for element: %s\n", $1);

        parseExpression($1);
            lenExpressions = 0;
            // put a new line in the file
            strcpy(sourceCode[lenSourceCode++], "\n");
    }

    }
    ;


if_statement
    : IF LPAREN condition RPAREN if_body ELSE if_body
    {
        char else_label[20], end_label[20];
        sprintf(else_label, "L%d", label_count++);
        sprintf(end_label, "L%d", label_count++);
        printf("--%s--\n", $3);
        printf("--%s--\n", $5);
        fflush(stdout);
        // Parse the range strings
        int ifStart, ifEnd, elseStart, elseEnd;
        sscanf($3, "%d:%d", &ifStart, &ifEnd);
        sscanf($5, "%d:%d", &elseStart, &elseEnd);

        // Insert labels and jumps
        char formattedInstruction[MAX];
        snprintf(formattedInstruction, MAX, "jne %s", else_label);
        insertSourceCode(ifEnd, formattedInstruction);

        snprintf(formattedInstruction, MAX, "%s:", else_label);
        insertSourceCode(elseStart, formattedInstruction);

        snprintf(formattedInstruction, MAX, "jmp %s", end_label);
        insertSourceCode(elseEnd, formattedInstruction);

        snprintf(formattedInstruction, MAX, "%s:", end_label);
        insertSourceCode(lenSourceCode, formattedInstruction);

        free($5);
        // free($6);
    }
    ;





return_statement
    : RETURN arithmetic_expression SEMICOLON
    {
        sprintf(sourceCode[lenSourceCode++], "mov eax, %s\nret", $2);
    }
    ;

condition
    : term EQ term
    {
        if (isdigit($1[0])) {
            sprintf(sourceCode[lenSourceCode++], "mov ebx, %s", $1);
        } else {
            sprintf(sourceCode[lenSourceCode++], "mov ebx, [%s]", $1);
        }

        if (isdigit($3[0])) {
            sprintf(sourceCode[lenSourceCode++], "mov eax, %s", $3);
        } else {
            sprintf(sourceCode[lenSourceCode++], "mov eax, [%s]", $3);
        }

        strcpy(sourceCode[lenSourceCode++], "cmp ebx, eax");

        // Format the string as "startIndex:endIndex"
        char* rangeStr = (char*)malloc(20);
        sprintf(rangeStr, "%d:%d", lenSourceCode - 1, lenSourceCode);
        $$ = rangeStr;
    }
    |
    term NE term
    {
        if (isdigit($1[0])) {
            sprintf(sourceCode[lenSourceCode++], "mov ebx, %s", $1);
        } else {
            sprintf(sourceCode[lenSourceCode++], "mov ebx, [%s]", $1);
        }

        if (isdigit($3[0])) {
            sprintf(sourceCode[lenSourceCode++], "mov eax, %s", $3);
        } else {
            sprintf(sourceCode[lenSourceCode++], "mov eax, [%s]", $3);
        }

        strcpy(sourceCode[lenSourceCode++], "cmp eax, ebx");

        // Format the string as "startIndex:endIndex"
        char* rangeStr = (char*)malloc(20);
        sprintf(rangeStr, "%d:%d", lenSourceCode - 1, lenSourceCode);
        $$ = rangeStr;
    }
    ;


arithmetic_expression
    : arithmetic_expression PLUS term
    {
        strncpy(expressions[lenExpressions++], "+", MAX - 1);
        strncpy(expressions[lenExpressions], $3, MAX - 1);
        expressions[lenExpressions][MAX - 1] = '\0';
        lenExpressions++;
    }
    | arithmetic_expression MINUS term
    {
        strncpy(expressions[lenExpressions++], "-", MAX - 1);
        strncpy(expressions[lenExpressions], $3, MAX - 1);
        expressions[lenExpressions][MAX - 1] = '\0';
        lenExpressions++;
    }
    | arithmetic_expression MULTIPLY term
    {
        strncpy(expressions[lenExpressions++], "*", MAX - 1);
        strncpy(expressions[lenExpressions], $3, MAX - 1);
        expressions[lenExpressions][MAX - 1] = '\0';
        lenExpressions++;
    }
    | arithmetic_expression DIVIDE term
    {
        strncpy(expressions[lenExpressions++], "/", MAX - 1);
        strncpy(expressions[lenExpressions], $3, MAX - 1);
        expressions[lenExpressions][MAX - 1] = '\0';
        lenExpressions++;
    }
    | term
    {
        strncpy(expressions[lenExpressions], $1, MAX - 1);
        expressions[lenExpressions][MAX - 1] = '\0';
        lenExpressions++;
    }
    ;

term
    : CONST_INT
    {
        printf("Processed CONST_INT: %s\n", $1);
        // strncpy(expressions[lenExpressions], $1, MAX - 1);
        // expressions[lenExpressions][MAX - 1] = '\0';
        // lenExpressions++;
    }
    | ID
    {
        printf("Processed ID: %s\n", $1);
        // strncpy(expressions[lenExpressions], $1, MAX - 1);
        // expressions[lenExpressions][MAX - 1] = '\0';
        // lenExpressions++;
    }
    | LPAREN arithmetic_expression RPAREN
    {
        printf("Processed Parenthesized Expression\n");
    }
    ;

simple_type
    : INT
    | STRING
    | CHAR
    ;

%%

int main(int argc, char* argv[]) {
    FILE* f = NULL;
    if (argc > 1) {
        f = fopen(argv[1], "r");
    }

    if (!f) {
        perror("Could not open file!");
        yyin = stdin;
    } else {
        yyin = f;
    }
    strcpy(imports[lenImports++],"exit");
    while(!feof(yyin)) {
        yyparse();
    }
    printf("Parsing done\n");
    char outputFile[100]="";
    strcat(outputFile, argv[1]);
    strcat(outputFile, "_asm.asm");
    asm_out = fopen(outputFile, "w");
    

    printf("Parsing done\n");
    fprintf(asm_out, "bits 32\nglobal main\n\n");
    printf("Printing imports\n");
    printf("bits 32\nglobal _start\n\n");
   
    printf("Done printing imports\n");
    fprintf(asm_out, "section .data\n");
    printf("section .data\n");
    printDeclarationSegment();
    fprintf(asm_out, "section .text\n");
 printImports();
    printf("section .text\n");
    printf("main:\n");
    fprintf(asm_out, "main:\n");
    printCodeSegment();

    fprintf(asm_out, "\tpush dword 0\n\tcall exit\n");
    printf("\tpush dword 0\n\tcall exit\n");
    fclose(asm_out);
    printf("All OK\n");
    for(int i = 0; i < lenDeclarations; i++) {
        printf("%s\n", declarations[i]);
    }
    printf("----------------");
    for(int i = 0; i < lenSourceCode; i++) {
        printf("%s\n", sourceCode[i]);
    }
    printf("----------------");
    for(int i = 0; i < lenImports; i++) {
        printf("%s\n", imports[i]);
    }
    printf("----------------");
    for(int i=0;i<lenExpressions;i++)
    {
        printf("%s\n",expressions[i]);
    }
    // free stuff 
    return 0;
}

bool found(char col[][MAX], int n, char* var) {

    for (int i = 0; i < n; i++) {
        printf("Comparing %s with %s\n", col[i], var);
        fflush(stdout);
        if (strstr(col[i], var) != NULL) {
            return true;
        }
    }
    return false;}

void parseExpression(char* element) {
    if (isdigit(expressions[0][0])) {
        sprintf(sourceCode[lenSourceCode++], "mov eax, %s", expressions[0]);
    } else {
        sprintf(sourceCode[lenSourceCode++], "mov eax, [%s]", expressions[0]);
    }

    for (int i = 1; i < lenExpressions - 1; i += 2) {
        char* operator = expressions[i];
        char* nextTerm = expressions[i + 1];

        if (strcmp(operator, "*") == 0 || strcmp(operator, "/") == 0) {
            //multiply or divide
            if (isdigit(nextTerm[0])) {
                sprintf(sourceCode[lenSourceCode++], "imul eax, %s", nextTerm);
            } else {
                sprintf(sourceCode[lenSourceCode++], "imul eax, [%s]", nextTerm);
            }
        } else {
            // add or subtract
            sprintf(sourceCode[lenSourceCode++], "push eax");

            if (isdigit(nextTerm[0])) {
                sprintf(sourceCode[lenSourceCode++], "mov eax, %s", nextTerm);
            } else {
                sprintf(sourceCode[lenSourceCode++], "mov eax, [%s]", nextTerm);
            }
            // Check for more multiplications or divisions
            while (i + 2 < lenExpressions && (strcmp(expressions[i + 2], "*") == 0 || strcmp(expressions[i + 2], "/") == 0)) {
                i += 2;
                nextTerm = expressions[i + 1];
                // if next term has a multiplication or division
                if (strcmp(expressions[i], "*") == 0) {
                    if (isdigit(nextTerm[0])) {
                        sprintf(sourceCode[lenSourceCode++], "imul eax, %s", nextTerm);
                    } else {
                        sprintf(sourceCode[lenSourceCode++], "imul eax, [%s]", nextTerm);
                    }
                }
            }

            sprintf(sourceCode[lenSourceCode++], "pop ebx");

            if (strcmp(operator, "+") == 0) {
                sprintf(sourceCode[lenSourceCode++], "add eax, ebx");
            } else {
                sprintf(sourceCode[lenSourceCode++], "sub eax, ebx");
            }
        }
    }

    if (element != NULL) {
        sprintf(sourceCode[lenSourceCode++], "mov [%s], eax", element);
    }

    lenExpressions = 0;
}



void printImports() {
    printf("Printing imports\n");
    for (int i = 0; i < lenImports; i++) {
        fprintf(asm_out, "extern %s\n", imports[i]);
        printf("extern %s\n", imports[i]);
    }
    printf("Done printing imports\n");
}

void printDeclarationSegment() {
    printf("Printing declarations\n");
    for (int i = 0; i < lenDeclarations; i++) {
        printf("%s\n", declarations[i]);
        fprintf(asm_out, "%s\n", declarations[i]);
    }
    //default format string
    fprintf(asm_out, "\tformat db \"%%d\", 0\n");
    fprintf(asm_out,"\tendl db 0Ah, 0\n");

    printf("Done printing declarations\n");
}

void printCodeSegment() {
    printf("Printing code\n");

    // Print the buffered source code
    for (int i = 0; i < lenSourceCode; i++) {
        fprintf(asm_out, "\t%s\n", sourceCode[i]);
        printf("\t%s\n", sourceCode[i]);
    }

    printf("Done printing code\n");
}

