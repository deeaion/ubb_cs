/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "asm_synt.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

extern int yylex();
extern FILE* yyin;
int line_number;

FILE* asm_out;
char* filename;
int label_count = 0;
#define MAX 1000
char declarations[MAX][MAX], sourceCode[MAX][MAX], imports[MAX][MAX];
int lenDeclarations = 0, lenSourceCode = 0, lenImports = 0;

char expressions[MAX][MAX];
int lenExpressions = 0;

bool found(char col[][MAX], int n, char* var);
void parseExpression(char* element);
void printImports();
void printDeclarationSegment();
void printCodeSegment();

char if_body[MAX][MAX];
char else_body[MAX][MAX];
int lenIfBody = 0, lenElseBody = 0;

#define MAX_LABELS 100
char label_stack[MAX_LABELS][20];
int label_top = -1;

void push_label(const char* label) {
    if (label_top < MAX_LABELS - 1) {
        strcpy(label_stack[++label_top], label);
    } else {
        fprintf(stderr, "Label stack overflow!\n");
        exit(1);
    }
}

char* pop_label() {
    if (label_top >= 0) {
        return label_stack[label_top--];
    } else {
        fprintf(stderr, "Label stack underflow!\n");
        exit(1);
    }
}

char* peek_label() {
    if (label_top >= 0) {
        return label_stack[label_top];
    } else {
        return NULL;
    }
}

void insertSourceCode(int index, const char* instruction) {
    if (lenSourceCode >= MAX) {
        fprintf(stderr, "Source code array overflow!\n");
        exit(EXIT_FAILURE);
    }

    if (index < 0 || index > lenSourceCode) {
        fprintf(stderr, "Error: Invalid index %d for source code insertion!\n", index);
        return;
    }

    if (instruction == NULL || strlen(instruction) == 0) {
        return;
    }

    for (int i = lenSourceCode; i > index; i--) {
        strcpy(sourceCode[i], sourceCode[i - 1]);
    }

    strcpy(sourceCode[index], instruction);
    lenSourceCode++;
}


void yyerror(const char* s) {
    fprintf(stderr, "Syntax error: %s at line %d\n", s, line_number);
    exit(1);
}



