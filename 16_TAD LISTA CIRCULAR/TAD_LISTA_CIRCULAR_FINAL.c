/*
Nome : Euller Henrique Bandeira Olivera
Matrícula: 11821BSI210
*/

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

//LIST_CIRCULAR.h

#ifndef LIST_CIRCULAR_H_INCLUDED
#define LIST_CICULAR_H_INCLUDED

#include "ALUNO.h"

typedef struct circ_list LIST;
typedef struct clist_node CLIST_NODE;


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

int list_free(LIST *L);
int list_size(LIST *L);

int return_next(LIST *L, ALUNO *aluno);

#endif

//LIST_CIRCULAR.c

#include <stdlib.h>
#include <stdio.h>
#include "LIST_CIRCULAR.h"

struct circ_list{
  CLIST_NODE *end;
  CLIST_NODE *end_initial;
  int size;
};

struct clist_node{
  ALUNO data;
  CLIST_NODE *next;
};

LIST *list_create(){ // TÁ CERTA
  LIST *L = NULL;
  
  L = malloc(1 * sizeof(LIST));
  if(L == NULL){
    return NULL;
  }
  
  L -> end = NULL;
  L -> end_initial = NULL;
  
return L;
}

int list_push_front(LIST *L, ALUNO aluno){ // TÁ CERTA
  if(L == NULL){
    return -1;
  }
  
  CLIST_NODE *NODE = NULL;
  NODE = malloc(1 * sizeof(CLIST_NODE));
  
  if(NODE == NULL){
    return -1;
  }
  else{
    
    NODE -> data = aluno;
    
    // Se a lista for vazia
    if(L -> end == NULL){
      NODE -> next =  NODE;  
      L -> end = NODE;
      L -> end_initial = L -> end;
    }
    //Se a lista não for vazia
    else{
      NODE -> next = L -> end -> next;  // O primeiro nó se torna o próximo nó
      L -> end -> next = NODE; // O nó criado se torna o primeiro nó
    }
    L -> size = L -> size + 1;
  }
return 0;  
  
}

int list_push_back(LIST *L, ALUNO aluno){
  if(L == NULL){
    return -1;
  }
  
  CLIST_NODE *NODE = NULL;
  NODE = malloc(1 * sizeof(CLIST_NODE));
  
  if(NODE == NULL){
    return -1;
  }
  else{
    NODE -> data = aluno;
    
    // Se a lista for vazia
    if(L -> end == NULL){
      NODE -> next = NODE;
      L -> end = NODE;
      L -> end_initial = L -> end;
    }
     
    // Se a lista não for vazia
    else{
      NODE -> next = L -> end -> next; // O primeiro nó se torna o próximo nó 
      L -> end -> next = NODE;
      L -> end = NODE;
    }
    L -> size = L -> size + 1;
  }
  return 0;
}

int list_insert(LIST *L, int pos, ALUNO aluno){
  if(L == NULL || pos <= 0){
    return -1;
  }
  
  CLIST_NODE *NODE = NULL;
  NODE = malloc(1 * sizeof(CLIST_NODE));
  
  if(NODE == NULL){
    return -1;
  }
  
  NODE -> data = aluno;
  
  //Se a lista for vazia
  if(L -> end == NULL){
    NODE -> next = NODE;
    L -> end = NODE; 
    L -> end_initial = L -> end;
  }
  
  //Se a lista não for vazia
  else{
    CLIST_NODE *NODE_PRESENT = NULL;
    CLIST_NODE *NODE_PREVIOUS = NULL;
    
    NODE_PRESENT = L -> end -> next; // O primeiro nó se torna o nó atual
    
    int i = 1;
    while(NODE_PRESENT -> next != L -> end -> next && i < pos){
      NODE_PREVIOUS = NODE_PRESENT; // O nó atual se torna o nó anterior
      NODE_PRESENT = NODE_PRESENT -> next; // O próximo nó se torna o nó atual
      i++;
    }
    
    //Se posição não for encontrada
    if(i != pos){
      return -1;
    }
    
    //Se a posição for encontrada
    else{  
      NODE -> next = NODE_PRESENT; // O nó atual se torna o próximo nó
      NODE_PREVIOUS -> next = NODE; /// O nó anterior deixa de apontar para o nó atual e começa a apontar para o nó criado
    }  
  }
  L -> size = L -> size + 1;  
  return 0;
}

