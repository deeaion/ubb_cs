/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SYNTACTIC_ANALYZER_TAB_H_INCLUDED
# define YY_YY_SYNTACTIC_ANALYZER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    CONST_STRING = 259,            /* CONST_STRING  */
    CONST_INT = 260,               /* CONST_INT  */
    CONST_FLOAT = 261,             /* CONST_FLOAT  */
    REL_OP = 262,                  /* REL_OP  */
    CIN = 263,                     /* CIN  */
    COUT = 264,                    /* COUT  */
    IF = 265,                      /* IF  */
    ELSE = 266,                    /* ELSE  */
    WHILE = 267,                   /* WHILE  */
    DO = 268,                      /* DO  */
    RETURN = 269,                  /* RETURN  */
    ENDL = 270,                    /* ENDL  */
    INT = 271,                     /* INT  */
    FLOAT = 272,                   /* FLOAT  */
    STRING = 273,                  /* STRING  */
    CHAR = 274,                    /* CHAR  */
    STRUCT = 275,                  /* STRUCT  */
    VOID = 276,                    /* VOID  */
    ASSIGN = 277,                  /* ASSIGN  */
    LBRACE = 278,                  /* LBRACE  */
    RBRACE = 279,                  /* RBRACE  */
    LPAREN = 280,                  /* LPAREN  */
    RPAREN = 281,                  /* RPAREN  */
    SEMICOLON = 282,               /* SEMICOLON  */
    PLUS = 283,                    /* PLUS  */
    MINUS = 284,                   /* MINUS  */
    MULTIPLY = 285,                /* MULTIPLY  */
    DIVIDE = 286,                  /* DIVIDE  */
    MODULO = 287,                  /* MODULO  */
    GT = 288,                      /* GT  */
    LT = 289,                      /* LT  */
    GE = 290,                      /* GE  */
    LE = 291,                      /* LE  */
    EQ = 292,                      /* EQ  */
    NE = 293,                      /* NE  */
    INCLUDE = 294,                 /* INCLUDE  */
    IO_STREAM = 295,               /* IO_STREAM  */
    MATH_H = 296,                  /* MATH_H  */
    DOT = 297,                     /* DOT  */
    RSHIFT = 298,                  /* RSHIFT  */
    LSHIFT = 299,                  /* LSHIFT  */
    UMINUS = 300,                  /* UMINUS  */
    NO_ELSE = 301                  /* NO_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "syntactic_analyzer.y"

    char *strval;
    int intval;
    float floatval;

#line 116 "syntactic_analyzer.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SYNTACTIC_ANALYZER_TAB_H_INCLUDED  */