#line 164 "asm_synt.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


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
    REL_OP = 261,                  /* REL_OP  */
    CIN = 262,                     /* CIN  */
    COUT = 263,                    /* COUT  */
    IF = 264,                      /* IF  */
    ELSE = 265,                    /* ELSE  */
    WHILE = 266,                   /* WHILE  */
    RETURN = 267,                  /* RETURN  */
    ENDL = 268,                    /* ENDL  */
    INT = 269,                     /* INT  */
    FLOAT = 270,                   /* FLOAT  */
    STRING = 271,                  /* STRING  */
    CHAR = 272,                    /* CHAR  */
    VOID = 273,                    /* VOID  */
    ASSIGN = 274,                  /* ASSIGN  */
    LBRACE = 275,                  /* LBRACE  */
    RBRACE = 276,                  /* RBRACE  */
    LPAREN = 277,                  /* LPAREN  */
    RPAREN = 278,                  /* RPAREN  */
    SEMICOLON = 279,               /* SEMICOLON  */
    DO = 280,                      /* DO  */
    PLUS = 281,                    /* PLUS  */
    MINUS = 282,                   /* MINUS  */
    MULTIPLY = 283,                /* MULTIPLY  */
    DIVIDE = 284,                  /* DIVIDE  */
    MODULO = 285,                  /* MODULO  */
    GT = 286,                      /* GT  */
    LT = 287,                      /* LT  */
    GE = 288,                      /* GE  */
    LE = 289,                      /* LE  */
    EQ = 290,                      /* EQ  */
    NE = 291,                      /* NE  */
    INCLUDE = 292,                 /* INCLUDE  */
    IO_STREAM = 293,               /* IO_STREAM  */
    MATH_H = 294,                  /* MATH_H  */
    DOT = 295,                     /* DOT  */
    RSHIFT = 296,                  /* RSHIFT  */
    LSHIFT = 297,                  /* LSHIFT  */
    CONST_FLOAT = 298              /* CONST_FLOAT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 95 "asm_synt.y"

    char* strval;
   

#line 259 "asm_synt.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_CONST_STRING = 4,               /* CONST_STRING  */
  YYSYMBOL_CONST_INT = 5,                  /* CONST_INT  */
  YYSYMBOL_REL_OP = 6,                     /* REL_OP  */
  YYSYMBOL_CIN = 7,                        /* CIN  */
  YYSYMBOL_COUT = 8,                       /* COUT  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_ELSE = 10,                      /* ELSE  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_RETURN = 12,                    /* RETURN  */
  YYSYMBOL_ENDL = 13,                      /* ENDL  */
  YYSYMBOL_INT = 14,                       /* INT  */
  YYSYMBOL_FLOAT = 15,                     /* FLOAT  */
  YYSYMBOL_STRING = 16,                    /* STRING  */
  YYSYMBOL_CHAR = 17,                      /* CHAR  */
  YYSYMBOL_VOID = 18,                      /* VOID  */
  YYSYMBOL_ASSIGN = 19,                    /* ASSIGN  */
  YYSYMBOL_LBRACE = 20,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 21,                    /* RBRACE  */
  YYSYMBOL_LPAREN = 22,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 23,                    /* RPAREN  */
  YYSYMBOL_SEMICOLON = 24,                 /* SEMICOLON  */
  YYSYMBOL_DO = 25,                        /* DO  */
  YYSYMBOL_PLUS = 26,                      /* PLUS  */
  YYSYMBOL_MINUS = 27,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 28,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 29,                    /* DIVIDE  */
  YYSYMBOL_MODULO = 30,                    /* MODULO  */
  YYSYMBOL_GT = 31,                        /* GT  */
  YYSYMBOL_LT = 32,                        /* LT  */
  YYSYMBOL_GE = 33,                        /* GE  */
  YYSYMBOL_LE = 34,                        /* LE  */
  YYSYMBOL_EQ = 35,                        /* EQ  */
  YYSYMBOL_NE = 36,                        /* NE  */
  YYSYMBOL_INCLUDE = 37,                   /* INCLUDE  */
  YYSYMBOL_IO_STREAM = 38,                 /* IO_STREAM  */
  YYSYMBOL_MATH_H = 39,                    /* MATH_H  */
  YYSYMBOL_DOT = 40,                       /* DOT  */
  YYSYMBOL_RSHIFT = 41,                    /* RSHIFT  */
  YYSYMBOL_LSHIFT = 42,                    /* LSHIFT  */
  YYSYMBOL_CONST_FLOAT = 43,               /* CONST_FLOAT  */
  YYSYMBOL_44_ = 44,                       /* ','  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_program = 46,                   /* program  */
  YYSYMBOL_header = 47,                    /* header  */
  YYSYMBOL_library_inclusions = 48,        /* library_inclusions  */
  YYSYMBOL_declaration_or_function_list = 49, /* declaration_or_function_list  */
  YYSYMBOL_declaration_or_function = 50,   /* declaration_or_function  */
  YYSYMBOL_variable_declaration = 51,      /* variable_declaration  */
  YYSYMBOL_function = 52,                  /* function  */
  YYSYMBOL_parameter_list = 53,            /* parameter_list  */
  YYSYMBOL_parameter = 54,                 /* parameter  */
  YYSYMBOL_body = 55,                      /* body  */
  YYSYMBOL_instruction_list = 56,          /* instruction_list  */
  YYSYMBOL_instruction = 57,               /* instruction  */
  YYSYMBOL_input_instruction = 58,         /* input_instruction  */
  YYSYMBOL_output_instruction = 59,        /* output_instruction  */
  YYSYMBOL_assignments = 60,               /* assignments  */
  YYSYMBOL_if_body = 61,                   /* if_body  */
  YYSYMBOL_assignment = 62,                /* assignment  */
  YYSYMBOL_if_statement = 63,              /* if_statement  */
  YYSYMBOL_return_statement = 64,          /* return_statement  */
  YYSYMBOL_condition = 65,                 /* condition  */
  YYSYMBOL_arithmetic_expression = 66,     /* arithmetic_expression  */
  YYSYMBOL_term = 67,                      /* term  */
  YYSYMBOL_simple_type = 68                /* simple_type  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   91

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  45
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  87

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    44,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   120,   120,   124,   128,   129,   133,   134,   138,   139,
     145,   156,   165,   166,   167,   171,   175,   182,   183,   187,
     188,   189,   190,   191,   192,   196,   208,   225,   226,   230,
     251,   279,   316,   323,   345,   370,   377,   384,   391,   398,
     407,   414,   421,   428,   429,   430
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "CONST_STRING",
  "CONST_INT", "REL_OP", "CIN", "COUT", "IF", "ELSE", "WHILE", "RETURN",
  "ENDL", "INT", "FLOAT", "STRING", "CHAR", "VOID", "ASSIGN", "LBRACE",
  "RBRACE", "LPAREN", "RPAREN", "SEMICOLON", "DO", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "MODULO", "GT", "LT", "GE", "LE", "EQ", "NE",
  "INCLUDE", "IO_STREAM", "MATH_H", "DOT", "RSHIFT", "LSHIFT",
  "CONST_FLOAT", "','", "$accept", "program", "header",
  "library_inclusions", "declaration_or_function_list",
  "declaration_or_function", "variable_declaration", "function",
  "parameter_list", "parameter", "body", "instruction_list", "instruction",
  "input_instruction", "output_instruction", "assignments", "if_body",
  "assignment", "if_statement", "return_statement", "condition",
  "arithmetic_expression", "term", "simple_type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-72)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -30,    -8,    12,    61,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,    61,   -72,   -72,   -72,    37,   -72,    -9,    61,   -72,
     -22,   -72,    55,    28,    61,   -72,    35,   -72,   -72,    51,
      23,    34,    57,    -1,   -72,    20,   -72,   -72,   -72,   -72,
     -72,   -72,    77,    -1,    78,    -1,    -1,   -72,   -72,    -1,
      33,   -72,   -72,   -72,    58,    39,    59,    45,    62,    10,
      27,   -72,    -1,    -1,    -1,    -1,   -72,   -72,   -72,    64,
      -1,    -1,   -72,   -72,   -72,   -72,   -72,    83,    79,   -72,
     -72,     5,   -72,    64,   -72,   -72,   -72
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     3,     4,     5,     1,    43,    44,
      45,     2,     7,     9,     8,     0,     6,     0,    14,    10,
       0,    13,     0,     0,     0,    15,     0,    11,    12,     0,
       0,     0,     0,     0,    19,     0,    18,    21,    22,    20,
      23,    24,     0,     0,     0,     0,     0,    41,    40,     0,
       0,    39,    16,    17,     0,     0,     0,     0,     0,     0,
       0,    32,     0,     0,     0,     0,    30,    25,    26,     0,
       0,     0,    42,    35,    36,    37,    38,     0,     0,    33,
      34,     0,    27,     0,    29,    28,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -72,   -72,   -72,   -72,   -72,    76,   -21,   -72,   -72,    66,
     -72,   -72,    53,   -72,   -72,   -72,     8,   -71,   -72,   -72,
     -72,   -10,   -46,   -15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,    11,    12,    13,    14,    20,    21,
      27,    35,    36,    37,    38,    81,    78,    39,    40,    41,
      58,    50,    51,    15
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      59,    23,    47,    22,    48,    34,    82,     1,    29,    22,
      85,    42,     7,    18,    34,    19,    73,    74,    75,    76,
      42,    49,    24,    29,    79,    80,    84,    30,    31,    32,
       5,     6,    33,    55,     8,    57,     9,    10,    29,    60,
      17,    52,    30,    31,    32,    70,    71,    33,    26,     8,
      72,     9,    10,    62,    63,    64,    65,    61,    25,    62,
      63,    64,    65,    66,    44,    62,    63,    64,    65,    68,
      43,    62,    63,    64,    65,     8,    45,     9,    10,    46,
      54,    56,    19,    67,    77,    69,    29,    16,    53,    83,
      28,    86
};

static const yytype_int8 yycheck[] =
{
      46,    23,     3,    18,     5,    26,    77,    37,     3,    24,
      81,    26,     0,    22,    35,    24,    62,    63,    64,    65,
      35,    22,    44,     3,    70,    71,    21,     7,     8,     9,
      38,    39,    12,    43,    14,    45,    16,    17,     3,    49,
       3,    21,     7,     8,     9,    35,    36,    12,    20,    14,
      23,    16,    17,    26,    27,    28,    29,    24,     3,    26,
      27,    28,    29,    24,    41,    26,    27,    28,    29,    24,
      19,    26,    27,    28,    29,    14,    42,    16,    17,    22,
       3,     3,    24,    24,    20,    23,     3,    11,    35,    10,
      24,    83
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    37,    46,    47,    48,    38,    39,     0,    14,    16,
      17,    49,    50,    51,    52,    68,    50,     3,    22,    24,
      53,    54,    68,    23,    44,     3,    20,    55,    54,     3,
       7,     8,     9,    12,    51,    56,    57,    58,    59,    62,
      63,    64,    68,    19,    41,    42,    22,     3,     5,    22,
      66,    67,    21,    57,     3,    66,     3,    66,    65,    67,
      66,    24,    26,    27,    28,    29,    24,    24,    24,    23,
      35,    36,    23,    67,    67,    67,    67,    20,    61,    67,
      67,    60,    62,    10,    21,    62,    61
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    48,    48,    49,    49,    50,    50,
      51,    52,    53,    53,    53,    54,    55,    56,    56,    57,
      57,    57,    57,    57,    57,    58,    59,    60,    60,    61,
      62,    63,    64,    65,    65,    66,    66,    66,    66,    66,
      67,    67,    67,    68,    68,    68
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     2,     2,     1,     1,     1,
       3,     6,     3,     1,     0,     2,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     1,     2,     3,
       4,     7,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     3,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 10: /* variable_declaration: simple_type ID SEMICOLON  */
