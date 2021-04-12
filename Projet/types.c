#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

/* Print */
void print_tab(int n){
	for (int i = 0; i < n; ++i){
		printf("	");
  	}
}

void print_parm(int n,struct parm_t p){
	print_tab(n);
	printf("Parm:\n");
	print_tab(n+1);
	printf("%s\n",p.type);
	print_tab(n+1);
	printf("%s\n",p.identificateur);
}

void print_liste_parms(int n,struct liste_parms_t* tab){
	print_tab(n);
	printf("Liste Parms:\n");
	print_tab(n+1);
	printf("size = %d\n",tab->size);
	for (int i = 0; i < tab->size; ++i){
    		print_parm(n+1,tab->liste[i]);
  	}
}

void print_liste_constantes(int n,struct liste_constantes_t tab){
	print_tab(n);
	printf("Liste Constantes:\n");
	print_tab(n+1);
	printf("size = %d\n",tab.size);
	for (int i = 0; i < tab.size; ++i){
		print_tab(n+1);
    		printf("%d\n",tab.liste[i]);
  	}
}

void print_declarateur(int n,struct declarateur_t d){
	print_tab(n);
	printf("Declarateur:\n");
	print_tab(n+1);
	printf("%s\n",d.identificateur);
	if(d.liste_constantes.size>0){
		print_liste_constantes(n+1,d.liste_constantes);
	}
}

void print_liste_declarateurs(int n,struct liste_declarateurs_t tab){
	print_tab(n);
	printf("Liste Declarateurs:\n");
	print_tab(n+1);
	printf("size = %d\n",tab.size);
	for (int i = 0; i < tab.size; ++i){
    		print_declarateur(n+1,tab.liste[i]);
  	}
}

void print_declaration(int n,struct declaration_t* d){
	print_tab(n);
	printf("Declaration:\n");
	print_tab(n+1);
	printf("%s\n",d->type);
	print_liste_declarateurs(n+1,d->liste_declarateurs);
}

void print_liste_declarations(int n,struct liste_declarations_t* tab){
	print_tab(n);
	printf("Liste Declarations:\n");
	print_tab(n+1);
	printf("size = %d\n",tab->size);
	for (int i = 0; i < tab->size; ++i){
    		print_declaration(n+1,&tab->liste[i]);
  	}
}

void print_saut(int n,struct saut_t* s){
	print_tab(n);
	printf("Saut:\n");
	if(s->Return){
		print_tab(n+1);
		printf("Return\n");
		if(s->expression != NULL){
			print_expression(n+1,s->expression);
		}
	}
	else{
		print_tab(n+1);
		printf("Break\n");
	}
}

void print_selection(int n,struct selection_t* s){
	print_tab(n);
	printf("Selection:\n");
	switch(s->type_selection){
		case 0 :
			print_tab(n+1);
			printf("%s\n",s->selection_nom);
			print_condition(n+1,&s->condition);
			print_instruction(n+1,s->liste_instructions->liste[0]);
            		break;
        	case 1 :
        		print_tab(n+1);
			printf("%s\n",s->selection_nom);
			print_condition(n+1,&s->condition);
			print_instruction(n+1,s->liste_instructions->liste[0]);
			print_tab(n+1);
			printf("else\n");
			print_instruction(n+1,s->liste_instructions->liste[1]);
                	break;
        	case 2 :
			print_tab(n+1);
			printf("%s\n",s->selection_nom);
			print_expression(n+1,&s->expression);
			print_instruction(n+1,s->liste_instructions->liste[0]);
                	break;
        	case 3 :
        		print_tab(n+1);
			printf("%s\n",s->selection_nom);
			print_tab(n+1);
			printf("%d\n",s->constante);
			print_instruction(n+1,s->liste_instructions->liste[0]);
        		break;
        	case 4 :
        		print_tab(n+1);
			printf("%s\n",s->selection_nom);
			print_instruction(n+1,s->liste_instructions->liste[0]);
        		break;
            	default :
            		printf("ERROR:\n");
	}
}

