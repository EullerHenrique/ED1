/*Primeira Lista*/

//Multiplos

#include <stdio.h>

int main(void){
    unsigned int n = 0;
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int auxi = 0;
    unsigned int auxj = 0;

    printf("<<Múltiplos>>\n");

    printf("Entre com o valor de n: ");
    scanf("%u",&n);

    printf("Entre com o valor de i: ");
    scanf("%u",&i);

    printf("Entre com o valor de j: ");
    scanf("%u",&j);


    for(int k = 0; k < n; k++){

    	if(auxi * i == auxj * j){ // Se os múltiplos forem iguais
    		
    		if(auxi * i == 0){ // If usado somente para printar a frase e o primeiro número. Este if será obrigatoriamente executado na primeira iteração. A variável printada poderia ser auxj * j.
    		   printf("Os múltiplos de i ou j são: %u",auxi * i);
    		}

    		else{ // If usado para printar os outros múltiplo comuns. A variável printada poderia ser auxj * j.
    			printf(",%u",auxi * i);

    		}
    		auxj++;
    		auxi++; 
    	}

    	else{ // Se os múltiplos não forem iguais
    	 
    	 	if(auxi * i > auxj * j){ // If usado para imprimir os múltiplos em ordem crescente, se auxi * i >  auxj * j, o if irá imprimir o menor múltiplo, ou seja, auxj * j. 
    			printf(",%u",auxj * j);
    			auxj++;
    	 	}

    	 	else{
    			printf(",%u",auxi * i); // If usado para imprimri os múltiplos em ordem crescente, se auxi * i < auxj * j, o if irá imprimir o menor múltiplo, ou seja, auxi * i.
 				auxi++;	   	 
    	 	}
    	}
    }

    printf("\n");
    return 0;
}


//Primos

#include <stdio.h>

int main(void){

	int a = 0;
	int divisores = 0;

	printf("<<Números primos>>\n");
	printf("Entre com o valor: ");

	scanf("%d",&a);

	for(int i = 1; i <= a; i++){
		if(a % i == 0){
			divisores++;
		}
	}

	if(divisores == 2){
		printf("O número %d é primo\n",a);
	}
	else{
		printf("O número %d não é primo\n",a);
	}

	return 0;
}


//Binario - Decimal

#include<stdio.h>
#include<math.h>


int main(void){
	int n = 0;
	int i = 0;
	int i2 = 0;

	int x = 0;
	long long int bin = 0;
	long long int decimal = 0;

	printf("<< Conversor binário-decimal >>\n");
	printf("Entre com o número de bits: ");
	scanf("%d",&n);
	

	for(i = 1, i2 = n - 1; i <= n; i++, i2--){
		printf("Digite o bit #%d: ",i);
		scanf("%d",&x);
	
		if(x == 0 || x == 1){
		    bin =  x*pow(10,i2) + bin;

		    decimal = x*pow(2,i2) + decimal;
        }
        else{
        	printf("O número não é binário\n");
        	return 0;
        }
	}

	printf("O número binário %lld em decimal é %lld \n",bin, decimal);
  
return 0;
}

//Triangulo

#include <stdio.h>

int main(void){
	int n = 0;
	int num = 0;

	scanf("%d",&n);
	num = 1;

	for(int linha = 1; linha <= n; linha++){
        for(int coluna = 1; coluna <= linha; coluna++){
        	printf("%d ",num);
        	num++;
        }

		printf("\n");		 
	}
	return 0;
}


//Fatorial

#include <stdio.h>

int main(void){
	int fat= 0;
	int i = 0;

	fat = 1;

	printf("<<Fatorial>>\n");

	for(i = 1; i <= 10; i++){
		fat = fat * i;
		printf("%d! = %d\n",i,fat);
	}    

return 0;
}

/*Segunda Lista*/


//Normalização - Proporção

#include <stdio.h>

int main(void){
	int vet[5] = {0};
	int maior = vet[0];
	double m = 0;

	printf("<<Normalizando as notas>>\n");

	for(int i = 0; i < 5; i++){
		printf("Entre com a nota do aluno %d: ",i+1);
		scanf("%d",&vet[i]);	
	}

	printf("\n\n");
	printf("Notas normalizadas\n\n");

	for(int i = 0; i < 5; i++){
		if(vet[i] > maior){
			maior = vet[i];
		}
	}

 	m =  100/maior;

	for(int i = 0; i < 5; i++){
		printf("A nota do aluno %d é: %.0lf\n",i+1,vet[i] * m);  
	}


return 0;
}

