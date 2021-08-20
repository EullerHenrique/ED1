/*
Nome: Euller Henrique Bandeira Oliveira
Matrícula: 11821BSI210
*/


/*LISTA_6_Estruturas*/


/*Questão 01*/
#include <stdio.h>

typedef struct{
	int DDD;
	int numero;

}Telefone;

int main(void){
	Telefone telefone[3] = {0, 0};

	int i = 0;

	for(i = 0; i < 3; i++){
		printf("Digite o DDD e o telefone: ");
		scanf("%d",&telefone[i].DDD);
		scanf("%d",&telefone[i].numero);
	}

	printf("Telefones cadastrados \n");

	for(i = 0; i < 3; i++){
		printf("(%d) %d ",telefone[i].DDD, telefone[i].numero);
		printf("\n");
	}
return 0;
}

/*Questão 02*/

#include <stdio.h>

typedef struct{
	int DDD;
	int numero;

}Telefone;

int main(void){
	Telefone telefone[3] = {0, 0};

	int i = 0;

	for(i = 0; i < 3; i++){
		printf("Digite o DDD e o telefone: ");
		scanf("%d",&telefone[i].DDD);
		scanf("%d",&telefone[i].numero);
	}

	printf("Telefones cadastrados \n");

	for(i = 0; i < 3; i++){
		printf("(%d) %d ",telefone[i].DDD, telefone[i].numero);
		printf("\n");
	}
return 0;
}

/*Questão 03*/

#include <stdio.h>
#include <string.h>

typedef struct{
	char rua[50];
	char cidade[50];
	int  numero;
	char cep[50];
	char estado[4];
	char complemento[50];
}Endereco;

int main(void){
	Endereco endereco[3];

	int i = 0;

	for(i = 0; i < 3; i++){
		
		printf("Endereço %d",i+1);
		printf("\n");
		
		printf("Digite a rua: ");
		fgets(endereco[i].rua,sizeof(endereco[i].rua),stdin);
		endereco[i].rua[strcspn(endereco[i].rua,"\n")] = '\0';
		
		printf("Digite a cidade: ");
		fgets(endereco[i].cidade,sizeof(endereco[i].cidade),stdin);
		endereco[i].cidade[strcspn(endereco[i].cidade,"\n")] ='\0';

		printf("Digite o número: ");
		scanf("%d",&endereco[i].numero);
		getchar();

		printf("Digite o cep: ");
		fgets(endereco[i].cep,sizeof(endereco[i].cep),stdin);
		endereco[i].cep[strcspn(endereco[i].cep,"\n")] = '\0';

		printf("Digite o estado: ");
		fgets(endereco[i].estado,sizeof(endereco[i].estado),stdin);
		endereco[i].estado[strcspn(endereco[i].estado,"\n")] = '\0';

		printf("Digite o complemento: ");
		fgets(endereco[i].complemento,sizeof(endereco[i].complemento),stdin);
		endereco[i].complemento[strcspn(endereco[i].complemento,"\n")] = '\0';


		printf("\n");
		printf("\n");

	}
	
	for(i = 0; i < 3; i++){
		
		if(strcmp(endereco[i].estado,"MG") == 0){
			printf("Endereço %d",i+1);
			printf("\n");

			printf("Rua: %s",endereco[i].rua);
			printf("\n");
			printf("Cidade: %s",endereco[i].cidade); 
			printf("\n");
			printf("Numero: %d",endereco[i].numero);
			printf("\n");
			printf("Cep: %s ",endereco[i].cep);
			printf("\n");
			printf("Estado: %s",endereco[i].estado);
			printf("\n");
			printf("complemento: %s",endereco[i].complemento);
			printf("\n");
			printf("\n");
	}
}

return 0;
}


/*Questão 04*/

#include <stdio.h>
#include <string.h>

typedef struct{
	char rua[50];
	char cidade[50];
	unsigned int numero;
	char cep[50];
	char estado[4];
	char complemento[50];
}Endereco;

typedef struct{
	unsigned int DDD;
	unsigned int numero;

}Telefone;


