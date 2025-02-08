%{
#include "asm_synt.tab.h" // Include Bison header
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int line_number; // Declare line_number
%}

%option noyywrap

DIGIT           [0-9]
LETTER          [a-zA-Z_]
ID              {LETTER}({LETTER}|{DIGIT})*
CONST_FLOAT     {DIGIT}+"."{DIGIT}+([eE][+-]?{DIGIT}+)?
CONST_INT       {DIGIT}+
CONST_STRING    \"([^\"\\]|\\.)*\"

%%
"."             { printf("Token: DOT, Line: %d\n", line_number); return DOT; }
"#"[ \t]*"include" { printf("Token: INCLUDE, Line: %d\n", line_number); return INCLUDE; }  
"<iostream>"    { printf("Token: IO_STREAM, Line: %d\n", line_number); return IO_STREAM; }
"<math.h>"      { printf("Token: MATH_H, Line: %d\n", line_number); return MATH_H; }
"int"           { printf("Token: INT, Line: %d\n", line_number); return INT; }
"float"         { printf("Token: FLOAT, Line: %d\n", line_number); return FLOAT; }
"string"        { printf("Token: STRING, Line: %d\n", line_number); return STRING; }
"char"          { printf("Token: CHAR, Line: %d\n", line_number); return CHAR; }
"void"          { printf("Token: VOID, Line: %d\n", line_number); return VOID; }
"if"            { printf("Token: IF, Line: %d\n", line_number); return IF; }
"else"          { printf("Token: ELSE, Line: %d\n", line_number); return ELSE; }
"while"         { printf("Token: WHILE, Line: %d\n", line_number); return WHILE; }
"do"            { printf("Token: DO, Line: %d\n", line_number); return DO; }
"return"        { printf("Token: RETURN, Line: %d\n", line_number); return RETURN; }
"cin"           { printf("Token: CIN, Line: %d\n", line_number); return CIN; }
"cout"          { printf("Token: COUT, Line: %d\n", line_number); return COUT; }
"endl"          { printf("Token: ENDL, Line: %d\n", line_number); return ENDL; }

{ID}            { printf("Token: ID (%s), Line: %d\n", yytext, line_number); yylval.strval = strdup(yytext); return ID; }
{CONST_INT}     { printf("Token: CONST_INT (%d), Line: %d\n", atoi(yytext), line_number); yylval.strval = strdup(yytext); return CONST_INT; }
{CONST_FLOAT}   { printf("Token: CONST_FLOAT (%f), Line: %d\n", atof(yytext), line_number); yylval.strval = strdup(yytext); return CONST_FLOAT; }
"-"             { printf("Token: MINUS, Line: %d\n", line_number); return MINUS; }
"{"             { printf("Token: LBRACE, Line: %d\n", line_number); return LBRACE; }
"}"             { printf("Token: RBRACE, Line: %d\n", line_number); return RBRACE; }
"("             { printf("Token: LPAREN, Line: %d\n", line_number); return LPAREN; }
")"             { printf("Token: RPAREN, Line: %d\n", line_number); return RPAREN; }
"="             { printf("Token: ASSIGN, Line: %d\n", line_number); return ASSIGN; }
"+"             { printf("Token: PLUS, Line: %d\n", line_number); return PLUS; }
"*"             { printf("Token: MULTIPLY, Line: %d\n", line_number); return MULTIPLY; }
"/"             { printf("Token: DIVIDE, Line: %d\n", line_number); return DIVIDE; }
"%"             { printf("Token: MODULO, Line: %d\n", line_number); return MODULO; }
";"             { printf("Token: SEMICOLON, Line: %d\n", line_number); return SEMICOLON; }
">"             { printf("Token: GT, Line: %d\n", line_number); return GT; }
"<"             { printf("Token: LT, Line: %d\n", line_number); return LT; }
">="            { printf("Token: GE, Line: %d\n", line_number); return GE; }
"<="            { printf("Token: LE, Line: %d\n", line_number); return LE; }
"=="            { printf("Token: EQ, Line: %d\n", line_number); return EQ; }
"!="            { printf("Token: NE, Line: %d\n", line_number); return NE; }
"<<"            { printf("Token: LSHIFT, Line: %d\n", line_number); return LSHIFT; }
">>"            { printf("Token: RSHIFT, Line: %d\n", line_number); return RSHIFT; }

[ \t]+          ;  // Ignore spaces and tabs
\n              { line_number++; } // Increment line number on newline

.               { fprintf(stderr, "Lexical Error: Invalid character '%s' at line %d\n", yytext, line_number); return yytext[0]; }
