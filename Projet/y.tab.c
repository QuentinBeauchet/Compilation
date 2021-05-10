/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "miniC.y"

#include "types.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex();
void yyerror (const char *s);

programme_t global_programme;


#line 83 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    INT = 258,
    VOID = 259,
    IDENTIFICATEUR = 260,
    CONSTANTE = 261,
    PLUS = 262,
    MOINS = 263,
    MUL = 264,
    DIV = 265,
    LSHIFT = 266,
    RSHIFT = 267,
    BAND = 268,
    BOR = 269,
    LT = 270,
    GT = 271,
    GEQ = 272,
    LEQ = 273,
    EQ = 274,
    NEQ = 275,
    NOT = 276,
    LAND = 277,
    LOR = 278,
    EXTERN = 279,
    RETURN = 280,
    BREAK = 281,
    ELSE = 282,
    FOR = 283,
    WHILE = 284,
    IF = 285,
    SWITCH = 286,
    CASE = 287,
    DEFAULT = 288,
    THEN = 289,
    moins = 290,
    REL = 291
  };
#endif
/* Tokens.  */
#define INT 258
#define VOID 259
#define IDENTIFICATEUR 260
#define CONSTANTE 261
#define PLUS 262
#define MOINS 263
#define MUL 264
#define DIV 265
#define LSHIFT 266
#define RSHIFT 267
#define BAND 268
#define BOR 269
#define LT 270
#define GT 271
#define GEQ 272
#define LEQ 273
#define EQ 274
#define NEQ 275
#define NOT 276
#define LAND 277
#define LOR 278
#define EXTERN 279
#define RETURN 280
#define BREAK 281
#define ELSE 282
#define FOR 283
#define WHILE 284
#define IF 285
#define SWITCH 286
#define CASE 287
#define DEFAULT 288
#define THEN 289
#define moins 290
#define REL 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 58 "miniC.y"

	char* type;
	char* identificateur;
	int constante;
	bool boolean;
	char* binary_op;
	char* binary_rel;
	char* binary_comp;
	char* selection_nom;
	
	parm_t parm;
	liste_parms_t liste_parms;
	declarateur_t declarateur;
	liste_declarateurs_t liste_declarateurs;
	declaration_t declaration;
	liste_declarations_t liste_declarations;
	variable_t variable;
	liste_expressions_t liste_expressions;
	expression_t expression;
	condition_t condition;
	appel_t appel;
	affectation_t affectation;
	saut_t saut;
	bloc_t bloc;
	selection_t selection;
	instruction_t instruction;
	liste_instructions_t liste_instructions;
	iteration_t iteration;
	fonction_t fonction;
	liste_fonctions_t liste_fonctions;
	programme_t programme;

#line 240 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
typedef yytype_uint8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   257

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  162

#define YYUNDEFTOK  2
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,    42,     2,     2,    38,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    37,
       2,    46,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    93,    93,    97,    99,   102,   104,   109,   112,   114,
     119,   120,   125,   127,   131,   132,   135,   137,   140,   143,
     146,   148,   151,   153,   156,   157,   160,   161,   162,   163,
     164,   165,   168,   173,   176,   180,   185,   191,   192,   195,
     196,   197,   200,   203,   206,   209,   212,   214,   220,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   236,   237,
     238,   241,   243,   246,   249,   252,   256,   259,   267,   268,
     271,   272,   273,   274,   275,   276
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "VOID", "IDENTIFICATEUR",
  "CONSTANTE", "PLUS", "MOINS", "MUL", "DIV", "LSHIFT", "RSHIFT", "BAND",
  "BOR", "LT", "GT", "GEQ", "LEQ", "EQ", "NEQ", "NOT", "LAND", "LOR",
  "EXTERN", "RETURN", "BREAK", "ELSE", "FOR", "WHILE", "IF", "SWITCH",
  "CASE", "DEFAULT", "THEN", "moins", "REL", "';'", "','", "'['", "']'",
  "'('", "')'", "'{'", "'}'", "':'", "'='", "$accept", "programme",
  "liste_declarations", "liste_fonctions", "declaration",
  "liste_declarateurs", "declarateur", "fonction", "type", "liste_parms",
  "parm", "liste_instructions", "liste_instructions_in_case",
  "instruction", "instruction_in_switch", "iteration",
  "selection_out_switch", "selection_in_switch", "saut", "affectation",
  "bloc", "bloc_in_switch", "appel", "variable", "expression",
  "liste_expressions", "condition", "binary_rel", "binary_comp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    59,    44,    91,
      93,    40,    41,   123,   125,    58,    61
};
# endif

