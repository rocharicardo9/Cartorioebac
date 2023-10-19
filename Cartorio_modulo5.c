#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o e mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Fun��o responsavel por cadastrar os usuarios no sistema
{
	//inicio cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de variaveis/string
	
	printf("Digite o CPF a ser cadastro: "); //coletando as informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se as string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // criar o arquivo
	file = fopen(arquivo, "w"); // criar o arquivo e o "W" significa escrever 
	fprintf(file,cpf); // salvo o valor da variavel
    fclose(file); // fechar o arquivo
    
    file = fopen(arquivo,"a"); //Cria o arquivo e o "A" significa acessar (Atualizar)
    fprintf(file,","); // separndo as variaveis com a virgula 
    fclose(file); // fechar o arquivo 
    
    printf("Digite o nome a ser cadastrado: "); //coletando as informa��es
    scanf("%s",nome); //%s refere-se as string
    
    file = fopen(arquivo,"a"); // criar o arquivo  e o "A" significa acessar (Atualizar)
    fprintf(file,nome); // salvo o valor da variavel
    fclose(file); // fechar o arquivo 
    
    file = fopen(arquivo,"a"); // criar o arquivo e o "A" significa acessar (Atualizar)
    fprintf(file,","); //separando as variaveis com a virgula
    fclose(file); // fechar o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // coletando as informa��es 
	scanf("%s",sobrenome); //%s refere-se as string 
	
	file = fopen(arquivo,"a"); // criar o arquivo e o "A" significa acessar (Atualizar)
	fprintf(file,sobrenome); // salvo o valor da variavel 
	fclose(file); // fechar o arquivo 
	
	file = fopen(arquivo,"a"); // criar o arquivo e o "A" significa acessar (Atualizar)
    fprintf(file,","); // separando as variaveis com a virgula 
    fclose(file); // fechar o arquivo 
	
	printf("Digite o cargo a ser cadastrado: "); // coletando as informa��es 
	scanf("%s",cargo); //%s refere-se as string
	
	file = fopen(arquivo,"a"); // criar o arquivo e o "A" significa acessar (Atualizar)
	fprintf(file,cargo); // salvo o valor da variavel 
	fclose(file); // fechar o arquivo
	
	system("pause"); // pausando a informa��o para o usuario 
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o cpf a ser consultado: ");
    scanf("%s",cpf); //salvando na vareavel (String)
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file== NULL)
    {
    printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
    
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	printf("\nEssas s�o as informa��es do usuario: ");
	printf("%s", conteudo);
	printf("\n\n");
	}
    
    system("pause");
    

}


int deletar()
{
	char cpf[40]; //criando a vareavel ou string (CPF)
	
	printf("Digite o CPF do usu�rio a ser deletado:");
	scanf("%s",cpf); //salvando na vareavel (string)
	
	remove(cpf); // removendo a vareavel ou string (CPF)
	
	FILE *file;
	file = fopen(cpf,"r"); //lendo o arquivo CPF (r)
	
	if(file == NULL)
	{
		printf("O usuario n�o se encontra no sistema!.\n");
		system("pause");
	}
}



int main()
    {
    int opcao=0; //definindo as vari�veis
    int laco=1;
    char senhadigitada[10]="a";
    
    printf("###Cartorio da EBAC###\n\n");
    printf("Login de administrador!\n\nDigite a sua Senha: ");
    scanf("%s",senhadigitada);
    
    if(senhadigitada[10] = "admin")
    {
	
    
        for(laco=1;laco=1;)
        {
	
            system("cls");
	  	
	        setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	        printf("###Cartorio da EBAC###\n\n"); //inicio do menu
            printf("Escolha a op��o desejada do menu:\n\n");
            printf("\t1 - Registrar nomes\n");
            printf("\t2 - consultar nomes\n");
            printf("\t3 - Deletar nomes\n\n");
            printf("\t4 - sair do sistema\n\n");
	        printf("op��o:"); //fim do menu
    
            scanf("%d", &opcao); //armazenado a escolha do usu�rio
    
            system("cls"); // responsavel por limpar a tela
        
        
            switch(opcao)// inicio da sele��o do menu
            {
        	    case 1:
        	    registro(); //chamada de fun��es
    	        break;
    	    
    	        case 2:
    	        consulta(); //chamada de fun��es 
			    break;
			
			    case 3: 
			    deletar(); //chamada de fun��es
			    break;
			    
			    case 4:
			    printf("Obrigado por ultilizar o sistema!\n");
				return 0;
				break;	
		
		        default:
			    printf("Essa opcao nao esta disponivel!\n");
		        system("pause");
			    break;	
		    } // fim da sele��o
    
	    }
    }
    
    else
        printf("Senha incorreta!");
        
        	
}

