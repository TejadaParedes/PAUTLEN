/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "alfa.y" /* yacc.c:339  */


#include <stdio.h>
#include <string.h> 
#include "alfa.h"  

int yylex();
void yyerror();
extern FILE* yyout;
extern int n_linea;
extern int n_columna;
extern int error;

TIPO tipo;
CLASE clase;
int tam_vector;

INFO_SIMBOLO *is;

INFO_SIMBOLO is_aux;

int num_no = 0;
int num_cmp = 0;
int num_cond = 0;
int num_loops = 0;
int idx_variable_local = 0;
int num_local_variables = 0;
int num_parametros = 0;
int idx_parametro = 0;
int is_function = 0;
int is_call_function = 0;
int parametros = 0;
int existe_return = 0;


#line 102 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_MAIN = 258,
    TOK_INT = 259,
    TOK_BOOLEAN = 260,
    TOK_ARRAY = 261,
    TOK_FUNCTION = 262,
    TOK_IF = 263,
    TOK_ELSE = 264,
    TOK_WHILE = 265,
    TOK_SCANF = 266,
    TOK_PRINTF = 267,
    TOK_RETURN = 268,
    TOK_IGUAL = 269,
    TOK_AND = 270,
    TOK_OR = 271,
    TOK_DISTINTO = 272,
    TOK_MENORIGUAL = 273,
    TOK_MAYORIGUAL = 274,
    TOK_MENOR = 275,
    TOK_MAYOR = 276,
    TOK_NOT = 277,
    TOK_PUNTOYCOMA = 278,
    TOK_COMA = 279,
    TOK_PARENTESISIZQUIERDO = 280,
    TOK_PARENTESISDERECHO = 281,
    TOK_CORCHETEIZQUIERDO = 282,
    TOK_CORCHETEDERECHO = 283,
    TOK_LLAVEIZQUIERDA = 284,
    TOK_LLAVEDERECHA = 285,
    TOK_ASIGNACION = 286,
    TOK_MAS = 287,
    TOK_MENOS = 288,
    TOK_DIVISION = 289,
    TOK_ASTERISCO = 290,
    TOK_TRUE = 291,
    TOK_FALSE = 292,
    TOK_CONSTANTE_ENTERA = 293,
    TOK_IDENTIFICADOR = 294,
    TOK_ERROR = 295,
    MENOSU = 296
  };
#endif
/* Tokens.  */
#define TOK_MAIN 258
#define TOK_INT 259
#define TOK_BOOLEAN 260
#define TOK_ARRAY 261
#define TOK_FUNCTION 262
#define TOK_IF 263
#define TOK_ELSE 264
#define TOK_WHILE 265
#define TOK_SCANF 266
#define TOK_PRINTF 267
#define TOK_RETURN 268
#define TOK_IGUAL 269
#define TOK_AND 270
#define TOK_OR 271
#define TOK_DISTINTO 272
#define TOK_MENORIGUAL 273
#define TOK_MAYORIGUAL 274
#define TOK_MENOR 275
#define TOK_MAYOR 276
#define TOK_NOT 277
#define TOK_PUNTOYCOMA 278
#define TOK_COMA 279
#define TOK_PARENTESISIZQUIERDO 280
#define TOK_PARENTESISDERECHO 281
#define TOK_CORCHETEIZQUIERDO 282
#define TOK_CORCHETEDERECHO 283
#define TOK_LLAVEIZQUIERDA 284
#define TOK_LLAVEDERECHA 285
#define TOK_ASIGNACION 286
#define TOK_MAS 287
#define TOK_MENOS 288
#define TOK_DIVISION 289
#define TOK_ASTERISCO 290
#define TOK_TRUE 291
#define TOK_FALSE 292
#define TOK_CONSTANTE_ENTERA 293
#define TOK_IDENTIFICADOR 294
#define TOK_ERROR 295
#define MENOSU 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 102 "alfa.y" /* yacc.c:355  */

    TIPO_ATRIBUTOS atributos;

