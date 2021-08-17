/*
Nome:  Euller Henrique Bandeira Oliveira
Matricula:  11821BSI210
*/

/*Questão 01

//LISTA.h

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

/*LISTA.c

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



/*MAIN_LISTA.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LISTA.h"


void imprime_aluno(ALUNO *aluno){

  if(aluno == NULL){
    printf("Erro!!!\n");
    return;
  }
  
  printf("Nome: %s\n", aluno[0].nome);
  printf("Matricula: %d\n",aluno[0].matricula);
  printf("Nota da primeira prova: %f \n",aluno[0].notas[0]);
  printf("Nota da segunda  prova: %f \n",aluno[0].notas[1]);
  printf("Nota da terceira prova: %f \n",aluno[0].notas[2]);      
  printf("Nota da terceira prova: %f \n",aluno[0].notas[3]);   
  
 }

int main(void){  
  LISTA *L = NULL;
  ALUNO aluno;
  
  int opcao = 0;
  int loop = 0;
  int x = 0;

  
  while(loop == 0){
    printf("======================================================================\n");
    printf("========================Operações com listas =========================\n");
    printf("======================================================================\n");
    printf("1  - Criar lista\n");
    printf("2  - Inserir aluno no começo \n");
    printf("3  - Inserir aluno no final \n");
    printf("4  - Inserir aluno ordenamente \n");
    printf("5  - Remover aluno do começo da lista\n");
    printf("6  - Remover aluno do final da lista\n");
    printf("7  - Remover aluno pela sua matricula\n");
    printf("8  - Descobrir o tamanho atual da lista\n");
    printf("9  - Acessar os dados de determinado aluno na lista pela sua posição\n");
    printf("10 - Acessar os dados de determinado aluno na lista pela sua matricula\n");
    printf("11 - Imprimir lista\n");
    printf("12 - Destruir lista\n");
    printf("13 - Fechar programa\n");
    printf("Digite a opção desejada: ");  
    scanf("%d",&opcao);
    printf("\n");
    
    if(opcao == 1){
      L =  criar_lista();
      
      if(L == NULL){
        printf("Erro!!!\n");
      }
    }
    else
    if(opcao == 2){
      if(L ==  NULL){
        printf("Erro!!!\n");
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
          
          if(insere_lista_inicio(L,aluno) == -1){
            printf("Erro!!!\n");
          }
        }        
    }
    else
    if(opcao == 3){
      if(L ==  NULL){
        printf("Erro!!!\n");
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
        
        if(insere_lista_final(L,aluno) == -1){
          printf("Erro!!!\n");
        }
      }
    }
    else
    if(opcao == 4){
      if(L == NULL){
        printf("Erro!!!\n");
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
        
        if(insere_lista_ordenada(L,aluno) == -1){
          printf("Erro!!1\n");
        }
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
      if(L == NULL){
        printf("Erro!!!\n");
      }
      else{
        
        int matricula = 0;
        printf("Digite a matricula do aluno a ser removido: ");
        scanf("%d",&matricula);
        
        if(remove_lista_matricula(L, matricula)){
          printf("Erro!!!\n");
        }
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
      if(L == NULL){
        printf("Erro!!!\n");
      }
      else{
        int x = 0;
        
        printf("Digite a posição do aluno a ser consultado: \n");
        scanf("%d",&x);
        
        if(consulta_lista_pos(L,&aluno, x) == -1){
          printf("Erro!!!\n");
        }
        else{
          imprime_aluno(&aluno);
        } 
      } 
    }
    else
    if(opcao == 10){
      if(L == NULL){
        printf("Erro!!!\n");
      }
      else{

        int matricula = 0;
        
        printf("Digite a matricula do aluno a ser consultado: \n");
        scanf("%d",&matricula);
        
        if(consulta_lista_matricula(L,&aluno,matricula) == -1){
          printf("Erro!!!\n");
        } 
        else{
          imprime_aluno(&aluno);
        } 
      }
    }
    else
    if(opcao == 11){
      
        int x = 0 ;
        x = tamanho_lista(L);
      
        if(x == -1){
          printf("Erro!!!!\n");
        }
        
        for(int i = 0; i < x; i++){
          if(consulta_lista_pos(L,&aluno, i+1) == -1){
            printf("Erro!!!\n");
          }
          else{
            imprime_aluno(&aluno);
          }
        }
        
    }
    else
    if(opcao == 12){
      if(libera_lista(L) == -1){
        printf("Erro!!!\n");
      }
    }
    else
    if(opcao == 13){
      exit(1);
    }
  }

return 0;
}


/*Questão 02

/* LISTA_MODIFICADA.h */

typedef struct{
  char nome[100];
  int matricula;
  float notas[4];
  int faltas;
}ALUNO;
  
