#include <stdio.h>
#include <stdlib.h>
#include "D_LINKED_LIST_2.h"

struct dlinkedList{
  DLNODE *begin;
  DLNODE *end;
  int size;
};

struct dlnode{
   ALUNO data;
   DLNODE *next;
   DLNODE *prev;
};

LIST* list_create(){
  LIST *L = NULL;
  L = malloc(1 * sizeof(LIST)); 
  
  if(L == NULL){
    return NULL;
  }
  
  L -> begin = NULL; 
  L -> end = NULL;
   
  L -> size = 0;  
  return L;
}

int list_push_front(LIST *L, ALUNO aluno){
  if(L == NULL){
    return -1;
  }
  
  DLNODE *NODE = NULL; 
  NODE = malloc(1 * sizeof(DLNODE)); // Cria o nó
  
  if(NODE == NULL){
    return -1;
  }
  
  NODE -> data = aluno; // O nó recebe os dados do aluno
  
  NODE -> prev = NULL; // O nó anterior fica vazio
  NODE -> next = L -> begin; // O primeiro nó se torna o próximo
  
  //Se a lista for vazia
  if(L -> begin == NULL){
    L -> begin = NODE; // O nó criado é inserido no primeiro elemento
    L -> end = NODE; // O nó criado é inserido no último elemento
  }
  
  // Se a lista não for vazia 
  else{
    L -> begin -> prev = NODE; // O nó criado é inserido no nó anterior ao primeiro nó ( no caso o nó anterior ao primeiro nó era NULL))
    L -> begin = NODE; // O nó criado se torna o primeiro nó
  }
  L -> size = L -> size + 1;
  return 0;
}

int list_push_back(LIST *L, ALUNO aluno){
  if(L == NULL){
    return -1;
  }
  
  DLNODE *NODE = NULL;
  NODE = malloc(1 * sizeof(DLNODE));
  if(NODE == NULL){
    return -1;
  }
  
  NODE -> data = aluno; // O nó criado recebe os dados do aluno
  
  NODE -> prev = L -> end; // O último nó se torna o nó anterior
  NODE -> next = NULL; // O próximo nó fica vazio
  
  // Se a lista for vazia
  if(L -> begin == NULL){
    L -> begin = NODE;
    L -> end = NODE;
  }
  
  //Se a lista não for vazia
  else{
    L -> end -> next = NODE; // O nó criado é inserido no nó posterior ao último nó
    L -> end = NODE; // O nó criado se torna o último nó
  }
  L -> size = L -> size + 1;
  return 0;
}
  
int list_insert(LIST *L, int pos, ALUNO aluno){
  if(L == NULL || pos <= 0){
    return -1;
  }
  
  DLNODE *NODE = NULL;
  NODE =  malloc(1 * sizeof(DLNODE));
  
  NODE -> data = aluno;
  
  // Se a lista for vazia
  if(L -> begin == NULL){
    
    NODE -> prev = NULL;
    NODE -> next = NULL; 
    
    L -> begin = NODE;
    L -> end = NODE;
  }
  
  //Se a lista não for vazia
  else{
    
    // Se a posição desejada for a primeira
    if(pos == 1){
      NODE -> prev = NULL;
      NODE -> next = L -> begin; // O primeiro nó se torna o próximo
      
      L -> begin -> prev = NODE; // O nó criado é inserido no nó anterior ao primeiro nó ( no caso o nó anterior ao primeiro nó era NULL))
      L -> begin = NODE; // O nó criado se torna o primeiro nó
    }
    
    // Se a posição desejada for a última
    else
    if(pos == L -> size){
      
      NODE -> prev = L -> end; // O último nó se torna o nó anterior
      NODE -> next = NULL;
  
      L -> end -> next = NODE; // O nó criado é inserido no nó posterior ao último nó
      L -> end = NODE; // O nó criado se torna o último nó  
    }
    
    //Se a posição desejada estiver no meio
    else{
      
      DLNODE *NODE_PRESENT = NULL;
      NODE_PRESENT = L -> begin; // O primeiro nó se torna o nó atual
    
      int i = 1;
      // Este laço irá percorrer toda a lista enquanto a posição não for encontrada
      while(NODE_PRESENT != NULL && i < pos){
        NODE_PRESENT = NODE_PRESENT -> next; // O próximo nó se torna o nó atual
        i++;
      }
      
      // Se a posição nao for encontrada
      if(NODE_PRESENT == NULL){
        return -1;
      }
      
      //Se a posição for encontrada
      else{
        
        NODE -> prev = NODE_PRESENT -> prev; // O nó anterior do nó atual se torna o nó anterior ao nó criado
        NODE -> next = NODE_PRESENT; // O nó atual se torna o próximo nó do nó criado
        
        NODE_PRESENT -> prev -> next = NODE; // O nó anterior ao nó atual deixa de apontar para o próprio nó atual e começa a apontar para o nó criado      
      }
  }
}
L -> size = L -> size + 1;
return 0;
}