#line 225 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 242 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   144

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  152

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   107,   107,   110,   111,   114,   117,   118,   121,   124,
     125,   128,   137,   138,   141,   142,   145,   169,   182,   200,
     201,   204,   205,   208,   214,   228,   229,   232,   233,   236,
     237,   240,   241,   242,   243,   246,   247,   250,   280,   289,
     313,   317,   322,   333,   338,   343,   349,   359,   369,   374,
     384,   394,   404,   414,   424,   434,   444,   454,   464,   488,
     494,   499,   504,   507,   519,   530,   534,   539,   542,   545,
     551,   559,   567,   575,   583,   591,   601,   607,   615,   621,
     629,   636,   665,   667
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_MAIN", "TOK_INT", "TOK_BOOLEAN",
  "TOK_ARRAY", "TOK_FUNCTION", "TOK_IF", "TOK_ELSE", "TOK_WHILE",
  "TOK_SCANF", "TOK_PRINTF", "TOK_RETURN", "TOK_IGUAL", "TOK_AND",
  "TOK_OR", "TOK_DISTINTO", "TOK_MENORIGUAL", "TOK_MAYORIGUAL",
  "TOK_MENOR", "TOK_MAYOR", "TOK_NOT", "TOK_PUNTOYCOMA", "TOK_COMA",
  "TOK_PARENTESISIZQUIERDO", "TOK_PARENTESISDERECHO",
  "TOK_CORCHETEIZQUIERDO", "TOK_CORCHETEDERECHO", "TOK_LLAVEIZQUIERDA",
  "TOK_LLAVEDERECHA", "TOK_ASIGNACION", "TOK_MAS", "TOK_MENOS",
  "TOK_DIVISION", "TOK_ASTERISCO", "TOK_TRUE", "TOK_FALSE",
  "TOK_CONSTANTE_ENTERA", "TOK_IDENTIFICADOR", "TOK_ERROR", "MENOSU",
  "$accept", "programa", "declaraciones", "declaracion", "clase",
  "clase_escalar", "tipo", "clase_vector", "identificadores", "funciones",
  "funct_name", "funct_name_params", "funcion", "parametros_funcion",
  "resto_parametros_funcion", "parametro_funcion", "pfid",
  "declaraciones_funcion", "sentencias", "sentencia", "sentencia_simple",
  "bloque", "asignacion", "elemento_vector", "condicional",
  "if_statement_sentencias", "if_statement", "bucle", "while_star",
  "while_end", "lectura", "escritura", "retorno_funcion", "exp",
  "funct_call_star", "lista_expresiones", "resto_lista_expresiones",
  "expf", "comparacion", "constante", "constante_logica",
  "constante_entera", "identificador", "escribirTabla", "escribirMain", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

#define YYPACT_NINF -32

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-32)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       0,    -6,     9,     8,   -32,   -32,   -32,    14,   -32,     8,
      -8,   -32,   -32,   -32,    10,    29,   -32,   -32,    23,    25,
      28,    14,   -32,    37,    16,    29,   -32,    -8,    35,    15,
      16,    14,    42,    43,    55,    98,    98,   -20,    46,    16,
      72,   -32,   -32,    69,   -32,    16,    71,   -32,    98,    16,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,    76,    74,    83,
      88,    98,   -32,   -32,    98,    98,    98,   -32,   -32,   -32,
      26,   -32,    45,    98,   -32,   -32,   -32,    45,    98,    98,
     -32,   -32,   -32,    98,   -32,   112,    49,    92,   -32,   -32,
     -32,    95,    14,   -32,    70,   -32,    24,    99,   -32,   -32,
      98,    98,    98,    98,    98,    98,    45,   100,   103,    82,
      45,    45,   101,   104,   -32,     8,    88,   109,    98,    98,
      98,    98,    98,    98,   -32,   -32,   -32,    84,    84,    84,
     -32,   -32,   -32,    98,   -32,   -32,    16,   -32,   -32,   -32,
     -32,   -32,    45,    45,    45,    45,    45,    45,   103,   102,
     -32,   -32
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     9,    10,     0,    82,     3,
       0,     6,     8,     7,     0,    15,     4,    81,     0,    12,
       0,     0,    83,     0,     0,    15,     5,     0,     0,     0,
       0,    20,     0,     0,     0,     0,     0,     0,     0,    27,
       0,    30,    31,     0,    35,     0,     0,    36,     0,     0,
      32,    33,    34,    14,    13,    11,    16,     0,     0,     0,
      22,     0,    45,    47,     0,     0,     0,    78,    79,    80,
      58,    62,    48,    66,    59,    76,    77,    49,     0,     0,
      18,    28,    29,     0,    43,    40,     0,     0,     2,    24,
      23,     0,     0,    19,     0,    57,     0,     0,    54,    64,
       0,     0,     0,     0,     0,     0,    69,     0,    68,     0,
      37,    38,     0,     0,    44,    26,    22,     0,     0,     0,
       0,     0,     0,     0,    60,    61,    55,    56,    50,    51,
      52,    53,    63,     0,    65,    39,     0,    46,    25,    17,
      21,    42,    70,    71,    72,    73,    74,    75,    68,     0,
      67,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -32,   -32,    -7,   -32,   -32,   -32,     1,   -32,   113,   114,
     -32,   -32,   -32,   -32,    12,    50,   -32,   -32,   -29,   -32,
     -32,   -32,   -32,   -24,   -32,   -32,   -32,   -32,   -32,   -32,
     -32,   -32,   -32,   -31,   -32,   -32,   -19,    11,   -32,   -32,
     -32,   -32,   -32,   -32,   -32
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,    10,    11,    12,    13,    18,    22,
      23,    24,    25,    59,    93,    60,    90,   139,    38,    39,
      40,    41,    42,    71,    44,    45,    46,    47,    48,    49,
      50,    51,    52,   106,    73,   107,   134,   108,    97,    74,
      75,    76,    19,    15,    30
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      43,    57,    16,     1,    72,    77,    43,    78,    14,     4,
      81,    79,     5,     6,     7,    43,    84,    86,     5,     6,
      87,    43,    29,     3,    32,    43,    33,    34,    35,    36,
      94,    17,    58,    95,    96,    98,    21,    20,   118,   100,
     101,   119,   120,   121,   122,   123,    26,   109,   110,    27,
     124,    99,   111,    78,    56,    37,   102,   103,   104,   105,
     100,   101,    31,    55,   100,   101,    28,    61,    62,   126,
     127,   128,   129,   130,   131,   113,    80,   102,   103,   104,
     105,   102,   103,   104,   105,   100,   101,   142,   143,   144,
     145,   146,   147,    58,    63,    82,   117,   100,   101,   100,
      83,    85,   102,   103,   104,   105,    88,   149,   138,    91,
     135,    92,    43,    89,   102,   103,   104,   105,   104,   105,
      64,   112,   114,    65,   115,   125,   132,   133,   140,   150,
     136,    66,   151,   137,    67,    68,    69,    70,   141,    53,
      54,     0,   116,     0,   148
};

