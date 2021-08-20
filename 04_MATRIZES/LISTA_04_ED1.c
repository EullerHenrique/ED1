/*

Nome : Euller Henrique Bandeira Oliveira
Matrícula : 11821BSI210

*/

/*LISTA_04_MATRIZES*/


/*Questão 01*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int mat1[4][4] = {0};
	int mat2[4][4] = {0};
	int soma[4][4] = {0};

	srand(time(NULL));

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			mat1[i][j] = (rand()/(double)RAND_MAX)*100;
			mat2[i][j] = (rand()/(double)RAND_MAX)*100;
		}
	}


	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			soma[i][j] =  mat1[i][j] + mat2[i][j];
		}
	}

	printf("Matriz 1: \n\n");

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			printf("%4d",mat1[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	printf("Matriz 2: \n\n");

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			printf("%4d",mat2[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	printf("Soma: \n\n");

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			printf("%4d",soma[i][j]);
		}
		printf("\n");
	}

return 0;
}

/*Questão 02*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int mat1[3][3] = {0};
	int mat2[3][3] ={0};
	int multiplica[3][3] ={0};

	srand(time(NULL));

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			mat1[i][j] = (rand()/(double)RAND_MAX)*10;
			mat2[i][j] = (rand()/(double)RAND_MAX)*10;
		}
	}

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			multiplica[i][j] = 0;
			for(int k = 0; k < 3; k++){
				multiplica[i][j] = multiplica[i][j] + mat1[i][k] * mat2[k][j];
			}
		}
	}

	printf("\n");
	printf("Matriz 1: \n\n");

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%4d",mat1[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	printf("Matriz 2: \n\n");

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%4d",mat2[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	printf("Multiplicação:\n\n");


	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%4d",multiplica[i][j]);
		}
		printf("\n");
	}

return 0;
}

/*Questão 03*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int mat1[3][4] = {0};
	int mat2[4][5] = {0};
	int multiplica[3][5] = {0};

	srand(time(NULL));

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 4; j++){
			mat1[i][j] = (rand()/(double)RAND_MAX)*10;
		}
	}

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 5; j++){
			mat2[i][j] = (rand()/(double)RAND_MAX)*10;
		}
	}

	for(int i = 0 ; i < 3 ; i++){ // i = indice do primeiro vetor da mat1
		 
		for(int j = 0, j2 = 0 ; j < 4, j2 < 5; j++,j2++){ // j = indice do primeiro vetor da mat2, j2 = indice do segundo vetor da mat2
			multiplica[i][j2] = 0;
	
			for(int k = 0, k2 = 0; k < 4, k2 < 4; k++,k2++){ // k = indice que acessa os valores do segundo vetor da mat1, k2 = indice que acessa os valores do primeiro vetor da mat2
				multiplica[i][j2] = multiplica[i][j2] + mat1[i][k] * mat2[k2][j2];
			}
		}
	}


	printf("\n");
	printf("Matriz 1: \n\n");

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 4; j++){
			printf("%4d",mat1[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	printf("Matriz 2: \n\n");

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 5; j++){
			printf("%4d",mat2[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	printf("Multiplicação:\n\n");

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 5; j++){
			printf("%4d",multiplica[i][j]);
		}
		printf("\n");
	}



	
return 0;
}

/*Questão 04*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int mat[5][8] = {0};
	int menor = 0;
	int posicao = 0;

	srand(time(NULL));

	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 8; j++){
			mat[i][j] = (rand()/(double)RAND_MAX)*100;
		}
	}

	menor = mat[0][0];

	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 8; j++){
			
			if(mat[i][j] < menor){
				menor = mat[i][j];
				posicao = j + 1;
			}
		}
	}

	printf("\n");
	printf("Matriz 5 X 8: \n\n");

	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 8; j++){
			printf("%4d",mat[i][j]);
		}
		printf("\n");
	}

	printf("Menor: %d \n",menor);
	printf("Posição: %d \n",posicao);

return 0;
}

/*Questão 05*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int mat[5][5] ={0};
	int soma = 0;
	srand(time(NULL));

	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			mat[i][j] = (rand()/(double)RAND_MAX)*100;
		}
	}

	printf("Matriz 5 X 5: \n\n");

	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			printf("%4d",mat[i][j]);
		}
		printf("\n");
	}


	for(int i = 0, j = 0; i < 5, j < 5; i++,j++){
			soma = mat[i][j] + soma;
 	}

 	printf("A soma da diagonal principal da matriz 5 X 5 é %d \n",soma);
	
return 0;
}

/*Questão 06*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int mat[3][3] = {0};
	int soma_linha[3]  = {0};
	int soma_coluna[3] = {0};
	int cont = 0;

	srand(time(NULL));

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			mat[i][j] = (rand()/(double)RAND_MAX)*100;
		}
	}

	printf("Matriz 3 X 3: \n\n");
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%4d",mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("Soma de cada linha: \n");
	for(int i = 0; i < 3; i++){	
		for(int j = 0; j < 3; j++){
			soma_linha[i] = mat[i][j] + soma_linha[i];
		}
	}

	for(int i = 0; i < 3; i++){
		printf("Linha %d = %d \n",i+1,soma_linha[i]);
	}
	printf("\n");

	printf("Soma de cada coluna: \n");	
	for(int j = 0; j < 3; j++){
		for(int i = 0; i < 3; i++){	
			soma_coluna[j] = mat[i][j] + soma_coluna[j];
		}
	}	

	for(int i = 0; i < 3; i++){
		printf("Coluna %d = %d \n",i+1,soma_coluna[i]);
	}
return 0;
}

/*Questão 07*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int simetria(int mat[][3], int mat2[][3]){
	for(int i  = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(mat[i][j] == mat[j][i]){
				return 1;
				
			}
			else{
				return 0;
			}
		}
	}
}

int main(void){
	int mat[3][3] = {0};
	int mat2[3][3] ={0};
	int opcao = 0;

	srand(time(NULL));

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			mat[i][j] = (rand()/(double)RAND_MAX)*100;
		}
	}

	printf("Matriz 3 X 3: \n\n");
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%4d",mat[i][j]);
		}
		printf("\n");
	}

	for(int i = 0; i < 3; i++){
		for(int j = 0 ; j < 3; j++){
			mat2[j][i] = mat[i][j];
		}
	}

	printf("\n");
	printf("Matriz 3 X 3: \n\n");
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%4d",mat2[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	opcao = simetria(mat,mat2);
	
	if(opcao == 1){	
		printf("A Matriz é simétrica\n");
	}
	
	if(opcao == 0){
		printf("A Matriz não é simétrica\n");
	}
	

return 0;
}

/*Questão 08*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Imprime matriz original
void printmat(int mat[6][6]){
	
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			printf("%4d",mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");

return;
}

//Copia a matriz original
void mat_cpy(int mat[6][6],int mat2[6][6]){
	
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			mat2[i][j] = mat[i][j];
		}
	}
return;
}

// Soma todos os elementos da matriz original
int soma_total(int mat[6][6]){
	int soma = 0;

	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			soma = mat[i][j] + soma;
		}
	}

return soma;
}

//Soma duas matrizes
void soma_matrizes(int mat2[6][6], int mat3[6][6], int mat4[6][6]){
	
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			mat4[i][j] =  mat2[i][j] + mat3[i][j];
		}
	}

return;	
}


//Direita
void mat_direita_sup(int mat[6][6]){
	for(int i = 0; i < 6; i++){
		for(int j = i + 1; j < 6; j++){
			mat[i][j] = 0;
		}
	}
return;
}

int mat_direita_inf(int mat[6][6]){
	for(int i = 0; i < 6; i++){
		for(int j = 5; j > 5 - i; j--){
			mat[i][j] = 0;
		}
	}

}

//Esquerda
int mat_esquerda_sup(int mat[6][6]){
	for(int i = 0; i < 6; i++){
		for(int j = 4 - i; j >= 0; j--){
			mat[i][j] = 0;
		}
	}
}
 
int mat_esquerda_inf(int mat[6][6]){
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < i; j++){
			mat[i][j] = 0;
		}
	}
}


// Diagonais
int diagonalp(int mat[6][6]){
	for(int i = 0, j = 0; i < 6, j < 6; i++,j++){
		mat[i][j] = 0;
	}

}
int diagonals(int mat[6][6]){
	for(int i = 0, j = 0; i < 6, j < 6; i++, j++){
		mat[i][5 - j] = 0;
	}
}

int main(void){
	int mat[6][6]  = {0};
	int mat2[6][6] = {0};
	int mat3[6][6] = {0};
	int mat4[6][6] = {0};
	int soma_hachuradas = 0;
	int soma[8] = {0};

	srand(time(NULL));

	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			mat[i][j] = (rand()/(double)RAND_MAX)*100;
		}
	}
	printf("\n");

	printf("Matriz 6X6:\n");
	printmat(mat);
	
	//Soma 1
	mat_cpy(mat,mat2);
	mat_esquerda_inf(mat2);
	diagonalp(mat2);
	soma[0] = soma_total(mat2);

	printf("Parte hachurada 1:\n");
	printmat(mat2);
	printf("Soma da parte hachurada 1: %d\n\n",soma[0]);

	//Soma 2
	mat_cpy(mat,mat2);
	mat_direita_inf(mat2);
	diagonals(mat2);
	soma[1] = soma_total(mat2);

	printf("Parte hachurada 2:\n");
	printmat(mat2);
	printf("Soma da parte hachurada 2: %d\n\n",soma[1]);

	//Soma 3
	mat_cpy(mat,mat2);
	mat_direita_inf(mat2);
	mat_esquerda_inf(mat2);
	diagonalp(mat2);
	diagonals(mat2);
	soma[2] = soma_total(mat2);


	printf("Parte hachurada 3:\n");
	printmat(mat2);
	printf("Soma da parte hachurada 3: %d\n\n",soma[2]);

	//Soma 4
	mat_cpy(mat,mat2);
	mat_direita_sup(mat2);
	mat_direita_inf(mat2);
	
	diagonalp(mat2);
	diagonals(mat2);
	soma[3] = soma_total(mat2);

	printf("Parte hachurada 4:\n");
	printmat(mat2);
	printf("Soma da parte hachurada 4: %d\n\n",soma[3]);

	//Soma 5_1
	mat_cpy(mat,mat2);
	mat_direita_sup(mat2);
	mat_direita_inf(mat2);
	
	diagonalp(mat2);
	diagonals(mat2);

	int soma5_1 = 0; 
	soma5_1 = soma_total(mat2);

	//Soma5_2
	mat_cpy(mat,mat3);
	mat_esquerda_sup(mat3);
	mat_esquerda_inf(mat3);
	
	diagonalp(mat3);
	diagonals(mat3);

	int soma5_2 = 0;
	soma5_2 = soma_total(mat3);

	soma[4] = soma5_1 + soma5_2;

	soma_matrizes(mat2,mat3,mat4);

	printf("Parte hachurada 5:\n");
	printmat(mat4);
	printf("Soma da parte hachurada 5: %d\n\n",soma[4]);

	//Soma6_1
	mat_cpy(mat,mat2);
	mat_direita_sup(mat2);
	mat_esquerda_sup(mat2);
	
	diagonalp(mat2);
	diagonals(mat2);
	
	int soma6_1 = 0;
	soma6_1 = soma_total(mat2);

	//Soma6_2
	mat_cpy(mat,mat3);
	mat_direita_inf(mat3);
	mat_esquerda_inf(mat3);
	
	diagonalp(mat3);
	diagonals(mat3);

	int soma6_2 = 0;
	soma6_2 = soma_total(mat3);

	soma[5] = soma6_1 + soma6_2;

	soma_matrizes(mat2,mat3,mat4);

	printf("Parte hachurada 6:\n");
	printmat(mat4);
	printf("Soma da parte hachurada 6: %d\n\n",soma[5]);

	//Soma 7
	mat_cpy(mat,mat2);
	mat_direita_inf(mat2);
	
	diagonalp(mat2);
	diagonals(mat2);

	soma[6] = soma_total(mat2);

	printf("Parte hachurada 7:\n");
	printmat(mat2);
	printf("Soma da parte hachurada 7: %d\n\n",soma[6]);

	//Soma 8 
	mat_cpy(mat,mat2);
	mat_direita_sup(mat2);
	
	diagonalp(mat2);
	diagonals(mat2);

	soma[7] = soma_total(mat2);

	printf("Parte hachurada 8:\n");
	printmat(mat2);
	printf("Soma da parte hachurada 8: %d\n\n",soma[7]);

	// Soma das pates hachuradas
	soma_hachuradas = soma[0] + soma[1] + soma[2] + soma[3] + soma[4] + soma[5] + soma[6] + soma[7];
	
	printf("A soma total das partes hachuradas é %d\n",soma_hachuradas);	

return 0;	
}