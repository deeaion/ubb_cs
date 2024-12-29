%option noyywrap

%%
[1-9][0-9]* 			printf("zecimal %s", yytext);
0[0-7]*  				printf("octal: %s", yytext);
0(x|X)[0-9A-Ea-e]+		printf ("hexazecimal: %s", yytext);
(0b|0B)(0|1)+			printf("binar: %s", yytext);


%%

void main(){
	yylex();
}