int list_push_ordered(LIST *L, ALUNO aluno){
  if(L == NULL){
    return -1;
  }
  
  CLIST_NODE *NODE = NULL;
  NODE = malloc(1 * sizeof(CLIST_NODE));
  
  NODE -> data = aluno;
  
  //Se a lista for vazia
  if(L -> end == NULL){
    NODE -> next = NODE;
    L -> end  = NODE; 
    L -> size  = L -> size + 1; 
  }
  else 
  if(L -> end -> next-> data.matricula > aluno.matricula){
    free(NODE);
    list_push_front(L, aluno);
  }
  else
  if(L -> end -> data.matricula < aluno.matricula){
    free(NODE);
    list_push_back(L, aluno);
  }
  else{
    CLIST_NODE *NODE_PRESENT = NULL;
    CLIST_NODE *NODE_PREVIOUS = NULL;
    
    NODE_PRESENT = L -> end -> next; // O primeiro nó se torna o nó atual
    
    while(NODE_PRESENT -> data.matricula < aluno.matricula && NODE_PRESENT -> next != L -> end -> next){
      NODE_PREVIOUS = NODE_PRESENT; // O nó atual se torna o nó anterior
      NODE_PRESENT = NODE_PRESENT -> next; // O próximo nó se torna o nó atual
    }
    
    if(NODE_PRESENT == L -> end -> next){
      return -1;
    }
    else{  
      NODE -> next = NODE_PRESENT;//O nó atual se torna o próximo nó 
      NODE_PREVIOUS -> next = NODE;//O nó anterior deixa de apontar para o nó atual e começa a apontar para o nó criado    
    }
    L -> size  = L -> size + 1; 
  } 
    return 0;
}

int list_pop_front(LIST *L){
  if(L == NULL || L -> size <= 0){
    return -1;
  }
  
  //Se a lista for vazia
  else
  if(L -> end == NULL){
    return -1;
  }
  
  //Se a lista não for vazia
  else{
    CLIST_NODE *NODE_FRONT = NULL;
    
    NODE_FRONT = L -> end -> next; // O primeiro nó se torna o nó iniciaL
    
    L -> end -> next = NODE_FRONT -> next; 
    L -> end = NODE_FRONT -> next;
    
    L -> end_initial = L -> end;
    
    free(NODE_FRONT); // A memória do nó inicial é liberada
    L -> size = L -> size - 1;
  }
  
  return 0;
}

int list_pop_back(LIST *L){
  if(L == NULL || L -> size <= 0){
    return -1;
  }
  
  // Se a lista for vazia
  else
  if(L -> end == NULL){
    return -1;
  }
  
  // Se a lista não for vazia
  else{    
    CLIST_NODE *NODE_PRESENT = NULL;
    
    NODE_PRESENT = L -> end -> next;
    while(NODE_PRESENT -> next != L -> end){
      NODE_PRESENT = NODE_PRESENT -> next;
    }

    if(NODE_PRESENT == L -> end){
      L -> end = NULL;
      L -> end_initial = L -> end; // O próximo nó (NULL) se torna o primeiro nó
      free(NODE_PRESENT);
      L -> size = L -> size - 1;
    }
    else{
      NODE_PRESENT -> next = L -> end -> next;
      free(L -> end); // Libera a memória do nó atual
      L -> end = NODE_PRESENT;
      L -> end_initial = L -> end;  
      
      L -> size = L -> size - 1;
    }
     
  }
  return 0;
}