#line 146 "asm_synt.y"
    {
        char temp[1000];
        sprintf(temp, "\t%s times 4 db 0", (yyvsp[-1].strval));
        if (!found(declarations, lenDeclarations, temp)) {
            strcpy(declarations[lenDeclarations++], temp);
        }
    }
#line 1371 "asm_synt.tab.c"
    break;

  case 11: /* function: simple_type ID LPAREN parameter_list RPAREN body  */
#line 157 "asm_synt.y"
    {
        // char func[100];
        // sprintf(func, "global %s\n%s:", $2, $2);
        // strcpy(sourceCode[lenSourceCode++], func);
    }
#line 1381 "asm_synt.tab.c"
    break;

  case 16: /* body: LBRACE instruction_list RBRACE  */
#line 176 "asm_synt.y"
    {
        (yyval.strval)=strdup("");
    }
#line 1389 "asm_synt.tab.c"
    break;

  case 25: /* input_instruction: CIN RSHIFT ID SEMICOLON  */
#line 197 "asm_synt.y"
    {
        if (!found(imports, lenImports, "scanf")) {
            strcpy(imports[lenImports++], "scanf");
        }
        char input[100];
        sprintf(input, "push dword %s\n\tpush dword format\n\tcall scanf\n\tadd esp, 8\n", (yyvsp[-1].strval));
        strcpy(sourceCode[lenSourceCode++], input);
    }
