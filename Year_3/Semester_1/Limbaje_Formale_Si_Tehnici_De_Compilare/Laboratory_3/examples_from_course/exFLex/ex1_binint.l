%option noyywrap

%%
0|1(0|1)*   printf("OK");

%%
int main(){
	yylex();
}