#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "D_LINKED_LIST_2.h"

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
    
    printf("====================================================================================\n");
    printf("==============================Operações com listas==================================\n");
    printf("====================================================================================\n");
    printf("1  - Inserir aluno no começo \n");
    printf("2  - Inserir aluno no final \n");
    printf("3  - Inserir aluno ordenamente de acordo com a matrícula \n");
    printf("4  - Inserir aluno de acordo com a posição \n");
    printf("5  - Remover aluno do começo da lista\n");
    printf("6  - Remover aluno do final da lista\n");
    printf("7  - Remover aluno de acordo com a posição\n");
    printf("8  - Remover aluno de acordo com a matricula\n");
    printf("9  - Descobrir o tamanho atual da lista\n");
    printf("10 - Descobrir posição de determinada matricula\n");
    printf("11 - A lista está cheia?\n");
    printf("12 - A lista está vazia?\n");
    printf("13 - Acessar os dados de determinado aluno na lista de acordo com a sua posição\n");
    printf("14 - Acessar os dados de determinado aluno na lista de acordo com a sua matrícula\n");
    printf("15 - Acessar os dados do primeiro aluno\n");
    printf("16 - Acessar os dados do último aluno\n");
    printf("17 - Imprimir lista\n");
    printf("18 - Destruir lista\n");
    printf("19 - Fechar programa\n");
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
        int pos = 0;
        printf("Digite a posição do aluno a ser removido: ");
        scanf("%d",&pos);
        
        if(list_erase(L, pos) == -1){
          printf("Erro!!!\n");
        }
    }
    else
    if(opcao == 8){  
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
    else
    if(opcao == 11){
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
    if(opcao == 12){
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
    if(opcao == 13){
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
    if(opcao == 14){
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
  if(opcao == 15){
    if(list_front(L, &aluno) == -1){
      printf("ERRO!!!\n");
    }
    else{
      imprime_aluno(&aluno);
    }
  }
  else
  if(opcao == 16){
    if(list_front(L, &aluno) == -1){
      printf("ERRO!!!\n");
    }
    else{
      imprime_aluno(&aluno);
    }    
  }
  else
  if(opcao == 17){
    if(list_print(L) == -1){
      printf("ERRO!!!\n");
    };
  }
  else
  if(opcao == 18){
    if(list_free(L) == -1){
      printf("Erro!!!\n");
    }
  }
  else
  if(opcao == 19){
    exit(1);
  }
  
}// fecha o while

return 0;
}