static const yytype_int16 yycheck[] =
{
      24,    30,     9,     3,    35,    36,    30,    27,     7,     0,
      39,    31,     4,     5,     6,    39,    45,    48,     4,     5,
      49,    45,    21,    29,     8,    49,    10,    11,    12,    13,
      61,    39,    31,    64,    65,    66,     7,    27,    14,    15,
      16,    17,    18,    19,    20,    21,    23,    78,    79,    24,
      26,    25,    83,    27,    39,    39,    32,    33,    34,    35,
      15,    16,    25,    28,    15,    16,    38,    25,    25,   100,
     101,   102,   103,   104,   105,    26,    30,    32,    33,    34,
      35,    32,    33,    34,    35,    15,    16,   118,   119,   120,
     121,   122,   123,    92,    39,    23,    26,    15,    16,    15,
      31,    30,    32,    33,    34,    35,    30,   136,   115,    26,
      28,    23,   136,    39,    32,    33,    34,    35,    34,    35,
      22,     9,    30,    25,    29,    26,    26,    24,   116,   148,
      29,    33,    30,    29,    36,    37,    38,    39,    29,    25,
      27,    -1,    92,    -1,   133
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    43,    29,     0,     4,     5,     6,    44,    45,
      46,    47,    48,    49,    48,    85,    44,    39,    50,    84,
      27,     7,    51,    52,    53,    54,    23,    24,    38,    48,
      86,    25,     8,    10,    11,    12,    13,    39,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    51,    50,    28,    39,    60,    48,    55,
      57,    25,    25,    39,    22,    25,    33,    36,    37,    38,
      39,    65,    75,    76,    81,    82,    83,    75,    27,    31,
      30,    60,    23,    31,    60,    30,    75,    60,    30,    39,
      58,    26,    23,    56,    75,    75,    75,    80,    75,    25,
      15,    16,    32,    33,    34,    35,    75,    77,    79,    75,
      75,    75,     9,    26,    30,    29,    57,    26,    14,    17,
      18,    19,    20,    21,    26,    26,    75,    75,    75,    75,
      75,    75,    26,    24,    78,    28,    29,    29,    44,    59,
      56,    29,    75,    75,    75,    75,    75,    75,    79,    60,
      78,    30
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    46,    46,    47,    48,
      48,    49,    50,    50,    51,    51,    52,    53,    54,    55,
      55,    56,    56,    57,    58,    59,    59,    60,    60,    61,
      61,    62,    62,    62,    62,    63,    63,    64,    64,    65,
      66,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    76,    77,    77,    78,    78,    79,
      80,    80,    80,    80,    80,    80,    81,    81,    82,    82,
      83,    84,    85,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     1,     2,     3,     1,     1,     1,     1,
       1,     5,     1,     3,     2,     0,     3,     6,     3,     2,
       0,     3,     0,     2,     1,     1,     0,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     4,
       2,     6,     5,     2,     3,     2,     4,     2,     2,     2,
       3,     3,     3,     3,     2,     3,     3,     2,     1,     1,
       3,     3,     1,     3,     2,     2,     0,     3,     0,     1,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     0,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 107 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");}
#line 1439 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 110 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R2:\t<declaraciones> ::= <declaracion>\n");}
#line 1445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 111 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");}
#line 1451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 114 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");}
#line 1457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 117 "alfa.y" /* yacc.c:1646  */
    {clase = ESCALAR; fprintf(yyout, ";R5:\t<clase> ::= <clase_escalar>\n");}
#line 1463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 118 "alfa.y" /* yacc.c:1646  */
    {clase = VECTOR; fprintf(yyout, ";R7:\t<clase> ::= <clase_vector>\n");}
#line 1469 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 121 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R9:\t<clase_escalar> ::= <tipo>\n");}
#line 1475 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 124 "alfa.y" /* yacc.c:1646  */
    {tipo = ENTERO; fprintf(yyout, ";R10:\t<tipo> ::= int\n");}
#line 1481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 125 "alfa.y" /* yacc.c:1646  */
    {tipo = BOOLEANO; fprintf(yyout, ";R11:\t<tipo> ::= boolean\n");}
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 128 "alfa.y" /* yacc.c:1646  */
    {
    tam_vector = (yyvsp[-1].atributos).valor_entero;
    if(tam_vector < 1 || tam_vector > MAX_TAMANIO_VECTOR){
        fprintf(stderr, "****Error semantico en linea %d: El tamanyo del vector %s excede los limites permitidos (1,64).\n", n_linea, (yyvsp[-1].atributos).lexema);
        return -1;
    }
    fprintf(yyout, ";R15:\t<clase_vector> ::= array <tipo> [ <constante_entera> ]\n");}
#line 1499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 137 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R18:\t<identificadores> ::= <identificador>\n");}
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 138 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");}
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 141 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R20:\t<funciones> ::= <funcion> <funciones>\n");}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 142 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R21:\t<funciones> ::=\n");}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 145 "alfa.y" /* yacc.c:1646  */
    {
    existe_return = 0;
    is_function = 1;
    is = BuscarSimbolo((yyvsp[0].atributos).lexema);
    if(is){
        fprintf(stderr, "****Error semantico en la linea %d: Declaracion duplicada.\n", n_linea);
        return -1;
    }

    is_aux.lexema = (yyvsp[0].atributos).lexema;
    is_aux.categoria = FUNCION;
    is_aux.tipo = tipo;
    is_aux.clase = ESCALAR;

    strcpy((yyval.atributos).lexema, (yyvsp[0].atributos).lexema);
    (yyval.atributos).tipo = tipo;

    declararFuncion((yyvsp[0].atributos).lexema, &is_aux);
    idx_variable_local = 0;
    num_local_variables = 0;
    idx_parametro = 0;
    num_parametros = 0;
}
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 169 "alfa.y" /* yacc.c:1646  */
    {

    is = BuscarSimbolo((yyvsp[-5].atributos).lexema);
    if(!is){
        fprintf(stderr, "****Error semantico en la linea %d: Declaracion duplicada.", n_linea);
        return -1;
    }
    is->adicional1 = num_parametros;
    strcpy((yyval.atributos).lexema, (yyvsp[-5].atributos).lexema);
    (yyval.atributos).tipo = (yyvsp[-5].atributos).tipo;
    declarar_Funcion(yyout, (yyvsp[-5].atributos).lexema, num_local_variables);
}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 182 "alfa.y" /* yacc.c:1646  */
    {

    if(!existe_return){
        fprintf(stderr, "****Error semantico en lin %d: Funcion %s sin sentencia de retorno.", n_linea, (yyvsp[-2].atributos).lexema);
        return -1;
    }
    cerrarFuncion();
    funcionFin(yyout);
    is = BuscarSimbolo((yyvsp[-2].atributos).lexema);
    if(!is){
        fprintf(stderr, "****Error semantico en la linea %d: Declaracion duplicada.", n_linea);
        return -1;
    }
    is->adicional1 = num_parametros; 
    is_function = 0;
    fprintf(yyout, ";R22:\t<funcion> ::= function <tipo> <identificador> ( <parametros_funcion> ){ <declaracion_funcion> <sentencias> }\n");}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 200 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 201 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R24:\t<parametros_funcion> ::=\n");}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 204 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R25:\t<resto_parametros_funcion> ::= ;<parametro_funcion> <resto_parametros_funcion>\n");}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 205 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R26:\t<resto_parametros_funcion> ::=\n");}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 208 "alfa.y" /* yacc.c:1646  */
    {
    num_parametros++;
    idx_parametro++;
    fprintf(yyout, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 214 "alfa.y" /* yacc.c:1646  */
    {
    is = BuscarSimbolo((yyvsp[0].atributos).lexema);
    if(is){
        fprintf(stderr, "****Error semantico en la linea %d: Declaracion duplicada.\n", n_linea);
        return -1;
    }
    is_aux.lexema = (yyvsp[0].atributos).lexema;
    is_aux.categoria = PARAMETRO;
    is_aux.clase = ESCALAR;
    is_aux.tipo = tipo;
    is_aux.adicional1 = num_parametros;
    declarar((yyvsp[0].atributos).lexema, &is_aux);
}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 228 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 229 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R29:\t<declaraciones_funcion> ::=\n");}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 232 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R30:\t<sentencias> ::= <sentencia>\n");}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 233 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 236 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R32:\t<sentencia> ::= <sentencia_simple> ;\n");}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 237 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R33:\t<sentencia> ::= <bloque>\n");}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 240 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R34:\t<sentencia_simple> ::= <asignacion>\n");}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 241 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R35:\t<sentencia_simple> ::= <lectura>\n");}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 242 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R36:\t<sentencia_simple> ::= <escritura>\n");}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 243 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 246 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R40:\t<bloque> ::= <condicional>\n");}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 247 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R41:\t<bloque> ::= <bucle>\n");}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 250 "alfa.y" /* yacc.c:1646  */
    {
    is = BuscarSimbolo((yyvsp[-2].atributos).lexema);
    if(!is){
       fprintf(stderr, "****Error semantico en lin %d: Acceso a variable no declarada (%s).\n", n_linea, (yyvsp[-2].atributos).lexema);
        return -1; 
    }
    else{
        if(is->categoria == FUNCION){
            fprintf(stderr, "****Error semantico en lin %d: Asignacion incompatible.\n", n_linea);
            return -1;
        }
        else if(is->clase == VECTOR){
            fprintf(stderr, "****Error semantico en lin %d: Asignacion incompatible.\n", n_linea);
            return -1;
        }
        else if(is->tipo != (yyvsp[0].atributos).tipo){
            fprintf(stderr, "****Error semantico en lin %d: Asignacion incompatible.\n", n_linea);
            return -1;
        }
        else if(!usoGlobal((yyvsp[-2].atributos).lexema)){
            if(is->categoria == PARAMETRO) asignar_local(yyout, num_parametros-is->adicional1+1, (yyvsp[0].atributos).es_direccion);
            else asignar_local(yyout, -(is->adicional1+1), (yyvsp[0].atributos).es_direccion);
        }
        else{
            asignar(yyout, (yyvsp[-2].atributos).lexema, (yyvsp[0].atributos).es_direccion);
            fprintf(yyout, ";R43:\t<asignacion> ::= <identificador> = <exp>\n");
        }

    }
}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 280 "alfa.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].atributos).tipo != (yyvsp[0].atributos).tipo){
            fprintf(stderr, "****Error semantico en lin %d: Asignacion incompatible.\n", n_linea);
            return -1;
        }
        asignar_vector(yyout, (yyvsp[0].atributos).es_direccion);
        fprintf(yyout, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 289 "alfa.y" /* yacc.c:1646  */
    {
    is = BuscarSimbolo((yyvsp[-3].atributos).lexema);
    if(!is){
        fprintf(stderr, "****Error semantico en lin %d: Acceso a variable no declarada (%s).\n", n_linea, (yyvsp[-3].atributos).lexema);
        return -1;
    }
    else if(is->clase == ESCALAR){
        fprintf(stderr, "****Error semantico en lin %d: Intento de indexacion de una variable que no es de tipo vector.\n", n_linea);
        return -1;
    }

    (yyval.atributos).tipo = is->tipo;
    (yyval.atributos).es_direccion = 1;

    if((yyvsp[-1].atributos).tipo != ENTERO){
        fprintf(stderr, "****Error semantico en lin %d: El indice en una operacion de indexacion tiene que ser de tipo entero.\n", n_linea);
        return -1;
    }

    escribir_elemento_vector(yyout, (yyvsp[-3].atributos).lexema, is->adicional1, (yyvsp[-1].atributos).es_direccion);

    fprintf(yyout, ";R48:\t<elemento_vector> ::= <identificador> = [ <exp> ]\n");}
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 313 "alfa.y" /* yacc.c:1646  */
    {
    
    ifthenelse_fin(yyout, (yyvsp[-1].atributos).etiqueta); /***---*/
    fprintf(yyout, ";R50:\t<condicional> ::= <identificador> = if( <exp> ){ <sentencias> }\n");}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 317 "alfa.y" /* yacc.c:1646  */
    {
        ifthenelse_fin(yyout, (yyvsp[-5].atributos).etiqueta);
        fprintf(yyout, ";R51:\t<condicional> ::= <identificador> = if( <exp> ){ <sentencias> } else { <sentencias> }\n");}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 322 "alfa.y" /* yacc.c:1646  */
    {
    if((yyvsp[-2].atributos).tipo != BOOLEANO){
        fprintf(stderr, "****Error semantico en lin %d: Condicional con condicion de tipo int.\n", n_linea);
        return -1;
    }

    (yyval.atributos).etiqueta = num_cond++;

    ifthen_inicio(yyout, (yyvsp[-2].atributos).es_direccion, (yyval.atributos).etiqueta);
}
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 333 "alfa.y" /* yacc.c:1646  */
    {
    (yyval.atributos).etiqueta = (yyvsp[-1].atributos).etiqueta;
    ifthenelse_fin_then(yyout, (yyval.atributos).etiqueta);
}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 338 "alfa.y" /* yacc.c:1646  */
    {
    while_fin(yyout, (yyvsp[-2].atributos).etiqueta);
    fprintf(yyout, ";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 343 "alfa.y" /* yacc.c:1646  */
    {

    (yyval.atributos).etiqueta = num_loops++;
    while_inicio(yyout, (yyval.atributos).etiqueta);
}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 349 "alfa.y" /* yacc.c:1646  */
    {
    if((yyvsp[-2].atributos).tipo != BOOLEANO){
        fprintf(yyout, "****Error semantico en lin %d: Bucle con condicion de tipo int.\n", n_linea);
        return -1;
    }

    (yyval.atributos).etiqueta = (yyvsp[-3].atributos).etiqueta;
    while_exp_pila(yyout, (yyvsp[-2].atributos).es_direccion, (yyval.atributos).etiqueta);
}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 359 "alfa.y" /* yacc.c:1646  */
    {
    is = BuscarSimbolo((yyvsp[0].atributos).lexema);
    if(!is){
        fprintf(stderr, "****Error semantico en lin %d: Acceso a variable no declarada (%s).\n", n_linea, (yyvsp[0].atributos).lexema);
        return -1;
    }
    leer(yyout, (yyvsp[0].atributos).lexema, is->tipo);
    fprintf(yyout, ";R54:\t<lectura> ::= scanf <identificador>\n");}
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 369 "alfa.y" /* yacc.c:1646  */
    {
    escribir(yyout, !((yyvsp[0].atributos).es_direccion), (yyvsp[0].atributos).tipo);
    fprintf(yyout, ";R56:\t<escritura> ::= printf <exp>\n");}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 374 "alfa.y" /* yacc.c:1646  */
    {
    if(!is_function){
        fprintf(stderr, "****Error semantico en lin %d: Sentencia de retorno fuera del cuerpo de una función.\n", n_linea);
        return -1;
    }
    existe_return = 1;
    retornarFuncion(yyout, (yyvsp[0].atributos).es_direccion);
    fprintf(yyout, ";R61:\t<retorno_funcion> ::= return <exp>\n");}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 384 "alfa.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO){
            fprintf(stderr, "****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", n_linea);
            return -1;
        }
        sumar(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        (yyval.atributos).es_direccion = 0;
        (yyval.atributos).tipo = ENTERO;
        fprintf(yyout, ";R72:\t<exp> ::= <exp> + <exp>\n");
    }
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 394 "alfa.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO){
            fprintf(stderr, "****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", n_linea);
            return -1;
        }
        restar(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        (yyval.atributos).es_direccion = 0;
        (yyval.atributos).tipo = ENTERO;
        fprintf(yyout, ";R73:\t<exp> ::= <exp> - <exp>\n");
    }
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 404 "alfa.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO){
            fprintf(stderr, "****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", n_linea);
            return -1;
        }
        dividir(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        (yyval.atributos).es_direccion = 0;
        (yyval.atributos).tipo = ENTERO;
        fprintf(yyout, ";R74:\t<exp> ::= <exp> / <exp>\n");
    }
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 414 "alfa.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO){
            fprintf(stderr, "****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", n_linea);
            return -1;
        }
        multiplicar(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        (yyval.atributos).es_direccion = 0;
        (yyval.atributos).tipo = ENTERO;
        fprintf(yyout, ";R75:\t<exp> ::= <exp> * <exp>\n");
    }
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 424 "alfa.y" /* yacc.c:1646  */
    {
        if((yyvsp[0].atributos).tipo != ENTERO){
            fprintf(stderr, "****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", n_linea);
            return -1;
        }
        cambiar_signo(yyout, (yyvsp[0].atributos).es_direccion);
        (yyval.atributos).es_direccion = 0;
        (yyval.atributos).tipo = ENTERO;
        fprintf(yyout, ";R76:\t<exp> ::= - <exp>\n");
    }
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 434 "alfa.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].atributos).tipo != BOOLEANO || (yyvsp[0].atributos).tipo != BOOLEANO){
            fprintf(stderr, "****Error semantico en lin %d: Operacion logica con operandos int.\n", n_linea);
            return -1;
        }
        y(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        (yyval.atributos).es_direccion = 0;
        (yyval.atributos).tipo = BOOLEANO;
        fprintf(yyout, ";R77:\t<exp> ::= <exp> && <exp>\n");
    }
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 444 "alfa.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].atributos).tipo != BOOLEANO || (yyvsp[0].atributos).tipo != BOOLEANO){
            fprintf(stderr, "****Error semantico en lin %d: Operacion logica con operandos int.\n", n_linea);
            return -1;
        }
        o(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        (yyval.atributos).es_direccion = 0;
        (yyval.atributos).tipo = BOOLEANO;
        fprintf(yyout, ";R78:\t<exp> ::= <exp> || <exp>\n");
    }
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 454 "alfa.y" /* yacc.c:1646  */
    {
        if((yyvsp[0].atributos).tipo != BOOLEANO){
            fprintf(stderr, "****Error semantico en lin %d: Operacion logica con operandos int.\n", n_linea);
            return -1;
        }
        no(yyout, (yyvsp[0].atributos).es_direccion, num_no++);
        (yyval.atributos).es_direccion = 0;
        (yyval.atributos).tipo = BOOLEANO;
        fprintf(yyout, ";R79:\t<exp> ::= ! <exp>\n");
    }
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 464 "alfa.y" /* yacc.c:1646  */
    {
        strcpy((yyval.atributos).lexema, (yyvsp[0].atributos).lexema);
        is = BuscarSimbolo((yyvsp[0].atributos).lexema);
        if(!is){
            fprintf(stderr, "****Error semantico en lin %d: Acceso a variable no declarada (%s).\n", n_linea, (yyvsp[0].atributos).lexema);
            return -1; 
        }
        if(!usoGlobal((yyvsp[0].atributos).lexema)){
            if(is->categoria == PARAMETRO){
                escribir_operando_funcion(yyout, (num_parametros - is->adicional1)+1);
            }
            else{
                escribir_operando_funcion(yyout, -(is->adicional1+1));
            }
        }else{

            escribir_operando(yyout, (yyvsp[0].atributos).lexema, 1);
        }
        
        (yyval.atributos).es_direccion = 1;
        (yyval.atributos).tipo = is->tipo;
        
        fprintf(yyout, ";R80:\t<exp> ::= <identificador>\n");
    }
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 488 "alfa.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
        escribir_operando(yyout, (yyvsp[0].atributos).lexema, 0);
        fprintf(yyout, ";R81:\t<exp> ::= <constante>\n");
    }
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 494 "alfa.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
        (yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion;
        fprintf(yyout, ";R82:\t<exp> ::= ( <exp> )\n");
    }
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 499 "alfa.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = BOOLEANO;
        (yyval.atributos).es_direccion = 0;
        fprintf(yyout, ";R83:\t<exp> ::= ( <comparacion> )\n");
    }
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 504 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(yyout, ";R85:\t<exp> ::= <elemento_vector>\n");
    }
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 507 "alfa.y" /* yacc.c:1646  */
    {
        is = BuscarSimbolo((yyvsp[-2].atributos).lexema);
        if(is->adicional1 != parametros){
            fprintf(stderr, "****Error semantico en lin %d: Numero incorrecto de parametros en llamada a funcion.\n", n_linea);
            return -1;
        }
        is_call_function = 0;
        (yyval.atributos).tipo = is->tipo;
        llamarFuncion(yyout, (yyvsp[-2].atributos).lexema, is->adicional1);
        fprintf(yyout, ";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");}
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 519 "alfa.y" /* yacc.c:1646  */
    {
    if(is_call_function){
        fprintf(stderr, "****Error semantico en lin %d: No esta permitido el uso de llamadas a funciones como parametros de otras funciones.\n", n_linea);
        return -1;
    }

    is_call_function = 1;
    parametros = 0;
    strcpy((yyval.atributos).lexema, (yyvsp[-1].atributos).lexema);
}
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 530 "alfa.y" /* yacc.c:1646  */
    {
    is_call_function = 0;
    parametros++;
    fprintf(yyout, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");}
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 534 "alfa.y" /* yacc.c:1646  */
    {
        is_call_function = 0;
        fprintf(yyout, ";R90:\t<lista_expresiones> ::=\n");}
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 539 "alfa.y" /* yacc.c:1646  */
    {
    parametros++;
    fprintf(yyout, ";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");}
#line 2136 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 542 "alfa.y" /* yacc.c:1646  */
    {fprintf(yyout, ";R92:\t<lista_expresiones> ::=\n");}
#line 2142 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 545 "alfa.y" /* yacc.c:1646  */
    {
    if((yyvsp[0].atributos).es_direccion){
        cambiar_a_valor(yyout);
    }
}
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 551 "alfa.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO){
            fprintf(stderr, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", n_linea);
            return -1;
        }
        igual(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, num_cmp);
        fprintf(yyout, ";R93:\t<comparacion> ::= <exp> == <exp>\n");
    }
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 559 "alfa.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO){
            fprintf(stderr, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", n_linea);
            return -1;
        }
        distinto(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, num_cmp);
        fprintf(yyout, ";R94:\t<comparacion> ::= <exp> != <exp>\n");
    }
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 567 "alfa.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO){
            fprintf(stderr, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", n_linea);
            return -1;
        }
        menor_igual(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, num_cmp);
        fprintf(yyout, ";R95:\t<comparacion> ::= <exp> <= <exp>\n");
    }