int list_pop_mat(LIST *L, int mat){
  if(L == NULL || L -> size <= 0){
    return -1;
  }
  else
  if(L -> end == NULL){
    return -1;
  }
  else{
    
    CLIST_NODE *NODE_PREVIOUS = NULL;
    CLIST_NODE *NODE_PRESENT = NULL;
    
    NODE_PRESENT = L -> end -> next; // O primeiro nó se torna o nó atual
    
    while(NODE_PRESENT -> data.matricula != mat && NODE_PRESENT -> next != L -> end -> next){
      NODE_PREVIOUS = NODE_PRESENT; // O nó atual se torna o nó anterior
      NODE_PRESENT = NODE_PRESENT -> next; // O próximo nó se torna o nó atual
    }

    if(NODE_PRESENT == L -> end -> next){
      list_pop_front(L);
      return 0;
    }
    else
    if(NODE_PRESENT == L -> end){
      list_pop_back(L);
      return 0;
    }
    else
    if(NODE_PRESENT == L -> end -> next){
      return -1;
    }
    else{
        NODE_PREVIOUS -> next = NODE_PRESENT -> next; 
        free(NODE_PRESENT); // Libera a memoria do nó atual
        L -> size = L -> size - 1;
        return 0;
    }
  }
}


int list_pop_pos(LIST *L, int pos){
  if(L == NULL || pos <= 0 || L -> size <= 0 || pos > L -> size){
    return -1;
  }
  else
  if(L -> end == NULL){
    return -1;
  }
  else
  if(L -> size == 1){
    list_pop_front(L);
    return 0;
  }
  else
  if(pos == L -> size) {
    list_pop_back(L);
    return 0;
  }
  else{
    CLIST_NODE *NODE_PRESENT = NULL;
    CLIST_NODE *NODE_PREVIOUS = NULL;
    
    NODE_PRESENT = L -> end -> next; // O primeiro nó se torna o nó atual
    
    int i = 1;
    while(NODE_PRESENT -> next != L -> end -> next && i < pos){
      NODE_PREVIOUS = NODE_PRESENT; // O nó atual se torna o nó anterior
      NODE_PRESENT = NODE_PRESENT -> next; // O próximo nó se torna o nó atual
      i++;
    }
  
    if(NODE_PRESENT == L -> end -> next){
      return -1;
    }
    else{
        NODE_PREVIOUS -> next = NODE_PRESENT -> next; 
        free(NODE_PRESENT); // Libera a memoria do nó atual
        L -> size = L -> size - 1;
        return 0;
    }
  }
} 
  
int list_find_pos(LIST*L, int pos, ALUNO *aluno){
  
  //Se a lista for vazia
  if(L == NULL || pos <= 0 || L -> size == 0){
    return -1;
  }
  else
  if(L -> end == NULL){
    return -1;
  }
  else{

    //Se a posição desejada for a primeira
    if(pos == 1){
      *aluno = L -> end -> next -> data;
    }
  
    else{
      CLIST_NODE *NODE_PRESENT = NULL;
      NODE_PRESENT = L -> end -> next;
      
      int i = 1;
      while(NODE_PRESENT -> next != L -> end -> next  && i < pos){
        NODE_PRESENT = NODE_PRESENT -> next;
        i++;
      }
      
       if(i != pos){
        return -1;
       }
       else{
         *aluno = NODE_PRESENT -> data;
       }      
    }
  }

}

