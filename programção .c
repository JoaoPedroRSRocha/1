#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string


int registro() //fun��o responsavel por cadastrar os usu�rio no sistema
{	
	setlocale(LC_ALL, "Portuguese");
	
	printf("\tReg�stro de nomes!\n");
	//inicio da cria��o e vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis
	printf("Digite o CPF a ser cadastrado : "); //coletando informa��es do usu�rio
	scanf("%s",cpf); //%s refere-se a string/armazenando as string
	
	strcpy(arquivo,cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivo //"W" para criar novo arquivo
	fprintf(file,"CPF do usu�rio : "); 
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo,"a"); //"A" para atualizar arquivo
	fprintf(file,"\nNome do usu�ro :"); //adicionar virgula
	fclose(file);
	
	printf("Digite o nome a ser cadastrado : ");
	scanf ("%s", nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,"\nSobrenome do usu�rio : ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado : ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,"\nCargo do usu�rio : ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado : ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	printf("\tConsultar nomes!\n");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF do usu�rio a ser consultado : ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //"R" para ler o arquivo
	
	if(file == NULL) //"==" compara��o 
	{
		printf("Arquivo n�o localizado!. \n");
	}
	
	while(fgets(conteudo,200,file) != NULL) //procurar no arquivo 
	{
		printf("%s",conteudo);
		printf("\n");
	}
	
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	printf("\tDeletar nomes!\n");
	
	
	char cpf[40];
	
	printf("\nDigite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\n\tO usu�rio n�o se encontra mais no sistema!.\n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //definindo as variaveis
	
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //responsavel por limpar a tela 
		
		setlocale(LC_ALL, "Portuguese"); //escolha de linguagem
		
		printf("\t Cart�rio da EBAC\n\n");//inicio do menu
		printf("Escolha as op��o desejada a seguir:\n\n");
		printf("\t1 - Resgistrar nomes\n");
		printf("\t2 - Cunsutar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Qual a op��o desejada ?"); //fim do menu
			
		scanf("%d", &opcao); //armazenando a escolha do usuario 
					
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao)//inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break; //fechar
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:printf("Essa op��o � inexistente!\n");
			system("pause");
			break;
		}//fim da sele��o
						
	}
}
