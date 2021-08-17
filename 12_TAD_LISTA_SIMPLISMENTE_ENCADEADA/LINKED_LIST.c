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
    L -> head = NODE;
  }
  
  //Se a lista não for vazia
  else{
    NODE -> next = L -> head;  // O primeiro nó se torna o próximo nó
    L -> head = NODE; // O nó criado se torna o primeiro nó
  }
return 0;  
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
    L -> head = NODE; // O nó criado se torna o primeiro nó
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
    
    NODE_PREVIOUS -> next = NODE; // O nó anterior deixa de apontar para o nó atual e começa a apontar para o nó criado
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
    L -> head = NODE; // O nó criado se torna o primeiro nó
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
        L -> head = NODE; /// O nó criado se torna o primeiro nó 
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
    L -> head = NODE; // O nó criado se torna o primeiro nó
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
      NODE -> next = L -> head;
      L -> head = NODE;
    }
          
    // Se a matricula tiver que ser inserida no meio
    else{
      NODE -> next = NODE_PRESENT; 
      NODE_PREVIOUS -> next = NODE;
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
      L -> head = NODE_PRESENT -> next;// O próximo nó (NULL) se torna o primeiro nó(NULL)
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
        NODE_PREVIOUS -> next = NODE_PRESENT -> next; // O nó anterior deixa de apontar para o nó atual e começa a apontar para NULL
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
  // Se a lista for vazia
  if(L == NULL || pos <= 0 || pos >  L -> size){
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
