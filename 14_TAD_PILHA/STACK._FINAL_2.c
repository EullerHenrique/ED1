//Nome: Euller Henrique Bandeira Oliveira
//Matricula: 11821BSI210

//QUESTÃO 01

//ALUNO.h

#ifndef ALUNO_H_INCLUDED // if not def (se o ALUNO_H_INCLUDED não estiver definido)
#define ALUNO_H_INCLUDED // então o ALUNO_H_INCLUDED será definido

typedef struct{
  char nome[100];
  int matricula;
  float notas[4];
  int faltas;
}ALUNO;

#endif 

//LISTA.h

#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#define MAX 1000
#include "ALUNO.h"

typedef struct LISTA LISTA;

LISTA *criar_lista();

int tamanho_lista(LISTA* L);

int lista_cheia(LISTA *L);
int lista_vazia(LISTA *L);


int insere_lista_inicio(LISTA *L, ALUNO aluno);

int insere_lista_final(LISTA *L, ALUNO aluno);

int insere_lista_ordenada(LISTA *L, ALUNO aluno);


int remove_lista_inicio(LISTA *L);

int remove_lista_final(LISTA *L);

int remove_lista_matricula(LISTA* L, int matricula);


int consulta_lista_pos(LISTA *L, ALUNO *aluno, int pos);
int consulta_lista_matricula(LISTA *L, ALUNO *aluno, int matricula);

int libera_lista(LISTA* L); 

#endif

//LISTA.c

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

