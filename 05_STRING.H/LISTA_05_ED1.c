/*Questão 01*/

#include <stdio.h>

int main(void){
	int val[5] = {2,4,5,8,10};

	unsigned long int p = 0;
	p = &val[2];

	printf("Digite 6: ");
	scanf("%d",p);

	for(int i = 0 ; i < 5; i++){
		printf("%d",val[i]);
	}
	printf("\n");

return 0;
}

/*Questão 02*/

#include <stdio.h>

int main(void){
	int val[5] = {2,4,5,8,10};
	
	int *pval = NULL;
	pval = &val[4];

	int a = 40;
	
	int *pa;
	pa = &a;

	/*a) */
	
	printf("Endereço de 'a' usando o &a: %u",&a);
	printf("\n");
	printf("Endereço de 'a' usando o pa: %u",pa);
	printf("\n\n");

	/*b) */
	
	printf("Digite o novo valor de 'a': ");
	scanf("%d",pa);
	printf("Novo valor de 'a': %d ",a);
	printf("\n\n");

	/*c) */

	printf("Digite 20 para alterar o quarto indice do vetor val: ");
	scanf("%d",pval);

	printf("Novo vetor: ");
	for(int i = 0; i < 5; i++){
		printf("%d ",val[i]);
	}
	printf("\n\n");

	/*D) */

	printf("Valor da váriavel a: %d",a);
	printf("\n");
	printf("Valor da váriavel pa %u",pa);
	printf("\n");

	printf("Endereço da váriavel a: %u",&a);
	printf("\n");
	printf("Endereço da váriavel pa: %u",&pa);
	printf("\n\n");

	for(int i = 0; i < 5;i++){
		printf("Valor do vetor val[%d]: %d",i,val[i]);
		printf("\n");
	}
	printf("\n");


	for(int i = 0; i < 5; i++){
		printf("Endereço do vetor val[%d]: %u",i,&val[i]);
		printf("\n");
	}
	printf("\n");
	
	printf("Valor da váriavel pval: %u",pval);
	printf("\n");
	printf("Endereço da váriavel pval: %u",&pval);
	printf("\n\n");
	

return 0;
}

/*Questão 03*/

#include <stdio.h>

int main(void){
	int val[5] = {2,4,5,8,10};
	
	int *pval = NULL;
	pval = &val[0];

	printf("Vetor: ");
	for(int i = 0; i < 5; i++){
		printf("%d ",*(pval + i)); // *(pval + i) = *(&val[0] + i) -- ACESSA O CONTEÚDO DO ENDEREÇO &val[0] + i
	}
	printf("\n\n");

	for(int i = 0; i < 5; i++){
		printf("Endereço do vetor val[%d]: %u",i,&val[i]);
		printf("\n");
	}
	printf("\n\n");

	for(int i = 0; i < 5; i++){
		printf("Valor da váriavel val[%d]: %d",i,val[i]);
		printf("\n");
	}
	printf("\n\n");

	for(int i = 0; i < 5; i++){
		printf("Valor da váriavel pval[%d]: %u",i,pval[i]);
		printf("\n");
	}
	printf("\n\n");

	
	for(int i = 0; i < 5; i++){
		printf("Endereço do vetor pval[%d]: %u",i,&pval[i]);
		printf("\n");
	}
	printf("\n\n");

return 0;
}


/*Questão 04*/

#include <stdio.h>

int main(void){
	int val[5] = {2,4,5,8,10};
	
	int *pval = NULL;
	pval = &val[0];

	printf("Vetor: ");
	for(int i = 0; i < 5; i++){
		(*(pval + i))--; 
		printf("%d ",*(pval + i)); // *(pval + i) = *(&val[0] + i)
	}
	printf("\n\n");

	for(int i = 0; i < 5; i++){
		printf("Endereço do vetor val[%d]: %p",i,&val[i]);
		printf("\n");
	}
	printf("\n\n");

	for(int i = 0; i < 5; i++){
		printf("Valor da váriavel val[%d]: %d",i,val[i]);
		printf("\n");
	}
	printf("\n\n");

	for(int i = 0; i < 5; i++){
		printf("Valor da váriavel pval[%d]: %d",i,*(pval + i));
		printf("\n");
	}
	printf("\n\n");

	
	for(int i = 0; i < 5; i++){
		printf("Endereço do vetor pval[%d]: %p",i,(pval + i));
		printf("\n");
	}
	printf("\n\n");
}

/*Questão 05*/
/*Questão 5*/

#include <stdio.h>

