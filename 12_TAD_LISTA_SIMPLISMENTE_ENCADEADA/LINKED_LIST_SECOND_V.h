struct aluno{
  int matricula;
  char nome[30];
  float notas[4];
  int faltas;
};

typedef struct list LIST;
typedef struct list_node LIST_NODE;
typedef struct aluno ALUNO;

LIST *list_create();

int list_push_front(LIST *L, ALUNO aluno);
int list_push_back(LIST *L, ALUNO aluno);
int list_insert(LIST *L, int pos, ALUNO aluno);
int list_push_ordered(LIST *L, ALUNO aluno);

int list_pop_front(LIST *L);
int list_pop_back(LIST *L);
int list_pop_mat(LIST *L, int mat);
int list_pop_pos(LIST *L, int pos);

int list_find_pos(LIST*L, int pos, ALUNO *aluno);
int list_find_mat(LIST *L, int mat, ALUNO *aluno);

int list_full(LIST *L); 
int list_void(LIST *L);

int list_print(LIST *L);

int list_size(LIST *L);
int list_free(LIST *L);