int lista_vazia(LISTA *L){
  if(L == NULL){
    return -1;
  }
  else
  if(L -> qtd == 0){
    return 1;
  }
  else{
    return 0;
  }
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
  
  for(int j = L -> qtd - 1; j >= i; j--){ // desloca tudo pra direita
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

int consulta_lista_matricula(LISTA *L, ALUNO *aluno, int matricula){
  if(L == NULL){
    return -1;
  }
  
  int i = 0;
  while(i < L-> qtd && L -> aluno[i].matricula != matricula){
    i++;
  }
  
  //Se a matricula não for encontrada
  if(i == L -> qtd){
    return -1;
  }
  
  *aluno = L -> aluno[i];
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

//WRAPPER_ESTATICO.h

#ifndef WRAPPER_ESTATICO_INCLUDED // if not def (se não estiver definido)
#define WRAPPER_ESTATICO_INCLUDED

#include "ALUNO.h"

typedef struct stack STACK;

STACK *stack_create();

int stack_push(STACK *S, ALUNO aluno);
int stack_pop(STACK *S);
int stack_top(STACK *S, ALUNO *aluno);

int stack_empty(STACK *S);
int stack_full(STACK *S);
int stack_size(STACK *S);

int stack_free(STACK *S);

#endif

//WRAPPER_ESTATICO.c

#include "WRAPPER_ESTATICO.h"
#include "LISTA.h"

#include <stdlib.h>

struct stack{
  LISTA *L;
};

STACK* stack_create(){
  STACK *S = NULL;
  S = malloc(1 * sizeof(STACK));
  if(S == NULL){
    return NULL;
  } 
  
  S -> L = criar_lista();
   if(S -> L == NULL){
     return NULL;
   } 
   
  return S;
}

int stack_push(STACK *S, ALUNO aluno){
  if(S == NULL){
    return -1;
  }
  return insere_lista_final(S -> L, aluno);
}

int stack_pop(STACK *S){
  if(S == NULL){
    return -1;
  }
  return remove_lista_final(S -> L);
}

int stack_top(STACK *S, ALUNO *aluno){
  if(S == NULL){
    return -1;
  }
  else{
    return consulta_lista_pos(S -> L, aluno, tamanho_lista(S -> L));
  }
}

int stack_empty(STACK *S){
  if(S == NULL){
    return -1;
  }
  return lista_vazia(S -> L);
}

int stack_size(STACK *S){
  if(S == NULL){
    return -1;
  }
  return tamanho_lista(S -> L);
}

int stack_free(STACK *S){
  if(S == NULL){
    return -1;
  }
  
  if(libera_lista(S -> L) == -1){
    return -1;
  }
  
  free(S);
}

//MAIN_WRAPPER_ESTATICO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "WRAPPER_ESTATICO.h"

void imprime_aluno(ALUNO *aluno){

  if(aluno == NULL){
    printf("Erro!!!\n");
    return;
  }
  
  printf("Nome: %s\n", aluno->nome);
  printf("Matricula: %d\n",aluno->matricula);
  printf("Nota da primeira prova: %f \n",aluno->notas[0]);
  printf("Nota da segunda  prova: %f \n",aluno->notas[1]);
  printf("Nota da terceira prova: %f \n",aluno->notas[2]);      
  printf("Nota da terceira prova: %f \n",aluno->notas[3]);   
  
}

int main(void){  
  STACK *S = NULL;
  ALUNO aluno;
 
  int loop = 0;
  int opcao  = 0;
  int bool = 0;
  
  while(loop == 0){
    
    printf("====================================================================================\n");
    printf("==============================Operações com uma pilha==================================\n");
    printf("====================================================================================\n");
    printf("1  - Criar pilha \n");
    printf("2  - Inserir aluno \n");
    printf("3  - Remover aluno \n");
    printf("4  - Acessar aluno\n");
    printf("5  - A pilha está vazia?\n");
    printf("6  - Descobrir o tamanho da pilha\n");
    printf("7  - Destruir pilha\n");
    printf("8  - Fechar programa\n");
    printf("Digite a opção desejada: ");  
    scanf("%d",&opcao);
    printf("\n");
    
    if(opcao == 1){
      if(bool == 1){
        printf("ERRO!!!\n");
      }
      else{
        S =  stack_create();  
        if(S == NULL){
          printf("Erro!!!\n");
        }else{
              
          printf("Pilha criada com sucesso\n\n");
          bool = 1;
        }
      }
    }
    else
    if(opcao == 2){
      if(bool == 0){
        printf("ERRO!!!\n");
      }
      else{
        getchar();
        printf("Nome: ");
        fgets(aluno.nome,sizeof(aluno.nome),stdin);
        aluno.nome[strcspn(aluno.nome,"\n")] = '\0';
            
        printf("Matrícula: ");
        scanf("%d",&aluno.matricula);
            
        printf("Nota da primeira prova : ");
        scanf("%f",&aluno.notas[0]);
            
        printf("Nota da segunda prova: ");
        scanf("%f",&aluno.notas[1]);
            
        printf("Nota da terceira prova: ");
        scanf("%f",&aluno.notas[2]);
            
        printf("Nota da quarta prova: ");
        scanf("%f",&aluno.notas[3]);
            
        printf("Quantidade de faltas: ");
        scanf("%d",&aluno.faltas);
        printf("\n");  
          
        if(stack_push(S,aluno) == -1){
        printf("Erro!!!\n");
        }
      }
    }
    else
    if(opcao == 3){
      if(bool == 0 || stack_pop(S) == -1){
        printf("ERRO!!!\n");
      }
    }
    else
    if(opcao == 4){
      if(bool == 0 || stack_top(S,&aluno) == -1){
        printf("ERRO!!!\n");
      }
      else{
        imprime_aluno(&aluno);
      }
    }
    else
    if(opcao == 5){
      if(bool == 1){
        int x = 0;
        x = stack_empty(S);
        
        if(x == -1){
          printf("ERRO!!!\n");
        }
        else
        if(x == 1){
          printf("True\n");
        }
        else{
          printf("False\n");
        }
      }
      else{
        printf("ERRO!!!\n");
      }
    }
    else
    if(opcao == 6){
      if(bool == 1){
        int qtd = 0;
        qtd = stack_size(S);
         
        if(qtd == -1){
          printf("ERRO!!!\n");
        }
        else{
          printf("Tamanho da pilha: %d \n",qtd);
        }
      }
      else{
        printf("ERRO!!!\n");
      }
    }
    else
    if(opcao == 7){
      
      if(bool == 0 || stack_free(S) == -1){
        printf("ERRO!!!\n");
      }
      bool = 0;
    }
    else
    if(opcao == 8){
      exit(1);
    }
  }
      
        
return 0;
}

//Questão 02

//ALUNO.h

#ifndef ALUNO_H_INCLUDED // if not def (se o ALUNO_H_INCLUDED não estiver definido)
#define ALUNO_H_INCLUDED // então o ALUNO_H_INCLUDED será definido

typedef struct{
  char nome[100];
  int matricula;
  float notas[4];
  int faltas;
}ALUNO;

#endif 

//LINKED_LIST.h

#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

#include "ALUNO.h"

typedef struct list LIST;
typedef struct list_node LIST_NODE;


LIST *list_create();

int list_push_front(LIST *L, ALUNO aluno);
int list_push_back(LIST *L, ALUNO aluno);
int list_insert(LIST *L, int pos, ALUNO aluno);
int list_push_ordered(LIST *L, ALUNO aluno);

int list_pop_front(LIST *L);
int list_pop_back(LIST *L);
int list_pop_mat(LIST *L, int mat);
int list_pop_pos(LIST *L, int pos, ALUNO aluno);

int list_find_pos(LIST*L, int pos, ALUNO *aluno);
int list_find_mat(LIST *L, int mat, ALUNO *aluno);

int list_full(LIST *L); 
int list_void(LIST *L);

int list_print(LIST *L);

int list_free(LIST *L);
int list_size(LIST *L);

#endif

//LINKED_LIST.c

#include <stdlib.h>
#include <stdio.h>
#include "LINKED_LIST.h"

struct list{
  LIST_NODE *head;
};

struct list_node{
  ALUNO data;
  LIST_NODE *next;
};

LIST *list_create(){
  LIST *L = NULL;
  
  L = malloc(1 * sizeof(LIST));
  if(L == NULL){
    return NULL;
  }
  
  L -> head = NULL;

return L;
}

int list_push_front(LIST *L, ALUNO aluno){
  if(L == NULL){
    return -1;
  }
  
  LIST_NODE *NODE = NULL;
  NODE = malloc(1 * sizeof(LIST_NODE));
  
  if(NODE == NULL){
    return -1;
  }
    
  NODE -> data = aluno;
  
  // Se a lista for vazia
  if(L -> head == NULL){
    NODE -> next = NULL;
    
    L -> head = NODE;//O nó crido é inserido no primeiro nó
  }
  
  //Se a lista não for vazia
  else{
    NODE -> next = L -> head;  // O primeiro nó se torna o próximo nó
    
    L -> head = NODE; // O nó criado é inserido no primeiro nó
return 0;  
}
}

int list_push_back(LIST *L, ALUNO aluno){
  if(L == NULL){
    return -1;
  }
  
  LIST_NODE *NODE = NULL;
  NODE = malloc(1 * sizeof(LIST_NODE));
  
  if(NODE == NULL){
    return -1;
  }
  
  NODE -> data = aluno;
  
  // Se a lista for vazia
  if(L -> head == NULL){
    NODE -> next = NULL;
    L -> head = NODE; // O nó criado é inserido no primeiro nó
  } 
  
  // Se a lista não for vazia
  else{
    LIST_NODE *NODE_PRESENT = NULL;
    LIST_NODE *NODE_PREVIOUS = NULL;
    
    NODE_PRESENT = L -> head; // O primeiro nó se torna o nó atual
    
    while(NODE_PRESENT != NULL){
      NODE_PREVIOUS = NODE_PRESENT; // O nó atual se torna o nó anterior
      NODE_PRESENT = NODE_PRESENT -> next; // O próximo nó se torna o nó atual
    }
    
    NODE -> next = NULL;
    NODE_PREVIOUS -> next = NODE; // O nó anterior deixa de apontar para o nó atual(QUE NO CASO É NULL) e começa a apontar para o nó criado
  } 
  return 0;
}

int list_insert(LIST *L, int pos, ALUNO aluno){
  if(L == NULL || pos <= 0){
    return -1;
  }
  
  LIST_NODE *NODE = NULL;
  NODE = malloc(1 * sizeof(LIST));
  
  if(NODE == NULL){
    return -1;
  }
  
  NODE -> data = aluno;
  
  //Se a lista for vazia
  if(L -> head == NULL){
    NODE -> next = NULL; 
    L -> head = NODE; // O nó criado é inserido no primeiro nó
  }
  
  //Se a lista não for vazia
  else{
    LIST_NODE *NODE_PRESENT = NULL;
    LIST_NODE *NODE_PREVIOUS = NULL;
    
    NODE_PRESENT = L -> head; // O primeiro nó se torna o nó atual
    
    int i = 1;
    while(NODE_PRESENT != NULL && i < pos){
      NODE_PREVIOUS = NODE_PRESENT; // O nó atual se torna o nó anterior
      NODE_PRESENT = NODE_PRESENT -> next; // O próximo nó se torna o nó atual
      i++;
    }
    
    //Se posição não for encontrada
    if(NODE_PRESENT == NULL){
      return -1;
    }
    
    //Se a posição for encontrada
    else{
      
      // Se a posição encontrada for a primeira
      if(NODE_PRESENT == L -> head){
        NODE -> next = L -> head; // O primeiro nó se torna o próximo nó
        L -> head = NODE; /// O nó criado é inserido no primeiro nó 
      }
      
      // Se a posição encontrada não for a primeira
      else{
        NODE -> next = NODE_PRESENT; // O nó atual se torna o próximo nó
        NODE_PREVIOUS -> next = NODE; /// O nó anterior deixa de apontar para o nó atual e começa a apontar para o nó criado
      }  
    }
  }
  return 0;
}

int list_push_ordered(LIST *L, ALUNO aluno){
  if(L == NULL){
    return -1;
  }
  
  LIST_NODE *NODE= NULL;
  NODE = malloc(1 * sizeof(LIST_NODE));
  
  NODE -> data = aluno;
  
  //Se a lista for vazia
  if(L -> head == NULL){
    NODE -> next = NULL;
    L -> head = NODE; // O nó criado é inserido no primeiro nó
  }
  
  //Se a lista não for vazia
  else{
    LIST_NODE *NODE_PRESENT = NULL;
    LIST_NODE *NODE_PREVIOUS = NULL;
    
    NODE_PRESENT = L -> head; // O primeiro nó se torna o nó atual
    
    while(NODE_PRESENT != NULL && NODE_PRESENT -> data.matricula < aluno.matricula){
      NODE_PREVIOUS = NODE_PRESENT; // O nó atual se torna o nó anterior
      NODE_PRESENT = NODE_PRESENT -> next; // O próximo nó se torna o nó atual
    }
    
    // Se a matricula tiver que ser inserida no primeiro nó
    if(NODE_PRESENT == L -> head){
      NODE -> next = L -> head;// O primeiro nó se torna o próximo nó
      L -> head = NODE;//O nó criado é inserido no primeiro nó
    }
    
    // Se a matricula tiver que ser inserida no meio
    else{
      NODE -> next = NODE_PRESENT;//O nó atual se torna o próximo nó 
      NODE_PREVIOUS -> next = NODE;//O nó anterior deixa de apontar para o nó atual e começa a apontar para o nó criado
    }
    return 0;
  }
}

int list_pop_front(LIST *L){
  if(L == NULL){
    return -1;
  }
  
  //Se a lista for vazia
  else
  if(L -> head == NULL){
    return -1;
  }
  
  //Se a lista não for vazia
  else{
    LIST_NODE *NODE_FRONT = NULL;
    NODE_FRONT = L -> head; // O primeiro nó se torna o nó inicia
    
    L -> head = NODE_FRONT -> next; // O próximo nó se torna o primeiro nó
    
    free(NODE_FRONT); // A memória do nó inicial é liberada
    
  }
  return 0;
}

int list_pop_back(LIST *L){
  if(L == NULL){
    return -1;
  }
  
  //Se a lista for vazia
  else
  if(L -> head == NULL){
    return -1;
  }
  
  //Se a lista não for vazia
  else{
    LIST_NODE *NODE_PREVIOUS = NULL;
    LIST_NODE *NODE_PRESENT = NULL;
  
    NODE_PRESENT = L -> head; // O primeiro nó se torna o nó inicial
    
    while(NODE_PRESENT -> next != NULL){
      NODE_PREVIOUS = NODE_PRESENT; // O nó atual se torna o nó anterior
      NODE_PRESENT = NODE_PRESENT -> next; // O próximo nó se torna o nó atual
    }
    
    //Se a lista tiver somente um nó
    if(NODE_PRESENT == L -> head){
      L -> head = NODE_PRESENT -> next;// O próximo nó (NULL) se torna o primeiro nó
      free(NODE_PRESENT);
    }
    //Se a lista não tiver somente um nó
    else{
      NODE_PREVIOUS -> next = NODE_PRESENT -> next; // O nó anterior deixa de apontar para o nó atual e começa a apontar para NULL
      free(NODE_PRESENT); // Libera a memória do nó atual
    }
  }
  return 0;
}

int list_pop_mat(LIST *L, int mat){
  if(L == NULL){
    return -1;
  }
  
  //Se a lista for vazia
  else
  if(L -> head == NULL){
    return -1;
  }
  
  //Se a lista nãao for vazia
  else{
    
    LIST_NODE *NODE_PRESENT = NULL;
    LIST_NODE *NODE_PREVIOUS = NULL;
    
    NODE_PRESENT = L -> head; // O primeiro nó se torna o nó atual
    
    while(NODE_PRESENT != NULL && NODE_PRESENT -> data.matricula != mat){
      NODE_PREVIOUS = NODE_PRESENT; // O nó atual se torna o nó anterior
      NODE_PRESENT = NODE_PRESENT -> next; // O próximo nó se torna o nó atual
    }
    
    //Se a matricula não for encontrada
    if(NODE_PRESENT == NULL){
      return -1;
    }
    
    //Se a matricula for encontrada
    else{
      
      //Se a matricula estiver no primeiro nó
      if(NODE_PRESENT == L-> head){
        L -> head = NODE_PRESENT -> next;// O próximo nó se torna o primeiro nó
        free(NODE_PRESENT);
      }
      
      // Se a matricula não estiver no primeiro nó
      else{
        NODE_PREVIOUS -> next = NODE_PRESENT -> next; // O nó anterior deixa de apontar para o nó atual e começa a apontar para o próximo nó
        free(NODE_PRESENT); // Libera a memoria do nó atual
      }
    }
    return 0;
  }
}

int list_pop_pos(LIST *L, int pos, ALUNO aluno){
  if(L == NULL || pos <= 0){
    return -1;
  }
  
  //Se a lista for vazia
  else
  if(L -> head == NULL){
    return -1;
  }
  
  //Se a lista não for vazia
  else{
    LIST_NODE *NODE_PRESENT = NULL;
    LIST_NODE *NODE_PREVIOUS = NULL;
    
    NODE_PRESENT = L -> head; // O primeiro nó se torna o nó atual
    
    int i = 1;
    while(NODE_PRESENT != NULL && i < pos){
      NODE_PREVIOUS = NODE_PRESENT; // O nó atual se torna o nó anterior
      NODE_PRESENT = NODE_PRESENT -> next; // O próximo nó se torna o nó atual
      i++;
    }
    
    //Se a posição não for encontrada
    if(NODE_PRESENT == NULL){
      return -1;
    } 
    
    //Se a posição foi encontrada
    else{
      
      //Se a posição for a primeira
      if(NODE_PRESENT ==  L -> head){
        L -> head = NODE_PRESENT -> next; // O próximo nó se torna o primeiro nó
        free(NODE_PRESENT); // Libera a memória do nó atual
      }
      
      //Se a posição não for a primeira
      else{
        NODE_PREVIOUS -> next = NODE_PRESENT -> next;
        free(NODE_PRESENT); // Libera a memoria do nó atual
      }
    }
  } 
  return 0;
}

int list_find_pos(LIST*L, int pos, ALUNO *aluno){
  
  //Se a lista for vazia
  if(L == NULL || pos <= 0){
    return -1;
  }
  
  //Se a lista não for vazia
  else{
    
    //Se a posição desejada for a primeira
    if(pos == 1){
      *aluno = L -> head -> data;
    }
    
    //Se a posição desejada não for a primeira
    else{
      
      LIST_NODE *NODE_PRESENT = NULL;
      NODE_PRESENT = L -> head; // O primeiro nó se torna o nó atual
      
      int i = 1;
      while(NODE_PRESENT != NULL && i < pos){
        NODE_PRESENT = NODE_PRESENT -> next;// O proximo nó se torna o nó atual
        i++;
      }
    
      //Se a posição não for encontrada
      if(NODE_PRESENT == NULL){
        return -1;
      }
    
      //Se a posição for encontrada
      else{
        *aluno = NODE_PRESENT -> data;
        return 0;
      }
    }
  }
}

int list_find_mat(LIST *L, int mat, ALUNO *aluno){
  if(L == NULL){
    return -1;
  }
  
  //Se a lista for vazia
  else
  if(L -> head == NULL){
    return -1;
  }
  
  //Se a lista não for vazia
  else{
    LIST_NODE *NODE_PRESENT = NULL;
    NODE_PRESENT = L -> head; // O primeiro nó se torna o nó atual
    
    while(NODE_PRESENT != NULL && NODE_PRESENT -> data.matricula != mat){
      NODE_PRESENT = NODE_PRESENT -> next; // O próximo nó se torna o nó atual
    }
    
    //Se a matricula não for encontrada
    if(NODE_PRESENT == NULL){
      return -1;
    }
    
    //Se a matricula for encontrada
    else{
      *aluno = NODE_PRESENT -> data; 
      return 0;
    }
  }
}

int list_full(LIST *L){ // A lista nunca estará cheia porque ela está sendo alocada dinamicamente
  if(L == NULL){
    return -1;
  }
  return 0; // Retorna false
}

int list_void(LIST *L){
  if(L == NULL){
    return -1;
  }
  else
  if(L -> head == NULL){
    return 1; // retorna true
  }
  else{
    return 0; // retorna false
  }
}

int list_print(LIST *L){
  if(L == NULL){
    return -1;
  }
  
  // Se a lista for vazia
  else
  if(L -> head == NULL){
    return -1;
  }
  
  LIST_NODE *NODE_PRESENT = NULL;
  NODE_PRESENT = L -> head; // O primeiro nó se torna o nó atual
  
  int i = 1;
  while(NODE_PRESENT != NULL){
    printf("Aluno %d\n\n",i);
    printf("Nome: %s\n",NODE_PRESENT -> data.nome);
    printf("Matrícula: %d \n",NODE_PRESENT -> data.matricula);
    printf("Nota da primeira prova %f\n",NODE_PRESENT -> data.notas[0]);
    printf("Nota da segunda prova %f\n",NODE_PRESENT -> data.notas[1]);
    printf("Nota da terceira prova %f\n",NODE_PRESENT -> data.notas[2]);
    printf("Nota da quarta prova %f\n",NODE_PRESENT -> data.notas[3]);
    printf("Faltas: %d\n",NODE_PRESENT -> data.faltas);
    printf("\n\n");
    i++;
    NODE_PRESENT = NODE_PRESENT -> next; // O próximo nó se torna o nó atual
  }
return 0;
}

int list_free(LIST *L){
  if(L == NULL){
    return -1;
  }
  
  LIST_NODE *NODE_PRESENT = NULL;
  
  NODE_PRESENT = L -> head;// O primeiro nó se torna o nó atual
  
  while(NODE_PRESENT != NULL){
    L -> head = NODE_PRESENT -> next;// O próximo nó se torna o primeiro nó 
    free(NODE_PRESENT);// Libera a memoria do nó atual
    NODE_PRESENT = L -> head;// O primeiro nó se torna o nó atual
  }
  free(L);// Libera a memória da lista
  return 0;
}

int list_size(LIST *L){
  if(L == NULL){
    return -1;
  }
  
  int i = 0;
  
  //Se a lista for vazia
  if(L -> head == NULL){
    return i;
  }
  
  //Se a lista não for vazia
  else{
    LIST_NODE *NODE_PRESENT = NULL;
    NODE_PRESENT = L -> head; // O primeiro nó se torna o nó atual 
    
    while(NODE_PRESENT != NULL){
      NODE_PRESENT = NODE_PRESENT -> next;// O próximo nó se torna o nó atual
      i++;
    }
    return i;
  }  
}

//MAIN_LINKED_LIST.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "D_LINKED_LIST.h"

void imprime_aluno(ALUNO *aluno){

  if(aluno == NULL){
    printf("Erro!!!\n");
    return;
  }
  
  printf("Nome: %s\n", aluno->nome);
  printf("Matricula: %d\n",aluno->matricula);
  printf("Nota da primeira prova: %f \n",aluno->notas[0]);
  printf("Nota da segunda  prova: %f \n",aluno->notas[1]);
  printf("Nota da terceira prova: %f \n",aluno->notas[2]);      
  printf("Nota da terceira prova: %f \n",aluno->notas[3]);   
  
}

int main(void){  
  LIST *L = NULL;
  ALUNO aluno;
  
  int opcao = 0;
  int loop = 0;  
  int bool = 0;

  while(loop == 0){
    
    printf("====================================================================================\n");
    printf("==============================Operações com listas==================================\n");
    printf("====================================================================================\n");
    printf("1  - Criar lista\n");
    printf("2  - Inserir aluno no começo \n");
    printf("3  - Inserir aluno no final \n");
    printf("4  - Inserir aluno ordenamente de acordo com a matrícula \n");
    printf("5  - Inserir aluno de acordo com a posição \n");
    printf("6  - Remover aluno do começo da lista\n");
    printf("7  - Remover aluno do final da lista\n");
    printf("8  - Remover aluno de acordo com a posição\n");
    printf("9  - Remover aluno de acordo com a matricula\n");
    printf("10 - Descobrir o tamanho atual da lista\n");
    printf("11 - Descobrir posição de determinada matricula\n");
    printf("12 - A lista está cheia?\n");
    printf("13 - A lista está vazia?\n");
    printf("14 - Acessar os dados de determinado aluno na lista de acordo com a sua posição\n");
    printf("15 - Acessar os dados de determinado aluno na lista de acordo com a sua matrícula\n");
    printf("16 - Acessar os dados do primeiro aluno\n");
    printf("17 - Acessar os dados do último aluno\n");
    printf("18 - Imprimir lista\n");
    printf("19 - Destruir lista\n");
    printf("20 - Fechar programa\n");
    printf("Digite a opção desejada: ");  
    scanf("%d",&opcao);
    printf("\n");
    
    if(opcao == 1){
      if(bool == 1){
        printf("Erro!!!\n");
      }
      else{
        L =  list_create();  
        if(L == NULL){
          printf("Erro!!!\n");
        }
        bool = 1;
      }
    }
    else
    if(opcao == 2){
      if(bool == 0){
        printf("ERRO!!!\n");
      }else{
        
      
        getchar();
        printf("Nome: ");
        fgets(aluno.nome,sizeof(aluno.nome),stdin);
        aluno.nome[strcspn(aluno.nome,"\n")] = '\0';
            
        printf("Matrícula: ");
        scanf("%d",&aluno.matricula);
            
        printf("Nota da primeira prova : ");
        scanf("%f",&aluno.notas[0]);
            
        printf("Nota da segunda prova: ");
        scanf("%f",&aluno.notas[1]);
            
        printf("Nota da terceira prova: ");
        scanf("%f",&aluno.notas[2]);
            
        printf("Nota da quarta prova: ");
        scanf("%f",&aluno.notas[3]);
            
        printf("Quantidade de faltas: ");
        scanf("%d",&aluno.faltas);
        printf("\n");  
            
        if(list_push_front(L,aluno) == -1){
          printf("Erro!!!\n");
          }
        }
    }        
    else
    if(opcao == 3){
      
      if(bool == 0){
        printf("ERRO!!!\n");
      }else{
        
      
       
        getchar();
        printf("Nome: ");
        fgets(aluno.nome,sizeof(aluno.nome),stdin);
        aluno.nome[strcspn(aluno.nome,"\n")] = '\0';
          
        printf("Matrícula: ");
        scanf("%d",&aluno.matricula);
          
        printf("Nota da primeira prova : ");
        scanf("%f",&aluno.notas[0]);
          
        printf("Nota da segunda prova: ");
        scanf("%f",&aluno.notas[1]);
      
        printf("Nota da terceira prova: ");
        scanf("%f",&aluno.notas[2]);
          
        printf("Nota da quarta prova: ");
        scanf("%f",&aluno.notas[3]);
          
        printf("Quantidade de faltas: ");
        scanf("%d",&aluno.faltas);
        printf("\n");
          
        if(list_push_back(L,aluno) == -1){
          printf("Erro!!!\n");
        }
      }
    }
    else
    if(opcao == 4){
      if(bool == 0){
        printf("ERRO!!!\n");
      }else{
        
      
        getchar();
        printf("Nome: ");
        fgets(aluno.nome,sizeof(aluno.nome),stdin);
        aluno.nome[strcspn(aluno.nome,"\n")] = '\0';
          
        printf("Matrícula: ");
        scanf("%d",&aluno.matricula);
          
        printf("Nota da primeira prova : ");
        scanf("%f",&aluno.notas[0]);
          
        printf("Nota da segunda prova: ");
        scanf("%f",&aluno.notas[1]);
          
        printf("Nota da terceira prova: ");
        scanf("%f",&aluno.notas[2]);
          
        printf("Nota da quarta prova: ");
        scanf("%f",&aluno.notas[3]);
          
        printf("Quantidade de faltas: ");
        scanf("%d",&aluno.faltas);
        printf("\n");
          
        if(list_push_ordered(L,aluno) == -1){
          printf("Erro!!!\n");
        }
      }
    }
    else
    if(opcao == 5){
      if(bool == 0){
        printf("ERRO!!!\n");
      }else{
        
        int pos = 0;
        
        printf("Digite a posição desejada: ");
        scanf("%d", &pos);
        printf("\n");
        
        getchar();
        printf("Nome: ");
        fgets(aluno.nome,sizeof(aluno.nome),stdin);
        aluno.nome[strcspn(aluno.nome,"\n")] = '\0';
          
        printf("Matrícula: ");
        scanf("%d",&aluno.matricula);
          
        printf("Nota da primeira prova : ");
        scanf("%f",&aluno.notas[0]);
          
        printf("Nota da segunda prova: ");
        scanf("%f",&aluno.notas[1]);
          
        printf("Nota da terceira prova: ");
        scanf("%f",&aluno.notas[2]);
          
        printf("Nota da quarta prova: ");
        scanf("%f",&aluno.notas[3]);
          
        printf("Quantidade de faltas: ");
        scanf("%d",&aluno.faltas);
        printf("\n");
        
        
        if(list_insert(L, pos, aluno) == -1){
          printf("ERRO!!!\n");
        }
      }
    }
    else
    if(opcao == 6){  
        if(bool == 0 || list_pop_front(L) == -1){
          printf("Erro!!!\n");
        }
    }
    else
    if(opcao == 7){
        if(bool == 0 || list_pop_back(L) == -1){
          printf("Erro!!!\n");
        }
    }
    else
    if(opcao == 8){ 
      if(bool == 0){
        printf("ERRO!!!\n");
      } 
      else{
        int pos = 0;
        printf("Digite a posição do aluno a ser removido: ");
        scanf("%d",&pos);
        
        if(list_erase(L, pos) == -1){
          printf("Erro!!!\n");
        }
      }
    }
    else
    if(opcao == 9){  
        if(bool == 0){
          printf("ERRO!!!\n");
        }
        else{      
          int matricula = 0;
          int pos = 0;
          printf("Digite a matricula do aluno a ser removido: ");
          scanf("%d",&matricula);
          
          if(getpos(L,matricula, &pos) == -1){
            printf("ERRO!!!\n");
          }else{
          
            if(list_erase(L, pos) == -1){
              printf("Erro!!!\n");
            }
        }
      }
    }
    else
    if(opcao == 10){
    
      if(bool == 0){
        printf("ERRO!!!\n");
      }else{
        int x = 0;
        x = list_size(L);
        
        if(x == -1){
          printf("Erro!!!\n");
        }
        else{
        printf("Tamanho da lista = %d \n",x);
        }
      }
    }
    else
    if(opcao == 11){
        
        if(bool == 0){
          printf("ERRO!!!\n");
        }
        else{
          int matricula = 0;
          int pos = 0;
          
          printf("Digite a matricula: ");
          scanf("%d",&matricula);
          
          if(getpos(L, matricula, &pos) == -1){
            printf("ERRO!!!\n");
          }
          else{
            printf("A posição da matrícula %d é %d \n",matricula,pos);
          }
        }
    }
    else
    if(opcao == 12){
      if(bool == 0){
        printf("ERRO!!!\n");
      }
      else{  
        int x = 0;
        x = list_full(L);
        
        if(x == -1){
          printf("Erro!!!\n");
        }
        else
        if(x == 0){
          printf("False\n");
        } 
      }
    } 
    else
    if(opcao == 13){
      if(bool == 0){
        printf("ERRO!!!\n");
      }
      else{
        int x = 0;
        x = list_void(L);
        
        if(x == -1){
          printf("Erro!!!\n");
        }
        else
        if(x == 1){
          printf("True\n");
        }
        else
        if(x == 0){
          printf("False\n");
        }
      } 
    }   
    else
    if(opcao == 14){
        if(bool == 0){
          printf("ERRO!!!\n");
        }
        else{
          int x = 0;
          
          printf("Digite a posição do aluno a ser consultado: \n");
          scanf("%d",&x);
          
          if(list_find_pos(L, x, &aluno) == -1){
            printf("Erro!!!\n");
          }
          else{
            imprime_aluno(&aluno);
          } 
        }
    } 
    else
    if(opcao == 15){
        if(bool == 0){
          printf("ERRO!!!\n");
        }
        else{
          int matricula = 0;
          
          printf("Digite a matricula do aluno a ser consultado: \n");
          scanf("%d",&matricula);
          
          if(list_find_mat(L,matricula,&aluno) == -1){
            printf("Erro!!!\n");
          } 
          else{
            imprime_aluno(&aluno);
          } 
        }
   }
  else
  if(opcao == 16){
    if(bool == 0 || list_front(L, &aluno) == -1){
      printf("ERRO!!!\n");
    }
    else{
      imprime_aluno(&aluno);
    }
  }
  else
  if(opcao == 17){
    if(bool == 0 || list_front(L, &aluno) == -1){
      printf("ERRO!!!\n");
    }
    else{
      imprime_aluno(&aluno);
    }    
  }
  else
  if(opcao == 18){
    if(bool == 0 || list_print(L) == -1){
      printf("ERRO!!!\n");
    }
  }
  else
  if(opcao == 19){
    if(bool == 0 || list_free(L) == -1){
      printf("Erro!!!\n");
    }
    bool = 0;
  }
  else
  if(opcao == 20){
    exit(1);
  }
  
}// fecha o while

return 0;
}

//QUESTÃO 03

//PARENTESES.h

#ifndef PARENTESES_H_INCLUDED
#define PARENTESES_H_INCLUDED

#include <stdlib.h>

typedef struct stack STACK;

STACK *stack_create();

int stack_push(STACK *S, char sequencia);
int stack_pop(STACK *S);
int stack_top(STACK *S, char *sequencia);

int stack_empty(STACK *S);
int stack_full(STACK *S);
int stack_size(STACK *S);

int stack_free(STACK *S);

#endif

//PARENTESES.c

#include <stdio.h>
#include "PARENTESES.h"
#define MAX 50

struct stack {
  char data[MAX];
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

int stack_push(STACK *S, char sequencia){
  if(S == NULL){
    return -1;
  }
  else{
    
    //Se a pilha estiver cheia
    if(S -> size == MAX){
      return -1;
    }
    
    //Se a pilha não estiver cheia
    else{
      S -> data[S -> size] = sequencia;
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
    //Se a pilha estiver vazia
    if(S -> size == 0){
        return -1;
    }
    //Se a pilha não estiver vazia
    else{
      S -> size =  S -> size - 1;
      return 0;
    }
  }
}

int stack_top(STACK *S, char *sequencia){
  if(S == NULL){
    return -1;
  }
  else{
    //Se a pilha estiver vazia
    if(S -> size == 0){
      return -1;
    }
    else{
      *sequencia = S -> data[S -> size -1];
    }
  }
}

int stack_empty(STACK *S){
  if(S == NULL){
    return -1;
  }
  else{
    //Se a pilha for vazia
    if(S -> size == 0){
      return 1;
    }
    //Se a pilha não for vazia
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
    //Se a pilha estiver cheia
    if(S -> size == MAX){
      return 1;
    }
    //Se a pilha não estiver cheia
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

//MAIN_PARENTESES.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PARENTESES.h"

int verifica(char sequencia[]){
  STACK *S = NULL;
  
  S = stack_create(); 
  if(S == NULL){
    printf("ERRO!!!\n");
  }
  
  char c = sequencia[0];
  for(int i = 0; c!= '\0'; i++){
    c = sequencia[i];
    if(c == ')'){
      if(stack_empty(S) == 1){
      return 0;    
      }
      else{
        stack_top(S,&c);
        stack_pop(S);
    
        if(c != '('){
          return 0;
        }
      }
    }
    else
    if(c == ']'){
      if(stack_empty(S) == 1){
        return 0;
      }
      else{
        stack_top(S,&c);
        stack_pop(S);
      
        if(c != '['){
          return 0;
        }
      }
    }
    else{
      stack_push(S, sequencia[i]);
    }  
  }
  
  if(stack_empty(S) == 1){
    return 1;
  }
  else{
    return 0;
  }
      
}

int main(void){  
  char sequencia[50];
  
  printf("Digite a sequência de parêntes e colchetes: ");
  fgets(sequencia,sizeof(sequencia),stdin);
  sequencia[strcspn(sequencia,"\n")] = '\0';
  
  if(verifica(sequencia) == 1){
    printf("SEQUENCIA CORRETA\n");
  }
  else{
    printf("SEQUENCIA ERRADA\n");
  }
    
return 0;
}

//Questão 04

//STACK_DINAMICO.h

#ifndef STACK_DINAMICO 
#define STACK_DINAMICO

#include <stdlib.h>
#include "ALUNO.h"

typedef struct dslinkedstack STACK;
typedef struct dsnode DSNODE;

STACK *stack_create();

int stack_push(STACK *S, ALUNO aluno);
int stack_pop(STACK *S);
int stack_top(STACK *S, ALUNO *aluno);

int stack_empty(STACK *S);
int stack_full(STACK *S);
int stack_size(STACK *S);
int stack_print(STACK *S);

int stack_free(STACK *S);

#endif

//STACK_DINAMICO.c

#include <stdio.h>
#include "STACK_DINAMICO.h"

struct dslinkedstack{
  DSNODE *top;
  int size;
};

struct dsnode{
   ALUNO data;
   DSNODE *next;
};

STACK * stack_create(){
  STACK *S = NULL;
  S = malloc(1 * sizeof(STACK));
  
  if(S == NULL){
    return NULL;
  }
  
  else{
     S -> top = NULL;
     S -> size = 0;
     return S;
  } 
}

int stack_push(STACK *S, ALUNO aluno){
  if(S == NULL){
    return -1;
  }
  else{
    DSNODE *NODE = NULL;
    
    NODE = malloc(1 * sizeof(DSNODE));
    if(NODE == NULL){
      return -1;
    }
    else{
    
      NODE -> data = aluno;
      NODE -> next = S -> top; // O topo se torna o próximo nó
      
      S -> top = NODE; // O nó se torna o topo
      S -> size = S -> size + 1;
      return 0;
    }
  }
}

int stack_pop(STACK *S){
  if(S == NULL){
    return -1;
  }
  
  //Se a pilha for vazia
  else
  if(S -> top == NULL){
    return -1;
  }
  S -> top = S -> top -> next; // O proxímo nó se torna o topo
  S -> size = S -> size - 1;
}

int stack_top(STACK *S, ALUNO *aluno){
  if(S == NULL){
    return -1;
  }
  else{
    //Se a pilha for vazia
    if(S -> top == NULL){
      return -1;
    }
    else{
      *aluno = S -> top -> data;
    }
  }
}

int stack_free(STACK *S){
  if(S == NULL){
    return -1;
  }
  else{
    DSNODE *NODE_PRESENT = NULL;
    NODE_PRESENT = S -> top;
    
    while(NODE_PRESENT != NULL){
      NODE_PRESENT = S -> top;
      S -> top = NODE_PRESENT -> next;
      free(NODE_PRESENT);
    }
    free(S);
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
    return 0;
  }
}

int stack_print(STACK *S){
  if(S == NULL){
    return -1;
  }
    
  DSNODE *NODE_PRESENT = NULL;
  NODE_PRESENT = S -> top;
    
  int i = 1;
  while(NODE_PRESENT != NULL){
    printf("Aluno %d\n\n",i);
    printf("Nome: %s\n",NODE_PRESENT -> data.nome);
    printf("Matrícula: %d \n",NODE_PRESENT -> data.matricula);
    printf("Nota da primeira prova %f\n",NODE_PRESENT -> data.notas[0]);
    printf("Nota da segunda prova %f\n",NODE_PRESENT -> data.notas[1]);
    printf("Nota da terceira prova %f\n",NODE_PRESENT -> data.notas[2]);
    printf("Nota da quarta prova %f\n",NODE_PRESENT -> data.notas[3]);
    printf("Faltas: %d\n",NODE_PRESENT -> data.faltas);
    printf("\n\n");
    i++;
    NODE_PRESENT = NODE_PRESENT -> next; // o próximo nó se torna o nó atual
  }
  return 0;
}

//MAIN_STACK_DINAMICO.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "STACK_DINAMICO.h"

void imprime_aluno(ALUNO *aluno){

  if(aluno == NULL){
    printf("Erro!!!\n");
    return;
  }
  
  printf("Nome: %s\n", aluno->nome);
  printf("Matricula: %d\n",aluno->matricula);
  printf("Nota da primeira prova: %f \n",aluno->notas[0]);
  printf("Nota da segunda  prova: %f \n",aluno->notas[1]);
  printf("Nota da terceira prova: %f \n",aluno->notas[2]);      
  printf("Nota da terceira prova: %f \n",aluno->notas[3]);   
  
}

int main(void){  
  STACK *S = NULL;
  ALUNO aluno;
 
  int loop = 0;
  int opcao  = 0;
  int bool = 0;
  
  while(loop == 0){
    
    printf("====================================================================================\n");
    printf("==============================Operações com uma pilha==================================\n");
    printf("====================================================================================\n");
    printf("1  - Criar pilha \n");
    printf("2  - Inserir aluno \n");
    printf("3  - Remover aluno \n");
    printf("4  - Acessar aluno\n");
    printf("5  - A pilha está cheia?\n");
    printf("6  - A pilha está vazia?\n");
    printf("7  - Descobrir o tamanho da pilha\n");
    printf("8  - Imprimir pilha\n");
    printf("9  - Destruir pilha\n");
    printf("10 - Fechar programa\n");
    printf("Digite a opção desejada: ");  
    scanf("%d",&opcao);
    printf("\n");
    
    if(opcao == 1){
      S =  stack_create();  
      if(S == NULL){
        printf("Erro!!!\n");
      }
      
      printf("Pilha criada com sucesso\n\n");
      bool = 1;
    }
    else
    if(opcao == 2){
      getchar();
      printf("Nome: ");
      fgets(aluno.nome,sizeof(aluno.nome),stdin);
      aluno.nome[strcspn(aluno.nome,"\n")] = '\0';
          
      printf("Matrícula: ");
      scanf("%d",&aluno.matricula);
          
      printf("Nota da primeira prova : ");
      scanf("%f",&aluno.notas[0]);
          
      printf("Nota da segunda prova: ");
      scanf("%f",&aluno.notas[1]);
          
      printf("Nota da terceira prova: ");
      scanf("%f",&aluno.notas[2]);
          
      printf("Nota da quarta prova: ");
      scanf("%f",&aluno.notas[3]);
          
      printf("Quantidade de faltas: ");
      scanf("%d",&aluno.faltas);
      printf("\n");  
          
      if(bool == 0 || stack_push(S,aluno) == -1){
        printf("Erro!!!\n");
        }
    }
    else
    if(opcao == 3){
      if(bool == 0 || stack_pop(S) == -1){
        printf("ERRO!!!\n");
      }
    }
    else
    if(opcao == 4){
      if(bool == 0 || stack_top(S,&aluno) == -1){
        printf("ERRO!!!\n");
      }
      else{
        imprime_aluno(&aluno);
      }
    }
    else
    if(opcao == 5){
      if(bool == 1){
        int x = 0;
        x = stack_full(S);
        
        if(x == -1){
          printf("ERRO!!!\n");
        }
        else
        if(x == 1){
          printf("True\n");
        }
        else{
          printf("False\n");
        }
      }
      else{
        printf("ERRO!!!\n");
      }
    }
    else
    if(opcao == 6){
      if(bool == 1){
        int x = 0;
        x = stack_empty(S);
        
        if(x == -1){
          printf("ERRO!!!\n");
        }
        else
        if(x == 1){
          printf("True\n");
        }
        else{
          printf("False\n");
        }
      }
      else{
        printf("ERRO!!!\n");
      }
    }
    else
    if(opcao == 7){
      if(bool == 1){
        int qtd = 0;
        qtd = stack_size(S);
         
        if(qtd == -1){
          printf("ERRO!!!\n");
        }
        else{
          printf("Tamanho da pilha: %d \n",qtd);
        }
      }
      else{
        printf("ERRO!!!\n");
      }
    }
    else
    if(opcao == 8){
      if(bool == 0 || stack_print(S) == -1){
        printf("ERRO!!!\n");
      }
    }
    else
    if(opcao == 9){
      
      if(bool == 0 || stack_free(S) == -1){
        printf("ERRO!!!\n");
      }
      bool = 0;
    }
    else
    if(opcao == 10){
      exit(1);
    }
  }
      
        
return 0;
}

//QUESTÃO 5

//STACK_CHAR.h
#ifndef STACK_CHAR_H_INCLUDED
#define STACK_CHAR_H_INCLUDED

#include <stdlib.h>

typedef struct stack STACK;

STACK *stack_create();

int stack_push(STACK *S, char x);
int stack_pop(STACK *S);
int stack_top(STACK *S, char *x);

int stack_empty(STACK *S);
int stack_full(STACK *S);
int stack_size(STACK *S);
int stack_print(STACK *S);

int stack_free(STACK *S);

#endif

//STACK_CHAR.c
#include <stdio.h>
#include "STACK_CHAR.h"
#define MAX 100

struct stack{
  char data[MAX];
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

int stack_push(STACK *S, char x){
  if(S == NULL){
    return -1;
  }
  else{
    
    //Se a piha estiver cheia
    if(S -> size == MAX){
      return -1;
    }
    
    //Se a pilha não estiver cheia
    else{
      S -> data[S -> size] = x;//Insere o caractere no topo
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
    
    //Se a pilha estiver vazia
    if(S -> size == 0){
        return -1;
    }
    
    //Se a pilha não estiver vazia
    else{
      S -> size =  S -> size - 1;// Não é póssivel mais acessar tal posição, por isso seu elemento é "removido".
      return 0;
    }
  }
}

int stack_top(STACK *S, char *x){
  if(S == NULL){
    return -1;
  }
  else{
    
    //Se a pilha estiver vazia
    if(S -> size == 0){
      return -1;
    }
    else{
      *x = S -> data[S -> size - 1];
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

//STACK_POS_FIX.c

#include <stdlib.h> 
#include <string.h>
#include <stdio.h>
#include "STACK_CHAR.h"

char *infixa_para_pos_fixa(char *inf){
  STACK *S = NULL;
  S = stack_create();

  int n = 0;
  n = strlen(inf);
  
  char *POSF = NULL; 
  POSF = malloc((n + 1) *sizeof(char)); // PQ N+1?
  
  char x;
  
  for(int i = 0, j = 0; inf[i] != '\0';i++){
    switch (inf[i]) {
      case '(': stack_push(S,inf[i]);
                break;
      case ')': stack_top(S,&x);
                stack_pop(S);
                while(x!= '('){
                  POSF[j] = x;
                  j++;
                  stack_top(S,&x);
                  stack_pop(S);
                }
                break;
      case '+':
      case '-': stack_top(S,&x);
                stack_pop(S);
                while(x != '('){
                  POSF[j] = x;
                  j++;
                  stack_top(S,&x);
                  stack_pop(S);
                }
                  
                stack_push(S, x);
                stack_push(S, inf[i]);
                break;
      case '*':
      case '/': stack_top(S,&x);
                stack_pop(S);
                while(x!= '(' && x!= '+' && x!= '-'){
                  POSF[j] = x;
                  j++;
                  
                  stack_top(S,&x);
                  stack_pop(S);
                  }
                  
                  stack_push(S, x);
                  stack_push(S, inf[i]);
                  break;
      default: POSF[j] = inf[i];
               j++;                
    }
  }
  return POSF;
}

int main(void){  
  char inf[50];
  
  printf("Digite a sequência infixa: ");
  fgets(inf,sizeof(inf),stdin);
  inf[strcspn(inf,"\n")] = '\0';
  
  char *POSF = NULL;
  POSF = infixa_para_pos_fixa(inf);
  
  printf("A sequência pós fixa é: %s", POSF); 
  printf("\n\n");
   
return 0;
}