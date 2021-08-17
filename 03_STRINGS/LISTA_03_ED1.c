/*Questão 1*/

#include <stdio.h>

int main(void){
	unsigned int numeros = 0;

	for(numeros = 28 ; numeros <= 255; numeros++){
		printf("Valor: %d , Caracter correspondente: %c \n",numeros,numeros);
	}
return 0;
}
/*Questão 2*/

#include <stdio.h>

int main(void){
	char nome[51] = {'\0'};
	char c = '\0';
	int i = 0;

	printf("<<Vetor de Char>>\n\n");
	printf("Digite um nome: ");
      
	setbuf(stdin,NULL);

	for(i = 0; c != '\n';i++){
		c = getchar();
		if(c != '\n'){ // if usado para retirar o não incluir o '\n' no vetor. 
			nome[i] = c;
		}
	}

	printf("O nome digitado foi: ");
	for(int j = 0; j < i; j++){
		printf("%c",nome[j]);
	}
	printf("\n");
	return 0;
}

/*Questão 3*/

#include <stdio.h>

int main(void){
	char nome[51] = {'\0'};
	char c = '\0';
	int i = 0;
	int j = 0;	


	printf("<<Vetor de Char>>\n\n");
	printf("Digite um nome: ");

	setbuf(stdin,NULL);

	for(i = 0; c != '\n'; i++){
		c = getchar();
		if(c!= '\n'){
			nome[i] = c;
		}

		for(int k = 97; k <= 122; k++){
			if(nome[i] == k){
				nome[i] = k - 32;
			}
		}
	}

	printf("O nome digitado foi: ");
	
	for(int m = 0; m < i; m++){
		printf("%c",nome[m]); // imprime letra por letra 
	}
	printf("\n");

	return 0;
}

/*Questão 4*/

#include <stdio.h>

int compara(char nome1[],char nome2[]){

       for(int h = 0; h < 51; h++){
			if(nome1[h] != nome2[h]){ // quando um caractere for diferente do outro os nomes serão diferentes.
				return 1;
		 	}
    	}
	return -1;// se o laço for acabar signfica que os nomes são iguais.
}

int main(void){
	char nome1[51] = {'\0'};
	char nome2[51] = {'\0'};

	char c = '\0';

	int opcao = 0;


	printf("<<Compara Nomes>>\n\n");

	printf("Digite o nome 1: ");   
	setbuf(stdin,NULL); 

	for(int i = 0; c != '\n';i++){ 
		c = getchar();
		if(c != '\n'){
			nome1[i] = c;
		} 
	}

	c = '\0';
	printf("Digite o nome 2: ");
	setbuf(stdin,NULL); 

	for(int i = 0; c != '\n'; i++){
		c = getchar();
		if(c != '\n'){
			nome2[i] = c;
		}
	}

	opcao = compara(nome1,nome2);
	
	if(opcao == -1){
		printf("Os nomes são iguais\n");
	}
	if(opcao == 1){
		printf("Os nomes são diferentes\n");
	}


return 0;
}

/*Questão 5*/

#include <stdio.h>

int compara(char nome1[],char nome2[]){

       for(int h = 0; h < 51; h++){
			if(nome1[h] != nome2[h]){ // quando um caractere for diferente do outro os nomes serão diferentes.
				return 1;
		 	}
    	}
	return -1;// se o laço for acabar signfica que os nomes são iguais.
}

int main(void){
	char nome1[51] = {'\0'};
	char nome2[51] = {'\0'};

	char c = '\0';

	int opcao = 0;


	printf("<<Compara Nomes>>\n\n");

	printf("Digite o nome 1: ");   
	setbuf(stdin,NULL); 

	for(int i = 0; c != '\n';i++){ 
		c = getchar();
		if(c != '\n'){
			nome1[i] = c;
		} 
		for(int k = 97; k <= 122; k++){
			if(nome1[i] == k){
				nome1[i] = k - 32;
			}
		}
	}

	c = '\0';
	printf("Digite o nome 2: ");
	setbuf(stdin,NULL); 

	for(int i = 0; c != '\n'; i++){
		c = getchar();
		if(c != '\n'){
			nome2[i] = c;
		}
		for(int k = 97; k <= 122; k++){
			if(nome2[i] == k){
				nome2[i] = k - 32;
			}
		}
	}

	opcao = compara(nome1,nome2);
	
	if(opcao == -1){
		printf("Os nomes são iguais\n");
	}
	if(opcao == 1){
		printf("Os nomes são diferentes\n");
	}


return 0;
}

/*Questão 6*/

#include <stdio.h>

int main(void){
	char nome[41] = {'\0'};
	char nome1[41] = {'\0'};
	char nome2[41] = {'\0'};

	char c = '\0';

	int j = 0;
	int k = 0;


	printf("<<Vetor de Char>>\n\n");
	printf("Digite um nome e sobrenome: ");
  
 
	setbuf(stdin,NULL);	
	for(int i = 0; c != '\n';i++){
		c = getchar();
		if(c != '\n'){
		nome[i] = c;
		}
	}

	for(j = 0; nome[j] != ' ' && nome[j] != '\0'; j++){ //Esse if copia todos os caracteres digitados até o espaço, do vetor nome para o vetor nome1. Se não tiver espaço, o if copia todos caracteres digitados até o '\0'. 
		nome1[j] = nome[j];
	}
	nome1[j] = '\0';
	
	printf("Nome: ");
	j++;// sai do espaço.

	for(k = 0; nome[j] != '\0'; j++, k++){ //Esse if copia todos os caracteres digitados depois do espaço, do vetor nome para o vetor nome2. 
		nome2[k] = nome[j];
	}
	nome2[j] = '\0';

	for(int i = 0; i < j; i++){
		printf("%c",nome1[i]);
	}
	printf("\n");

	printf("Sobrenome: ");
	for(int i = 0; i < j; i++){
		printf("%c",nome2[i]);
	}
	printf("\n");

	return 0;
}

/*Questão 7*/

//O programa funciona corretamente com o %s no printf

#include <stdio.h>

int main(void){
	char nome[51] = {'\0'};
	char c = '\0';

	printf("<<Vetor de Char>>\n\n");
	printf("Digite um nome: ");
      
	setbuf(stdin,NULL);

	for(int i = 0; c != '\n';i++){
		c = getchar();
		if(c != '\n'){ // if usado para retirar o não incluir o '\n' no vetor. 
			nome[i] = c;
		}
	}
	printf("O nome digitado foi: %s",nome);
	printf("\n");
return 0;
}



