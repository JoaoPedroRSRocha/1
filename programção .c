#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocaçães de texto por região
#include <string.h> //biblioteca responsável por cuidar das string


int registro() //função responsavel por cadastrar os usuário no sistema
{	
	setlocale(LC_ALL, "Portuguese");
	
	printf("\tRegístro de nomes!\n");
	//inicio da criação e variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis
	printf("Digite o CPF a ser cadastrado : "); //coletando informações do usuário
	scanf("%s",cpf); //%s refere-se a string/armazenando as string
	
	strcpy(arquivo,cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivo //"W" para criar novo arquivo
	fprintf(file,"CPF do usuário : "); 
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo,"a"); //"A" para atualizar arquivo
	fprintf(file,"\nNome do usuáro :"); //adicionar virgula
	fclose(file);
	
	printf("Digite o nome a ser cadastrado : ");
	scanf ("%s", nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,"\nSobrenome do usuário : ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado : ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,"\nCargo do usuário : ");
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
	
	printf("Digite o CPF do usuário a ser consultado : ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //"R" para ler o arquivo
	
	if(file == NULL) //"==" comparação 
	{
		printf("Arquivo não localizado!. \n");
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
	
	printf("\nDigite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\n\tO usuário não se encontra mais no sistema!.\n");
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
		
		printf("\t Cartório da EBAC\n\n");//inicio do menu
		printf("Escolha as opção desejada a seguir:\n\n");
		printf("\t1 - Resgistrar nomes\n");
		printf("\t2 - Cunsutar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Qual a opção desejada ?"); //fim do menu
			
		scanf("%d", &opcao); //armazenando a escolha do usuario 
					
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao)//inicio da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break; //fechar
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:printf("Essa opção é inexistente!\n");
			system("pause");
			break;
		}//fim da seleção
						
	}
}
