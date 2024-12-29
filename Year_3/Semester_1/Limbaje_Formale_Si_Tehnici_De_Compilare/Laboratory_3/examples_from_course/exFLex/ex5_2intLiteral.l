%option noyywrap

SUFIX	((u|U)?(l|L)?(l|L)?)|((l|L)?(l|L)?(u|U)?)

%%
[1-9][0-9]*{SUFIX} 				printf("zecimal %s\n", yytext);
0[0-7]*{SUFIX}  				printf("octal: %s\n", yytext);
0(x|X)[0-9A-Ea-e]+{SUFIX}		printf ("hexazecimal: %s\n", yytext);
(0b|0B)(0|1)+{SUFIX}			printf("binar: %s\n", yytext);


%%

void main(){
	yylex();
}