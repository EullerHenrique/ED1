/*
Nome: Euller Henrique Bandeira Oliveira
Matrícula: 11821BSI210
 
*/

//Questão 1

//LISTA_ENCADEADA.h

struct aluno{
  int matricula;
  char nome[30];
  float notas[4];
  int faltas;
};

typedef struct lista LISTA;
typedef struct lista_no LISTA_NO;
typedef struct aluno ALUNO;

LISTA* cria_lista();

int insere_lista_inicio(LISTA* L, ALUNO aluno);
int insere_lista_final(LISTA* L, ALUNO aluno);
int insere_lista_ordenada(LISTA* L, ALUNO aluno);

int insere_lista_pos(LISTA* L, int pos, ALUNO aluno);

int consulta_lista_pos(LISTA* L, int pos, ALUNO *aluno);
int consulta_lista_mat(LISTA* L, int mat, ALUNO *aluno);

int remove_lista_mat(LISTA* L, int mat);
int remove_lista_inicio(LISTA* L);
int remove_lista_final(LISTA* L);

int tamanho_lista(LISTA* L);

int lista_cheia(LISTA* L);
int lista_vazia(LISTA* L);

int imprime_lista(LISTA* L);

int libera_lista(LISTA* L);

//LISTA_ENCADEADA.c

#include <stdlib.h>
#include <stdio.h>
#include "LISTA_ENCADEADA.h"

struct lista{
  LISTA_NO *head; // guarda um ponteiro com o endereço do primeiro nó
};

struct lista_no{ // nó
  struct aluno dado; // guarda os dados do aluno
  LISTA_NO *prox; // guarda um ponteiro com o endereço do próximo nó
};


LISTA *cria_lista(){
  LISTA *L = NULL;
  
  L = malloc(1 * sizeof(LISTA)); // Cria a lista.
  if(L == NULL){
    return NULL;
  }
  
  L -> head = NULL; // Lista vazia
  
  return L;
}

int insere_lista_inicio(LISTA *L, ALUNO aluno){
  if(L == NULL){
    return -1;
  }
  
  LISTA_NO *NO = NULL; 
  NO = malloc(1 * sizeof(LISTA_NO));  // Cria o nó
  
  if(NO == NULL){
    return -1;
  }
  
  NO -> dado = aluno; //O nó criado recebe os dados do aluno
    
  // Desloca para direita
  NO -> prox = L -> head; // O primeiro nó se torna o próximo nó
  //
  L -> head = NO; // O nó criado é inserido no primeiro nó 
    
  return 0;
}


int insere_lista_final(LISTA *L, ALUNO aluno){
  if(L == NULL){
    return -1;
  }
  
  LISTA_NO *NO = NULL;
  NO = malloc(1 * sizeof(LISTA_NO)); // Cria o nó
  if(NO == NULL){
    return -1;
  }
      
  NO -> dado = aluno; //O nó criado recebe os dados do aluno
  NO -> prox = NULL; // O nó criado recebe NULL por estar no final da lista
      
  // Se a lista for vazia, então o nó criado é inserido no inicio da lista
  if(L -> head == NULL){
     L -> head = NO; // O nó criado é inserido no primeiro nó
  }
  //Se a lista não for vazia, então o nó será inserido no final da lista
  else{
    LISTA_NO *NO_ATUAL = NULL;
    LISTA_NO *NO_ANTERIOR = NULL;
        
    NO_ATUAL = L -> head; // O primeiro nó se torna o nó atual
        
    // A lista deixará de ser percorrida quando o nó atual for igual a null
    while(NO_ATUAL != NULL){
          NO_ANTERIOR = NO_ATUAL; //O nó atual se torna o nó anterior
          NO_ATUAL = NO_ATUAL -> prox; // O próximo nó se torna o nó atual
    }
    NO_ANTERIOR -> prox = NO; //O nó criado é inserido no nó posterior ao nó anterior, ou seja, o nó criado é inserido no último nó encontrado.
  }
return 0;
}

int insere_lista_ordenada(LISTA *L, ALUNO aluno){
  if(L == NULL){
    return -1;
  }
    
  LISTA_NO *NO = NULL; 
  NO = malloc(1 * sizeof(LISTA_NO)); // Cria o nó
  if(NO == NULL){
    return -1;
  }
    
  NO -> dado = aluno; //O nó criado recebe os dados do aluno
    
  // Se a lista for vazia, então o nó criado é inserido no inicio da lista
  if(L -> head == NULL){ 
    NO -> prox = NULL;// O nó criado recebe NULL por estar no final da lista 
    L -> head = NO;  // O nó criado é inserido no primeiro nó
  }
  else{
      LISTA_NO *NO_ATUAL = NULL;
      LISTA_NO *NO_ANTERIOR = NULL;
      
      NO_ATUAL = L -> head; // O primeiro nó se torna o nó atual
      
      // A lista deixará de ser percorrida quando o nó atual for igual a null ou quando uma matricula maior que a matricula do aluno enviado para esta função for encontrada
      while(NO_ATUAL != NULL && NO_ATUAL -> dado.matricula < aluno.matricula){
        NO_ANTERIOR = NO_ATUAL;//O nó atual se torna o nó anterior
        NO_ATUAL = NO_ATUAL -> prox; // O próximo nó se torna o nó atual
      }
    
      // Se o nó encontrado for o primeiro, o nó criado será inserido no primeiro nó e o nó que estava no primeiró nó será deslocado para direita
      if(NO_ATUAL == L -> head){
         //Desloca pra direita
         NO -> prox = L -> head; // O primeiro nó se torna o próximo nó
         //
         L -> head = NO; // O nó criado é inserido no primeiro nó 
      }
      // Se o nó encontrado não for o primeiro  
      else{
        //Desloca pra direita
        NO -> prox = NO_ATUAL; // O nó atual se torna o próximo nó
        //
        NO_ANTERIOR -> prox = NO; //O nó criado é inserido no nó posterior ao nó anterior, ou seja, o nó criado é inserido no último nó encontrado.
      }
    }
    return 0;
}

