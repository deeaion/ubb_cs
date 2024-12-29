%{
#include <stdio.h>
%}

%%
input : start '\n'
start :  'a' start 'b'
		| 'a' 'b'
        ;

	 
%%
yylex() {
        int c;
        c = getchar();
        return c;
}

yyerror()
{
    printf("syntax error\n");
}

int main()
{
    if(0==yyparse()) printf("Result yyparse OK\n");
	return 0;
}
