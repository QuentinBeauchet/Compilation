/* structures de données */

typedef struct _param_t {
	char *nom;
	int val;
	char *type;
} param_t;

void print_param(param_t t);

typedef struct _listof_param_t {
	param_t list[100];
	int size;
} listof_param_t;

listof_param_t append_listof_param(listof_param_t tab,param_t t);

typedef struct _fonction_t {
	listof_param_t args;
	char *nom;
	char *type;
} fonction_t;

typedef struct _declarateur_t {
	char* identificateur;
	struct declarateur_t *d;
	char* constante;
} declarateur_t;

void print_fonction(fonction_t f);