int insere_lista_pos(LISTA *L, int pos, ALUNO aluno){
  if(L == NULL || pos <= 0){
    return -1;
  }
    LISTA_NO *NO = NULL;
    NO = malloc(1 * sizeof(LISTA_NO)); // Cria o nó
    if(NO == NULL){
      return -1;
    }
    
    NO -> dado = aluno; //O nó criado recebe os dados do aluno
    
    // Se a lista for vazia, então o nó criado é inserido no inicio da lista
    if(L -> head == NULL){
      NO -> prox = NULL;// O nó criado recebe NULL por estar no final da lista
      L -> head = NO; // O nó criado é inserido no primeiro 
    }
    else{
      LISTA_NO *NO_ANTERIOR = NULL;
      LISTA_NO *NO_ATUAL = NULL;
      
      NO_ATUAL = L -> head; // O primeiro nó se torna o nó atual
      
      int i = 1;
      
      //  A lista deixará de ser percorrida quando i for maior que pos, ou seja, quando a posição for encontrada 
      while(NO_ATUAL != NULL && i < pos){
        NO_ANTERIOR = NO_ATUAL; //O nó atual se torna o nó anterior
        NO_ATUAL = NO_ATUAL -> prox; // O proximo nó se torna o nó atual
        i++;
      }
    
    //Se toda a lista tiver sido percorrido e a posição não tiver sido encontrada
    if(NO_ATUAL == NULL){
      return -1;
    } 
    else 
    // Se o nó encontrado for o primeiro, o nó criado será inserido no primeiro nó e o nó que estava no primeiró nó será deslocado para direita
    if(NO_ATUAL == L -> head){
      // Desloca pra direita
      NO -> prox = L -> head; // O primeiro nó se torna o próximo nó
      //
      L -> head = NO; // O nó criado é inserido no primeiro nó 
    }
    else{
      // Desloca pra direita
      NO -> prox = NO_ATUAL; // O nó atual se torna o próximo nó
      //
      NO_ANTERIOR -> prox = NO;//O nó criado é inserido no nó posterior ao nó anterior, ou seja, o nó criado é inserido no último nó encontrado.
    }
  }
    return 0;
}

int consulta_lista_pos(LISTA *L, int pos, ALUNO* aluno){
  if(L == NULL || pos <= 0){
    return -1;
  }
  
  LISTA_NO *NO_ATUAL = NULL;
  
  NO_ATUAL = L -> head; // O primeiro nó se torna o nó atual
  
  int i = 1;
  
  // A lista deixará de ser percorrida quando o nó atual for NULL ou quando i for maior que pos, ou seja, quando a posição for encontrada 
  while(NO_ATUAL != NULL && i < pos){
    NO_ATUAL = NO_ATUAL -> prox; // O proximo nó se torna o nó atual
    i++;
  }
  
  //Se toda a lista tiver sido percorrido e a posição não tiver sido encontrada
  if(NO_ATUAL == NULL){
    return -1;
  }
  //Se o nó desejado foi encontrado, ou seja, a posição desejada foi encontrada
  else{
    *aluno = NO_ATUAL -> dado; // Os dados do nó atual são inseridos na estrutura aluno
    return 0; 
  }

}

int consulta_lista_mat(LISTA *L, int mat, ALUNO *aluno){
  if(L == NULL){
    return -1;
  }
  
  LISTA_NO *NO_ATUAL = NULL;
  
  NO_ATUAL = L -> head; // O primeiro nó se torna o nó atual
  
  // A lista deixará de ser percorrida quando o nó atual for null ou quando a matricula presente no nó atual for igual a matricula do aluno enviado para esta função, ou seja, percorre até a matricula ser encontrada 
  while(NO_ATUAL != NULL && NO_ATUAL -> dado.matricula != mat){
    NO_ATUAL = NO_ATUAL -> prox; // O proximo nó se torna o nó atual
  }
  
  //Se toda a lista tiver sido percorrido e a posição não tiver sido encontrada
  if(NO_ATUAL == NULL){
    return -1;
  }
  //O nó desejado foi encontrado, ou seja, a matricula desejada foi encontrada
  else{
    *aluno = NO_ATUAL -> dado; // Os dados do nó atual é inserido na estrutura aluno
    return 0;
  }

}