typedef struct{
	unsigned int dia;
	unsigned int mes;
	unsigned int ano;

}Data;


typedef struct{
	char nome[50];
	char CPF[20];
	char sexo;
	char estado_civil[20];
	unsigned int salario;
	char rg[20];
	Endereco endereco_comercial;
	Endereco endereco_residencial;
	Telefone telefone;
	Telefone telefone_residencial;
	Data data_de_nascimento;
	Data data_de_ingresso; 
}Cadastro;


int menu(void){
	char opcao = '\0';


	printf("==============================\n");
	printf("===========Cadastro===========\n");
	printf("==============================\n\n");

	printf("a - Listar todos os cadastros\n");
	printf("b - Cadastrar/Sobrescrever nova pessoa\n");
	printf("c - Listar as pessoas que nasceram depois de 1990\n");
	printf("d - Copiar dados de um cadastro para outro\n");
	printf("\n");

	printf("Digite a opção desejada: ");
	scanf("\n%c",&opcao);

	if(opcao == 'a'){
		return 1;
	}
	if(opcao == 'b'){
		return 2;
	}
	if(opcao == 'c'){
		return 3;
	}
	if(opcao == 'd'){
		return 4;
	}

return 0;
}

void listar(Cadastro cadastro[]){
	printf("\n");
	for(int i = 0; i < 5; i++){
		
		printf("Cadastro %i\n\n",i+1);

		printf("Nome: %s\n",cadastro[i].nome);
		printf("CPF: %s\n",cadastro[i].CPF);
		printf("Sexo: %c\n",cadastro[i].sexo);
		printf("Estado Civil: %s\n",cadastro[i].estado_civil);
		printf("Salario: %d\n",cadastro[i].salario);
		printf("RG: %s\n",cadastro[i].rg);

		printf("\nEndereço comercial\n\n");

		printf("Rua: %s\n", cadastro[i].endereco_comercial.rua);
		printf("Cidade: %s\n", cadastro[i].endereco_comercial.cidade);
		printf("Numero: %d\n", cadastro[i].endereco_comercial.numero);
		printf("Cep: %s\n", cadastro[i].endereco_comercial.cep);
		printf("Estado: %s\n",cadastro[i].endereco_comercial.estado);
		printf("Complemento: %s\n", cadastro[i].endereco_comercial.complemento);
		printf("\n");

		printf("Endereço residencial\n\n");

		printf("Rua: %s\n", cadastro[i].endereco_residencial.rua);
		printf("Cidade: %s\n", cadastro[i].endereco_residencial.cidade);
		printf("Numero: %d\n", cadastro[i].endereco_residencial.numero);
		printf("Cep: %s\n", cadastro[i].endereco_residencial.cep);
		printf("Estado: %s\n",cadastro[i].endereco_residencial.estado);
		printf("Complemento: %s\n", cadastro[i].endereco_residencial.complemento);
		printf("\n");

		printf("Telefone: (%d) %d",cadastro[i].telefone.DDD, cadastro[i].telefone.numero);
		printf("\n");
		printf("Telefone residencia: (%d) %d", cadastro[i].telefone_residencial.DDD,cadastro[i].telefone_residencial.numero);
		printf("\n\n");
	}
return;
}

