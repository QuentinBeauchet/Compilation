D                       [0-9]
L                       [a-zA-Z_]

%{
#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"

void debug();

%}

%x C_COMMENT

%%

"/*"            { BEGIN(C_COMMENT); }
<C_COMMENT>"*/" { BEGIN(INITIAL); }
<C_COMMENT>\n   { }
<C_COMMENT>.    { }

"break"                {debug();
			yylval.boolean = false;
			return BREAK; }
"else"                 {debug();
			yylval.boolean = true;
			return ELSE; }
"extern"              	{debug();
			yylval.boolean = true;
			return EXTERN; }
"return"               {debug();
			yylval.boolean = true;
			return RETURN; }
			
"case"                 {debug();
			yylval.selection_nom = strdup(yytext); 
			return CASE; }
"default"              {debug();
			yylval.selection_nom = strdup(yytext);
			return DEFAULT; }
"if"                   {debug();
			yylval.selection_nom = strdup(yytext);
			return IF; }
"switch"               {debug();
			yylval.selection_nom = strdup(yytext);
			return SWITCH; }
			
"for"                  {debug();
			yylval.boolean = true;
			return FOR; }
"while"                {debug();
			yylval.boolean = false;
			return WHILE; }

"int"                	{debug();
			yylval.type=strdup(yytext); 
			return INT; }
"void"                	{debug();
			yylval.type=strdup(yytext); 
			return VOID; }

{L}({L}|{D})*         	{debug();
			yylval.identificateur = strdup(yytext);
			return IDENTIFICATEUR; }

{D}+                  	{debug();
			yylval.constante = atoi(yytext);
			return CONSTANTE; }

"/"                   	{debug();
			yylval.binary_op = strdup(yytext);
            		return DIV; }
"+"                    {debug();
			yylval.binary_op = strdup(yytext);
             		return PLUS; }
"-"                    {debug();
			yylval.binary_op = strdup(yytext);
             		return MOINS; }
"*"                    {debug();
			yylval.binary_op = strdup(yytext);
             		return MUL; }
">>"                   {debug();
			yylval.binary_op = strdup(yytext);
             		return RSHIFT; }
"<<"                  	{debug();
			yylval.binary_op = strdup(yytext);
             		return LSHIFT; }   
"&"                    {debug();
			yylval.binary_op = strdup(yytext);
             		return BAND; }
"|"                    {debug();
			yylval.binary_op = strdup(yytext);
             		return BOR; }          
             		
"&&"                   {debug();
			yylval.binary_rel = strdup(yytext);
             		return LAND; }
"||"                   {debug();
			yylval.binary_rel = strdup(yytext);
             		return LOR; }
"!"                    {debug();
			yylval.binary_rel = strdup(yytext);
			return NOT; }
             		
">"                    {debug();
			yylval.binary_comp = strdup(yytext);
             		return GT; }
"<"                    {debug();
			yylval.binary_comp = strdup(yytext);
             		return LT; }		
"<="                   {debug();
			yylval.binary_comp = strdup(yytext);
             		return LEQ; }
">="                  	{debug();
			yylval.binary_comp = strdup(yytext);
             		return GEQ; }
"=="                   {debug();
			yylval.binary_comp = strdup(yytext);
             		return EQ; }
"!="                  	{debug();
			yylval.binary_comp = strdup(yytext);
             		return NEQ; }

[ \t\v\n\f]            {}
.                      {debug();
			return yytext[0]; }

%%

void debug(){
	if(global_debug){
	ECHO;
	printf("\n");
	}
}


