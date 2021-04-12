D                       [0-9]
L                       [a-zA-Z_]
H                       [a-fA-F0-9]

%{
#include "types.h"
#include <stdio.h>
#include "y.tab.h"

%}

%x C_COMMENT

%%

"/*"            { BEGIN(C_COMMENT); }
<C_COMMENT>"*/" { BEGIN(INITIAL); }
<C_COMMENT>\n   { }
<C_COMMENT>.    { }

"break"                {ECHO;printf("\n");
			yylval.boolean = false;
			return BREAK; }
"else"                 {ECHO;printf("\n");
			yylval.boolean = true;
			return ELSE; }
"extern"              	{ECHO;printf("\n");
			yylval.boolean = true;
			return EXTERN; }
"return"               {ECHO;printf("\n");
			yylval.boolean = true;
			return RETURN; }
			
"case"                 {ECHO;printf("\n");
			yylval.selection_nom = strdup(yytext); 
			return CASE; }
"default"              {ECHO;printf("\n");
			yylval.selection_nom = strdup(yytext);
			return DEFAULT; }
"if"                   {ECHO;printf("\n");
			yylval.selection_nom = strdup(yytext);
			return IF; }
"switch"               {ECHO;printf("\n");
			yylval.selection_nom = strdup(yytext);
			return SWITCH; }
			
"for"                  {ECHO;printf("\n");
			yylval.boolean = true;
			return FOR; }
"while"                {ECHO;printf("\n");
			yylval.boolean = false;
			return WHILE; }

"int"                 	{ECHO;printf("\n");
			yylval.type=strdup(yytext); 
			return INT; }
"void"                	{ECHO;printf("\n");
			yylval.type=strdup(yytext); 
			return VOID; }

{L}({L}|{D})*         	{ECHO;printf("\n");
			yylval.identificateur = strdup(yytext);
			return IDENTIFICATEUR; }

{D}+                  	{ECHO;printf("\n");
			yylval.constante = atoi(yytext);
			return CONSTANTE; }

"/"                   	{ECHO;printf("\n");
			yylval.binary_op = strdup(yytext);
            		return DIV; }
"+"                    {ECHO;printf("\n");
			yylval.binary_op = strdup(yytext);
             		return PLUS; }
"-"                    {ECHO;printf("\n");
			yylval.binary_op = strdup(yytext);
             		return MOINS; }
"*"                    {ECHO;printf("\n");
			yylval.binary_op = strdup(yytext);
             		return MUL; }
">"                    {ECHO;printf("\n");
			yylval.binary_op = strdup(yytext);
             		return GT; }
"<"                    {ECHO;printf("\n");
			yylval.binary_op = strdup(yytext);
             		return LT; }
"&"                    {ECHO;printf("\n");
			yylval.binary_op = strdup(yytext);
             		return BAND; }
"|"                    {ECHO;printf("\n");
			yylval.binary_op = strdup(yytext);
             		return BOR; }
">>"                   {ECHO;printf("\n");
			yylval.binary_op = strdup(yytext);
             		return RSHIFT; }
"<<"                   {ECHO;printf("\n");
			yylval.binary_op = strdup(yytext);
             		return LSHIFT; }
             		
"&&"                   {ECHO;printf("\n");
			yylval.binary_rel = strdup(yytext);
             		return LAND; }
"||"                   {ECHO;printf("\n");
			yylval.binary_rel = strdup(yytext);
             		return LOR; }
"!"                    {ECHO;printf("\n");
			yylval.binary_rel = strdup(yytext);
			return NOT; }
             		
"<="                   {ECHO;printf("\n");
			yylval.binary_comp = strdup(yytext);
             		return LEQ; }
">="                   {ECHO;printf("\n");
			yylval.binary_comp = strdup(yytext);
             		return GEQ; }
"=="                   {ECHO;printf("\n");
			yylval.binary_comp = strdup(yytext);
             		return EQ; }
"!="                   {ECHO;printf("\n");
			yylval.binary_comp = strdup(yytext);
             		return NEQ; }

[ \t\v\n\f]            {}
.                      {ECHO;printf("\n");
			return yytext[0]; }

%%

