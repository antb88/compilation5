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
#line 1 "source.ypp" /* yacc.c:339  */
 
	#include "source.hpp"
	extern int yylineno;
	int yylex();
	void yyerror(const char*);

	/* helper functions */
	void assertNotDefinedInScope(string& name);
	void assertTypeAssignment(VarType from, VarType to);
	void assertDefinedGlobaly(string& name);
	void assertVarTypeNot(VarType forbidden, VarType type);
	void assertVarType(VarType desired, VarType type);
	void assertCanBreak();
	void assertThat(bool condition);

	/* IR functuins */
	void emitRopExpression(Attribute& target, Attribute& first, string rop, Attribute& third);
	void emitAopExpression(string target, string lhs, string aop, string rhs) ;
	string toDecimal(string numstr, int base);
	int getBaseOf(VarType varType);
	void print(string num, VarType type);


	static SymbolTable st;
	static int inBreak = 0;
	static int inCond = 0;

#line 94 "source.tab.cpp" /* yacc.c:339  */

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

/* In a future release of Bison, this section will be replaced
   by #include "source.tab.hpp".  */
#ifndef YY_YY_SOURCE_TAB_HPP_INCLUDED
# define YY_YY_SOURCE_TAB_HPP_INCLUDED
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
    LP = 258,
    RP = 259,
    LC = 260,
    RC = 261,
    SC = 262,
    COL = 263,
    INT = 264,
    DECIMAL = 265,
    BINARY = 266,
    HEXIDECIMAL = 267,
    PRINT = 268,
    INPUT = 269,
    TRUE = 270,
    FALSE = 271,
    WHILE = 272,
    BREAK = 273,
    BOOL = 274,
    SWITCH = 275,
    CASE = 276,
    ID = 277,
    STRING = 278,
    NUM = 279,
    IF = 280,
    ELSE = 281,
    ASSIGN = 282,
    OR = 283,
    AND = 284,
    EVEN_LT = 285,
    EVEN_GT = 286,
    EVEN = 287,
    NOT_EVEN = 288,
    LT = 289,
    GT = 290,
    PLUS = 291,
    MINUS = 292,
    MULT = 293,
    DIV = 294,
    NOT = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SOURCE_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 186 "source.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   244

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  52
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  118

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    66,    66,    68,    72,    82,    86,    90,    94,    98,
     102,   106,   110,   111,   112,   114,   121,   142,   161,   168,
     169,   174,   178,   182,   186,   189,   194,   195,   196,   198,
     202,   206,   210,   214,   218,   223,   224,   225,   226,   237,
     252,   258,   265,   271,   277,   285,   295,   306,   318,   330,
     336,   342,   349
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LP", "RP", "LC", "RC", "SC", "COL",
  "INT", "DECIMAL", "BINARY", "HEXIDECIMAL", "PRINT", "INPUT", "TRUE",
  "FALSE", "WHILE", "BREAK", "BOOL", "SWITCH", "CASE", "ID", "STRING",
  "NUM", "IF", "ELSE", "ASSIGN", "OR", "AND", "EVEN_LT", "EVEN_GT", "EVEN",
  "NOT_EVEN", "LT", "GT", "PLUS", "MINUS", "MULT", "DIV", "NOT", "$accept",
  "Prog", "BEGOLS", "ENDOLS", "BEGSCOPE", "ENDSCOPE", "BEGBREAK",
  "ENDBREAK", "M", "IN_COND", "END_IN_COND", "Statements", "Statement",
  "CasesList", "CaseStat", "BaseType", "Type", "Exp", YY_NULLPTR
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
     295
};
# endif

