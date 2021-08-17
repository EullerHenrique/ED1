#define MAX 1000

typedef struct{
  char nome[100];
  int matricula;
  float notas[4];
  int faltas;
}ALUNO;
  
typedef struct LISTA LISTA;

LISTA *criar_lista();

int tamanho_lista(LISTA* L);

int lista_cheia(LISTA *L);


int insere_lista_inicio(LISTA *L, ALUNO alun);

int insere_lista_final(LISTA *L, ALUNO aluno);

int insere_lista_ordenada(LISTA *L, ALUNO aluno);


int remove_lista_inicio(LISTA *L);

int remove_lista_final(LISTA *L);

int remove_lista_matricula(LISTA* L, int matricula);


int consulta_lista_pos(LISTA *L, ALUNO *aluno, int pos);
int consulta_lista_matricula(LISTA *L, ALUNO *aluno, int matricula);

int libera_lista(LISTA* L); 