void print_instruction(int n,struct instruction_t* i){
	print_tab(n);
	printf("Instruction:\n");
	if(i->iteration != NULL){
		print_iteration(n+1,i->iteration);
	}
	else if(i->selection != NULL){
		print_selection(n+1,i->selection);
	}
	else if(i->saut != NULL){
		print_saut(n+1,i->saut);
	}
	else if(i->affectation != NULL){
		print_affectation(n+1,i->affectation);
	}
	else if(i->bloc != NULL){
		print_bloc(n+1,i->bloc);
	}
	else if(i->appel != NULL){
		print_appel(n+1,i->appel);
	}
}

void print_liste_instructions(int n,struct liste_instructions_t* tab){
	print_tab(n);
	printf("Liste Instructions:\n");
	print_tab(n+1);
	printf("size = %d\n",tab->size);
	for (int i = 0; i < tab->size; ++i){
    		print_instruction(n+1,tab->liste[i]);
  	}
}

void print_bloc(int n,struct bloc_t* b){
	print_tab(n);
	printf("Bloc:\n");
	print_liste_declarations(n+1,&b->liste_declarations);
	print_liste_instructions(n+1,&b->liste_instructions);
}

void print_appel(int n,struct appel_t* a){
	print_tab(n);
	printf("Appel:\n");
	print_tab(n+1);
	printf("%s\n",a->identificateur);
	print_liste_expressions(n+1,&a->liste_expressions);
}

void print_affectation(int n,struct affectation_t* a){
	print_tab(n);
	printf("Affectation:\n");
	print_variable(n+1,&a->variable);
	print_expression(n+1,&a->expression);
}

void print_liste_affectations(int n,struct liste_affectations_t* tab){
	print_tab(n);
	printf("Liste Affectations:\n");
	print_tab(n+1);
	printf("size = %d\n",tab->size);
	for (int i = 0; i < tab->size; ++i){
    		print_affectation(n+1,&tab->liste[i]);
  	}
}

void print_variable(int n,struct variable_t* v){
	print_tab(n);
	printf("Variable:\n");
	print_tab(n+1);
	printf("%s\n",v->identificateur);
	if(v->liste_expressions != NULL){
		print_liste_expressions(n+1,v->liste_expressions);
	}
}

void print_liste_expressions(int n,struct liste_expressions_t* tab){
	print_tab(n);
	printf("Liste Expressions:\n");
	print_tab(n+1);
	printf("size = %d\n",tab->size);
	for (int i = 0; i < tab->size; ++i){
    		print_expression(n+1,&tab->liste[i]);
  	}
}

void print_expression(int n,struct expression_t* e){
	print_tab(n);
	printf("Expression:\n");
	switch(e->type_expression){
		case 0 :
            		print_expression(n+1,&e->liste_expressions->liste[0]);
            		break;
        	case 1 :
                	print_expression(n+1,&e->liste_expressions->liste[0]);
                	print_tab(n+1);
                	printf("%s\n",e->binary_op);
                	print_expression(n+1,&e->liste_expressions->liste[1]);
                	break;
        	case 2 :
                	print_tab(n+1);
                	printf("%s\n",e->binary_op);
                	print_expression(n+1,&e->liste_expressions->liste[0]);
                	break;
        	case 3 :
        		print_tab(n+1);
        		printf("%d\n",*e->constante);
        		break;
            	case 4 :
            		print_variable(n+1,e->variable);
            		break;
                case 5 :
        		print_tab(n+1);
        		printf("%s\n",e->identificateur);
        		print_liste_expressions(n+1,e->liste_expressions);
        		break;
            	default :
            		printf("ERROR\n");
	}
}

