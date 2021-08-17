/*Questão 1*/

#include <stdio.h>

int main(void){
	int vet[6] = {0};

	printf("<<Listando um vetor>>\n");
	
	printf("Entre com o número 1: ");
	scanf("%d",&vet[0]);

	printf("Entre com o número 2: ");
	scanf("%d",&vet[1]);

	printf("Entre com o número 3: ");
	scanf("%d",&vet[2]);

	printf("Entre com o número 4: ");
	scanf("%d",&vet[3]);

	printf("Entre com o número 5: ");
	scanf("%d",&vet[4]);

	printf("Entre com o número 6: ");
	scanf("%d",&vet[5]);

	printf("\n");
	printf("Os valores lidos são: %d %d %d %d %d %d\n",vet[0],vet[1],vet[2],vet[3],vet[4],vet[5]);

	return 0;
}

/*Questão 2*/

#include <stdio.h>

int main(void){
	int vet[6] = {0};

	printf("<<Listando um vetor>>\n");

	for(int i = 0; i < 6; i++){
		printf("Entre com o número %d:",i+1);
		scanf("%d",&vet[i]);
	}

	printf("\n");
	printf("Os valores lidos são: ");

	for(int i = 0; i < 6; i++){
		printf("%d ",vet[i]);
	}
	printf("\n");


	return 0;
}

/*Questão 3*/

#include <stdio.h>

int main(void){
	int vet[6] = {0};

	printf("<<Listando um vetor em ordem inversa>>\n");

	for(int i = 0; i < 6 ; i++){
		printf("Entre com o número %d: ",i+1);
		scanf("%d",&vet[i]);
	}

	printf("\n");
	printf("A ordem inversa dos números é: ");

	for(int i = 5; i >= 0; i--){
		printf("%d ",vet[i]);
	}
	printf("\n");

	return 0;
}

/*Questão 4*/

#include <stdio.h>

int main(void){
	int vet[6]= {0};

	printf("<<Listando um vetor de números pares>>\n");

	for(int i = 0 ; i < 6 ; i++){
		printf("Entre com o número %d:",i+1);
		scanf("%d",&vet[i]);
		
		while(vet[i] % 2 != 0){
			 printf("Erro: Valor inválido\n\n");
			 printf("Entre com o número %d:",i+1);
			 scanf("%d",&vet[i]);
		}
	}

	printf("\n");
	printf("Os números pares digitados foram: ");

	for(int i = 0; i < 6; i++){
		printf("%d ",vet[i]);
	}
	printf("\n");

	return 0;
}

/*Questão 5*/

#include <stdio.h>

int main(void){
	int vet[5] = {0};
	int i = 0;
	int soma = 0;
	double media = 0;

	int maior = vet[0];
	int menor = vet[0];

	printf("<<5 valores>>\n");

	for(int i = 0; i < 5 ; i++){
		printf("Entre com o número %d: ",i+1);
		scanf("%d",&vet[i]);
	}

	printf("\n");
	printf("Os números digitados são: ");

	for(int i = 0; i < 5; i++){
		printf("%d ",vet[i]);
	}

	printf("\n");
	
	for(i = 0; i < 5;i++){

		if(vet[i] > maior){
			maior = vet[i];
		}
		if(vet[i] < menor){
			menor = vet[i];
		}

		soma =  vet[i] + soma; 
	}
		media = soma / (double) i;

	printf("O maior valor é: %d\n",maior);

	printf("O menor valor é %d\n",menor);

	printf("A média é: %.1lf\n",media);

return 0;
}

/*Questão 6*/

#include <stdio.h>

int main(void){
	int vet[5] = {'\0'};
	int i = 0;
	int posicao_1 = 0;
	int posicao_2 = 0;
	int maior = vet[0];
	int menor = vet[0];
	int soma = 0;
	double media = 0;

	printf("<<5 valores>>\n");

	for(int i = 0; i < 5 ; i++){
		printf("Entre com o número %d: ",i+1);
		scanf("%d",&vet[i]);
	}

	printf("\n");
	printf("Os números digitados são: ");

	for(int i = 0; i < 5; i++){
		printf("%d ",vet[i]);
	}

	printf("\n");

	for(i = 0; i < 5;i++){

		if(vet[i] > maior){
			maior = vet[i];
			posicao_1 = i ;
		}
		if(vet[i] < menor){
			menor = vet[i];
			posicao_2 = i;
		}

		soma =  vet[i] + soma; 
	}
		media = soma / (double) i;

	printf("O maior valor é: %d, localizado na posição %d do vetor\n",maior, posicao_1);

	printf("O menor valor é: %d, localizado na posição %d do vetor\n",menor,posicao_2);

	printf("A média é %.1lf\n",media);

return 0;
}

