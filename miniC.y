%{
#include "types.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex();
void yyerror (const char *s);

programme_t global_programme;

%}
%token<type> INT VOID
%token<identificateur> IDENTIFICATEUR
%token<constante> CONSTANTE
%token<binary_op> PLUS MOINS MUL DIV LSHIFT RSHIFT BAND BOR LT GT
%token<binary_comp> GEQ LEQ EQ NEQ
%token<binary_rel> NOT LAND LOR
%token<boolean> EXTERN RETURN BREAK ELSE FOR WHILE
%token<selection_nom> IF SWITCH CASE DEFAULT
%left PLUS MOINS
%left MUL DIV
%left LSHIFT RSHIFT
%left BOR BAND
%left LAND LOR
%nonassoc THEN
%nonassoc ELSE
%nonassoc moins
%left REL
%start programme
%define parse.error verbose

%type<type> type
%type<parm> parm
%type<liste_parms> liste_parms
%type<declarateur> declarateur
%type<liste_declarateurs> liste_declarateurs
%type<declaration> declaration
%type<liste_declarations> liste_declarations
%type<binary_rel> binary_rel
%type<binary_comp> binary_comp
%type<variable> variable
%type<expression> expression
%type<liste_expressions> liste_expressions
%type<condition> condition
%type<appel> appel
%type<affectation> affectation
%type<saut> saut
%type<bloc> bloc bloc_in_switch
%type<selection> selection_out_switch selection_in_switch
%type<instruction> instruction instruction_in_switch
%type<liste_instructions> liste_instructions liste_instructions_in_case
%type<iteration> iteration
%type<fonction> fonction
%type<liste_fonctions> liste_fonctions
%type<programme> programme

%union{
	char* type;
	char* identificateur;
	int constante;
	bool boolean;
	char* binary_op;
	char* binary_rel;
	char* binary_comp;
	char* selection_nom;
	
	parm_t parm;
	liste_parms_t liste_parms;
	declarateur_t declarateur;
	liste_declarateurs_t liste_declarateurs;
	declaration_t declaration;
	liste_declarations_t liste_declarations;
	variable_t variable;
	liste_expressions_t liste_expressions;
	expression_t expression;
	condition_t condition;
	appel_t appel;
	affectation_t affectation;
	saut_t saut;
	bloc_t bloc;
	selection_t selection;
	instruction_t instruction;
	liste_instructions_t liste_instructions;
	iteration_t iteration;
	fonction_t fonction;
	liste_fonctions_t liste_fonctions;
	programme_t programme;
}

%%
programme	:	
		liste_declarations liste_fonctions 		{$$ = (programme_t){.liste_declarations = copyOf_liste_declarations(&$1), .liste_fonctions = $2};
								global_programme=$$;}
;
liste_declarations	:
		liste_declarations declaration 		{append_liste_declarations(&$1,$2);
								$$=$1;}
	|		 					{$$ = (liste_declarations_t){ .size = 0};}
;
liste_fonctions	:	
		liste_fonctions fonction 			{append_liste_fonctions(&$1,$2);
								$$=$1;}
	|       fonction 					{liste_fonctions_t tab = {.size = 0};
								append_liste_fonctions(&tab,$1);
								$$=tab;}
;
declaration	:	
		type liste_declarateurs ';' 			{$$ = (declaration_t){ .type = $1, .liste_declarateurs = $2};}
;
liste_declarateurs	:	
		liste_declarateurs ',' declarateur 		{append_liste_declarateurs(&$1,$3);
								$$ = $1;}
	|	declarateur 					{liste_declarateurs_t tab = {.size = 0};
								append_liste_declarateurs(&tab,$1);
								$$ = tab;}
;
declarateur	:	
		IDENTIFICATEUR 				{$$ = (declarateur_t){ .identificateur = $1, .liste_constantes = (liste_constantes_t){.size = 0}};}
	|	declarateur '[' CONSTANTE ']' 		{append_liste_constantes(&$1.liste_constantes,$3);
								$$ = $1;}
	
;
fonction	:	
		    type IDENTIFICATEUR '(' liste_parms ')' bloc         				    {$$ = (fonction_t){ .liste_parms = $4,
                                       								 .bloc = copyOf_bloc(&$6), .identificateur = $2, .type = $1};}
	|	EXTERN type IDENTIFICATEUR '(' liste_parms ')' ';'  						{$$ = (fonction_t){ .Extern = $1, .liste_parms = $5,
														.identificateur = $3, .type = $2};}