void cadastrar(Cadastro cadastro[]){
	int opcao = 0;

	printf("\n");
	printf("Cadastrar / Sobrescrever nova pessoa\n\n");
	printf("Em que posição você deseja cadastrar/Sobrescrever?\n");
	printf("Opções disponíveis 0, 1, 2,3 ou 4: ");

	scanf("%d",&opcao);
	getchar();

	printf("Nome: ");
	fgets(cadastro[opcao].nome,sizeof(cadastro[opcao].nome),stdin);
	cadastro[opcao].nome[strcspn(cadastro[opcao].nome,"\n")] = '\0';

	printf("CPF: ");
	fgets(cadastro[opcao].CPF,sizeof(cadastro[opcao].CPF),stdin);
	cadastro[opcao].CPF[strcspn(cadastro[opcao].CPF,"\n")] = '\0';

	printf("Sexo: ");
	scanf("\n%c",&cadastro[opcao].sexo); 
	getchar();

	printf("Estado Civil: ");
	fgets(cadastro[opcao].estado_civil,sizeof(cadastro[opcao].estado_civil),stdin);
	cadastro[opcao].estado_civil[strcspn(cadastro[opcao].estado_civil,"\n")] = '\0';

	printf("Salario: ");
	scanf("%u",&cadastro[opcao].salario);

	printf("RG: ");
	fgets(cadastro[opcao].rg,sizeof(cadastro[opcao].rg),stdin);
	cadastro[opcao].rg[strcspn(cadastro[opcao].rg,"\n")] = '\0';

	printf("\nEndereço comercial\n\n");

	printf("Rua: ");
	fgets(cadastro[opcao].endereco_comercial.rua,sizeof(cadastro[opcao].endereco_comercial.rua),stdin);
	cadastro[opcao].endereco_comercial.rua[strcspn(cadastro[opcao].endereco_comercial.rua,"\n")] = '\0';

	printf("Cidade:  ");
	fgets(cadastro[opcao].endereco_comercial.cidade,sizeof(cadastro[opcao].endereco_comercial.cidade),stdin);
	cadastro[opcao].endereco_comercial.cidade[strcspn(cadastro[opcao].endereco_comercial.cidade,"\n")] = '\0';

	printf("Numero:  ");
	scanf("%u",&cadastro[opcao].endereco_comercial.numero);
	getchar();

	printf("Cep:  ");
	fgets(cadastro[opcao].endereco_comercial.cep,sizeof(cadastro[opcao].endereco_comercial.cep),stdin);
	cadastro[opcao].endereco_comercial.cep[strcspn(cadastro[opcao].endereco_comercial.cep,"\n")] = '\0';

	printf("Estado:  ");
	fgets(cadastro[opcao].endereco_comercial.estado,sizeof(cadastro[opcao].endereco_comercial.estado),stdin);
	cadastro[opcao].endereco_comercial.estado[strcspn(cadastro[opcao].endereco_comercial.estado,"\n")] = '\0';

	printf("Complemento: ");
	fgets(cadastro[opcao].endereco_comercial.complemento,sizeof(cadastro[opcao].endereco_comercial.complemento),stdin);
	cadastro[opcao].endereco_comercial.complemento[strcspn(cadastro[opcao].endereco_comercial.complemento,"\n")] = '\0';

	printf("Endereço residencial\n\n");
	
	printf("Rua: ");
	fgets(cadastro[opcao].endereco_residencial.rua,sizeof(cadastro[opcao].endereco_residencial.rua),stdin);
	cadastro[opcao].endereco_residencial.rua[strcspn(cadastro[opcao].endereco_residencial.rua,"\n")] = '\0';

	printf("Cidade:  ");
	fgets(cadastro[opcao].endereco_residencial.cidade,sizeof(cadastro[opcao].endereco_residencial.cidade),stdin);
	cadastro[opcao].endereco_residencial.cidade[strcspn(cadastro[opcao].endereco_residencial.cidade,"\n")] = '\0';

	printf("Numero:  ");
	scanf("%u",&cadastro[opcao].endereco_residencial.numero);
	getchar();

	printf("Cep:  ");
	fgets(cadastro[opcao].endereco_residencial.cep,sizeof(cadastro[opcao].endereco_residencial.cep),stdin);
	cadastro[opcao].endereco_residencial.cep[strcspn(cadastro[opcao].endereco_residencial.cep,"\n")] = '\0';

	printf("Estado:  ");
	fgets(cadastro[opcao].endereco_residencial.estado,sizeof(cadastro[opcao].endereco_residencial.estado),stdin);
	cadastro[opcao].endereco_residencial.estado[strcspn(cadastro[opcao].endereco_residencial.estado,"\n")] = '\0';

	printf("Complemento: ");
	fgets(cadastro[opcao].endereco_residencial.complemento,sizeof(cadastro[opcao].endereco_residencial.complemento),stdin);
	cadastro[opcao].endereco_residencial.complemento[strcspn(cadastro[opcao].endereco_residencial.complemento,"\n")] = '\0';

	printf("\n");
	printf("Telefone \n");
	
	printf("Digite o DDD: "); 
	scanf("%u",&cadastro[opcao].telefone.DDD);
	
	printf("Digite o número: "); 
	scanf("%u",&cadastro[opcao].telefone.numero);

	printf("\nTelefone residencial \n");
	
	printf("Digite o DDD: "); 
	scanf("%u", &cadastro[opcao].telefone_residencial.DDD);
	
	printf("Digite o número: ");
	scanf("%u",&cadastro[opcao].telefone_residencial.numero);
return;
}
void anos_90(Cadastro cadastro[]){
	printf("\n");
	printf("As pessoas que nasceram depois dos anos 90 são: \n\n");
	
	for(int i = 0; i < 5; i++){
		if(cadastro[i].data_de_nascimento.ano > 1990){
		printf("Nome: %s\n",cadastro[i].nome);
		printf("CPF: %s\n",cadastro[i].CPF);
		printf("Sexo: %c\n",cadastro[i].sexo);
		printf("Estado Civil: %s\n",cadastro[i].estado_civil);
		printf("Salario: %d\n",cadastro[i].salario);
		printf("RG: %s\n",cadastro[i].rg);

		printf("\nEndereço comercial\n\n");

		printf("Rua: %s\n", cadastro[i].endereco_comercial.rua);
		printf("Cidade: %s\n", cadastro[i].endereco_comercial.cidade);
		printf("Numero: %d\n", cadastro[i].endereco_comercial.numero);
		printf("Cep: %s\n", cadastro[i].endereco_comercial.cep);
		printf("Estado: %s\n",cadastro[i].endereco_comercial.estado);
		printf("Complemento: %s\n", cadastro[i].endereco_comercial.complemento);
		printf("\n");

		printf("Endereço residencial\n\n");

		printf("Rua: %s\n", cadastro[i].endereco_residencial.rua);
		printf("Cidade: %s\n", cadastro[i].endereco_residencial.cidade);
		printf("Numero: %d\n", cadastro[i].endereco_residencial.numero);
		printf("Cep: %s\n", cadastro[i].endereco_residencial.cep);
		printf("Estado: %s\n",cadastro[i].endereco_residencial.estado);
		printf("Complemento: %s\n", cadastro[i].endereco_residencial.complemento);
		printf("\n");

		printf("Telefone: (%d) %d",cadastro[i].telefone.DDD, cadastro[i].telefone.numero);
		printf("\n");
		printf("Telefone residencia: (%d) %d", cadastro[i].telefone_residencial.DDD,cadastro[i].telefone_residencial.numero);
		printf("\n\n");
		}
	}
	printf("\n");
return;
}

