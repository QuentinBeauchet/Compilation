D                       [0-9]
L                       [a-zA-Z_]
H                       [a-fA-F0-9]

%{
#include <stdio.h>
#include "y.tab.h"


/* Ne gère pas les commentaires. A rajouter */
/* Supprimer les lignes dont vous n'avez pas besoin. */

%}

%%
"break"                 { return BREAK; }
"case"                  { return CASE; }
"const"                 { return CONSTANTE; }
"default"               { return DEFAULT; }
"else"                  { return ELSE; }
"extern"                { return EXTERN; }
"for"                   { return FOR; }
"if"                    { return IF; }
"int"                   { return INT; }
"return"                { return RETURN; }
"switch"                { return SWITCH; }
"void"                  { return VOID; }
"while"                 { return WHILE; }

{L}({L}|{D})*           { return IDENTIFICATEUR; }

"/"                   	{ return DIV; }
"+"                    	{ return PLUS; }
"-"                    	{ return MOINS; }
"*"                    	{ return MUL; }
">"                    	{ return GT; }
"<"                    	{ return LT; }
"&"                    	{ return BAND; }
"|"                    	{ return BOR; }
">>"                    { return RSHIFT; }
"<<"                    { return LSHIFT; }
"&&"                    { return LAND; }
"||"                    { return LOR; }
"<="                    { return LEQ; }
">="                    { return GEQ; }
"=="                    { return EQ; }
"!="                    { return NEQ; }
"!"                    	{ return NOT; }

[ \t\v\n\f]             { /* A completer */ }
.                       { return yytext[0]; }
%%