;
type	:	
		VOID 							{$$ = $1;}
	|	INT							{$$ = $1;}
;
liste_parms	:	
		liste_parms ',' parm 					{append_liste_parms(&$1,$3);
									$$ = $1;}
	|	parm 							{liste_parms_t tab = {.size = 0};
									append_liste_parms(&tab,$1);
									$$ = tab;}
	|								{$$ = (liste_parms_t){.size = 0};}
;
parm	:	
		INT IDENTIFICATEUR 					{$$ = (parm_t){ .type = $1, .identificateur = $2};}
;
liste_instructions :	
		liste_instructions instruction 			{append_liste_instructions(&$1,$2);
									$$ = $1;}
	|								{$$ = (liste_instructions_t){.size = 0};}
;
liste_instructions_in_case :	
		liste_instructions_in_case instruction_in_switch 	{append_liste_instructions(&$1,$2);
									$$ = $1;}
	|								{$$ = (liste_instructions_t){.size = 0};}
;
instruction	:
		selection_in_switch					{$$ = (instruction_t){.selection = copyOf_selection(&$1)};}
	|	instruction_in_switch					{$$ = $1;}
;
instruction_in_switch	:
		iteration 						{$$ = (instruction_t){.iteration = copyOf_iteration(&$1)};}
	|	saut 							{$$ = (instruction_t){.saut = copyOf_saut(&$1)};}
	|	affectation ';' 					{$$ = (instruction_t){.affectation = copyOf_affectation(&$1)};}
	|	bloc 							{$$ = (instruction_t){.bloc = copyOf_bloc(&$1)};}
	|	appel 							{$$ = (instruction_t){.appel = copyOf_appel(&$1)};}
	|	selection_out_switch					{$$ = (instruction_t){.selection = copyOf_selection(&$1)};}
;
iteration	:	
		FOR '(' affectation ';' condition ';' affectation ')' instruction	{liste_affectations_t tab = {.size = 0};
											append_liste_affectations(&tab,$3);
											append_liste_affectations(&tab,$7);
											$$ = (iteration_t){.For = $1, .condition = copyOf_condition(&$5), .instruction =
											copyOf_instruction(&$9), .liste_affectations = copyOf_liste_affectations(&tab)};}
	|	WHILE '(' condition ')' instruction 					{$$ = (iteration_t){.For = $1, .condition = copyOf_condition(&$3), .instruction = copyOf_instruction(&$5)};}
;
selection_out_switch	:	
		IF '(' condition ')' instruction %prec THEN		{liste_instructions_t tab = {.size = 0};
									append_liste_instructions(&tab,$5);
									$$ = (selection_t){.type_selection = 0, .selection_nom = $1, .condition = $3, .liste_instructions =
									copyOf_liste_instructions(&tab)};}
	|	IF '(' condition ')' instruction ELSE instruction	{liste_instructions_t tab = {.size = 0};
									append_liste_instructions(&tab,$5);
									append_liste_instructions(&tab,$7);
									$$ = (selection_t){.type_selection = 1, .selection_nom = $1, .condition = $3, .Else = $6, .liste_instructions =
									copyOf_liste_instructions(&tab)};}
	|	SWITCH '(' expression ')' instruction 		{liste_instructions_t tab = {.size = 0};
									append_liste_instructions(&tab,$5);
									$$ = (selection_t){.type_selection = 2, .selection_nom = $1, .expression = $3, .liste_instructions =
									copyOf_liste_instructions(&tab)};}
;
selection_in_switch	:	
		CASE CONSTANTE ':' bloc_in_switch 			{$$ = make_selection(3,$1,$4,$2);}
	|	DEFAULT ':' bloc_in_switch 				{$$ = make_selection(4,$1,$3,0);}
;
saut	:	
		BREAK ';' 						{$$ = (saut_t){.Return = $1};}
	|	RETURN ';' 						{$$ = (saut_t){.Return = $1};}
	|	RETURN expression ';' 					{$$ = (saut_t){.Return = $1, .expression = copyOf_expression(&$2)};}
;
affectation	:	
		variable '=' expression 				{$$ = (affectation_t){.variable = $1, .expression = $3};}
;
bloc	:	
		'{' liste_declarations liste_instructions '}' 	{$$ = (bloc_t){.liste_declarations = $2 , .liste_instructions = $3};}
;
bloc_in_switch	:
		liste_declarations liste_instructions_in_case		{$$ = (bloc_t){.liste_declarations = $1 , .liste_instructions = $2};}
