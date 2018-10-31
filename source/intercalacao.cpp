#include<stdio.h>
#include<stdlib.h>
#include<string>
#include "../include/header.hpp"

void escreve_arquivo(FILE* arq, Registro* reg){
	//Escrever Registro
	fprintf(arq, "%s\n", reg->info);
}
void ler_linha_arquivo(FILE* arq, Registro *reg){
	char* linha = reinterpret_cast<char*> (malloc(sizeof(char ) * 120));
	int i;
	char aux[6];
	fscanf(arq, "%[^\n]s", linha); /* Pega uma linhas do arquivo */
    fgetc(arq); /* Pegar o \n que sobra */
    printf("%s\n", linha);
  	for(i = 0; i < 6; i++){
  		aux[i] = linha[i];
  	}
  	reg->chave = atoi(aux);
  	reg->info = linha;
	// Pegar o Registro e a chave
}

int merge(char*  arquivo1, char*  arquivo2){
	FILE *arq1 = fopen(arquivo1, "r");
	FILE *arq2 = fopen(arquivo2, "r");
	FILE *arqmerge = fopen("lista12.txt", "w+");
	if (arq1 != NULL && arq2 != NULL) { /* Se os dois arquivos forem validos */
		Registro reg1,reg2;
		ler_linha_arquivo(arq1, &reg1);
		ler_linha_arquivo(arq2, &reg2);
		while (!feof(arq1) && !feof(arq2)) { /* Enquanto houver registros*/
			/* Se acabar algum dos 2
			if(feof(arq1)){
				while(!feof(arq2)){
					escreve_arquivo(arqmerge, &reg2);
					ler_linha_arquivo(arq2, &reg2);
				}
			}else{
				while(!feof(arq1)){
					escreve_arquivo(arqmerge, &reg1);
					ler_linha_arquivo(arq1, &reg1);
				}
			}*/
			/* Se os dois arquivos estiverem */
			printf("Comparacao:%d , %d \n", reg1.chave,reg2.chave);
			if (reg1.chave < reg2.chave) {
				printf("1 Menor\n");
				escreve_arquivo(arqmerge, &reg1);
				ler_linha_arquivo(arq1, &reg1);
			} else {
				if (reg2.chave < reg1.chave) {
					printf("2 Menor\n");
					escreve_arquivo(arqmerge, &reg2);
					ler_linha_arquivo(arq2, &reg2);
				} else {
					printf("Igual\n");
					escreve_arquivo(arqmerge, &reg1);
					ler_linha_arquivo(arq1, &reg1);
					ler_linha_arquivo(arq2, &reg2);
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