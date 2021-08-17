/*
Nome: Euller Henrique Bandeira Oliveira
Matrícula: 11821BSI210
*/

//Questão 01

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
  else
  if(L -> head == NULL){
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

//WRAPPER_FILA.h

#ifndef WRAPPER_FILA_H_INCLUDED
#define WRAPPER_FILA_H_INCLUDED

#include "ALUNO.h"

typedef struct queue QUEUE;

//Create /free operations
QUEUE *queue_create();
int queue_free(QUEUE *Q);

//Query operations 
int queue_front(QUEUE *Q,ALUNO *aluno);

//Insert/delete operations
int queue_push(QUEUE *Q, ALUNO aluno);
int queue_pop(QUEUE *Q);

//Size operations
int queue_size(QUEUE *Q);
int queue_empty(QUEUE *Q);
int queue_full(QUEUE *Q);

#endif

//WRAPPER_FILA.c

#include "WRAPPER_FILA.h"
#include "LINKED_LIST.h"

#include <stdlib.h>

struct queue{
  LIST *L;
};

QUEUE* queue_create(){
  QUEUE *Q = NULL;
  Q = malloc(1 * sizeof(QUEUE));
  if(Q == NULL){
    return NULL;
  } 
  
  Q -> L = list_create();
  if(Q -> L == NULL){
   return NULL;
  } 
   
  return Q;
}

int queue_push(QUEUE *Q, ALUNO aluno){
  if(Q == NULL){
    return -1;
  }
  return list_push_back(Q -> L, aluno);
}

int queue_pop(QUEUE *Q){
  if(Q == NULL){
    return -1;
  }
  else{
    return list_pop_front(Q -> L);
  }
}

int queue_front(QUEUE *Q, ALUNO *aluno){
  if(Q == NULL){
    return -1;
  }
  else{
    return list_find_pos(Q -> L, 1, aluno);
  }
}

int queue_empty(QUEUE *Q){
  if(Q == NULL){
    return -1;
  }
  else{
    return list_void(Q -> L);
  }
}

int queue_full(QUEUE *Q){
  if(Q == NULL){
    return -1;
  }
  else{
      return list_full(Q -> L);
  }
}

int queue_size(QUEUE *Q){
  if(Q == NULL){
    return -1;
  }
  return list_size(Q -> L);
}

int queue_free(QUEUE *Q){
  if(Q == NULL){
    return -1;
  }
  
  free(Q);
  return list_free(Q -> L);

}


// MAIN_WRAPPER.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "WRAPPER_FILA.h"

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
  QUEUE *Q = NULL;
  ALUNO aluno;
 
  int loop = 0;
  int opcao  = 0;
  int bool = 0;
  
  while(loop == 0){
    
    printf("====================================================================================\n");
    printf("==============================Operações com uma FILA==================================\n");
    printf("====================================================================================\n");
    printf("1  - Criar FILA \n");
    printf("2  - Inserir aluno \n");
    printf("3  - Remover aluno \n");
    printf("4  - Acessar aluno\n");
    printf("5  - A FILA está cheia?\n");
    printf("6  - A FILA está vazia?\n");
    printf("7  - Descobrir o tamanho da FILA\n");
    printf("8  - Imprimir FILA\n");
    printf("9  - Destruir FILA\n");
    printf("10 - Fechar programa\n");
    printf("Digite a opção desejada: ");  
    scanf("%d",&opcao);
    printf("\n");
    
    if(opcao == 1){
      Q =  queue_create();  
      if(Q == NULL){
        printf("Erro!!!\n");
      }
      
      printf("FILA criada com sucesso\n\n");
      bool = 1;
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
            
        if(queue_push(Q,aluno) == -1){
          printf("Erro!!!\n");
          }
      }
    }
    else
    if(opcao == 3){
      if(bool == 0 || queue_pop(Q) == -1){
        printf("ERRO!!!\n");
      }
    }
    else
    if(opcao == 4){
      if(bool == 0 || queue_front(Q,&aluno) == -1){
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
        x = queue_full(Q);
        
        if(x == -1){
          printf("ERRO!!!\n");
        }
        else
        if(x == 1){
          printf("TRUE!!!\n");
        }
        else{
          printf("FALSE!!!\n");
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
        x = queue_empty(Q);
        
        if(x == -1){
          printf("ERRO!!!\n");
        }
        else
        if(x == 1){
          printf("TRUE!!!\n");
        }
        else{
          printf("FALSE!!!\n");
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
        qtd = queue_size(Q);
         
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
      
      if(bool == 0 || queue_free(Q) == -1){
        printf("ERRO!!!\n");
      }
      bool = 0;
    }
    else
    if(opcao == 9){
      exit(1);
    }
  }
          
return 0;
}

//QUESTÃO 02

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

//QUEUE_DINAMICA.h

#ifndef QUEUE_DINAMICA_INCLUDED
#define QUEUE_DINAMICA_INCLUDED

#include "ALUNO.h"
#include <stdlib.h>

typedef struct queue QUEUE;
typedef struct queue_node QNODE;

//Create /free operations
QUEUE *queue_create();
int queue_free(QUEUE *Q);

//Query operations 
int queue_front(QUEUE *Q,ALUNO *aluno);

//Insert/delete operations
int queue_push(QUEUE *Q, ALUNO aluno);
int queue_pop(QUEUE *Q);

//Size operations
int queue_size(QUEUE *Q);
int queue_empty(QUEUE *Q);
int queue_full(QUEUE *Q);

#endif

//QUEUE_DINAMICA.c

#include <stdio.h>
#include <stdlib.h>
#include "QUEUE_DINAMICA.h"

struct queue{
  QNODE *begin;
  QNODE *end;
  int size;
};

struct queue_node{
   ALUNO data;
   QNODE *next;
};

QUEUE* queue_create(){
  QUEUE *Q = NULL;
  Q = malloc(1 * sizeof(QUEUE));
  
  if(Q == NULL){
    return NULL;
  }
  else{
    Q -> begin = NULL;
    Q -> end = NULL;
    Q -> size = 0;
  }
  return Q;
}

int queue_front(QUEUE *Q,ALUNO *aluno){
  if(Q == NULL){
    return -1;
  }
  else{
    //If the queue is empty
    if(Q -> size == 0){
      return -1;
    }
    //If the queue is not empty
    else{
      *aluno = Q -> begin -> data;
    }
  }
}

int queue_free(QUEUE *Q){
  //If the pointer is equal to null
  if(Q == NULL){
    return -1;
  }
  //If the pointer is not equal null
  else{
    QNODE *NODE_PRESENT = NULL;
    
    while(Q -> begin != NULL){
      NODE_PRESENT = Q -> begin;// The first node becomes the node presente
      Q -> begin = Q -> begin -> next; // The next node becomes the first node
      free(NODE_PRESENT); // The memory of the node present is released
    }
    free(Q);// The memory of the queue is released
    return 0;
  }
}

int queue_push(QUEUE *Q, ALUNO aluno){
   if(Q == NULL){
     return -1;
   }
   else{
     QNODE *NODE  = NULL;
     NODE = malloc(1 * sizeof(QNODE));
     if(NODE == NULL){
       return -1;
     }
     else{
       NODE -> data = aluno;
       NODE -> next = NULL;
       
       //If the queue is empty
       if(Q -> size == 0){
         Q -> begin  = NODE;
         Q -> end = NODE;
         Q -> size = Q -> size + 1;
       }
       
       //If the queue is not empty
       else{
         Q -> end -> next = NODE; // the node is inserted into the node after the last node
         Q -> end = NODE; // The node becomes the last node
         Q -> size =  Q -> size + 1;
         return 0;
     }
   }
 }
}

int queue_pop(QUEUE *Q){
  if(Q == NULL){
    return -1;
  }
  else{
    if(Q -> size == 0){
      return -1;
    }
    else{
      
      QNODE *NODE_PRESENT  = NULL;
      NODE_PRESENT = Q -> begin; //The first node becomes the node present 
      
      Q -> begin = Q -> begin -> next; // The node after the begin node becomes the begin node
      
      //If the first node is equal to NULL
      if(Q -> begin == NULL){ 
        Q -> end = NULL;//The last node is equal to NULL
      }
      
      free(NODE_PRESENT); // The memory of the node present is released
      Q -> size = Q -> size - 1;
    }
  }
}


int queue_size(QUEUE *Q){
  if(Q == NULL){
    return -1;
  }
  else{
    return Q -> size;
  }
}

int queue_full(QUEUE *Q){
   if(Q == NULL){
     return -1;
   }
   else{
     return 0;
   }
}

int queue_empty(QUEUE *Q){
  if(Q == NULL){
    return -1;
  }
  else
  if(Q -> size == 0){
    return 1;
  }
  else{
    return 0;
  }
}


//MAIN_QUEUE_DINAMICA.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "QUEUE_DINAMICA.h"

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
  QUEUE *Q = NULL;
  ALUNO aluno;
 
  int loop = 0;
  int opcao  = 0;
  int bool = 0;
  
  while(loop == 0){
    
    printf("====================================================================================\n");
    printf("==============================Operações com uma FILA==================================\n");
    printf("====================================================================================\n");
    printf("1  - Criar FILA \n");
    printf("2  - Inserir aluno \n");
    printf("3  - Remover aluno \n");
    printf("4  - Acessar aluno\n");
    printf("5  - A FILA está cheia?\n");
    printf("6  - A FILA está vazia?\n");
    printf("7  - Descobrir o tamanho da FILA\n");
    printf("8  - Destruir FILA\n");
    printf("9 - Fechar programa\n");
    printf("Digite a opção desejada: ");  
    scanf("%d",&opcao);
    printf("\n");
    
    if(opcao == 1){
      Q =  queue_create();  
      if(Q == NULL){
        printf("Erro!!!\n");
      }
      
      printf("FILA criada com sucesso\n\n");
      bool = 1;
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
          
        if(queue_push(Q,aluno) == -1){
          printf("Erro!!!\n");
        }
      }
    }
    else
    if(opcao == 3){
      if(bool == 0 || queue_pop(Q) == -1){
        printf("ERRO!!!\n");
      }
    }
    else
    if(opcao == 4){
      if(bool == 0 || queue_front(Q,&aluno) == -1){
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
        x = queue_full(Q);
        
        if(x == -1){
          printf("ERRO!!!\n");
        }
        else
        if(x == 1){
          printf("TRUE!!!\n");
        }
        else{
          printf("FALSE!!!\n");
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
        x = queue_empty(Q);
        
        if(x == -1){
          printf("ERRO!!!\n");
        }
        else
        if(x == 1){
          printf("TRUE!!!\n");
        }
        else{
          printf("FALSE!!!\n");
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
        qtd = queue_size(Q);
         
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
      
      if(bool == 0 || queue_free(Q) == -1){
        printf("ERRO!!!\n");
      }
      bool = 0;
    }
    else
    if(opcao == 9){
      exit(1);
    }
  }
      
        
return 0;
}


//QUESTÃO 03

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

//QUEUE_MODIFICADA.h

#ifndef QUEUE_DINAMICA_INCLUDED
#define QUEUE_DINAMICA_INCLUDED

#include "ALUNO.h"
#include <stdlib.h>

typedef struct queue QUEUE;
typedef struct queue_node QNODE;

//Create /free operations
QUEUE *queue_create();
int queue_free(QUEUE *Q);

//Query operations 
int queue_front(QUEUE *Q,ALUNO *aluno);

//Insert/delete operations
int queue_push(QUEUE *Q, ALUNO aluno);
int queue_pop(QUEUE *Q);

//Size operations
int queue_size(QUEUE *Q);
int queue_empty(QUEUE *Q);
int queue_full(QUEUE *Q);

#endif

//QUEUE_MODIFICADA.c

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "QUEUE_MODIFICADA.h"

struct queue{
  ALUNO *data; 
  int front;
  int rear;
  int size;
  int initial_capacity;
  int last_capacity;
};

QUEUE *queue_create(int MAX){
  QUEUE *Q = NULL;
  Q  = malloc(1 * sizeof(QUEUE));
  if(Q == NULL || MAX < 0){
    return NULL;
  }
  else{
    
    Q -> data = malloc(MAX * sizeof(ALUNO));

    Q -> front = 0;
    Q -> rear = 0;
    Q -> initial_capacity = MAX;
    Q -> last_capacity = MAX;
    Q -> size = 0;
    return Q;
  }
}

int queue_free(QUEUE *Q){
  //If the pointer is equal to null
  if(Q == NULL){
    return -1;
  }
  //If the pointer is not equal null
  else{
    free(Q);
    return 0;
  }
}

int queue_front(QUEUE *Q, ALUNO *aluno){
  //If the pointer is equal to null
  if(Q == NULL){
    return -1;
  }
  //If the queue is empty
  else
  if(Q -> size == 0){
    return -1;
  }
  //If the queue is not empty
  else{  
    *aluno = Q -> data[Q -> front]; // *student receives the first element of the vector
  }
}

int queue_push(QUEUE *Q, ALUNO aluno){
  //If the pointer is equal to null
  if(Q == NULL){
    return -1;
  }
  
  else
  if( Q -> size == Q -> last_capacity){
    Q -> last_capacity = Q -> size + Q -> initial_capacity;
    
    Q -> data = realloc(Q -> data, Q -> last_capacity * sizeof(ALUNO));  
    if(Q -> data == NULL){
      return -1;
    }
    
    Q -> rear = Q -> size + 1;
    for(int i = 0; i < Q -> front; i++){
      Q -> data[Q -> rear] = Q -> data[i];
      Q -> rear = (Q -> rear + 1) % Q -> last_capacity;
    }// for
  }

  Q -> data[Q -> rear] = aluno; //The student is Inserted at the end of the queue
  Q -> rear = (Q -> rear + 1 )%Q -> last_capacity;  // The remainder of the division of Q -> rear + 1 by 
                                     // the maximum queue size will be the new value of Q -> rear
                                    
  Q -> size = Q -> size + 1; // The size of queue increases

}


int queue_pop(QUEUE *Q){
  //If the pointer is equal to null
  if(Q == NULL){
    return -1;
  }
  //If the queue is empty
  else
  if(Q -> size == 0){
    return -1;
  }
  //If the queue is not empty
  else{
    Q -> front = (Q -> front + 1)% Q -> last_capacity;// The remainder of the division of Q -> front + 1 by 
                                     // the maximum queue size will be the new value of Q -> front,
                                     //that is, the previous Q -> front is lost, and consequently removed
    
    Q -> size = Q -> size - 1; // The size of queue decreases
    return 0;
  }
}

int queue_compact(QUEUE *Q){
  
  if(Q == NULL){
    return -1;
  }
  
  Q -> last_capacity = ceil( (double)Q -> size / (double) Q -> initial_capacity) * (Q -> initial_capacity);
  
  if(Q -> last_capacity == 0){
    Q -> last_capacity = Q -> initial_capacity;
  }
  else
  if(Q -> front + 1 > Q -> last_capacity){
    int lim = Q -> rear;
    for(int i = Q -> front; i != lim; i = (i + 1) % Q -> last_capacity){
      Q -> data[Q -> rear] = Q -> data[i];
      Q -> rear = (Q -> rear + 1) % Q -> last_capacity;
    }
    Q -> front = lim;
  }
    
  Q -> data = realloc(Q -> data,  Q -> last_capacity * sizeof(ALUNO));
  
  if(Q -> data == NULL){
    return -1;
  }
  
return 0;  
}

int queue_size_present(QUEUE *Q){
  //If the pointer is equal to null
  if(Q == NULL){
    return -1;
  }
  //If the pointer is not equal to null
  else{
    return Q -> size;
  }
}

int queue_size_max(QUEUE *Q){
  if(Q == NULL){
    return - 1;
  }
  else{
    return Q -> last_capacity;
  }
}

int queue_empty(QUEUE *Q){
  //If the pointer is equal to null
  if(Q == NULL){
    return -1;
  }
  
  //If the queue is empty
  else
  if(Q -> size == 0){
    return 1;//true
  }
  //If the queue is not empty
  else{
    return 0;//false
  }
}

int queue_full(QUEUE *Q){
  //If the pointer is equal to null
  if(Q == NULL){
    return -1;
  }
  //If the queue is full
  else
  if(Q -> size == Q -> last_capacity){
    return 1;//true
  }  
  else{
    return 0;//false
  }
}


//MAIN_QUEUE_MODIFICADA.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "QUEUE_MODIFICADA.h"

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
  QUEUE *Q = NULL;
  ALUNO aluno;
  
  int opcao = 0;
  int loop = 0;
  int bool = 0;
  int MAX = 0; 
  
  printf("Digite o tamanho desejado da fila: ");
  scanf("%d",&MAX);
    
    while(loop == 0){
      
      printf("====================================================================================\n");
      printf("==============================Operações com uma FILA==================================\n");
      printf("====================================================================================\n");
      printf("1  - Criar FILA \n");
      printf("2  - Inserir aluno \n");
      printf("3  - Remover aluno \n");
      printf("4  - Acessar aluno\n");
      printf("5  - A FILA está cheia?\n");
      printf("6  - A FILA está vazia?\n");
      printf("7  - Descobrir o tamanho atual da fila\n");
      printf("8  - Descobrir o tamanho máximo da fila\n");
      printf("9  - Compactar fila \n");
      printf("10  - Destruir FILA\n");
      printf("11 - Fechar programa\n");
      printf("Digite a opção desejada: ");  
      scanf("%d",&opcao);
      printf("\n");
      
      if(opcao == 1){
        Q =  queue_create(MAX);  
        if(Q == NULL){
          printf("Erro!!!\n");
        }
        
        printf("FILA criada com sucesso\n\n");
        bool = 1;
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
                
        if(queue_push(Q,aluno) == -1){
          printf("Erro!!!\n");
          }
        }
      }
      else
      if(opcao == 3){
        if(bool == 0 || queue_pop(Q) == -1){
          printf("ERRO!!!\n");
        }
      }
      else
      if(opcao == 4){
        if(bool == 0 || queue_front(Q,&aluno) == -1){
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
          x = queue_full(Q);
          
          if(x == -1){
            printf("ERRO!!!\n");
          }
          else
          if(x == 1){
            printf("TRUE!!!\n");
          }
          else{
            printf("FALSE!!!\n");
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
          x = queue_empty(Q);
          
          if(x == -1){
            printf("ERRO!!!\n");
          }
          else
          if(x == 1){
            printf("TRUE!!!\n");
          }
          else{
            printf("FALSE!!!\n");
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
          qtd = queue_size_present(Q);
           
          if(qtd == -1){
            printf("ERRO!!!\n");
          }
          else{
            printf("Tamanho atual da pilha: %d \n",qtd);
          }
        }
        else{
          printf("ERRO!!!\n");
        }
      }
      else
      if(opcao == 8){
        if(bool == 1){
          int qtd = 0;
          qtd = queue_size_max(Q);
           
          if(qtd == -1){
            printf("ERRO!!!\n");
          }
          else{
            printf("Tamanho maximo da pilha: %d \n",qtd);
          }
        }
        else{
          printf("ERRO!!!\n");
        }
      }
      else
      if(opcao == 9){
        if(bool == 1){  
          if(queue_compact(Q) == -1){
            printf("ERRO!!!\n");
          }
        }
      }
      else
      if(opcao == 10){
        
        if(bool == 0 || queue_free(Q) == -1){
          printf("ERRO!!!\n");
        }
        bool = 0;
      }
      else
      if(opcao == 11){
        exit(1);
      }
    }
        
          
  return 0;
  }
  
