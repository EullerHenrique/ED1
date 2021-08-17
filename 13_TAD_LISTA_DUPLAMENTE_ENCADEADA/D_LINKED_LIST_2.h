struct aluno{
  int matricula;
  char nome[30];
  float notas[4];
  int faltas;
};

typedef struct dlinkedList LIST;
typedef struct dlnode DLNODE;
typedef struct aluno ALUNO;

LIST* list_create(); // fiz


int list_push_front(LIST *L, ALUNO aluno); // fiz
int list_push_back(LIST *L, ALUNO aluno); // fiz
int list_insert(LIST *L, int pos, ALUNO aluno); // fiz
int list_push_ordered(LIST *L, ALUNO aluno); // fiz

int list_pop_front(LIST *L); //fiz
int list_pop_back(LIST *L); //fiz
int list_erase(LIST *L, int pos); //fiz
int list_erase_short_version(LIST *L, int pos); // fiz
int list_pop_mat(LIST *L, int matricula); // fiz

int list_find_mat(LIST *L, int mat, ALUNO *aluno); // fiz 
int list_find_pos(LIST *L, int pos, ALUNO *aluno); // fiz

int list_front(LIST *L, ALUNO *aluno);
int list_back(LIST *L, ALUNO *aluno);

int getpos(LIST *L, int mat, int *pos); // fiz

int list_size(LIST* L);// fiz

int list_full(LIST* L); // fiz
int list_void(LIST* L); // fiz

int list_print(LIST* L); // fiz
int list_free(LIST *L); // fiz