//Média e desvio padrão

#include <stdio.h>
#include <math.h>

int main(void){
	int vet[5] = {0};
	int i = 0;
	int soma = 0;
	double media = 0;
	double dp = 0;

	printf("<<Média e desvio-padrão>>\n");

	for(i = 0; i < 5; i++){
		printf("Digite o valor %d: ",i+1);
		scanf("%d",&vet[i]);
		soma = vet[i] + soma; 
	}
	
	media = soma / (double)i;

	for(i = 0; i < 5; i++){
		dp = pow(vet[i] - media,2) + dp; 
	}
	dp = sqrt(dp / (double)(i - 1));

	printf("\n");
	printf("A média é %.0lf e o desvio-padrão %.13lf",media,dp);
	printf("\n");

return 0;
}

// Pares e impares

#include <stdio.h>

int main(void){
	int vet[5] ={0};
	int v1[5] = {0};
	int v2[5] = {0};
	
	printf("<<Pares e ímpares>>\n");

	for(int i = 0; i < 5;i++){
		printf("Digite o valor %d:",i+1);
		scanf("%d",&vet[i]);
	}
	printf("\n");
	
	for(int i = 0, int j = 0, int k = 0; i < 5; i++){
			
			if(vet[i] % 2 == 0){
				v1[j] = vet[i];
				j++;
			}
			else{
				v2[k] =  vet[i];
				k++;
		} 
	}

	printf("Impares: ");

	for(int i = 0; i < k; i++){
		   printf("%d ",v2[i]);
	}
	printf("\n");

	printf("Pares: ");
	for(int i = 0; i < j; i++){
			printf("%d ",v1[i]);
	}
	printf("\n");

	return 0;
}

//Como fazer probabilidade

printf("Probabilidades\n");

	for(int i = 0; i < 4; i++){
		soma = cores[i] + soma;
	}

	for(int i = 0; i < 4; i++){
		prob[i] = (cores[i] / (double)soma) * 100;
		
		if(prob[i] > maior){
			maior = prob[i];
		}
	}

//Valores iguais de um vetor

 #include <stdio.h>
 
 int main(void){
    int vet1[8]; // Tal vetor armazena os números lidos 
    int vet2[8]; // Tal vetor armazena os números repetidos
    
    int i = 0;
    int j = 0;

   	int k = 0;
   	int n = 0;
  	
  	int igualdade_repetiu = 0;
        
    printf("<<Valores iguais>>\n");

    for(i= 0; i < 8; i++){
        printf("Entre com o numero %d: ",i+1);
        scanf("%d",&vet1[i]);
    }

    for(i = 0; i < 8; i++){
        for(j = i + 1; j < 8; j ++){
        	
        	igualdade_repetiu = 0; // 0 =  False, 1 = True

            if(vet1[i] == vet1[j]){// Se vet1[i] for igual a vet1[j].
                
                for(k = 0; k < n; k++){ // Este laço for será executado se o k for menor que n, Este laço for serve para os valores do vet2 serem comparados com os valores de vet1. 
                    if(vet1[i] == vet2[k]){ // Se vet1[i] for igual a vet2[k], o valor de vet1[i] não será adicionado ao vetor vet2[n].
                        igualdade_repetiu = 1;// A igualdade repetiu.    
                    }
                }
                  
                if(igualdade_repetiu == 0){ // Se a igualdade não tiver repetido, o valor de vet1[i] será atribuido ao vetor vet2[n], ou seja, valores serão inseridos no vet2.
                	vet2[n] = vet1[i];
                  	n++;// Aumenta o indice do vet2[n], isto é, o seu tamanho.
                }
            }
        }
    }

   printf("Valores repetidos: ");
   for(i = 0; i < n; i++){
      	printf("%d ", vet2[i]);
    }
    printf("\n");

return 0;
}

