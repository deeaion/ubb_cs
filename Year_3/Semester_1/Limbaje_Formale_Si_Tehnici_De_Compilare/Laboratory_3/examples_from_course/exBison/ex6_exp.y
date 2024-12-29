%{
#include <stdio.h>
%}

%token DIGIT

%%
line : 	expr '\n'    {  printf("%d\n",$1); }
	 ;
expr  : term '+' expr 	{ $$ = $1 + $3;}
	  | term			{ $$ = $1;}
	;
term  : fact '*' term 	{ $$ = $1 * $3;}
	  | fact			{ $$ = $1;}
	;
fact  : DIGIT				{ $$ = $1;}
     ;


%%
yylex()
{
        int c;

        c = getchar();

        if (isdigit(c)) {
			yylval = c - '0';
			return DIGIT;
        }
        return c;
}

yyerror()
{
    printf("syntax error\n");
}

main()
{
    yyparse();
}
