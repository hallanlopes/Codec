/*
- Descricão fonte : Interface do Codificador/Decodificador + Compactador/Descompactador 
- Disciplina      : Seguranca e Auditoria de Sistemas 
- Professor       : Mr.Oberdan Rolim 
- Aluno 	      : Raffael Bottoli Schemmer 
- Data Termino    : 24/08/2008 
*/

#include<stdio.h>  /* printf scanf fopen feof fgets sscanf fprintf */
#include<stdlib.h> /* system atoi itoa */
#include <string.h> /* strcpy strcmp strlen strcat */
#include "Codec.h" 
#define TAM 30

///////////////////////////////////////////////////////////////////////// Declaracao de Variaveis
int opcao,retorno,chave;
///////////////////////////////////////////////////////////////////////// Declaracão de Variaveis do tipo Char
char nome_arquivo[TAM];
///////////////////////////////////////////////////////////////////////// Funcao Main(Interface)
int main()
{
	do // Menu de entrada do usuario
	{
		printf("\t|| -------------------------- || -- Codec -- || -------------------------- ||\n\n\n\n");
		printf("\t\t\t      (1) Codificar um arquivo\n\n");
		printf("\t\t\t      (2) Decodificar um arquivo\n\n");
		printf("\t\t\t      (3) Compactar um arquivo\n\n");
		printf("\t\t\t      (4) Descompactar um arquivo\n\n");
		printf("\t\t\t      (5) Codificar e compactar um arquivo\n\n");
		printf("\t\t\t      (6) Descompactar e decodificar um arquivo\n\n");
		printf("\t\t\t      (7) Visualizar um arquivo\n\n");
		printf("\t\t\t      (8) Exibir as propriedades de um arquivo\n\n");
		printf("\t\t\t      (9) Sair do programa\n\n\n\n\n\t\t\t\t\t\t");
		printf("\t\t\t      Opcao [ ]\b\b");
		scanf("%d",&opcao);
		fflush(stdin);
		if(opcao == 9){break;}
		if(opcao < 1 || opcao > 9) // Verificação de entrada do usuario
		{
			printf("\n\nOpcao invalida, digite um valor pertencente ao menu acima !!\n\n");
			system("pause");
			system("cls");
			continue;
		}	
		
		le_nome_entrada(nome_arquivo); // Chama nome de entrada que captura a entrada do nome do arquivo
		if((retorno = abrir_arquivo(nome_arquivo)) == 0)
		{
			if((retorno = carregar_arquivo_para_memoria()) == 0)
			{
				switch(opcao) // Seleciona uma determinada funcionalidade de acordo com a entrada do usuario
				{
					case(1): // Ok // Codificar um arquivo 
					{
						chave = le_valor_chave(chave); // Chama a funcao le_valor_chave que efetua a leitura da chave informada pelo usuario retornando seu valor para a variavel chave
						if((retorno = codificar(chave)) == 0) // Chama a funcao codifica que recebe como parametro o valor da chave para codificar o arquivo e retorna para retorno seu estado atual
						{
							if((retorno = carregar_arquivo_para_disco('1')) == 0) // Chama a funcao carrega arquivo para o disco que carrega o arquivo atual codificado residente em memoria para o disco do computador 
							{
								reportar_retornos(retorno,3,1); // Informa a sequencia(retorno,3,1) caso o case(1) execute até este ponto do codigo na opcao 1(codificar arquivo)
								break;
							}
							reportar_retornos(retorno,2,1); // Informa a sequencia(retorno,2,1) caso acontecer algum erro com o carregamento do arquivo para o disco do arquivo na opcao 1(codificar arquivo)
							break;
						}
						reportar_retornos(retorno,1,1); // Informa a sequencia(retorno,1,1) caso acontecer algum erro com a codificacão do arquivo na opcao 1(codificar arquivo)
						break;
					}
					case(2): // Ok // Decodificar um arquivo
					{
						chave = le_valor_chave(chave); // Chama a funcao le_valor_chave que efetua a leitura da chave informada pelo usuario retornando seu valor para a variavel chave
						if((retorno = decodificar(chave)) == 0) // Chama a funcao decodifica que recebe como parametro o valor da chave para decodificar o arquivo e retorna para retorno seu estado atual
						{
							if((retorno = carregar_arquivo_para_disco('2')) == 0) // Chama a funcao carrega arquivo para o disco que carrega o arquivo atual codificado residente em memoria para o disco do computador 
							{
								reportar_retornos(retorno,3,2); // Informa a sequencia(retorno,3,2) caso o case(2) execute até este ponto do codigo na opcao 2(decodificar arquivo)
								break;
							}
							reportar_retornos(retorno,2,2);	// Informa a sequencia(retorno,2,2) caso acontecer algum erro com o carregamento do arquivo para o disco do arquivo na opcao 2(decodificar arquivo)
							break;
						}
						reportar_retornos(retorno,1,2);	// Informa a sequencia(retorno,1,2) caso acontecer algum erro com a decodificacao do arquivo na opcao 2(decodificar arquivo)
						break;
					}
					case(3): // Ok // Compactar um arquivo
					{
						if((retorno = compactar()) == 0) // Chama a funcao compactar que compacta o arquivo e retorna para retorno seu estado atual
						{
							if((retorno = carregar_arquivo_para_disco('3')) == 0) // Chama a funcao carrega arquivo para o disco que carrega o arquivo atual compactado residente em memoria para o disco do computador 
							{
								reportar_retornos(retorno,3,3); // Informa a sequencia(retorno,3,3) caso o case(3) execute até este ponto do codigo na opcao 3(compactar arquivo)
								break;
							}
							reportar_retornos(retorno,2,3); // Informa a sequencia(retorno,2,3) caso acontecer algum erro com o carregamento do arquivo para o disco do arquivo na opcao 3(compactar arquivo)
							break;
						}
						reportar_retornos(retorno,1,3); // Informa a sequencia(retorno,1,3) caso acontecer algum erro com a compactacao do arquivo na opcao 3(compactar arquivo)
						break;
					}
					case(4): // Ok // Descompactar um arquivo
					{
						if((retorno = descompactar()) == 0) // Chama a funcao descompactar que descompacta o arquivo e retorna para retorno seu estado atual
						{ 
							if((retorno = carregar_arquivo_para_disco('4')) == 0) // Chama a funcao carrega arquivo para o disco que carrega o arquivo atual descompactado residente em memoria para o disco do computador 
							{
								reportar_retornos(retorno,3,4); // Informa a sequencia(retorno,3,4) caso o case(4) execute até este ponto do codigo na opcao 4(descompactar arquivo)
								break;
							}	
							reportar_retornos(retorno,2,4); // Informa a sequencia(retorno,2,4) caso acontecer algum erro com o carregamento do arquivo para o disco do arquivo na opcao 4(descompactar arquivo)
							break;
						}	
						reportar_retornos(retorno,1,4); // Informa a sequencia(retorno,1,4) caso acontecer algum erro com a descompactacao do arquivo na opcao 4(descompactar arquivo)
						break;
					}	
					case(5): // Ok // Codificar e Compactar um arquivo
					{
						chave = le_valor_chave(chave); // Chama a funcao le_valor_chave que efetua a leitura da chave informada pelo usuario retornando seu valor para a variavel chave
						if((retorno = codificar(chave)) == 0) // Chama a funcao codifica que recebe como parametro o valor da chave para codificar o arquivo e retorna para retorno seu estado atual
						{
							if((retorno = compactar()) == 0) // Chama a funcao compactar que compacta o arquivo e retorna para retorno seu estado atual
							{
								if((retorno = carregar_arquivo_para_disco('3')) == 0) // Chama a funcao carrega arquivo para o disco que carrega o arquivo atual codificado e compactado residente em memoria para o disco do computador 
								{
									reportar_retornos(retorno,4,5); // Informa a sequencia(retorno,4,5) caso o case(5) execute até este ponto do codigo na opcao 5(codificar e compactar arquivo)
									break;
								}
								reportar_retornos(retorno,3,5); // Informa a sequencia(retorno,3,5) caso acontecer algum erro com o carregamento do arquivo para o disco do arquivo na opcao 5(codificar e compactar arquivo)
								break;
							}	
							reportar_retornos(retorno,2,5); // Informa a sequencia(retorno,2,5) caso acontecer algum erro com a compactacao do arquivo na opcao 5(codificar e compactar arquivo)
							break;
						}	
						reportar_retornos(retorno,1,5); // Informa a sequencia(retorno,1,5) caso acontecer algum erro com a codificacao do arquivo na opcao 5(codificar e compactar arquivo)
						break;
					}	
					case(6): // Ok // Descompactar e Decodificar um arquivo
					{
						if((retorno = descompactar()) == 0) // Chama a funcao descompactar que descompacta o arquivo e retorna para retorno seu estado atual
						{
							chave = le_valor_chave(chave); // Chama a funcao le_valor_chave que efetua a leitura da chave informada pelo usuario retornando seu valor para a variavel chave
							if((retorno = decodificar(chave)) == 0) // Chama a funcao decodifica que recebe como parametro o valor da chave para decodificar o arquivo e retorna para retorno seu estado atual
							{
								if((retorno = carregar_arquivo_para_disco('2')) == 0) // Chama a funcao carrega arquivo para o disco que carrega o arquivo atual descompactado e decodificado residente em memoria para o disco do computador 
								{
									reportar_retornos(retorno,4,6); // Informa a sequencia(retorno,4,6) caso o case(6) execute até este ponto do codigo na opcao 6(descompactar e decodificar um arquivo)
									break;
								}
								reportar_retornos(retorno,3,6); // Informa a sequencia(retorno,3,6) caso acontecer algum erro com o carregamento do arquivo para o disco do arquivo na opcao 6(descompactar e decodificar um arquivo)
								break;
							}
							reportar_retornos(retorno,2,6); // Informa a sequencia(retorno,2,6) caso acontecer algum erro com a decodificacao do arquivo na opcao 6(descompactar e decodificar um arquivo)
							break;
						}
						reportar_retornos(retorno,1,6); // Informa a sequencia(retorno,1,6) caso acontecer algum erro com a descompactacao do arquivo na opcao 6(descompactar e decodificar um arquivo)
						break;
					}
					case(7): // Ok // Visualizar um arquivo
					{
						if((retorno = visualizar()) == 0) // Chama a funcao visualizar que mostra o arquivo fonte residente em memoria arquivo e retorna para retorno seu estado atual
						{
							reportar_retornos(retorno,2,7); // Informa a sequencia(retorno,2,7) caso o case(7) execute até este ponto do codigo na opcao 7(visualizar arquivo)
							break;
						}	
						reportar_retornos(retorno,1,7); // Informa a sequencia(retorno,1,7) caso acontecer algum erro com a visualizacão do arquivo na opcao 7(visualizar arquivo)
						break;
					}	
					case(8): // Ok // Exibir as propriedades de um arquivo
					{	
						if((retorno = exibir()) == 0)// Chama a funcao exibir que mostra as propriedades o arquivo fonte residente em memoria arquivo e retorna para retorno seu estado atual
						{
							reportar_retornos(retorno,2,8); // Informa a sequencia(retorno,2,8) caso o case(8) execute até este ponto do codigo na opcao 8(exibir propriedades do arquivo)
							break;
						}
						reportar_retornos(retorno,1,8); // Informa a sequencia(retorno,1,8) caso acontecer algum erro com a exibicao das propriedades do arquivo na opcao 8(exibir propriedades do arquivo)
						break;
					}						
				}
			}
			else
			{
				reportar_retornos(retorno,2,0); // Informa a sequencia(retorno,2,0) caso acontecer algum erro com o carregamento do arquivo para a memoria
				continue;
			}
		}
		else
		{
			reportar_retornos(retorno,1,0); // Informa a sequencia(retorno,1,0) caso acontecer algum erro com o abrir arquivo
			continue;
		}
	}while(opcao!= 9); // Condicão de termino do programa
	return(0);
}