#line 1402 "asm_synt.tab.c"
    break;

  case 26: /* output_instruction: COUT LSHIFT arithmetic_expression SEMICOLON  */
#line 209 "asm_synt.y"
    {
        if (!found(imports, lenImports, "printf")) {
            strcpy(imports[lenImports++], "printf");
        }

        // Load the expression result into eax
        parseExpression(NULL);
    lenExpressions = 0;
        // Generate the printf call
        sprintf(sourceCode[lenSourceCode++], "push dword eax");
        sprintf(sourceCode[lenSourceCode++], "push dword format");
        sprintf(sourceCode[lenSourceCode++], "call printf");
        sprintf(sourceCode[lenSourceCode++], "add esp, 8\n");
    }
#line 1421 "asm_synt.tab.c"
    break;

  case 29: /* if_body: LBRACE assignments RBRACE  */
#line 231 "asm_synt.y"
    {
        int startIndex = lenSourceCode;
        int instructionsCount = lenSourceCode - startIndex;

        for (int i = 0; i < instructionsCount; i++) {
            strcpy(if_body[lenIfBody++], sourceCode[startIndex + i]);
        }

        lenSourceCode = startIndex;

        // Format the string as "startIndex:endIndex"
        char* rangeStr = (char*)malloc(20);
        sprintf(rangeStr, "%d:%d", startIndex, startIndex + instructionsCount);
         (yyval.strval) = strdup(""); 
        (yyval.strval) = rangeStr;
    }
#line 1442 "asm_synt.tab.c"
    break;

  case 30: /* assignment: ID ASSIGN arithmetic_expression SEMICOLON  */