#line 2191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 575 "alfa.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO){
            fprintf(stderr, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", n_linea);
            return -1;
        }
        mayor_igual(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, num_cmp);
        fprintf(yyout, ";R96:\t<comparacion> ::= <exp> >= <exp>\n");
    }
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 583 "alfa.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO){
            fprintf(stderr, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", n_linea);
            return -1;
        }
        menor(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, num_cmp);
        fprintf(yyout, ";R97:\t<comparacion> ::= <exp> < <exp>\n");
    }
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 591 "alfa.y" /* yacc.c:1646  */
    {
        if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO){
            fprintf(stderr, "****Error semantico en lin %d: Comparacion con operandos boolean.\n", n_linea);
            return -1;
        }
        mayor(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, num_cmp);
        fprintf(yyout, ";R98:\t<comparacion> ::= <exp> > <exp>\n");
    }
#line 2230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 601 "alfa.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
        strcpy((yyval.atributos).lexema, (yyvsp[0].atributos).lexema);
        fprintf(yyout, ";R99:\t<constante> ::= <constante_logica>\n");
    }
#line 2241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 607 "alfa.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
        strcpy((yyval.atributos).lexema, (yyvsp[0].atributos).lexema);
        fprintf(yyout, ";R100:\t<constante> ::= <constante_entera>\n");
    }