int list_push_ordered(LIST *L, ALUNO aluno){
  if(L == NULL){
    return -1;
  }
  
  DLNODE *NODE = NULL;
  NODE = malloc(1 * sizeof(DLNODE));
  
  NODE -> data = aluno;
  
  // Se a lista for fazia
  if(L -> begin == NULL){  
    
    NODE -> prev = NULL;
    NODE -> next = NULL;
    
    L -> begin = NODE;
    L -> end = NODE;
  }
  
  // Se a lista não estiver vazia
  else{
    
    DLNODE *NODE_PRESENT = NULL;
    NODE_PRESENT = L -> begin;
    
    while(NODE_PRESENT != NULL && NODE_PRESENT -> data.matricula < aluno.matricula){
      NODE_PRESENT = NODE_PRESENT -> next;
    }
  
    // Se a matricula itiver que ser inserida no primeiro nó
    if(NODE_PRESENT == L -> begin){
      
      NODE -> prev = NULL;
      NODE -> next = L -> begin;
    
      L -> begin -> prev = NODE; 
      L -> begin = NODE;
    }
    
    // Se a matricula tiver que ser inserida no último nó
    else
    if(NODE_PRESENT == NULL){
      NODE -> prev = L -> end;
      NODE -> next = NULL;
      
      L -> end -> next = NODE;
      L -> end = NODE;
    }
    
    // Se a matricula tiver que ser inserida no meio
    else{
      NODE -> prev = NODE_PRESENT -> prev;
      NODE -> next = NODE_PRESENT;
        
      NODE_PRESENT -> prev -> next = NODE;
    }
  }
  L -> size = L -> size + 1;
  return 0;
}
  
int list_pop_front(LIST *L){
  if(L == NULL){
    return -1;
  }
  
  // Se a lista for vazia
  if(L -> begin == NULL){
    return -1;
  }
  
  // Se a lista não for vazia
  else{
    // Se a lista tiver somente um elemento
    if(L -> size == 1){
      free(L -> begin); // Libera a memória do primeiro nó
    
      L -> begin = NULL; // O primeiro elemento fica vazio (Apaga o endereço do primeiro nó)
      L -> end = NULL; // O último elemento fica vazio (Apaga o endereço do último nó)
    }
    
    // Se a lista não tiver somente um elemento
    else{
      DLNODE *NODE_FRONT = NULL;
      
      NODE_FRONT = L -> begin; // O primeiro nó se torna o nó inicial
      
      L -> begin = NODE_FRONT -> next; // O nó posterior ao nó inicial se torna o primeiro nó 
      L -> begin -> prev = NULL; // O nó anterior ao primeiro nó fica vazio
      
      free(NODE_FRONT); // A memória do nó inicial é liberada
    }
    L -> size = L -> size - 1;
    return 0;
  }
}

int list_pop_back(LIST *L){
  if(L == NULL){
    return -1;
  }
  
  // Se a lista for vazia
  if(L -> begin == NULL){
    return -1;
  }
  // Se a lista não for vazia
  else{
    
    // Se a lista tiver somente um nó
    if(L -> size == 1){
      free(L -> begin); // Libera a memória do primeiro nó
    
      L -> begin = NULL; // O primeiro nó fica vazio ( Apaga o endereço do primeiro nó)
      L -> end = NULL; // O último nó fica vazio (Apaga o endereço do último nó)
    }
    
    // Se a lista não tiver só um nó
    else{
      DLNODE *NODE_BACK = NULL;
      
      NODE_BACK = L -> end; // O último nó se torna o nó final
      
      L -> end = NODE_BACK -> prev; // O nó anterior ao último nó se torna o nó final
      L -> end -> next = NULL; // O nó posteiror ao último nó fica vazio.
        
      free(NODE_BACK); // Libera a memória do nó final    
    }
    L -> size =  L -> size -1;
    return 0;
  }
}

