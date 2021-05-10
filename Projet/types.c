#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

FILE* fichier;
int index_graph = 1;

/* Print */
void print_tab(int n){
	for (int i = 0; i < n; ++i){
		printf("   ");
  	}
}

void print_parm(int n,parm_t p){
	print_tab(n);
	printf("Parm:\n");
	print_tab(n+1);
	printf("%s\n",p.type);
	print_tab(n+1);
	printf("%s\n",p.identificateur);
}

void print_liste_parms(int n,liste_parms_t* tab){
	print_tab(n);
	printf("Liste Parms:\n");
	print_tab(n+1);
	printf("size = %d\n",tab->size);
	for (int i = 0; i < tab->size; ++i){
    		print_parm(n+1,tab->liste[i]);
  	}
}

void print_liste_constantes(int n,liste_constantes_t tab){
	print_tab(n);
	printf("Liste Constantes:\n");
	print_tab(n+1);
	printf("size = %d\n",tab.size);
	for (int i = 0; i < tab.size; ++i){
		print_tab(n+1);
    		printf("%d\n",tab.liste[i]);
  	}
}

void print_declarateur(int n,declarateur_t d){
	print_tab(n);
	printf("Declarateur:\n");
	print_tab(n+1);
	printf("%s\n",d.identificateur);
	if(d.liste_constantes.size>0){
		print_liste_constantes(n+1,d.liste_constantes);
	}
}

void print_liste_declarateurs(int n,liste_declarateurs_t tab){
	print_tab(n);
	printf("Liste Declarateurs:\n");
	print_tab(n+1);
	printf("size = %d\n",tab.size);
	for (int i = 0; i < tab.size; ++i){
    		print_declarateur(n+1,tab.liste[i]);
  	}
}

void print_declaration(int n,declaration_t* d){
	print_tab(n);
	printf("Declaration:\n");
	print_tab(n+1);
	printf("%s\n",d->type);
	print_liste_declarateurs(n+1,d->liste_declarateurs);
}

void print_liste_declarations(int n,liste_declarations_t* tab){
	print_tab(n);
	printf("Liste Declarations:\n");
	print_tab(n+1);
	printf("size = %d\n",tab->size);
	for (int i = 0; i < tab->size; ++i){
    		print_declaration(n+1,&tab->liste[i]);
  	}
}

