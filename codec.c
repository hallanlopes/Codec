/*
- Descricão fonte : Definicão das Funcões do Codificador/Decodificador + Compactador/Descompactador 
- Disciplina      : Seguranca e Auditoria de Sistemas 
- Professor       : Mr.Oberdan Rolim 
- Aluno 	      : Raffael Bottoli Schemmer 
- Data Termino    : 24/08/2008 
*/

#include<stdio.h>  /* printf scanf fopen feof fgets sscanf fprintf */
#include<stdlib.h> /* system atoi itoa */
#include <string.h> /* strcpy strcmp strlen strcat */
#define X 1024
#define Y 256
#define Z 4086
#define TAM 30

///////////////////////////////////////////////////////////////////////// Declaracão de Variaveis do tipo FILE
FILE *arquivo; /* Ponteiro para arquivo */
///////////////////////////////////////////////////////////////////////// Declaracão de Variaveis do tipo Char
char nome_arquivo[TAM];
char matriz_memoria[X][Y];
char temp[Y];
char temp2[Y];
char tipo_arquivo;
///////////////////////////////////////////////////////////////////////// Declaracão de Variaveis do tipo Int
int linha,coluna,contador1,contador2,contador3,contador4,tamanho_palavra,tamanho_arquivo_compactado;
int tamanho_linha,contador,chave,contador5,flag,tamanho_arquivo,contador_aless,contador6,linha1,marcador;
///////////////////////////////////////////////////////////////////////// Declaracão de Variaveis do tipo banco_dados
struct banco_dados
{
	int peso;
	char nome[20];
	char aless[3];
	
}palavra[Z],ranking;
///////////////////////////////////////////////////////////////////////// Funcao que reporta os erros a interface
void reportar_retornos(int erro,int pos,int cas)
{
	switch(cas) // Verifica a qual case pertence a chamada
	{
		case(0): // Chamadas externas aos cases (Abertura && Leitura de arquivo)
		{
			switch(pos)
			{
				case(1): // Erros referentes a abertura de um arquivo
				{
					if(erro == 1)printf("\nArquivo nao encontrado !!\n\n");
					break;
				} 
				case(2): // Erros referentes a carregamento de arquivo para memoria
				{
					if(erro == 1)printf("\nO programa nao suporta a extensao de arquivo informada !!\n\n");
					if(erro == 2)printf("\nOs dados do arquivo nao batem com a extensao !!\n\n");
					break;
				} 
			}
			break;
		}
		case(1): // Tratamento de erros da Codificacão de arquivo
		{
			switch(pos)
			{
				case(1): // Erros referentes a codificacão de um arquivo
				{
					if(erro == 1)printf("\nVoce nao pode codificar um arquivo compactado !!\n\n");
					if(erro == 2)printf("\nO arquivo que voce deseja codificar ja esta codificado !!\n\n");
					break;
				} 
				case(2): // Erros referentes a carregamento de arquivo para disco
				{
					if(erro == 1)printf("\nNao foi possivel carregar arquivo para o disco !!\n\n");
					break;
				} 
				case(3): // Impressão de que a codificacão foi efetuada com sucesso	
				{
					printf("\nArquivo codificado com sucesso !!\n\n");
					break;
				} 
			}
			break;
		}
		case(2): // Tratamento de erros da Decodificacão de arquivo
		{
			switch(pos)
			{
				case(1): // Erros referentes a decodificacao de um arquivo
				{
					if(erro == 1){printf("\nVoce nao pode decodificar um arquivo texto !!\n\n");}
					if(erro == 2){printf("\nVoce nao pode decodificar um arquivo compactado !!\n\n");}
					break;
				}
				case(2): // Erros referentes a carregamento de arquivo para disco
				{
					if(erro == 1)printf("\nNao foi possivel carregar arquivo para o disco !!\n\n");
					break;
				} 
				case(3): // Impressão de que a decodificacão foi efetuada com sucesso	
				{
					printf("\nArquivo Decodificado com sucesso !!\n\n");
					break;
				}
			}
			break;
		}
		case(3): // Tratamento de erros da Compactacao de arquivo
		{
			switch(pos)
			{
				case(1): // Erros referentes a compactacão de um arquivo
				{
					if(erro == 1)printf("\nVoce nao pode compactar um arquivo compactado !!\n\n");
					break;
				} 
				case(2): // Erros referentes a carregamento de arquivo para disco
				{
					if(erro == 1)printf("\nNao foi possivel carregar arquivo para o disco !!\n\n");
					break;
				} 
				case(3): // Impressão de que a compactacao foi efetuada com sucesso	
				{
					printf("\nArquivo Compactado com sucesso !!\n\n");
					break;
				}
			}
			break;
		}
		case(4): // Tratamento de erros da Descompactacao de arquivo
		{
			switch(pos)
			{
				case(1): // Erros referentes a descompactacao de um arquivo
				{
					if(erro == 1){printf("Nao e possivel descompactar um arquivo(txt) nao compactado ");}
					if(erro == 2){printf("Nao e possivel descompactar um arquivo(cfr) nao compactado ");}
					break;
				} 
				case(2): // Erros referentes a carregamento de arquivo para disco
				{
					if(erro == 1)printf("\nNao foi possivel carregar arquivo para o disco !!\n\n");
					break;
				} 
				case(3): // Impressão de que a descompactacao foi efetuada com sucesso	
				{
					printf("\nArquivo Descompactado com sucesso !!\n\n");
					break;
				}
			}
			break;
		}
		case(5): // Tratamento de erros da Codificacao e Compactacao de arquivo
		{
			switch(pos)
			{
				case(1):{break;} // Erros referentes a codificacao de um arquivo
				case(2):{break;} // Erros referentes a compactacao de um arquivo
				case(3): // Erros referentes a carregamento de arquivo para disco
				{
					if(erro == 1)printf("\nNao foi possivel carregar arquivo para o disco !!\n\n");
					break;
				}
				case(4): // Impressão de que a codificacao e a compactacao foram efetuadas com sucesso
				{
					printf("\nArquivo Codificado e Compactado com sucesso !!\n\n");
					break;
				} 
			}
			break;
		}
		case(6): // Tratamento de erros da Descompactacao e Decodificacao de arquivo
		{
			switch(pos)
			{
				case(1):{break;} // Erros referentes a descompactacao de um arquivo
				case(2):{break;} // Erros referentes a decodificacao de um arquivo
				case(3): // Erros referentes a carregamento de arquivo para disco
				{
					if(erro == 1)printf("\nNao foi possivel carregar arquivo para o disco !!\n\n");
					break;
				}
				case(4): // Impressão de que a descompactacao e a decodificacao foram efetuadas com sucesso
				{
					printf("\nArquivo Descompactado e Decodificado com sucesso !!\n\n");
					break;
				} 
			}
			break;
		}
		case(7): // Tratamento de erros da Visualizacao de arquivo
		{
			switch(pos)
			{
				case(1):{break;} // Erros referentes a visualizacão do arquivo
				case(2):{break;} // Impressão de que a visualizacão foi efetuada com sucesso
			}
			break;
		}
		case(8): // Tratamento de erros da Exibicão das propriedades de arquivo
		{
			switch(pos)
			{
				case(1):{break;} // Erros referentes a exibicão das propriedades de um arquivo
				case(2):{break;} // Impressão de que a exibicão das propriedades foi efetuada com sucesso
			}
			break;
		}
	}
	system("pause");
	system("cls");
}

