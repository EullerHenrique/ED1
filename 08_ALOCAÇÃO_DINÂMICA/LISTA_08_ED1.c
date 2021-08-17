/*LISTA_8-_Funções*/


/*Questão 1*/
#include <stdio.h>

void DesenhaLinha(void){
	printf("========\n");
return;
}

int main(void){
	
	for(int i = 0; i < 20; i++){
		DesenhaLinha();
	}
return 0;
}

/*Questão 2*/
#include <stdio.h>

void DesenhaLinha(int qtd_caracteres){
	for(int i = 0; i < qtd_caracteres; i++){
		printf("=");
	}
	printf("\n");
return;
}

int main(void){
	int qtd_caracteres = 0;
	
printf("Quantos sinais de igual cada linha deve ter? \n");
	scanf("%d",&qtd_caracteres);

	for(int i = 0; i < 20; i++){
		DesenhaLinha(qtd_caracteres);
	}
return 0;
}

/*Questão 3*/
#include <stdio.h>

int fatorial(int x){
	int fat = 0;
	fat = 1;

	for(int i = 1; i <= x; i++){
		fat = i * fat;
	}
return fat;
}

void DesenhaLinha(void){
	printf("========\n");
return;
}

int main(void){
	int x = 0;
	int fat = 0;

	for(int i = 0; i < 5; i++){
		DesenhaLinha();
		printf("Fatorial\n");
		DesenhaLinha();

		printf("Digite o fatorial a ser calculado: ");
		scanf("%d",&x);

		fat = fatorial(x);
		printf("Fat de %d: %d\n",x,fat);
	}
return 0;
}

/*Questão 4*/
#include <stdio.h>

float potencia(int base, int expoente){
	float x = 1;

	if(expoente > 0){
		for(int i = 0; i < expoente; i++){
		x = base * x;
		}
	}
	if(expoente < 0){
		expoente = expoente * -1;
		for(int i = 0; i < expoente; i++){
			x = base * x;
		}
			x = 1 / x;
	}
return x;
}

