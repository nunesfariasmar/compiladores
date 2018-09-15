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
extern YYSTYPE yylval;