void copiar(Cadastro cadastro[]){
	int origem = 0;
	int destino = 0;

	printf("Insira a origem e o destino dos dados \n");
	printf("Opções disponíveis: 0, 1, 2, 3 ou 4 \n");
	
	printf("Origem: ");
	scanf("%d",&origem);

	printf("Destino: ");
	scanf("%d",&destino);

	strcpy(cadastro[destino].nome,cadastro[origem].nome);
	strcpy(cadastro[destino].CPF,cadastro[origem].CPF);
	
	cadastro[destino].sexo = cadastro[origem].sexo;

	cadastro[destino].salario = cadastro[origem].salario;
	strcpy(cadastro[destino].rg,cadastro[origem].rg);

	strcpy(cadastro[destino].endereco_comercial.rua,cadastro[origem].endereco_comercial.rua);
	strcpy(cadastro[destino].endereco_comercial.cidade,cadastro[origem].endereco_comercial.cidade);

	cadastro[destino].endereco_comercial.numero = cadastro[origem].endereco_comercial.numero;
	
	strcpy(cadastro[destino].endereco_comercial.cep,cadastro[origem].endereco_comercial.cep);
	strcpy(cadastro[destino].endereco_comercial.estado,cadastro[origem].endereco_comercial.estado);
	strcpy(cadastro[destino].endereco_comercial.complemento,cadastro[origem].endereco_comercial.complemento);

	strcpy(cadastro[destino].endereco_residencial.rua,cadastro[origem].endereco_residencial.rua);
	strcpy(cadastro[destino].endereco_residencial.cidade,cadastro[origem].endereco_residencial.cidade);

	cadastro[destino].endereco_residencial.numero = cadastro[origem].endereco_residencial.numero;
	
	strcpy(cadastro[destino].endereco_residencial.cep,cadastro[origem].endereco_residencial.cep);
	strcpy(cadastro[destino].endereco_residencial.estado,cadastro[origem].endereco_residencial.estado);
	strcpy(cadastro[destino].endereco_residencial.complemento,cadastro[origem].endereco_residencial.complemento);

	cadastro[destino].telefone.DDD = cadastro[origem].telefone.DDD;
	cadastro[destino].telefone.numero = cadastro[origem].telefone.numero;

	cadastro[destino].telefone_residencial.DDD = cadastro[origem].telefone_residencial.DDD;
	cadastro[destino].telefone_residencial.numero = cadastro[origem].telefone_residencial.numero;

return;
}



