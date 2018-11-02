#include<stdio.h>
#include "../include/header.hpp"
#include"../include/lista.h"
#include <string.h>

int verifica_curso_novo (Lista* liscurso, char curso[8]){
	if(is_in_lista(liscurso, curso)){
		return 0;
	}else {
		return 1;
	}

}

void escreve_seckey(FILE* arqsec, Registro reg, int cont){
    fseek(arqsec, 0, SEEK_END);
    fprintf(arqsec, "%8s %d", reg.curso, cont);
}

void escreve_listainvertida(FILE* arqinv, Registro reg){

}

void muda_seckey(FILE* arqsec, Registro reg){

}


void lista_invertida(const char* nomearq){
	FILE* arq = fopen(nomearq, "r");

	/* Arquivo com numero de 0 a 9 */
	char nomeinv[30] = "listainv ";
	char nomesec[30] = "secundarykey ";
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
	int cont = 0;
	while(!feof(arq)){/* Enquanto houver registros */
		ler_linha_arquivo(arq, &reg);
		/* Se o curso for diferente dos outros ja registrados*/
		if(verifica_curso_novo(liscurso, reg.curso)){
			liscurso = lista_insere(liscurso, reg.curso);
			escreve_seckey(arqsec, reg, cont); /* Escreve no arquivo da chave secundaria */
			escreve_listainvertida(arqinv, reg); /* Escreve no arquivo de indice invertido */
		}else{
			muda_seckey(arqsec, reg);
			escreve_listainvertida(arqinv, reg);
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