int list_find_mat(LIST *L, int mat, ALUNO *aluno){
  if(L == NULL || L -> size == 0){
    return -1;
  }
  
  //Se a lista não for vazia
  else{
    CLIST_NODE *NODE_PRESENT = NULL;
    NODE_PRESENT = L -> end -> next; // O primeiro nó se torna o nó atual
    
    while(NODE_PRESENT -> next != L -> end -> next  && NODE_PRESENT -> data.matricula != mat){
      NODE_PRESENT = NODE_PRESENT -> next; // O próximo nó se torna o nó atual
    }
    
    //Se a matricula não for encontrada
    if(NODE_PRESENT -> data.matricula != mat){
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
  if(L -> end == NULL){
    return 1; // retorna true
  }
  else{
    return 0; // retorna false
  }
}

int list_size(LIST *L){
  if(L == NULL){
    return -1;
  }
  else{
    return L -> size;
  }  
}

int list_free(LIST *L){
  if(L == NULL){
    return -1;
  }
  
  CLIST_NODE *NODE_PRESENT = NULL;
  
  NODE_PRESENT = L -> end -> next;// O primeiro nó se torna o nó atual
  
  while(NODE_PRESENT -> next != L -> end -> next){
    L -> end -> next = NODE_PRESENT -> next;// O próximo nó se torna o primeiro nó 
    free(NODE_PRESENT);// Libera a memoria do nó atual
    NODE_PRESENT = L -> end -> next;// O primeiro nó se torna o nó atual
  }
  free(L);// Libera a memória da lista
  return 0;
}


int return_next(LIST *L, ALUNO *aluno){
  if(L == NULL){
    return -1;
  }
  
  //Se a lista for vazia
  else
  if(L -> end == NULL || L -> end_initial == NULL){
    return -1;
  }
  
  // Se a lista não for vazia
  else{
    
    if(L -> size == 1){
      *aluno = L -> end_initial -> data;
    }
    else
    if(L -> end_initial != L -> end){
      *aluno = L -> end_initial -> data;
      L -> end_initial = L -> end_initial -> next;
    }
    else
    if(L -> end_initial == L -> end){
      *aluno = L -> end_initial -> data;
      L -> end_initial = L -> end_initial -> next;
    }
  }
    
    return 0;
}

//QUESTÃO 02

//MAIN_LIST_CIRCULAR.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "LIST_CIRCULAR.h"

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
  
  L =  list_create();  
  if(L == NULL){
    printf("Erro!!!\n");
  }
  while(loop == 0){
    
    printf("===============================================================================================\n");
    printf("==============================Operações com listas circulares==================================\n");
    printf("===============================================================================================\n");
    printf("1  - Inserir aluno no começo \n");
    printf("2  - Inserir aluno no final \n");
    printf("3  - Inserir aluno ordenamente de acordo com a matrícula \n");
    printf("4  - Inserir aluno de acordo com a posição \n");
    printf("5  - Remover aluno do começo da lista\n");
    printf("6  - Remover aluno do final da lista\n");
    printf("7  - Remover aluno de acordo com a sua matricula\n");
    printf("8  - Remover aluno de acordo com a sua posição\n");
    printf("9  - Descobrir o tamanho atual da lista\n");
    printf("10 - A lista está cheia?\n");
    printf("11 - A lista está vazia?\n");
    printf("12 - Acessar os dados de determinado aluno na lista de acordo com a sua posição\n");
    printf("13 - Acessar os dados de determinado aluno na lista de acordo com a sua matrícula\n");
    printf("14 - Destruir lista\n");
    printf("15 - Fechar programa\n");
    printf("16 - Retornar o próximo nó\n");
    printf("Digite a opção desejada: ");  
    scanf("%d",&opcao);
    printf("\n");
    
    if(opcao == 1){
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
        
      if(list_push_back(L,aluno) == -1){
        printf("Erro!!!\n");
      }
    }
    
    else
    if(opcao == 3){
  
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
    else
    if(opcao == 4){
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
    else
    if(opcao == 5){  
        if(list_pop_front(L) == -1){
          printf("Erro!!!\n");
        }
    }
    else
    if(opcao == 6){
        if(list_pop_back(L) == -1){
          printf("Erro!!!\n");
        }
    }
    else
    if(opcao == 7){  
        int matricula = 0;
        printf("Digite a matricula do aluno a ser removido: ");
        scanf("%d",&matricula);
        
        if(list_pop_mat(L, matricula) == -1){
          printf("Erro!!!\n");
        }
    }
    else
    if(opcao == 8){  
        int pos = 0;
        printf("Digite a posição do aluno a ser removido: ");
        scanf("%d",&pos);
        
        if(list_pop_pos(L, pos) == -1){
          printf("Erro!!!\n");
        }
    }
    else
    if(opcao == 9){
        
        int x = 0;
        x = list_size(L);
        
        if(x == -1){
          printf("Erro!!!\n");
        }
        else{
        printf("Tamanho da lista = %d \n",x);
        }
    }
    else
    if(opcao == 10){
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
    else
    if(opcao == 11){
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
    else
    if(opcao == 12){
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
    else
    if(opcao == 13){
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
  else
  if(opcao == 14){
    if(list_free(L) == -1){
      printf("Erro!!!\n");
    }
  }
  else
  if(opcao == 15){
    exit(1);
  }
  else
  if(opcao == 16){
    if(return_next(L, &aluno) == -1){
      printf("ERRO!!!\n");
    }
    else{
        imprime_aluno(&aluno);
    }
  }
  
}// fecha o while

return 0;
}


