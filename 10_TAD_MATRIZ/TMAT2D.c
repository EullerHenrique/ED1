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




