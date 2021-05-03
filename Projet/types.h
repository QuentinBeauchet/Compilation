#include <stdbool.h>

static bool global_debug = true;

/* Structures de données */

typedef struct parm_t {
	char *identificateur;
	char *type;
}parm_t;

typedef struct liste_parms_t {
	parm_t liste[20];
	int size;
}liste_parms_t;

typedef struct liste_constantes_t {
	int liste[20];
	int size;
}liste_constantes_t;

typedef struct declarateur_t {
	char* identificateur;
	liste_constantes_t liste_constantes;
}declarateur_t;

typedef struct liste_declarateurs_t {
	declarateur_t liste[20];
	int size;
}liste_declarateurs_t;

typedef struct declaration_t {
	liste_declarateurs_t liste_declarateurs;
	char* type;
}declaration_t;

typedef struct liste_declarations_t {
	declaration_t liste[20];
	int size;
}liste_declarations_t;

typedef struct variable_t {
	char* identificateur;
	struct liste_expressions_t* liste_expressions;
}variable_t;

typedef struct expression_t {
	int type_expression;
	char* identificateur;
	struct liste_expressions_t* liste_expressions;
	variable_t* variable;
	int* constante;
	char* binary_op;
}expression_t;

typedef struct liste_expressions_t {
	expression_t liste[20];
	int size;
}liste_expressions_t;

typedef struct affectation_t {
	variable_t variable;
	expression_t expression;
}affectation_t;

typedef struct liste_affectations_t {
	affectation_t liste[20];
	int size;
}liste_affectations_t;

typedef struct condition_t {
	int type_condition;
	char* binary_rel;
	char* binary_comp;
	struct liste_conditions_t* liste_conditions;
	liste_expressions_t* liste_expressions;
}condition_t;

typedef struct liste_conditions_t {
	condition_t liste[20];
	int size;
}liste_conditions_t;

typedef struct appel_t {
	char* identificateur;
	liste_expressions_t liste_expressions;
}appel_t;

typedef struct saut_t {
	bool Return;
	expression_t* expression;
}saut_t;

typedef struct selection_t {
	int type_selection;
	char* selection_nom; 
	int constante; 
	bool Else;
	struct liste_instructions_t* liste_instructions;
	condition_t condition;
	expression_t expression;
}selection_t;

typedef struct instruction_t {
	struct iteration_t* iteration;
	selection_t* selection;
	saut_t* saut;
	affectation_t* affectation;
	struct bloc_t* bloc;
	appel_t* appel;
}instruction_t;

typedef struct liste_instructions_t {
	instruction_t* liste[100];
	int size;
}liste_instructions_t;

typedef struct bloc_t {
	liste_instructions_t liste_instructions;
	liste_declarations_t liste_declarations;
}bloc_t;

typedef struct iteration_t {
	bool For;
	liste_affectations_t* liste_affectations;
	condition_t* condition;
	instruction_t* instruction;
}iteration_t;

typedef struct fonction_t {
	liste_parms_t liste_parms;
	liste_declarations_t* liste_declarations;
	liste_instructions_t* liste_instructions;
	bool Extern;
	char *identificateur;
	char *type;
}fonction_t;

typedef struct liste_fonctions_t {
	fonction_t liste[20];
	int size;
}liste_fonctions_t;

typedef struct programme_t {
	liste_declarations_t* liste_declarations;
	liste_fonctions_t liste_fonctions;
}programme_t;

/* Environement */

typedef struct Value {
	union Exp {
		fonction_t fonction;
		variable_t variable;
	}exp;
	int type;
}Value;

typedef struct Env {
	Value liste_value[50];
	char* liste_symbol[50];
	int size;
}Env;

/* Declarations fonctions Print */

void print_programme(programme_t p);
void print_liste_declarations(int n,liste_declarations_t* tab);
void print_declaration(int n,declaration_t* d);
void print_liste_declarateurs(int n,liste_declarateurs_t tab);
void print_declarateur(int n,declarateur_t d);
void print_liste_constantes(int n,liste_constantes_t tab);
void print_liste_fonctions(int n,liste_fonctions_t tab);
void print_fonction(int n,fonction_t f);
void print_liste_parms(int n,liste_parms_t* tab);
void print_parm(int n,parm_t p);
void print_liste_instructions(int n,liste_instructions_t* tab);
void print_instruction(int n,instruction_t* i);
void print_iteration(int n,iteration_t* i);
void print_selection(int n,selection_t* s);
void print_saut(int n,saut_t* s);
void print_affectation(int n,affectation_t* a);
void print_bloc(int n,bloc_t* b);
void print_appel(int n,appel_t* a);
void print_variable(int n,variable_t* v);
void print_liste_expressions(int n,liste_expressions_t* tab);
void print_expression(int n,expression_t* e);
void print_condition(int n,condition_t* c);

/* Declarations fonctions Dot */
void dot_generation(programme_t programme,char* file_name);
void dot_programme(programme_t* programme);
void dot_liste_fonctions(liste_fonctions_t liste_fonctions);
void dot_fonction(fonction_t fonction);
int dot_instruction(instruction_t instruction);
int dot_bloc(bloc_t b);
int dot_appel(appel_t appel);
int dot_expression (expression_t e);
int dot_selection(selection_t s);
int dot_condition(condition_t cond);
int dot_saut (saut_t saut);
int dot_iteration (iteration_t i);
int dot_affectation (affectation_t affectation);
int dot_variable(variable_t t);
