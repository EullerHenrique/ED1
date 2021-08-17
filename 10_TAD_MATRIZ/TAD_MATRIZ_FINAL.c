/*
Nome:  Euller Henrique Bandeira Oliveira
Matricula:  11821BSI210
*/

/* TMAT2D.h */
typedef struct Tmat2d Tmat2d;

Tmat2d *criarmat(int NLIN,int NCOL);
int prencher(Tmat2d *mat, int maximo);

int escrever_elem(Tmat2d *mat, int NLIN, int NCOL, double valor);
int acessa_elem(Tmat2d *mat, int NLIN, int NCOL, double *valor);

int somar(Tmat2d *mat, Tmat2d *mat2, Tmat2d *mat3);

int multiplicar(Tmat2d *mat, Tmat2d *mat2, Tmat2d *mat3);
int multiplica_escalar(Tmat2d *mat, Tmat2d *mat3, int x);

double traco(Tmat2d *mat, double *soma_diagonal);

double *soma_linha(Tmat2d *mat);
double *soma_coluna(Tmat2d *mat);

int libera(Tmat2d *mat);

/* TMAT2D.c */

#include <stdlib.h>
#include <time.h>

#include "TMAT2D.h"

struct Tmat2d{
  double *dados;
  int NLINHAS;
  int NCOLUNAS;

};


Tmat2d *criarmat(int NLIN, int NCOL){
  
  Tmat2d *mat = NULL;
  mat = malloc(1 * sizeof(Tmat2d));
  
  if(mat == NULL || NLIN < 0 || NCOL < 0){
    return NULL;
  }
  
  mat -> dados = malloc(NLIN * NCOL * sizeof(double));
  if(mat -> dados == NULL){
    return NULL;
  }
  
  mat -> NLINHAS = NLIN;
  mat -> NCOLUNAS = NCOL;

  return mat;
}

int prencher(Tmat2d *mat, int maximo){
  if(mat == NULL){
    return -1;
  }
    
  srand(time(NULL));
  
  for(int i = 0; i < mat -> NLINHAS; i++){
    for(int j = 0; j < mat -> NCOLUNAS; j++){
      mat -> dados[(j * mat -> NLINHAS) + i] = (rand()/(double)RAND_MAX) * maximo;
    }
  }
  
return 0;  
}

int escrever_elem(Tmat2d *mat, int NLIN, int NCOL, double valor){
  
  if(mat == NULL || NLIN >= mat -> NLINHAS || NCOL >= mat -> NCOLUNAS || NLIN < 0  || NCOL < 0 ){
    return -1;
  }    
    
  mat -> dados [ NCOL * mat -> NLINHAS + NLIN] = valor;
    
return 0;  
}


int acessa_elem(Tmat2d *mat, int NLIN, int NCOL, double *valor){
  
  if(mat == NULL || NLIN >= mat -> NLINHAS || NCOL >= mat -> NCOLUNAS || NLIN < 0  || NCOL < 0 ){
    return -1;
  }   
    
  *valor = mat -> dados [ NCOL * mat -> NLINHAS + NLIN];
    
return 0;  
}

int somar(Tmat2d *mat, Tmat2d *mat2, Tmat2d *mat3){
  
  if(mat == NULL || mat2 == NULL || mat3 == NULL || mat -> NLINHAS !=  mat2 -> NLINHAS || mat -> NCOLUNAS != mat2 -> NCOLUNAS){
    return -1;
  }
  
  for(int i = 0; i < mat3 -> NLINHAS; i++){
    for(int j = 0; j < mat3 -> NCOLUNAS; j++){
      
      mat3 -> dados[j * mat3 -> NLINHAS + i] = mat -> dados[j * mat -> NLINHAS + i] + mat2 -> dados[j * mat2 -> NLINHAS + i];     
    }
  }
    
  return 0;
}

int multiplicar(Tmat2d *mat, Tmat2d *mat2, Tmat2d *mat3){

  if(mat == NULL || mat2 == NULL || mat3 == NULL || mat -> NCOLUNAS != mat2 -> NLINHAS ){
    return -1;
  }
      
  for(int i = 0; i < mat3 -> NLINHAS; i++){
    
    for(int j = 0; j < mat3 -> NCOLUNAS; j++){
          
      mat3 -> dados [(j * mat3 -> NLINHAS) + i] = 0;
          
      for(int k = 0; k < mat2 -> NLINHAS; k++){
        
        mat3 -> dados[(j * mat3 -> NLINHAS) + i] += mat -> dados[(k * mat -> NLINHAS) + i] * mat2 -> dados[(j * mat2 -> NLINHAS) + k];     
      }
    }
  }    
  
return 0;
}