int list_erase(LIST *L, int pos){
    
    // Se a lista for vazia
    if(L == NULL || pos <= 0 || pos > L -> size){
      return -1;
    }
    
    //Se a lista não for vazia
    else{
      
      // Se a lista possuir somente um nó
      if(L -> size == 1){
        free(L -> begin); // Libera a memória do primeiro nó
        
        L -> begin = NULL; // O primeiro nó fica vazio. Apaga o endereço do primeiro nó, e consequentemente seus dados.
        L -> end = NULL; // O último nó fica vazio. Apaga o endereço do último nó, e consequentemente seus dados.
      }
      // Se a lista não possuir somente um nó
      else{
        
        DLNODE *NODE_PRESENT = NULL;
        
        // Se a posição desejada for a primeira
        if(pos == 1){
          NODE_PRESENT = L -> begin; // O primeiro nó se torna o nó atual
          
          L -> head = NODE_PRESENT -> next; // O próximo nó se torna o primeiro nó
          L -> begin -> prev = NULL; // O nó anterior ao primeiro nó fica vazio   
          free(NODE_PRESENT);     
        }
        
        // Se a posição desejada for a última
        else
        if(pos == L -> size){
          NODE_PRESENT = L -> end; // O último nó se torna o nó atual
      
          L -> end = NODE_PRESENT -> prev; // O nó anterior ao último nó se torna o último nó    
          L -> end -> next =  NULL; // O nó posterior ao último nó fica vazio
          free(NODE_PRESENT);
        }
        
        // Se o nó estiver no meio da lista
        else{
          int i = 1;
          NODE_PRESENT = L -> begin; // O primeiro nó se torna o nó atual
          
          // Este nó percorre toda a lista até encontra a posição desejada
          while(NODE_PRESENT != NULL && i < pos){
            NODE_PRESENT =  NODE_PRESENT -> next; // O nó posteiror ao nó atual se torna o nó atual
            i++;
          }
                
          NODE_PRESENT -> prev -> next = NODE_PRESENT -> next; // O nó anterior ao nó atual deixa de apontar para o próprio nó atual e começa a apontar para o proximo nó
          NODE_PRESENT -> next -> prev = NODE_PRESENT -> prev; // O nó posterior ao nó atual deixa de apontar para o próprio nó atual e começa a apontar para o nó anterior
          
          free(NODE_PRESENT);   
        }
      }
      L -> size = L -> size - 1;
      return 0;
    }
}

int list_erase_short_version(LIST *L, int pos){
  // Se a lista for vazia 
  if(L == NULL || pos <= 0 || pos > L -> size){
    return -1;
  }

  // Se a lista não for vazia
  else{
    DLNODE *NODE_PRESENT;
    NODE_PRESENT = L -> begin; // O primeiro nó se torna o nó atual
    
    int i = 1;
    while(NODE_PRESENT != NULL && i < pos){
      NODE_PRESENT = NODE_PRESENT -> next;
      i++;
    } 
    
    // Se o nó desejado for o primeiro
    if(NODE_PRESENT -> prev == NULL){ // Se o nó anterior ao nó atual estiver vazio signfica que tal nó é o primeiro
      L -> begin = NODE_PRESENT -> next; // O nó posterior ao nó atual se torna o primeiro nó
    }
    // Se o nó desejado for o último
    else
    if(NODE_PRESENT -> next == NULL){ // Se o nó posterior ao nó atual estiver vazio signfica que tal nó é o último
      L -> end = NODE_PRESENT -> prev; // O nó anterior ao nó atual se tórna o último nó
    }
    
    // Se o nó desejado não for o primeiro
    else
    if (NODE_PRESENT -> prev != NULL){
      NODE_PRESENT -> prev -> next = NODE_PRESENT -> next;
    }
    
    // Se o nó desejado não for o último
    else
    if (NODE_PRESENT -> next != NULL){
      NODE_PRESENT -> next -> prev = NODE_PRESENT -> prev;
    }
    
    free(NODE_PRESENT); // Libera a memória do nó atual
    L -> size = L -> size - 1;
  }
} 

int list_pop_mat(LIST *L, int mat){
  if(L == NULL){
    return -1;
  }
  
  //Se a lista for vazia 
  if(L -> begin == NULL){
    return -1;
  }
  
  //Se a lista não for vazia
  else{
    
    // Se a lista possuir somente um nó
    if(L -> size == 1){
      free(L -> begin); // Libera a memória do primeiro nó
      
      L -> begin = NULL; // O primeiro nó fica vazio. Apaga o endereço do primeiro nó, e consequentemente seus dados.
      L -> end = NULL; // O último nó fica vazio. Apaga o endereço do último nó, e consequentemente seus dados.
    }
    
    // Se a lista não possuir somente um nó
    else{
      
      DLNODE *NODE_PRESENT = NULL;
      NODE_PRESENT = L -> begin;
       
      while(NODE_PRESENT != NULL && NODE_PRESENT -> data.matricula != mat){
        NODE_PRESENT = NODE_PRESENT -> next;
      }
      
      //Se a matricula não for encontrada
      if(NODE_PRESENT == NULL){
        return -1;
      }
      
      //Se a matricula estiver no primeiro nó
      else
      if(NODE_PRESENT == L -> begin){
        L -> begin = NODE_PRESENT -> next;
        L -> begin -> prev = NULL;
        free(NODE_PRESENT);
      }
      
      //Se a matricula estiver no último nó
      else
      if(NODE_PRESENT == L -> end){
        L -> end = NODE_PRESENT -> prev;
        L -> end -> next = NULL;
        free(NODE_PRESENT);
      }
      
      //Se a matricula estiver no meio
      else{
        NODE_PRESENT -> prev -> next = NODE_PRESENT -> next;
        NODE_PRESENT -> next -> prev = NODE_PRESENT -> prev;
        
        free(NODE_PRESENT);
      }
    }
    L -> size = L -> size - 1;
  }
}

