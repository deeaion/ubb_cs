%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define YYDEBUG 1
int line_number = 1; // Define and initialize line number
extern FILE *yyin;
extern char *yytext;

int yylex(void);

void yyerror(const char *s) {
    fprintf(stderr, "Syntax error: %s at line %d (near '%s')\n", s, line_number, yytext);
}
%}

%union {
    char *strval;
    int intval;
    float floatval;
}

%token <strval> ID CONST_STRING
%token <intval> CONST_INT
%token <floatval> CONST_FLOAT
%token REL_OP CIN COUT IF ELSE WHILE DO RETURN ENDL
%token INT FLOAT STRING CHAR STRUCT VOID
%token ASSIGN
%token LBRACE RBRACE LPAREN RPAREN SEMICOLON
%token PLUS MINUS MULTIPLY DIVIDE MODULO
%token GT LT GE LE EQ NE INCLUDE IO_STREAM MATH_H DOT RSHIFT LSHIFT

%right UMINUS
%left PLUS MINUS
%left MULTIPLY DIVIDE MODULO
%nonassoc DOT  // Higher precedence than arithmetic
%nonassoc NO_ELSE
%nonassoc ELSE

%type <strval> struct_name

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
    | standalone_struct_declaration
    | inline_struct_variable_declaration
    ;

standalone_struct_declaration
    : STRUCT struct_name LBRACE variable_declaration_list RBRACE SEMICOLON
      {
          printf("DEBUG: Parsed standalone struct declaration: %s\n", $2);
      }
    ;

inline_struct_variable_declaration
    : STRUCT struct_name LBRACE variable_declaration_list RBRACE ID SEMICOLON
      {
          printf("DEBUG: Parsed inline struct variable: %s %s\n", $2, $6);
      }
    | STRUCT struct_name ID SEMICOLON
      {
          printf("DEBUG: Parsed struct variable declaration: %s %s\n", $2, $3);
      }
    ;

variable_declaration_list
    : variable_declaration_list variable_declaration
    | variable_declaration
    ;

variable_declaration
    : simple_type ID SEMICOLON
    ;

function
    : simple_type ID LPAREN parameter_list RPAREN body
    ;

parameter_list
    : parameter_list ',' parameter
    | parameter
    | /* epsilon */
    ;

parameter
    : type ID
    ;

body
    : LBRACE instruction_list RBRACE
    ;

instruction_list
    : instruction_list instruction
    | /* epsilon */
    ;

instruction
    : variable_declaration
    | inline_struct_variable_declaration
    | assignment
    | input_instruction
    | output_instruction
    | while_loop
    | do_while_loop
    | if_statement
    | return_statement
    ;

assignment
    : ID ASSIGN arithmetic_expression SEMICOLON
    | ID DOT ID ASSIGN arithmetic_expression SEMICOLON
    ;

input_instruction
    : CIN RSHIFT ID SEMICOLON
    | CIN RSHIFT ID DOT ID SEMICOLON
    ;

output_instruction
    : COUT LSHIFT arithmetic_expression SEMICOLON
    | COUT LSHIFT ENDL SEMICOLON
    ;

while_loop
    : WHILE LPAREN condition RPAREN body
    ;

do_while_loop
    : DO body WHILE LPAREN condition RPAREN SEMICOLON
    ;

if_statement
    : IF LPAREN condition RPAREN body %prec NO_ELSE
    | IF LPAREN condition RPAREN body ELSE body
    ;

return_statement
    : RETURN arithmetic_expression SEMICOLON
    | RETURN SEMICOLON
    ;

condition
    : arithmetic_expression relational_operator arithmetic_expression
    | arithmetic_expression
    ;

relational_operator
    : GT | LT | GE | LE | EQ | NE
    ;

arithmetic_expression
    : arithmetic_expression PLUS arithmetic_expression
    | arithmetic_expression MINUS arithmetic_expression
    | arithmetic_expression MULTIPLY arithmetic_expression
    | arithmetic_expression DIVIDE arithmetic_expression
    | arithmetic_expression MODULO arithmetic_expression
    | CONST_FLOAT
    | CONST_INT
    | ID
    | ID DOT ID
    ;

type
    : simple_type
    | struct_type
    ;

simple_type
    : INT
    | FLOAT
    | STRING
    | CHAR
    | VOID
    ;

struct_type
    : STRUCT struct_name
    ;

struct_name
    : ID
    ;

%%

// Main function
int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }
    if (argc > 2 && !strcmp(argv[2], "-d")) yydebug = 1;
    yyin = file;
    int result = yyparse();
    fclose(file);

    if (result == 0) {
        printf("Parsing completed successfully.\n");
    } else {
        printf("Parsing failed.\n");
    }

    return result;
}