#line 252 "asm_synt.y"
    {
        printf("HERE");
        printf("%s\n", (yyvsp[-3].strval));
        fflush(stdout);
        // for(int i=0;i<lenDeclarations;i++)
        // {
        //     printf("%s\n",declarations[i]);
        //     fflush(stdout);
        // }
        if ((yyvsp[-3].strval) != NULL && !found(declarations, lenDeclarations, (yyvsp[-3].strval))) {
            yyerror("Variable not declared before assignment.");
        }

    if ((yyvsp[-3].strval) != NULL) {
        printf("Parsing expression for element: %s\n", (yyvsp[-3].strval));

        parseExpression((yyvsp[-3].strval));
            lenExpressions = 0;
            // put a new line in the file
            strcpy(sourceCode[lenSourceCode++], "\n");
    }

    }
#line 1470 "asm_synt.tab.c"
    break;

  case 31: /* if_statement: IF LPAREN condition RPAREN if_body ELSE if_body  */
#line 280 "asm_synt.y"
    {
        char else_label[20], end_label[20];
        sprintf(else_label, "L%d", label_count++);
        sprintf(end_label, "L%d", label_count++);
        printf("--%s--\n", (yyvsp[-4].strval));
        printf("--%s--\n", (yyvsp[-2].strval));
        fflush(stdout);
        // Parse the range strings
        int ifStart, ifEnd, elseStart, elseEnd;
        sscanf((yyvsp[-4].strval), "%d:%d", &ifStart, &ifEnd);
        sscanf((yyvsp[-2].strval), "%d:%d", &elseStart, &elseEnd);

        // Insert labels and jumps
        char formattedInstruction[MAX];
        snprintf(formattedInstruction, MAX, "jne %s", else_label);
        insertSourceCode(ifEnd, formattedInstruction);

        snprintf(formattedInstruction, MAX, "%s:", else_label);
        insertSourceCode(elseStart, formattedInstruction);

        snprintf(formattedInstruction, MAX, "jmp %s", end_label);
        insertSourceCode(elseEnd, formattedInstruction);

        snprintf(formattedInstruction, MAX, "%s:", end_label);
        insertSourceCode(lenSourceCode, formattedInstruction);

        free((yyvsp[-2].strval));
        // free($6);
    }
#line 1504 "asm_synt.tab.c"
    break;

  case 32: /* return_statement: RETURN arithmetic_expression SEMICOLON  */
#line 317 "asm_synt.y"
    {
        sprintf(sourceCode[lenSourceCode++], "mov eax, %s\nret", (yyvsp[-1].strval));
    }
#line 1512 "asm_synt.tab.c"
    break;

  case 33: /* condition: term EQ term  */
#line 324 "asm_synt.y"
    {
        if (isdigit((yyvsp[-2].strval)[0])) {
            sprintf(sourceCode[lenSourceCode++], "mov ebx, %s", (yyvsp[-2].strval));
        } else {
            sprintf(sourceCode[lenSourceCode++], "mov ebx, [%s]", (yyvsp[-2].strval));
        }

        if (isdigit((yyvsp[0].strval)[0])) {
            sprintf(sourceCode[lenSourceCode++], "mov eax, %s", (yyvsp[0].strval));
        } else {
            sprintf(sourceCode[lenSourceCode++], "mov eax, [%s]", (yyvsp[0].strval));
        }

        strcpy(sourceCode[lenSourceCode++], "cmp ebx, eax");

        // Format the string as "startIndex:endIndex"
        char* rangeStr = (char*)malloc(20);
        sprintf(rangeStr, "%d:%d", lenSourceCode - 1, lenSourceCode);
        (yyval.strval) = rangeStr;
    }
#line 1537 "asm_synt.tab.c"
    break;

  case 34: /* condition: term NE term  */
#line 346 "asm_synt.y"
    {
        if (isdigit((yyvsp[-2].strval)[0])) {
            sprintf(sourceCode[lenSourceCode++], "mov ebx, %s", (yyvsp[-2].strval));
        } else {
            sprintf(sourceCode[lenSourceCode++], "mov ebx, [%s]", (yyvsp[-2].strval));
        }

        if (isdigit((yyvsp[0].strval)[0])) {
            sprintf(sourceCode[lenSourceCode++], "mov eax, %s", (yyvsp[0].strval));
        } else {
            sprintf(sourceCode[lenSourceCode++], "mov eax, [%s]", (yyvsp[0].strval));
        }

        strcpy(sourceCode[lenSourceCode++], "cmp eax, ebx");

        // Format the string as "startIndex:endIndex"
        char* rangeStr = (char*)malloc(20);
        sprintf(rangeStr, "%d:%d", lenSourceCode - 1, lenSourceCode);
        (yyval.strval) = rangeStr;
    }
