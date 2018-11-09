#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../include/header.hpp"

void get_chave(Registro* reg){
	/* funcao faz a chave juntando matricula com o primeiro nome */
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
}

void escreve_arquivo(FILE* arq, Registro* reg){
	/* Escreve o arquivo com formatacao */
	fprintf(arq, "%s %-40s %d  %-8s %c \n", reg->matric,reg->nome,reg->op,reg->curso,reg->turma);
}
void ler_linha_arquivo(FILE* arq, Registro *reg){
	char aux[70], a;
	/* Se o primeiro caracter for um * */
    long posicaoInicial = ftell(arq);
    a = fgetc(arq);
    if(a == '*') {
        strcpy(reg->matric, "-1");
        fscanf(arq, "%[^\n]s", aux);
        fgetc(arq);
        if(!feof(arq))
            ler_linha_arquivo(arq, reg);
    }
    fseek(arq, posicaoInicial, SEEK_SET);
	/* Captura a matricula */
	fscanf(arq, "%s", reg->matric);
    fgetc(arq); /* Pegar o espaço que sobra */

    /* Captura o nome  */
    fscanf(arq, "%[^0-9]s", reg->nome);

	/* Captura o OP */
	fscanf(arq, "%[0-9]s", aux);
	reg->op = atoi(aux);
  	fscanf(arq, "%[^A-Z]s", aux); /* Pegar o espaço que sobra */
  	
  	/* Captura o Curso  */
  	fscanf(arq, "%[A-Z]s", reg->curso);
  	fscanf(arq, "%[^A-Z]s", aux); /* Pegar o espaço que sobra */
  	
  	/* Captura a turma */
  	reg->turma = fgetc(arq);
  	/* Definindo a chave */
  	get_chave(reg);
  	fgetc(arq);
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
			if (strcmp(reg1.chave,reg2.chave) < 0) {
				escreve_arquivo(arqmerge, &reg1);
				ler_linha_arquivo(arq1, &reg1);
			} else {
				if (strcmp(reg1.chave,reg2.chave) > 0) {
					escreve_arquivo(arqmerge, &reg2);
					ler_linha_arquivo(arq2, &reg2);
				} else {
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