/////////////////////////////////////////////////////////////////////// Funcao que le a chave do usuario e retorna para o sistema
int le_valor_chave(int chave) // Ok
{
	printf("\nEntre com o valor da chave (Obs : Entre com valor inteiro) : ");
	scanf("%d",&chave);
	fflush(stdin);
	return(chave);
}
/////////////////////////////////////////////////////////////////////// Funcao que le o nome do arquivo de entrada e retorna para o sistema
void le_nome_entrada(char *nome[TAM]) // Ok
{
	system("cls");
	printf("\t|| ------------------- || -- Informando um arquivo -- || ------------------- ||\n\n\n\n");
	printf("Entre com o nome do arquivo a ser lido (Arquivos Suportados : .txt/.cfr/.shr) : ");
	scanf("%s",nome);
	fflush(stdin);
}
/////////////////////////////////////////////////////////////////////// Funcao que realiza a leitura do arquivo
int abrir_arquivo(char nome_arquivo[TAM]) // Ok
{
	arquivo = fopen(nome_arquivo,"rb");
	if(arquivo == NULL)
	{
		return(1); // Retorna 1 quando não conseguiu abrir o arquivo
	}
	return(0); // Retorna 0 se conseguiu abrir o arquivo
}
/////////////////////////////////////////////////////////////////////// Funcao que carrega o arquivo do disco para a memoria
int carregar_arquivo_para_memoria()// Ok
{
	while(!feof(arquivo)) /* Enquanto for diferente do final do arquivo executa */
	{
        fgets(matriz_memoria[linha],Y,arquivo); /* Copia 100 caracteres do arquivo na matriz */		
		linha++;
	}
	tamanho_linha = strlen(nome_arquivo); // Verifica o tamanho do nome do arquivo(com sua extensão)
	if(nome_arquivo[tamanho_linha-4] == '.'  && nome_arquivo[tamanho_linha-3] == 't' && nome_arquivo[tamanho_linha-2] == 'x' && nome_arquivo[tamanho_linha-1] == 't')
	{
		tipo_arquivo = 'T'; // Caso a extensão do arquivo for txt atribui a variavel tipo de arquivo o char T
	}
	else if(nome_arquivo[tamanho_linha-4] == '.'  && nome_arquivo[tamanho_linha-3] == 'c' && nome_arquivo[tamanho_linha-2] == 'f' && nome_arquivo[tamanho_linha-1] == 'r')
	{
		tipo_arquivo = 'C'; // Caso a extensão do arquivo for cfr atribui a variavel tipo de arquivo o char C
	}
	else if(nome_arquivo[tamanho_linha-4] == '.'  && nome_arquivo[tamanho_linha-3] == 's' && nome_arquivo[tamanho_linha-2] == 'h' && nome_arquivo[tamanho_linha-1] == 'r')
	{
		tipo_arquivo = 'S'; // Caso a extensão do arquivo for shr atribui a variavel tipo de arquivo o char S
	}
	else
	{
		return(1); // Extensão de arquivo desconhecido pelo programa
	}
	tamanho_linha = strlen(matriz_memoria[0]); // Verifica o tamanho da primeira linha do arquivo
	contador1=0; // Zera um contador temporario qualquer
	if((matriz_memoria[0][0] == 't' || matriz_memoria[0][0] == 'T') && (matriz_memoria[0][1] == 'x' || matriz_memoria[0][1] == 'X') && (matriz_memoria[0][2] == 't' || matriz_memoria[0][2] == 'T') && tipo_arquivo == 'T')
	{
		for(contador=0;contador<tamanho_linha;contador++)
		{
			if(matriz_memoria[0][contador] != ' ' && matriz_memoria[0][contador] != '\n') // Conta o numero de caracteres da primeira linha menos os caracteres " " e \n
			{
				contador1++;
			}
		}
		if(contador1 > 4) 
		{
			return(2); // Extensão de arquivo não bate com o tipo do arquivo
		}
		else
		{
			return(0);
		}
	}
	else if((matriz_memoria[0][0] == 'c' || matriz_memoria[0][0] == 'C') && (matriz_memoria[0][1] == 'f' || matriz_memoria[0][1] == 'F') && (matriz_memoria[0][2] == 'r' || matriz_memoria[0][2] == 'R') && tipo_arquivo == 'C')
	{ // Verifica se a primeira linha do arquivo contem uma palavra igual a CFR ou cfr
		for(contador=0;contador<tamanho_linha;contador++)
		{
			if(matriz_memoria[0][contador] != ' ' && matriz_memoria[0][contador] != '\n') // Conta o numero de caracteres da primeira linha menos os caracteres " " e \n
			{
				contador1++;
			}
		}
		if(contador1 > 4) 
		{
			return(2); // Extensão de arquivo não bate com o tipo do arquivo
		}
		else
		{
			return(0);
		}
	}
	else if((matriz_memoria[0][0] == 's' || matriz_memoria[0][0] == 'S') && (matriz_memoria[0][1] == 'h' || matriz_memoria[0][1] == 'H') && (matriz_memoria[0][2] == 'r' || matriz_memoria[0][2] == 'R') && tipo_arquivo == 'S')
	{ // Verifica se a primeira linha do arquivo contem uma palavra igual a SHR ou shr
		for(contador=0;contador<tamanho_linha;contador++)
		{
			if(matriz_memoria[0][contador] != ' ' && matriz_memoria[0][contador] != '\n') // Conta o numero de caracteres da primeira linha menos os caracteres " " e \n
			{
				contador1++;
			}
		}
		if(contador1 > 5) 
		{
			return(2); // Extensão de arquivo não bate com o tipo do arquivo
		}
		else
		{
			return(0);
		}
	}
	else
	{
		return(2);
	}
}
/////////////////////////////////////////////////////////////////////// Funcao que carrega o arquivo da memoria para o disco
int carregar_arquivo_para_disco(char formato_saida) // Ok
{
	tamanho_linha = strlen(nome_arquivo); 
	if(formato_saida == '1') // Saida da codificacão de arquivo
	{
		nome_arquivo[tamanho_linha-3] = 'c';
		nome_arquivo[tamanho_linha-2] = 'f';
		nome_arquivo[tamanho_linha-1] = 'r';
	}
	if(formato_saida == '2') // Saida da decodificacão de arquivo
	{
		nome_arquivo[tamanho_linha-3] = 't';
		nome_arquivo[tamanho_linha-2] = 'x';
		nome_arquivo[tamanho_linha-1] = 't';
	}
	if(formato_saida == '3') // Saida da compactacão de arquivo
	{
		nome_arquivo[tamanho_linha-3] = 's';
		nome_arquivo[tamanho_linha-2] = 'h';
		nome_arquivo[tamanho_linha-1] = 'r';
	}
	if(formato_saida == '4') // Saida da descompactacão de arquivo
	{
		if(tipo_arquivo == 'T')
		{
			nome_arquivo[tamanho_linha-3] = 't';
			nome_arquivo[tamanho_linha-2] = 'x';
			nome_arquivo[tamanho_linha-1] = 't';
		}
		if(tipo_arquivo == 'C')
		{
			nome_arquivo[tamanho_linha-3] = 'c';
			nome_arquivo[tamanho_linha-2] = 'f';
			nome_arquivo[tamanho_linha-1] = 'r';
		}
	}
	arquivo = fopen(nome_arquivo,"wb"); 
	if(arquivo == NULL) 
	{
		return(1);
	}
	for(contador=0;contador<linha;contador++)
	{
		tamanho_linha = strlen(matriz_memoria[contador]);
		for(contador1=0;contador1<tamanho_linha;contador1++)
		{
			fprintf(arquivo,"%c",matriz_memoria[contador][contador1]);
		}
	}
	return(0);
}
/////////////////////////////////////////////////////////////////////// Funcao que codifica o arquivo de acordo com uma chave informada
int codificar(int chave) // Ok
{
	if(tipo_arquivo == 'S')
	{
		return(1); 
	}
	if(tipo_arquivo == 'C')
	{
		return(2);
	}	
	matriz_memoria[0][0] = 'c';
	matriz_memoria[0][1] = 'f';
	matriz_memoria[0][2] = 'r';
	matriz_memoria[0][3] = 13;
	for(contador=1;contador<linha;contador++)
	{
		tamanho_linha = strlen(matriz_memoria[contador]);
		for(contador1=0;contador1<tamanho_linha;contador1++)
		{
			contador2 = matriz_memoria[contador][contador1] + chave;
			if((matriz_memoria[contador][contador1] >= 65 && matriz_memoria[contador][contador1] <= 90) || (matriz_memoria[contador][contador1] >= 97 && matriz_memoria[contador][contador1] <= 122))
			{
				if(matriz_memoria[contador][contador1] <= 90 && contador2 > 90) 
				{
					contador2 = contador2 - 90;
					matriz_memoria[contador][contador1] = 64 + contador2;
					continue;
				}
				else if(matriz_memoria[contador][contador1] <= 122 && contador2 > 122)
				{
					contador2 = contador2 - 122;
					matriz_memoria[contador][contador1] = 96 + contador2;
					continue;
				}
				else 
				{
					matriz_memoria[contador][contador1] = contador2;
				}
			}
		}
	}	
	return(0);
}/////////////////////////////////////////////////////////////////////// Funcao que decodifica o arquivo de acordo com uma chave informada
int decodificar(int chave)// Ok
{
	if(tipo_arquivo == 'T')
	{
		return(1);
	}
	if(tipo_arquivo == 'S')
	{
		return(2);
	}
	matriz_memoria[0][0] = 't';
	matriz_memoria[0][1] = 'x';
	matriz_memoria[0][2] = 't';
	matriz_memoria[0][3] = 13;
	for(contador=1;contador<linha;contador++)
	{
		tamanho_linha = strlen(matriz_memoria[contador]);
		for(contador1=0;contador1<tamanho_linha;contador1++)
		{
			contador2 = matriz_memoria[contador][contador1] - chave;
			if((matriz_memoria[contador][contador1] >= 65 && matriz_memoria[contador][contador1] <= 90) || (matriz_memoria[contador][contador1] >= 97 && matriz_memoria[contador][contador1] <= 122))
			{
				if((matriz_memoria[contador][contador1] <= 90 && matriz_memoria[contador][contador1] >= 65) && contador2 < 65)
				{
					contador2 = 64 - contador2;
					matriz_memoria[contador][contador1] = 90 - contador2;
					continue;
				}
				else if((matriz_memoria[contador][contador1] <= 122 && matriz_memoria[contador][contador1] >= 97) && contador2 < 97) 
				{
					contador2 = 96 - contador2;
					matriz_memoria[contador][contador1] = 122 - contador2;
					continue;
				}	
				else
				{
					matriz_memoria[contador][contador1] = contador2;
				}	
			}
		}
	}
	return(0);
}
/////////////////////////////////////////////////////////////////////// Funcao que compacta um arquivo
int compactar() // Verificar
{
	contador_aless = 0; // Incrementar as posicoes da estrutura
	flag=0;
	if(tipo_arquivo == 'S')
	{
		return(1); // O arquivo que voce quer compactar já esta compactado
	}
	for(contador1=1;contador1<linha;contador1++)// Varre as linhas do arquivo
	{
		tamanho_linha = strlen(matriz_memoria[contador1]);
		contador2=0;
		while(contador2 < tamanho_linha-2)            
		{
			contador4=0; // Incrementar as posicoes do nome da nova palavra
			while(matriz_memoria[contador1][contador2] != 11 && matriz_memoria[contador1][contador2] != 04 && matriz_memoria[contador1][contador2] != 32 && matriz_memoria[contador1][contador2] != 33 && matriz_memoria[contador1][contador2] != 34 && matriz_memoria[contador1][contador2] != 35 && matriz_memoria[contador1][contador2] != 36 && matriz_memoria[contador1][contador2] != 37 && matriz_memoria[contador1][contador2] != 38 && matriz_memoria[contador1][contador2] != 39 && matriz_memoria[contador1][contador2] != 40 && matriz_memoria[contador1][contador2] != 41 && matriz_memoria[contador1][contador2] != 42 && matriz_memoria[contador1][contador2] != 43 && matriz_memoria[contador1][contador2] != 44 && matriz_memoria[contador1][contador2] != 45 && matriz_memoria[contador1][contador2] != 46 && matriz_memoria[contador1][contador2] != 47 && matriz_memoria[contador1][contador2] != 58 && matriz_memoria[contador1][contador2] != 59 && matriz_memoria[contador1][contador2] != 60 && matriz_memoria[contador1][contador2] != 61 && matriz_memoria  [contador1][contador2] != 62 && matriz_memoria[contador1][contador2] != 63&& matriz_memoria[contador1][contador2] != 64 && matriz_memoria[contador1][contador2] != 91 && matriz_memoria[contador1][contador2] != 92 && matriz_memoria[contador1][contador2] != 93 && matriz_memoria[contador1][contador2] != 94 && matriz_memoria[contador1][contador2] != 95 && matriz_memoria[contador1][contador2] != 96 && matriz_memoria[contador1][contador2] != 123 && matriz_memoria[contador1][contador2] != 124 && matriz_memoria[contador1][contador2] != 125 && matriz_memoria[contador1][contador2] != 126)
			{ // Procura a nova palavra na string que armazena temporariamente a linha
				flag = 1;
				temp[contador4] = matriz_memoria[contador1][contador2];
				contador4++;
				contador2++;
			}
			temp[contador4] = '\0';
			contador5=0;
			if(flag == 1) // Verifica se foi encontrado uma palavra nova
			{	
				if(contador4 > 4) // Verifica se a palavra encontrada é maior que 2(senão nem compensa criar aless)
				{
					while(contador5 < contador_aless) // Verifica se a palavra encontrada já não pertence a uma das cadastradas no banco de aless
					{
						if((contador = strcmp(palavra[contador5].nome,temp) == 0)) // Caso encontrar uma palavra igual incrementa o contador da palavra em +1
						{
							palavra[contador5].peso++;
							break; // Para a execucão do codigo
						}
						contador5++;
					}
					if(contador5 == contador_aless) // Caso o contador chegar ao fim tudo indica que a nova palavra encontrada deve ser cadastrada no banco
					{
						strcpy(palavra[contador_aless].nome,temp);  // É feito uma copia do nome ao banco de dados
						palavra[contador_aless].peso++; // Seu novo peso é incrementando em 1 
						contador_aless++; // O contador do banco é incrementado (Nova palavra cadastrada)
					}
				}
				flag = 0; // O contador verificador de palavras é zerado
			}
			contador2++; // Contador de posicão de caracteres é atualizado
		}
		
	}
	for(contador1 = 0;contador1<contador_aless;contador1++) // Bloco que realiza o deslocamento decrescente dos pesos das palavras mais cotadas
	{
		for(contador = contador1;contador<contador_aless;contador++)
		{
			if(palavra[contador1].peso < palavra[contador].peso) 
			{
				ranking.peso =  palavra[contador1].peso; // Realiza a substituicão dos pesos e nomes usando um temporario do tipo banco_dados
				strcpy(ranking.nome,palavra[contador1].nome);
				palavra[contador1].peso = palavra[contador].peso;
				strcpy(palavra[contador1].nome,palavra[contador].nome);
				palavra[contador].peso = ranking.peso;
				strcpy(palavra[contador].nome,ranking.nome);
			}
		}
	}
	if(contador_aless>10)
	{
		contador_aless = 10;
	}
	tamanho_arquivo=0; // Calcula o tamanho do arquivo residente em memoria
	for(contador1=1;contador1<linha;contador1++)
	{
		tamanho_arquivo = tamanho_arquivo + strlen(matriz_memoria[contador1]);
	}
	// Busca as palavras no arquivo e substitui as iguais contidas na base de dados de aless
	flag=0;
	linha1 = linha;
	for(contador1=1;contador1<linha;contador1++)
	{
		tamanho_linha = strlen(matriz_memoria[contador1]);
		contador2=0;
		while(contador2 < tamanho_linha-2)            
		{
			contador4=0; // Incrementar as posicoes do nome da nova palavra
			while(matriz_memoria[contador1][contador2] != 11 && matriz_memoria[contador1][contador2] != 04 && matriz_memoria[contador1][contador2] != 32 && matriz_memoria[contador1][contador2] != 33 && matriz_memoria[contador1][contador2] != 34 && matriz_memoria[contador1][contador2] != 35 && matriz_memoria[contador1][contador2] != 36 && matriz_memoria[contador1][contador2] != 37 && matriz_memoria[contador1][contador2] != 38 && matriz_memoria[contador1][contador2] != 39 && matriz_memoria[contador1][contador2] != 40 && matriz_memoria[contador1][contador2] != 41 && matriz_memoria[contador1][contador2] != 42 && matriz_memoria[contador1][contador2] != 43 && matriz_memoria[contador1][contador2] != 44 && matriz_memoria[contador1][contador2] != 45 && matriz_memoria[contador1][contador2] != 46 && matriz_memoria[contador1][contador2] != 47 && matriz_memoria[contador1][contador2] != 58 && matriz_memoria[contador1][contador2] != 59 && matriz_memoria[contador1][contador2] != 60 && matriz_memoria[contador1][contador2] != 61 && matriz_memoria  [contador1][contador2] != 62 && matriz_memoria[contador1][contador2] != 63&& matriz_memoria[contador1][contador2] != 64 && matriz_memoria[contador1][contador2] != 91 && matriz_memoria[contador1][contador2] != 92 && matriz_memoria[contador1][contador2] != 93 && matriz_memoria[contador1][contador2] != 94 && matriz_memoria[contador1][contador2] != 95 && matriz_memoria[contador1][contador2] != 96 && matriz_memoria[contador1][contador2] != 123 && matriz_memoria[contador1][contador2] != 124 && matriz_memoria[contador1][contador2] != 125 && matriz_memoria[contador1][contador2] != 126)
			{ // Procura a nova palavra na string que armazena temporariamente a linha
				flag =1;
				temp[contador4] = matriz_memoria[contador1][contador2];
				contador4++;
				contador2++;
			}
			temp[contador4] = '\0';
			contador5=0;
			if(flag == 1) // Verifica se foi encontrado uma palavra nova
			{	
				if(contador4 > 4) // Verifica se a palavra encontrada é maior que 2 (Senão automaticamente ela não vai estar cadastrada)
				{
					while(contador5 < contador_aless) // Vetor que corre o banco de aless procurando por palavras cadastradas
					{
						if((contador = strcmp(palavra[contador5].nome,temp) == 0)) // Se a palavra do arquivo for igual a do banco substitui pelo aless correspondente
						{
							strcpy(temp,matriz_memoria[contador1]);
							contador6 = strlen(palavra[contador5].nome); // captura o tamanho da palavra
							contador = contador2 - contador6; // Contador temporario recebe a posicao atual na linha do arquivo
							contador3=0; // Contador3 é zerado 
							while(contador3<contador)
							{
								matriz_memoria[contador1][contador3] = temp[contador3];
								contador3++;
							}
							
							// Dados a serem colocados no lugar das palavras
							
							temp[contador3] = 35;
							if(contador5 == 0){temp[contador3+1] = 48;}
							else if(contador5 == 1){temp[contador3+1] = 49;}
							else if(contador5 == 2){temp[contador3+1] = 50;}
							else if(contador5 == 3){temp[contador3+1] = 51;}
							else if(contador5 == 4){temp[contador3+1] = 52;}
							else if(contador5 == 5){temp[contador3+1] = 53;}
							else if(contador5 == 6){temp[contador3+1] = 54;}
							else if(contador5 == 7){temp[contador3+1] = 55;}
							else if(contador5 == 8){temp[contador3+1] = 56;}
							else if(contador5 == 9){temp[contador3+1] = 57;}
							temp[contador3+2] = 32;
							contador3 = contador3+2;
							contador = contador2;
							while(contador3 < tamanho_linha)
							{
								temp[contador3] = matriz_memoria[contador1][contador];
								contador3++;
								contador++;
							}
							temp[contador3] = '\0';
							strcpy(matriz_memoria[contador1],temp);
							
						}
						contador5++;
					}
				}
				flag=0;
			}
			contador2++;
		}
	}
	// Deslocador de linhas de arquivo
	contador1 = contador_aless + linha1;
	contador5 = contador1;
	contador3 = linha1;
	for(contador4=0;contador4<linha1;contador4++)
	{
		strcpy(matriz_memoria[contador1],matriz_memoria[contador3]);
		contador3--;
		contador1--;
	}
	linha1 = contador5;
	
	// Colocador de aless no arquivo
	for(contador=0,contador1=1;contador1<contador_aless;contador1++,contador++)
	{
		strcpy(matriz_memoria[contador1],palavra[contador].nome);
		contador2 = strlen(palavra[contador].nome);
		matriz_memoria[contador1][contador2] = 10;
		matriz_memoria[contador1][contador2+1] = '\0';
	}
	// Colocador de extensao verificador interno no arquivo
	matriz_memoria[0][0] = 's';
	matriz_memoria[0][1] = 'h';
	matriz_memoria[0][2] = 'r';
	if(contador_aless == 0){matriz_memoria[0][3] = 32;}
	if(contador_aless == 1){matriz_memoria[0][3] = 48;}
	if(contador_aless == 2){matriz_memoria[0][3] = 49;}
	if(contador_aless == 3){matriz_memoria[0][3] = 50;}
	if(contador_aless == 4){matriz_memoria[0][3] = 51;}
	if(contador_aless == 5){matriz_memoria[0][3] = 52;}
	if(contador_aless == 6){matriz_memoria[0][3] = 53;}
	if(contador_aless == 7){matriz_memoria[0][3] = 54;}
	if(contador_aless == 8){matriz_memoria[0][3] = 55;}
	if(contador_aless == 9){matriz_memoria[0][3] = 56;}
	if(contador_aless == 10){matriz_memoria[0][3] = 57;}
	matriz_memoria[0][4] = 10;
	// Colocador de extensao de saida no arquivo
	if(tipo_arquivo == 'T'){matriz_memoria[contador_aless][0] = 't';matriz_memoria[contador_aless][1] = 'x';matriz_memoria[contador_aless][2] = 't';matriz_memoria[contador_aless][3] = 10;}
	if(tipo_arquivo == 'C'){matriz_memoria[contador_aless][0] = 'c';matriz_memoria[contador_aless][1] = 'f';matriz_memoria[contador_aless][2] = 'r';matriz_memoria[contador_aless][3] = 10;}
	// Calcula o tamanho do arquivo compactado residente em memoria
	tamanho_arquivo_compactado =0; 
	contador1=0;
	while(contador1<linha1)
	{
		tamanho_arquivo_compactado = tamanho_arquivo_compactado + strlen(matriz_memoria[contador1]);
		contador1++;
	}
	linha = linha1;
	printf("\n\nTamanho Original				: %d caracteres\n",tamanho_arquivo);
	printf("Tamanho do Arquivo Compactado 			: %d caracteres\n",tamanho_arquivo_compactado);
	printf("O percentual de compactacao do arquivo e de 	: %d %%\n",(tamanho_arquivo_compactado*100/tamanho_arquivo));
	return(0);
}
/////////////////////////////////////////////////////////////////////// Funcao que descompacta um arquivo
int descompactar() // Terminar
{
	if(tipo_arquivo == 'T')
	{
		return(1); // Não é possivel descompactar um arquivo(txt) não compactado 
	}
	if(tipo_arquivo == 'C')
	{
		return(2); // Não é possivel descompactar um arquivo (cfr) não compactado
	}
	// Verifica o numero de aless presente no arquivo
	if(matriz_memoria[0][3] == 32){contador=0;}
	if(matriz_memoria[0][3] == 48){contador=1;}
	if(matriz_memoria[0][3] == 49){contador=2;}
	if(matriz_memoria[0][3] == 50){contador=3;}
	if(matriz_memoria[0][3] == 51){contador=4;}
	if(matriz_memoria[0][3] == 52){contador=5;}
	if(matriz_memoria[0][3] == 53){contador=6;}
	if(matriz_memoria[0][3] == 54){contador=7;}
	if(matriz_memoria[0][3] == 55){contador=8;}
	if(matriz_memoria[0][3] == 56){contador=9;}
	if(matriz_memoria[0][3] == 57){contador=10;}
	// Armazena os aless do arquivo no banco de dados residente em memoria
	contador1=1,contador2=0;
	while(contador1<contador)
	{
		strcpy(palavra[contador2].nome,matriz_memoria[contador1]);
		if(contador2 == 0){strcpy(palavra[contador2].aless,"#0");}
		if(contador2 == 1){strcpy(palavra[contador2].aless,"#1");}
		if(contador2 == 2){strcpy(palavra[contador2].aless,"#2");}
		if(contador2 == 3){strcpy(palavra[contador2].aless,"#3");}
		if(contador2 == 4){strcpy(palavra[contador2].aless,"#4");}
		if(contador2 == 5){strcpy(palavra[contador2].aless,"#5");}
		if(contador2 == 6){strcpy(palavra[contador2].aless,"#6");}
		if(contador2 == 7){strcpy(palavra[contador2].aless,"#7");}
		if(contador2 == 8){strcpy(palavra[contador2].aless,"#8");}
		if(contador2 == 9){strcpy(palavra[contador2].aless,"#9");}
		if(contador2 == 10){strcpy(palavra[contador2].aless,"#10");}
		contador1++;
		contador2++;
	}
	// Verifica o tipo de saida do arquivo descompactado
	if(matriz_memoria[contador][0] == 't' && matriz_memoria[contador][1] == 'x' && matriz_memoria[contador][2] == 't')
	{
		tipo_arquivo = 'T';
	}
	if(matriz_memoria[contador][0] == 'c' && matriz_memoria[contador][1] == 'f' && matriz_memoria[contador][2] == 'r')
	{
		tipo_arquivo = 'C';
	}	
	// Por convencão atualiza o contador de aless com o valor de aless do arquivo 
	marcador = contador+1;
	contador_aless = contador-1;
	contador5=1;
	contador6 = linha - marcador;
	// Desloca o arquivo para cima
	while(marcador<linha)
	{
		strcpy(matriz_memoria[contador5],matriz_memoria[marcador]);
		marcador++;
		contador5++;
	}
	// Coloca o tipo do arquivo no arquivo
	if(tipo_arquivo == 'T')
	{
		matriz_memoria[0][0] = 't';
		matriz_memoria[0][1] = 'x';
		matriz_memoria[0][2] = 't';
		matriz_memoria[0][3] = 13;
	}
	if(tipo_arquivo == 'C')
	{
		matriz_memoria[0][0] = 'c';
		matriz_memoria[0][1] = 'f';
		matriz_memoria[0][2] = 'r';
		matriz_memoria[0][3] = 13;
	}
	// Procura pelos aless do arquivo e os substitui para descompactar o arquivo
	contador1=1;
	while(contador1<contador6)
	{
		contador4 = strlen(matriz_memoria[contador1]);
		contador5=0;
		while(contador5<contador4)
		{
			contador3=0; // Armazena o valor depois do aless
			if(matriz_memoria[contador1][contador5] == 35)
			{
				contador2=-1;
				if(matriz_memoria[contador1][contador5+1] == 48){contador2=0;}
				if(matriz_memoria[contador1][contador5+1] == 49){contador2=1;}
				if(matriz_memoria[contador1][contador5+1] == 50){contador2=2;}
				if(matriz_memoria[contador1][contador5+1] == 51){contador2=3;}
				if(matriz_memoria[contador1][contador5+1] == 52){contador2=4;}
				if(matriz_memoria[contador1][contador5+1] == 53){contador2=5;}
				if(matriz_memoria[contador1][contador5+1] == 54){contador2=6;}
				if(matriz_memoria[contador1][contador5+1] == 55){contador2=7;}
				if(matriz_memoria[contador1][contador5+1] == 56){contador2=8;}
				if(matriz_memoria[contador1][contador5+1] == 57){contador2=9;}
				if(matriz_memoria[contador1][contador5+1] == 49 && matriz_memoria[contador1][contador5+2] == 48){contador2=10;}
				if(contador2 != -1)
				{
					//
					contador4=0;
					while(contador4<contador5)
					{
						temp[contador4] = matriz_memoria[contador1][contador4];
						contador4++;
					}
					if(contador2 == 10){contador3 = contador5 + 3;}else{contador3 = contador5 + 2;}
					contador=0;
					while(contador < contador5)
					{
						temp[contador3] = matriz_memoria[contador1][contador3];
						contador3++;
					}
					//
				}
			}
			contador5++;
		}
		contador1++;
	}
	
	linha = contador6;
	return(0);
}
/////////////////////////////////////////////////////////////////////// Funcao que visualiza o arquivo informado
int visualizar() // Ok
{
	printf("\n\nVisualizando o arquivo : %s\n\n\n",nome_arquivo);
	if(tipo_arquivo == 'T' || tipo_arquivo == 'C')
	{
		contador=1;
	}
	else if(tipo_arquivo == 'S')
	{
		contador=0;
		if(matriz_memoria[0][3] != 32)
		{
			if(matriz_memoria[0][3] == 48){contador=3;}
			else if(matriz_memoria[0][3] == 49){contador=4;}
			else if(matriz_memoria[0][3] == 50){contador=5;}
			else if(matriz_memoria[0][3] == 51){contador=6;}
			else if(matriz_memoria[0][3] == 52){contador=7;}
			else if(matriz_memoria[0][3] == 53){contador=8;}
			else if(matriz_memoria[0][3] == 54){contador=9;}
			else if(matriz_memoria[0][3] == 55){contador=10;}
			else if(matriz_memoria[0][3] == 56){contador=11;}
			else if(matriz_memoria[0][3] == 57){contador=12;}
		}
		else
		{
			contador=2;
		}
	}
	while(contador < linha)
	{
		printf("%s",matriz_memoria[contador]);
		contador++;
	}
	printf("\n\n");
	return(0);
}
/////////////////////////////////////////////////////////////////////// Funcao que exibe os dados do arquivo informado
int exibir() // Ok
{
	if(tipo_arquivo == 'T')
	{	
		printf("\nO arquivo informado e do tipo comum(txt) !!\n");
		contador=1;
	}
	if(tipo_arquivo == 'C')
	{
		contador=1;
		printf("\nO arquivo informado e do tipo codificado(cfr) !!\n");
	}
	if(tipo_arquivo == 'S')
	{
		contador=0;
		if(matriz_memoria[0][3] != 32)
		{
			if(matriz_memoria[0][3] == 48){contador=3;}
			else if(matriz_memoria[0][3] == 49){contador=4;}
			else if(matriz_memoria[0][3] == 50){contador=5;}
			else if(matriz_memoria[0][3] == 51){contador=6;}
			else if(matriz_memoria[0][3] == 52){contador=7;}
			else if(matriz_memoria[0][3] == 53){contador=8;}
			else if(matriz_memoria[0][3] == 54){contador=9;}
			else if(matriz_memoria[0][3] == 55){contador=10;}
			else if(matriz_memoria[0][3] == 56){contador=11;}
			else if(matriz_memoria[0][3] == 57){contador=12;}
		}
		else
		{
			contador=2;
		}
		printf("\nO arquivo informado e do tipo compactado(shr) !!\n");
	}
	tamanho_arquivo = 0;
	while(contador < linha)
	{
		tamanho_arquivo = tamanho_arquivo + strlen(matriz_memoria[contador]);
		contador++;
	}
	printf("\nO tamanho do arquivo informado e de %d caracteres !! \n\n",tamanho_arquivo);
	return(0);
}
