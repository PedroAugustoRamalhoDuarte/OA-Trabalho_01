#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../include/header.hpp"
void get_chave(Registro* reg){
	char* aux = (char*) malloc(sizeof(char) * 30);
	int i;
	for(i = 0; i < 7; i++){
		aux[i] = reg->matric[i];
	}
	for(i = 6; i < 30; i++){
		if(reg->nome[i-6] == ' ')
			break;
		aux[i] = reg->nome[i-6];
	};
	aux[i] = '\0';
	strcpy(reg->chave, aux);
	printf("%s", reg->chave);
}
void escreve_arquivo(FILE* arq, Registro* reg){
	/* Formatar Melhor */
	fprintf(arq, "%s %s %d %s %c \n", reg->matric,reg->nome,reg->op,reg->curso,reg->turma);
}
void ler_linha_arquivo(FILE* arq, Registro *reg){
	char aux[30];

	/* Captura a matricula */
	fscanf(arq, "%s", reg->matric);
    printf("%s\n", reg->matric);
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
  	get_chave(reg);
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
			printf("Comparacao:%s , %s \n", reg1.chave,reg2.chave);
			if (strcmp(reg1.chave,reg2.chave) < 0) {
				printf("1 Menor\n");
				escreve_arquivo(arqmerge, &reg1);
				ler_linha_arquivo(arq1, &reg1);
			} else {
				if (strcmp(reg1.chave,reg2.chave) > 0) {
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