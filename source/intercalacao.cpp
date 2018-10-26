#include<stdio.h>
#include<stdlib.h>
#include<string>
#include "../include/header.hpp"

void escreve_arquivo(FILE* arq, Registro reg){
	//Escrever Registro
}
void Ler_lista(FILE* arq, Registro reg){
	char* linha = reinterpret_cast<char*> (malloc(sizeof(char ) * 120));
	fscanf(arq, "%[^\n]s", linha); /* Pega uma linhas do arquivo */
    fgetc(arq); /* Pegar o \n que sobra */
	// Pegar o Registro e a chave
}

int merge(char*  arquivo1, char*  arquivo2){
	FILE *arq1 = fopen(arquivo1, "r");
	FILE *arq2 = fopen(arquivo2, "r");
	FILE *arqmerge = fopen("lista12.txt", "w+");
	if (arq1 != NULL && arq2 != NULL) { /* Se os dois arquivos forem validos */
		Registro reg1,reg2;
		Ler_lista(arq1, reg1);
		Ler_lista(arq2, reg2);
		while (!feof(arq1) && !feof(arq2)) { /* Enquanto houver registros*/
			if (reg1.chave < reg2.chave) {
				escreve_arquivo(arqmerge, reg1);
				Ler_lista(arq1, reg1);
			} else {
				if (reg2.chave < reg1.chave) {
					escreve_arquivo(arqmerge, reg2);
					Ler_lista(arq2, reg2);
				} else {
					escreve_arquivo(arqmerge, reg1);
					Ler_lista(arq1, reg1);
					Ler_lista(arq2, reg2);
				}
			}
		} 
		fclose(arq1);
		fclose(arq2);
		fclose(arqmerge);
		return 1; /* Exito */
	}else {
		return 0; /* Erro */
	}
}