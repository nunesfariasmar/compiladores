%option c++ prefix="gr8_scanner_" outfile="gr8_scanner.cpp"
%option stack noyywrap yylineno 8bit debug
%{
// make relevant includes before including the parser's tab file
#include <string>
#include <vector>
#include <stdlib.h>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include <cdk/ast/lvalue_node.h>
#include "gr8_parser.tab.h"

std::vector<int> pilha(1,0);
int current_identation = 0;
int i;

// don't change this
#define yyerror LexerError
%}
%x X_STRING X_COMMENT X_LINE X_IDENT X_CHECK_IDENT X_STRING_IGNORE
%%
                {set_debug(0);}

"<<"					yy_push_state(X_COMMENT); /* ignore comments */
<X_COMMENT>"<<"			yy_push_state(X_COMMENT);
<X_COMMENT>">>"			yy_pop_state();
<X_COMMENT>.|\n 		;


^[a-zA-Z0-9.()]+             {if (current_identation != 0){
                        yy_push_state(X_CHECK_IDENT);
                        current_identation = 0;
                        yyless(0);}
                        else {yyless(0);
                        }
                    }

"below"                return '<';
"above"                return '>';
"equals"               return tEQ;
"minus"                return '-';
"plus"                 return '+';
"times"                return '*';
"over"				         return '/';
"modulus"              return '%';
"not"                  return tNOT;
"and"                  return tAND;
"or"                   return tOR;

"if"                   return tIF;
"else"                 return tELSE;
"input"                return tREAD;
"define"               return tDEFINE;
"public"               return tPUBLIC;
"as"                   return tAS;
"function"             return tFUNCTION;
"procedure"            return tPROCEDURE;
"small"                return tINT;
"huge"                 return tREAL;
"on"                   return tON;
"news"                 return tNEWS;
"initially"            return tINITIALLY;
"fake"                 return tFAKE;
"tweet"                return tTWEET;
"post"                 return tPOST;
"again"                return tAGAIN;
"stop"                 return tSTOP;
"return"               return tRETURN;
"assign"           	   return tASSIGN;
"to"                   return tTO;
"sweeping"             return tSWEEPING;
"from"                 return tFROM;
"by"                   return tBY;
"do"                   return tDO;
"uses"				         return tUSES;
"elsif"				         return tELIF;
"then"				         return tTHEN;
"use"                  return tUSE;
"for"                  return tFOR;
"cell"                 return tCELL;
"at"                   return tAT;
"null"                 return tNULL;
"objects"              return tOBJECTS;
[?]                    return '?';


[A-Za-z][A-Za-z0-9-]*  yylval.s = new std::string(yytext); return tIDENTIFIER;

\"                              yy_push_state(X_STRING); yylval.s = new std::string("");
<X_STRING>\"                    yy_pop_state(); return tSTRING;
<X_STRING>'~'\"                 *yylval.s += yytext + 1;
<X_STRING>.                     *yylval.s += yytext;
<X_STRING>"~~"                  *yylval.s += yytext + 1;
<X_STRING>"~0"                  yy_push_state(X_STRING_IGNORE);
<X_STRING>"~"[0-6][0-6][0-6]    {i = strtol(yytext+1, nullptr, 7);
                                  if (i > 255) yyerror("Invalid number in base 7 (Overflow)");
                                  else *yylval.s += i;
                                }
<X_STRING>"~"[0-6][0-6]         i = strtol(yytext+1, nullptr, 7); *yylval.s += i;
<X_STRING>"~"[1-6]              i = strtol(yytext+1, nullptr, 7); *yylval.s += i;
<X_STRING>"~t"		              *yylval.s += '\t';
<X_STRING>"~n"		              *yylval.s += '\n';
<X_STRING>"~r"		              *yylval.s += '\r';
<X_STRING>\n                    yyerror("newline in string");

<X_STRING_IGNORE>\"    yy_pop_state(); yy_pop_state(); return tSTRING;
<X_STRING_IGNORE>\n    yyerror("newline in string");
<X_STRING_IGNORE>.     ;

"..."\n                  yy_push_state(X_LINE);
<X_LINE>"..."\n          ;
<X_LINE>\n               yy_pop_state();
<X_LINE>.                ;

[0-9]*[.][0-9]+				  yylval.d = atof(yytext); return tDOUBLE;
[0-9]+[eE][-][0-9]+			yylval.d = atof(yytext); return tDOUBLE;
[0-9]+[eE][0-9]+			  yylval.d = atof(yytext); return tDOUBLE;

[0-9]*[.][0-9][eE][-][0-9]+			yylval.d = atof(yytext); return tDOUBLE;
[0-9]*[.][0-9][eE][0-9]+			  yylval.d = atof(yytext); return tDOUBLE;

[1-9][0-9]*              yylval.i = strtol(yytext, nullptr, 10); return tINTEGER;
[0][0-6]*                yylval.i = strtol(yytext, nullptr, 7); return tINTEGER;


[\n]+                  return ';';

^[ \t]                 yy_push_state(X_IDENT); current_identation = 0; yyless(0);

<X_IDENT>\t          {if ((current_identation % 8) == 0) current_identation += 8;
                      else current_identation = current_identation + 8 - (current_identation % 8);}
<X_IDENT>[ ]         {current_identation += 1; }
<X_IDENT>.           {if (current_identation > pilha.back()) {
                          pilha.push_back(current_identation);
                          yy_pop_state();
                          yyless(0);
                          return '{'; }

                        else if (current_identation < pilha.back()){
                          yy_push_state(X_CHECK_IDENT);
                          yyless(0);
                          }

                        else{
                          yy_pop_state();
                          yyless(0);
                          }
                        }

<X_CHECK_IDENT>.     {if (pilha.empty()) yyerror("Bad Identation");
                         else if(current_identation == pilha.back()){ yy_pop_state(); yyless(0);}
                         else {pilha.pop_back(); yyless(0); return '}';}

                        }

<<EOF>>                {if(pilha.back() == 0) return 0;
						            else{
							              pilha.pop_back();
                            return '}';
						                }
						            }

[()=;{},]       return *yytext;


"!!".*$               ;
^[ ]+$                ;
[ \t] 			          ;

.                     std::cout << "THIS FUCKER: " << yytext << std::endl; yyerror("Unknown character");

%%