#define YYPACT_NINF (-71)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -71,    12,    32,   -71,   -71,   -71,   195,    32,   -71,   -71,
      22,    24,   -71,    29,    -4,   -31,    25,    20,    -4,    97,
     -71,    87,   109,    97,   112,   -10,   -71,   -71,    25,    83,
      38,   -71,    97,    92,   -71,   113,   -71,   -71,   -71,   195,
      87,    77,   142,     3,   149,   164,   165,   173,   176,   194,
     163,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   178,
     -71,   -71,   -36,    17,   177,   -71,    17,   -71,    17,   180,
       6,   -71,   239,    54,    54,    17,   175,   -71,   195,   -71,
      17,    17,   229,    39,    17,   -71,   159,    17,    17,    17,
      17,    17,    17,    17,    17,   -71,   -71,   208,   205,    54,
     215,    49,    51,   167,   -71,   195,   -71,    99,   181,   229,
      17,   210,    80,   -71,   135,   135,   199,   199,   189,   189,
     -71,   -71,    54,    54,   145,    56,   -71,   -71,   -71,   -71,
     -71,   -71,    17,   -71,   -71,   108,    54,   108,   108,   -71,
      58,   -71,   -71,   229,   -71,   -71,    89,   174,   -71,   229,
     -71,   -71,   221,   -71,   -71,   239,   -71,   108,   207,   -71,
     108,   -71
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     1,    15,    14,     0,     2,     3,     6,
       0,     0,     5,     0,    10,     0,     9,     0,     0,    18,
       7,     0,     0,    18,     0,     0,    17,    10,     8,     0,
       0,    19,     0,     0,    11,     0,    16,     4,    13,    21,
       0,     0,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     4,    12,    20,    25,    26,    31,    24,    27,     0,
      29,    30,     0,    63,    46,    58,     0,    40,     0,    59,
       0,    39,     0,     0,     0,     0,     0,     4,    21,    28,
       0,     0,    62,     0,    63,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    41,    46,     0,     0,     0,
       0,     0,     0,     0,     4,    23,    38,     0,     0,    42,
       0,     0,     0,    48,    49,    50,    52,    51,    54,    53,
      55,    56,     0,     0,     0,     0,    71,    70,    72,    73,
      74,    75,     0,    68,    69,     0,     0,     0,     0,    37,
      44,    43,    47,    61,    45,    60,     0,     0,    66,    67,
      33,    65,    34,    36,    22,     0,    64,     0,     0,    35,
       0,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -71,   -71,     4,   -71,   -71,   -71,   230,   243,    63,   231,
     220,   179,   -71,    47,   115,   -71,   -71,   -71,   -71,   -70,
     -71,   152,   -71,   -41,   -42,   169,   -69,   -71,   -71
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   105,     7,     8,    15,    16,     9,    40,    25,
      26,    41,   140,    53,    54,    55,    56,    57,    58,    59,
      60,   106,    61,    69,   100,    83,   101,   136,   132
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      62,    70,    97,    80,     2,   102,    20,    21,    64,    65,
      81,    66,     3,    87,    88,    89,    90,    91,    92,    93,
      94,    82,    64,    65,    85,    66,    86,    14,    32,    17,
     125,    62,    33,   103,    18,     4,     5,    19,   108,   109,
      67,    39,    82,    95,    68,   114,   115,   116,   117,   118,
     119,   120,   121,   146,   147,    78,     6,   124,    68,    64,
      65,    23,    66,    42,    22,    10,    62,   151,   143,    11,
      13,   133,   134,   133,   134,    98,    32,   110,   133,   134,
      35,   111,    42,    43,    44,   158,    45,    46,    47,    48,
     149,   135,    27,   137,    62,    99,    62,    62,   148,    62,
      24,    51,    43,    44,    42,    45,    46,    47,    48,    49,
      50,   133,   134,    42,    62,    29,    62,    31,   110,    62,
      51,    52,   145,    34,    43,    44,   155,    45,    46,    47,
      48,    49,    50,    43,    44,    37,    45,    46,    47,    48,
      49,    50,    51,   141,    89,    90,    91,    92,    93,    94,
      38,    51,    87,    88,    89,    90,    91,    92,    93,    94,
     126,   127,   128,   129,   130,   131,    87,    88,    89,    90,
      91,    92,    93,    94,    87,    88,    89,    90,    91,    92,
      93,    94,   150,    63,   152,   153,    71,   113,    87,    88,
      89,    90,    91,    92,    93,    94,   133,   134,     4,     5,
      76,   113,    93,    94,   159,    72,    73,   161,    77,   138,
      91,    92,    93,    94,    74,    79,   156,    75,    84,    80,
     104,   142,    87,    88,    89,    90,    91,    92,    93,    94,
     126,   127,   128,   129,   130,   131,    87,    88,    89,    90,
      91,    92,    93,    94,    96,   122,   123,   144,   157,   160,
      12,    28,    36,   112,    30,   154,   139,   107
};

