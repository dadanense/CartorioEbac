#include <stdio.h> 	//biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings


int registro()
{
	
	//in�cio das vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final das vari�veis
	
	printf("Digite o CPF a ser cadastrado:  ");
	scanf("%s", cpf); //%s refere-se ao scan da string 
	
	strcpy(arquivo, cpf);	//Respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //o W cria o arquivo e escreve
	fprintf(file, "CPF: ");
	fprintf(file,cpf);  //salva o valor da vari�vel
	fclose(file);   //fecha o arquivo
	
	file = fopen(arquivo, "a"); //o A apenas atualiza as informa��es do arquivo
	fclose(file);
	
	printf("Digite o nome a ser cadastrado:  ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "  Nome: ");
	fprintf(file,nome); //fun��o fprintf insere os dados dentro do arquivo
	fclose(file);
	
	file = fopen(arquivo, "a");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:  ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "  Sobrenome: ");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:  ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, "  Cargo: ");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
	
}


int consulta()
{
	setlocale(LC_ALL, "Portuguese");

	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel localizar este arquivo! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
		system("pause");

}


int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
		
	if(file == NULL)
	{
		printf("Usu�rio n�o encontrado no sistema!\n");
	}
		system("pause");
	
}

 
int main()													
{
	int opcao=0;	//Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		setlocale(LC_ALL, "Portuguese");	//Definindo a linguagem
	
		system("cls");	
	
		printf("### Cart�rio da EBAC ### \n\n");    //In�cio do menu
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n\n");   //Fim do menu
		printf("Op��o: ");
	
	
		scanf("%d", &opcao);		//Armazenando a escolha do usu�rio
	
		system("cls"); //Respons�vel por limpar a tela
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��o
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
						
			default:
			printf("Op��o inv�lida!\n");
			system("pause");
			break;	//fim da sele��o			
		}
	}
}
