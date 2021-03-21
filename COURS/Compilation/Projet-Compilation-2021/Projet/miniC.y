%{
#include <stdio.h>
#include <stdlib.h>
%}
%token IDENTIFICATEUR CONSTANTE VOID INT FOR WHILE IF ELSE SWITCH CASE DEFAULT
%token BREAK RETURN PLUS MOINS MUL DIV LSHIFT RSHIFT BAND BOR LAND LOR LT GT 
%token GEQ LEQ EQ NEQ NOT EXTERN
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
%%
programme	:	
		liste_declarations liste_fonctions {printf("programme: liste_declarations: %s liste_fonctions: %s",$1,$2);}
;
liste_declarations	:	
		liste_declarations declaration {printf("liste_declarations: liste_declarations: %s declaration: %s",$1,$2);}
	|	
;
liste_fonctions	:	
		liste_fonctions fonction {printf("liste_fonctions: liste_fonctions: %s fonction: %s",$1,$2);}
	|       fonction {printf("liste_fonctions: fonction: %s",$1);};
;
declaration	:	
		type liste_declarateurs ';' {printf("declaration: type: %s liste_declarateurs: %s ;",$1,$2);}
;
liste_declarateurs	:	
		liste_declarateurs ',' declarateur {printf("liste_declarateurs: liste_declarateurs: %s , declarateur: %s ;",$1,$3);}
	|	declarateur {printf("liste_declarateurs: declarateur: %s",$1);}
;
declarateur	:	
		IDENTIFICATEUR {printf("declarateur: IDENTIFICATEUR: %s",$1);}
	|	declarateur '[' CONSTANTE ']' {printf("declarateur: [ CONSTANTE ]: %s",$1);}
;
fonction	:	
		type IDENTIFICATEUR '(' liste_parms ')' '{' liste_declarations liste_instructions '}' {printf("fonction: type: %s  IDENTIFICATEUR: %s ( liste_parms: %s ) { liste_declarations: %s liste_instructions: %s }",$1,$2,$4,$7,$8);}
	|	EXTERN type IDENTIFICATEUR '(' liste_parms ')' ';'  {printf("fonction: EXTERN: %s type: %s IDENTIFICATEUR: %s ( liste_parms: %s ) ;",$1,$2,$3,$5);}
;
type	:	
		VOID {printf("type: VOID: %s",$1);}
	|	INT {printf("type: INT: %s",$1);}
;
liste_parms	:	
		liste_parms ',' parm {printf("list_parms: liste_parms: %s , parm: %s",$1,$3);}
	|	{printf("list_parms:");}
;
parm	:	
		INT IDENTIFICATEUR {printf("parm: INT: %s IDENTIFICATEUR: %s",$1,$2);}
;
liste_instructions :	
		liste_instructions instruction {printf("liste_instructions: liste_instructions: %s instruction: %s",$1,$2);}
	|	{printf("liste_instructions:");}
;
instruction	:	
		iteration {printf("instruction: iteration: %s",$1);}
	|	selection {printf("instruction: selection: %s",$1);}
	|	saut {printf("instruction: saut: %s",$1);}
	|	affectation ';' {printf("instruction: affactation: %s ;",$1);}
	|	bloc {printf("instruction: bloc: %s",$1);}
	|	appel {printf("instruction: appel: %s",$1);}
;
iteration	:	
		FOR '(' affectation ';' condition ';' affectation ')' instruction {printf("iteration: FOR: %s ( affectation: %s ; condition: %s ; affectation:%s ) instruction: %s",$1,$3,$5,$7,$9);}
	|	WHILE '(' condition ')' instruction {printf("iteration: WHILE: %s ( condition: %s ) instruction: %s",$1,$3,$5);}
;
selection	:	
		IF '(' condition ')' instruction %prec THEN {printf("selection: IF: %s ( condition: %s ) instruction: %s ",$1,$3,$5);}
	|	IF '(' condition ')' instruction ELSE instruction {printf("selection: IF: %s ( condition: %s ) instruction: %s ELSE: %s instruction: %s",$1,$3,$5,$6,$7);}
	|	SWITCH '(' expression ')' instruction {printf("selection: SWITCH: %s ( expression: %s ) instruction: %s",$1,$3,$5);}
	|	CASE CONSTANTE ':' instruction {printf("selection: CASE: %s CONSTANTE: %s : instruction: %s",$1,$2,$4);}
	|	DEFAULT ':' instruction {printf("selection: DEFAULT: %s : instruction: %s",$1,$3);}
;
saut	:	
		BREAK ';' {printf("saut: BREAK: %s ;",$1);}
	|	RETURN ';' {printf("saut: RETURN: %s ;",$1);}
	|	RETURN expression ';' {printf("saut: RETURN: %s expression: %s ;",$1,$2);}
;
affectation	:	
		variable '=' expression {printf("affectation: variable: %s = expression: %s",$1,$3);}
;
bloc	:	
		'{' liste_declarations liste_instructions '}' {printf("bloc: { liste_declarations: %s liste_instructions: %s }",$2,$3);}
;
appel	:	
		IDENTIFICATEUR '(' liste_expressions ')' ';' {printf("appel: IDENTIFICATEUR: %s ( liste_instructions: %s ) ;",$1,$3);}
;
variable	:	
		IDENTIFICATEUR {printf("variable: IDENTIFICATEUR: %s ",$1);}
	|	variable '[' expression ']' {printf("variable: variable: %s [ expression: %s ]",$1,$3);}
;
expression	:	
		'(' expression ')' {printf("expression: ( expression: %s )",$2);}
	|	expression binary_op expression %prec OP {printf("expression: expression: %s binary_op: %s expression: %s",$1,$2,$3);}
	|	MOINS expression {printf("expression: MOINS: %s expression: %s",$1,$2);}
	|	CONSTANTE {printf("expression: CONSTANTE: %s"),$1;}
	|	variable {printf("expression: variable: %s"),$1;}
	|	IDENTIFICATEUR '(' liste_expressions ')' {printf("expression: IDENTIFICATEUR: %s ( liste_expressions: %s )",$1,$3);}
;
liste_expressions	:	
		liste_expressions ',' expression {printf("liste_expressions: liste_expressions: %s , expression: %s",$1,$3);}
	|
;
condition	:	
		NOT '(' condition ')' {printf("condition: NOT: %s ( condition: %s )",$1,$3);}
	|	condition binary_rel condition %prec REL {printf("condition: condition: %s binary_rel: %s condition: %s",$1,$2,$3);}
	|	'(' condition ')' {printf("condition: ( condition: %s )",$2);}
	|	expression binary_comp expression {printf("condition: expression: %s binary_op: %s expression: %s",$1,$2,$3);}
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
  fprintf (stderr, "ERREUR:%s\n", s);
}

int main(){
	while(1) 
		yyparse();
}
