#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20110908

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "gr8_parser.y"
/*-- don't change *any* of these: if you do, you'll break the compiler.*/
#include <cdk/compiler.h>
#include "ast/all.h"
#define LINE               compiler->scanner()->lineno()
#define yylex()            compiler->scanner()->scan()
#define yyerror(s)         compiler->scanner()->error(s)
#define YYPARSE_PARAM_TYPE std::shared_ptr<cdk::compiler>
#define YYPARSE_PARAM      compiler
/*-- don't change *any* of these --- END!*/
#line 13 "gr8_parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  int                   i;	/* integer value */
  std::string          *s;	/* symbol name or string literal */
  double                d;
  cdk::basic_node      *node;	/* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  cdk::lvalue_node     *lvalue;
  gr8::block_node      *block;
  basic_type      *type;
  cdk::typed_node   *typed_node;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 53 "gr8_parser.y"
/*-- The rules below will be included in yyparse, the main parsing function.*/
#line 51 "gr8_parser.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#define YYERROR_DECL() yyerror(const char *s)
#define YYERROR_CALL(msg) yyerror(msg)

extern int YYPARSE_DECL();

#define tINTEGER 257
#define tIDENTIFIER 258
#define tSTRING 259
#define tDOUBLE 260
#define tIF 261
#define tREAD 262
#define tAS 263
#define tDEFINE 264
#define tPUBLIC 265
#define tFUNCTION 266
#define tPROCEDURE 267
#define tINT 268
#define tREAL 269
#define tUSES 270
#define tINITIALLY 271
#define tON 272
#define tNEWS 273
#define tFAKE 274
#define tTWEET 275
#define tPOST 276
#define tAGAIN 277
#define tSTOP 278
#define tRETURN 279
#define tELIF 280
#define tTHEN 281
#define tASSIGN 282
#define tTO 283
#define tSWEEPING 284
#define tFROM 285
#define tBY 286
#define tDO 287
#define tAND 288
#define tOR 289
#define tNOT 290
#define tUSE 291
#define tFOR 292
#define tCELL 293
#define tAT 294
#define tNULL 295
#define tOBJECTS 296
#define tIFX 297
#define tELSE 298
#define tEQ 299
#define tUNARY 300
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    0,    6,    6,   20,   20,   20,   20,   20,   20,
   18,   18,   18,   18,   19,   19,   19,   19,    8,    8,
   21,   21,   21,   21,    7,    7,   22,   22,   22,   22,
   23,   23,   23,   23,    5,    5,    5,    5,   14,   14,
   14,   14,   14,   14,   15,   15,   16,   16,   17,   17,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    2,    2,    2,    3,    3,    3,    3,
   11,    4,    4,   10,   10,   10,   10,   10,   10,   10,
   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,
   10,   10,   10,   10,   24,   24,    9,    9,   13,   13,
   12,   12,   12,   12,
};
static const short yylen[] = {                            2,
    1,    0,    1,    2,    2,    2,    1,    1,    2,    4,
    6,    5,    4,    3,    5,    4,    3,    2,    1,    3,
    7,    6,    3,    2,    1,    2,    7,    6,    9,    8,
    6,    5,    8,    7,    5,    4,    4,    3,    1,    1,
    1,    2,    2,    2,    1,    2,    1,    2,    1,    2,
    2,    3,    3,    3,    2,    3,    2,    3,    2,    2,
    2,    1,    1,    6,    4,    6,    3,    5,    5,    7,
    4,   10,    8,    1,    1,    1,    1,    1,    2,    2,
    2,    2,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    2,    1,    1,    2,    1,    3,    1,    4,
    2,    4,    1,    3,
};
static const short yydefred[] = {                         0,
    0,    0,    0,    0,    0,   41,   49,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    3,    0,    7,    8,
    0,    0,    0,    0,    0,    0,    0,    4,    0,    0,
   46,   42,   48,   43,   44,   50,    5,    6,    9,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   19,   10,    0,    0,    0,    0,    0,    0,   32,
    0,    0,    0,    0,    0,    0,    0,    0,   74,   99,
   95,   76,   78,    0,    0,    0,    0,   77,    0,    0,
    0,    0,   94,    0,    0,    0,   31,    0,    0,    0,
    0,    0,   28,    0,    0,    0,   20,  101,    0,    0,
    0,    0,   82,   81,    0,    0,    0,   79,    0,    0,
    0,    0,    0,    0,    0,    0,   22,   93,   96,    0,
   27,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   38,   25,   63,   62,    0,    0,    0,    0,    0,
   34,    0,   21,    0,    0,    0,  104,    0,    0,    0,
    0,    0,    0,    0,   85,   86,   87,   33,    0,    0,
    0,    0,    0,   55,    0,   57,   59,    0,    0,    0,
   60,   36,    0,   37,   26,   51,   61,   30,  102,    0,
  100,  103,   29,    0,   52,   53,   54,   56,   58,    0,
    0,   35,    0,   71,    0,    0,    0,    0,    0,    0,
   66,    0,    0,    0,    0,    0,    0,    0,    0,   73,
    0,    0,    0,    0,   68,   72,    0,   70,
};
static const short yydgoto[] = {                          9,
  143,  144,  209,  145,  146,   10,  148,   60,  110,  149,
  150,   93,   94,   61,   12,   13,   14,   15,   16,   17,
   62,   19,   20,   95,
};
static const short yysindex[] = {                        88,
  281,  289, -257,    0,    0,    0,    0,   52,    0,   88,
 -223, -154, -151, -232,  -39,   10,    0,   43,    0,    0,
  327, -166, -162, -133, -218, -136, -127,    0,   96, -114,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -109,
 -118, -200, -108, -115,  117,  -94,  314,  106, -105, -100,
 -198,  -80,  120,  314, -175,  314,  -91,  -87,   52,  141,
  -71,    0,    0,  740,  314,  120,  314, -169,   65,    0,
  -42,  120,  314,  141,  740,  314,  -67,  314,    0,    0,
    0,    0,    0,  -65,  740,  740,  740,    0,  740,  740,
  740,   17,    0,  131,  -64,  141,    0,  -31,  120,  314,
  530,  120,    0,  -30,   39,  141,    0,    0,  340,  -28,
  340,   48,    0,    0,   70,  740,  740,    0,  740,  740,
  740,  740,  740,  740,  740,  740,    0,    0,    0,  120,
    0,  -29,  740,  740,  740,  -47,  -38,  905,  740, -249,
  350,    0,    0,    0,    0,  137,  571,  811,   79,  145,
    0,  120,    0,  -58,  740,   31,    0,  116,  116,  116,
  116,  116,   19,   19,    0,    0,    0,    0,  120,  100,
  109,  130,  149,    0,  150,    0,    0,  139,  160,  -72,
    0,    0,  857,    0,    0,    0,    0,    0,    0,  340,
    0,    0,    0,  120,    0,    0,    0,    0,    0, -249,
  740,    0, -241,    0,  169,  740,  120,  740,  -63,  181,
    0,    8,  740,  120,  740,  120,  272,  -83,  303,    0,
  120,  120,  120,  -73,    0,    0,  120,    0,
};
static const short yyrindex[] = {                       227,
    0,    0,    0, -139, -191,    0,    0,    0,    0,  235,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  177,    0,    0,  -33,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  179,  -26,    0,    0,    0,    0,  180,
    0,    0,    0,    0,    0,    0,    0,  188,    0,  189,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  194,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -37,  -13,  195,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  197,    0,    0,  249,    0,
  -27,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  201,  225,  432,
  463,  485,  371,  401,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -25,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  898,    0,    0,    0,    0,    0,  950,    0,
    0,    0,    0,    0,    0,    0,    0,  633,    0,    0,
    0,    0,    0,  694,    0,    0,    0,    0,
};
static const short yygindex[] = {                         0,
 -110,    0,    0,    0, 1100,  157,   93,   33,    0, 1212,
    0,  115, -104,  576,    0,    0,    0,    0,    0,   -7,
   27,    0,    0,    0,
};
#define YYTABLESIZE 1427
static const short yytable[] = {                        103,
   26,   78,   28,  103,  103,  103,  103,  103,   80,  103,
   24,  174,   78,   78,   78,  155,   97,   23,   98,   37,
  176,  103,  103,   75,  103,   24,   18,   75,   75,   75,
   75,   75,   23,   75,   29,  180,   18,  185,  206,   45,
   35,   36,   30,   87,  126,   75,   75,   46,   75,  124,
  122,  192,  123,  126,  125,  126,  207,  127,  124,  122,
  124,  123,   53,  125,   66,  125,   40,  121,   38,  120,
   91,   54,  185,   67,   40,  126,  121,   47,  120,  153,
  124,  122,   47,  123,  126,  125,   71,   72,   74,  124,
  122,   42,  123,   99,  125,  204,   73,   96,  121,   98,
  120,   39,  100,   43,  107,  104,  126,  121,  106,  120,
  157,  124,  122,   31,  123,  126,  125,   33,   39,   32,
  124,  122,   34,  123,   44,  125,   39,   18,   45,  121,
   48,  120,  132,   47,   45,   49,  126,  186,  121,   28,
  120,  124,  122,   50,  123,  126,  125,   52,   51,   55,
  124,  122,  126,  123,   56,  125,   57,  124,  122,  121,
  123,  120,  125,   58,   63,   64,  126,  195,  121,   65,
  120,  124,  122,   18,  123,  126,  125,   68,   69,   75,
  124,  122,   76,  123,   78,  125,   29,  101,  196,  121,
   45,  120,  108,  128,  129,  181,  126,  199,  121,  189,
  120,  124,  122,  187,  123,  126,  125,  197,  198,  173,
  124,  122,  201,  123,  222,  125,  213,  126,  175,  121,
  102,  120,  124,  122,  227,  123,    2,  125,  121,   24,
  120,  130,  152,  169,    1,   18,   23,   17,   14,  183,
  121,   91,  120,  103,   91,  103,   13,   16,  103,  103,
  103,  103,   15,   12,  103,   11,  103,  147,  103,   91,
   91,  103,   91,  154,   97,   92,   98,   75,   92,   75,
  191,    0,   75,   75,   75,   75,    0,    0,   75,    0,
   75,    0,   75,   92,   92,   75,   92,    0,   80,   80,
    0,    0,   80,  215,  216,  116,  117,    0,    0,    0,
    0,    0,    0,  118,  116,  117,  119,   80,  126,    0,
    0,    0,  118,  124,  122,  119,  123,   84,  125,    4,
    5,   86,    0,   87,    6,    7,  116,  117,    0,    0,
    0,  121,    0,  120,  118,  116,  117,  119,    0,  126,
    0,  156,    0,  118,  124,  122,  119,  123,    0,  125,
    0,    1,    2,    0,    3,    4,    5,  116,  117,    0,
    6,    7,  121,    0,  120,  118,  116,  117,  119,    0,
    0,    0,    0,    0,  118,    0,  126,  119,    8,    0,
  194,  124,  122,    0,  123,    0,  125,  116,  117,   91,
    0,    0,   89,    0,   90,  118,  116,  117,  119,  121,
    0,  120,    0,    0,  118,    0,    0,  119,    0,    0,
    0,   83,    0,   83,   83,   83,    0,  116,  117,    0,
    0,    0,    0,    0,    0,  118,  116,  117,  119,   83,
   83,    0,   83,    0,  118,    0,    0,  119,    0,    0,
    0,   84,  200,   84,   84,   84,    0,  116,  117,    0,
    0,  208,    0,    0,    0,  118,  116,  117,  119,   84,
   84,  214,   84,    0,  118,    0,    0,  119,  116,  117,
    0,    0,   90,    0,    0,   90,  118,    0,    0,  119,
    0,   91,    0,   91,    0,    0,   91,   91,   91,   91,
   90,   90,   91,   90,   91,    0,   91,    0,    0,   91,
    0,    0,    0,   89,    0,   92,   89,   92,    0,    0,
   92,   92,   92,   92,    0,    0,   92,    0,   92,    0,
   92,   89,   89,   92,   89,   88,    0,    0,   88,   80,
    0,   80,    0,    0,   80,   80,    0,    0,    0,    0,
   80,    0,   80,   88,   88,   21,   88,   22,    4,    5,
    0,    0,  221,    6,    7,   24,    4,    5,    0,  116,
  117,    6,    7,    0,    0,    0,    0,  118,    0,   91,
  119,    0,   89,    0,   90,   11,   23,   25,   59,    0,
    0,    4,    5,   27,    0,   11,    6,    7,   69,  223,
  116,  117,    0,   40,    4,    5,   41,    0,  118,    6,
    7,  119,    0,    0,    0,    0,   79,   80,   81,   82,
   91,   83,    0,   89,    0,   90,    0,    4,    5,    0,
    0,    0,    6,    7,    0,    0,    0,  116,  117,   69,
    0,    0,    0,    0,   77,  118,   84,    0,  119,   85,
   86,    0,   87,    0,   88,    0,    0,    0,    0,    0,
    0,   83,    0,   83,  142,    0,   83,   83,   83,   83,
    0,    0,   83,    0,   83,    0,   83,    0,    0,   83,
    0,    0,   67,    0,    0,   67,   11,   67,    0,    0,
    0,   84,    0,   84,    0,    0,   84,   84,   84,   84,
    0,   67,   84,    0,   84,  182,   84,    0,    0,   84,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   90,    0,   90,    0,   27,   90,   90,   90,
   90,    0,   11,   90,    0,   90,    0,   90,    0,    0,
   90,    0,    0,   69,    0,    0,   69,    0,   69,    0,
    0,    0,    0,   89,    0,   89,    0,    0,   89,   89,
   89,   89,   69,    0,   89,    0,   89,   67,   89,    0,
    0,   89,    0,    0,    0,   88,    0,   88,    0,    0,
   88,   88,   88,   88,    0,    0,   88,    0,   88,   91,
   88,    0,   89,   88,   90,    0,   79,   80,   81,   82,
  133,   83,    0,    1,    2,    0,    3,    4,    5,    0,
    0,    0,    6,    7,  134,  135,  136,  137,  138,    0,
    0,  139,    0,  140,    0,    0,   84,    0,   69,   85,
  141,    0,   87,    0,   88,    0,    0,   79,   80,   81,
   82,  133,   83,    0,    1,    2,    0,    3,    4,    5,
    0,    0,    0,    6,    7,  134,  135,  136,  137,  138,
   91,    0,  139,   89,  140,   90,    0,   84,    0,    0,
   85,  141,    0,   87,    0,   88,    0,    0,    0,   69,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   67,
   67,   67,   67,   67,   67,    0,   91,    0,    0,   89,
    0,   90,    0,    0,    0,    0,    0,   67,   67,   67,
   67,   67,   67,    0,   67,   69,   67,    0,    0,   67,
    0,    0,   67,   67,    0,   67,    0,   67,    0,    0,
    0,    0,    0,    0,    0,  184,    0,   65,    0,    0,
   65,    0,   65,    0,   91,    0,    0,   89,    0,   90,
   69,   69,   69,   69,   69,   69,   65,    0,    0,    0,
    0,    0,    0,  177,    0,    0,    0,    0,   69,   69,
   69,   69,   69,   69,    0,   69,    0,   69,    0,    0,
   69,  202,    0,   69,   69,    0,   69,    0,   69,   64,
    0,    0,   64,    0,   64,    0,   79,   80,   81,   82,
    0,   83,    0,    0,    0,    0,    0,    0,   64,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   65,    0,    0,    0,   84,    0,    0,   85,
   86,    0,   87,    0,   88,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   79,   80,   81,
   82,  133,   83,    0,   64,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  134,  135,  136,  137,  138,
    0,    0,  139,    0,  140,    0,    0,   84,    0,    0,
   85,   86,    0,   87,    0,   88,    0,    0,    0,    0,
    0,    0,    0,   79,   80,   81,   82,  133,   83,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  134,  135,  136,  137,  138,    0,    0,  139,    0,
  140,    0,    0,   84,    0,    0,   85,   86,    0,   87,
    0,   88,   70,    0,   65,   65,   65,   65,   65,   65,
    0,   79,   80,   81,   82,   97,   83,    0,    0,    0,
    0,  103,   65,   65,   65,   65,   65,    0,    0,   65,
    0,   65,    0,    0,   65,    0,    0,   65,   65,    0,
   65,   84,   65,    0,   85,   86,    0,   87,  131,   88,
    0,  151,    0,    0,    0,    0,   64,   64,   64,   64,
   64,   64,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   64,   64,   64,   64,   64,  168,
    0,   64,    0,   64,    0,    0,   64,    0,    0,   64,
   64,    0,   64,    0,   64,    0,    0,    0,    0,    0,
    0,  188,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  193,    0,
    0,    0,    0,    0,    0,   92,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  105,    0,    0,    0,
    0,    0,    0,  203,    0,    0,  109,  111,  112,    0,
  113,  114,  115,    0,    0,    0,  211,    0,    0,    0,
    0,    0,    0,  218,    0,  220,    0,    0,    0,    0,
  224,  225,  226,    0,    0,    0,  228,  158,  159,    0,
  160,  161,  162,  163,  164,  165,  166,  167,    0,    0,
    0,    0,    0,    0,  170,  171,  172,    0,    0,  178,
  179,    0,  111,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  190,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  205,    0,    0,    0,    0,  210,    0,  212,
    0,    0,    0,    0,  217,    0,  219,
};
static const short yycheck[] = {                         37,
  258,   44,   10,   41,   42,   43,   44,   45,  258,   47,
   44,   59,   44,   44,   44,   44,   44,   44,   44,   59,
   59,   59,   60,   37,   62,   59,    0,   41,   42,   43,
   44,   45,   59,   47,  258,  140,   10,  148,  280,  258,
  273,  274,  266,  293,   37,   59,   60,  266,   62,   42,
   43,  156,   45,   37,   47,   37,  298,   41,   42,   43,
   42,   45,  263,   47,  263,   47,  258,   60,   59,   62,
   40,  272,  183,  272,  266,   37,   60,  269,   62,   41,
   42,   43,  274,   45,   37,   47,   54,  263,   56,   42,
   43,  258,   45,  263,   47,  200,  272,   65,   60,   67,
   62,   59,  272,  266,   78,   73,   37,   60,   76,   62,
   41,   42,   43,  268,   45,   37,   47,  269,  258,  274,
   42,   43,  274,   45,  258,   47,  266,  101,  268,   60,
  258,   62,  100,  270,  274,   40,   37,   59,   60,  147,
   62,   42,   43,  258,   45,   37,   47,  266,  258,  258,
   42,   43,   37,   45,  270,   47,   40,   42,   43,   60,
   45,   62,   47,  258,   59,  271,   37,   59,   60,  270,
   62,   42,   43,  147,   45,   37,   47,  258,   59,  271,
   42,   43,  270,   45,   44,   47,  258,  123,   59,   60,
  258,   62,  258,   63,  259,   59,   37,   59,   60,  258,
   62,   42,   43,   59,   45,   37,   47,   59,   59,  257,
   42,   43,  285,   45,  298,   47,  280,   37,  257,   60,
  263,   62,   42,   43,  298,   45,    0,   47,   60,  263,
   62,  263,  263,  263,    0,   59,  263,   59,   59,  147,
   60,   41,   62,  281,   44,  283,   59,   59,  286,  287,
  288,  289,   59,   59,  292,   59,  294,  101,  296,   59,
   60,  299,   62,  292,  292,   41,  292,  281,   44,  283,
  156,   -1,  286,  287,  288,  289,   -1,   -1,  292,   -1,
  294,   -1,  296,   59,   60,  299,   62,   -1,  258,   41,
   -1,   -1,   44,  286,  287,  288,  289,   -1,   -1,   -1,
   -1,   -1,   -1,  296,  288,  289,  299,   59,   37,   -1,
   -1,   -1,  296,   42,   43,  299,   45,  287,   47,  268,
  269,  291,   -1,  293,  273,  274,  288,  289,   -1,   -1,
   -1,   60,   -1,   62,  296,  288,  289,  299,   -1,   37,
   -1,  294,   -1,  296,   42,   43,  299,   45,   -1,   47,
   -1,  264,  265,   -1,  267,  268,  269,  288,  289,   -1,
  273,  274,   60,   -1,   62,  296,  288,  289,  299,   -1,
   -1,   -1,   -1,   -1,  296,   -1,   37,  299,  291,   -1,
  281,   42,   43,   -1,   45,   -1,   47,  288,  289,   40,
   -1,   -1,   43,   -1,   45,  296,  288,  289,  299,   60,
   -1,   62,   -1,   -1,  296,   -1,   -1,  299,   -1,   -1,
   -1,   41,   -1,   43,   44,   45,   -1,  288,  289,   -1,
   -1,   -1,   -1,   -1,   -1,  296,  288,  289,  299,   59,
   60,   -1,   62,   -1,  296,   -1,   -1,  299,   -1,   -1,
   -1,   41,  283,   43,   44,   45,   -1,  288,  289,   -1,
   -1,  283,   -1,   -1,   -1,  296,  288,  289,  299,   59,
   60,  281,   62,   -1,  296,   -1,   -1,  299,  288,  289,
   -1,   -1,   41,   -1,   -1,   44,  296,   -1,   -1,  299,
   -1,  281,   -1,  283,   -1,   -1,  286,  287,  288,  289,
   59,   60,  292,   62,  294,   -1,  296,   -1,   -1,  299,
   -1,   -1,   -1,   41,   -1,  281,   44,  283,   -1,   -1,
  286,  287,  288,  289,   -1,   -1,  292,   -1,  294,   -1,
  296,   59,   60,  299,   62,   41,   -1,   -1,   44,  281,
   -1,  283,   -1,   -1,  286,  287,   -1,   -1,   -1,   -1,
  292,   -1,  294,   59,   60,  265,   62,  267,  268,  269,
   -1,   -1,  281,  273,  274,  267,  268,  269,   -1,  288,
  289,  273,  274,   -1,   -1,   -1,   -1,  296,   -1,   40,
  299,   -1,   43,   -1,   45,    0,    1,    2,  265,   -1,
   -1,  268,  269,    8,   -1,   10,  273,  274,   59,  287,
  288,  289,   -1,  267,  268,  269,   21,   -1,  296,  273,
  274,  299,   -1,   -1,   -1,   -1,  257,  258,  259,  260,
   40,  262,   -1,   43,   -1,   45,   -1,  268,  269,   -1,
   -1,   -1,  273,  274,   -1,   -1,   -1,  288,  289,   59,
   -1,   -1,   -1,   -1,   59,  296,  287,   -1,  299,  290,
  291,   -1,  293,   -1,  295,   -1,   -1,   -1,   -1,   -1,
   -1,  281,   -1,  283,  125,   -1,  286,  287,  288,  289,
   -1,   -1,  292,   -1,  294,   -1,  296,   -1,   -1,  299,
   -1,   -1,   40,   -1,   -1,   43,  101,   45,   -1,   -1,
   -1,  281,   -1,  283,   -1,   -1,  286,  287,  288,  289,
   -1,   59,  292,   -1,  294,  125,  296,   -1,   -1,  299,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  281,   -1,  283,   -1,  141,  286,  287,  288,
  289,   -1,  147,  292,   -1,  294,   -1,  296,   -1,   -1,
  299,   -1,   -1,   40,   -1,   -1,   43,   -1,   45,   -1,
   -1,   -1,   -1,  281,   -1,  283,   -1,   -1,  286,  287,
  288,  289,   59,   -1,  292,   -1,  294,  125,  296,   -1,
   -1,  299,   -1,   -1,   -1,  281,   -1,  283,   -1,   -1,
  286,  287,  288,  289,   -1,   -1,  292,   -1,  294,   40,
  296,   -1,   43,  299,   45,   -1,  257,  258,  259,  260,
  261,  262,   -1,  264,  265,   -1,  267,  268,  269,   -1,
   -1,   -1,  273,  274,  275,  276,  277,  278,  279,   -1,
   -1,  282,   -1,  284,   -1,   -1,  287,   -1,  125,  290,
  291,   -1,  293,   -1,  295,   -1,   -1,  257,  258,  259,
  260,  261,  262,   -1,  264,  265,   -1,  267,  268,  269,
   -1,   -1,   -1,  273,  274,  275,  276,  277,  278,  279,
   40,   -1,  282,   43,  284,   45,   -1,  287,   -1,   -1,
  290,  291,   -1,  293,   -1,  295,   -1,   -1,   -1,   59,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,
  258,  259,  260,  261,  262,   -1,   40,   -1,   -1,   43,
   -1,   45,   -1,   -1,   -1,   -1,   -1,  275,  276,  277,
  278,  279,  280,   -1,  282,   59,  284,   -1,   -1,  287,
   -1,   -1,  290,  291,   -1,  293,   -1,  295,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  125,   -1,   40,   -1,   -1,
   43,   -1,   45,   -1,   40,   -1,   -1,   43,   -1,   45,
  257,  258,  259,  260,  261,  262,   59,   -1,   -1,   -1,
   -1,   -1,   -1,   59,   -1,   -1,   -1,   -1,  275,  276,
  277,  278,  279,  280,   -1,  282,   -1,  284,   -1,   -1,
  287,  125,   -1,  290,  291,   -1,  293,   -1,  295,   40,
   -1,   -1,   43,   -1,   45,   -1,  257,  258,  259,  260,
   -1,  262,   -1,   -1,   -1,   -1,   -1,   -1,   59,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  125,   -1,   -1,   -1,  287,   -1,   -1,  290,
  291,   -1,  293,   -1,  295,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
  260,  261,  262,   -1,  125,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  275,  276,  277,  278,  279,
   -1,   -1,  282,   -1,  284,   -1,   -1,  287,   -1,   -1,
  290,  291,   -1,  293,   -1,  295,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  257,  258,  259,  260,  261,  262,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  275,  276,  277,  278,  279,   -1,   -1,  282,   -1,
  284,   -1,   -1,  287,   -1,   -1,  290,  291,   -1,  293,
   -1,  295,   53,   -1,  257,  258,  259,  260,  261,  262,
   -1,  257,  258,  259,  260,   66,  262,   -1,   -1,   -1,
   -1,   72,  275,  276,  277,  278,  279,   -1,   -1,  282,
   -1,  284,   -1,   -1,  287,   -1,   -1,  290,  291,   -1,
  293,  287,  295,   -1,  290,  291,   -1,  293,   99,  295,
   -1,  102,   -1,   -1,   -1,   -1,  257,  258,  259,  260,
  261,  262,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  275,  276,  277,  278,  279,  130,
   -1,  282,   -1,  284,   -1,   -1,  287,   -1,   -1,  290,
  291,   -1,  293,   -1,  295,   -1,   -1,   -1,   -1,   -1,
   -1,  152,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  169,   -1,
   -1,   -1,   -1,   -1,   -1,   64,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   75,   -1,   -1,   -1,
   -1,   -1,   -1,  194,   -1,   -1,   85,   86,   87,   -1,
   89,   90,   91,   -1,   -1,   -1,  207,   -1,   -1,   -1,
   -1,   -1,   -1,  214,   -1,  216,   -1,   -1,   -1,   -1,
  221,  222,  223,   -1,   -1,   -1,  227,  116,  117,   -1,
  119,  120,  121,  122,  123,  124,  125,  126,   -1,   -1,
   -1,   -1,   -1,   -1,  133,  134,  135,   -1,   -1,  138,
  139,   -1,  141,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  155,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  201,   -1,   -1,   -1,   -1,  206,   -1,  208,
   -1,   -1,   -1,   -1,  213,   -1,  215,
};
#define YYFINAL 9
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 300
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'",0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
0,"';'","'<'",0,"'>'","'?'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,"tINTEGER","tIDENTIFIER","tSTRING","tDOUBLE","tIF",
"tREAD","tAS","tDEFINE","tPUBLIC","tFUNCTION","tPROCEDURE","tINT","tREAL",
"tUSES","tINITIALLY","tON","tNEWS","tFAKE","tTWEET","tPOST","tAGAIN","tSTOP",
"tRETURN","tELIF","tTHEN","tASSIGN","tTO","tSWEEPING","tFROM","tBY","tDO",
"tAND","tOR","tNOT","tUSE","tFOR","tCELL","tAT","tNULL","tOBJECTS","tIFX",
"tELSE","tEQ","tUNARY",
};
static const char *yyrule[] = {
"$accept : file",
"file : listd",
"file :",
"listd : decl",
"listd : listd decl",
"decl : func_decl ';'",
"decl : procedure_decl ';'",
"decl : func",
"decl : procedure",
"decl : var ';'",
"decl : tUSE type tIDENTIFIER ';'",
"func_decl : tPUBLIC type tFUNCTION tIDENTIFIER tUSES vars",
"func_decl : type tFUNCTION tIDENTIFIER tUSES vars",
"func_decl : tPUBLIC type tFUNCTION tIDENTIFIER",
"func_decl : type tFUNCTION tIDENTIFIER",
"procedure_decl : tPUBLIC tPROCEDURE tIDENTIFIER tUSES vars",
"procedure_decl : tPROCEDURE tIDENTIFIER tUSES vars",
"procedure_decl : tPUBLIC tPROCEDURE tIDENTIFIER",
"procedure_decl : tPROCEDURE tIDENTIFIER",
"vars : var",
"vars : vars ',' var",
"var : tPUBLIC type tIDENTIFIER '(' tINITIALLY expr ')'",
"var : type tIDENTIFIER '(' tINITIALLY expr ')'",
"var : tPUBLIC type tIDENTIFIER",
"var : type tIDENTIFIER",
"listi : instruction",
"listi : listi instruction",
"func : tDEFINE tPUBLIC type tFUNCTION tIDENTIFIER tAS block",
"func : tDEFINE type tFUNCTION tIDENTIFIER tAS block",
"func : tDEFINE tPUBLIC type tFUNCTION tIDENTIFIER tON vars tAS block",
"func : tDEFINE type tFUNCTION tIDENTIFIER tON vars tAS block",
"procedure : tDEFINE tPUBLIC tPROCEDURE tIDENTIFIER tAS block",
"procedure : tDEFINE tPROCEDURE tIDENTIFIER tAS block",
"procedure : tDEFINE tPUBLIC tPROCEDURE tIDENTIFIER tON vars tAS block",
"procedure : tDEFINE tPROCEDURE tIDENTIFIER tON vars tAS block",
"block : ';' '{' listd listi '}'",
"block : ';' '{' listd '}'",
"block : ';' '{' listi '}'",
"block : ';' '{' '}'",
"type : tINT",
"type : tREAL",
"type : tNEWS",
"type : smalls tFAKE",
"type : huges tFAKE",
"type : fakes tNEWS",
"smalls : tINT",
"smalls : smalls tINT",
"huges : tREAL",
"huges : huges tREAL",
"fakes : tFAKE",
"fakes : fakes tFAKE",
"instruction : expr ';'",
"instruction : tTWEET expr ';'",
"instruction : tPOST expr ';'",
"instruction : tAGAIN tINTEGER ';'",
"instruction : tAGAIN ';'",
"instruction : tSTOP tINTEGER ';'",
"instruction : tSTOP ';'",
"instruction : tRETURN expr ';'",
"instruction : tRETURN ';'",
"instruction : block ';'",
"instruction : assignment ';'",
"instruction : sweep",
"instruction : if",
"if : tIF expr tTHEN block tELIF elsif",
"if : tIF expr tTHEN block",
"if : tIF expr tTHEN block tELSE block",
"elsif : expr tTHEN block",
"elsif : expr tTHEN block tELSE block",
"elsif : elsif tELIF expr tTHEN block",
"elsif : elsif tELIF expr tTHEN block tELSE block",
"assignment : tASSIGN expr tTO lval",
"sweep : tSWEEPING lval tFROM expr tTO expr tBY expr tDO block",
"sweep : tSWEEPING lval tFROM expr tTO expr tDO block",
"expr : tINTEGER",
"expr : strings",
"expr : tDOUBLE",
"expr : tNULL",
"expr : tREAD",
"expr : expr tOBJECTS",
"expr : tNOT expr",
"expr : '-' expr",
"expr : '+' expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr tEQ expr",
"expr : expr tAND expr",
"expr : expr tOR expr",
"expr : lval '?'",
"expr : specialexpr",
"strings : tSTRING",
"strings : strings tSTRING",
"param : expr",
"param : param ',' expr",
"lval : tIDENTIFIER",
"lval : tCELL expr tAT specialexpr",
"specialexpr : tDO tIDENTIFIER",
"specialexpr : tUSE param tFOR tIDENTIFIER",
"specialexpr : lval",
"specialexpr : '(' expr ')'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = data->s_mark - data->s_base;
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 57 "gr8_parser.y"
	{ compiler->ast(yystack.l_mark[0].sequence); }
break;
case 2:
#line 58 "gr8_parser.y"
	{ compiler->ast(new cdk::sequence_node(LINE)); }
break;
case 3:
#line 61 "gr8_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].typed_node); }
break;
case 4:
#line 62 "gr8_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].typed_node, yystack.l_mark[-1].sequence); }
break;
case 5:
#line 65 "gr8_parser.y"
	{ yyval.typed_node = yystack.l_mark[-1].typed_node; }
break;
case 6:
#line 66 "gr8_parser.y"
	{ yyval.typed_node = yystack.l_mark[-1].typed_node; }
break;
case 7:
#line 67 "gr8_parser.y"
	{ yyval.typed_node = yystack.l_mark[0].typed_node; }
break;
case 8:
#line 68 "gr8_parser.y"
	{ yyval.typed_node = yystack.l_mark[0].typed_node; }
break;
case 9:
#line 69 "gr8_parser.y"
	{ yyval.typed_node = yystack.l_mark[-1].typed_node; }
break;
case 10:
#line 70 "gr8_parser.y"
	{ yyval.typed_node = new gr8::variable_declaration_node(LINE, true, yystack.l_mark[-1].s, new gr8::null_node(LINE));}
break;
case 11:
#line 73 "gr8_parser.y"
	{ yyval.typed_node = new gr8::function_declaration_node(LINE, true, yystack.l_mark[-2].s, yystack.l_mark[0].sequence); yyval.typed_node->type(yystack.l_mark[-4].type);  }
break;
case 12:
#line 74 "gr8_parser.y"
	{ yyval.typed_node = new gr8::function_declaration_node(LINE, false, yystack.l_mark[-2].s, yystack.l_mark[0].sequence); yyval.typed_node->type(yystack.l_mark[-4].type); }
break;
case 13:
#line 75 "gr8_parser.y"
	{ yyval.typed_node = new gr8::function_declaration_node(LINE, true, yystack.l_mark[0].s, new cdk::sequence_node(LINE)); yyval.typed_node->type(yystack.l_mark[-2].type); }
break;
case 14:
#line 76 "gr8_parser.y"
	{ yyval.typed_node = new gr8::function_declaration_node(LINE, false, yystack.l_mark[0].s, new cdk::sequence_node(LINE)); yyval.typed_node->type(yystack.l_mark[-2].type); }
break;
case 15:
#line 79 "gr8_parser.y"
	{ yyval.typed_node = new gr8::function_declaration_node(LINE, true, yystack.l_mark[-2].s, yystack.l_mark[0].sequence); yyval.typed_node->type(new basic_type(0, basic_type::TYPE_VOID)); }
break;
case 16:
#line 80 "gr8_parser.y"
	{ yyval.typed_node = new gr8::function_declaration_node(LINE, false, yystack.l_mark[-2].s, yystack.l_mark[0].sequence); yyval.typed_node->type(new basic_type(0, basic_type::TYPE_VOID)); }
break;
case 17:
#line 81 "gr8_parser.y"
	{ yyval.typed_node = new gr8::function_declaration_node(LINE, true, yystack.l_mark[0].s, new cdk::sequence_node(LINE)); yyval.typed_node->type(new basic_type(0, basic_type::TYPE_VOID));}
break;
case 18:
#line 82 "gr8_parser.y"
	{ yyval.typed_node = new gr8::function_declaration_node(LINE, false, yystack.l_mark[0].s, new cdk::sequence_node(LINE)); yyval.typed_node->type(new basic_type(0, basic_type::TYPE_VOID));}
break;
case 19:
#line 85 "gr8_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].typed_node); }
break;
case 20:
#line 86 "gr8_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].typed_node, yystack.l_mark[-2].sequence); }
break;
case 21:
#line 89 "gr8_parser.y"
	{ yyval.typed_node = new gr8::variable_declaration_node(LINE, true, yystack.l_mark[-4].s, yystack.l_mark[-1].expression); yyval.typed_node->type(yystack.l_mark[-5].type);}
break;
case 22:
#line 90 "gr8_parser.y"
	{ yyval.typed_node = new gr8::variable_declaration_node(LINE, false, yystack.l_mark[-4].s, yystack.l_mark[-1].expression); yyval.typed_node->type(yystack.l_mark[-5].type); }
break;
case 23:
#line 91 "gr8_parser.y"
	{ yyval.typed_node = new gr8::variable_declaration_node(LINE, true, yystack.l_mark[0].s, new gr8::null_node(LINE)); yyval.typed_node->type(yystack.l_mark[-1].type); }
break;
case 24:
#line 92 "gr8_parser.y"
	{ yyval.typed_node = new gr8::variable_declaration_node(LINE, false, yystack.l_mark[0].s, new gr8::null_node(LINE)); yyval.typed_node->type(yystack.l_mark[-1].type); }
break;
case 25:
#line 96 "gr8_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node); }
break;
case 26:
#line 97 "gr8_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-1].sequence); }
break;
case 27:
#line 100 "gr8_parser.y"
	{ yyval.typed_node = new gr8::function_node(LINE, true, yystack.l_mark[-2].s, new cdk::sequence_node(LINE), yystack.l_mark[0].block); yyval.typed_node->type(yystack.l_mark[-4].type); }
break;
case 28:
#line 101 "gr8_parser.y"
	{ yyval.typed_node = new gr8::function_node(LINE, false, yystack.l_mark[-2].s, new cdk::sequence_node(LINE), yystack.l_mark[0].block); yyval.typed_node->type(yystack.l_mark[-4].type); }
break;
case 29:
#line 102 "gr8_parser.y"
	{ yyval.typed_node = new gr8::function_node(LINE, true, yystack.l_mark[-4].s, yystack.l_mark[-2].sequence, yystack.l_mark[0].block); yyval.typed_node->type(yystack.l_mark[-6].type); }
break;
case 30:
#line 103 "gr8_parser.y"
	{ yyval.typed_node = new gr8::function_node(LINE, false, yystack.l_mark[-4].s, yystack.l_mark[-2].sequence, yystack.l_mark[0].block); yyval.typed_node->type(yystack.l_mark[-6].type); }
break;
case 31:
#line 106 "gr8_parser.y"
	{ yyval.typed_node = new gr8::function_node(LINE, true, yystack.l_mark[-2].s, new cdk::sequence_node(LINE), yystack.l_mark[0].block); yyval.typed_node->type(new basic_type(0, basic_type::TYPE_VOID));}
break;
case 32:
#line 107 "gr8_parser.y"
	{ yyval.typed_node = new gr8::function_node(LINE, false, yystack.l_mark[-2].s, new cdk::sequence_node(LINE), yystack.l_mark[0].block); yyval.typed_node->type(new basic_type(0, basic_type::TYPE_VOID));}
break;
case 33:
#line 108 "gr8_parser.y"
	{ yyval.typed_node = new gr8::function_node(LINE, true, yystack.l_mark[-4].s, yystack.l_mark[-2].sequence, yystack.l_mark[0].block); yyval.typed_node->type(new basic_type(0, basic_type::TYPE_VOID));}
break;
case 34:
#line 109 "gr8_parser.y"
	{ yyval.typed_node = new gr8::function_node(LINE, false, yystack.l_mark[-4].s, yystack.l_mark[-2].sequence, yystack.l_mark[0].block); yyval.typed_node->type(new basic_type(0, basic_type::TYPE_VOID));}
break;
case 35:
#line 113 "gr8_parser.y"
	{ yyval.block = new gr8::block_node(LINE, yystack.l_mark[-2].sequence, yystack.l_mark[-1].sequence); }
break;
case 36:
#line 114 "gr8_parser.y"
	{ yyval.block = new gr8::block_node(LINE, yystack.l_mark[-1].sequence, new cdk::sequence_node(LINE)); }
break;
case 37:
#line 115 "gr8_parser.y"
	{ yyval.block = new gr8::block_node(LINE, new cdk::sequence_node(LINE), yystack.l_mark[-1].sequence); }
break;
case 38:
#line 116 "gr8_parser.y"
	{ yyval.block = new gr8::block_node(LINE, new cdk::sequence_node(LINE), new cdk::sequence_node(LINE)); }
break;
case 39:
#line 119 "gr8_parser.y"
	{ yyval.type = new basic_type(4, basic_type::TYPE_INT); }
break;
case 40:
#line 120 "gr8_parser.y"
	{ yyval.type = new basic_type(8, basic_type::TYPE_DOUBLE); }
break;
case 41:
#line 121 "gr8_parser.y"
	{ yyval.type = new basic_type(4, basic_type::TYPE_STRING); }
break;
case 42:
#line 122 "gr8_parser.y"
	{ yyval.type = new basic_type(4, basic_type::TYPE_POINTER); yyval.type->_subtype = yystack.l_mark[-1].type; }
break;
case 43:
#line 123 "gr8_parser.y"
	{ yyval.type = new basic_type(8, basic_type::TYPE_POINTER); yyval.type->_subtype = yystack.l_mark[-1].type; }
break;
case 44:
#line 124 "gr8_parser.y"
	{ yyval.type = new basic_type(4, basic_type::TYPE_POINTER); yyval.type->_subtype = yystack.l_mark[-1].type; }
break;
case 45:
#line 127 "gr8_parser.y"
	{ yyval.type = new basic_type(4, basic_type::TYPE_INT); }
break;
case 46:
#line 128 "gr8_parser.y"
	{ yyval.type = new basic_type(4, basic_type::TYPE_POINTER); yyval.type->_subtype = yystack.l_mark[-1].type; }
break;
case 47:
#line 131 "gr8_parser.y"
	{ yyval.type = new basic_type(8, basic_type::TYPE_DOUBLE); }
break;
case 48:
#line 132 "gr8_parser.y"
	{ yyval.type = new basic_type(8, basic_type::TYPE_POINTER); yyval.type->_subtype = yystack.l_mark[-1].type; }
break;
case 49:
#line 135 "gr8_parser.y"
	{ yyval.type = new basic_type(4, basic_type::TYPE_STRING); }
break;
case 50:
#line 136 "gr8_parser.y"
	{ yyval.type = new basic_type(4, basic_type::TYPE_POINTER); yyval.type->_subtype = yystack.l_mark[-1].type; }
break;
case 51:
#line 139 "gr8_parser.y"
	{ yyval.node = new gr8::evaluation_node(LINE, yystack.l_mark[-1].expression); }
break;
case 52:
#line 140 "gr8_parser.y"
	{ yyval.node = new gr8::print_node(LINE, yystack.l_mark[-1].expression, false); }
break;
case 53:
#line 141 "gr8_parser.y"
	{ yyval.node = new gr8::print_node(LINE, yystack.l_mark[-1].expression, true); }
break;
case 54:
#line 142 "gr8_parser.y"
	{ yyval.node = new gr8::again_node(LINE, yystack.l_mark[-1].i); }
break;
case 55:
#line 143 "gr8_parser.y"
	{ yyval.node = new gr8::again_node(LINE, 1); }
break;
case 56:
#line 144 "gr8_parser.y"
	{yyval.node = new gr8::stop_node(LINE, yystack.l_mark[-1].i); }
break;
case 57:
#line 145 "gr8_parser.y"
	{ yyval.node = new gr8::stop_node(LINE, 1); }
break;
case 58:
#line 146 "gr8_parser.y"
	{ yyval.node = new gr8::return_node(LINE, yystack.l_mark[-1].expression); }
break;
case 59:
#line 147 "gr8_parser.y"
	{ yyval.node = new gr8::return_node(LINE, new gr8::null_node(LINE)); }
break;
case 60:
#line 148 "gr8_parser.y"
	{ yyval.node = yystack.l_mark[-1].block; }
break;
case 61:
#line 149 "gr8_parser.y"
	{ yyval.node = yystack.l_mark[-1].expression; }
break;
case 62:
#line 150 "gr8_parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 63:
#line 151 "gr8_parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 64:
#line 154 "gr8_parser.y"
	{ yyval.node = new gr8::if_else_node(LINE, yystack.l_mark[-4].expression, yystack.l_mark[-2].block, yystack.l_mark[0].node); }
break;
case 65:
#line 155 "gr8_parser.y"
	{ yyval.node = new gr8::if_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].block); }