#line 1562 "asm_synt.tab.c"
    break;

  case 35: /* arithmetic_expression: arithmetic_expression PLUS term  */
#line 371 "asm_synt.y"
    {
        strncpy(expressions[lenExpressions++], "+", MAX - 1);
        strncpy(expressions[lenExpressions], (yyvsp[0].strval), MAX - 1);
        expressions[lenExpressions][MAX - 1] = '\0';
        lenExpressions++;
    }
#line 1573 "asm_synt.tab.c"
    break;

  case 36: /* arithmetic_expression: arithmetic_expression MINUS term  */
#line 378 "asm_synt.y"
    {
        strncpy(expressions[lenExpressions++], "-", MAX - 1);
        strncpy(expressions[lenExpressions], (yyvsp[0].strval), MAX - 1);
        expressions[lenExpressions][MAX - 1] = '\0';
        lenExpressions++;
    }
#line 1584 "asm_synt.tab.c"
    break;

  case 37: /* arithmetic_expression: arithmetic_expression MULTIPLY term  */
#line 385 "asm_synt.y"
    {
        strncpy(expressions[lenExpressions++], "*", MAX - 1);
        strncpy(expressions[lenExpressions], (yyvsp[0].strval), MAX - 1);
        expressions[lenExpressions][MAX - 1] = '\0';
        lenExpressions++;
    }
#line 1595 "asm_synt.tab.c"
    break;

  case 38: /* arithmetic_expression: arithmetic_expression DIVIDE term  */
#line 392 "asm_synt.y"
    {
        strncpy(expressions[lenExpressions++], "/", MAX - 1);
        strncpy(expressions[lenExpressions], (yyvsp[0].strval), MAX - 1);
        expressions[lenExpressions][MAX - 1] = '\0';
        lenExpressions++;
    }
#line 1606 "asm_synt.tab.c"
    break;

  case 39: /* arithmetic_expression: term  */
#line 399 "asm_synt.y"
    {
        strncpy(expressions[lenExpressions], (yyvsp[0].strval), MAX - 1);
        expressions[lenExpressions][MAX - 1] = '\0';
        lenExpressions++;
    }
#line 1616 "asm_synt.tab.c"
    break;

  case 40: /* term: CONST_INT  */
#line 408 "asm_synt.y"
    {
        printf("Processed CONST_INT: %s\n", (yyvsp[0].strval));
        // strncpy(expressions[lenExpressions], $1, MAX - 1);
        // expressions[lenExpressions][MAX - 1] = '\0';
        // lenExpressions++;
    }
#line 1627 "asm_synt.tab.c"
    break;

  case 41: /* term: ID  */
#line 415 "asm_synt.y"
    {
        printf("Processed ID: %s\n", (yyvsp[0].strval));
        // strncpy(expressions[lenExpressions], $1, MAX - 1);
        // expressions[lenExpressions][MAX - 1] = '\0';
        // lenExpressions++;
    }
#line 1638 "asm_synt.tab.c"
    break;

  case 42: /* term: LPAREN arithmetic_expression RPAREN  */
#line 422 "asm_synt.y"
    {
        printf("Processed Parenthesized Expression\n");
    }
#line 1646 "asm_synt.tab.c"
    break;


#line 1650 "asm_synt.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 433 "asm_synt.y"


int main(int argc, char* argv[]) {
    FILE* f = NULL;
    if (argc > 1) {
        f = fopen(argv[1], "r");
    }

    if (!f) {
        perror("Could not open file!");
        yyin = stdin;
    } else {
        yyin = f;
    }
    strcpy(imports[lenImports++],"exit");
    while(!feof(yyin)) {
        yyparse();
    }
    printf("Parsing done\n");
    char outputFile[100]="";
    strcat(outputFile, argv[1]);
    strcat(outputFile, "_asm.asm");
    asm_out = fopen(outputFile, "w");
    

    printf("Parsing done\n");
    fprintf(asm_out, "bits 32\nglobal main\n\n");
    printf("Printing imports\n");
    printf("bits 32\nglobal _start\n\n");
   
    printf("Done printing imports\n");
    fprintf(asm_out, "section .data\n");
    printf("section .data\n");
    printDeclarationSegment();
    fprintf(asm_out, "section .text\n");
 printImports();
    printf("section .text\n");
    printf("main:\n");
    fprintf(asm_out, "main:\n");
    printCodeSegment();

    fprintf(asm_out, "\tpush dword 0\n\tcall exit\n");
    printf("\tpush dword 0\n\tcall exit\n");
    fclose(asm_out);
    printf("All OK\n");
    for(int i = 0; i < lenDeclarations; i++) {
        printf("%s\n", declarations[i]);
    }
    printf("----------------");
    for(int i = 0; i < lenSourceCode; i++) {
        printf("%s\n", sourceCode[i]);
    }
    printf("----------------");
    for(int i = 0; i < lenImports; i++) {
        printf("%s\n", imports[i]);
    }
    printf("----------------");
    for(int i=0;i<lenExpressions;i++)
    {
        printf("%s\n",expressions[i]);
    }
    // free stuff 
    return 0;
}