#line 2252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 615 "alfa.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = BOOLEANO;
        (yyval.atributos).es_direccion = 0;
        strcpy((yyval.atributos).lexema, "1");
        fprintf(yyout, ";R102:\t<constante_logica> ::= true\n");
    }
#line 2263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 621 "alfa.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = BOOLEANO;
        (yyval.atributos).es_direccion = 0;
        strcpy((yyval.atributos).lexema, "0");
        fprintf(yyout, ";R103:\t<constante_logica> ::= false\n");
    }
#line 2274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 629 "alfa.y" /* yacc.c:1646  */
    {
    (yyval.atributos).tipo = ENTERO;
    (yyval.atributos).es_direccion = 0;
    fprintf(yyout, ";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n");}
#line 2283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 636 "alfa.y" /* yacc.c:1646  */
    {
    is = BuscarSimbolo((yyvsp[0].atributos).lexema);
    if((is && !is_function) || (is && EsLocal((yyvsp[0].atributos).lexema))){
        fprintf(stderr, "****Error semantico en la linea %d: Declaracion duplicada.", n_linea);
        return -1;
    }
    is_aux.lexema = (yyvsp[0].atributos).lexema;
    is_aux.categoria = VARIABLE;
    is_aux.clase = clase;
    is_aux.tipo = tipo;
    if(clase == VECTOR) is_aux.adicional1 = tam_vector;
    else is_aux.adicional1 = 1;

    if(is_function){
        if(clase == VECTOR){
            fprintf(stderr, "****Error semantico en lin %d: Variable local de tipo no escalar.\n", n_linea);
            return -1;
        }
        is_aux.adicional1 = num_local_variables;
        num_local_variables++;
        idx_variable_local++;
    }
    else declarar_variable(yyout, (yyvsp[0].atributos).lexema, tipo, is_aux.adicional1);

    declarar((yyvsp[0].atributos).lexema, &is_aux);

    fprintf(yyout, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");}
#line 2315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 665 "alfa.y" /* yacc.c:1646  */
    {escribir_segmento_codigo(yyout);}
#line 2321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 667 "alfa.y" /* yacc.c:1646  */
    {escribir_inicio_main(yyout);}
#line 2327 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2331 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 669 "alfa.y" /* yacc.c:1906  */



void yyerror(const char* s) {
    if(!error){
        fprintf(stderr, "****Error sintactico en [lin %d, col %d]\n", n_linea, n_columna);
    }
    error = 0;
}
