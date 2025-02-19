/* partial scanner for a toy Pascal-like language */ 

%{ 				
#include <math.h> 			/* -> atof()  */
%} 

%option noyywrap

DIGIT 	[0-9] 
ID 		[a-z][a-z0-9]* 

%% 

{DIGIT}+ 	{ 
				printf( "An integer: %s (%d)\n", yytext, 
				atoi( yytext ) ); 
			} 

{DIGIT}+"."{DIGIT}* 	{ 
				printf( "A float: %s (%g)\n", yytext, atof( yytext ) ); 
			} 

if|then|else|begin|end  printf( "A keyword: %s\n", yytext ); 

{ID} 					printf( "An identifier: %s\n", yytext ); 

"+"|"-"|"*"|"/" 		printf( "An operator: %s\n", yytext ); 

"{"[^}\n]*"}" 			/* eat up one-line comments */ 

[ \t\n]+ 				/* eat up whitespace */ 
.			 			printf( "Unrecognized chr.: %s\n", yytext ); 


%% 
int main( argc, argv ) 
int argc; 
char **argv; 
{ 
    ++argv, --argc; /* skip over program name */ 
    if ( argc > 0 ) 
    	yyin = fopen( argv[0], "r" ); 
    else 
     	yyin = stdin; 
    yylex(); 
	return 0;
} 

