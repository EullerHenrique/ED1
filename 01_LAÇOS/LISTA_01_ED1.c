/*LISTA_01_ED1
Nome: Euller Henrique Bandeira Oliveira
Matrícula: 11821BSI210
*/

/*Questão 1*/

#include <stdio.h>

int main(void){
	int i = 10;

	printf("<<Contagem regressiva>>\n");

	while(i >= 0){
		printf("%d.. ",i);
		i--;
	}
	printf("FIM!\n");

	return 0;
}

/*Questão 2*/

#include <stdio.h>


int main(void){
	 int i = 10;

	 printf("<<Contagem regressiva>>\n");

	 do{
	 	printf("%d.. ",i);
		i--;
	 }
	 while(i >= 0);
	 
	printf("FIM!\n");

	return 0;
}

/*Questão 3*/

#include <stdio.h>

int main(void){
	
	printf("<<Contagem Regressiva>>\n");
	
	for(int i = 10; i >= 0; i--){
		printf("%d.. ", i);
	}
	printf("FIM!\n");
	return 0;
}

/*Questão 4*/

#include <stdio.h>

int main(void){
	int a = 0;

	printf("<<Contagem Regressiva>>\n");
	printf("Qual é o número inicial? ");

	scanf("%d", &a);

	while (a >= 0){
		printf("%d.. ",a);
		a--;	
	}

	printf("FIM!\n");
	return 0;
}

/*Questão 5*/

#include <stdio.h>

int main(void){

	int a = 0;
	printf("<<Contagem Regressiva>>\n");
	printf("Qual é o número inicial? ");

	scanf("%d", &a);

	do{ 	
		printf("%d.. ",a);
		a--;	
	}
	while( a >= 0);

	printf("FIM!\n");

	return 0;
}

/*Questão 6 */

#include <stdio.h>

int main(void){
	
	int a = 0;
	printf("<<Contagem Regressiva>>\n");
	printf("Qual é o número inicial? ");

	scanf("%d", &a);

	for(;a >= 0; a--){
		printf("%d.. ",a);	
	}

	printf("FIM!\n");

	return 0;
}

/*Questão 7 */

#include <stdio.h>

int main(void){
	int a = 0;

	printf("<<Contagem Progressiva até 0>>\n");
	printf("Qual é o número inicial? ");

	scanf("%d", &a);

	while(a <= 0){
		printf("%d.. ",a);
		a++;
	}
	printf("FIM!\n");

	return 0;
}

/*Questão 8*/

#include <stdio.h>

int main(void){
	
	int a = 0;
	printf("<<Contagem Progressiva até 0>>\n");
	printf("Qual é o número inicial? ");

	scanf("%d", &a);

	do{
		printf("%d.. ",a);
		a++;
	}
	while( a <= 0);

	printf("FIM!\n");

	return 0;
}

/* O do-while não é a melhor estrutura para resolver este exercício devido ao seguinte fato: 
se o usuário digitar um número positivo, ou seja, maior do que 0 ou igual à 0, o número será impresso mesmo não fazendo sentido,
pois a estrutura do do-while n depende de uma condição para se inicar, tal estrutura depende de uma condição para continuar. 



/*Questã 9*/

#include <stdio.h>

int main(void){
	
	int a = 0;
	printf("<<Contagem Progressiva até 0>>\n");
	printf("Qual é o número inicial? ");

	scanf("%d", &a);

	for(;a <= 0;a++){
		printf("%d.. ",a);
	}

	printf("FIM!\n");

	return 0;
}

/*Questão 10*/

#include <stdio.h>

int main(void){
	int a = 0;
	int i = 0;

	int soma = 0;

	printf("<<Soma de n valores naturais>>\n");
	printf("Quantos números deseja somar? ");

	scanf("%d",&a);

	while( i <= a){
		soma = soma + i;
		i++;
	}


	printf("A soma dos %d primeiros números naturais é: %d\n",a,soma);

	return 0;
		
}

/*Questão 11*/

#include <stdio.h>

int main(void){
	
	int i = 0;
	int n = 0;
	int soma = 0;

	printf("<<Soma de n valores naturais>>\n");
    printf("Quantos números deseja somar? ");

    scanf("%d",&n);

  
    do{
    	soma = soma + i;
    	i++;
    }
    while(i <= n);

    printf("A soma dos %d primeiros números naturais é: %d\n",n,soma);

return 0;
}

/*Questão 12*/

#include <stdio.h>

int main(void){
	int n = 0;
	int soma = 0;


	printf("<<Soma de n valores naturais>>\n");
	printf("Quantos números deseja somar? ");
    
    scanf("%d",&n);

    for(int i = 0; i <= n; i++){
    	soma = i + soma;
    }

    printf("A soma dos %d números naturais é: %d \n ",n,soma);


return 0;
}