//Valores iguais de um vetor e quantas vezes cada valor repetiu

 #include <stdio.h>
 
 int main(void){
    int vet1[8]; // Tal vetor armazena os números lidos 
    int vet2[8]; // Tal vetor armazena os números repetidos
    
    int i = 0;
    int j = 0;

   	int k = 0;
   	int n = 0;
   	int contador = 0;
  	
  	int igualdade_repetiu = 0;
        
    printf("<<Valores iguais>>\n");

    for(i= 0; i < 8; i++){
        printf("Entre com o numero %d: ",i+1);
        scanf("%d",&vet1[i]);

    }
    printf("\n");

    for(i = 0; i < 8; i++){
        for(j = i + 1; j < 8; j ++){
        	
        	igualdade_repetiu = 0; // 0 =  False, 1 = True
        	contador = 0;// reinicia o contador

            if(vet1[i] == vet1[j]){// Se vet1[i] for igual a vet1[j].
                
                for(k = 0; k < n; k++){ // Este laço for será executado se o k for menor que n. 
                    if(vet1[i] == vet2[k]){ // Se vet1[i] for igual a vet2[k], o valor de vet1[i] não será adicionado ao vetor vet2[n].
                        igualdade_repetiu = 1;// A igualdade repetiu.    
                    }
                }
                  
                if(igualdade_repetiu == 0){ // Se a igualdade não tiver repetido, o valor de vet1[i] será atribuido ao vetor vet2[n].
                	vet2[n] = vet1[i];

                	for(int i = 0; i < 8; i++){// Este laço for serve para comparar todos o valores do vet1 com o valor atual do vet2[n].
                		if(vet1[i] == vet2[n]){
                			contador++;// Conta os números iguais.
                		}
                	}

                	printf("%d repetiu %d vezes", vet2[n], contador);
                	printf("\n");

                  	n++;// Aumenta o indice do vet2[n], isto é, o seu tamanho.
                }
            }
        }
       
    }

return 0;
}

/*Lista 3*/

//Nome maiusculo sem a bibiloteca string

#include <stdio.h>

int main(void){
	char nome[51] = {'\0'};
	char c = '\0';
	
	int i = 0;
	int j = 0;
	int m = 0;	


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
	
	for(m = 0; m < i; m++){
		printf("%c",nome[m]); // imprime letra por letra 
	}
	printf("\n");
	
	return 0;
}	


// Determina se dois nomes são iguais

#include <stdio.h>

int compara(char nome1[],char nome2[]){
	int i = 0;
       
    for(i = 0; i < 51; hi++){
		if(nome1[i] != nome2[i]){ // quando um caractere for diferente do outro os nomes serão diferentes.
			return 1;
		 }
    }

return -1; // se o laço for acabar signfica que os nomes são iguais.
}

