#include <stdlib.h>

struct aluno{
  char nome[30];
  int matricula;
  float notas[4];
  int faltas;
};

typedef struct stack STACK;
typedef struct aluno ALUNO;

STACK *stack_create();

int stack_push(STACK *S, ALUNO aluno);
int stack_pop(STACK *S);
int stack_top(STACK *S, ALUNO *aluno);

int stack_empty(STACK *S);
int stack_full(STACK *S);
int stack_size(STACK *S);
int stack_print(STACK *S);

int stack_free(STACK *S);