typedef struct LISTA LISTA;

LISTA *criar_lista();

int tamanho_lista_atual(LISTA* L);
int tamanho_lista_maximo(LISTA *L);

int lista_cheia(LISTA *L);
int lista_vazia(LISTA *L);

int insere_lista_inicio(LISTA *L, ALUNO aluno);
int insere_lista_final(LISTA *L, ALUNO aluno);
int insere_lista_ordenada(LISTA *L, ALUNO aluno);

int compactar_lista(LISTA *L);

int remove_lista_inicio(LISTA *L);
int remove_lista_final(LISTA *L);
int remove_lista_matricula(LISTA* L, int matricula);

int consulta_lista_pos(LISTA *L, ALUNO *aluno, int pos);
int consulta_lista_matricula(LISTA *L, ALUNO *aluno, int matricula);

int libera_lista(LISTA* L); 

/* LISTA_MODIFICADA.c */

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "LISTA_MODIFICADA.h"

struct LISTA{
  ALUNO *aluno;
  int tamanho_maximo_inicial;
  int tamanho_maximo_final;
  int qtd;
}; 
  
LISTA* criar_lista(int MAX){
  LISTA *L = NULL;
  L = malloc(1 * sizeof(LISTA)); 
  
  if(L == NULL || MAX < 0){
    return NULL;
  }
  
  L -> aluno = malloc(MAX * sizeof(ALUNO));
  if(L -> aluno == NULL){
    return NULL;
  }
  
  L  -> tamanho_maximo_inicial = MAX; 
  L  -> tamanho_maximo_final = MAX; 
  L  -> qtd = 0;

return L;  
}

int tamanho_lista_atual(LISTA* L){
  if(L == NULL){
    return -1;
  }

return L -> qtd;
}

int tamanho_lista_maximo(LISTA *L){
  if(L == NULL){
    return -1;
  }
return L -> tamanho_maximo_final;
}

int lista_cheia(LISTA *L){
  if(L == NULL){
    return -1;
  }
  else
  if( L -> qtd == L -> tamanho_maximo_final){
    return 1;
  }
  else{
   return 0;
  }
}

int lista_vazia(LISTA *L){
  if(L == NULL){
    return -1;
  }
  else
  if(L -> qtd  == 0){
    return 1;
  }
  else{
    return 0;
  }
}

int insere_lista_inicio(LISTA *L, ALUNO aluno){
  
  if(L == NULL){
    return -1;
  }
  else
  if(L -> qtd == L -> tamanho_maximo_final){
    L -> tamanho_maximo_final = L -> qtd + L-> tamanho_maximo_inicial;
    L -> aluno = realloc(L -> aluno, L -> tamanho_maximo_final * sizeof(ALUNO));
    if(L -> aluno == NULL){
      return -1;
    }
  }
  
  for(int i = L -> qtd - 1; i >= 0; i--){ // Desloca tudo para direita
    L -> aluno[i+1] = L -> aluno[i];
  }

  L -> aluno[0] = aluno; // Insere o aluno na primeira posição da lista
  L -> qtd = L -> qtd + 1;

return 0;
}

int insere_lista_final(LISTA *L, ALUNO aluno){
  if(L == NULL){
    return -1;
  }
  else
  if(L -> qtd == L -> tamanho_maximo_final){
    L -> tamanho_maximo_final = L -> qtd + L -> tamanho_maximo_inicial; 
    L -> aluno = realloc(L -> aluno, L -> tamanho_maximo_final * sizeof(ALUNO));
    if(L -> aluno == NULL){
      return -1;
    }
  }
  
  L -> aluno[L -> qtd] = aluno; // insere o aluno na última posição da lista
  L -> qtd = L -> qtd + 1;

return 0;
}