void print_iteration(int n,struct iteration_t* i){
	print_tab(n);
	printf("Iteration:\n");
	print_tab(n+1);
	if(i->For){
		printf("For\n");
		print_affectation(n+1,&i->liste_affectations->liste[0]);
		print_condition(n+1,i->condition); 
		print_affectation(n+1,&i->liste_affectations->liste[1]);
		print_instruction(n+1,i->instruction); 
	}
	else{
		printf("While:\n");
		print_condition(n+1,i->condition); 
		print_instruction(n+1,i->instruction); 
	}
}

void print_condition(int n,struct condition_t* c){
	print_tab(n);
	printf("Condition:\n");
	switch(c->type_condition){
		case 0 :
            		print_tab(n+1);
			printf("!\n");
			print_condition(n+1,&c->liste_conditions->liste[0]);
            		break;
        	case 1 :
                	print_condition(n+1,&c->liste_conditions->liste[0]);
			print_tab(n+1);
			printf("%s\n",c->binary_rel);
			print_condition(n+1,&c->liste_conditions->liste[1]);
                	break;
        	case 2 :
			print_condition(n+1,&c->liste_conditions->liste[1]);
                	break;
        	case 3 :
        		print_expression(n+1,&c->liste_expressions->liste[0]);
			print_tab(n+1);
			printf("%s\n",c->binary_comp);
			print_expression(n+1,&c->liste_expressions->liste[1]);
        		break;
            	default :
            		printf("ERROR:\n");
	}
}

void print_fonction(int n,struct fonction_t f){
	print_tab(n);
	printf("Fonction:\n");
	if(f.Extern){
		print_tab(n+1);
		printf("extern\n");
	}
	print_tab(n+1);
	printf("%s\n",f.type);
	print_tab(n+1);
	printf("%s\n",f.identificateur);
	print_liste_parms(n+1,&f.liste_parms);
	if(!f.Extern){
		print_liste_declarations(n+1,f.liste_declarations);
		print_liste_instructions(n+1,f.liste_instructions);
	}
}

void print_liste_fonctions(int n,struct liste_fonctions_t tab){
	print_tab(n);
	printf("Liste Fonctions:\n");
	print_tab(n+1);
	printf("size = %d\n",tab.size);
	for (int i = 0; i < tab.size; ++i){
    		print_fonction(n+1,tab.liste[i]);
  	}
}

void print_programme(struct programme_t p){
	printf("Programme:\n");
	print_liste_declarations(1,p.liste_declarations);
	print_liste_fonctions(1,p.liste_fonctions);
}

/* CopyOf */

struct liste_declarations_t* copyOf_liste_declarations(struct liste_declarations_t* tab){
	struct liste_declarations_t* copy = NULL;
	int length = sizeof(struct liste_declarations_t);
	copy = (struct liste_declarations_t *) malloc(length);
	memcpy(copy,tab,length);
	return copy;
}

struct liste_instructions_t* copyOf_liste_instructions(struct liste_instructions_t* tab){
	struct liste_instructions_t* copy = NULL;
	int length = sizeof(struct liste_instructions_t);
	copy = (struct liste_instructions_t *) malloc(length);
	memcpy(copy,tab,length);
	return copy;
}

struct instruction_t* copyOf_instruction(struct instruction_t* b){
	struct instruction_t* copy = NULL;
	int length = sizeof(struct instruction_t);
	copy = (struct instruction_t *) malloc(length);
	memcpy(copy,b,length);
	return copy;
}

struct iteration_t* copyOf_iteration(struct iteration_t* i){
	struct iteration_t* copy = NULL;
	int length = sizeof(struct iteration_t);
	copy = (struct iteration_t *) malloc(length);
	memcpy(copy,i,length);
	return copy;
}

struct selection_t* copyOf_selection(struct selection_t* i){
	struct selection_t* copy = NULL;
	int length = sizeof(struct selection_t);
	copy = (struct selection_t *) malloc(length);
	memcpy(copy,i,length);
	return copy;
}

struct saut_t* copyOf_saut(struct saut_t* b){
	struct saut_t* copy = NULL;
	int length = sizeof(struct saut_t);
	copy = (struct saut_t *) malloc(length);
	memcpy(copy,b,length);
	return copy;
}

