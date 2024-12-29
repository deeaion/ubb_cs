%{
#include <stdio.h>
%}

%token DIGIT

%%
line : expr '\n'         { printf("OK\n");}
     ;
expr : expr expr '+'
		| expr expr '*'
		| DIGIT
     ;


%%
yylex()
{
        int c;

        c = getchar();

        if (isdigit(c)) {
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