bool found(char col[][MAX], int n, char* var) {

    for (int i = 0; i < n; i++) {
        printf("Comparing %s with %s\n", col[i], var);
        fflush(stdout);
        if (strstr(col[i], var) != NULL) {
            return true;
        }
    }
    return false;}

void parseExpression(char* element) {
    if (isdigit(expressions[0][0])) {
        sprintf(sourceCode[lenSourceCode++], "mov eax, %s", expressions[0]);
    } else {
        sprintf(sourceCode[lenSourceCode++], "mov eax, [%s]", expressions[0]);
    }

    for (int i = 1; i < lenExpressions - 1; i += 2) {
        char* operator = expressions[i];
        char* nextTerm = expressions[i + 1];

        if (strcmp(operator, "*") == 0 || strcmp(operator, "/") == 0) {
            // Procesare înmulțire sau împărțire
            if (isdigit(nextTerm[0])) {
                sprintf(sourceCode[lenSourceCode++], "imul eax, %s", nextTerm);
            } else {
                sprintf(sourceCode[lenSourceCode++], "imul eax, [%s]", nextTerm);
            }
        } else {
            // Procesare adunare sau scădere
            sprintf(sourceCode[lenSourceCode++], "push eax");

            if (isdigit(nextTerm[0])) {
                sprintf(sourceCode[lenSourceCode++], "mov eax, %s", nextTerm);
            } else {
                sprintf(sourceCode[lenSourceCode++], "mov eax, [%s]", nextTerm);
            }

            while (i + 2 < lenExpressions && (strcmp(expressions[i + 2], "*") == 0 || strcmp(expressions[i + 2], "/") == 0)) {
                i += 2;
                nextTerm = expressions[i + 1];

                if (strcmp(expressions[i], "*") == 0) {
                    if (isdigit(nextTerm[0])) {
                        sprintf(sourceCode[lenSourceCode++], "imul eax, %s", nextTerm);
                    } else {
                        sprintf(sourceCode[lenSourceCode++], "imul eax, [%s]", nextTerm);
                    }
                }
            }

            sprintf(sourceCode[lenSourceCode++], "pop ebx");

            if (strcmp(operator, "+") == 0) {
                sprintf(sourceCode[lenSourceCode++], "add eax, ebx");
            } else {
                sprintf(sourceCode[lenSourceCode++], "sub eax, ebx");
            }
        }
    }

    if (element != NULL) {
        sprintf(sourceCode[lenSourceCode++], "mov [%s], eax", element);
    }

    lenExpressions = 0;
}



void printImports() {
    printf("Printing imports\n");
    for (int i = 0; i < lenImports; i++) {
        fprintf(asm_out, "extern %s\n", imports[i]);
        printf("extern %s\n", imports[i]);
    }
    printf("Done printing imports\n");
}

void printDeclarationSegment() {
    printf("Printing declarations\n");
    for (int i = 0; i < lenDeclarations; i++) {
        printf("%s\n", declarations[i]);
        fprintf(asm_out, "%s\n", declarations[i]);
    }
    //default format string
    fprintf(asm_out, "\tformat db \"%%d\", 0\n");
    fprintf(asm_out,"\tendl db 0Ah, 0\n");

    printf("Done printing declarations\n");
}

void printCodeSegment() {
    printf("Printing code\n");

    // Print the buffered source code
    for (int i = 0; i < lenSourceCode; i++) {
        fprintf(asm_out, "\t%s\n", sourceCode[i]);
        printf("\t%s\n", sourceCode[i]);
    }

    printf("Done printing code\n");
}

