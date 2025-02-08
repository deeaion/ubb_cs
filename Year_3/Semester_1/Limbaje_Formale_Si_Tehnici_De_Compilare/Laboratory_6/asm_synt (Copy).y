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
void parseExpression(char* element, char* register_name);
void printImports();
void printDeclarationSegment();
void printCodeSegment();


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


void yyerror(const char* s) {
    fprintf(stderr, "Syntax error: %s at line %d\n", s, line_number);
    exit(1);
}
%}

%union {
    char *strval;

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
%type <strval> arithmetic_expression term factor condition
%type <strval> return_statement
%type <strval> body


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

variable_declaration_list
    : variable_declaration_list variable_declaration
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
    | while_loop
    | if_statement
    | return_statement
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

        parseExpression($1,"eax");
            lenExpressions = 0;
            // put a new line in the file
            strcpy(sourceCode[lenSourceCode++], "\n");
    }

    }
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
        parseExpression(NULL,"eax");
    lenExpressions = 0;
        // Generate the printf call
        sprintf(sourceCode[lenSourceCode++], "push dword eax");
        sprintf(sourceCode[lenSourceCode++], "push dword format");
        sprintf(sourceCode[lenSourceCode++], "call printf");
        sprintf(sourceCode[lenSourceCode++], "add esp, 8\n");
    }
    ;


while_loop
    : WHILE LPAREN condition RPAREN body
    {
        char start_label[20], end_label[20];
        sprintf(start_label, "L%d", lenSourceCode);
        sprintf(end_label, "L%d", lenSourceCode + 1);

        strcpy(sourceCode[lenSourceCode++], start_label);
        strcpy(sourceCode[lenSourceCode++], "cmp eax, 0");
        sprintf(sourceCode[lenSourceCode++], "je %s", end_label);
        strcpy(sourceCode[lenSourceCode++], start_label);
        strcpy(sourceCode[lenSourceCode++], end_label);
    }
    ;

    
if_statement
    : IF LPAREN condition RPAREN body
    {
        // Obține eticheta pentru blocul else
        char* else_label = pop_label();

        // Adaugă codul pentru blocul `if`
        strcpy(sourceCode[lenSourceCode++], $5);

        // Adaugă eticheta pentru blocul else
        sprintf(sourceCode[lenSourceCode++], "%s:", else_label);
    }
    | IF LPAREN condition RPAREN body ELSE body
    {
        // Generează etichete unice pentru else și final
        char else_label[20], end_label[20];
        sprintf(else_label, "L%d", label_count++);
        sprintf(end_label, "L%d", label_count++);

        // Salt la blocul else dacă condiția este falsă
        strcpy(sourceCode[lenSourceCode++], "cmp eax, ebx");
        sprintf(sourceCode[lenSourceCode++], "jne %s", else_label);

        // Codul pentru blocul `if`
        strcpy(sourceCode[lenSourceCode++], $5);

        // Salt la sfârșitul blocului
        sprintf(sourceCode[lenSourceCode++], "jmp %s", end_label);

        // Eticheta pentru blocul else
        sprintf(sourceCode[lenSourceCode++], "%s:", else_label);
        strcpy(sourceCode[lenSourceCode++], $7);

        // Eticheta de sfârșit
        sprintf(sourceCode[lenSourceCode++], "%s:", end_label);
    }
    ;









return_statement
    : RETURN arithmetic_expression SEMICOLON
    {
        sprintf(sourceCode[lenSourceCode++], "mov eax, %s\nret", $2);
    }
    ;

condition
    : arithmetic_expression EQ arithmetic_expression
    {
        // Evaluează prima expresie și stochează rezultatul în ebx
        if (isdigit($1[0])) {
            sprintf(sourceCode[lenSourceCode++], "mov ebx, %s", $1);
        } else {
            parseExpression($1, "ebx");
                lenExpressions = 0;
        }

        // Evaluează a doua expresie și stochează rezultatul în eax
        if (isdigit($3[0])) {
            sprintf(sourceCode[lenSourceCode++], "mov eax, %s", $3);
        } else {
            parseExpression($3, "eax");
                lenExpressions = 0;
        }

        // Compară registrele eax și ebx
        strcpy(sourceCode[lenSourceCode++], "cmp eax, ebx");

        // Generăm un label pentru blocul else
        char else_label[20];
        sprintf(else_label, "L%d", label_count++);
        sprintf(sourceCode[lenSourceCode++], "jne %s", else_label);

        // Punem label-ul else pe stivă
        push_label(else_label);
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
    | FLOAT
    | STRING
    | CHAR
    | VOID
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

void parseExpression(char* element, char* register_name) {
    if (lenExpressions == 0) {
        fprintf(stderr, "Error: Empty expression\n");
        return;
    }
    printf("Parsing expression\n");
    printf("Element: %s\n", element ? element : "NULL");
    printf("Register: %s\n", register_name);
    fflush(stdout);

    // Load the first term into the specified register
    if (isdigit(expressions[0][0])) {
        sprintf(sourceCode[lenSourceCode++], "mov %s, %s", register_name, expressions[0]);
    } else {
        sprintf(sourceCode[lenSourceCode++], "mov %s, [%s]", register_name, expressions[0]);
    }

    // Process remaining terms
    //print expression
    printf("Expression: ");
    for(int i=0;i<lenExpressions;i++)
    {
        printf("%s ",expressions[i]);
    }
    printf("\n");
    for (int i = 1; i < lenExpressions; i += 2) {
        char* operator = expressions[i];
        char* nextTerm = expressions[i + 1];
        printf("Operator: %s\n", operator);
        printf("Next term: %s\n", nextTerm);
        fflush(stdout);

        if (nextTerm == NULL) {
            fprintf(stderr, "Error: Missing term after operator\n");
            return;
        }

        // Load the next term into ebx
        if (isdigit(nextTerm[0])) {
            sprintf(sourceCode[lenSourceCode++], "mov ebx, %s", nextTerm);
        } else {
            sprintf(sourceCode[lenSourceCode++], "mov ebx, [%s]", nextTerm);
        }

        // Handle the operator
        if (strcmp(operator, "+") == 0) {
            strcpy(sourceCode[lenSourceCode++], "add eax, ebx");
        } else if (strcmp(operator, "-") == 0) {
            strcpy(sourceCode[lenSourceCode++], "sub eax, ebx");
        } else if (strcmp(operator, "*") == 0) {
            strcpy(sourceCode[lenSourceCode++], "imul eax, ebx");
        } else if (strcmp(operator, "/") == 0) {
            strcpy(sourceCode[lenSourceCode++], "mov edx, 0");
            strcpy(sourceCode[lenSourceCode++], "div ebx");
        } else {
            fprintf(stderr, "Error: Unknown operator %s\n", operator);
        }
    }

    // If it's an assignment, store the result back into memory
    if (element != NULL) {
        sprintf(sourceCode[lenSourceCode++], "mov [%s], %s", element, register_name);
    }

    // Clear expressions

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
    for (int i = 0; i < lenSourceCode; i++) {
        fprintf(asm_out, "\t%s\n", sourceCode[i]);
        printf("\t%s\n", sourceCode[i]);
    }
    printf("Done printing code\n");
}
