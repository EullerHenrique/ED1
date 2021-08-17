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


