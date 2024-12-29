%{
#include <stdio.h>
%}

%%
input :  /* secv. vida */
        | line '\n' input
        ;

line :
      | bindigit line
     ;

bindigit: 	'0'
			| '1'
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

main()
{
    if(0==yyparse()) printf("Result yyparse OK\n");
}
