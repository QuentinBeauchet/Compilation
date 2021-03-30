#include <stdio.h>
#include <stdlib.h>
#include "types.h"

void print_param(param_t t){
	printf("Param_t: %s %s = %d\n",t.type,t.nom,t.val);
}

listof_param_t concat_listof_param(listof_param_t tab,listof_param_t t){
	if(t.size>0){
		tab.list[tab.size]=t.list[0];
		tab.size=tab.size+1;
	}
	return tab;
}

listof_param_t append_listof_param(listof_param_t tab,param_t t){
	tab.list[tab.size]=t;
	tab.size=tab.size+1;
	return tab;
}

void print_listof_param(listof_param_t tab){
	for (int i = 0; i < tab.size; ++i){
		if(i!=0){
			printf("; ");
		}
		printf("ok");
    		print_param(tab.list[i]);
  	}
}

void print_fonction(fonction_t f){
	printf("Fonction_t: %s %s",f.type,f.nom);
	printf("(");
	print_listof_param(f.args);
	printf(")\n");
}