int remove_lista_inicio(LISTA *L){
  // Se L for NULL ou se a lista for vazia
  if(L == NULL || L -> head == NULL){ 
    return -1;
  }
  
  LISTA_NO *NO_INICIAL = NULL;
  NO_INICIAL = L -> head;// O primeiro nó se torna o nó inicial 
  
  //Desloca pra esquerda
  L -> head = NO_INICIAL -> prox; // o próximo nó se torna o primeiro nó      
  //
  free(NO_INICIAL); // o nó inicial é removido

return 0;  
}

int remove_lista_final(LISTA *L){
  // Se L for NULL ou se a lista for vazia
  if(L == NULL || L -> head == NULL){
    return -1;
  }
  
  LISTA_NO *NO_ANTERIOR = NULL;
  LISTA_NO *NO_ATUAL = NULL;
  
  NO_ATUAL = L -> head;// O primeiro nó se torna o nó atual
  
  // A lista deixará de ser percorrida quando o nó atual apontar para null
  while(NO_ATUAL -> prox != NULL){
    NO_ANTERIOR = NO_ATUAL; //O nó atual se torna o nó anterior
    NO_ATUAL = NO_ATUAL -> prox; // O proximo nó se torna o nó atual
  }
  
  //Se a lista tiver somente um nó, então o primeiro nó da lista será removido apagando o seu endereço
  if(NO_ATUAL == L -> head){
    L -> head = NO_ATUAL -> prox;// o próximo nó se torna o primeiro nó, ou seja, NULL se torna o primeiro nó      
  }
  //Se a lista não tiver só um nó
  else{
    NO_ANTERIOR -> prox =  NO_ATUAL -> prox; // O nó anterior deixa de apontar para o nó atual e começa a apontar para NULL.
    free(NO_ATUAL); // nó atual é removido
  }
  return 0;
}

int remove_lista_mat(LISTA *L, int mat){
  // Se L for NULL ou se a lista for vazia
  if(L == NULL || L -> head == NULL){
    return -1;
  }
  
  LISTA_NO *NO_ANTERIOR = NULL;
  LISTA_NO *NO_ATUAL = NULL;
  
  NO_ATUAL = L -> head;// O primeiro nó se torna o nó atual
  
  // A lista deixará de ser percorrida quando o nó atual apontar para null ou quando a matricula presente no nó atual for igual a matricula do aluno enviado para esta função, ou seja, percorre até a matricula ser encontrada 
  while(NO_ATUAL != NULL && NO_ATUAL -> dado.matricula != mat){
    NO_ANTERIOR = NO_ATUAL; //O nó atual se torna o nó anterior
    NO_ATUAL = NO_ATUAL -> prox; // O proximo nó se torna o nó atual
  }
  
  //Se toda a lista tiver sido percorrida, a matricula não foi encontrada
  if(NO_ATUAL == NULL){
    return -1;
  }
  else
  //Se a lista tiver somente um nó, então o primeiro nó da lista será removido apagando o seu endereço
  if(NO_ATUAL == L-> head){
    L -> head = NO_ATUAL -> prox; //O próximo nó se torna o primeiro nó, ou seja, NULL se torna o primeiro nó    
  }
  else{
    NO_ANTERIOR -> prox = NO_ATUAL -> prox; // O nó anterior deixa de apontar para o nó atual e começa a apontar para NULL.
    free(NO_ATUAL);  // nó atual é removido
  }
  return 0;
}
  
int tamanho_lista(LISTA * L){
  if(L == NULL){
    return -1;
  }
  LISTA_NO *NO_ATUAL = NULL;
  NO_ATUAL = L -> head; // O primeiro nó se torna o nó atual
  int i = 0;
  
  // A lista deixará de ser percorrida quando o nó atual for null
  while(NO_ATUAL != NULL){ 
    NO_ATUAL = NO_ATUAL -> prox; // o próximo nó se torna o nó atual
    i++;
  }
return i; // retorna o tamanho da lista
}

int lista_cheia(LISTA *L){ // A lista nunca estará cheia porque está listas encadeadas são alocadas dinamicamente
  if(L == NULL){
    return -1;
  }
  return 0;// retorna false
}

int lista_vazia(LISTA *L){
  if(L == NULL){
    return -1;// retorna erro
  }
  else
  if(L -> head == NULL){// se a lista for vazia
    return 1;// retorna true
  }
  else{
    return 0; // retorna false
  }
}
  
int imprime_lista(LISTA *L){
  // Se L for NULL ou se a lista for vazia
  if(L == NULL || L -> head == NULL){
    return -1;
  }
  
  LISTA_NO *NO_ATUAL = NULL;
  NO_ATUAL = L -> head; // o primeiro nó se torna o nó atual
  
  //A lista deixará de ser percorrida quando o nó atual for igual a NULL
  int i = 1;
  while(NO_ATUAL != NULL){
    printf("Aluno %d\n\n",i);
    printf("Nome: %s\n",NO_ATUAL -> dado.nome);
    printf("Matrícula: %d \n",NO_ATUAL -> dado.matricula);
    printf("Nota da primeira prova %f\n",NO_ATUAL -> dado.notas[0]);
    printf("Nota da segunda prova %f\n",NO_ATUAL -> dado.notas[1]);
    printf("Nota da terceira prova %f\n",NO_ATUAL -> dado.notas[2]);
    printf("Nota da quarta prova %f\n",NO_ATUAL -> dado.notas[3]);
    printf("Faltas: %d\n",NO_ATUAL -> dado.faltas);
    printf("\n\n");
    i++;
    NO_ATUAL = NO_ATUAL -> prox; // o próximo nó se torna o nó atual
  }
return 0;
}