#define YYPACT_NINF -89

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-89)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -89,     4,   184,   -89,   -89,   -89,   -89,   -89,     2,   -15,
      13,    32,   -89,    37,    18,    45,   184,   -89,   -89,    31,
     184,    34,   -89,   -89,   -89,    48,    81,    34,   100,    65,
     -89,   -89,    34,    34,   -89,   -89,   -89,    -4,   168,    67,
     -89,   -89,   -89,   -89,   -89,   -89,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,   -89,    34,    80,   113,
      34,   -89,    34,   -89,   -89,    34,    34,   201,   121,    42,
      87,    50,   -27,   -18,   -18,   -89,   -89,   182,    47,   -89,
     182,   133,   -89,    30,   192,    53,    52,   123,   -89,   -89,
     151,   170,    52,   -89,   -89,    81,   -89,   -89,   184,   184,
     169,   -89,   -89,   -89,   157,   -89,   184,   -89,   -89,   -89,
     184,   -89,   -89,   166,   -89,   -89,   185,   -89
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     1,     5,    29,    30,    31,     0,     0,
       0,     0,    33,     0,     0,     0,     6,    13,    32,     0,
       0,     0,    42,    43,    39,     0,    40,     0,     0,     0,
      10,    24,     0,     0,    10,     2,    12,     0,     0,     0,
      19,    41,    44,    18,     9,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,     0,     0,     0,
       0,    15,     0,     6,    34,     0,     0,    47,    48,    49,
      50,    51,    52,    35,    36,    37,    38,    11,     0,    17,
      11,     0,    14,    45,    46,     0,     0,     0,    16,     7,
       0,     0,    27,     3,     3,     0,    25,    26,     0,     0,
       0,     4,     4,     3,    21,     8,     0,     3,    23,     4,
       0,     7,     4,     0,    22,     8,     0,    28
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -89,   -89,   -88,   -58,   187,   136,    89,    90,   162,   174,
     161,   222,   -16,   152,   -89,   -25,   -89,   -19
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    98,   104,     2,    35,    94,   108,    65,    57,
      85,    16,    17,    91,    92,    18,    19,    28
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      36,    41,    39,    61,     3,    21,    99,    29,    42,    52,
      53,    54,    55,    58,    59,   106,    30,    22,    23,   110,
      54,    55,    36,    62,    24,    25,    26,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    21,    77,    31,
      32,    80,    27,    81,   105,    33,    83,    84,    34,    22,
      23,   111,    86,    37,   114,    40,    24,    89,    26,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
     100,    64,    56,    90,    27,    49,    50,    51,    52,    53,
      54,    55,   101,   102,    78,    51,    52,    53,    54,    55,
     109,     5,     6,     7,   112,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      79,    50,    51,    52,    53,    54,    55,    93,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      88,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    48,    49,    50,    51,    52,    53,    54,
      55,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,     4,    63,    95,    96,   103,     5,     6,
       7,     8,     9,   107,   115,    10,    11,    12,    13,     4,
      14,    20,   117,    15,     5,     6,     7,     8,     9,    82,
     113,    10,    11,    12,    13,   116,    14,    66,    60,    15,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    87,    38,     0,    97
};