int multiplica_escalar(Tmat2d *mat, Tmat2d *mat3,int x){
  
  if(mat == NULL || mat3 == NULL){
    return -1;
  }
      
  for(int i = 0; i < mat3 -> NLINHAS ; i++){
    
    for(int j = 0; j < mat3 -> NCOLUNAS; j++){
        
      mat3 -> dados [(j * mat3 -> NLINHAS) + i] = 0;
        
      for(int k = 0; k < mat3 -> NLINHAS; k++){
        
        mat3 -> dados[(j * mat3 -> NLINHAS) + i] = mat -> dados[(j * mat -> NLINHAS) + i] * x;     
      }
    }
  }
  return 0;
}

double traco(Tmat2d *mat, double *soma_diagonal){
  if(mat == NULL){
    return -1;
  }
      
  for(int i = 0; i < mat -> NLINHAS; i++){
      *soma_diagonal = mat-> dados[(i * mat-> NLINHAS) + i] + *soma_diagonal;
  }
  return 0;
}

double *soma_linha(Tmat2d *mat){
  if(mat == NULL){
    return NULL;
  }

  double *soma = NULL;
  soma = malloc(mat -> NLINHAS * sizeof(double));
  
  if(soma == NULL){
    return NULL;
  }
  
  for(int i = 0; i < mat -> NLINHAS; i++){	
    for(int j = 0; j < mat -> NCOLUNAS; j++){
      soma[i] = mat -> dados[(j * mat -> NLINHAS) + i] + soma[i];
  }  
}
  
return soma;
}

double *soma_coluna(Tmat2d *mat){
  if(mat == NULL){
    return NULL;
  }
  
  double *soma;
  soma = malloc(mat-> NCOLUNAS *sizeof(double));
  
  if(soma == NULL){
    return NULL;
  }
  
  for(int i = 0; i < mat-> NLINHAS; i++){
    for(int j = 0; j < mat -> NCOLUNAS; j++){	
      soma[j] = mat -> dados[(j * mat -> NLINHAS) + i] + soma[j];
  }	
}
  
return soma;
}

int libera(Tmat2d *mat){
  if(mat == NULL){
    return -1;
  }
  free(mat -> dados);
  free(mat);
}

/* MAIN.c*/

// Quais dados serão armazenados?
// O número de linhas, número de colunas e os próprios dados.

// Quais operações serão necessárias?

// Criar/destruir o TAD
// Escrever elemento i,j
// Acessar elemento i,j
// Preencher com números aleatórios entre um valor mínimo e máximo
// Somar duas matrizes
// Multiplicar duas matrizes
// Multiplicar uma matriz por um valor escalar
// Calcular o Traço da matriz
// Retornar um vetor com a soma das linhas
// Retornar um vetor com a soma das colunas

#include <stdio.h>
#include <stdlib.h>
#include "TMAT2D.h"

void menu(void){
  int opcao = 0;
  printf("\n");
  printf("============================================================================\n");
  printf("==============================Operações com matrizes========================\n");
  printf("============================================================================\n");
  printf("1 - Criar e prencher com números aleatórios a primeira matriz\n");
  printf("2 - Criar e prencher com números aleatórios a segunda matriz \n");
  printf("3 - Imprimir as duas matrizes\n");                              
  printf("4 - Escrever determinado elemento em determinada posição da primeira matriz\n");
  printf("5 - Escrever determinado elemento em determinada posição da segunda matriz \n");
  printf("6 - Acessar determinado elemento de determinada posição da primeira matriz \n");
  printf("7 - Acessar determinado elemento de determinada posição da segunda matriz  \n");
  printf("8 - Somar as duas matrizes              \n");
  printf("9 - Multiplicar as duas matrizes        \n");
  printf("10- Multiplicar a primeira matriz por um valor escalar \n");
  printf("11- Multiplicar a segunda matriz por um valor escalar  \n");
  printf("12- Calcular o traço da primeira matriz  \n");
  printf("13- Calcular o traço da segunda matriz   \n");
  printf("14- Calcular a soma das linhas da primeira matriz \n");
  printf("15- Calcular a soma das linhas da segunda matriz  \n");
  printf("16- Calcular a soma das colunas da primeira matriz\n");
  printf("17- Calcular a soma das colunas da segunda matriz \n");
  printf("18- Liberar o espaço de memória utilizado\n");
  printf("19- Fechar o programa\n\n");
  
  printf("Digite a opção desejada: ");
return;
}