int main(void){
	int base = 0;
	int expoente = 0;
	float resultado = 0;

	printf("========\n");
	printf("Potência\n");
	printf("========\n");

	printf("Digite a base da potência: ");
	scanf("%d",&base);

	printf("Digite o expoente da potência: ");
	scanf("%d",&expoente);

	resultado = potencia(base,expoente);
	printf("%.2d ^ %.2d = %.2f \n",base,expoente,resultado);

return 0;

/*Questão 5*/

#include <stdio.h>
#include <math.h>

int quadrado_perfeito(double x){
	x = sqrt(x);
	double inteiro = 0;
	double fracionario = 0;

	fracionario = modf(x,&inteiro);
	if(fracionario == 0){
		return 1;
	}
	else{
		return 0;
	}
}

int main(void){
	double  numero = 0;
	int opcao = 0;

printf("Digite o número: ");
	scanf("%lf",&numero);

	opcao = quadrado_perfeito(numero);
	if(opcao == 1){
		printf("True\n");
	}
	else{
		printf("False\n");
	}
return 0;
}

/*Questão 6*/

#include <stdio.h>
#include <stdlib.h>

void DesenhaLinha(void){
	printf("========\n");
return;
}

double fatorial(int x){
	double fat = 0;	
	fat = 1;

	for(int i = 1; i <= x; i++){
		fat = i * fat;
	}
return fat;
}

double numero_neperiano(int qtd_termos){

	double e = 0;

	for(int i = 0; i < qtd_termos; i++){
		e = 1 / fatorial(i) + e;
	}
return e;
}

int main(void){
	int qtd_termos = 0;
	double e = 0;

		for(int i = 0; i < 5; i++){
			DesenhaLinha();
			printf("Número neperiano\n");
			DesenhaLinha();

			printf("Digite a quantidade de termos a serem calculados: ");
			scanf("%d",&qtd_termos);

			e = numero_neperiano(qtd_termos);
			printf("O número neperiano é: %lf\n",e);
		}

return 0;
}

/*Questão 7*/

#include <stdio.h>

void troque(int* a, int* b){
	int temp = 0;

	temp = *a;
	*a = *b;
	*b = temp;
return;
}

int main(void){
	printf("======\n");
	printf("Troque\n");
	printf("======\n");

	int a = 0;
	int b = 0;

	printf("Digite o valor de a: ");
	scanf("%d",&a);

	printf("Digite o valor de b: ");
	scanf("%d",&b);

	troque(&a,&b);
	printf("Os valores trocados são: %d %d ",a,b);
	printf("\n");
return 0;
}

/*Questão 8*/

#include <stdio.h>

float incp(float y, float x){
	if(x > 0){
		x = (x * y / 100) + x;
	}
	else{
		x = (x * y/ 100) - x;
	}
return x;
}

int main(void){
	
	float x = 0;
	float y = 0;

	printf("Digite o valor de x: ");
	scanf("%f",&x);
	if(x > 0){
		printf("Digite o quanto você deseja aumentar o valor de x (em porcentagem): ");
		scanf("%f",&y);
	}
	else{
		printf("Digite o quanto você deseja diminuir o valor de x (em porcentagem): ");
		scanf("%f",&y);

	}

	x = incp(y,x);
	printf("O novo valor de x é: %.2f ",x);
	printf("\n");
return 0;
}


/*Questão 9*/

#include <stdio.h>

void incp(float* y, float* x){
	if(x > 0){
		*x = (*x * *y / 100) + *x;
	}
	else{
		*x = (*x * *y/ 100) - *x;
	}
return ;
}

int main(void){
	
	float x = 0;
	float y = 0;

	printf("Digite o valor de x: ");
	scanf("%f",&x);
	if(x > 0){
		printf("Digite o quanto você deseja aumentar o valor de x (em porcentagem): ");
		scanf("%f",&y);
	}
	else{
		printf("Digite o quanto você deseja diminuir o valor de x (em porcentagem): ");
		scanf("%f",&y);

	}

	incp(&y,&x);
	
	printf("O novo valor de x é: %.2f ",x);
	printf("\n");
return 0;
}

/*Questão 10*/

#include <stdio.h>

typedef struct {
	int x;
	int y;
	
}Ponto;

void imprime_ponto(Ponto ponto){
	printf("(%d, %d)",ponto.x,ponto.y);
	printf("\n");
return;
}

int main(void){

	Ponto ponto;
	
	printf("Digite o ponto x: ");
	scanf("%d",&ponto.x);

	printf("Digite o ponto y: ");
	scanf("%d",&ponto.y);

	imprime_ponto(ponto);

return 0;
}

/*Questão 11*/

#include <stdio.h>

typedef struct {
	int x;
	int y;
	
}Ponto;

Ponto soma_ponto(Ponto p1, Ponto p2){
	Ponto p3;
	p3.x = p1.x + p2.x;
	p3.y = p1.y + p2.y;  
return p3;
}

void imprime_ponto(Ponto p1,Ponto p2, Ponto p3){
	printf("A soma de (%d, %d) com (%d, %d) é: (%d,%d) ",p1.x,p1.y,p2.x,p2.y,p3.x,p3.y);
	printf("\n");
return;
}


int main(void){

	Ponto p1;
	Ponto p2;
	Ponto p3;
	
	printf("Digite o ponto x1: ");
	scanf("%d",&p1.x);

	printf("Digite o ponto y1: ");
	scanf("%d",&p1.y);

	printf("Digite o ponto x2: ");
	scanf("%d",&p2.x);

	printf("Digite o ponto y2: ");
	scanf("%d",&p2.y);

	p3 = soma_ponto(p1,p2);
	imprime_ponto(p1,p2,p3);

return 0;
}

/*Questão 12*/

#include <stdio.h>

typedef struct {
	int x;
	int y;
	
}Ponto;

void soma_ponto(Ponto p1, Ponto p2, Ponto *p3){
	(*p3).x = p1.x + p2.x; //(*p3).x = p3->x  
	(*p3).y = p1.y + p2.y;  
return;
}

void imprime_ponto(Ponto p1,Ponto p2, Ponto p3){
	printf("A soma de (%d, %d) com (%d, %d) é: (%d,%d) ",p1.x,p1.y,p2.x,p2.y,p3.x,p3.y);
	printf("\n");
return;
}


int main(void){

	Ponto p1;
	Ponto p2;
	Ponto p3;
	
	printf("Digite o ponto x1: ");
	scanf("%d",&p1.x);

	printf("Digite o ponto y1: ");
	scanf("%d",&p1.y);

	printf("Digite o ponto x2: ");
	scanf("%d",&p2.x);

	printf("Digite o ponto y2: ");
	scanf("%d",&p2.y);

	soma_ponto(p1,p2,&p3);
	imprime_ponto(p1,p2,p3);

return 0;
}

/*Questão 13*/
#include <stdio.h>

typedef struct {
	int x;
	int y;
}Ponto;

int calc_area(Ponto p1, Ponto p2){

	int base = 0;
	int altura = 0;
	int area = 0;

	if(p1.x > p2.x){
		base = p1.x - p2.x;
	}
	else{
		base = p2.x - p1.x;
	}
	if(p1.y > p2.y){
		altura = p1.y - p2.y;
	}
	else{
		altura = p2.y - p1.y;
	}

	area = base * altura;
return area;
} 
int main(void){
	Ponto p1;
	Ponto p2;

	int area = 0;

	printf("Digite o ponto x1: ");
	scanf("%d",&p1.x);

	printf("Digite o ponto y1: ");
	scanf("%d",&p1.y);

	printf("Digite o ponto x2: ");
	scanf("%d",&p2.x);

	printf("Digite o ponto y2: ");
	scanf("%d",&p2.y);

	area = calc_area(p1,p2);
	printf("A área o retângulo definido por (%d,%d) e (%d,%d) é %d \n",p1.x,p1.y, p2.x, p2.y,area);
return 0;
}


/*Questão 14*/

#include <stdio.h>

typedef struct {
	int x;
	int y;
}Ponto;

void multiplica(Ponto* p1, int constante){
	p1->x = p1->x * constante;
	p1->y = p1->y * constante;
return;
}

int main(void){
	Ponto p1;

	int constante = 0;

	printf("Digite o valor do ponto x: ");
	scanf("%d",&p1.x);

	printf("Digite o valor do ponto y: ");
	scanf("%d",&p1.y);

	printf("Digite a constante: ");
	scanf("%d",&constante);

	printf("Resultado: (%d,%d) * %d = ",p1.x,p1.y,constante);
	multiplica(&p1,constante);
	printf("(%d,%d)",p1.x,p1.y);
	printf("\n");
return 0;
}


/*Questão 15*/

#include <stdio.h>

typedef struct {
	int x;
	int y;
}Ponto;


void inc_dir(Ponto* ponto,char c){
	if(c == 'n'){
		ponto->y = ponto->y + 1;
	}
	if(c == 's'){
		ponto->y = ponto->y - 1;
	}
	if(c == 'l'){
		ponto->x = ponto->x - 1;
	}
	if(c == 'o'){
		ponto->x = ponto->x + 1;
	}
return;
}

int main(void){
	char c = '\0';

	Ponto ponto; 

	printf("Digite o valor de x: ");
	scanf("%d",&ponto.x);
	
	printf("Digite o valor de y: ");
	scanf("%d",&ponto.y);

	printf("Digite a direção: ");
	scanf("\n%c",&c);

	inc_dir(&ponto,c);

	printf("A nova coordenada é: %d %d",ponto.x,ponto.y);
	printf("\n");
return 0;
}

/*Questão 16*/

#include <stdio.h>
#include <string.h>

typedef struct {
	int x;
	int y;
}Ponto;

void inc_diag(Ponto** ponto,char direcao[]){
	if(strcmp(direcao,"sudeste") == 0){
		(**ponto).x = (**ponto).y - 1;
		(**ponto).x = (**ponto).x - 1;
	}
	if(strcmp(direcao,"sudoeste") == 0){
		(**ponto).y = (**ponto).y - 1;
		(**ponto).x = (**ponto).x + 1;
	}
	if(strcmp(direcao,"nordeste") == 0){
		(**ponto).y = (**ponto).y + 1;
		(**ponto).x = (**ponto).x - 1;

	}
	if(strcmp(direcao,"noroeste") == 0){
		(**ponto).y = (**ponto).y + 1;
		(**ponto).x = (**ponto).x + 1;
	}
return;
}

void inc_dir(Ponto* ponto,char c1, char c2){
	char direcao[15] = {'\0'};
	
	if(c1 == 's' && c2 == 'l'){
		strcpy(direcao,"sudeste");
		inc_diag(&ponto,direcao);
	}
	if(c1 == 's' && c2 == 'o' ){
		strcpy(direcao, "sudoeste");
		inc_diag(&ponto,direcao);
	}
	if(c1 == 'n' && c2 == 'l'){
		strcpy(direcao, "nordeste");
		inc_diag(&ponto,direcao);
	}
	if(c1 == 'n' && c2 == 'o'){
		strcpy(direcao,"noroeste");
		inc_diag(&ponto,direcao);
	}

return;
}

int main(void){

	Ponto ponto;

	char c1 = '\0';
	char c2 = '\0';

	printf("Digite o valor de x: ");
	scanf("%d",&ponto.x);
	
	printf("Digite o valor de y: ");
	scanf("%d",&ponto.y);

	printf("Digite a primeira direção (NORTE OU SUL): ");
	scanf("\n%c",&c1);

	printf("Digite a segunda direção (LESTE OU OESTE): ");
	scanf("\n%c",&c2);

	inc_dir(&ponto,c1,c2);

	printf("A nova coordenada é: (%d, %d)",ponto.x,ponto.y);
	printf("\n");
return 0;
}

/*Questão 17*/

#include <stdio.h>
void imprime_vet_int(int vet1[], int n1){
	for(int i = 0; i < n1; i++){
		printf("%d ",vet1[i]);
	}
	printf("\n");
return;
}
void imprime_vet_double(double vet2[], int n2){
	for(int i = 0; i < n2; i++){
		printf("%.2lf ", vet2[i]);
	}
	printf("\n");
return;
}
void imprime_vet_float(float vet3[], int n3){
	for(int i = 0; i < n3; i++){
		printf("%.2f ",vet3[i]);
	}
	printf("\n");
return;
}
int main(void){
	int vet1[10] = {0};
	double vet2[10] = {0};
	float vet3[10] = {0};
	
	printf("Digite os valores do vetor inteiro \n");
	for(int i = 0; i < 10; i++){
		scanf("%d",&vet1[i]);
	}

	printf("Digite os valores do vetor double\n");
	for(int i = 0; i < 10; i++){
		scanf("%lf",&vet2[i]);
	}

	printf("Digite os valores do vetor float \n");
	for(int i = 0; i < 10; i++){
		scanf("%f",&vet3[i]);
	}
	printf("Vetor inteiro: ");
	imprime_vet_int(vet1,10);

	printf("Vetor double: ");
	imprime_vet_double(vet2,10);
	
	printf("Vetor float: ");
	imprime_vet_float(vet3,10);
return 0;
}
/*Questão 18*/

#include <stdio.h>

void maior_menor(double vet[], double* maior, double* menor){
	*maior = vet[0];
	*menor = vet[0];

	for(int i = 0; i < 10; i++){
		if(vet[i] >  *maior){
			*maior = vet[i];
		}
		if(vet[i] < *menor){
			*menor = vet[i];
		}
	}
return;
}

void imprime_vet_double(double vet[], int n2){
	for(int i = 0; i < n2; i++){
		printf("Valor de vet_double[%d]: %.2lf",i,vet[i]);
		printf("\n");
	}
	printf("\n");
return;
}

int main(void){
	double vet[10] = {0};
	double maior = 0;
	double menor = 0;

	printf("Digite 10 valores\n");
	for(int i = 0; i < 10; i++){
		scanf("%lf",&vet[i]);
	}

	maior_menor(vet,&maior,&menor);
	imprime_vet_double(vet,10);
	printf("Maior valor: %.2lf\n",maior);
	printf("Menor valor: %.2lf\n",menor);

return 0;
}

/*Questão 19*/

#include <stdio.h>

int negativos(float* vet, int N){
	int cont = 0;

	for(int i = 0; i < N; i++){
		if(vet[i] < 0){
			cont++;
		}
	}
return cont;
}

int main(void){
	float vet[10] = {0};
	int qtd_negativos = 0;

	printf("Digite 10 valores\n");
	for(int i = 0; i < 10; i++){
		printf("Digite o valor de vet[%d]: ",i);
		scanf("%f",&vet[i]);
	}

	qtd_negativos = negativos(vet,10);
	printf("O vetor lido possui %d valores negativos: ",qtd_negativos);
	printf("\n");

return 0;
}

/*Questão 20*/

#include <stdio.h>

void copiarvet(int vet_origem[],int vet_destino[],int n){
	for(int i = 0; i < n; i++){
		vet_destino[i] = vet_origem[i];  
	}
return;
}

void imprime_vet_int(int vet[], int n){
	for(int i = 0; i < n; i++){
		printf("%d ",vet[i]);
	}
	printf("\n");
return;
}

int main(void){
	int vet1[10] = {0};
	int vet2[10] = {0};

	printf("Digite 10 valores\n");
	for(int i = 0; i < 10; i++){
		scanf("%d",&vet1[i]);
	}

	copiarvet(vet1,vet2,10);

	printf("Vetor original: ");
	imprime_vet_int(vet1,10);

	printf("Vetor com a cópia: ");
	imprime_vet_int(vet2,10);
return 0;
}

/*Questão 21*/

#include <stdio.h>

void imprime_vet(int vet[], int n){
	for(int i = 0; i < n; i++){
		printf("%d ",vet[i]);
	}
	printf("\n");
return;
}

void mult_vet(int vet_origem[], int escalar, int n){
	for(int i = 0 ; i < n; i++){
		vet_origem[i] = vet_origem[i] * escalar;
	}
return;
}


int main(void){
	int vet[10] = {0};
	int escalar = 0;

	printf("Digite 10 números\n");
	for(int i = 0; i < 10; i++){
		scanf("%d",&vet[i]);
	}

	printf("Digite o escalar: ");
	scanf("%d",&escalar);

	printf("Vetor antes da multiplicação: ");
	imprime_vet(vet,10);

	mult_vet(vet, escalar, 10);
	
	printf("Vetor depois da multiplicação: ");
	imprime_vet(vet,10);
return 0;
}


/*Questão 22*/

#include <stdio.h>
#include<stdlib.h>

void abs_vet(int vet[], int n){
	for(int i = 0; i < n; i++){
		vet[i] = abs(vet[i]);
	}
}

void imprime_vet_int(int vet[], int n){
	for(int i = 0; i < n; i++){
		printf("%d ",vet[i]);
	}
	printf("\n");
return;
}


int main(void){
	int vet[10] = {0};

	printf("Digite 10 valores\n");
	for(int i = 0; i < 10; i++){
		scanf("%d",&vet[i]);
	}

	abs_vet(vet,10);

	imprime_vet_int(vet,10);
return 0;
}


/*Questão 23*/

#include <stdio.h>
#include <stdlib.h>

void imprime_vet_int(int vet[], int n){
	for(int i = 0; i < n; i++){
		printf("%d ",vet[i]);
	}
	printf("\n");
return;
}

void maior_menor(int vet[], int* maior, int* menor, int n){
	*maior = vet[0];
	*menor = vet[0];

	for(int i = 0; i < n; i++){
		if(vet[i] >  *maior){
			*maior = vet[i];
		}
		if(vet[i] < *menor){
			*menor = vet[i];
		}
	}
return;
}

int negativos(int vet[], int n){
	int cont = 0;

	for(int i = 0; i < n; i++){
		if(vet[i] < 0){
			cont++;
		}
	}
return cont;
}

int* copia_vet_abs(int vet[],int n){
	int *vet_abs =NULL;

	vet_abs = calloc(n,sizeof(double));

	for(int i = 0; i < n; i++){
		vet_abs[i] = vet[i];
	}
return vet_abs;
free(vet_abs);
}



int* abs_vet(int vet[], int n){
	for(int i = 0; i < n; i++){
		vet[i] = abs(vet[i]);
	}
return vet;
}

int* copia_vet(int vet[],int n){
	int *vet2 =NULL;

	vet2 = calloc(n,sizeof(double));

	for(int i = 0; i < n; i++){
		vet2[i] = vet[i];
	}
return vet2;
free(vet2);
}

void mult_vet(int vet_origem[], int escalar, int n){
	for(int i = 0 ; i < n; i++){
		vet_origem[i] = vet_origem[i] * escalar;
	}
return;
}

int main(void){
	int* vet = NULL;
	int* vet2 = NULL;
	int* vet_abs = NULL;

	int maior = 0;
	int menor = 0;
	
	int n = 0;
	int qtd_negativos = 0;
	int escalar = 0;

	printf("Entre com o tamanho do vetor: ");
	scanf("%d",&n);

	vet = calloc(n,sizeof(int));

	for(int i = 0;i < n; i++){
		printf("Entre com o elemento %d: ",i+1);
		scanf("%d",&vet[i]);
	}
	printf("\n\n");	

	printf("Vetor: ");
	imprime_vet_int(vet,n);

	
	maior_menor(vet,&maior,&menor,n);
	printf("Maior : %d\n",maior);
	printf("Menor : %d\n",menor);

	qtd_negativos = negativos(vet,n);
	printf("Número de negativos: %d",qtd_negativos);
	printf("\n");

	vet_abs = copia_vet_abs(vet,n);

	printf("Valor absoluto: ");
	abs_vet(vet_abs,n);
	imprime_vet_int(vet_abs,n);
	printf("\n\n");

	printf("Copiando para outro vetor(alocado dinamicamente)\n");
	
	vet2 = copia_vet(vet,n);

	printf("Vetor original: ");
	for(int i = 0; i < n; i++){
		printf("%d ",vet[i]);
	}
	printf("\n");

	printf("Vetor copiado: ");
	for(int i = 0; i < n; i++){
		printf("%d ",vet2[i]);
	}
	printf("\n\n");

	printf("Entre com o escalar para multiplicar o vetor original: ");
	scanf("%d",&escalar);

	printf("Vetor antes da multiplicação: ");
	imprime_vet_int(vet,n);

	mult_vet(vet, escalar,n);
	
	printf("Vetor depois da multiplicação: ");
	imprime_vet_int(vet,n);

	free(vet);
	free(vet2);
	free(vet_abs);
return 0;
}

/*Questão 24*/

#include <stdio.h>
#include <stdlib.h>

int* aloca_inteiro(int n){
	int *vet = NULL;

	vet = calloc(n, sizeof(int));

return vet;
free(vet);
}

void imprime_vet(int vet[], int n){
	for(int i = 0; i < n; i++){
		printf("%d ",vet[i]);
	}
	printf("\n");
return;
}

int main(void){
	int *vet = NULL;
	int n = 0;

	printf("Quantos números você deseja digitar? ");
	scanf("%d",&n);
	
	vet = aloca_inteiro(n);

	printf("Vetor lido: ");
	imprime_vet(vet,n);

	free(vet);
return 0;
}

/*Questão 25*/

#include <stdio.h>
#include <stdlib.h>

double* copia_vet(double* vet,int n){
	double *vet2 =NULL;

	vet2 = calloc(n,sizeof(double));

	for(int i = 0; i < n; i++){
		vet2[i] = vet[i];
	}
return vet2;
free(vet2);
}

int main(void){
	double *vet = NULL;
	double *vet2 = NULL;
	int n = 0;

	printf("Quantos números você deseja ler?\n");
	scanf("%d",&n);

	vet = calloc(n,sizeof(double));

	printf("Digite os números: ");
	for(int i = 0; i < n; i++){
		scanf("%lf",&vet[i]);
	}

	vet2 = copia_vet(vet,n);

	printf("Vetor original: ");
	for(int i = 0; i < n; i++){
		printf("%.2lf ",vet[i]);
	}
	printf("\n");

	printf("Vetor copiado: ");
	for(int i = 0; i < n; i++){
		printf("%.2lf ",vet2[i]);
	}
	printf("\n");

	free(vet);
	free(vet2);
return 0;
}



/*Questão 26*/

#include <stdio.h>
#include <stdlib.h>

double* to_double(int *vet_int,int n){
	
	double *vet_double = NULL;
	vet_double = calloc(n,sizeof(double));
	
	for(int i =0; i < n; i++){
		vet_double[i] = (double) vet_int[i];
	}

return vet_double;
free(vet_double);	
}

int main(void){
	int *vet_int = NULL;
	double *vet_double = NULL;
	int n = 0;

	printf("Quantos valores deseja ler?: ");
	scanf("%d",&n);

	vet_int = calloc(n,sizeof(int));
	for(int i = 0; i < n;i++){
		scanf("%d",&vet_int[i]);
	}
	printf("\n");

    vet_double = to_double(vet_int,n);
    printf("Vetor double: ");
    for(int i = 0; i < n; i++){
    	printf("%.2lf ",vet_double[i]);
    }
    printf("\n");

    free(vet_int);
    free(vet_double);

return 0; 
}

/*Questão 27*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x;
	int y;	
}Ponto;

void pontos(Ponto* ponto, int n){
	for(int i = 0; i < n; i++){
		ponto[i].x = 0;
		ponto[i].y = 0;
	}
return;
}

int main(void){
	Ponto* ponto = NULL;
	int n = 0;
	
	printf("Quantos pontos zerados vc deseja imprimir?: ");
	scanf("%d",&n);

	 ponto = malloc(n * sizeof(Ponto));

	pontos(ponto,n);

	for(int i = 0; i < n; i++){
		printf("(%d,%d)",ponto[i].x,ponto[i].y);
		printf("\n");
	}

	free(ponto);

return 0;
}

/*Questão 28*/

#include <stdio.h>
#include <stdlib.h>

void copiarvet(double* vet_origem,double* vet_destino,int n){
	
	vet_destino = calloc(n,sizeof(double));

	for(int i = 0; i < n; i++){
		vet_destino[i] = vet_origem[i];
	}

	{  	printf("Endereços durante a execução da função\n");
		printf("%lu",&vet_origem);
		printf("\n");
		printf("%lu",&vet_destino);
		printf("\n");
		printf("%lu",&n);
		printf("\n");

	}
free(vet_destino);	
return;
}

int main(void){
	double* vet_origem = NULL;
	double* vet_destino = NULL;
	int n = 0;

	printf("Quantos números você deseja ler?\n");
	scanf("%d",&n);

	vet_origem = calloc(n,sizeof(double));

	printf("Digite os números: ");
	for(int i = 0; i < n; i++){
		scanf("%lf",&vet_origem[i]);
	}

	{	printf("Endereços antes da execução da função\n");
		printf("%lu",&vet_origem);
		printf("\n");
		printf("%lu",&vet_destino);
		printf("\n");
		printf("%lu",&n);
		printf("\n");

	}

	copiarvet(vet_origem,vet_destino,n);

	{
		printf("Endereços depois da execução da função\n");
		printf("%lu",&vet_origem);
		printf("\n");
		printf("%lu",&vet_destino);
		printf("\n");
		printf("%lu",&n);
		printf("\n");

	}

	printf("Vetor original: ");
	for(int i = 0; i < n; i++){
		printf("%.2lf ",vet_origem[i]);
	}
	printf("\n");

	printf("Vetor copiado: ");
	for(int i = 0; i < n; i++){
		printf("%.2lf ",vet_destino[i]);
	}
	printf("\n");

	free(vet_origem);
	free(vet_destino);

return 0;
}

/*Esta função não funciona porque o endereço do vet_destino não foi retornado pela função, portanto o programa não conseguirá imprimir o conteudo do ponteiro vet_destino presente na int main.

Solução 
Usar um ponteiro para ponteiro para retornar por referência o endereço de vet_destino.

*/
