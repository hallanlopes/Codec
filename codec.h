/*
- Descricão fonte : Arquivo de cabeçalho do Codificador/Decodificador + Compactador/Descompactador (Codec) - Codec.h
- Disciplina      : Seguranca e Auditoria de Sistemas (8 Semestre)
- Professor       : Mr.Oberdan Rolim 
- Aluno 	        : Raffael Bottoli Schemmer 
- Data Termino    : 24/08/2008 

Copyright (C) 2015, Schemmer, B. Raffael;
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef Codec_h /* Definicão dos prototipos do Codec */
#define Codec_h

int le_valor_chave(int); 			     		        /* Lê o valor da chave informado pelo usuario */
void reportar_retornos(int,int,int);         /* Reporta os valores retornados pelas funcoes de acordo com as entradas efetuadas pelo usuario */
void le_nome_entrada(char *);			          /* Lê o nome do arquivo informado pelo usuario */
int abrir_arquivo(char []);				         /* Realiza a abertura do nome do arquivo informado no computador */
int visualizar();						              /* Mostra o arquivo solicitado residente na memoria do computador */
int exibir();						                 /* Mostra as propriedades de um arquivo solicitado pelo usuario */
int carregar_arquivo_para_memoria();    /* Carrega o arquivo residente em disco para a memoria do computador */
int carregar_arquivo_para_disco(char); /* Carrega o arquivo residente na memoria do computador para o disco */
int codificar(int);					          /* Codifica um arquivo residente em memoria de acordo com uma chave informada pelo usuario */
int decodificar(int);				         /* Decodifica um arquivo residente em memoria de acordo com uma chave informada pelo usuario */
int compactar();		            	  /* Compacta um arquivo informado pelo usuario carregado e residente na memoria do computador */
int descompactar();				         /* Desompacta um arquivo informado pelo usuario carregado e residente na memoria do computador */

#endif