break;
case 66:
#line 156 "gr8_parser.y"
	{ yyval.node = new gr8::if_else_node(LINE, yystack.l_mark[-4].expression, yystack.l_mark[-2].block, yystack.l_mark[0].block); }
break;
case 67:
#line 159 "gr8_parser.y"
	{ yyval.node = new gr8::if_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].block); }
break;
case 68:
#line 160 "gr8_parser.y"
	{ yyval.node = new gr8::if_else_node(LINE, yystack.l_mark[-4].expression, yystack.l_mark[-2].block, yystack.l_mark[0].block); }
break;
case 69:
#line 161 "gr8_parser.y"
	{ yyval.node = new gr8::if_else_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].block, yystack.l_mark[-4].node); }
break;
case 70:
#line 162 "gr8_parser.y"
	{ yyval.node = new gr8::if_else_node(LINE, yystack.l_mark[-4].expression, yystack.l_mark[-2].block, yystack.l_mark[0].block); }
break;
case 71:
#line 165 "gr8_parser.y"
	{ yyval.expression = new cdk::assignment_node(LINE, yystack.l_mark[0].lvalue, yystack.l_mark[-2].expression);}
break;
case 72:
#line 168 "gr8_parser.y"
	{ yyval.node = new gr8::sweep_node(LINE, yystack.l_mark[-8].lvalue, yystack.l_mark[-4].expression, yystack.l_mark[0].block, yystack.l_mark[-6].expression, yystack.l_mark[-2].expression); }