static const yytype_uint8 yycheck[] =
{
      41,    43,    72,    39,     0,    74,    37,    38,     5,     6,
      46,     8,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    63,     5,     6,    66,     8,    68,     5,    38,     5,
      99,    72,    42,    75,     5,     3,     4,    41,    80,    81,
      37,    37,    84,    37,    41,    87,    88,    89,    90,    91,
      92,    93,    94,   122,   123,    51,    24,    99,    41,     5,
       6,    41,     8,     5,    39,     2,   107,   136,   110,     6,
       7,    22,    23,    22,    23,    21,    38,    38,    22,    23,
      42,    42,     5,    25,    26,   155,    28,    29,    30,    31,
     132,    42,     5,    42,   135,    41,   137,   138,    42,   140,
       3,    43,    25,    26,     5,    28,    29,    30,    31,    32,
      33,    22,    23,     5,   155,     6,   157,     5,    38,   160,
      43,    44,    42,    40,    25,    26,    37,    28,    29,    30,
      31,    32,    33,    25,    26,    43,    28,    29,    30,    31,
      32,    33,    43,    44,     9,    10,    11,    12,    13,    14,
      37,    43,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     7,     8,     9,    10,
      11,    12,    13,    14,     7,     8,     9,    10,    11,    12,
      13,    14,   135,    41,   137,   138,    37,    42,     7,     8,
       9,    10,    11,    12,    13,    14,    22,    23,     3,     4,
       6,    42,    13,    14,   157,    41,    41,   160,    45,    42,
      11,    12,    13,    14,    41,    37,    42,    41,    41,    39,
      45,    40,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     7,     8,     9,    10,
      11,    12,    13,    14,     5,    37,    41,    37,    27,    42,
       7,    21,    32,    84,    23,   140,   104,    78
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    48,    49,     0,     3,     4,    24,    50,    51,    54,
      55,    55,    54,    55,     5,    52,    53,     5,     5,    41,
      37,    38,    39,    41,     3,    56,    57,     5,    53,     6,
      56,     5,    38,    42,    40,    42,    57,    43,    37,    49,
      55,    58,     5,    25,    26,    28,    29,    30,    31,    32,
      33,    43,    44,    60,    61,    62,    63,    64,    65,    66,
      67,    69,    70,    41,     5,     6,     8,    37,    41,    70,
      71,    37,    41,    41,    41,    41,     6,    45,    49,    37,
      39,    46,    71,    72,    41,    71,    71,     7,     8,     9,
      10,    11,    12,    13,    14,    37,     5,    66,    21,    41,
      71,    73,    73,    71,    45,    49,    68,    58,    71,    71,
      38,    42,    72,    42,    71,    71,    71,    71,    71,    71,
      71,    71,    37,    41,    71,    73,    15,    16,    17,    18,
      19,    20,    75,    22,    23,    42,    74,    42,    42,    68,
      59,    44,    40,    71,    37,    42,    73,    73,    42,    71,
      60,    73,    60,    60,    61,    37,    42,    27,    66,    60,
      42,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    51,    52,    52,
      53,    53,    54,    54,    55,    55,    56,    56,    56,    57,
      58,    58,    59,    59,    60,    60,    61,    61,    61,    61,
      61,    61,    62,    62,    63,    63,    63,    64,    64,    65,
      65,    65,    66,    67,    68,    69,    70,    70,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    72,    72,    73,    73,    73,    73,    74,    74,
      75,    75,    75,    75,    75,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     2,     1,     3,     3,     1,
       1,     4,     9,     7,     1,     1,     3,     1,     0,     2,
       2,     0,     2,     0,     1,     1,     1,     1,     2,     1,
       1,     1,     9,     5,     5,     7,     5,     4,     3,     2,
       2,     3,     3,     4,     2,     5,     1,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     1,     1,
       4,     3,     1,     0,     4,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 2:
#line 93 "miniC.y"
                                                                {(yyval.programme) = (programme_t){.liste_declarations = copyOf_liste_declarations(&(yyvsp[-1].liste_declarations)), .liste_fonctions = (yyvsp[0].liste_fonctions)};
								global_programme=(yyval.programme);}
#line 1545 "y.tab.c"
    break;

  case 3:
#line 97 "miniC.y"
                                                        {append_liste_declarations(&(yyvsp[-1].liste_declarations),(yyvsp[0].declaration));
								(yyval.liste_declarations)=(yyvsp[-1].liste_declarations);}
#line 1552 "y.tab.c"
    break;

  case 4:
#line 99 "miniC.y"
                                                                {(yyval.liste_declarations) = (liste_declarations_t){ .size = 0};}
#line 1558 "y.tab.c"
    break;

  case 5:
#line 102 "miniC.y"
                                                                {append_liste_fonctions(&(yyvsp[-1].liste_fonctions),(yyvsp[0].fonction));
								(yyval.liste_fonctions)=(yyvsp[-1].liste_fonctions);}
#line 1565 "y.tab.c"
    break;

  case 6:
#line 104 "miniC.y"
                                                                {liste_fonctions_t tab = {.size = 0};
								append_liste_fonctions(&tab,(yyvsp[0].fonction));
								(yyval.liste_fonctions)=tab;}
#line 1573 "y.tab.c"
    break;

  case 7:
#line 109 "miniC.y"
                                                                {(yyval.declaration) = (declaration_t){ .type = (yyvsp[-2].type), .liste_declarateurs = (yyvsp[-1].liste_declarateurs)};}
#line 1579 "y.tab.c"
    break;

  case 8:
#line 112 "miniC.y"
                                                                {append_liste_declarateurs(&(yyvsp[-2].liste_declarateurs),(yyvsp[0].declarateur));
								(yyval.liste_declarateurs) = (yyvsp[-2].liste_declarateurs);}
#line 1586 "y.tab.c"
    break;

  case 9:
#line 114 "miniC.y"
                                                                {liste_declarateurs_t tab = {.size = 0};
								append_liste_declarateurs(&tab,(yyvsp[0].declarateur));
								(yyval.liste_declarateurs) = tab;}
#line 1594 "y.tab.c"
    break;

  case 10:
#line 119 "miniC.y"
                                                        {(yyval.declarateur) = (declarateur_t){ .identificateur = (yyvsp[0].identificateur), .liste_constantes = (liste_constantes_t){.size = 0}};}
#line 1600 "y.tab.c"
    break;

  case 11:
#line 120 "miniC.y"
                                                        {append_liste_constantes(&(yyvsp[-3].declarateur).liste_constantes,(yyvsp[-1].constante));
								(yyval.declarateur) = (yyvsp[-3].declarateur);}
#line 1607 "y.tab.c"
    break;

  case 12:
#line 125 "miniC.y"
                                                                                                        {(yyval.fonction) = (fonction_t){ .liste_parms = (yyvsp[-5].liste_parms),
														.liste_declarations = copyOf_liste_declarations(&(yyvsp[-2].liste_declarations)), .identificateur = (yyvsp[-7].identificateur), .type = 														(yyvsp[-8].type), .liste_instructions = copyOf_liste_instructions(&(yyvsp[-1].liste_instructions))};}
#line 1614 "y.tab.c"
    break;

  case 13:
#line 127 "miniC.y"
                                                                                                                {(yyval.fonction) = (fonction_t){ .Extern = (yyvsp[-6].boolean), .liste_parms = (yyvsp[-2].liste_parms),
														.identificateur = (yyvsp[-4].identificateur), .type = (yyvsp[-5].type)};}
#line 1621 "y.tab.c"
    break;

  case 14:
#line 131 "miniC.y"
                                                                        {(yyval.type) = (yyvsp[0].type);}
#line 1627 "y.tab.c"
    break;

  case 15:
#line 132 "miniC.y"
                                                                        {(yyval.type) = (yyvsp[0].type);}
#line 1633 "y.tab.c"
    break;

  case 16:
#line 135 "miniC.y"
                                                                        {append_liste_parms(&(yyvsp[-2].liste_parms),(yyvsp[0].parm));
									(yyval.liste_parms) = (yyvsp[-2].liste_parms);}
#line 1640 "y.tab.c"
    break;

  case 17:
#line 137 "miniC.y"
                                                                        {liste_parms_t tab = {.size = 0};
									append_liste_parms(&tab,(yyvsp[0].parm));
									(yyval.liste_parms) = tab;}
#line 1648 "y.tab.c"
    break;

  case 18:
#line 140 "miniC.y"
                                                                        {(yyval.liste_parms) = (liste_parms_t){.size = 0};}
#line 1654 "y.tab.c"
    break;

  case 19:
#line 143 "miniC.y"
                                                                        {(yyval.parm) = (parm_t){ .type = (yyvsp[-1].type), .identificateur = (yyvsp[0].identificateur)};}
#line 1660 "y.tab.c"
    break;

  case 20:
#line 146 "miniC.y"
                                                                {append_liste_instructions(&(yyvsp[-1].liste_instructions),(yyvsp[0].instruction));
									(yyval.liste_instructions) = (yyvsp[-1].liste_instructions);}
#line 1667 "y.tab.c"
    break;

  case 21:
#line 148 "miniC.y"
                                                                        {(yyval.liste_instructions) = (liste_instructions_t){.size = 0};}
#line 1673 "y.tab.c"
    break;

  case 22:
#line 151 "miniC.y"
                                                                        {append_liste_instructions(&(yyvsp[-1].liste_instructions),(yyvsp[0].instruction));
									(yyval.liste_instructions) = (yyvsp[-1].liste_instructions);}
#line 1680 "y.tab.c"
    break;

  case 23:
#line 153 "miniC.y"
                                                                        {(yyval.liste_instructions) = (liste_instructions_t){.size = 0};}
#line 1686 "y.tab.c"
    break;

  case 24:
#line 156 "miniC.y"
                                                                        {(yyval.instruction) = (instruction_t){.selection = copyOf_selection(&(yyvsp[0].selection))};}
#line 1692 "y.tab.c"
    break;

  case 25:
#line 157 "miniC.y"
                                                                        {(yyval.instruction) = (yyvsp[0].instruction);}
#line 1698 "y.tab.c"
    break;

  case 26:
#line 160 "miniC.y"
                                                                        {(yyval.instruction) = (instruction_t){.iteration = copyOf_iteration(&(yyvsp[0].iteration))};}
#line 1704 "y.tab.c"
    break;

  case 27:
#line 161 "miniC.y"
                                                                        {(yyval.instruction) = (instruction_t){.saut = copyOf_saut(&(yyvsp[0].saut))};}
#line 1710 "y.tab.c"
    break;

  case 28:
#line 162 "miniC.y"
                                                                        {(yyval.instruction) = (instruction_t){.affectation = copyOf_affectation(&(yyvsp[-1].affectation))};}
#line 1716 "y.tab.c"
    break;

  case 29:
#line 163 "miniC.y"
                                                                        {(yyval.instruction) = (instruction_t){.bloc = copyOf_bloc(&(yyvsp[0].bloc))};}
#line 1722 "y.tab.c"
    break;

  case 30:
#line 164 "miniC.y"
                                                                        {(yyval.instruction) = (instruction_t){.appel = copyOf_appel(&(yyvsp[0].appel))};}
#line 1728 "y.tab.c"
    break;

  case 31:
#line 165 "miniC.y"
                                                                        {(yyval.instruction) = (instruction_t){.selection = copyOf_selection(&(yyvsp[0].selection))};}
#line 1734 "y.tab.c"
    break;

  case 32:
#line 168 "miniC.y"
                                                                                        {liste_affectations_t tab = {.size = 0};
											append_liste_affectations(&tab,(yyvsp[-6].affectation));
											append_liste_affectations(&tab,(yyvsp[-2].affectation));
											(yyval.iteration) = (iteration_t){.For = (yyvsp[-8].boolean), .condition = copyOf_condition(&(yyvsp[-4].condition)), .instruction =
											copyOf_instruction(&(yyvsp[0].instruction)), .liste_affectations = copyOf_liste_affectations(&tab)};}
#line 1744 "y.tab.c"
    break;

  case 33:
#line 173 "miniC.y"
                                                                                        {(yyval.iteration) = (iteration_t){.For = (yyvsp[-4].boolean), .condition = copyOf_condition(&(yyvsp[-2].condition)), .instruction = copyOf_instruction(&(yyvsp[0].instruction))};}
#line 1750 "y.tab.c"
    break;

  case 34:
#line 176 "miniC.y"
                                                                        {liste_instructions_t tab = {.size = 0};
									append_liste_instructions(&tab,(yyvsp[0].instruction));
									(yyval.selection) = (selection_t){.type_selection = 0, .selection_nom = (yyvsp[-4].selection_nom), .condition = (yyvsp[-2].condition), .liste_instructions =
									copyOf_liste_instructions(&tab)};}
#line 1759 "y.tab.c"
    break;

  case 35:
#line 180 "miniC.y"
                                                                        {liste_instructions_t tab = {.size = 0};
									append_liste_instructions(&tab,(yyvsp[-2].instruction));
									append_liste_instructions(&tab,(yyvsp[0].instruction));
									(yyval.selection) = (selection_t){.type_selection = 1, .selection_nom = (yyvsp[-6].selection_nom), .condition = (yyvsp[-4].condition), .Else = (yyvsp[-1].boolean), .liste_instructions =
									copyOf_liste_instructions(&tab)};}
#line 1769 "y.tab.c"
    break;

  case 36:
#line 185 "miniC.y"
                                                                {liste_instructions_t tab = {.size = 0};
									append_liste_instructions(&tab,(yyvsp[0].instruction));
									(yyval.selection) = (selection_t){.type_selection = 2, .selection_nom = (yyvsp[-4].selection_nom), .expression = (yyvsp[-2].expression), .liste_instructions =
									copyOf_liste_instructions(&tab)};}
#line 1778 "y.tab.c"
    break;

  case 37:
#line 191 "miniC.y"
                                                                        {(yyval.selection) = make_selection(3,(yyvsp[-3].selection_nom),(yyvsp[0].bloc),(yyvsp[-2].constante));}
#line 1784 "y.tab.c"
    break;

  case 38:
#line 192 "miniC.y"
                                                                        {(yyval.selection) = make_selection(4,(yyvsp[-2].selection_nom),(yyvsp[0].bloc),0);}
#line 1790 "y.tab.c"
    break;

  case 39:
#line 195 "miniC.y"
                                                                        {(yyval.saut) = (saut_t){.Return = (yyvsp[-1].boolean)};}
#line 1796 "y.tab.c"
    break;

  case 40:
#line 196 "miniC.y"
                                                                        {(yyval.saut) = (saut_t){.Return = (yyvsp[-1].boolean)};}
#line 1802 "y.tab.c"
    break;

  case 41:
#line 197 "miniC.y"
                                                                        {(yyval.saut) = (saut_t){.Return = (yyvsp[-2].boolean), .expression = copyOf_expression(&(yyvsp[-1].expression))};}
#line 1808 "y.tab.c"
    break;

  case 42:
#line 200 "miniC.y"
                                                                        {(yyval.affectation) = (affectation_t){.variable = (yyvsp[-2].variable), .expression = (yyvsp[0].expression)};}
#line 1814 "y.tab.c"
    break;

  case 43:
#line 203 "miniC.y"
                                                                {(yyval.bloc) = (bloc_t){.liste_declarations = (yyvsp[-2].liste_declarations) , .liste_instructions = (yyvsp[-1].liste_instructions)};}
#line 1820 "y.tab.c"
    break;

  case 44:
#line 206 "miniC.y"
                                                                        {(yyval.bloc) = (bloc_t){.liste_declarations = (yyvsp[-1].liste_declarations) , .liste_instructions = (yyvsp[0].liste_instructions)};}
#line 1826 "y.tab.c"
    break;

  case 45:
#line 209 "miniC.y"
                                                                        {(yyval.appel) = (appel_t){.identificateur = (yyvsp[-4].identificateur) , .liste_expressions = *copyOf_liste_expressions(&(yyvsp[-2].liste_expressions))};}
#line 1832 "y.tab.c"
    break;

  case 46:
#line 212 "miniC.y"
                                                                {(yyval.variable) = (variable_t){.identificateur = (yyvsp[0].identificateur), .liste_expressions =
									copyOf_liste_expressions(&(liste_expressions_t){.size = 0})};}
#line 1839 "y.tab.c"
    break;

  case 47:
#line 214 "miniC.y"
                                                                        {append_liste_expressions((yyvsp[-3].variable).liste_expressions,(yyvsp[-1].expression));
									(yyval.variable) = (yyvsp[-3].variable);}
#line 1846 "y.tab.c"
    break;

  case 48:
#line 220 "miniC.y"
                                                                        {liste_expressions_t tab = {.size = 0};
									append_liste_expressions(&tab,(yyvsp[-1].expression));
									(yyvsp[-1].expression).liste_expressions = copyOf_liste_expressions(&tab);
									(yyvsp[-1].expression).type_expression = 0;
									(yyval.expression) = (yyvsp[-1].expression);}
#line 1856 "y.tab.c"
    break;

  case 49:
#line 225 "miniC.y"
                                                                        {(yyval.expression) = make_expr((yyvsp[-2].expression),(yyvsp[-1].binary_op),(yyvsp[0].expression));}
#line 1862 "y.tab.c"
    break;

  case 50:
#line 226 "miniC.y"
                                                                        {(yyval.expression) = make_expr((yyvsp[-2].expression),(yyvsp[-1].binary_op),(yyvsp[0].expression));}
#line 1868 "y.tab.c"
    break;

  case 51:
#line 227 "miniC.y"
                                                                        {(yyval.expression) = make_expr((yyvsp[-2].expression),(yyvsp[-1].binary_op),(yyvsp[0].expression));}
#line 1874 "y.tab.c"
    break;

  case 52:
#line 228 "miniC.y"
                                                                        {(yyval.expression) = make_expr((yyvsp[-2].expression),(yyvsp[-1].binary_op),(yyvsp[0].expression));}
#line 1880 "y.tab.c"
    break;

  case 53:
#line 229 "miniC.y"
                                                                        {(yyval.expression) = make_expr((yyvsp[-2].expression),(yyvsp[-1].binary_op),(yyvsp[0].expression));}
#line 1886 "y.tab.c"
    break;

  case 54:
#line 230 "miniC.y"
                                                                        {(yyval.expression) = make_expr((yyvsp[-2].expression),(yyvsp[-1].binary_op),(yyvsp[0].expression));}
#line 1892 "y.tab.c"
    break;

  case 55:
#line 231 "miniC.y"
                                                                        {(yyval.expression) = make_expr((yyvsp[-2].expression),(yyvsp[-1].binary_op),(yyvsp[0].expression));}
#line 1898 "y.tab.c"
    break;

  case 56:
#line 232 "miniC.y"
                                                                        {(yyval.expression) = make_expr((yyvsp[-2].expression),(yyvsp[-1].binary_op),(yyvsp[0].expression));}
#line 1904 "y.tab.c"
    break;

  case 57:
#line 233 "miniC.y"
                                                                        {liste_expressions_t tab = {.size = 0};
									append_liste_expressions(&tab,(yyvsp[0].expression));
									(yyval.expression) = (expression_t){.binary_op = (yyvsp[-1].binary_op), .liste_expressions = copyOf_liste_expressions(&tab), .type_expression = 2};}
#line 1912 "y.tab.c"
    break;

  case 58:
#line 236 "miniC.y"
                                                                        {(yyval.expression) = (expression_t){.constante = copyOf_constante(&(yyvsp[0].constante)), .type_expression = 3};}
#line 1918 "y.tab.c"
    break;

  case 59:
#line 237 "miniC.y"
                                                                        {(yyval.expression) = (expression_t){.variable = copyOf_variable(&(yyvsp[0].variable)), .type_expression = 4};}
#line 1924 "y.tab.c"
    break;

  case 60:
#line 238 "miniC.y"
                                                                        {(yyval.expression) = (expression_t){.identificateur = (yyvsp[-3].identificateur) , .liste_expressions = copyOf_liste_expressions(&(yyvsp[-1].liste_expressions)), .type_expression = 5};}
#line 1930 "y.tab.c"
    break;

  case 61:
#line 241 "miniC.y"
                                                                        {append_liste_expressions(&(yyvsp[-2].liste_expressions),(yyvsp[0].expression));
									(yyval.liste_expressions) = (yyvsp[-2].liste_expressions);}
#line 1937 "y.tab.c"
    break;

  case 62:
#line 243 "miniC.y"
                                                                        {liste_expressions_t tab= {.size = 0};
									append_liste_expressions(&tab,(yyvsp[0].expression));
									(yyval.liste_expressions) = tab;}
#line 1945 "y.tab.c"
    break;

  case 63:
#line 246 "miniC.y"
                                                                        {(yyval.liste_expressions) = (liste_expressions_t){.size = 0};}
#line 1951 "y.tab.c"
    break;

  case 64:
#line 249 "miniC.y"
                                                                        {liste_conditions_t tab = {.size = 0};
									append_liste_conditions(&tab,(yyvsp[-1].condition));
									(yyval.condition) = (condition_t){.type_condition = 0, .binary_rel = (yyvsp[-3].binary_rel), .liste_conditions = &tab};}
#line 1959 "y.tab.c"
    break;

  case 65:
#line 252 "miniC.y"
                                                                        {liste_conditions_t tab = {.size = 0};
									append_liste_conditions(&tab,(yyvsp[-2].condition));
									append_liste_conditions(&tab,(yyvsp[0].condition));
									(yyval.condition) = (condition_t){.type_condition = 1, .binary_rel = (yyvsp[-1].binary_rel), .liste_conditions = &tab};}
#line 1968 "y.tab.c"
    break;

  case 66:
#line 256 "miniC.y"
                                                                        {liste_conditions_t tab = {.size = 0};
									append_liste_conditions(&tab,(yyvsp[-1].condition));
									(yyval.condition) = (condition_t){.type_condition = 2, .liste_conditions = &tab};}
#line 1976 "y.tab.c"
    break;

  case 67:
#line 259 "miniC.y"
                                                                        {liste_expressions_t tab = {.size = 0};
									append_liste_expressions(&tab,(yyvsp[-2].expression));
									append_liste_expressions(&tab,(yyvsp[0].expression));
									(yyval.condition) = (condition_t){.type_condition = 3, .binary_comp = (yyvsp[-1].binary_comp), .liste_expressions =
									copyOf_liste_expressions(&tab)};}
#line 1986 "y.tab.c"
    break;

  case 68:
#line 267 "miniC.y"
                                                                        {(yyval.binary_rel) = (yyvsp[0].binary_rel);}
#line 1992 "y.tab.c"
    break;

  case 69:
#line 268 "miniC.y"
                                                                        {(yyval.binary_rel) = (yyvsp[0].binary_rel);}
#line 1998 "y.tab.c"
    break;

  case 70:
#line 271 "miniC.y"
                                                                        {(yyval.binary_comp) = (yyvsp[0].binary_op);}
#line 2004 "y.tab.c"
    break;

  case 71:
#line 272 "miniC.y"
                                                                        {(yyval.binary_comp) = (yyvsp[0].binary_op);}
#line 2010 "y.tab.c"
    break;

  case 72:
#line 273 "miniC.y"
                                                                        {(yyval.binary_comp) = (yyvsp[0].binary_comp);}
#line 2016 "y.tab.c"
    break;

  case 73:
#line 274 "miniC.y"
                                                                        {(yyval.binary_comp) = (yyvsp[0].binary_comp);}
#line 2022 "y.tab.c"
    break;

  case 74:
#line 275 "miniC.y"
                                                                        {(yyval.binary_comp) = (yyvsp[0].binary_comp);}
#line 2028 "y.tab.c"
    break;

  case 75:
#line 276 "miniC.y"
                                                                        {(yyval.binary_comp) = (yyvsp[0].binary_comp);}
#line 2034 "y.tab.c"
    break;


#line 2038 "y.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 279 "miniC.y"

 
void yyerror (const char *s){
  	fprintf (stderr, "ERREUR: %s\n", s);
}

int main(int argc, char *argv[]){
	if(global_debug){
		printf("-----------------------------------------------------------------LEX-----------------------------------------------------------------\n");
	}
	yyparse();
	if(global_debug){
		printf("-------------------------------------------------------VERIFICATION DES STRUCTS-------------------------------------------------------\n");
		print_programme(global_programme);
	}
	dot_generation(global_programme,argv[1]);
}

