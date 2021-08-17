#include <stdio.h>
#include "Stack.h"
#define MAX 100

struct stack {
  ALUNO data[MAX];;
  int size;
};

STACK *stack_create(){
  STACK *S = NULL;
  S = malloc(1 * sizeof(STACK));
  
  if(S == NULL){
    return NULL;
  }
  
  else{
    S -> size = 0;
    return S;
  }
}

int stack_push(STACK *S, ALUNO aluno){
  if(S == NULL){
    return -1;
  }
  else{
    //Se a piha estiver cheia
    if(S -> size == MAX){
      return -1;
    }
    //Se a lista não estiver cheia
    else{
      S -> data[S -> size] = aluno;
      S -> size = S -> size + 1;
      return 0;
    }
  }
}

int stack_pop(STACK *S){
  if(S == NULL){
    return -1;
  }
  else{
    //Se a lista estiver vazia
    if(S -> size == 0){
        return -1;
    }
    //Se a lista não estiver vazia
    else{
      S -> size =  S -> size - 1;
      return 0;
    }
  }
}

int stack_top(STACK *S, ALUNO *aluno){
  if(S == NULL){
    return -1;
  }
  else{
    //Se a lista estiver vazia
    if(S -> size == 0){
      return -1;
    }
    else{
      *aluno = S -> data[S -> size -1];
    }
  }
}

int stack_empty(STACK *S){
  if(S == NULL){
    return -1;
  }
  else{
    //Se a lista for vazia
    if(S -> size == 0){
      return 1;
    }
    //Se a lista não for vazia
    else{
      return 0;
    }
  }
}

int stack_full(STACK *S){
  if(S == NULL){
    return -1;
  }
  else{
    //Se a lista estiver cheia
    if(S -> size == MAX){
      return 1;
    }
    //Se a lista não estiver cheia
    else{
      return 0;
    }
  }
}

int stack_size(STACK *S){
  if(S == NULL){
    return -1;
  }
  else{
    return S -> size;
  }
}

int stack_free(STACK *S){
  if(S == NULL){
    return -1;
  }
  else{
    free(S);
    return 0;
  }
}

int stack_print(STACK *S){
  if(S == NULL){
    return -1;
  }
  else{
    int i = 0;
    while(i < S -> size){
        printf("Aluno %d\n\n",i + 1);
        printf("Nome: %s\n",S -> data[i].nome);
        printf("Matrícula: %d \n",S -> data[i].matricula);
        printf("Nota da primeira prova %f\n",S -> data[i].notas[0]);
        printf("Nota da segunda prova %f\n",S -> data[i].notas[1]);
        printf("Nota da terceira prova %f\n",S -> data[i].notas[2]);
        printf("Nota da quarta prova %f\n",S -> data[i].notas[3]);
        printf("Faltas: %d\n",S -> data[i].faltas);
        printf("\n\n");
        i++;
    }
    return 0;
  }
}