break;
case 73:
#line 169 "gr8_parser.y"
	{ yyval.node = new gr8::sweep_node(LINE, yystack.l_mark[-6].lvalue, yystack.l_mark[-2].expression, yystack.l_mark[0].block, yystack.l_mark[-4].expression, new cdk::integer_node(LINE, 1)); }
break;
case 74:
#line 172 "gr8_parser.y"
	{ yyval.expression = new cdk::integer_node(LINE, yystack.l_mark[0].i); }
break;
case 75:
#line 173 "gr8_parser.y"
	{ yyval.expression = new cdk::string_node(LINE, yystack.l_mark[0].s); }
break;
case 76:
#line 174 "gr8_parser.y"
	{ yyval.expression = new cdk::double_node(LINE, yystack.l_mark[0].d); }
break;
case 77:
#line 175 "gr8_parser.y"
	{ yyval.expression = new gr8::null_node(LINE);}
break;
case 78:
#line 176 "gr8_parser.y"
	{ yyval.expression = new gr8::read_node(LINE);}
break;
case 79:
#line 177 "gr8_parser.y"
	{ yyval.expression = new gr8::memory_reservation_node(LINE, yystack.l_mark[-1].expression);}
break;
case 80:
#line 178 "gr8_parser.y"
	{ yyval.expression = new cdk::not_node(LINE, yystack.l_mark[0].expression);}
