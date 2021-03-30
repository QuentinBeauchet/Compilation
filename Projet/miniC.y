%{
#include "types.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_param(param_t t);
void print_fonction(fonction_t f);
listof_param_t append_listof_param(listof_param_t tab,param_t t);
listof_param_t concat_listof_param(listof_param_t tab,listof_param_t t);

param_t tab[100];
int tab_index=0;
int read=1;	

%}
%token IDENTIFICATEUR CONSTANTE FOR INT VOID WHILE IF ELSE SWITCH CASE DEFAULT
%token BREAK RETURN PLUS MOINS MUL DIV LSHIFT RSHIFT BAND BOR LAND LOR LT GT 
%token GEQ LEQ EQ NEQ NOT EXTERN
%token END_OF_FILE
%left PLUS MOINS
%left MUL DIV
%left LSHIFT RSHIFT
%left BOR BAND
%left LAND LOR
%nonassoc THEN
%nonassoc ELSE
%left OP
%left REL
%start programme
%error-verbose

//%type liste_declarations liste_fonctions fonction type liste_parms

%type<val> GEQ LEQ EQ NEQ NOT PLUS MOINS MUL DIV LSHIFT RSHIFT BAND BOR LAND LOR LT GT 
%type<type> type INT VOID
%type<nom> IDENTIFICATEUR CONSTANTE
%type<listof_var> liste_parms parm
%type<listof_declarateur> liste_declarateurs declarateur
%type<listof_declaration> liste_declarations declaration

%union{
	char* type;
	int val;
	char* nom;
	listof_param_t listof_var;
	param_t var;
	declarateur_t* declarateur_p;
	declarateur_t declarateur;
	listof_declarateur_t listof_declarateur;
	declaration_t declaration;
	listof_declaration_t listof_declaration;
}

%%
programme	:	
		liste_declarations liste_fonctions 
;
liste_declarations	:	
		liste_declarations ',' declaration 	{yylval.listof_declaration=concat_listof_declaration_t($3,$1);}
	|	declaration				{yylval.listof_declaration=$1;}
;
liste_fonctions	:	
		liste_fonctions fonction 
	|       fonction 
;
declaration	:	
		type liste_declarateurs ';' 		{yylval.declaration = $1;}
;
liste_declarateurs	:	
		liste_declarateurs ',' declarateur 	{yylval.listof_declarateur=concat_listof_declarateur_t($3,$1);}
	|	declarateur 				{yylval.listof_declarateur=$1;}
;
declarateur	:	
		IDENTIFICATEUR {declarateur_t d = { .identificateur = $1};
				yylval.declarateur = d;}
	|	declarateur '[' CONSTANTE ']' 	{declarateur_t d = { .d = yylval.declarateur_p , .constante = yylval.nom};
						yylval.declarateur = d;}
	
;
fonction	:	
		type IDENTIFICATEUR '(' liste_parms ')' '{' liste_declarations liste_instructions '}' 
	|	EXTERN type IDENTIFICATEUR '(' liste_parms ')' ';'  	{fonction_t f = { .args = $5, .nom = $3, .type = $2};
									print_fonction(f);} 	
	|	END_OF_FILE 	{read=0;
				return;}
;
type	:	
		VOID 
	|	INT	
;
liste_parms	:	
		parm 			{//print_listof_param(yylval.listof_var);
					yylval.listof_var=$1;}
	|	parm ',' liste_parms 	{yylval.listof_var=concat_listof_param($3,$1);}
;
parm	:	
		INT IDENTIFICATEUR 	{param_t t = { .type = $1, .nom = $2,};
					//print_param(t);
					listof_param_t l = { .size = 0};
					yylval.listof_var=append_listof_param(l,t);}
	|				{listof_param_t l = { .size = 0};
					yylval.listof_var=l;}
;
liste_instructions :	
		liste_instructions instruction 
	|	
;
instruction	:	
		iteration 
	|	selection 
	|	saut 
	|	affectation ';' 
	|	bloc 
	|	appel 
;
iteration	:	
		FOR '(' affectation ';' condition ';' affectation ')' instruction 
	|	WHILE '(' condition ')' instruction 
;
selection	:	
		IF '(' condition ')' instruction %prec THEN 
	|	IF '(' condition ')' instruction ELSE instruction 
	|	SWITCH '(' expression ')' instruction 
	|	CASE CONSTANTE ':' instruction 
	|	DEFAULT ':' instruction 
;
saut	:	
		BREAK ';' 
	|	RETURN ';' 
	|	RETURN expression ';' 
;
affectation	:	
		variable '=' expression 
;
bloc	:	
		'{' liste_declarations liste_instructions '}' 
;
appel	:	
		IDENTIFICATEUR '(' liste_expressions ')' ';' 
;
variable	:	
		IDENTIFICATEUR 
	|	variable '[' expression ']' 
;
expression	:	
		'(' expression ')' 
	|	expression binary_op expression %prec OP 
	|	MOINS expression 
	|	CONSTANTE 
	|	variable 
	|	IDENTIFICATEUR '(' liste_expressions ')' 
;
liste_expressions	:	
		liste_expressions ',' expression 
	|
;
condition	:	
		NOT '(' condition ')' 
	|	condition binary_rel condition %prec REL 
	|	'(' condition ')' 
	|	expression binary_comp expression 
;
binary_op	:	
		PLUS {printf("binary_op: PLUS: %s",$1);}
	|       MOINS {printf("binary_op: MOINS: %s",$1);}
	|	MUL {printf("binary_op: MUL: %s",$1);}
	|	DIV {printf("binary_op: DIV: %s",$1);}
	|       LSHIFT {printf("binary_op: LSHIFT: %s",$1);}
	|       RSHIFT {printf("binary_op: RSHIFT: %s",$1);}
	|	BAND {printf("binary_op: BAND: %s",$1);}
	|	BOR {printf("binary_op: BOR: %s",$1);}
;
binary_rel	:	
		LAND {printf("binary_rel: LAND: %s",$1);}
	|	LOR {printf("binary_rel: LOR: %s",$1);}
;
binary_comp	:	
		LT {printf("binary_comp: LT: %d",$1);}
	|	GT {printf("binary_comp: GT: %d",$1);}
	|	GEQ {printf("binary_comp: GEQ: %d",$1);}
	|	LEQ {printf("binary_comp: LEQ: %d",$1);}
	|	EQ {printf("binary_comp: EQ: %d",$1);}
	|	NEQ {printf("binary_comp: NEQ: %d",$1);}
;

%%
 
void yyerror (char const *s){
  	fprintf (stderr, "ERREUR: %s\n", s);
}

int main(){
	int nbrErrorMax=0;
	while(read){
		yyparse();
		/*nbrErrorMax= nbrErrorMax + yyparse();
		if(nbrErrorMax>20){
			{printf("TROP D'ERREURS\n");}
			break;
		}*/
	}
	/*if(tab_index>0){
		for (int i = 0; i < tab_index; ++i){
    			print_param(tab[i]);
  		}
	}*/
}