;
appel	:	
		IDENTIFICATEUR '(' liste_expressions ')' ';'		{$$ = (appel_t){.identificateur = $1 , .liste_expressions = *copyOf_liste_expressions(&$3)};}
;
variable	:	
		IDENTIFICATEUR 					{$$ = (variable_t){.identificateur = $1, .liste_expressions =
									copyOf_liste_expressions(&(liste_expressions_t){.size = 0})};}
	|	variable '[' expression ']' 				{append_liste_expressions($1.liste_expressions,$3);
									$$ = $1;}
						
;
expression	:	

		'(' expression ')' 					{liste_expressions_t tab = {.size = 0};
									append_liste_expressions(&tab,$2);
									$2.liste_expressions = copyOf_liste_expressions(&tab);
									$2.type_expression = 0;
									$$ = $2;}
 	|	expression PLUS expression				{$$ = make_expr($1,$2,$3);}
	|	expression MOINS expression				{$$ = make_expr($1,$2,$3);}
	|	expression DIV expression				{$$ = make_expr($1,$2,$3);}
	|	expression MUL expression				{$$ = make_expr($1,$2,$3);}
	|	expression RSHIFT expression				{$$ = make_expr($1,$2,$3);}
	|	expression LSHIFT expression				{$$ = make_expr($1,$2,$3);}
	|	expression BAND expression				{$$ = make_expr($1,$2,$3);}
	|	expression BOR expression				{$$ = make_expr($1,$2,$3);}
	|	MOINS expression %prec moins				{liste_expressions_t tab = {.size = 0};
									append_liste_expressions(&tab,$2);
									$$ = (expression_t){.binary_op = $1, .liste_expressions = copyOf_liste_expressions(&tab), .type_expression = 2};}
	|	CONSTANTE 						{$$ = (expression_t){.constante = copyOf_constante(&$1), .type_expression = 3};}
	|	variable 						{$$ = (expression_t){.variable = copyOf_variable(&$1), .type_expression = 4};}
	|	IDENTIFICATEUR '(' liste_expressions ')' 		{$$ = (expression_t){.identificateur = $1 , .liste_expressions = copyOf_liste_expressions(&$3), .type_expression = 5};}
;
liste_expressions	:	
		liste_expressions ',' expression 			{append_liste_expressions(&$1,$3);
									$$ = $1;}
	|	expression						{liste_expressions_t tab= {.size = 0};
									append_liste_expressions(&tab,$1);
									$$ = tab;}
	|								{$$ = (liste_expressions_t){.size = 0};}
;
condition	:	
		NOT '(' condition ')' 					{liste_conditions_t tab = {.size = 0};
									append_liste_conditions(&tab,$3);
									$$ = (condition_t){.type_condition = 0, .binary_rel = $1, .liste_conditions = &tab};}
	|	condition binary_rel condition %prec REL 		{liste_conditions_t tab = {.size = 0};
									append_liste_conditions(&tab,$1);
									append_liste_conditions(&tab,$3);
									$$ = (condition_t){.type_condition = 1, .binary_rel = $2, .liste_conditions = &tab};}
	|	'(' condition ')' 					{liste_conditions_t tab = {.size = 0};
									append_liste_conditions(&tab,$2);
									$$ = (condition_t){.type_condition = 2, .liste_conditions = &tab};}
	|	expression binary_comp expression 			{liste_expressions_t tab = {.size = 0};
									append_liste_expressions(&tab,$1);
									append_liste_expressions(&tab,$3);
									$$ = (condition_t){.type_condition = 3, .binary_comp = $2, .liste_expressions =
									copyOf_liste_expressions(&tab)};}
;

binary_rel    :    
        LAND         							{$$ = $1;}
    |   LOR         							{$$ = $1;}
;
binary_comp    :   
        GT								{$$ = $1;}
    |   LT								{$$ = $1;}
    |   GEQ         							{$$ = $1;}
    |   LEQ         							{$$ = $1;}
    |   EQ        							{$$ = $1;}
    |   NEQ         							{$$ = $1;}
;

%%
 
void yyerror (const char *s){
  	fprintf (stderr, "ERREUR: %s\n", s);
}

int main(int argc, char *argv[]){
	if(global_debug){
		printf("-----------------------------------------------------------------LEX-----------------------------------------------------------------\n");
	}
	yyparse();
	if(global_debug){
		printf("-------------------------------------------------------VERIFICATION DES STRUCTS-------------------------------------------------------\n");
		print_programme(global_programme);
	}
	dot_generation(global_programme,argv[1]);
}