break;
case 81:
#line 179 "gr8_parser.y"
	{ yyval.expression = new cdk::neg_node(LINE, yystack.l_mark[0].expression); }
break;
case 82:
#line 180 "gr8_parser.y"
	{ yyval.expression = new gr8::identity_node(LINE, yystack.l_mark[0].expression); }
break;
case 83:
#line 181 "gr8_parser.y"
	{ yyval.expression = new cdk::add_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 84:
#line 182 "gr8_parser.y"
	{ yyval.expression = new cdk::sub_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 85:
#line 183 "gr8_parser.y"
	{ yyval.expression = new cdk::mul_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 86:
#line 184 "gr8_parser.y"
	{ yyval.expression = new cdk::div_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 87:
#line 185 "gr8_parser.y"
	{ yyval.expression = new cdk::mod_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 88:
#line 186 "gr8_parser.y"
	{ yyval.expression = new cdk::lt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 89:
#line 187 "gr8_parser.y"
	{ yyval.expression = new cdk::gt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 90:
#line 188 "gr8_parser.y"
	{ yyval.expression = new cdk::eq_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 91:
#line 189 "gr8_parser.y"
	{ yyval.expression = new cdk::and_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression);}
break;
case 92:
#line 190 "gr8_parser.y"
	{ yyval.expression = new cdk::or_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 93:
#line 191 "gr8_parser.y"
	{ yyval.expression = new gr8::address_node(LINE, yystack.l_mark[-1].lvalue); }
break;
case 94:
#line 192 "gr8_parser.y"
	{ yyval.expression = yystack.l_mark[0].expression; }
break;
case 95:
#line 195 "gr8_parser.y"
	{yyval.s = yystack.l_mark[0].s; }
break;
case 96:
#line 196 "gr8_parser.y"
	{ yyval.s = new std::string(*yystack.l_mark[-1].s + * yystack.l_mark[0].s); delete yystack.l_mark[-1].s; delete yystack.l_mark[0].s; }
break;
case 97:
#line 199 "gr8_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].expression);}
break;
case 98:
#line 200 "gr8_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].expression, yystack.l_mark[-2].sequence); }
break;
case 99:
#line 203 "gr8_parser.y"
	{ yyval.lvalue = new cdk::identifier_node(LINE, yystack.l_mark[0].s); }
break;
case 100:
#line 204 "gr8_parser.y"
	{ yyval.lvalue = new gr8::index_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 101:
#line 208 "gr8_parser.y"
	{ yyval.expression = new gr8::function_call_node(LINE, yystack.l_mark[0].s, new cdk::sequence_node(LINE)); }
break;
case 102:
#line 209 "gr8_parser.y"
	{ yyval.expression = new gr8::function_call_node(LINE, yystack.l_mark[0].s, yystack.l_mark[-2].sequence);}
break;
case 103:
#line 210 "gr8_parser.y"
	{ yyval.expression = new cdk::rvalue_node(LINE, yystack.l_mark[0].lvalue); }
break;
case 104:
#line 211 "gr8_parser.y"
	{ yyval.expression = yystack.l_mark[-1].expression; }
break;
#line 1313 "gr8_parser.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
