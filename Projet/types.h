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
listof_param_t concat_listof_param(listof_param_t tab,listof_param_t t);


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

typedef struct _listof_delclarateur_t {
	declarateur_t list[100];
	int size;
} listof_declarateur_t

listof_declarateur_t append_listof_declarateur_t(listof_declarateur_t tab , declarateur_t t);
listof_declarateur_t concat_listof_declarateur_t(listof_declarateur_t tab , listof_declarateur_t t);

typedef struct _declaration_t {
	listof_delclarateur_t args;
} declaration_t;

typedef struct _listof_declaration_t {
	declaration_t list[100];
	int size;
}_listof_declaration_t

listof_declaration_t append_listof_declaration_t(listof_declaration_t tab , declaration_t t);
listof_declaration_t concat_listof_declaration_t(listof_declaration_t tab , listof_declaration_t t);

void print_fonction(fonction_t f);
