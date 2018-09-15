%{
//-- don't change *any* of these: if you do, you'll break the compiler.
#include <cdk/compiler.h>
#include "ast/all.h"
#define LINE               compiler->scanner()->lineno()
#define yylex()            compiler->scanner()->scan()
#define yyerror(s)         compiler->scanner()->error(s)
#define YYPARSE_PARAM_TYPE std::shared_ptr<cdk::compiler>
#define YYPARSE_PARAM      compiler
//-- don't change *any* of these --- END!
%}

%union {
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
};

%token <i> tINTEGER
%token <s> tIDENTIFIER tSTRING
%token <d> tDOUBLE
%token tIF tREAD tAS tDEFINE tPUBLIC tFUNCTION tPROCEDURE tINT tREAL tUSES tINITIALLY tON tNEWS tFAKE tTWEET tPOST tAGAIN tSTOP tRETURN tELIF tTHEN tASSIGN tTO tSWEEPING tFROM tBY tDO tAND tOR tNOT tDOUBLE tUSE tFOR tCELL tAT tNULL tOBJECTS

%nonassoc tIFX
%nonassoc tELSE
%nonassoc tNOT
%nonassoc tOBJECTS

%left tAT
%left tEQ '>' '<' tAND tOR
%left '+' '-'
%left '*' '/' '%'
%nonassoc tUNARY '?'


%type <node> file instruction if elsif sweep
%type <block> block
%type <sequence> listd listi vars param
%type <expression> expr assignment specialexpr
%type <lvalue> lval
%type <type> type smalls huges fakes
%type <typed_node> func_decl procedure_decl decl var func procedure
%type <s> strings

%{
//-- The rules below will be included in yyparse, the main parsing function.
%}
%%

file	  : listd { compiler->ast($1); }
        |       { compiler->ast(new cdk::sequence_node(LINE)); }
	      ;

listd   : decl	     { $$ = new cdk::sequence_node(LINE, $1); }
	      | listd decl { $$ = new cdk::sequence_node(LINE, $2, $1); }
	      ;

decl    :   func_decl  ';'            { $$ = $1; }
        |   procedure_decl ';'        { $$ = $1; }
        |   func                      { $$ = $1; }
        |   procedure                 { $$ = $1; }
        |   var ';'                   { $$ = $1; }
        |   tUSE type tIDENTIFIER ';' { $$ = new gr8::variable_declaration_node(LINE, true, $3, new gr8::null_node(LINE));}
        ;

func_decl    : tPUBLIC type tFUNCTION tIDENTIFIER tUSES vars  { $$ = new gr8::function_declaration_node(LINE, true, $4, $6); $$->type($2);  }
             | type tFUNCTION tIDENTIFIER tUSES vars          { $$ = new gr8::function_declaration_node(LINE, false, $3, $5); $$->type($1); }
             | tPUBLIC type tFUNCTION tIDENTIFIER             { $$ = new gr8::function_declaration_node(LINE, true, $4, new cdk::sequence_node(LINE)); $$->type($2); }
             | type tFUNCTION tIDENTIFIER                     { $$ = new gr8::function_declaration_node(LINE, false, $3, new cdk::sequence_node(LINE)); $$->type($1); }
             ;

procedure_decl    : tPUBLIC tPROCEDURE tIDENTIFIER tUSES vars { $$ = new gr8::function_declaration_node(LINE, true, $3, $5); $$->type(new basic_type(0, basic_type::TYPE_VOID)); }
                  | tPROCEDURE tIDENTIFIER tUSES vars         { $$ = new gr8::function_declaration_node(LINE, false, $2, $4); $$->type(new basic_type(0, basic_type::TYPE_VOID)); }
                  | tPUBLIC tPROCEDURE tIDENTIFIER            { $$ = new gr8::function_declaration_node(LINE, true, $3, new cdk::sequence_node(LINE)); $$->type(new basic_type(0, basic_type::TYPE_VOID));}
                  | tPROCEDURE tIDENTIFIER                    { $$ = new gr8::function_declaration_node(LINE, false, $2, new cdk::sequence_node(LINE)); $$->type(new basic_type(0, basic_type::TYPE_VOID));}
                  ;

vars              : var          { $$ = new cdk::sequence_node(LINE, $1); }
                  | vars ',' var { $$ = new cdk::sequence_node(LINE, $3, $1); }
                  ;

var                : tPUBLIC type tIDENTIFIER '(' tINITIALLY expr ')' { $$ = new gr8::variable_declaration_node(LINE, true, $3, $6); $$->type($2);}
                   | type tIDENTIFIER '(' tINITIALLY expr ')'         { $$ = new gr8::variable_declaration_node(LINE, false, $2, $5); $$->type($1); }
                   | tPUBLIC type tIDENTIFIER                         { $$ = new gr8::variable_declaration_node(LINE, true, $3, new gr8::null_node(LINE)); $$->type($2); }
                   | type tIDENTIFIER                                 { $$ = new gr8::variable_declaration_node(LINE, false, $2, new gr8::null_node(LINE)); $$->type($1); }
                   ;