struct bloc_t* copyOf_bloc(struct bloc_t* b){
	struct bloc_t* copy = NULL;
	int length = sizeof(struct bloc_t);
	copy = (struct bloc_t *) malloc(length);
	memcpy(copy,b,length);
	return copy;
}

struct variable_t* copyOf_variable(struct variable_t* v){
	struct variable_t* copy = NULL;
	int length = sizeof(struct variable_t);
	copy = (struct variable_t *) malloc(length);
	memcpy(copy,v,length);
	return copy;
}

struct liste_affectations_t* copyOf_liste_affectations(struct liste_affectations_t* tab){
	struct liste_affectations_t* copy = NULL;
	int length = sizeof(struct liste_affectations_t);
	copy = (struct liste_affectations_t *) malloc(length);
	memcpy(copy,tab,length);
	return copy;
}

struct affectation_t* copyOf_affectation(struct affectation_t* v){
	struct affectation_t* copy = NULL;
	int length = sizeof(struct affectation_t);
	copy = (struct affectation_t *) malloc(length);
	memcpy(copy,v,length);
	return copy;
}

struct appel_t* copyOf_appel(struct appel_t* a){
	struct appel_t* copy = NULL;
	int length = sizeof(struct appel_t);
	copy = (struct appel_t *) malloc(length);
	memcpy(copy,a,length);
	return copy;
}

struct condition_t* copyOf_condition(struct condition_t* a){
	struct condition_t* copy = NULL;
	int length = sizeof(struct condition_t);
	copy = (struct condition_t *) malloc(length);
	memcpy(copy,a,length);
	return copy;
}

struct liste_expressions_t* copyOf_liste_expressions(struct liste_expressions_t* tab){
	struct liste_expressions_t* copy = NULL;
	int length = sizeof(struct liste_expressions_t);
	copy = (struct liste_expressions_t *) malloc(length);
	memcpy(copy,tab,length);
	return copy;
}

struct expression_t* copyOf_expression(struct expression_t* e){
	struct expression_t* copy = NULL;
	int length = sizeof(struct expression_t);
	copy = (struct expression_t *) malloc(length);
	memcpy(copy,e,length);
	return copy;
}

int* copyOf_constante(int* c){
	int* copy = NULL;
	int length = sizeof(int*);
	copy = (int*) malloc(length);
	memcpy(copy,c,length);
	return copy;
}

/* Append */

void append_liste_parms(struct liste_parms_t* tab,struct parm_t p){
	tab->liste[tab->size] = p;
	tab->size=tab->size+1;
}

void append_liste_constantes(struct liste_constantes_t* tab,int constante){
	tab->liste[tab->size] = constante;
	tab->size=tab->size+1;
}

void append_liste_declarateurs(struct liste_declarateurs_t* tab,struct declarateur_t d){
	tab->liste[tab->size] = d;
	tab->size=tab->size+1;
}

void append_liste_declarations(struct liste_declarations_t* tab,struct declaration_t d){
	tab->liste[tab->size] = d;
	tab->size=tab->size+1;
}

void append_liste_expressions(struct liste_expressions_t* tab,struct expression_t e){
	tab->liste[tab->size] = e;
	tab->size=tab->size+1;
}

void append_liste_conditions(struct liste_conditions_t* tab,struct condition_t c){
	tab->liste[tab->size] = c;
	tab->size=tab->size+1;
}

void append_liste_instructions(struct liste_instructions_t* tab, struct instruction_t i){
	tab->liste[tab->size] = copyOf_instruction(&i);
	tab->size=tab->size+1;
}

void append_liste_affectations(struct liste_affectations_t* tab, struct affectation_t a){
	tab->liste[tab->size] = a;
	tab->size=tab->size+1;
}

void append_liste_fonctions(struct liste_fonctions_t* tab, struct fonction_t f){
	tab->liste[tab->size] = f;
	tab->size=tab->size+1;
}