int main(void){

	Cadastro cadastro[5] = {	 
		  
		  {"Euller","222.222.222-22",'M',"Solteiro",2000,"MG-22.222.222"
		 ,{"Gétulio Vargas","Uberlândia",222,"38222-022","MG","Casa"}
		 ,{"Rondon Pacheco","Uberlândia",345,"38345-45","MG","Apartamento"}
		 ,{34, 992345678},{34,994356789},{18,5,2000},{10,8,2018}}

		 ,{"João","333.333.333-33",'M',"Solteiro",3000,"MG-33.333.333"
		 ,{"Gétulio Vargas","Uberlândia",333,"38333-033","MG","Casa"}
		 ,{"Rondon Pacheco","Uberlândia",343,"38343-43","MG","Apartamento"}
		 ,{34, 992345673},{34,994356783},{18,5,1989},{10,8,2015}}

		 ,{"Maria","444.444.444-44",'F',"Solteira",4000,"MG-44.444.444"
		 ,{"Gétulio Vargas","Uberlândia",444,"38444-044","MG","Casa"}
		 ,{"Rondon Pacheco","Uberlândia",344,"38344-44","MG","Apartamento"}
		 ,{34, 992345674},{34,994356789},{18,5,1985},{10,8,2017}}

		 ,{"José","555.555.555-55",'M',"Solteiro",5000,"MG-55.555.555"
		 ,{"Gétulio Vargas","Uberlândia",555,"38555-055","MG","Casa"}
		 ,{"Rondon Pacheco","Uberlândia",345,"38345-45","MG","Apartamento"}
		 ,{34, 992345675},{34,994356785},{18,5,2002},{10,8,2019}}

		 ,{"Henrique","666.666.666-66",'M',"Solteiro",6000,"MG-66.666.666"
		 ,{"Gétulio Vargas","Uberlândia",666,"38666-066","MG","Casa"}
		 ,{"Rondon Pacheco","Uberlândia",346,"38346-46","MG","Apartamento"}
		 ,{34, 992345676},{34,994356786},{18,5,1999},{10,8,2016}}
		
	};

	char opcao = '\0'; 
	int loop = 0; 

while(loop == 0){
		opcao = menu();

		if(opcao == 1){
			listar(cadastro);
		}
		if(opcao == 2){
			cadastrar(cadastro);
		}
		if(opcao == 3){
			anos_90(cadastro);
		}
		if(opcao == 4){
			copiar(cadastro);
		}
	}

return 0;
}
/*Questão 05*/

#include <stdio.h>
#include <string.h>

typedef struct 
{
	char nome[51];
	char matricula[12];
	double notas_provas[3];
	int  faltas;
	double media;
} Estudantes;