listi   : instruction	      { $$ = new cdk::sequence_node(LINE, $1); }
	      | listi instruction { $$ = new cdk::sequence_node(LINE, $2, $1); }
	      ;

func    : tDEFINE tPUBLIC type tFUNCTION tIDENTIFIER tAS block          { $$ = new gr8::function_node(LINE, true, $5, new cdk::sequence_node(LINE), $7); $$->type($3); }
        | tDEFINE type tFUNCTION tIDENTIFIER tAS block                  { $$ = new gr8::function_node(LINE, false, $4, new cdk::sequence_node(LINE), $6); $$->type($2); }
        | tDEFINE tPUBLIC type tFUNCTION tIDENTIFIER tON vars tAS block { $$ = new gr8::function_node(LINE, true, $5, $7, $9); $$->type($3); }
        | tDEFINE type tFUNCTION tIDENTIFIER tON vars tAS block         { $$ = new gr8::function_node(LINE, false, $4, $6, $8); $$->type($2); }
        ;

procedure   : tDEFINE tPUBLIC tPROCEDURE tIDENTIFIER tAS block          { $$ = new gr8::function_node(LINE, true, $4, new cdk::sequence_node(LINE), $6); $$->type(new basic_type(0, basic_type::TYPE_VOID));}
            | tDEFINE tPROCEDURE tIDENTIFIER tAS block                  { $$ = new gr8::function_node(LINE, false, $3, new cdk::sequence_node(LINE), $5); $$->type(new basic_type(0, basic_type::TYPE_VOID));}
            | tDEFINE tPUBLIC tPROCEDURE tIDENTIFIER tON vars tAS block { $$ = new gr8::function_node(LINE, true, $4, $6, $8); $$->type(new basic_type(0, basic_type::TYPE_VOID));}
            | tDEFINE tPROCEDURE tIDENTIFIER tON vars tAS block         { $$ = new gr8::function_node(LINE, false, $3, $5, $7); $$->type(new basic_type(0, basic_type::TYPE_VOID));}
            ;


block   : ';' '{' listd listi '}'   { $$ = new gr8::block_node(LINE, $3, $4); }
        | ';' '{' listd '}'         { $$ = new gr8::block_node(LINE, $3, new cdk::sequence_node(LINE)); }
        | ';' '{' listi '}'         { $$ = new gr8::block_node(LINE, new cdk::sequence_node(LINE), $3); }
        | ';' '{' '}'               { $$ = new gr8::block_node(LINE, new cdk::sequence_node(LINE), new cdk::sequence_node(LINE)); }
        ;

type : tINT               { $$ = new basic_type(4, basic_type::TYPE_INT); }
     | tREAL              { $$ = new basic_type(8, basic_type::TYPE_DOUBLE); }
     | tNEWS              { $$ = new basic_type(4, basic_type::TYPE_STRING); }
     | smalls tFAKE       { $$ = new basic_type(4, basic_type::TYPE_POINTER); $$->_subtype = $1; }
     | huges tFAKE        { $$ = new basic_type(8, basic_type::TYPE_POINTER); $$->_subtype = $1; }
     | fakes tNEWS        { $$ = new basic_type(4, basic_type::TYPE_POINTER); $$->_subtype = $1; }
     ;

smalls : tINT             { $$ = new basic_type(4, basic_type::TYPE_INT); }
       | smalls tINT      { $$ = new basic_type(4, basic_type::TYPE_POINTER); $$->_subtype = $1; }
       ;

huges : tREAL             { $$ = new basic_type(8, basic_type::TYPE_DOUBLE); }
      | huges tREAL      { $$ = new basic_type(8, basic_type::TYPE_POINTER); $$->_subtype = $1; }
      ;

fakes : tFAKE             { $$ = new basic_type(4, basic_type::TYPE_STRING); }
      | fakes tFAKE       { $$ = new basic_type(4, basic_type::TYPE_POINTER); $$->_subtype = $1; }
      ;

