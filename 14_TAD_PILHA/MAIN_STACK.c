#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "STACK.h"

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
  
  S =  stack_create();  
  if(S == NULL){
    printf("Erro!!!\n");
  }
  
  while(loop == 0){
    
    printf("====================================================================================\n");
    printf("==============================Operações com uma pilha==================================\n");
    printf("====================================================================================\n");
    printf("1 - Inserir aluno \n");
    printf("2 - Remover aluno \n");
    printf("3 - Acessar aluno\n");
    printf("4 - A lista está cheia?\n");
    printf("5 - A lista está vazia?\n");
    printf("6 - Descobrir o tamanho da lista\n");
    printf("7 - Imprimir pilha\n");
    printf("8 - Destruir pilha\n");
    printf("9 - Fechar programa\n");
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
          
      if(stack_push(S,aluno) == -1){
        printf("Erro!!!\n");
        }
    }
    else
    if(opcao == 2){
      if(stack_pop(S) == -1){
        printf("ERRO!!!\n");
      }
    }
    else
    if(opcao == 3){
      if(stack_top(S,&aluno) == -1){
        printf("ERRO!!!\n");
      }
      else{
        imprime_aluno(&aluno);
      }
    }
    else
    if(opcao == 4){
      int x = 0;
      x = stack_full(S);
      
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
    else
    if(opcao == 5){
      int x = 0;
      x = stack_empty(S);
      
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
    else
    if(opcao == 6){
      int qtd = 0;
      qtd = stack_size(S);
       
      if(qtd == -1){
        printf("ERRO!!!\n");
      }
      else{
        printf("O tamanho da pilha é %d \n",qtd);
      }
    }
    else
    if(opcao == 7){
      if(stack_print(S) == -1){
        printf("ERRO!!!\n");
      }
    }
    else
    if(opcao == 8){
      if(stack_free(S) == -1){
        printf("ERRO!!!\n");
      }
    }
    else
    if(opcao == 9){
      exit(1);
    }
  }
        
return 0;
}

