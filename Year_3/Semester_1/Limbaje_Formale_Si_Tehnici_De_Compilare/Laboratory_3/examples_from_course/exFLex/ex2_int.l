%option noyywrap

%%
0|[1-9][0-9]*   printf("Integer\n");

%%
main( argc, argv ) 
int argc; 
char **argv; 
	{ 	++argv, --argc; 		/* skip over program name */ 
		if ( argc > 0 ) 
			yyin = fopen( argv[0], "r" ); 
		else 
			yyin = stdin; 
		yylex(); 
	} 
