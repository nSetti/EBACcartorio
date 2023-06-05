#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string


	//início do registro
int registro() //função responsável pelo registro de usuários
{
	//início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
		
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf);//função de cópia de string
	
	FILE *file; //criando o arquivo
	
	file = fopen(arquivo, "w"); 
	fprintf(file,cpf); //salvando o valor da variável
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	
	printf("Digite o nome a ser cadastrado: "); //cadastrando o nome
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome); //salvando o valor da variável
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file," ");
	fclose(file);
	
	
	printf("Digite o sobrenome a ser cadastrado: "); //cadastrando o sobrenome
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome); //salvando o valor da variável
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	
	printf("Digite o cargo a ser cadastrado: "); //cadastrando o cargo
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo); //salvando o valor da variável
	fclose(file); //fechando o arquivo
	
	system("pause"); //pausa o console
}
	//fim do registro


	//início da consulta
int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//início da criação de variáveis/string	
	char cpf[40];
	char conteudo[200];
	//final da criação de variáveis/string
	
	printf("Digite o cpf a ser consultado: "); //comunicação de consulta
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //lendo o arquivo
	
	if(file == NULL) //comunicação com o usuário para caso o arquivo seja inexistente ou ilegível
	{
		printf("Não foi possível encontrar o usuário.\n");
		printf("Arquivo não localizado, inexistente ou corrompido.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //impressão no console do arquivo encontrado 
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}	
	system("pause"); //pausa o console
}
	//fim da consulta


	//início da exclusão
int deletar()
{
	//início da criação da variável
	char cpf[40];
	//final da criação da variável/string
	
	printf("Digite o CPF do usuário que deseja deletar: "); //comunicação de exclusão
	scanf("%s",cpf);
	
	remove(cpf); //função de exclusão
	
	FILE *file;
	file = fopen(cpf,"r"); //lendo o arquivo
	
		
	if(file = fopen(cpf,"r")) //comunicação com o usuário caso o arquivo ainda esteja aberto no sistema	
	{
		printf("\n\nNão foi possível deletar o usuário!\n");
		printf("Por favor reinicie o programa e tente novamente.\n\n");
		system("pause"); //pausa o console
	}
	
	if(file == NULL) //comunicação de sucesso de exclusão ou arquivo inexistente
	{
		printf("\n\nUsuário deletado com sucesso ou inexistente.\n\n");
		system("pause"); //pausa o console
	}
}
	//fim da exclusão


int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;

	for(laco=1;laco=1;) //definindo repetições
	{
		system("cls"); //responsável por limpar as informações anteriores da tela

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		//início do menu
		printf("\tCartório da EBAC\n\n");
	
		printf("Por favor, escolha a opção desejada:\n\n");
	
		//início das opções
		printf("\t1 - Resgistrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair\n\n");
		printf("Digite a opção: ");
		//fim das opções
		//fim do menu
		
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls"); //responsável por limpar as informações anteriores da tela
		
		//início da seleção
		switch(opcao)
		{
			case 1:
			registro(); //chamada da função de registro
			break;
			
			case 2:
			consulta(); //chamada da função de consulta
			break;
			
			case 3:
			deletar(); //chamada da função de exclusão
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema.\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível!\n\n"); //comunicação com o usuário caso a seleção esteja fora das escolhas
			system("pause"); //pausa o console
			break;
		}
		//fim da seleção
	}
}