instruction : expr ';'           { $$ = new gr8::evaluation_node(LINE, $1); }
            | tTWEET expr ';'    { $$ = new gr8::print_node(LINE, $2, false); }
            | tPOST expr ';'     { $$ = new gr8::print_node(LINE, $2, true); }
            | tAGAIN tINTEGER ';'{ $$ = new gr8::again_node(LINE, $2); }
            | tAGAIN ';'         { $$ = new gr8::again_node(LINE, 1); }
            | tSTOP tINTEGER ';' {$$ = new gr8::stop_node(LINE, $2); }
            | tSTOP ';'          { $$ = new gr8::stop_node(LINE, 1); }
            | tRETURN expr ';'   { $$ = new gr8::return_node(LINE, $2); }
            | tRETURN ';'        { $$ = new gr8::return_node(LINE, new gr8::null_node(LINE)); }
            | block ';'          { $$ = $1; }
            | assignment ';'     { $$ = $1; }
            | sweep              { $$ = $1; }
            | if                 { $$ = $1; }
            ;

if   : tIF expr tTHEN block tELIF elsif       { $$ = new gr8::if_else_node(LINE, $2, $4, $6); }
     | tIF expr tTHEN block             { $$ = new gr8::if_node(LINE, $2, $4); }
     | tIF expr tTHEN block tELSE block { $$ = new gr8::if_else_node(LINE, $2, $4, $6); }
     ;

elsif: expr tTHEN block                 { $$ = new gr8::if_node(LINE, $1, $3); }
	 | expr tTHEN block tELSE block       { $$ = new gr8::if_else_node(LINE, $1, $3, $5); }
	 | elsif tELIF expr tTHEN block             { $$ = new gr8::if_else_node(LINE, $3, $5, $1); }
	 | elsif tELIF expr tTHEN block tELSE block { $$ = new gr8::if_else_node(LINE, $3, $5, $7); }
	 ;

assignment: tASSIGN expr tTO lval { $$ = new cdk::assignment_node(LINE, $4, $2);}
          ;

sweep : tSWEEPING lval tFROM expr tTO expr tBY expr tDO block { $$ = new gr8::sweep_node(LINE, $2, $6, $10, $4, $8); }
      | tSWEEPING lval tFROM expr tTO expr tDO block          { $$ = new gr8::sweep_node(LINE, $2, $6, $8, $4, new cdk::integer_node(LINE, 1)); }
      ;

expr : tINTEGER                { $$ = new cdk::integer_node(LINE, $1); }
	   | strings                 { $$ = new cdk::string_node(LINE, $1); }
	   | tDOUBLE                 { $$ = new cdk::double_node(LINE, $1); }
	   | tNULL				           { $$ = new gr8::null_node(LINE);}
	   | tREAD                   { $$ = new gr8::read_node(LINE);}
	   | expr tOBJECTS           { $$ = new gr8::memory_reservation_node(LINE, $1);}
	   | tNOT expr               { $$ = new cdk::not_node(LINE, $2);}
     | '-' expr %prec tUNARY   { $$ = new cdk::neg_node(LINE, $2); }
     | '+' expr %prec tUNARY   { $$ = new gr8::identity_node(LINE, $2); }
     | expr '+' expr	         { $$ = new cdk::add_node(LINE, $1, $3); }
     | expr '-' expr	         { $$ = new cdk::sub_node(LINE, $1, $3); }
     | expr '*' expr	         { $$ = new cdk::mul_node(LINE, $1, $3); }
     | expr '/' expr	         { $$ = new cdk::div_node(LINE, $1, $3); }
     | expr '%' expr	         { $$ = new cdk::mod_node(LINE, $1, $3); }
     | expr '<' expr	         { $$ = new cdk::lt_node(LINE, $1, $3); }
     | expr '>' expr	         { $$ = new cdk::gt_node(LINE, $1, $3); }
     | expr tEQ expr	         { $$ = new cdk::eq_node(LINE, $1, $3); }
     | expr tAND expr          { $$ = new cdk::and_node(LINE, $1, $3);}
     | expr tOR expr           { $$ = new cdk::or_node(LINE, $1, $3); }
     | lval '?'                { $$ = new gr8::address_node(LINE, $1); }
     | specialexpr             { $$ = $1; }
     ;

strings : tSTRING         {$$ = $1; }
        | strings tSTRING { $$ = new std::string(*$1 + * $2); delete $1; delete $2; }
        ;

param : expr          { $$ = new cdk::sequence_node(LINE, $1);}
	  | param ',' expr  { $$ = new cdk::sequence_node(LINE, $3, $1); }
	  ;

lval : tIDENTIFIER                    { $$ = new cdk::identifier_node(LINE, $1); }
     | tCELL expr tAT specialexpr     { $$ = new gr8::index_node(LINE, $2, $4); }
     ;


specialexpr :        tDO tIDENTIFIER         { $$ = new gr8::function_call_node(LINE, $2, new cdk::sequence_node(LINE)); }
                   | tUSE param tFOR tIDENTIFIER { $$ = new gr8::function_call_node(LINE, $4, $2);}
                   | lval                    { $$ = new cdk::rvalue_node(LINE, $1); }
                   | '(' expr ')'            { $$ = $2; }
                   ;
%%
