#include<stdio.h>
#include<stdlib.h>
#include<string>
#include "../include/header.hpp"

void escreve_arquivo(FILE* arq, Registro* reg){
	//Escrever Registro
	/* Formatar Melhor */
	fprintf(arq, "%d %s %d %s %c \n", reg->matric,reg->nome,reg->op,reg->curso,reg->turma);
}
void ler_linha_arquivo(FILE* arq, Registro *reg){
	char aux[30];

	/* Captura a matricula */
	fscanf(arq, "%s", aux);
    reg->matric = atoi(aux);
    printf("%d\n", reg->matric);
    fgetc(arq); /* Pegar o espaço que sobra */

    /* Captura o nome  */
    fscanf(arq, "%[^0-9]s", reg->nome);
    printf("%s\n", reg->nome);

	/* Captura o OP */
	fscanf(arq, "%[0-9]s", aux);
	reg->op = atoi(aux);
	printf("%d\n", reg->op);
  	fscanf(arq, "%[^A-Z]s", aux); /* Pegar o espaço que sobra */
  	
  	/* Captura o Curso  */
  	fscanf(arq, "%[A-Z]s", reg->curso);
  	printf("%s\n", reg->curso);
  	fscanf(arq, "%[^A-Z]s", aux); /* Pegar o espaço que sobra */
  	
  	/* Captura a turma */
  	reg->turma = fgetc(arq);
  	printf("%c\n", reg->turma);

  	/* Definindo a chave */
  	reg->chave = reg->matric;
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