int main(Void){
	int v1 = 1;
	double v2 = 2;
	char c = 'a';
	
	int *p_v1;
	double *p_v2;
	char *p_c;

	p_v1 = &v1;
	p_v2 = &v2;
	p_c = &c;

	printf("Endereço de v1 %lu", p_v1);
	printf("\n");
	printf("Endereço de v2 %lu", p_v2);
	printf("\n");
	printf("Endereço de c %lu", p_c);
	printf("\n\n");

	printf("Endereço+1 de v1 %lu", p_v1 + 1);
	printf("\n");
	printf("Endereço+1 de v2 %lu", p_v2 + 1);
	printf("\n");
	printf("Endereço+1 de c %lu", p_c + 1);
	printf("\n\n");

	printf("Endereço-1 de v1 %lu", p_v1 - 1);
	printf("\n");
	printf("Endereço-1 de v2 %lu", p_v2 - 1);
	printf("\n");
	printf("Endereço-1 de c %lu", p_c - 1);
	printf("\n\n");

	printf("Endereço+2 de v1 %lu", p_v1 + 2);
	printf("\n");
	printf("Endereço+2 de v2 %lu", p_v2 + 2);
	printf("\n");
	printf("Endereço+2 de c %lu", p_c + 2);
	printf("\n\n");

	printf("Endereço-2 de v1 %lu", p_v1 - 2);
	printf("\n");
	printf("Endereço-2 de v2 %lu", p_v2 - 2);
	printf("\n");
	printf("Endereço-2 de c %lu", p_c - 2);
	printf("\n\n");


	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("Nome          Endereço var-2              Endereço var-1              Endereço var               Endereço v1 + 1                 Endereço v1 +2 \n");
	printf("variável/\n");
	printf("Endereços\n");
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("p_v1          %lu             %lu             %lu            %lu                 %lu\n", p_v1 - 2, p_v1 - 1, p_v1, p_v1 + 1, p_v1 + 2);
	printf("p_v2          %lu             %lu             %lu            %lu                 %lu\n", p_v2 - 2, p_v2 - 1, p_v2, p_v2 + 1, p_v2 + 2);
	printf("p_c           %lu             %lu             %lu            %lu                 %lu\n", p_c - 2 , p_c - 1, p_c, p_c + 1, p_c + 2);
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");

return 0;
}

/*Questão 06*/

/*

Houve um comportamento diferente no exercicio anterior ao somarmos/subtrairmos o valor de cada ponteiro, pois o tipo de cada ponteiro está associado ao tipo da váriavel associada.

Como o tipo char possui como tamanho 1byte, quando somamos 1 /subtraimos 1 o valor do ponteiro p_c (que no caso é o endereço de c) é adicionado/subtraido somente 1 byte no endereço de c.  
como o tipo int possui como tamanho 4bytes, quando somamos 1 /subtraimos 1 o valor do ponteiro p_v1 (que no caso é o endereço de v1) é adicionado/subtraido 4 bytes no endereço de v1,
pois a a contagem começa no quarto endereço reservado para a váriavel v1.  

Como o tipo double possui como tamanho 8bytes, quando somamos 1 /subtraimos 1 o valor do ponteiro p_v2(que no caso é o endereço de v2) é adicionado/subtraido 8 bytes no endereço de v2,
pois a contagem começa no oitavo endereço reservado para a várivel v2.  

*/

/*Questão 07*/

#include <stdio.h>

int main(void){
	char nome[13] = "José Augusto";

	printf("O nome digitado foi: ");
	for(int j = 0; j < 13; j++){
		printf("%c",*(pnome +j)); // *(pnome + j) = *(&nome[0] + i); ex : &nome[0] = 1, *(&1 + 1) = *(&2) => Acessa o conteúdo do endereço 2 da variável nome
	}
	printf("\n");

return 0;

}

/*Questão 08*/

#include <stdio.h>

int main(void){
	int a  = 0;
	double b = 0;

	void *p = NULL;

	p = &a; 
	printf("Digite o valor de a: ");
	scanf("%d", (int*)p);


	printf("Digite o valor de b: ");
	p = &b;
	scanf("%lf", (double*)p);
	printf("\n");

	p = &a;
	printf("O valor de a é: %d",*(int *)p);
	printf("\n");
	
	p = &b;
	printf("O valor de b é: %lf",*(double*)p);
	printf("\n");

return 0;
}

/*Questão 09*/

#include <stdio.h>

int main(void){
	double vet[10] = {1,2,3,4,5,6,7,8,9,10};

	for(int i = 0; i < 10; i++){
		printf("%lf",*(vet+i));
		printf("\n");
	}

return 0;
}


/*Questão 10*/

#include <stdio.h>

int main(void){
	int vet[10] = {1,2,3,4,5,6,7,8,9,10};

	for(int i = 9; i >= 0; i--){
		printf("%d",*(vet + i)); 
		printf("\n");
	}

return 0;
}
