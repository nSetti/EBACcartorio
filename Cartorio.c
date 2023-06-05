#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string


	//in�cio do registro
int registro() //fun��o respons�vel pelo registro de usu�rios
{
	//in�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
		
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf);//fun��o de c�pia de string
	
	FILE *file; //criando o arquivo
	
	file = fopen(arquivo, "w"); 
	fprintf(file,cpf); //salvando o valor da vari�vel
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	
	printf("Digite o nome a ser cadastrado: "); //cadastrando o nome
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome); //salvando o valor da vari�vel
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file," ");
	fclose(file);
	
	
	printf("Digite o sobrenome a ser cadastrado: "); //cadastrando o sobrenome
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome); //salvando o valor da vari�vel
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	
	printf("Digite o cargo a ser cadastrado: "); //cadastrando o cargo
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo); //salvando o valor da vari�vel
	fclose(file); //fechando o arquivo
	
	system("pause"); //pausa o console
}
	//fim do registro


	//in�cio da consulta
int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//in�cio da cria��o de vari�veis/string	
	char cpf[40];
	char conteudo[200];
	//final da cria��o de vari�veis/string
	
	printf("Digite o cpf a ser consultado: "); //comunica��o de consulta
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //lendo o arquivo
	
	if(file == NULL) //comunica��o com o usu�rio para caso o arquivo seja inexistente ou ileg�vel
	{
		printf("N�o foi poss�vel encontrar o usu�rio.\n");
		printf("Arquivo n�o localizado, inexistente ou corrompido.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //impress�o no console do arquivo encontrado 
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}	
	system("pause"); //pausa o console
}
	//fim da consulta


	//in�cio da exclus�o
int deletar()
{
	//in�cio da cria��o da vari�vel
	char cpf[40];
	//final da cria��o da vari�vel/string
	
	printf("Digite o CPF do usu�rio que deseja deletar: "); //comunica��o de exclus�o
	scanf("%s",cpf);
	
	remove(cpf); //fun��o de exclus�o
	
	FILE *file;
	file = fopen(cpf,"r"); //lendo o arquivo
	
		
	if(file = fopen(cpf,"r")) //comunica��o com o usu�rio caso o arquivo ainda esteja aberto no sistema	
	{
		printf("\n\nN�o foi poss�vel deletar o usu�rio!\n");
		printf("Por favor reinicie o programa e tente novamente.\n\n");
		system("pause"); //pausa o console
	}
	
	if(file == NULL) //comunica��o de sucesso de exclus�o ou arquivo inexistente
	{
		printf("\n\nUsu�rio deletado com sucesso ou inexistente.\n\n");
		system("pause"); //pausa o console
	}
}
	//fim da exclus�o


int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;

	for(laco=1;laco=1;) //definindo repeti��es
	{
		system("cls"); //respons�vel por limpar as informa��es anteriores da tela

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		//in�cio do menu
		printf("\tCart�rio da EBAC\n\n");
	
		printf("Por favor, escolha a op��o desejada:\n\n");
	
		//in�cio das op��es
		printf("\t1 - Resgistrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair\n\n");
		printf("Digite a op��o: ");
		//fim das op��es
		//fim do menu
		
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
		
		system("cls"); //respons�vel por limpar as informa��es anteriores da tela
		
		//in�cio da sele��o
		switch(opcao)
		{
			case 1:
			registro(); //chamada da fun��o de registro
			break;
			
			case 2:
			consulta(); //chamada da fun��o de consulta
			break;
			
			case 3:
			deletar(); //chamada da fun��o de exclus�o
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema.\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n\n"); //comunica��o com o usu�rio caso a sele��o esteja fora das escolhas
			system("pause"); //pausa o console
			break;
		}
		//fim da sele��o
	}
}