int insere_lista_ordenada(LISTA *L,ALUNO aluno){
  
  if(L == NULL){
    return -1;
  }
  else
  if(L -> qtd == L -> tamanho_maximo_final){    
    L -> tamanho_maximo_final = L -> qtd + L-> tamanho_maximo_inicial; 
    L -> aluno = realloc(L -> aluno, L -> tamanho_maximo_final * sizeof(ALUNO));
    if(L -> aluno == NULL){
      return -1;
    }
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

int compactar_lista(LISTA *L){
  
  if(L == NULL){
    return -1;
  }
  
  L -> tamanho_maximo_final = ceil( (double)L -> qtd / (double)L -> tamanho_maximo_inicial) * (L -> tamanho_maximo_inicial);
    
  L -> aluno = realloc(L -> aluno,   L -> tamanho_maximo_final * sizeof(ALUNO));
  
  if(L -> aluno == NULL){
    return -1;
  }
  
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
  while(i < L-> qtd && L -> aluno[i].matricula != matricula){ // procura a posição que a matricula digitada está na lista
    i++;
  }
  
  if(i == L -> qtd){ // a matricula não foi encontrada
    return -1;
  }
  
  *aluno = L -> aluno[i]; 
  
return 0;  
}

int remove_lista_inicio(LISTA *L){
  if(L == NULL || L -> qtd == 0 || L -> qtd < 0){
    return -1;
  }
  
  for(int i = 0; i < L -> qtd - 1; i++){// Desloca para a esquerda
    L -> aluno[i] = L -> aluno[i + 1]; 
  }

  L-> qtd = L -> qtd - 1;
  
return 0;  
}

int remove_lista_final(LISTA *L){
   if (L == NULL || L -> qtd == 0 || L -> qtd < 0){
     return -1;
   }
   
   L -> qtd = L -> qtd - 1;

return 0;   
} 

int remove_lista_matricula(LISTA* L, int matricula){
  if(L == NULL || L -> qtd == 0 || L -> qtd < 0){
    return -1;
  }
  
  int i = 0;
  while(i < L -> qtd && L -> aluno[i].matricula != matricula){ //procura a posição que a matricula digitada está na lista
  i++;
  }
  
  if(i == L -> qtd){ //a matricula não foi encontrada
    return -1;
  }
  
  for(int j = i; j < L -> qtd - 1; j++){ // desloca tudo pra esquerda
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

/* MAIN_LISTA_MODIFICADA.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "LISTA_MODIFICADA.h"

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
  int MAX = 0; 
  
  printf("Digite o tamanho desejado da lista: ");
  scanf("%d",&MAX);
  
  L =  criar_lista(MAX);
  
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
    printf("4  - Remover aluno do começo da lista\n");
    printf("5  - Remover aluno do final da lista\n");
    printf("6  - Remover aluno de acordo com a sua matricula\n");
    printf("7  - Descobrir o tamanho atual da lista\n");
    printf("8  - Descobrir o tamanho máximo da lista \n");
    printf("9  - A lista está cheia?\n");
    printf("10 - A lista está vazia?\n");
    printf("11 - Acessar os dados de determinado aluno na lista de acordo com a sua posição\n");
    printf("12 - Acessar os dados de determinado aluno na lista de acordo com a sua matrícula\n");
    printf("13 - Compactar lista \n");
    printf("14 - Imprimir lista\n");
    printf("15 - Destruir lista\n");
    printf("16 - Fechar programa\n");
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
        printf("Erro!!1\n");
      }
    }
    else
    if(opcao == 4){  
        if(remove_lista_inicio(L) == -1){
          printf("Erro!!!\n");
        }
    }
    else
    if(opcao == 5){
        if(remove_lista_final(L) == -1){
          printf("Erro!!!\n");
        }
    }
    else
    if(opcao == 6){  
        int matricula = 0;
        printf("Digite a matricula do aluno a ser removido: ");
        scanf("%d",&matricula);
        
        if(remove_lista_matricula(L, matricula)){
          printf("Erro!!!\n");
        }
    }
    else
    if(opcao == 7){
        
        int x = 0;
        x = tamanho_lista_atual(L);
        
        if(x == -1){
          printf("Erro!!!\n");
        }
        else{
        printf("Tamanho atual da lista = %d \n",x);
        }
    }
    else
    if(opcao == 8){
      int x = 0;
      x = tamanho_lista_maximo(L);
      
      if(x == -1){
        printf("Erro!!!\n");
      }
      else{
        printf("Tamanho máximo da lista = %d \n",x);
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
      if(x == 1){
        printf("True\n");
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
        
        if(consulta_lista_pos(L,&aluno, x) == -1){
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
        
        if(consulta_lista_matricula(L,&aluno,matricula) == -1){
          printf("Erro!!!\n");
        } 
        else{
          imprime_aluno(&aluno);
        } 
   }
  else
    if(opcao == 13){
      if(compactar_lista(L) == -1){
        printf("Erro!!!\n");
      }      
    }
    else
    if(opcao == 14){
      
        int x = 0 ;
        x = tamanho_lista_atual(L);
      
        if(x == -1){
          printf("Erro!!!!\n");
        }
        else{
          for(int i = 0; i < x; i++){
            if(consulta_lista_pos(L,&aluno, i+1) == -1){
              printf("Erro!!!\n");
            }
            else{
              imprime_aluno(&aluno);
            }
          } 
      } 
    }
    else
    if(opcao == 15){
      if(libera_lista(L) == -1){
        printf("Erro!!!\n");
      }
    }
    else
    if(opcao == 16){
      exit(1);
    }
  }

return 0;
}