int main(void){
		Estudantes estudantes[3];
		double nota_final[3] = {0};
		for(int i = 0; i < 3; i++){
			printf("Estudante %d\n",i+1);

			printf("Nome: ");
			fgets(estudantes[i].nome,sizeof(estudantes[i].nome),stdin);
			estudantes[i].nome[strcspn(estudantes[i].nome,"\n")] = '\0';

			printf("Matrícula: ");
			fgets(estudantes[i].matricula,sizeof(estudantes[i].matricula),stdin);
			estudantes[i].matricula[strcspn(estudantes[i].matricula,"\n")] = '\0';

			printf("Nota da primeira prova : ");
			scanf("%lf",&estudantes[i].notas_provas[0]);
			
			
			printf("Nota da segunda prova: ");
			scanf("%lf",&estudantes[i].notas_provas[1]);
			
			printf("Nota da terceira prova: ");
			scanf("%lf",&estudantes[i].notas_provas[2]);
			
			printf("Quantidade de faltas: ");
			scanf("%d",&estudantes[i].faltas);
			getchar();

			nota_final[i] = estudantes[i].notas_provas[0] + estudantes[i].notas_provas[1] + estudantes[i].notas_provas[2];

			printf("\n");
 		}

int posicao1 = 0;
		int posicao2 = 0;
		int posicao3 = 0;


 		for(int i = 0; i < 3; i++){
			estudantes[i].media = nota_final[i] /  3;  
		}

 		double maior = estudantes[0].media;
 		double menor = estudantes[0].media;
 		double maiorp1 = estudantes[0].notas_provas[0];
		
		for(int i = 0; i < 3; i++){
			if(estudantes[i].notas_provas[0] > maiorp1){
				maiorp1 = estudantes[i].notas_provas[0];
				posicao1 = i;	
			} 
			
			if(estudantes[i].media > maior){
				maior = estudantes[i].media;
				posicao2 = i;
			}
	
			if(estudantes[i].media < menor){
				menor = estudantes[i].media;
				posicao3 = i;
			}
		}
		printf("Aluno com a maior nota na P1 e sua nota: %s, %.2lf\n",estudantes[posicao1].nome,maiorp1);
		printf("Aluno com a maior média e sua nota: %s, %.2lf\n",estudantes[posicao2].nome,maior);
		printf("Aluno com a menor média e sua nota: %s, %.2lf\n",estudantes[posicao3].nome,menor);
		printf("\n");
		for(int i = 0; i < 3; i++){
			
			if(estudantes[i].faltas <= 18 && nota_final[i] >= 60){
					printf("Nome do aluno %d: %s\n",i+1,estudantes[i].nome);
					printf("Situação final: Aprovado\n\n");
			}
			else
			if(estudantes[i].faltas > 18 && nota_final[i] < 60){
				printf("Nome do aluno %d: %s\n",i+1,estudantes[i].nome);
				printf("Situação final: Reprovado por falta e por nota\n\n");
			}
			else
			if(estudantes[i].faltas > 18){
				printf("Nome do aluno %d: %s\n",i+1,estudantes[i].nome);
				printf("Situação final: Reprovado por falta\n\n");
			}
			else
			if(nota_final[i] < 60){
				printf("Nome do aluno %d: %s\n",i+1,estudantes[i].nome);
				printf("Situação final: Reprovado por nota\n\n");
			}
		}
return 0;
}

/*Questão 06*/

#include <stdio.h>
#include <string.h>

typedef struct{
	char nome[16];
	float potencia;
	float tempo_ativo;
	}Eletrodomestico;

