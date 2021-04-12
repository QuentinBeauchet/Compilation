#include <stdbool.h>

/* Structures de données */

struct parm_t {
	char *identificateur;
	char *type;
};

struct liste_parms_t {
	struct parm_t liste[20];
	int size;
};

struct liste_constantes_t {
	int liste[20];
	int size;
};

struct declarateur_t {
	char* identificateur;
	struct liste_constantes_t liste_constantes;
}; 

struct liste_declarateurs_t {
	struct declarateur_t liste[20];
	int size;
};

struct declaration_t {
	struct liste_declarateurs_t liste_declarateurs;
	char* type;
};

struct liste_declarations_t {
	struct declaration_t liste[20];
	int size;
};

struct variable_t {
	char* identificateur;
	struct liste_expressions_t* liste_expressions;
};

struct expression_t {
	int type_expression;
	char* identificateur;
	struct liste_expressions_t* liste_expressions;
	struct variable_t* variable;
	int* constante;
	char* binary_op;
};

struct liste_expressions_t {
	struct expression_t liste[20];
	int size;
};

struct affectation_t {
	struct variable_t variable;
	struct expression_t expression;
};

struct liste_affectations_t {
	struct affectation_t liste[20];
	int size;
};

struct condition_t {
	int type_condition;
	char* binary_rel;
	char* binary_comp;
	struct liste_conditions_t* liste_conditions;
	struct liste_expressions_t* liste_expressions;
};

struct liste_conditions_t {
	struct condition_t liste[20];
	int size;
};

struct appel_t {
	char* identificateur;
	struct liste_expressions_t liste_expressions;
};

struct saut_t {
	bool Return;
	struct expression_t* expression;
};

struct selection_t {
	int type_selection;
	char* selection_nom; 
	int constante; 
	bool Else;
	struct liste_instructions_t* liste_instructions; 
	struct condition_t condition; 
	struct expression_t expression;
};

struct instruction_t {
	struct iteration_t* iteration;
	struct selection_t* selection;
	struct saut_t* saut;
	struct affectation_t* affectation;
	struct bloc_t* bloc;
	struct appel_t* appel;
};

struct liste_instructions_t {
	struct instruction_t* liste[100];
	int size;
};

struct bloc_t {
	struct liste_instructions_t liste_instructions;
	struct liste_declarations_t liste_declarations;
};

struct iteration_t {
	bool For;
	struct liste_affectations_t* liste_affectations; 
	struct condition_t* condition; 
	struct instruction_t* instruction;
};

struct fonction_t {
	struct liste_parms_t liste_parms;
	struct liste_declarations_t* liste_declarations;
	struct liste_instructions_t* liste_instructions;
	bool Extern;
	char *identificateur;
	char *type;
};

struct liste_fonctions_t {
	struct fonction_t liste[20];
	int size;
};

struct programme_t {
	struct liste_declarations_t* liste_declarations;
	struct liste_fonctions_t liste_fonctions;
};

/* Declarations fonctions */

void print_programme(struct programme_t p);
void print_liste_declarations(int n,struct liste_declarations_t* tab);
void print_declaration(int n,struct declaration_t* d);
void print_liste_declarateurs(int n,struct liste_declarateurs_t tab);
void print_declarateur(int n,struct declarateur_t d);
void print_liste_constantes(int n,struct liste_constantes_t tab);
void print_liste_fonctions(int n,struct liste_fonctions_t tab);
void print_fonction(int n,struct fonction_t f);
void print_liste_parms(int n,struct liste_parms_t* tab);
void print_parm(int n,struct parm_t p);
void print_liste_instructions(int n,struct liste_instructions_t* tab);
void print_instruction(int n,struct instruction_t* i);
void print_iteration(int n,struct iteration_t* i);
void print_selection(int n,struct selection_t* s);
void print_saut(int n,struct saut_t* s);
void print_affectation(int n,struct affectation_t* a);
void print_bloc(int n,struct bloc_t* b);
void print_appel(int n,struct appel_t* a);
void print_variable(int n,struct variable_t* v);
void print_liste_expressions(int n,struct liste_expressions_t* tab);
void print_expression(int n,struct expression_t* e);
void print_condition(int n,struct condition_t* c);