void print_saut(int n,saut_t* s){
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

void print_selection(int n,selection_t* s){
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
			print_liste_instructions(n+1,s->liste_instructions);
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

void print_instruction(int n,instruction_t* i){
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

void print_liste_instructions(int n,liste_instructions_t* tab){
	print_tab(n);
	printf("Liste Instructions:\n");
	print_tab(n+1);
	printf("size = %d\n",tab->size);
	for (int i = 0; i < tab->size; ++i){
    		print_instruction(n+1,tab->liste[i]);
  	}
}

void print_bloc(int n,bloc_t* b){
	print_tab(n);
	printf("Bloc:\n");
	print_liste_declarations(n+1,&b->liste_declarations);
	print_liste_instructions(n+1,&b->liste_instructions);
}

void print_appel(int n,appel_t* a){
	print_tab(n);
	printf("Appel:\n");
	print_tab(n+1);
	printf("%s\n",a->identificateur);
	print_liste_expressions(n+1,&a->liste_expressions);
}

void print_affectation(int n,affectation_t* a){
	print_tab(n);
	printf("Affectation:\n");
	print_variable(n+1,&a->variable);
	print_expression(n+1,&a->expression);
}

void print_liste_affectations(int n,liste_affectations_t* tab){
	print_tab(n);
	printf("Liste Affectations:\n");
	print_tab(n+1);
	printf("size = %d\n",tab->size);
	for (int i = 0; i < tab->size; ++i){
    		print_affectation(n+1,&tab->liste[i]);
  	}
}

void print_variable(int n,variable_t* v){
	print_tab(n);
	printf("Variable:\n");
	print_tab(n+1);
	printf("%s\n",v->identificateur);
	if(v->liste_expressions != NULL){
		print_liste_expressions(n+1,v->liste_expressions);
	}
}

void print_liste_expressions(int n,liste_expressions_t* tab){
	print_tab(n);
	printf("Liste Expressions:\n");
	print_tab(n+1);
	printf("size = %d\n",tab->size);
	for (int i = 0; i < tab->size; ++i){
    		print_expression(n+1,&tab->liste[i]);
  	}
}

void print_expression(int n,expression_t* e){
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

void print_iteration(int n,iteration_t* i){
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

void print_condition(int n,condition_t* c){
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

void print_fonction(int n,fonction_t f){
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
		print_bloc(n+1,f.bloc);
	}
}

void print_liste_fonctions(int n,liste_fonctions_t tab){
	print_tab(n);
	printf("Liste Fonctions:\n");
	print_tab(n+1);
	printf("size = %d\n",tab.size);
	for (int i = 0; i < tab.size; ++i){
    		print_fonction(n+1,tab.liste[i]);
  	}
}

void print_programme(programme_t p){
	printf("Programme:\n");
	print_liste_declarations(1,p.liste_declarations);
	print_liste_fonctions(1,p.liste_fonctions);
}

/* CopyOf */

liste_declarations_t* copyOf_liste_declarations(liste_declarations_t* tab){
	liste_declarations_t* copy = NULL;
	int length = sizeof(liste_declarations_t);
	copy = (liste_declarations_t *) malloc(length);
	memcpy(copy,tab,length);
	return copy;
}

liste_instructions_t* copyOf_liste_instructions(liste_instructions_t* tab){
	liste_instructions_t* copy = NULL;
	int length = sizeof(liste_instructions_t);
	copy = (liste_instructions_t *) malloc(length);
	memcpy(copy,tab,length);
	return copy;
}

instruction_t* copyOf_instruction(instruction_t* b){
	instruction_t* copy = NULL;
	int length = sizeof(instruction_t);
	copy = (instruction_t *) malloc(length);
	memcpy(copy,b,length);
	return copy;
}

iteration_t* copyOf_iteration(iteration_t* i){
	iteration_t* copy = NULL;
	int length = sizeof(iteration_t);
	copy = (iteration_t *) malloc(length);
	memcpy(copy,i,length);
	return copy;
}

selection_t* copyOf_selection(selection_t* i){
	selection_t* copy = NULL;
	int length = sizeof(selection_t);
	copy = (selection_t *) malloc(length);
	memcpy(copy,i,length);
	return copy;
}

saut_t* copyOf_saut(saut_t* b){
	saut_t* copy = NULL;
	int length = sizeof(saut_t);
	copy = (saut_t *) malloc(length);
	memcpy(copy,b,length);
	return copy;
}

bloc_t* copyOf_bloc(bloc_t* b){
	bloc_t* copy = NULL;
	int length = sizeof(bloc_t);
	copy = (bloc_t *) malloc(length);
	memcpy(copy,b,length);
	return copy;
}

variable_t* copyOf_variable(variable_t* v){
	variable_t* copy = NULL;
	int length = sizeof(variable_t);
	copy = (variable_t *) malloc(length);
	memcpy(copy,v,length);
	return copy;
}

liste_affectations_t* copyOf_liste_affectations(liste_affectations_t* tab){
	liste_affectations_t* copy = NULL;
	int length = sizeof(liste_affectations_t);
	copy = (liste_affectations_t *) malloc(length);
	memcpy(copy,tab,length);
	return copy;
}

affectation_t* copyOf_affectation(affectation_t* v){
	affectation_t* copy = NULL;
	int length = sizeof(affectation_t);
	copy = (affectation_t *) malloc(length);
	memcpy(copy,v,length);
	return copy;
}

appel_t* copyOf_appel(appel_t* a){
	appel_t* copy = NULL;
	int length = sizeof(appel_t);
	copy = (appel_t *) malloc(length);
	memcpy(copy,a,length);
	return copy;
}

condition_t* copyOf_condition(condition_t* a){
	condition_t* copy = NULL;
	int length = sizeof(condition_t);
	copy = (condition_t *) malloc(length);
	memcpy(copy,a,length);
	return copy;
}

liste_expressions_t* copyOf_liste_expressions(liste_expressions_t* tab){
	liste_expressions_t* copy = NULL;
	int length = sizeof(liste_expressions_t);
	copy = (liste_expressions_t *) malloc(length);
	memcpy(copy,tab,length);
	return copy;
}

expression_t* copyOf_expression(expression_t* e){
	expression_t* copy = NULL;
	int length = sizeof(expression_t);
	copy = (expression_t *) malloc(length);
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

void append_liste_parms(liste_parms_t* tab,parm_t p){
	tab->liste[tab->size] = p;
	tab->size=tab->size+1;
}

void append_liste_constantes(liste_constantes_t* tab,int constante){
	tab->liste[tab->size] = constante;
	tab->size=tab->size+1;
}

void append_liste_declarateurs(liste_declarateurs_t* tab,declarateur_t d){
	tab->liste[tab->size] = d;
	tab->size=tab->size+1;
}

void append_liste_declarations(liste_declarations_t* tab,declaration_t d){
	tab->liste[tab->size] = d;
	tab->size=tab->size+1;
}

void append_liste_expressions(liste_expressions_t* tab,expression_t e){
	tab->liste[tab->size] = e;
	tab->size=tab->size+1;
}

void append_liste_conditions(liste_conditions_t* tab,condition_t c){
	tab->liste[tab->size] = c;
	tab->size=tab->size+1;
}

void append_liste_instructions(liste_instructions_t* tab, instruction_t i){
	tab->liste[tab->size] = copyOf_instruction(&i);
	tab->size=tab->size+1;
}

void append_liste_affectations(liste_affectations_t* tab, affectation_t a){
	tab->liste[tab->size] = a;
	tab->size=tab->size+1;
}

void append_liste_fonctions(liste_fonctions_t* tab, fonction_t f){
	tab->liste[tab->size] = f;
	tab->size=tab->size+1;
}

/* Autres */

expression_t make_expr(expression_t e1, char* binary_op, expression_t e2){
	liste_expressions_t tab = {.size = 0};
	append_liste_expressions(&tab,e1);
	append_liste_expressions(&tab,e2);
	return (expression_t){.binary_op = binary_op, .liste_expressions = copyOf_liste_expressions(&tab), .type_expression = 1};
}

selection_t make_selection(int type_selection, char* selection_nom, bloc_t bloc, int constante){
	liste_instructions_t tab = {.size = 0};
	if(selection_nom == "CASE" || "DEFAULT"){
		if(bloc.liste_declarations.size != 0 || bloc.liste_instructions.size !=0){
			append_liste_instructions(&tab,(instruction_t){.bloc = copyOf_bloc(&bloc)});
		}
		return (selection_t){.type_selection = type_selection, .selection_nom = selection_nom, .constante = constante, .liste_instructions = copyOf_liste_instructions(&tab)};
	}
}

void extend_env(Env* env, char* symbol, Value value){
	env->liste_symbol[env->size] = symbol;
	env->liste_value[env->size] = value;
	env->size=env->size+1;
}

Value lookup(Env* env, char* symbol){
	for(int i = env->size-1; i >= 0; --i){
    		if(env->liste_symbol[i]==symbol){
    			return env->liste_value[i];
    		}
  	}
  	printf("Erreur: Le symbol %s n'existe pas dans l'environement.\n",symbol);
  	exit(1);
}

/* Dot */

void dot_generation(programme_t programme,char* file_name){
	fichier=fopen(file_name, "w");
	fclose(fichier);
	fichier=fopen(file_name, "a");
	fprintf(fichier,"digraph diagram1 {\n");
	fprintf(fichier,"//programme\n");
	dot_programme(&programme);
	fprintf(fichier, "}\n");
	fclose(fichier);
}

void dot_programme(programme_t* programme){
	//affichage programme
	dot_liste_fonctions(programme->liste_fonctions);
}

void dot_liste_fonctions(liste_fonctions_t liste_fonctions){
	for (int i = 0; i < liste_fonctions.size; ++i){
		if(!liste_fonctions.liste[i].Extern){
    			dot_fonction(liste_fonctions.liste[i]);
    		}
  	}
	
}

void dot_fonction(fonction_t fonction){
	int myIndex = index_graph;
	fprintf(fichier,"node_%d [label=\"%s,%s\" shape=invtrapezium color=blue];//fonction\n ",myIndex,fonction.identificateur,fonction.type);
	index_graph = index_graph+1;
	int index_instruction = dot_bloc(*fonction.bloc);
	fprintf(fichier,"node_%d -> node_%d\n", myIndex,index_instruction );
}

int dot_instruction(instruction_t instruction){
	int myIndex = index_graph;
	
	if(instruction.bloc != NULL){
		int index_bloc = dot_bloc(*instruction.bloc);

	}
	else if (instruction.appel != NULL){
		int index_appel = dot_appel(*instruction.appel);
	}
	if(instruction.iteration != NULL){
		int index_iteration = dot_iteration(*instruction.iteration);
	}
	else if(instruction.selection != NULL){
		int index_selection = dot_selection(*instruction.selection);
	}
	else if(instruction.saut != NULL){
		int index_saut = dot_saut(*instruction.saut);
	}
	else if(instruction.affectation != NULL){
		int index_affec  = dot_affectation( *instruction.affectation);
	}
	index_graph = index_graph+1;
	return myIndex;
}
int dot_affectation (affectation_t affectation){
	int myIndex = index_graph;	
	index_graph= index_graph+1;
	
	if(affectation.variable.liste_expressions->size == 0){
		fprintf(fichier,"node_%d [label=\":=\" ];//affectation\n",myIndex);
		int index_var= index_graph;
		fprintf(fichier,"node_%d [label=\"%s\" ];//				affec\n",index_var,affectation.variable.identificateur);
		index_graph= index_graph+1;
		int index_expr = dot_expression(affectation.expression);
		fprintf(fichier,"node_%d -> node_%d\n", myIndex,index_var );
		fprintf(fichier,"node_%d -> node_%d\n", myIndex,index_expr );
	}else{
		
				int index_tab = index_graph;
		index_graph= index_graph+1;

		fprintf(fichier,"node_%d [label=\"TAB\"];//tableau\n",myIndex);
		fprintf(fichier,"node_%d [label=\"%s\"];//tableau\n",index_tab,affectation.variable.identificateur);
		fprintf(fichier,"node_%d -> node_%d//test\n", myIndex,index_tab );
		
		for (int i = 0; i < affectation.variable.liste_expressions->size; ++i){
			int index_tabi = dot_expression(affectation.variable.liste_expressions->liste[i]);
			fprintf(fichier ,"node_%d [shape=triangle];\n",index_tabi);
			int index_expr_tabi = dot_expression(affectation.expression);
			fprintf(fichier,"node_%d -> node_%d\n", myIndex,index_tabi );
			fprintf(fichier,"node_%d -> node_%d\n", index_tabi,index_expr_tabi );
    		}
  	}
		
	return myIndex;
}
int dot_iteration (iteration_t i){
	int myIndex = index_graph;
	index_graph =index_graph +1;
	if(i.For){
		fprintf(fichier,"node_%d [label=\"FOR\" ];//FOR\n",myIndex);
		int index_affec_init = dot_affectation(i.liste_affectations->liste[0]);
		int index_cond_for = dot_condition(*i.condition);
		int index_affec_post = dot_affectation(i.liste_affectations->liste[1]);
		int index_body_for = dot_instruction(*i.instruction);
		fprintf(fichier,"node_%d -> node_%d\n", myIndex,index_affec_init );
		fprintf(fichier,"node_%d -> node_%d\n", myIndex,index_cond_for );
		fprintf(fichier,"node_%d -> node_%d\n", myIndex,index_affec_post );
		fprintf(fichier,"node_%d -> node_%d\n", myIndex,index_body_for );
	}else{
		fprintf(fichier,"node_%d [label=\"WHILE\" ];//WHILE\n",myIndex);
		int index_cond_while = dot_condition(*i.condition);
		int index_corps_while = dot_instruction(*i.instruction);
		fprintf(fichier,"node_%d -> node_%d\n", myIndex,index_cond_while );
		fprintf(fichier,"node_%d -> node_%d\n", myIndex,index_corps_while );
	}
	return myIndex;
}
int dot_saut (saut_t saut){
	int myIndex = index_graph;
	index_graph =index_graph +1;
	
	if(saut.Return){
		fprintf(fichier,"node_%d [label=\"RETURN\" shape=trapezium color=blue];//RETURN\n",myIndex);
		if(saut.expression!= NULL){
			int index_expression = dot_expression(*saut.expression);
			fprintf(fichier,"node_%d -> node_%d\n", myIndex,index_expression );
		}
		
	}else{
		fprintf(fichier,"node_%d [label=\"BREAK\" shape=square];//BREAK\n",myIndex);
	}
	
	
	return myIndex;
}

int dot_bloc (bloc_t b){
	int myIndex = index_graph;
	index_graph =index_graph +1;
	fprintf(fichier,"node_%d [label=\"BLOC\" shape=ellipse];//bloc\n",myIndex);
	for (int i = 0; i < b.liste_instructions.size; ++i){
		int index_instruction = dot_instruction(*b.liste_instructions.liste[i]);
		fprintf(fichier,"node_%d -> node_%d\n", myIndex,index_instruction );
  	}
	
	return myIndex;
}
int dot_appel(appel_t appel){
	int myIndex = index_graph;
	index_graph =index_graph +1;
	fprintf(fichier,"node_%d [label=\"%s\" shape=septagon];//appel\n",myIndex,appel.identificateur);
	for (int i = 0; i < appel.liste_expressions.size; ++i){
		int index_expr = dot_expression(appel.liste_expressions.liste[i]);
		fprintf(fichier,"node_%d -> node_%d\n", myIndex,index_expr );
  	}
	
	return myIndex;
}
int dot_expression (expression_t e){
	int myIndex = index_graph;
	switch(e.type_expression){
		case 0 :
            		dot_expression(e.liste_expressions->liste[0]);
            		break;
        	case 1 :
        		index_graph =index_graph +1;
        		fprintf(fichier,"node_%d [label=\"%s\" ];//expression1\n",myIndex,e.binary_op);
        		int left_op = dot_expression(e.liste_expressions->liste[0]);
        		int right_op = dot_expression(e.liste_expressions->liste[1]);
        		fprintf(fichier,"node_%d -> node_%d\n", myIndex,left_op );
        		fprintf(fichier,"node_%d -> node_%d\n", myIndex,right_op );
                	break;
        	case 2 :
        		index_graph =index_graph +1;
        		fprintf(fichier,"node_%d [label=\"%s\" ];//expression3\n",myIndex,e.binary_op);
        		int res_op = dot_expression(e.liste_expressions->liste[0]);
        		fprintf(fichier,"node_%d -> node_%d\n", myIndex,res_op );
                	break;
        	case 3 :
        		index_graph =index_graph +1;
        		fprintf(fichier,"node_%d [label=\"%d\" ];//expression3\n",myIndex,*e.constante);
        		break;
            	case 4 :
            		index_graph =index_graph +1;
            		fprintf(fichier,"node_%d [label=\"%s\" ];//expression4\n",myIndex,e.variable->identificateur);
            		break;
                case 5 :
                	index_graph =index_graph +1;
        		fprintf(fichier,"node_%d [label=\"%s\" shape=septagon];//expression5\n",myIndex,e.identificateur);
			for (int i = 0; i < e.liste_expressions->size; ++i){
				int index_expr = dot_expression(e.liste_expressions->liste[i]);
				fprintf(fichier,"node_%d -> node_%d\n", myIndex,index_expr );
  			}
        		break;
            	default :
            		printf("ERROR\n");
	}
	
	return myIndex;
	
}
int dot_selection(selection_t s){
	int myIndex = index_graph;
	index_graph =index_graph +1;
	switch(s.type_selection){
		case 0 :
			fprintf(fichier,"node_%d [label=\"IF\" shape=diamond];//IF0\n",myIndex);
			int cond_index = dot_condition(s.condition);
			int then_index = dot_instruction(*s.liste_instructions->liste[0]);
			fprintf(fichier,"node_%d -> node_%d\n", myIndex,cond_index );
			fprintf(fichier,"node_%d -> node_%d\n", myIndex,then_index );
            		break;
        	case 1 :
        		fprintf(fichier,"node_%d [label=\"IF\" shape=diamond];//IF1\n",myIndex);
			int cond2_index = dot_condition(s.condition);
			int then2_index = dot_instruction(*s.liste_instructions->liste[0]);
			int else2_index = dot_instruction(*s.liste_instructions->liste[1]);
			fprintf(fichier,"node_%d -> node_%d\n", myIndex,cond2_index );
			fprintf(fichier,"node_%d -> node_%d\n", myIndex,then2_index );
        		fprintf(fichier,"node_%d -> node_%d\n", myIndex,else2_index );
                	break;
        	case 2 :
        		fprintf(fichier,"node_%d [label=\"SWITCH\"];//SC2\n",myIndex);
        		int index_expr_switch = dot_expression(s.expression);
        		fprintf(fichier,"node_%d -> node_%d\n", myIndex,index_expr_switch );
        		for (int i = 0; i < s.liste_instructions->liste[0]->bloc->liste_instructions.size; ++i){
				int index_instru = dot_instruction(*s.liste_instructions->liste[0]->bloc->liste_instructions.liste[i]);
				if(s.liste_instructions->liste[0]->bloc->liste_instructions.liste[i]->saut == NULL)
				fprintf(fichier,"node_%d -> node_%d\n", myIndex,index_instru );
				else fprintf(fichier,"node_%d -> node_%d\n", index_instru-3,index_instru );
  			}
                	break;
        	case 3 :
        		fprintf(fichier,"node_%d [label=\"%d\" shape=triangle];//SC3\n",myIndex,s.constante);
                	if(s.liste_instructions->size !=0){
                	int inst_index = dot_instruction(*s.liste_instructions->liste[0]);
                		fprintf(fichier,"node_%d -> node_%d\n", myIndex,inst_index );
                	}
                	break;
        	case 4 :
        		fprintf(fichier,"node_%d [label=\"DEFAULT\" shape=triangle];//SC4\n",myIndex);
        		int inst2_index = dot_instruction(*s.liste_instructions->liste[0]);
        		fprintf(fichier,"node_%d -> node_%d\n", myIndex,inst2_index );
        		break;
            	default :
            		printf("ERROR:\n");
      }
            return myIndex;
}

int dot_condition(condition_t cond){
	int myIndex = index_graph;
	index_graph = index_graph +1;
	switch(cond.type_condition){
		case 0 :
			fprintf(fichier,"node_%d [label=\"NOT\"];//cond1\n",myIndex);
			int cond_index = dot_condition(cond.liste_conditions->liste[0]);
			fprintf(fichier,"node_%d -> node_%d\n", myIndex,cond_index );
            		break;
        	case 1 :
        		fprintf(fichier,"node_%d [label=\"%s\"];//cond2\n",myIndex,cond.binary_rel);
        		int left_index = dot_condition(cond.liste_conditions->liste[0]);
        		int right_index = dot_condition(cond.liste_conditions->liste[1]);
        		fprintf(fichier,"node_%d -> node_%d\n", myIndex,left_index );
        		fprintf(fichier,"node_%d -> node_%d\n", myIndex,right_index );
                	break;
        	case 2 :
			dot_condition(cond.liste_conditions->liste[0]);
                	break;
        	case 3 :
        		fprintf(fichier,"node_%d [label=\"%s\"];//cond3\n",myIndex,cond.binary_comp);
        		int left2_index = dot_expression(cond.liste_expressions->liste[0]);
        		int right2_index = dot_expression(cond.liste_expressions->liste[1]);
        		fprintf(fichier,"node_%d -> node_%d\n", myIndex,left2_index );
        		fprintf(fichier,"node_%d -> node_%d\n", myIndex,right2_index );
        		break;
            	default :
            		printf("ERROR:\n");
            	}
            return myIndex;
}