/*Questão 7*/

#include <stdio.h>

int main(void){
	int vet[5] = {0};
	int maior = 0;
	maior = vet[0];
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
/*Questão 8*/

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

/*Questão 9*/
#include <stdio.h>

int main(void){
	int i = 0;
	int numero = 0;
	int soma = 0;
	double media = 0;
	int vet[100] = {0};

	printf("<<Média de n alunos. Máximo 100 alunos>>\n");

	printf("Entre com o  número de alunos: ");
	scanf("%d",&numero);

	if(numero > 100){
		printf("Erro!O número máximo de alunos permitido é 100.\n");
		return 0;		
	}

	for(i = 0; i < numero; i++){
		printf("Digite a nota do aluno %d:",i+1);
		scanf("%d",&vet[i]);
		soma = vet[i] + soma;
	}
		media = soma / (double)i;

	printf("\n");
	printf("Relatório de Notas\n");

	for(i = 0; i < numero; i++){
		printf("A nota do aluno %d é: %d \n",i+1,vet[i]);
	}

	printf("A média da turma é: %.1lf\n",media);

return 0;
}


/*Questão 10*/

#include <stdio.h>
int main(void){
	int vetA[3] = {0};
	int vetB[3] = {0};
	int vetC[3] = {0};

	printf("<<Subtração de vetores>>\n");

	for(int i = 0; i < 3; i++){
		printf("Digite o valor %d de A:",i+1);
		scanf("%d",&vetA[i]);
	}

	printf("\n");

	for(int i = 0; i < 3; i++){
		printf("Digite o valor %d de B:",i+1);
		scanf("%d",&vetB[i]);
	}

	for(int i = 0; i < 3; i++){
		vetC[i] = vetA[i] - vetB[i]; 
	}

	printf("\n");

	printf("O vetor C, definido como C = A - B é (%d,%d,%d)\n",vetC[0],vetC[1],vetC[2]);

return 0;	
}

/*Questão 11*/

#include <stdio.h>

int main(void){
	int vet[5] ={0};
	int v1[5] = {0};
	int v2[5] = {0};

	int i = 0;
	int j = 0;
	int k = 0;
	
	printf("<<Pares e ímpares>>\n");

	for(int i = 0; i < 5;i++){
		printf("Digite o valor %d:",i+1);
		scanf("%d",&vet[i]);
	}
	printf("\n");

	
	for(i = 0, j = 0, k = 0; i < 5; i++){
			
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

/*Questão 12*/

#include <stdio.h>

int main(void){
	int soma = 0;
	int cores[4] = {0};
	double prob[4] = {0};
	double maior = prob[0];

	printf("<<Probabilidades>>\n\n");

	printf("Digite a quantidade de bolihas\n");
	
	printf("Verde: ");
	scanf("%d",&cores[0]);

	printf("Azul: ");
	scanf("%d",&cores[1]);

	printf("Amarela: ");
	scanf("%d",&cores[2]);

	printf("Vermelha: ");
	scanf("%d",&cores[3]);

	printf("\n\n");

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


	if(prob[0] == prob[1] && prob [0] == prob[2] && prob[0] == prob[3]){
		printf("Verde: %.2lf%%\n",prob[0]);
		printf("Azul: %.2lf%%\n",prob[1]);
		printf("Amarela: %.2lf%%\n",prob[2]);
		printf("Vermelha: %.2lf%%\n",prob[3]);
	}
	else{	

		if(maior == prob[0]){
			if(prob[0] == prob[1] || prob[0] == prob[2] || prob[0] == prob[3]){
				printf("Verde: %.2lf%%\n",prob[0]);
			} 
			else{
				printf("Verde: %.2lf%% <<Maior probabilidade\n",prob[0]);
			}
		}
		else{
			printf("Verde: %.2lf%%\n",prob[0]);
		}
	
		if(maior == prob[1]){
			if(prob[1] == prob[0] || prob[1] == prob[2] || prob[1] == prob[3]){
				printf("Azul: %.2lf%%\n",prob[1]);
			} 
			else{
				printf("Azul: %.2lf%% <<Maior probabilidade\n",prob[1]);
			}
		}
		else{
			printf("Azul: %.2lf%%\n",prob[1]);
		}
	
		if(maior == prob[2]){
			if(prob[2] == prob[0] || prob[2] == prob[1] || prob[2] == prob[3]){
					printf("Amarela: %.2lf%%\n",prob[2]);
			} 
			else{
					printf("Amarela: %.2lf%% <<Maior probabilidade\n",prob[2]);
			}
		}
		else{
			printf("Amarela: %.2lf%%\n",prob[2]);
		}

		if(maior == prob[3]){
			if(prob[3] == prob[0] || prob[3] == prob[1] || prob[3] == prob[2]){
				printf("Amarela: %.2lf%%\n",prob[3]);
			} 
			else{
				printf("Amarela: %.2lf%% <<Maior probabilidade\n",prob[3]);
			}
		}
		else{	
			printf("Vermelha: %.2lf%%\n",prob[3]);
		}
	}

	return 0;
}

/*Questão 13*/
#include <stdio.h>

int main(void){
	int vet[5] = {0};

	printf("<<Zerando negativos>>\n");

	for(int i = 0; i < 5; i++){
		printf("Entre com o número %d: ",i + 1);
		scanf("%d",&vet[i]);
		
		if(vet[i] < 0){
			vet[i] = 0;
		}
	}
	printf("\n");

	printf("Zerando os negativos, obtém-se: ");
	
	for(int i = 0; i < 5; i++){
		printf("%d ",vet[i]);
	}
	printf("\n");

return 0;
}


/*Questão 14*/

#include <stdio.h>

int main(void){
	int vet[10000] = {0};
	int alunos = 0;
	int matricula = 0;
	char classe = '\0';
	float cra = 0.0;

	printf("<<Universidade X>>\n");
	
	printf("Quantos alunos serão cadastrados: ");
	scanf("%d",&alunos);
	printf("\n");

	for(int i = 0; i < alunos; i++){
		printf("Entre com o número do aluno: ");
		scanf("%d",&vet[i]);


		printf("Entre com a classe social do aluno: ");
		scanf("\n%c",&classe);
		
		while(classe != 'A' && classe != 'B' && classe != 'C' && classe != 'D' && classe != 'E'){	
			printf("As opções disponíveis são : A, B, C,D ou E, digite novamente: ");
			scanf("\n%c",&classe);
		}

		printf("Entre com o CRA do aluno: ");
		scanf("%f",&cra);

		printf("\n");

	}

	printf("====Alunos Cadastrados====\n");

	for(int i = 0; i < alunos; i++){
		printf("Número: %d Classe social %c CRA: %.2f\n",vet[i],classe,cra);
	}


return 0;
}

/*Questão 15*/
 #include <stdio.h>
 
 int main(){
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
                
                for(k = 0; k < n; k++){ // Este laço for será executado se o k for menor que n. 
                    if(vet1[i] == vet2[k]){ // Se vet1[i] for igual a vet2[k], o valor de vet1[i] não será adicionado ao veotr vet2[n].
                        igualdade_repetiu = 1;// A igualdade repetiu.    
                    }
                }
                  
                if(igualdade_repetiu == 0){ // Se a igualdade não tiver repetido, o valor de vet1[i] será atribuido ao vetor vet2[n].
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

/*Questão 16*/

 #include <stdio.h>
 
 int main(){
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
        	contador = 0;

            if(vet1[i] == vet1[j]){// Se vet1[i] for igual a vet1[j].
                
                for(k = 0; k < n; k++){ // Este laço for será executado se o k for menor que n. 
                    if(vet1[i] == vet2[k]){ // Se vet1[i] for igual a vet2[k], o valor de vet1[i] não será adicionado ao veotr vet2[n].
                        igualdade_repetiu = 1;// A igualdade repetiu.    
                    }
                }
                  
                if(igualdade_repetiu == 0){
               				 // Se a igualdade não tiver repetido, o valor de vet1[i] será atribuido ao vetor vet2[n].
                	vet2[n] = vet1[i];
                	for(int i = 0; i < 8; i++){
                		if(vet1[i] == vet2[n]){
                			contador++;
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