int main(void){
	char nome1[51] = {'\0'};
	char nome2[51] = {'\0'};
	char c = '\0';

	int i = 0;
	int opcao = 0;


	printf("<<Compara Nomes>>\n\n");

	printf("Digite o nome 1: ");   
	setbuf(stdin,NULL); 

	for(i = 0; c != '\n';i++){ 
		c = getchar();
		if(c != '\n'){
			nome1[i] = c;
		} 
	}

	c = '\0';
	printf("Digite o nome 2: ");
	setbuf(stdin,NULL); 

	for(i = 0; c != '\n'; i++){
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

// Determina se dois nomes são iguais (independente de serem maiusculos ou minusculos)

#include <stdio.h>

int compara(char nome1[],char nome2[]){

	int i = 0;

       for(i = 0; i < 51; i++){
			if(nome1[i] != nome2[i]){ // quando um caractere for diferente do outro os nomes serão diferentes.
				return 1;
		 	}
    	}
	return -1;// se o laço for acabar signfica que os nomes são iguais.
}

int main(void){
	char nome1[51] = {'\0'};
	char nome2[51] = {'\0'};
	char c = '\0';

	int i = 0;
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

// Divide o nome completo em nome e sobrenome 

/*Questão 6*/

#include <stdio.h>

int main(void){
	char nome[41] = {'\0'};
	char nome1[41] = {'\0'};
	char nome2[41] = {'\0'};
	char c = '\0';

	int i = 0;
	int j = 0;
	int k = 0;


	printf("<<Vetor de Char>>\n\n");
	printf("Digite um nome e sobrenome: ");
  
 
	setbuf(stdin,NULL);	
	for(i = 0; c != '\n';i++){
		c = getchar();
		if(c != '\n'){
		nome[i] = c;
		}
	}

	for(j = 0; nome[j] != ' ' && nome[j] != '\0'; j++){ //Esse if copia todos os caracteres digitados até o espaço, do vetor nome para o vetor nome1. 
		nome1[j] = nome[j]; //Se não tiver espaço, o if copia todos caracteres digitados até o '\0'. 
	}
	nome1[j] = '\0';
	
	printf("Nome: ");
	j++;// sai do espaço.

	for(k = 0; nome[j] != '\0'; j++, k++){ //Esse if copia todos os caracteres digitados depois do espaço, do vetor nome para o vetor nome2. 
		nome2[k] = nome[j];
	}
	nome2[j] = '\0';

	for(i = 0; i < j; i++){
		printf("%c",nome1[i]);
	}
	printf("\n");

	printf("Sobrenome: ");
	for(i = 0; i < j; i++){
		printf("%c",nome2[i]);
	}
	printf("\n");

	return 0;
}

/*Lista_03_Strings com Strings.h*/

// Imprime um nome com letras maiusculas e minusculas

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
	char maiusculo[51] = {'\0'};
	char minusculo[51] = {'\0'};
	char c = '\0';
	
	printf("<<Vetor de Char>>\n\n");
	printf("Digite um nome: ");

	setbuf(stdin,NULL); 

	for(int i = 0; c != '\n';i++){ 
		c = getchar(); 
		maiusculo[i] = toupper(c);
		minusculo[i] = tolower(c);
	}
	
	maiusculo[strcspn(maiusculo,"\n")] = '\0';
	minusculo[strcspn(minusculo,"\n")] = '\0';

	printf("O nome digitado é: %s\n",maiusculo);
	printf("O nome digitado é: %s\n",minusculo);

return 0;
}

// Compara dois nomes usando a strcmp

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
	char nome1[51] = {'\0'};
	char nome2[51] = {'\0'};

	printf("<<Compara nomes>>\n\n");

	printf("Digite o nome 1: ");
	fgets(nome1,sizeof(nome1),stdin);
	nome1[strcspn(nome1,"\n")] = '\0';
	
	printf("Digite o nome 2: ");
	fgets(nome2,sizeof(nome2),stdin);
	nome2[strcspn(nome2,"\n")] = '\0';

	if(strcmp(nome1, nome2) == 0){
		printf("Os nomes digitados são iguais\n");
	}else{
		printf("Os nomes digitados são diferentes\n");
	}

return 0;
}

// Compara dois nomes (independente de serem maisculos ou minusculos) usando a strcmp

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
	char maiusculo1[51] = {'\0'};
	char maiusculo2[51] = {'\0'};
	char c = '\0';
	
	printf("<<Compara nomes>>\n\n");

	printf("Digite o nome 1: ");
	setbuf(stdin,NULL); 

	for(int i = 0; c != '\n';i++){
		c = getchar();
		maiusculo1[i] = toupper(c);
	}
	maiusculo1[strcspn(maiusculo1,"\n")] = '\0';

	c = '\0';
	printf("Digite o nome 2: ");	
	setbuf(stdin,NULL);

	for(int i = 0; c != '\n'; i++){ 
		c = getchar(); 
		maiusculo2[i] = toupper(c);
	}
	maiusculo2[strcspn(maiusculo2,"\n")] = '\0';

	if(strcmp(maiusculo1, maiusculo2) == 0){
		printf("Os nomes digitados são iguais\n");
	}else{
		printf("Os nomes digitados são diferentes\n");
	}

return 0;
}

// Divide o nome completo em nome e sobrenome

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
	char nome[41] = {'\0'};
	char nome1[41] = {'\0'};
	char nome2[41] = {'\0'};
	int espaco = 0;

	printf("<<Vetor de Char>>\n\n");
	printf("Digite um nome e sobrenome: ");
	
	fgets(nome, sizeof(nome),stdin);
	nome[strcspn(nome,"\n")] = '\0';

	espaco = strcspn(nome," "); // quantos carateres tem até chegar no espaço
	strncpy(nome1,nome,espaco); // copia todos os caracteres até o espaco, do vetor nome para o vetor nome1
	strcpy(nome2,nome + espaco+1); // copia todos os caracteres depois do espaço do vetor nome para o vetor nome2
								  // *(&nome[0] + 7 + 1)
								 //  *(&nome[8]) 

	printf("Nome: %s",nome1);
	printf("\n");
	printf("Sobrenome: %s",nome2);
	printf("\n");

	return 0;
}




//Separa letras

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){

	char nome[41] = {'\0'};
	int tamanho = 0;

	printf("<<Separa letra>>\n\n");

	printf("Digite o nome: ");
	fgets(nome, sizeof(nome),stdin);
	nome[strcspn(nome,"\n")] = '\0'; // zera o '\n'

	printf("\n\n");
	tamanho = strlen(nome);
	
	for(int i = 0; i < tamanho; i++){
		printf("%d letra:%c \n",i+1,nome[i]);
	}

	return 0;
}


