#include<stdio.h>
#include "../include/header.hpp"
#include"../include/lista.h"
#include <string.h>
#include <stdlib.h>

int verifica_curso_novo (Lista* liscurso, char curso[8]){
	if(is_in_lista(liscurso, curso)){
		return 0;
	}else {
		return 1;
	}
}

void escreve_seckey(FILE* arqsec, Registro reg, int cont){
	long posicaoAtual = ftell(arqsec);
    fseek(arqsec, 0, SEEK_END);
    printf("escreve chave sec %s\n", reg.curso);
    fprintf(arqsec, "%-8s %d\n", reg.curso, cont);
	fseek(arqsec, posicaoAtual, SEEK_SET); /* Volta o ponteiro do arquivo para onde estava */
}

void escreve_listainvertidaP(FILE* arqinv, Registro reg){
	long posicaoAtual = ftell(arqinv);
	fseek(arqinv, 0, SEEK_END);
	fprintf(arqinv, "%-30s %d\n", reg.chave, -1);
	fseek(arqinv, posicaoAtual, SEEK_SET); /* Volta o ponteiro do arquivo para onde estava */
}

void escreve_listainvertida(FILE* arqinv, Registro reg, int referencia){
	long posicaoAtual = ftell(arqinv);
	fseek(arqinv, 0, SEEK_END);
	fprintf(arqinv, "%-30s %d\n", reg.chave, referencia);
	fseek(arqinv, posicaoAtual, SEEK_SET); /* Volta o ponteiro do arquivo para onde estava */
}

int muda_seckey(FILE* arqsec, Registro reg, int cont){
	long posicaoAtual = ftell(arqsec);
	char curso[8], aux[30], referencia[5];
	while(!feof(arqsec)){
		long posicaoAux = ftell(arqsec);/* Posicao da linha */
		fscanf(arqsec, "%s[A-Z]", curso);
		if (strcmp(curso, reg.curso) == 0) {
			fscanf(arqsec, "%[^0-9]s",aux); /* Pegar os espacos (fonte de erro)*/
			fscanf(arqsec, "%[^\n]s" , referencia);
			fseek(arqsec, posicaoAux, SEEK_SET);/* Volta para o comeco da linha */
			fprintf(arqsec, "%-8s %d\n", reg.curso, cont);
			break;
		}
	}
	fseek(arqsec, posicaoAtual, SEEK_SET);
	return atoi(referencia);
}


void gera_lista_invertida(const char* nomearq){
	FILE* arq = fopen(nomearq, "r");

	/* Arquivo com numero de 0 a 9 */
	char nomeinv[30] = "listainv .txt";
	char nomesec[30] = "secundarykey .txt";
	/* Definindo nome dos arquivos de saida */
	for (int i = 0; i < 30; ++i) {
		if ('0' <= nomearq[i]  && nomearq[i] <= '9') {
			/* Coloca o numero do arquivo invertido */
			nomeinv[8] = nomearq[i];
			nomesec[12] = nomearq[i];
			break;
		}
	}
	FILE* arqinv = fopen(nomeinv, "w+");
	FILE* arqsec = fopen(nomesec, "w+");
	Lista* liscurso;
	liscurso = lista_cria();
	Registro reg;
	int cont = 0, referencia;
	while(!feof(arq)){/* Enquanto houver registros */
		printf("%d\n", cont);
		ler_linha_arquivo(arq, &reg);
		/* Se o curso for diferente dos outros ja registrados*/
		if(verifica_curso_novo(liscurso, reg.curso)){
			liscurso = lista_insere(liscurso, reg.curso);
			escreve_seckey(arqsec, reg, cont); /* Escreve no arquivo da chave secundaria */
			escreve_listainvertidaP(arqinv, reg); /* Escreve no arquivo de indice invertido */
		}else{
			referencia = muda_seckey(arqsec, reg, cont);
			escreve_listainvertida(arqinv, reg, referencia);
		}
		cont ++;
	}
}

long calcularRegistroArquivo(FILE* arquivo){
	long posicaoAtual = ftell(arquivo);
	long tamanho;
	fseek(arquivo, 0, SEEK_END);
	tamanho = ftell(arquivo);
	fseek(arquivo, posicaoAtual, SEEK_SET);
	return tamanho/TAM_REG;
}