int main(void){
	
	float consumo_total = 0;
	float consumo[5] = {0};
	float consumo_relativo[5] = {0};
	float tempo_dias = 0;
	Eletrodomestico eletrodomestico[5];

	for(int i = 0; i < 5; i++){
		
		printf("\nEletrodoméstico %d ", i+1);
		printf("\n");
		
		printf("Nome: ");
		fgets(eletrodomestico[i].nome,sizeof(eletrodomestico[i].nome),stdin);
		eletrodomestico[i].nome[strcspn(eletrodomestico[i].nome,"\n")] = '\0';

		printf("Potencia(em KW): ");
		scanf("%f",&eletrodomestico[i].potencia);

		printf("Tempo ativo: ");
		scanf("%f",&eletrodomestico[i].tempo_ativo);
		getchar();
	}
	printf("\n");
	printf("Tempo em dias: ");
	scanf("%f",&tempo_dias);

	for(int i = 0; i < 5; i++){
		consumo[i] = eletrodomestico[i].potencia * eletrodomestico[i].tempo_ativo;
		consumo_total =  consumo[i] + consumo_total;
	}
	consumo_total = consumo_total * tempo_dias;

	for(int i = 0; i < 5; i++){
		consumo_relativo[i] = ((consumo[i] * tempo_dias / consumo_total) * 100);
	}	
	printf("\n");
	printf("Consumo total na casa: %.2f",consumo_total);
	printf("\n");


	for(int i = 0; i < 5; i++){
		
		printf("\n");
		printf("Eletrodomestico %d\n",i+1);	
		printf("Consumo: %.2f",consumo[i]);
		printf("\n");
		printf("Consumo relativo: %.2f", consumo_relativo[i]);
		printf("\n");
	}
return 0;
}

/*Questão 07*/

#include <stdio.h>
#include <string.h>

typedef struct{
	char nome[16];
	float potencia;
	float tempo_ativo;
	}Eletrodomestico;

int main(void){
	
	float consumo_total = 0;
	float consumo[5] = {0};
	float consumo_relativo[5] = {0};
	float tempo_dias = 0;
	Eletrodomestico eletrodomestico[5];

	for(int i = 0; i < 5; i++){
		
		printf("\nEletrodoméstico %d ", i+1);
		printf("\n");
		
		printf("Nome: ");
		fgets(eletrodomestico[i].nome,sizeof(eletrodomestico[i].nome),stdin);
		eletrodomestico[i].nome[strcspn(eletrodomestico[i].nome,"\n")] = '\0';

		printf("Potencia(em KW): ");
		scanf("%f",&eletrodomestico[i].potencia);

		printf("Tempo ativo: ");
		scanf("%f",&eletrodomestico[i].tempo_ativo);
		getchar();
	}
	printf("\n");
	printf("Tempo em dias: ");
	scanf("%f",&tempo_dias);

	for(int i = 0; i < 5; i++){
		consumo[i] = eletrodomestico[i].potencia * eletrodomestico[i].tempo_ativo;
		consumo_total =  consumo[i] + consumo_total;
	}
	consumo_total = consumo_total * tempo_dias;

	for(int i = 0; i < 5; i++){
		consumo_relativo[i] = ((consumo[i] * tempo_dias / consumo_total) * 100);
	}	
	printf("\n");
	printf("Consumo total na casa: %.2f",consumo_total);
	printf("\n");


	for(int i = 0; i < 5; i++){
		
		printf("\n");
		printf("Eletrodomestico %d\n",i+1);	
		printf("Consumo: %.2f",consumo[i]);
		printf("\n");
		printf("Consumo relativo: %.2f", consumo_relativo[i]);
		printf("\n");
	}

	printf("\n");
	printf("Endereço do consumo_total: %u\n",&consumo_total);
	printf("Endereço do consumo[0]: %u\n",&consumo[0]);
	printf("Endereço do consumo[1]: %u\n",&consumo[1]);
	printf("Endereço do consumo[2]: %u\n",&consumo[2]);
	printf("Endereço do consumo[3]: %u\n",&consumo[3]);
	printf("Endereço do consumo[4]: %u\n",&consumo[4]);

	printf("Endereço do consumo_relativo[0]: %u\n",&consumo_relativo[0]);
	printf("Endereço do consumo_relativo[1]: %u\n",&consumo_relativo[1]);
	printf("Endereço do consumo_relativo[2]: %u\n",&consumo_relativo[2]);
	printf("Endereço do consumo_relativo[3]: %u\n",&consumo_relativo[3]);
	printf("Endereço do consumo_relativo[4]: %u\n",&consumo_relativo[4]);

	printf("Endereço do tempo_dias: %u\n",&tempo_dias);
		
return 0;
}
