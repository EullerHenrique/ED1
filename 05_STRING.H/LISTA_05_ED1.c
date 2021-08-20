/*Questão 01*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
	char nome[51] = {'\0'};
	
	printf("<<Vetor de Char>>\n");

	printf("Digite um nome: ");
	gets(nome);
	nome[strcspn(nome,"\n")] = '\0';

	printf("O nome digitado é:%s\n",nome);

return 0;
}

/*Questão 2*/

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

/*Questão 03*/

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

/*Questão 4*/
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

/*Questão 05*/

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
	strncpy(nome1,nome,espaco); // copia todos os caracteres até o espaco do vetor nome para o vetor nome1
	strcpy(nome2,nome + espaco+1); // copia todos os caracteres depois do espaço do vetor nome para o vetor nome2

	printf("Nome: %s",nome1);
	printf("\n");
	printf("Sobrenome: %s",nome2);
	printf("\n");

	return 0;
}

/*Questão 06*/

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

/*Questão 07*/

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

/*Questão 08*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
	char nome[41] = {'\0'};
	char cpf[41] = {'\0'};
	char rg[41] = {'\0'};
	char endereco[41] = {'\0'};
	char cidade[41] = {'\0'};
	char estado[11] = {'\0'};
	char cep[11] = {'\0'};
	
	setbuf(stdin,NULL); 
	printf("Digite seu nome: ");
	fgets(nome,sizeof(nome),stdin);
	nome[strcspn(nome,"\n")] = '\0';

	setbuf(stdin,NULL); 
	printf("Digite seu CPF: "); 
	fgets(cpf,sizeof(cpf),stdin);
	cpf[strcspn(cpf,"\n")] = '\0';

	setbuf(stdin,NULL); 
	printf("Digite seu RG: ");
	fgets(rg,sizeof(rg),stdin);
	rg[strcspn(rg,"\n")] = '\0';

	setbuf(stdin,NULL); 
	printf("Digite seu endereco: ");
	fgets(endereco,sizeof(endereco),stdin);
	endereco[strcspn(endereco,"\n")] = '\0';
	
	setbuf(stdin,NULL); 
	printf("Digite sua cidade: ");
	fgets(cidade,sizeof(cidade),stdin);
	cidade[strcspn(cidade,"\n")] = '\0';
	
	setbuf(stdin,NULL); 
	printf("Digite seu estado: ");
	fgets(estado,sizeof(estado),stdin);
	estado[strcspn(estado,"\n")] = '\0';

	setbuf(stdin,NULL); 
	printf("Digite seu cep: ");
	fgets(cep,sizeof(cep),stdin);
	cep[strcspn(cep,"\n")] = '\0';
	
	printf("\n\n");
	printf("               D E C L A R A Ç Ã O\n\n\n");


	printf("Eu, %s,RG %s, CPF %s,\n",nome,rg,cpf);
	printf("residente da %s,%s-%s,\n",endereco,cidade,estado);
	printf("CEP %s venho por meio desta declarar que vou estudar para a prova\n",cep);
return 0;		     
}

 /* Questão 9*/

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

#include <stdio.h>
#include <string.h>

int main(void){
	char buff[5] = {'\0'};
	int pass = 0;
	
	printf("Entre com a senha : ");
	gets(buff);
	
	if(strcmp(buff, "1234") != 0){
		printf ("\nSenha Errada\n");
	} 
	else{
		printf ("\nSenha Correta\n");
		pass = 1;
		}
	
	if(pass == 1){ /* O usuário acertou a senha, poderá continuar*/
		printf ("\nAcesso liberado\n");
	}
	else{	
		printf ("\nAcesso negado\n");
	}
return 0;
}

/*Questão 11*/

/* 
a) Qual é a função do programa?

R: A função do programa é verificar se a senha digitada está correta e liberar o acesso se a senha estiver correta.

b) Qual a saída quando a senha correta é digitada (senha correta: 1234)

R: A saída é: Senha Correta
			  
			  Acesso liberado

c) Qual a saída para as seguintes senhas

a. 123

R: A saída é: Senha Errada
			  
			  Acesso negado

b. 12345

R: A saída é: Senha Errada
			  
			  Acesso negado

c. 123456

R: A saída é:
			  Senha Errada

			  Acesso negado
			  *** stack smashing detected ***: <unknown> terminated
			  Aborted (core dumped)

d) Em quais casos o programa obteve um comportamento inválido. Explique o motivo.

R: O programa obteve um comportamento inválido no caso em que foi digitado "123456", este comportamento ocorreu porque o vetor foi declarado com 5 dígitos, 
e foi digitado um número com 6 dígitos.
*/


/*Questão 12*/

/* a) Pense em uma solução para o problema do exercício 11 que utiliza fgets.
Considere que o tamanho máximo de uma senha são 4 dígitos.

R: A solução é aumentar o tamanho do vetor.
*/

#include <stdio.h>
#include <string.h>

int main(void){
	char buff[100] = {'\0'};
	int pass = 0;
	
	printf("Entre com a senha : ");
    fgets(buff,100,stdin);
    buff[strcspn(buff,"\n")] = '\0';
	
	if(strcmp(buff, "1234") != 0){
		printf ("\nSenha Errada\n");
	} 
	else{
		printf ("\nSenha Correta\n");
		pass = 1;
		}
	
	if(pass == 1){ /* O usuário acertou a senha, poderá continuar*/
		printf ("\nAcesso liberado\n");
	}
	else{	
		printf ("\nAcesso negado\n");
	}
return 0;
}

/*b) Teste com os seguintes valores
a. 123
R: A saída é: Senha Errada
			  
			  Acesso negado


b. 12345
R: A saída é: Senha Errada
			  
			  Acesso negado


c. 123456
R: A saída é: Senha Errada
			  
			  Acesso negado

*/