// Imprime uma string sem vogais

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
	char vet[41] = {'\0'};
	char c = '\0';

	printf("<<Sem vogais>>\n\n");
	printf("Digite a string: ");
	
	setbuf(stdin,NULL); 
	
	for(int i = 0; c != '\n';){		
		
		c = getchar();
	
		if(c != 'A' && c != 'a' && c != 'E' && c != 'e' && c != 'I' && c != 'i' && c != 'O' && c != 'o' && c != 'U' && c != 'u'){	
			vet[i] = c;
			i++;
		}
	}
	vet[strcspn(vet,"\n")] = '\0';
	printf("\n");

	printf("Saída sem vogais: %s\n",vet);
	return 0;
}

//Inverte uma string

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
	char vet[41] = {'\0'};
	char vet2[41] = {'\0'};
	int tamanho = 0;
	int i = 0;

	printf("<<Invertendo>>\n\n");
	
	setbuf(stdin,NULL); 
	printf("Digite a string: ");

	fgets(vet,sizeof(vet),stdin);
	vet[strcspn(vet,"\n")] = '\0';

	tamanho = strlen(vet);
	tamanho--; // faz o tamanho acessar o último indice do vetor. ex: "euller", vet[5] = 'r'
	
	for(i = 0; tamanho >= 0; tamanho--,i++){
		vet2[i] = vet[tamanho]; 	
	}
	vet2[i] = '\0';

	printf("\n");

	printf("Saída invertida: %s\n",vet2);
	
return 0;
}


/*Questão 10*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
	char maiusculo1[41] = {'\0'};
	char maiusculo2[41] = {'\0'};
	char c = '\0';
	int tamanho = 0;
	int i = 0;

 
	printf("Digite a string: ");
	setbuf(stdin,NULL); 

	for(int i = 0; c != '\n';i++){
		c = getchar();
		maiusculo1[i] = toupper(c);
	}
	maiusculo1[strcspn(maiusculo1,"\n")] = '\0';
	printf("\n");

	tamanho = strlen(maiusculo1);
	tamanho--; // faz o tamanho acessar o último indice do vetor. ex: "euller", vet[5] = 'r'
	
	for(i = 0; tamanho >= 0; tamanho--,i++){
		maiusculo2[i] = maiusculo1[tamanho]; 	
	}
	maiusculo2[i] = '\0';

	if(strcmp(maiusculo1,maiusculo2) == 0){
		printf("A string é um palindromo\n");
	}
	else{
		printf("A string não é um palindromo\n");
	}
	return 0;
}

/*Lista 4*/

//Aritmetica de ponteiros

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
		printf("Valor da váriavel pval[%d]: %u",i,*(pval + i));
		printf("\n");
	}
	printf("\n\n");

	
	for(int i = 0; i < 5; i++){
		printf("Endereço do vetor pval[%d]: %u",i,(pval + i));
		printf("\n");
	}
	printf("\n\n");

return 0;
}

//Aritmética de ponteiros

#include <stdio.h>

int main(void){
	int val[5] = {2,4,5,8,10};
	
	int *pval = NULL;
	pval = &val[0];

	printf("Vetor: ");
	for(int i = 0; i < 5; i++){
		(*(pval + i))--;// subtrai de cada elemento do vetor uma unidade 
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

// Ponteiro para void

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

// Par e impar usando alocação dinâmica

#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n = 0;
	int par = 0;
	int impar = 0;
	int *numeros = NULL;

	printf("Quantos números você deseja digitar? ");
	scanf("%d",&n);

	numeros = malloc(n * sizeof(int));

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

//Coordenadas com alocação dinâmica e estrutura

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

	vet = malloc(n * sizeof(coordenadas)); // retorna &vet[0].

	for(int i = 0; i < n; i++){
		printf("Entre com a coordenada x do ponto %d: ",i+1);
		scanf("%d",&vet[i].x);
		printf("Entre com a coordenada y do ponto %d: ",i+1);
		scanf("%d",&vet[i].y);
	}

	printf("Pontos digitados: ");
	for(int i = 0; i < n; i++){
		printf("(%d, %d);",vet[i].x,vet[i].y);
	}
	printf("\n");

	free(vet);

return 0;
}

//Definição de que ponto esta mais a esquerda, mais a direita, mais acima, mais abaixo.

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

	vet = malloc(n * sizeof(coordenadas));

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