Tmat2d *fcriarmat(int NLIN,int NCOL){
  Tmat2d *mat;

  mat = criarmat(NLIN,NCOL);
  
  if(mat == NULL){
    printf("Erro ao alocar matriz\n");
  }
  
return mat;
  
}

void fprencher(Tmat2d *mat){
  
  int maximo  = 0;
  printf("\nDetermine o valor máximo dos números aleatórios: ");
  scanf("%d",&maximo);
  
  if(prencher(mat,maximo) == -1){
    printf("Erro!!!\n");  
    return;
  }
return;  
}

void imprimir_matriz(Tmat2d *mat, int NLIN, int NCOL){
  
  printf("\n");
  double x = 0;
  
  for(int i = 0; i < NLIN; i++){
    for(int j = 0; j < NCOL; j++){
      
      if(acessa_elem(mat,i,j,&x) == -1){
        printf("Erro!!!\n");
      }
      else{
        printf("%lf ",x);
      }
    }
    printf("\n");
  }
  printf("\n");
}

 void fescrever_elemento(Tmat2d *mat){
   int linha = 0;
   int coluna = 0;
   double x = 0;
   
   printf("Digite a linha: ");
   scanf("%d",&linha);
   printf("Digite a coluna: ");
   scanf("%d",&coluna);
   printf("\n");
     
   printf("Digite o valor do elemento\n");
   scanf("%lf",&x);
   
   if(escrever_elem(mat, linha, coluna, x) == -1){
        printf("Erro!!!\n");
    }
    
return;    
}

void facessar_elemento(Tmat2d *mat){
  
  int linha = 0;
  int coluna = 0;
  double x = 0;
  
  printf("Digite a linha: ");
  scanf("%d",&linha);
  printf("Digite a coluna: ");
  scanf("%d",&coluna);
  printf("\n");
  
  if(acessa_elem(mat, linha, coluna,&x) == -1){
    printf("Erro!!!\n");
    return;
  }
  else{
  printf("O valor do elemento presente na linha %d e na coluna %d é %lf \n",linha,coluna,x);
  }
  
return;  
}

void fsomar_matrizes(Tmat2d *mat, Tmat2d *mat2, Tmat2d *mat3, int NLIN1, int NCOL1, int NLIN2, int NCOL2){ 
  
  if(somar(mat,mat2,mat3) == -1){
    printf("Erro!!!\n");
    return;
  }
  
  printf("\nSoma das matrizes\n\n");
  
  printf("Primeira matriz\n");
  imprimir_matriz(mat,NLIN1, NCOL1);
  printf("Segunda matriz\n");
  imprimir_matriz(mat2,NLIN2, NCOL2);
  printf("Resultados\n");
  imprimir_matriz(mat3,NLIN1, NCOL1);

return;  
}

void fmultiplicar_matrizes(Tmat2d *mat,Tmat2d *mat2, Tmat2d *mat3, int NLIN1, int NCOL1, int NLIN2, int NCOL2){
  
  if(multiplicar(mat,mat2,mat3) == -1){
    printf("Erro!!!\n");
  }
  
  printf("Multiplicação das matrizes\n\n");
  
  printf("Primeira matriz\n");
  imprimir_matriz(mat,NLIN1, NCOL1);
  printf("Segunda matriz\n");
  imprimir_matriz(mat2,NLIN2, NCOL2);
  
  printf("Resultados\n");
  imprimir_matriz(mat3,NLIN1, NCOL2);

return;
}

void f_multiplica_matriz_por_escalar(Tmat2d *mat, Tmat2d *mat3,int NLIN, int NCOL){
  
  printf("\n");
  int x = 0;
  
  printf("Multiplicação de uma matriz por um valor escalar\n\n");
  printf("Digite o valor escalar\n");
  scanf("%d",&x);
  
  if(multiplica_escalar(mat,mat3,x) == -1){
    printf("Erro!!!\n");
  }
  
  printf("\nMatriz\n");
  imprimir_matriz(mat,NLIN,NCOL);
  printf("Resultado\n");
  imprimir_matriz(mat3,NLIN,NCOL);

return;
}

void ftraco(Tmat2d *mat){
  double soma_diagonal = 0;
  
  if(traco(mat,&soma_diagonal) == -1){
    printf("Erro!!!\n");
  }
  else{
    printf("\nA soma da diagonal principal é %lf\n",soma_diagonal);
  }

return;
}