/*Questão 13*/

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

/*Questão 14*/

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

/*Questão 15*/

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

/*Questão 16*/

#include <stdio.h>
#include <math.h>

int main(void){
	int x = 0;
	double y = 0;

	x = 1;
	y = 2;

	printf("Com %d bits é póssivel endereçar %f posições de memória\n",x,y);
    
    x = x * 2;
    y = pow(y,2);

    while(x <= 128){
    	if(y < 5000000000){
 	  	printf("Com %d bits é póssivel endereçar %.0f posições de memória\n",x,y);
 	    }
 	    else{
 	    	printf("Com %d bits é póssivel endereçar %.14e posições de memória\n",x,y);
		}
 	  
 	  	x = x * 2;
        y = pow(y,2);
    }

    return 0;
}    

/*Questão 17*/

#include <stdio.h>

int main(void){
 	char x = '\0';
 	int i = 0;

 	printf("<<Forca de uma letra só>>\n");
 	printf("Qual a letra? ");

 	scanf("\n%c",&x);

 	for(i = 4; x != 'q' && i > -1; i--){
 		 		
 		if(i == 1){
 			printf("Última chance!!!\n");
 			printf("Qual a letra? ");
 		    scanf("\n%c",&x);
 		}
 		
 		if(i > 1){
 		   printf("Errado! Você têm mais %d chances\n",i);
 		   printf("Qual a letra? ");
 		   scanf("\n%c",&x);
 	    }

 	    if(i == 0 && x != 'q'){
 		   printf("Acabaram suas chances. A letra correta é 'q' \n");
 	   }

 	}

 	if(x == 'q'){
 		printf("ACERTOU!\n");
 	}

return 0;
}

/*Questão 18*/

#include <stdio.h>

int main(void){
	char o = '\0';
	int t = 0;
	
	double v1 = 0;
	double v2 = 0;

		while(t == 0){
			printf(" <<Conversor>>\n");
			printf("  Digite uma opção\n");
			printf("   1 - para converter de km/h para m/s\n");
			printf("   2 - para converter de m/s para hm/s\n");
			printf("   q - para sair\n");

			scanf("\n%c",&o);		

			if(o == '1'){
				printf("Digite a velocidade (km/h): \n");
				scanf("\n%lf",&v1);
				v2 = v1 / 3.6;		 

				printf("A velocidade em m/s é %.12lf\n",v2);
			}

			if(o == '2'){
				printf("Digite a velocidade (m/s): \n");
				scanf("\n%lf",&v2);
				v1 = v2 * 3.6;

				printf("A velocidade em km/h é %.0lf\n",v1 );
			}

			if(o == 'q'){
				t++;
			}
		}
   return 0;
}

/*Questão 19*/

#include <stdio.h>

int main(void){
	int j = 0;
	int c = 0;
	int i = 0;

	j = 50000;
	c = 25000;

	while(c <= j){
		  j = j + 800;
		  c = c + 3000;
		  i++;
	}
	i = i /12;
	
	printf("Levará %d ano(s) para que o Carlos fique com mais dinheiro que o José\n",i);

return 0;
}

/*Questão 20*/

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

/*Questão 21*/

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

/*Questão 22*/

#include <stdio.h>

int main(void){
	int fat = 0;
	int i = 0;

	fat = 1;

	printf("<<Fatorial>>\n");

	for(i = 1; i <= 15; i++){
		fat = fat * i;
		if(i > 10){
			printf("%d! = %d\n",i,fat);
		}
	}

return 0;
}

/* Ocorre um erro neste programa porque O tipo inteiro usado na declaração da váriavel fat não possui a quantidade de bits 
suficiente para comportar o 13!, o 14! e o 15!. Portanto, a solução para este problema é mudar o tipo da váriavel fat para 
um que comporte mais bits, como o long int, long long int, unsigned long long int, etc.*/

/*Código correto*/

#include <stdio.h>

int main(void){
	long int fat = 0;
	int i = 0;

	fat = 1;

	printf("<<Fatorial>>\n");

	for(i = 1; i <= 15; i++){
		fat = fat * i;
		if(i > 10){
			printf("%d! = %ld\n",i,fat);
		}
	}
return 0;

/*Questão 23*/

#include <stdio.h>

int main(void){

	int i = 0;
	int n = 0;
	double e = 0;
	double fat = 0;
	fat = 1;
	e = 1;

	printf("<<Número neperiano>>\n");
	printf("Entre com o número de termos: ");

	scanf("%d",&n);


	for(i = 1; i <= n; i++){
		fat = fat * i;
		e = 1 / fat + e;
	} 
	printf("e ~ %.14f\n",e);
return 0;
}