static const yytype_int8 yycheck[] =
{
      16,    26,    21,     7,     0,     3,    94,    22,    27,    36,
      37,    38,    39,    32,    33,   103,     3,    15,    16,   107,
      38,    39,    38,    27,    22,    23,    24,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,     3,    57,     7,
       3,    60,    40,    62,   102,    27,    65,    66,     3,    15,
      16,   109,     5,    22,   112,     7,    22,     4,    24,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      95,     4,     7,    21,    40,    33,    34,    35,    36,    37,
      38,    39,    98,    99,     4,    35,    36,    37,    38,    39,
     106,    10,    11,    12,   110,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,     7,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
       7,    34,    35,    36,    37,    38,    39,     4,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
       7,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    32,    33,    34,    35,    36,    37,    38,
      39,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,     5,     6,    24,     6,     8,    10,    11,
      12,    13,    14,    26,    18,    17,    18,    19,    20,     5,
      22,     4,     7,    25,    10,    11,    12,    13,    14,    63,
     111,    17,    18,    19,    20,   115,    22,    45,    34,    25,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    80,    20,    -1,    92
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    45,     0,     5,    10,    11,    12,    13,    14,
      17,    18,    19,    20,    22,    25,    52,    53,    56,    57,
      45,     3,    15,    16,    22,    23,    24,    40,    58,    22,
       3,     7,     3,    27,     3,    46,    53,    22,    52,    58,
       7,    56,    58,     7,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,     7,    50,    58,    58,
      50,     7,    27,     6,     4,    49,    49,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,     4,     7,
      58,    58,    46,    58,    58,    51,     5,    51,     7,     4,
      21,    54,    55,     4,    47,    24,     6,    54,    43,    43,
      56,    53,    53,     8,    44,    44,    43,    26,    48,    53,
      43,    44,    53,    47,    44,    18,    48,     7
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    52,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    54,    54,    55,    56,
      56,    56,    57,    57,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     1,     5,     3,     5,     4,     3,     3,
       3,     9,    13,    11,     2,     7,     2,     1,    11,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     1,
       1,     2,     1,     1,     2,     4,     4,     3,     3,     3,
       3,     3,     3
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
        case 3:
#line 68 "source.ypp" /* yacc.c:1646  */
    {
	st.newScope();
}
#line 1365 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 72 "source.ypp" /* yacc.c:1646  */
    {
	if (st.currentScope().size()) {
		st.deleteAndPrintScope();
	}
	else {
		st.deleteScope();
	}
}
#line 1378 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 82 "source.ypp" /* yacc.c:1646  */
    {
	st.newScope();
}
#line 1386 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 86 "source.ypp" /* yacc.c:1646  */
    {
	st.deleteAndPrintScope();	
}
#line 1394 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 90 "source.ypp" /* yacc.c:1646  */
    {
	inBreak++;
}
#line 1402 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 94 "source.ypp" /* yacc.c:1646  */
    {
	inBreak--;
}
#line 1410 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 98 "source.ypp" /* yacc.c:1646  */
    {
	(yyval).next = next();
}
#line 1418 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 102 "source.ypp" /* yacc.c:1646  */
    {
	inCond++;
}
#line 1426 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 106 "source.ypp" /* yacc.c:1646  */
    {
	inCond--;
}
#line 1434 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 114 "source.ypp" /* yacc.c:1646  */
    { 
	assertNotDefinedInScope((yyvsp[-1]).lexema); 
	(yyvsp[-1]).type = (yyvsp[-2]).type;
	(yyvsp[-1]).place = newTemp();
	st.addVar((yyvsp[-1]).lexema, (yyvsp[-1]).type, (yyvsp[-1]).place);  	
}
#line 1445 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 121 "source.ypp" /* yacc.c:1646  */
    {
	assertNotDefinedInScope((yyvsp[-3]).lexema); 
	assertTypeAssignment((yyvsp[-1]).type, (yyvsp[-4]).type);
	(yyvsp[-3]).type = (yyvsp[-4]).type;
	(yyvsp[-3]).place = newTemp();
	st.addVar((yyvsp[-3]).lexema, (yyvsp[-3]).type, (yyvsp[-3]).place);

	if ((yyvsp[-4]).type == VarType::TYPE_BOOL) {
		bp((yyvsp[-1]).falseList, next());
		emit((yyvsp[-3]).place + (yyvsp[-2]).lexema + "0");
		(yyval).nextList = makelist(next());
		emit("goto ");
		bp((yyvsp[-1]).trueList, next());
		emit((yyvsp[-3]).place + (yyvsp[-2]).lexema + "1");

	}  
	else {
		emit((yyvsp[-3]).place + (yyvsp[-2]).lexema + (yyvsp[-1]).place);
	}

}
#line 1471 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 142 "source.ypp" /* yacc.c:1646  */
    {
	assertDefinedGlobaly((yyvsp[-3]).lexema);
	assertTypeAssignment((yyvsp[-1]).type, st.getTypeOf((yyvsp[-3]).lexema));
	(yyvsp[-3]).type = st.getTypeOf((yyvsp[-3]).lexema);	
	(yyvsp[-3]).place = st.getPlaceOf((yyvsp[-3]).lexema);	

	if ((yyvsp[-3]).type == VarType::TYPE_BOOL) {
		bp((yyvsp[-1]).falseList, next());
		emit((yyvsp[-3]).place + (yyvsp[-2]).lexema + "0");
		(yyval).nextList = makelist(next());
		emit("goto ");
		bp((yyvsp[-1]).trueList, next());
		emit((yyvsp[-3]).place + (yyvsp[-2]).lexema + "1");

	}  
	else {
		emit((yyvsp[-3]).place + (yyvsp[-2]).lexema + (yyvsp[-1]).place);
	}
}
#line 1495 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 161 "source.ypp" /* yacc.c:1646  */
    {
	assertDefinedGlobaly((yyvsp[-1]).lexema);
	assertVarTypeNot(VarType::TYPE_BOOL, st.getTypeOf((yyvsp[-1]).lexema));
	print((yyvsp[-1]).place, (yyvsp[-1]).type);

	
}
#line 1507 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 169 "source.ypp" /* yacc.c:1646  */
    {
	assertDefinedGlobaly((yyvsp[-1]).lexema);
	assertVarTypeNot(VarType::TYPE_BOOL, st.getTypeOf((yyvsp[-1]).lexema));

}
#line 1517 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 174 "source.ypp" /* yacc.c:1646  */
    {
	assertVarType(VarType::TYPE_BOOL, (yyvsp[-6]).type);
}
#line 1525 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 178 "source.ypp" /* yacc.c:1646  */
    {
	assertVarType(VarType::TYPE_BOOL, (yyvsp[-10]).type);
}
#line 1533 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 182 "source.ypp" /* yacc.c:1646  */
    {
	assertVarType(VarType::TYPE_BOOL, (yyvsp[-8]).type);

}
#line 1542 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 186 "source.ypp" /* yacc.c:1646  */
    {
	assertCanBreak();
}
#line 1550 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 189 "source.ypp" /* yacc.c:1646  */
    {
	VarType type = (yyvsp[-4]).type; 
	assertThat(type == VarType::TYPE_DECIMAL || type == VarType::TYPE_BINARY || type == VarType::TYPE_HEXIDECIMAL);
}
#line 1559 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 198 "source.ypp" /* yacc.c:1646  */
    {
	(yyval).type = VarType::TYPE_DECIMAL;
}
#line 1567 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 202 "source.ypp" /* yacc.c:1646  */
    {
	(yyval).type = VarType::TYPE_BINARY;
}
#line 1575 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 206 "source.ypp" /* yacc.c:1646  */
    {
	(yyval).type = VarType::TYPE_HEXIDECIMAL;
}
#line 1583 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 210 "source.ypp" /* yacc.c:1646  */
    {
	(yyval).type = (yyvsp[0]).type;
}
#line 1591 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 214 "source.ypp" /* yacc.c:1646  */
    {
	(yyval).type = VarType::TYPE_BOOL;
}
#line 1599 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 218 "source.ypp" /* yacc.c:1646  */
    {
	(yyval).type = (yyvsp[-1]).type;
	(yyval).place = (yyvsp[-1]).place;
}
#line 1608 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 226 "source.ypp" /* yacc.c:1646  */
    {
	assertVarTypeNot(VarType::TYPE_BOOL, (yyvsp[-2]).type);
	assertVarTypeNot(VarType::TYPE_BOOL, (yyvsp[0]).type);
	assertTypeAssignment((yyvsp[-2]).type, (yyvsp[0]).type);
	(yyval).type = (yyvsp[-2]).type;

	(yyval).place = newTemp();
	emit((yyval).place + "=" + (yyvsp[-2]).place + (yyvsp[-1]).lexema + (yyvsp[0]).place);

}
#line 1623 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 237 "source.ypp" /* yacc.c:1646  */
    {
	assertDefinedGlobaly((yyvsp[0]).lexema);
	(yyvsp[0]).type = st.getTypeOf((yyvsp[0]).lexema); 
	(yyval).type = (yyvsp[0]).type;
	(yyval).place = st.getPlaceOf((yyvsp[0]).lexema);

	if (inCond && (yyval).type == VarType::TYPE_BOOL) {
		(yyval).trueList = makelist(next());
		emit("if " + (yyval).place +  "=="  + "1" + " goto " );
		(yyval).falseList = makelist(next());
		emit("goto ");
	}
}
#line 1641 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 252 "source.ypp" /* yacc.c:1646  */
    {
	(yyval).type = VarType::TYPE_DECIMAL;
	(yyval).place = (yyval).place = newTemp();
	emit((yyval).place + "=" + toDecimal((yyvsp[0]).lexema, 10));
}
#line 1651 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 258 "source.ypp" /* yacc.c:1646  */
    {
	(yyval).type = (yyvsp[0]).type;
	(yyval).place = newTemp();
	emit((yyval).place + "=" + toDecimal((yyvsp[-1]).lexema, getBaseOf((yyvsp[0]).type)));

}
#line 1662 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 265 "source.ypp" /* yacc.c:1646  */
    {
	(yyval).type = VarType::TYPE_BOOL;
	(yyval).trueList = makelist(next());
	emit("goto ");
}
#line 1672 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 271 "source.ypp" /* yacc.c:1646  */
    {
	(yyval).type = VarType::TYPE_BOOL;
	(yyval).falseList = makelist(next());
	emit("goto ");
}
#line 1682 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 277 "source.ypp" /* yacc.c:1646  */
    {
	assertVarType(VarType::TYPE_BOOL, (yyvsp[0]).type);
	(yyval).type = VarType::TYPE_BOOL;
	(yyval).falseList = (yyvsp[0]).trueList;
	(yyval).trueList = (yyvsp[0]).falseList;

}
#line 1694 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 285 "source.ypp" /* yacc.c:1646  */
    {
	assertVarType(VarType::TYPE_BOOL, (yyvsp[-3]).type);
	assertVarType(VarType::TYPE_BOOL, (yyvsp[-1]).type);
	(yyval).type = VarType::TYPE_BOOL;

	bp((yyvsp[-3]).falseList, (yyvsp[-1]).next);
	(yyval).falseList = (yyvsp[0]).falseList;
	(yyval).trueList = merge((yyvsp[-3]).trueList, (yyvsp[0]).trueList);
}
#line 1708 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 295 "source.ypp" /* yacc.c:1646  */
    {
	assertVarType(VarType::TYPE_BOOL, (yyvsp[-3]).type);
	assertVarType(VarType::TYPE_BOOL, (yyvsp[-1]).type);
	(yyval).type = VarType::TYPE_BOOL;
	
	bp((yyvsp[-3]).trueList, (yyvsp[-1]).next);
	(yyval).trueList = (yyvsp[0]).trueList;
	(yyval).falseList = merge((yyvsp[-3]).falseList, (yyvsp[0]).falseList);

}
#line 1723 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 306 "source.ypp" /* yacc.c:1646  */
    {
	assertTypeAssignment((yyvsp[-2]).type, (yyvsp[0]).type);
	(yyval).type = VarType::TYPE_BOOL;
	
	(yyval).trueList = makelist(next());
	emit("if " + (yyvsp[-2]).place +  "<"  + (yyvsp[0]).place + " goto ");
	(yyval).trueList = merge((yyval).trueList, makelist(next()));
	emit("if " + (yyvsp[-2]).place + "==" + (yyvsp[0]).place + " goto ");
	(yyval).falseList = makelist(next());
	emit("goto ");
}
#line 1739 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 318 "source.ypp" /* yacc.c:1646  */
    {
	assertTypeAssignment((yyvsp[-2]).type, (yyvsp[0]).type);
	(yyval).type = VarType::TYPE_BOOL;
	
	(yyval).trueList = makelist(next());
	emit("if " + (yyvsp[-2]).place +  ">"  + (yyvsp[0]).place + " goto ");
	(yyval).trueList = merge((yyval).trueList, makelist(next()));
	emit("if" + (yyvsp[-2]).place + "==" + (yyvsp[0]).place + " goto ");
	(yyval).falseList = makelist(next());
	emit("goto ");
}
#line 1755 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 330 "source.ypp" /* yacc.c:1646  */
    {
	assertTypeAssignment((yyvsp[-2]).type, (yyvsp[0]).type);
	(yyval).type = VarType::TYPE_BOOL;
	emitRopExpression((yyval), (yyvsp[-2]), "==", (yyvsp[0]));
}
#line 1765 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 336 "source.ypp" /* yacc.c:1646  */
    {
	assertTypeAssignment((yyvsp[-2]).type, (yyvsp[0]).type);
	(yyval).type = VarType::TYPE_BOOL;
	emitRopExpression((yyval), (yyvsp[-2]), "!=", (yyvsp[0]));
}
#line 1775 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 342 "source.ypp" /* yacc.c:1646  */
    {
	assertTypeAssignment((yyvsp[-2]).type, (yyvsp[0]).type);
	(yyval).type = VarType::TYPE_BOOL;
	emitRopExpression((yyval), (yyvsp[-2]), "<", (yyvsp[0]));

}
#line 1786 "source.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 349 "source.ypp" /* yacc.c:1646  */
    {
	assertTypeAssignment((yyvsp[-2]).type, (yyvsp[0]).type);
	(yyval).type = VarType::TYPE_BOOL;
	emitRopExpression((yyval), (yyvsp[-2]), ">", (yyvsp[0]));
	
}
#line 1797 "source.tab.cpp" /* yacc.c:1646  */
    break;


#line 1801 "source.tab.cpp" /* yacc.c:1646  */
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
#line 356 "source.ypp" /* yacc.c:1906  */


int main(){
	return yyparse();
}

void print(string var, VarType type) {
	
	string printType;
	if (type == VarType::TYPE_DECIMAL) {
		printType = "printD ";
	}
	else if (type == VarType::TYPE_HEXIDECIMAL) {
		printType = "printH ";
	}
	else if (type == VarType::TYPE_BINARY) {
		printType = "printB ";
	}
	cout << printType  + var << endl;
	
}

void emitAopExpression(string target, string lhs, string aop, string rhs) {
	emit(target + "=" + lhs + aop + rhs);
}

string toDecimal(string numstr, int base) {
	return to_string(stoul(numstr, NULL, base));
}

int getBaseOf(VarType varType) {
	if (varType == VarType::TYPE_BINARY) 	return 2;
	else if (varType == TYPE_HEXIDECIMAL) 	return 16;
	else  									return 10;
}

void emitRopExpression(Attribute& target, Attribute& lhs, string rop, Attribute& rhs) {
	target.trueList = makelist(next());
	emit("if " + lhs.place +  rop  + rhs.place + " goto ");
	target.falseList = makelist(next());
	emit("goto ");
}

void assertThat(bool condition) {
	if (!condition) {
		errorMismatch(yylineno);
		exit(1);
	}
}

void assertNotDefinedInScope(string& name) {
	if (st.isDefinedInScope(name)) {
		errorDef(yylineno,name.c_str());
		exit(1);
	}
}

void assertDefinedGlobaly(string& name) {
	if (!st.isDefined(name)) {
		errorUndef(yylineno, name.c_str());
		exit(1);
	}
}

void assertTypeAssignment(VarType from, VarType to) {
	//std::cout << "from = " << from << " to = " << to << std::endl;
	if (from == VarType::TYPE_BOOL) {
		assertVarType(VarType::TYPE_BOOL, to);
	}
	if (to == VarType::TYPE_BOOL) {
		assertVarType(VarType::TYPE_BOOL, from);
	}
}

void assertVarTypeNot(VarType forbidden, VarType type) {
	if (forbidden == type) {
		errorMismatch(yylineno);
		exit(1);
	}
}

void assertVarType(VarType desired, VarType type) {
	if (desired != type) {
		errorMismatch(yylineno);
		exit(1);
	}
}

void assertCanBreak() {
	if (!inBreak) {
		errorUnexpectedBreak(yylineno);
		exit(1);
	}
}

void yyerror(const char*){
	errorSyn(yylineno);
	exit(0);
}
															