void fsomalinhas(Tmat2d *mat, int NLIN){
  
  double *soma = NULL;
  soma = soma_linha(mat);
  
  if(soma == NULL){
    printf("Erro!!!\n");
    return;
  }
  
  printf("\nSoma das linhas da matriz\n");
  for(int i = 0; i < NLIN; i++){
    printf("Soma da linha %d = %lf\n",i+1,soma[i]);
  }
  
  free(soma);
return;
}

void fsomacolunas(Tmat2d *mat,int NCOL){
  
  double *soma = NULL;
  soma = soma_coluna(mat);
  
  if(soma == NULL){
    printf("Erro!!!\n");
    return;
  }
  
  printf("\nSoma das colunas da matriz\n");
  for(int i = 0; i < NCOL; i++){
    printf("Soma da coluna %d = %lf\n",i+1,soma[i]);
  }
  free(soma);
return;
}

int main(void){
  Tmat2d *mat = NULL;
  Tmat2d *mat2 = NULL;
  Tmat2d *mat3 = NULL;
  
  int loop = 0;
  int opcao = 0;  
  
  int NLIN1 = 0;
  int NCOL1 = 0;
  
  int NLIN2 = 0;
  int NCOL2 = 0;

  while(loop == 0){
  
    menu();
    scanf("%d",&opcao);  
    
    if(opcao == 1){
      printf("\n");
      printf("=============TAMANHO DA PRIMEIRA MATRIZ===============\n");
      printf("Digite a quantidade de linhas da primeira matriz: ");
      scanf("%d",&NLIN1);
      printf("Digite a quantidade de colunas da primeira matriz: ");
      scanf("%d",&NCOL1);
      printf("======================================================\n");
      
      mat = fcriarmat(NLIN1,NCOL1);
      fprencher(mat);
    }
    else
    if(opcao == 2){
      printf("=============TAMANHO DA SEGUNDA MATRIZ===============\n");
      printf("Digite a quantidade de linhas da segunda matriz: ");
      scanf("%d",&NLIN2);
      printf("Digite a quantidade de colunas da segunda matriz: ");
      scanf("%d",&NCOL2);
      printf("======================================================\n");
      
      mat2 = fcriarmat(NLIN2,NCOL2);
      fprencher(mat2);
      
    }
    else
    if(opcao == 3){
        printf("\nPrimeira matriz\n");
        imprimir_matriz(mat,NLIN1,NCOL1);
        printf("Segunda matriz\n");
        imprimir_matriz(mat2,NLIN2,NCOL2);
    }
    else
    if (opcao == 4){
        fescrever_elemento(mat);
    }
    else
    if (opcao == 5){
      fescrever_elemento(mat2);
    }
    else
    if(opcao == 6){
      facessar_elemento(mat);
    }
    else
    if(opcao == 7){
      facessar_elemento(mat2);
    }
    else
    if(opcao == 8){
      mat3 = fcriarmat(NLIN1,NCOL1);
      fsomar_matrizes(mat,mat2,mat3,NLIN1,NCOL1,NLIN2,NCOL2);
      libera(mat3); 
    }
    else
    if(opcao == 9){
      mat3 = fcriarmat(NLIN1,NCOL2);
      fmultiplicar_matrizes(mat,mat2,mat3,NLIN1,NCOL1,NLIN2,NCOL2);
      libera(mat3); 
    }
    else
    if(opcao == 10){
      mat3 = fcriarmat(NLIN1,NCOL1);
      f_multiplica_matriz_por_escalar(mat,mat3,NLIN1,NCOL1);
      libera(mat3); 
    }
    else
    if(opcao == 11){
      mat3 = fcriarmat(NLIN2,NCOL2);
      f_multiplica_matriz_por_escalar(mat2,mat3,NLIN2,NCOL2);
      libera(mat3); 
    }
    else
    if(opcao == 12){
      ftraco(mat);
    }
    else
    if(opcao == 13){
      ftraco(mat2);
    }
    else
    if(opcao == 14){
      fsomalinhas(mat,NLIN1);
    }
    else
    if(opcao == 15){
      fsomalinhas(mat2,NLIN2);
    }
    else
    if(opcao == 16){
      fsomacolunas(mat,NCOL1);
    }
    else
    if(opcao == 17){
      fsomacolunas(mat2,NCOL2);
    }
    else
    if (opcao == 18){
      if(libera(mat) == -1 || libera(mat2) == -1){
        printf("Erro!!!\n");
      }
    }
    else
    if(opcao == 19){
      exit(1);
    }
  }
  
  return 0;
}