int list_find_mat(LIST *L, int mat, ALUNO *aluno){
  if(L == NULL){
    return -1;
  }
  // Se a lista for vazia
  else
  if(L -> begin == NULL){
    return -1;
  }
  // Se a lista não for vazia
  else{
    DLNODE *NODE_PRESENT = NULL;
    NODE_PRESENT = L -> begin;
    
    while(NODE_PRESENT != NULL && NODE_PRESENT -> data.matricula != mat){
          NODE_PRESENT = NODE_PRESENT -> next;
    }
    
    //Se a matricula não for encontrada
    if(NODE_PRESENT == NULL){
    return -1;
    }

    // Se a matricula for encontrada
    else{
        *aluno = NODE_PRESENT -> data;
        return 0;
    }
  }
}

int list_find_pos(LIST *L, int pos, ALUNO *aluno){
  if(L == NULL){
    return -1;
  }
  // Se a lista for vazia
  else
  if(L -> begin == NULL){
    return -1;
  }
  // Se a lista não for vazia
  else{
    
    //Se a posição desejada for a primeira
    if(pos == 1){
      *aluno = L -> head -> data;
    }
    //Se a posição desejada não for a primeira
    else{
    
      DLNODE *NODE_PRESENT = NULL;
      NODE_PRESENT = L -> begin;
      
      int i = 1; 
      while(NODE_PRESENT != NULL && i != pos){
        NODE_PRESENT = NODE_PRESENT -> next;
        i++;
      }
      
      //Se a posição não for encontrada
      if(NODE_PRESENT == NULL){
        return -1;
      }

      // Se a posição for encontrada
      else{
        *aluno = NODE_PRESENT -> data;
        return 0;
      }
    }
  }
}

int getpos(LIST *L, int mat, int *pos){
  if(L == NULL){
    return -1;
  }
  
  DLNODE *NODE_PRESENT = NULL;
  NODE_PRESENT = L -> begin;
  
  int i = 1;
  while(NODE_PRESENT != NULL && NODE_PRESENT -> data.matricula != mat){
    NODE_PRESENT = NODE_PRESENT -> next;
    i++;
  }
  
  //Se a matricula não for encontrada
  if(NODE_PRESENT == NULL){
    return -1;
  }
  // Se a matricula for encontrada
  else{
    *pos = i;
    return 0;
  }
}
  
int list_size(LIST *L){
  return -1;
  if(L == NULL){
  }
  return L -> size;
}
  
int list_full(LIST *L){ // Como a lista é alocada dinamicamente nunca estará cheia
  if(L == NULL){
      return -1;
  }
  return 0; // retorna falso
}
  
int list_void(LIST *L){
  if(L == NULL){
    return -1;
  }
  else
  if(L -> begin == NULL){
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
    
  DLNODE *NODE_PRESENT = NULL;
  NODE_PRESENT = L -> begin; // o primeiro nó se torna o nó atual
    
  //A lista deixará de ser percorrida quando o nó atual for igual a NULL
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
  
int list_free(LIST *L){
  if(L == NULL){
    return -1;
  }
    
  DLNODE *NODE_PRESENT = NULL;
  NODE_PRESENT = L -> begin;
  
  while(NODE_PRESENT != NULL){
      L -> begin = NODE_PRESENT -> next; // O nó posterior ao nó atual se torna o primeiro nó
              
      free(NODE_PRESENT); // Libera a memória do nó atual
        
      NODE_PRESENT = L -> begin; // O primeiro nó se torna o nó atual
  }
  
  free(L); // Libera a memória da lista
  return 0;
  }

int list_front(LIST *L, ALUNO *aluno){
  if(L == NULL){
    return -1;
  }
  
  //Se a lista for vazia
  else
  if(L -> begin == NULL){
    return -1;
  }
  //Se a lista não for vazia
  else{
    *aluno = L -> begin -> data;
    return 0;
  }
}

int list_back(LIST *L, ALUNO *aluno){
  if(L == NULL){
    return -1;
  }
  //Se a lista for vazia
  else
  if(L -> begin == NULL){
    return -1;
  }
  //Se a lista não for vazia
  else{
    *aluno = L -> end -> data;
    return 0;
  }
}