int libera_lista(LISTA *L){
  if(L == NULL){
    return -1;
  }
  
  LISTA_NO *NO_ATUAL = NULL;
  NO_ATUAL = L -> head; // o primeiro nó se torna o nó atual
  
  //A lista deixará de ser percorrida quando o nó atual for igual a NULL
  while(NO_ATUAL != NULL){
    L -> head = NO_ATUAL -> prox; // o próximo nó se torna o primeiro nó
    free(NO_ATUAL); // remove o nó atual
    NO_ATUAL = L -> head; // o primeiro nó se torna o nó atual
  }
  
  free(L); // remove a lista
  return 0;  
}

// MAIN_LISTA_ENCADEADA.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "LISTA_ENCADEADA.h"

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
  LISTA *L = NULL;
  ALUNO aluno;
  
  int opcao = 0;
  int loop = 0;
  
  L =  cria_lista();  
  if(L == NULL){
    printf("Erro!!!\n");
  }
  while(loop == 0){
    
    printf("====================================================================================\n");
    printf("==============================Operações com listas==================================\n");
    printf("====================================================================================\n");
    printf("1  - Inserir aluno no começo \n");
    printf("2  - Inserir aluno no final \n");
    printf("3  - Inserir aluno ordenamente de acordo com a matrícula \n");
    printf("4  - Inserir aluno de acordo com a posição \n");
    printf("5  - Remover aluno do começo da lista\n");
    printf("6  - Remover aluno do final da lista\n");
    printf("7  - Remover aluno de acordo com a sua matricula\n");
    printf("8  - Descobrir o tamanho atual da lista\n");
    printf("9  - A lista está cheia?\n");
    printf("10 - A lista está vazia?\n");
    printf("11 - Acessar os dados de determinado aluno na lista de acordo com a sua posição\n");
    printf("12 - Acessar os dados de determinado aluno na lista de acordo com a sua matrícula\n");
    printf("13 - Imprimir lista\n");
    printf("14 - Destruir lista\n");
    printf("15 - Fechar programa\n");
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
          
      if(insere_lista_inicio(L,aluno) == -1){
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
        
      if(insere_lista_final(L,aluno) == -1){
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
        
      if(insere_lista_ordenada(L,aluno) == -1){
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
        
      if(insere_lista_pos(L, pos, aluno) == -1){
          printf("ERRO!!!\n");
      }
      
    }
    else
    if(opcao == 5){  
        if(remove_lista_inicio(L) == -1){
          printf("Erro!!!\n");
        }
    }
    else
    if(opcao == 6){
        if(remove_lista_final(L) == -1){
          printf("Erro!!!\n");
        }
    }
    else
    if(opcao == 7){  
        int matricula = 0;
        printf("Digite a matricula do aluno a ser removido: ");
        scanf("%d",&matricula);
        
        if(remove_lista_mat(L, matricula)){
          printf("Erro!!!\n");
        }
    }
    else
    if(opcao == 8){
        
        int x = 0;
        x = tamanho_lista(L);
        
        if(x == -1){
          printf("Erro!!!\n");
        }
        else{
        printf("Tamanho da lista = %d \n",x);
        }
    }
    else
    if(opcao == 9){
      int x = 0;
      x = lista_cheia(L);
      
      if(x == -1){
        printf("Erro!!!\n");
      }
      else
      if(x == 0){
        printf("False\n");
      } 
    } 
    else
    if(opcao == 10){
      int x = 0;
      x = lista_vazia(L);
      
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
    if(opcao == 11){
        int x = 0;
        
        printf("Digite a posição do aluno a ser consultado: \n");
        scanf("%d",&x);
        
        if(consulta_lista_pos(L, x, &aluno) == -1){
          printf("Erro!!!\n");
        }
        else{
          imprime_aluno(&aluno);
        } 
    } 
    else
    if(opcao == 12){
        int matricula = 0;
        
        printf("Digite a matricula do aluno a ser consultado: \n");
        scanf("%d",&matricula);
        
        if(consulta_lista_mat(L,matricula,&aluno) == -1){
          printf("Erro!!!\n");
        } 
        else{
          imprime_aluno(&aluno);
        } 
   }
  else
  if(opcao == 13){
    if(imprime_lista(L) == -1){
      printf("ERRO!!!\n");
    }
  }
  else
  if(opcao == 14){
    if(libera_lista(L) == -1){
      printf("Erro!!!\n");
    }
  }
  else
  if(opcao == 15){
    exit(1);
  }
  
}// fecha o while

return 0;
}

//Questão 2

// LISTA_ENCADEADA_2.h

struct aluno{
  int matricula;
  char nome[30];
  float notas[4];
  int faltas;
};

typedef struct lista LISTA;
typedef struct lista_no LISTA_NO;
typedef struct aluno ALUNO;

LISTA* cria_lista(int tipo_lista);

int insere_lista_inicio(LISTA* L, ALUNO aluno);
int insere_lista_final(LISTA* L, ALUNO aluno);
int insere_lista_ordenada(LISTA* L, ALUNO aluno);

int insere_lista_pos(LISTA* L, int pos, ALUNO aluno);

int consulta_lista_pos(LISTA* L, int pos, ALUNO *aluno);
int consulta_lista_mat(LISTA* L, int mat, ALUNO *aluno);

int remove_lista_mat(LISTA* L, int mat);
int remove_lista_inicio(LISTA* L);
int remove_lista_final(LISTA* L);

int tamanho_lista(LISTA* L);

int lista_cheia(LISTA* L);
int lista_vazia(LISTA* L);

int imprime_lista(LISTA* L);

int libera_lista(LISTA* L);

//LISTA_ENCADEADA_2.c
#include <stdlib.h>
#include <stdio.h>
#include "LISTA_ENCADEADA_2.h"

struct lista { // lista
 LISTA_NO *head; // guarda um ponteiro com o endereço do primeiro nó
 int qtd; // quantidade de elementos na lista
 int ordenada; // indica se a lista é ordenada
};

struct lista_no{ // nó
  struct aluno dado; // guarda os dados do aluno
  LISTA_NO *prox; // guarda um ponteiro com o endereço do próximo nó
};

LISTA *cria_lista(int tipo_lista){
  LISTA *L = NULL;
  
  L = malloc(1 * sizeof(LISTA)); // Cria lista
  if(L == NULL){
    return NULL;
  }
  
  L -> head = NULL; // Lista vazia
  L -> ordenada = tipo_lista; // Define o tipo da lista
  L -> qtd = 0; // Lista vazia
  
  return L;
}

int insere_lista_inicio(LISTA *L, ALUNO aluno){
  if(L == NULL || L -> ordenada == 1){
    return -1;
  }
  else
  // Se a lista não for ordenada
  if(L -> ordenada == 0){ 
    LISTA_NO *NO = NULL; 
    NO = malloc(1 * sizeof(LISTA_NO));  // Cria o nó
  
    if(NO == NULL){
      return -1;
    }
  
    NO -> dado = aluno; //O nó criado recebe os dados do aluno
    
    // Desloca para direita
    NO -> prox = L -> head; // O primeiro nó se torna o próximo nó
    //
    L -> head = NO; // O nó criado é inserido no primeiro nó 
    
    L -> qtd = L -> qtd + 1;
    return 0;
  }
}

int insere_lista_final(LISTA *L, ALUNO aluno){
  if(L == NULL || L -> ordenada == 1){
    return -1;
  }
  else
  // Se a lista não for ordenada
  if(L -> ordenada == 0){ 
      
      LISTA_NO *NO = NULL;
      NO = malloc(1 * sizeof(LISTA_NO)); // Cria o nó
      if(NO == NULL){
        return -1;
      }
      
      NO -> dado = aluno; //O nó criado recebe os dados do aluno
      NO -> prox = NULL; // O nó criado recebe NULL por estar no final da lista
      
      // Se a lista for vazia, então o nó criado é inserido no inicio da lista
      if(L -> head == NULL){
        L -> head = NO; // O nó criado é inserido no primeiro nó
      }
      //Se a lista não for vazia, então o nó será inserido no final da lista
      else{
        LISTA_NO *NO_ATUAL = NULL;
        LISTA_NO *NO_ANTERIOR = NULL;
        
        NO_ATUAL = L -> head; // O primeiro nó se torna o nó atual
        
        // A lista deixará de ser percorrida quando o nó atual for igual a null
        while(NO_ATUAL != NULL){
          NO_ANTERIOR = NO_ATUAL; //O nó atual se torna o nó anterior
          NO_ATUAL = NO_ATUAL -> prox; // O próximo nó se torna o nó atual
        }
        
        NO_ANTERIOR -> prox = NO; //O nó criado é inserido no nó posterior ao nó anterior, ou seja, o nó criado é inserido no último nó encontrado.
      }
      L -> qtd = L -> qtd + 1;
      return 0;
  }
}

int insere_lista_ordenada(LISTA *L, ALUNO aluno){
  if(L == NULL || L -> ordenada == 0){
    return -1;
  }
  else
  //Se a lista for ordenada
  if(L -> ordenada == 1){
    
    LISTA_NO *NO = NULL; 
    NO = malloc(1 * sizeof(LISTA_NO)); // Cria o nó
    if(NO == NULL){
      return -1;
    }
    
    NO -> dado = aluno; //O nó criado recebe os dados do aluno
    
    // Se a lista for vazia, então o nó criado é inserido no inicio da lista
    if(L -> head == NULL){ 
      NO -> prox = NULL;// O nó criado recebe NULL por estar no final da lista 
      L -> head = NO;  // O nó criado é inserido no primeiro nó
    }
    else{
      LISTA_NO *NO_ANTERIOR = NULL;
      LISTA_NO *NO_ATUAL = NULL;
    
      
      NO_ATUAL = L -> head; // O primeiro nó se torna o nó atual
      
      // A lista deixará de ser percorrida quando o nó atual for igual a null ou quando uma matricula maior que a matricula do aluno enviado para esta função for encontrada
      while(NO_ATUAL != NULL && NO_ATUAL -> dado.matricula < aluno.matricula){
        NO_ANTERIOR = NO_ATUAL;//O nó atual se torna o nó anterior
        NO_ATUAL = NO_ATUAL -> prox; // O próximo nó se torna o nó atual
      }
      // Se o nó encontrado for o primeiro, o nó criado será inserido no primeiro nó e o nó que estava no primeiró nó será deslocado para direita
      if(NO_ATUAL == L -> head){
         //Desloca pra direita
         NO -> prox = L -> head; // O primeiro nó se torna o próximo nó
         //
         L -> head = NO; // O nó criado é inserido no primeiro nó 
      }
      // Se o nó encontrado não for o primeiro  
      else{
        //Desloca pra direita
        NO -> prox = NO_ATUAL; // O nó atual se torna o próximo nó
        //
        NO_ANTERIOR -> prox = NO; //O nó criado é inserido no nó posterior ao nó anterior, ou seja, o nó criado é inserido no último nó encontrado.
      }
    }
      L -> qtd = L -> qtd + 1;
      return 0;
  }
}
    
int insere_lista_pos(LISTA *L, int pos, ALUNO aluno){
  if(L == NULL || pos <= 0 || L -> ordenada == 1){
    return -1;
  }
  if( L -> ordenada == 0){
    LISTA_NO *NO = NULL;
    NO = malloc(1 * sizeof(LISTA_NO)); // Cria o nó
    if(NO == NULL){
      return -1;
    }
    
    NO -> dado = aluno; //O nó criado recebe os dados do aluno
    
    // Se a lista for vazia, então o nó criado é inserido no inicio da lista
    if(L -> head == NULL){
      NO -> prox = NULL;// O nó criado recebe NULL por estar no final da lista
      L -> head = NO; // O nó criado é inserido no primeiro 
    }
    else{
      LISTA_NO *NO_ANTERIOR = NULL;
      LISTA_NO *NO_ATUAL = NULL;
      
      NO_ATUAL = L -> head; // O primeiro nó se torna o nó atual
      
      int i = 1;
      
      //  A lista deixará de ser percorrida quando i for maior que pos, ou seja, quando a posição for encontrada 
      while(NO_ATUAL != NULL && i < pos){
        NO_ANTERIOR = NO_ATUAL; //O nó atual se torna o nó anterior
        NO_ATUAL = NO_ATUAL -> prox; // O proximo nó se torna o nó atual
        i++;
      }
      
      //Se toda a lista tiver sido percorrido e a posição não tiver sido encontrada
      if(NO_ATUAL == NULL){
        return -1;
      }
      else
      // Se o nó encontrado for o primeiro, o nó criado será inserido no primeiro nó e o nó que estava no primeiró nó será deslocado para direita
      if(NO_ATUAL == L -> head){
        // Desloca pra direita
        NO -> prox = L -> head; // O primeiro nó se torna o próximo nó
        //
        L -> head = NO; // O nó criado é inserido no primeiro nó 
      }
      else{
        // Desloca pra direita
        NO -> prox = NO_ATUAL; // O nó atual se torna o próximo nó
        //
        NO_ANTERIOR -> prox = NO;//O nó criado é inserido no nó posterior ao nó anterior, ou seja, o nó criado é inserido no último nó encontrado.
      }
    } 
    L -> qtd = L -> qtd + 1;
    return 0;
  } 
}

int consulta_lista_pos(LISTA *L, int pos, ALUNO* aluno){
  if(L == NULL || pos <= 0){
    return -1;
  }
  
  LISTA_NO *NO_ATUAL = NULL;
  
  NO_ATUAL = L -> head; // O primeiro nó se torna o nó atual
  
  int i = 1;
  
  // A lista deixará de ser percorrida quando o nó atual for NULL ou quando i for maior que pos, ou seja, quando a posição for encontrada 
  while(NO_ATUAL != NULL && i < pos){
    NO_ATUAL = NO_ATUAL -> prox; // O proximo nó se torna o nó atual
    i++;
  }
  
  //Se toda a lista tiver sido percorrido e a posição não tiver sido encontrada
  if(NO_ATUAL == NULL){
    return -1;
  }
  //Se o nó desejado foi encontrado, ou seja, a posição desejada foi encontrada
  else{
    *aluno = NO_ATUAL -> dado; // Os dados do nó atual é inserido na estrutura aluno
    return 0; 
  }

}

int consulta_lista_mat(LISTA *L, int mat, ALUNO *aluno){
  if(L == NULL){
    return -1;
  }
  
  LISTA_NO *NO_ATUAL = NULL;
  
  NO_ATUAL = L -> head; // O primeiro nó se torna o nó atual
  
  // A lista deixará de ser percorrida quando o nó atual for null ou quando a matricula presente no nó atual for igual a matricula do aluno enviado para esta função, ou seja, percorre até a matricula ser encontrada 
  while(NO_ATUAL != NULL && NO_ATUAL -> dado.matricula != mat){
    NO_ATUAL = NO_ATUAL -> prox; // O proximo nó se torna o nó atual
  }
  
  //Se toda a lista tiver sido percorrido e a posição não tiver sido encontrada
  if(NO_ATUAL == NULL){
    return -1;
  }
  //O nó desejado foi encontrado, ou seja, a matricula desejada foi encontrada
  else{
    *aluno = NO_ATUAL -> dado; // Os dados do nó atual é inserido na estrutura aluno
    return 0;
  }

}

int remove_lista_inicio(LISTA *L){
  // Se L for NULL ou se a lista for vazia
  if(L == NULL || L -> head == NULL){ 
    return -1;
  }
  
  LISTA_NO *NO_INICIAL = NULL;
  NO_INICIAL = L -> head;// O primeiro nó se torna o nó inicial
  
  //Desloca pra esquerda
  L -> head = NO_INICIAL -> prox; // o próximo nó se torna o primeiro nó      
  //
  free(NO_INICIAL); // o nó inicial é removido
  L -> qtd = L -> qtd -1;

return 0;  
}

int remove_lista_final(LISTA *L){
  // Se L for NULL ou se a lista for vazia
  if(L == NULL || L -> head == NULL){
    return -1;
  }
  
  LISTA_NO *NO_ANTERIOR = NULL;
  LISTA_NO *NO_ATUAL = NULL;
  
  NO_ATUAL = L -> head;// O primeiro nó se torna o nó atual
  
  // A lista deixará de ser percorrida quando o nó atual apontar para null
  while(NO_ATUAL -> prox != NULL){
    NO_ANTERIOR = NO_ATUAL; //O nó atual se torna o nó anterior
    NO_ATUAL = NO_ATUAL -> prox; // O proximo nó se torna o nó atual
  }
  
  //Se a lista tiver somente um nó, então o primeiro nó da lista será removido apagando o seu endereço
  if(NO_ATUAL == L -> head){
    L -> head = NO_ATUAL -> prox;// o próximo nó se torna o primeiro nó, ou seja, NULL se torna o primeiro nó      
  }
  //Se a lista não tiver só um nó
  else{
    NO_ANTERIOR -> prox =  NO_ATUAL -> prox; // O nó anterior deixa de apontar para o nó atual e começa a apontar para NULL.
    free(NO_ATUAL); // nó atual é removido
  }
  L -> qtd = L -> qtd -1;
  return 0;
}

int remove_lista_mat(LISTA *L, int mat){
  // Se L for NULL ou se a lista for vazia
  if(L == NULL || L -> head == NULL){
    return -1;
  }
  
  LISTA_NO *NO_ANTERIOR = NULL;
  LISTA_NO *NO_ATUAL = NULL;
  
  NO_ATUAL = L -> head;// O primeiro nó se torna o nó atual
  
  // A lista deixará de ser percorrida quando o nó atual apontar para null ou quando a matricula presente no nó atual for igual a matricula do aluno enviado para esta função, ou seja, percorre até a matricula ser encontrada 
  while(NO_ATUAL != NULL && NO_ATUAL -> dado.matricula != mat){
    NO_ANTERIOR = NO_ATUAL; //O nó atual se torna o nó anterior
    NO_ATUAL = NO_ATUAL -> prox; // O proximo nó se torna o nó atual
  }
  
  //Se toda a lista tiver sido percorrida, a matricula não foi encontrada
  if(NO_ATUAL == NULL){
    return -1;
  }
  else
  //Se a lista tiver somente um nó, então o primeiro nó da lista será removido apagando o seu endereço
  if(NO_ATUAL == L-> head){
    L -> head = NO_ATUAL -> prox; //O próximo nó se torna o primeiro nó, ou seja, NULL se torna o primeiro nó    
  }
  else{
    NO_ANTERIOR -> prox = NO_ATUAL -> prox; // O nó anterior deixa de apontar para o nó atual e começa a apontar para NULL.
    free(NO_ATUAL);  // nó atual é removido
  }
  L -> qtd = L -> qtd -1;
  return 0;
}

int lista_cheia(LISTA *L){ // A lista nunca estará cheia porque está listas encadeadas são alocadas dinamicamente
  if(L == NULL){
    return -1;
  }
  return 0;// retorna false
}

int lista_vazia(LISTA *L){
  if(L == NULL){
    return -1;// retorna erro
  }
  else
  if(L -> head == NULL){// se a lista for vazia
    return 1;// retorna true
  }
  else{
    return 0; // retorna false
  }
}

int tamanho_lista(LISTA* L){
  if(L == NULL){
    return -1;
  }

return L -> qtd; // retorna o tamanho da lista
}

int imprime_lista(LISTA *L){
  // Se L for NULL ou se a lista for vazia
  if(L == NULL || L -> head == NULL){
    return -1;
  }
  
  LISTA_NO *NO_ATUAL = NULL;
  NO_ATUAL = L -> head; // o primeiro nó se torna o nó atual
  
  //A lista deixará de ser percorrida quando o nó atual for igual a NULL
  int i = 1;
  while(NO_ATUAL != NULL){
    printf("Aluno %d\n\n",i);
    printf("Nome: %s\n",NO_ATUAL -> dado.nome);
    printf("Matrícula: %d \n",NO_ATUAL -> dado.matricula);
    printf("Nota da primeira prova %f\n",NO_ATUAL -> dado.notas[0]);
    printf("Nota da segunda prova %f\n",NO_ATUAL -> dado.notas[1]);
    printf("Nota da terceira prova %f\n",NO_ATUAL -> dado.notas[2]);
    printf("Nota da quarta prova %f\n",NO_ATUAL -> dado.notas[3]);
    printf("Faltas: %d\n",NO_ATUAL -> dado.faltas);
    printf("\n\n");
    i++;
    NO_ATUAL = NO_ATUAL -> prox; // o próximo nó se torna o nó atual
  }
return 0;
}

int libera_lista(LISTA *L){
  if(L == NULL){
    return -1;
  }
  
  LISTA_NO *NO_ATUAL = NULL;

  NO_ATUAL = L -> head; // o primeiro nó se torna o nó atual
  
  //A lista deixará de ser percorrida quando o nó atual for igual a NULL
  while(NO_ATUAL != NULL){
    L -> head = NO_ATUAL -> prox; // o próximo nó se torna o primeiro nó
    free(NO_ATUAL);// remove o nó atual
    NO_ATUAL = L -> head; // // o primeiro nó se torna o nó atual
  }
  free(L); // remove a lista
  L -> qtd = 0; // lista vazia
return 0;  
}

//MAIN_LISTA_ENCADEADA_2.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "LISTA_ENCADEADA_2.h"

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
  LISTA *L = NULL;
  ALUNO aluno;
  
  int opcao = 0;
  int loop = 0;
  int tipo_lista = 0;
  
  printf("Escolha o tipo da lista desejado\n\n");
  printf("0 - Lista Não Ordenada\n");
  printf("1 - Lista Ordenada\n\n");
  
  printf("Digite a opção desejada: ");
  scanf("%d",&tipo_lista);
  
  while(tipo_lista != 0 && tipo_lista != 1){
    printf("Digite uma opção válida: ");
    scanf("%d",&tipo_lista);
  }
  printf("\n\n");
  
  L =  cria_lista(tipo_lista);  
  if(L == NULL){
    printf("Erro!!!\n");
  }
  while(loop == 0){
    
    printf("====================================================================================\n");
    printf("==============================Operações com listas==================================\n");
    printf("====================================================================================\n");
    printf("1  - Inserir aluno no começo \n");
    printf("2  - Inserir aluno no final \n");
    printf("3  - Inserir aluno ordenamente de acordo com a matrícula \n");
    printf("4  - Inserir aluno de acordo com a posição \n");
    printf("5  - Remover aluno do começo da lista\n");
    printf("6  - Remover aluno do final da lista\n");
    printf("7  - Remover aluno de acordo com a sua matricula\n");
    printf("8  - Descobrir o tamanho atual da lista\n");
    printf("9  - A lista está cheia?\n");
    printf("10 - A lista está vazia?\n");
    printf("11 - Acessar os dados de determinado aluno na lista de acordo com a sua posição\n");
    printf("12 - Acessar os dados de determinado aluno na lista de acordo com a sua matrícula\n");
    printf("13 - Imprimir lista\n");
    printf("14 - Destruir lista\n");
    printf("15 - Fechar programa\n");
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
          
      if(insere_lista_inicio(L,aluno) == -1){
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
        
      if(insere_lista_final(L,aluno) == -1){
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
        
      if(insere_lista_ordenada(L,aluno) == -1){
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
      
      if(insere_lista_pos(L, pos, aluno) == -1){
          printf("ERRO!!!\n");
      }
      
    }
    else
    if(opcao == 5){  
        if(remove_lista_inicio(L) == -1){
          printf("Erro!!!\n");
        }
    }
    else
    if(opcao == 6){
        if(remove_lista_final(L) == -1){
          printf("Erro!!!\n");
        }
    }
    else
    if(opcao == 7){  
        int matricula = 0;
        printf("Digite a matricula do aluno a ser removido: ");
        scanf("%d",&matricula);
        
        if(remove_lista_mat(L, matricula)){
          printf("Erro!!!\n");
        }
    }
    else
    if(opcao == 8){
        
        int x = 0;
        x = tamanho_lista(L);
        
        if(x == -1){
          printf("Erro!!!\n");
        }
        else{
        printf("Tamanho da lista = %d \n",x);
        }
    }
    else
    if(opcao == 9){
      int x = 0;
      x = lista_cheia(L);
      
      if(x == -1){
        printf("Erro!!!\n");
      }
      else
      if(x == 0){
        printf("False\n");
      } 
    } 
    else
    if(opcao == 10){
      int x = 0;
      x = lista_vazia(L);
      
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
    if(opcao == 11){
        int x = 0;
        
        printf("Digite a posição do aluno a ser consultado: \n");
        scanf("%d",&x);
        
        if(consulta_lista_pos(L, x, &aluno) == -1){
          printf("Erro!!!\n");
        }
        else{
          imprime_aluno(&aluno);
        } 
    } 
    else
    if(opcao == 12){
        int matricula = 0;
        
        printf("Digite a matricula do aluno a ser consultado: \n");
        scanf("%d",&matricula);
        
        if(consulta_lista_mat(L,matricula,&aluno) == -1){
          printf("Erro!!!\n");
        } 
        else{
          imprime_aluno(&aluno);
        } 
   }
  else
  if(opcao == 13){
    if(imprime_lista(L) == -1){
      printf("ERRO!!!\n");
    }
  }
  else
  if(opcao == 14){
    if(libera_lista(L) == -1){
      printf("Erro!!!\n");
    }
  }
  else
  if(opcao == 15){
    exit(1);
  }
}// fecha o while

return 0;
}







