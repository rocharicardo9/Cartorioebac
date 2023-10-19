#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alocação de espaço e memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Função responsavel por cadastrar os usuarios no sistema
{
	//inicio criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variaveis/string
	
	printf("Digite o CPF a ser cadastro: "); //coletando as informações do usuário
	scanf("%s", cpf); //%s refere-se as string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // criar o arquivo
	file = fopen(arquivo, "w"); // criar o arquivo e o "W" significa escrever 
	fprintf(file,cpf); // salvo o valor da variavel
    fclose(file); // fechar o arquivo
    
    file = fopen(arquivo,"a"); //Cria o arquivo e o "A" significa acessar (Atualizar)
    fprintf(file,","); // separndo as variaveis com a virgula 
    fclose(file); // fechar o arquivo 
    
    printf("Digite o nome a ser cadastrado: "); //coletando as informações
    scanf("%s",nome); //%s refere-se as string
    
    file = fopen(arquivo,"a"); // criar o arquivo  e o "A" significa acessar (Atualizar)
    fprintf(file,nome); // salvo o valor da variavel
    fclose(file); // fechar o arquivo 
    
    file = fopen(arquivo,"a"); // criar o arquivo e o "A" significa acessar (Atualizar)
    fprintf(file,","); //separando as variaveis com a virgula
    fclose(file); // fechar o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // coletando as informações 
	scanf("%s",sobrenome); //%s refere-se as string 
	
	file = fopen(arquivo,"a"); // criar o arquivo e o "A" significa acessar (Atualizar)
	fprintf(file,sobrenome); // salvo o valor da variavel 
	fclose(file); // fechar o arquivo 
	
	file = fopen(arquivo,"a"); // criar o arquivo e o "A" significa acessar (Atualizar)
    fprintf(file,","); // separando as variaveis com a virgula 
    fclose(file); // fechar o arquivo 
	
	printf("Digite o cargo a ser cadastrado: "); // coletando as informações 
	scanf("%s",cargo); //%s refere-se as string
	
	file = fopen(arquivo,"a"); // criar o arquivo e o "A" significa acessar (Atualizar)
	fprintf(file,cargo); // salvo o valor da variavel 
	fclose(file); // fechar o arquivo
	
	system("pause"); // pausando a informação para o usuario 
	
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
    printf("Não foi possivel abrir o arquivo, não localizado!\n");
    
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	printf("\nEssas são as informações do usuario: ");
	printf("%s", conteudo);
	printf("\n\n");
	}
    
    system("pause");
    

}


int deletar()
{
	char cpf[40]; //criando a vareavel ou string (CPF)
	
	printf("Digite o CPF do usuário a ser deletado:");
	scanf("%s",cpf); //salvando na vareavel (string)
	
	remove(cpf); // removendo a vareavel ou string (CPF)
	
	FILE *file;
	file = fopen(cpf,"r"); //lendo o arquivo CPF (r)
	
	if(file == NULL)
	{
		printf("O usuario não se encontra no sistema!.\n");
		system("pause");
	}
}



int main()
    {
    int opcao=0; //definindo as variáveis
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
            printf("Escolha a opção desejada do menu:\n\n");
            printf("\t1 - Registrar nomes\n");
            printf("\t2 - consultar nomes\n");
            printf("\t3 - Deletar nomes\n\n");
            printf("\t4 - sair do sistema\n\n");
	        printf("opção:"); //fim do menu
    
            scanf("%d", &opcao); //armazenado a escolha do usuário
    
            system("cls"); // responsavel por limpar a tela
        
        
            switch(opcao)// inicio da seleção do menu
            {
        	    case 1:
        	    registro(); //chamada de funções
    	        break;
    	    
    	        case 2:
    	        consulta(); //chamada de funções 
			    break;
			
			    case 3: 
			    deletar(); //chamada de funções
			    break;
			    
			    case 4:
			    printf("Obrigado por ultilizar o sistema!\n");
				return 0;
				break;	
		
		        default:
			    printf("Essa opcao nao esta disponivel!\n");
		        system("pause");
			    break;	
		    } // fim da seleção
    
	    }
    }
    
    else
        printf("Senha incorreta!");
        
        	
}

