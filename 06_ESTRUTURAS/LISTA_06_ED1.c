/* Questão 01*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
	double *produtos = NULL;
	int n = 0;
	int i = 0;
	
	printf("Informe o número de produtos: ");
	scanf("%d",&n);
	
	// é necessário usar o comando malloc para alocar a memória
	produtos = (double *) malloc(n*sizeof(double));
	
	for (i = 0; i < n; i++){
	printf("Informe o valor do produto %d R$:",i+1);
	scanf("%lf", &produtos[i]);
	}
	
	printf("\nProdutos cadastrados\n");
	for (i = 0; i < n; i++){
	printf("Produto %d - R$: %f\n",i+1, produtos[i]);
	}
	
	// ao terminar de usar o vetor, devemos liberar a memória
	free(produtos);

	return 0;
}

/* 

n =  tamanho do vetor desejado.
sizeof(double) = tamanho em bytes do tipo double
(n * sizeof(double)) = quantidade de bytes desejado

 */
  


/* Questão 02*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
	int *numeros = NULL;

	numeros = (int *) malloc(5 * sizeof(int));

	for(int i = 0; i < 5; i++){
		scanf("%d",&numeros[i]);
	}

	for(int i = 0; i < 5; i++){
		printf("%d ",numeros[i]);
	}
	printf("\n");

	free(numeros);
return 0;
}

/* Questão 03*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n = 0;
	int par = 0;
	int impar = 0;
	int *numeros = NULL;

	printf("Quantos números você deseja digitar? ");
	scanf("%d",&n);

	numeros = (int*) malloc(n * sizeof(int));

	for(int i = 0; i < n; i++){
		scanf("%d", &numeros[i]);
	}

	for(int i = 0; i < n; i++){
		if(numeros[i] % 2 == 0){
			par++;
		}
		else{
			impar++;
		}
		
	}

	printf("%d números são pares",par);
	printf("\n");
	printf("%d números são impares",impar);
	printf("\n");

	free(numeros);

return 0;
}


/* Questão 04*/

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int x;
	int y;
} coordenadas;

int main (void){
	int n = 0;
	coordenadas *vet = NULL;

	printf("Quantos pontos deseja digitar: ");
	scanf("%d",&n);

	vet = (coordenadas*) malloc(n * sizeof(coordenadas));

	for(int i = 0; i < n; i++){
		printf("Entre com a coordenada x do ponto %d: ",i+1);
		scanf("%d",&vet[i].x);
		printf("Entre com a coordenada y do ponto %d: ",i+1);
		scanf("%d",&vet[i].y);
	}

	printf("Pontos digitados: ");
	for(int i = 0; i < n; i++){
		printf("(%d, %d),",vet[i].x,vet[i].y);
	}
	printf("\n");

	free(vet);

return 0;
}

/* Questão 05*/
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int x;
	int y;
} coordenadas;

int main (void){
	int n = 0;
	
	coordenadas *vet = NULL;
	int  *maior_x = NULL;
	int  *menor_x = NULL;
	int  *maior_y = NULL;
	int  *menor_y = NULL;

	printf("Quantos pontos deseja digitar: ");
	scanf("%d",&n);

	vet = (coordenadas*) malloc(n * sizeof(coordenadas));

	for(int i = 0; i < n; i++){
		printf("Entre com a coordenada x do ponto %d: ",i+1);
		scanf("%d",&vet[i].x);
		printf("Entre com a coordenada y do ponto %d: ",i+1);
		scanf("%d",&vet[i].y);
	}

	maior_x = &vet[0].x; // OBS : PONTEIROS SOMENTE RECEBEM ENDEDERÇOS!!!
	menor_x = &vet[0].x;

	maior_y = &vet[0].y;
	menor_y = &vet[0].y;

	for(int i = 0; i < n; i++){
		if(vet[i].x > *maior_x){
			maior_x = &vet[i].x;
		}
		
		if(vet[i].x < *menor_x){
			menor_x = &vet[i].x;
		}

		if(vet[i].y > *maior_y){
			maior_y = &vet[i].y;
		}

		if(vet[i].y < *menor_y){
			menor_y = &vet[i].y;
		}
	}

	printf("Ponto mais a esquerda: %d ",*menor_x);
	printf("\n");
	printf("Ponto mais a direita: %d",*maior_x);
	printf("\n");
	printf("Ponto mais acima: %d", *maior_y);
	printf("\n");
	printf("Ponto mais abaixo: %d",*menor_y);
	printf("\n");

	free(vet);

return 0;
}
