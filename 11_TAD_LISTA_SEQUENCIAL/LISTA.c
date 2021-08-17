#include <stdlib.h>
#include <string.h>
#include "LISTA.h"

struct LISTA{
  ALUNO aluno[MAX];
  int qtd;
};  

LISTA* criar_lista(){
  LISTA *L;
  L = malloc(1 * sizeof(LISTA)); 
  
  if(L == NULL){
    return NULL;
  }
  
  L  -> qtd = 0;

return L;  
}

int tamanho_lista(LISTA* L){
  if(L == NULL){
    return -1;
  }

return L -> qtd;
}

int lista_cheia(LISTA *L){
  if(L == NULL){
    return -1;
  }
  else
  if(L -> qtd == MAX){
    return 1;
  }
return 0;
}

int insere_lista_inicio(LISTA *L, ALUNO aluno){
  if(L == NULL || lista_cheia(L) == 1){
    return -1;
  }
  for(int i = L -> qtd - 1; i >= 0; i--){
    L -> aluno[i+1] = L -> aluno[i];
  }

  L -> aluno[0] = aluno;
  L -> qtd = L -> qtd + 1;

return 0;  
}

int insere_lista_final(LISTA *L, ALUNO aluno){
  if(L == NULL || lista_cheia(L) == 1){
    return -1;
  }
  
  L -> aluno[L -> qtd] = aluno;
  L -> qtd = L -> qtd + 1;

return 0;
}

int insere_lista_ordenada(LISTA *L,ALUNO aluno){
  if(L == NULL || lista_cheia(L) == 1){
    return -1;
  }

  int i = 0;
  
  while(i < L -> qtd && L -> aluno[i].matricula <  aluno.matricula){ // determina em que posição o aluno está
    i++; 
  }
  
  for(int j = L -> qtd - 1; j >= i; j--){ // descola tudo pra direita
    L -> aluno[j+1] = L -> aluno[j];
  }
  
  L -> aluno[i] = aluno; // insere o aluno na posição encontrada
  L -> qtd = L -> qtd + 1;

return 0;
}

int consulta_lista_pos(LISTA *L, ALUNO *aluno, int pos){
  if(L == NULL || pos <= 0 || pos > L -> qtd){
    return -1;
  }
  
  *aluno = L -> aluno[pos-1];

return 0;  
}

int consulta_lista_matricula(LISTA *L, ALUNO aluno[], int matricula){
  if(L == NULL){
    return -1;
  }
  
  int i = 0;
  while(i < L-> qtd && L -> aluno[i].matricula != matricula){
    i++;
  }
  
  if(i == L -> qtd){
    return -1;
  }
  
  aluno[0] = L -> aluno[i];
return 0;  
}

int remove_lista_inicio(LISTA *L){
  if(L == NULL || L -> qtd == 0){
    return -1;
  }
  
  for(int i = 0; i < L -> qtd - 1; i++){
    L -> aluno[i] = L -> aluno[i + 1]; 
  }

  L-> qtd = L -> qtd - 1;
  
return 0;  
}

int remove_lista_final(LISTA *L){
   if (L == NULL || L -> qtd == 0){
     return -1;
   }
   
   L -> qtd = L -> qtd - 1;

return 0;   
} 

int remove_lista_matricula(LISTA* L, int matricula){
  if(L == NULL || L -> qtd == 0){
    return -1;
  }
  
  int i = 0;
  while(i < L -> qtd && L -> aluno[i].matricula != matricula){ // procura o indice do elemento com a matricula digitada
    i++;
  }
  
  if(i == L -> qtd){ //elemento nao encontrado
    return -1;
  }
  
  for(int j = i; j < L -> qtd - 1; j++){ // preenche da esquerda pra direita
    L -> aluno[j] = L -> aluno[j+1];
  }
  
  L -> qtd = L -> qtd - 1;

return 0;  
}

int libera_lista(LISTA* L){
  if(L == NULL){
    return -1;
  }
  free(L);
return 0; 
}



