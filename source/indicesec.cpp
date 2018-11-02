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
	/* Lista para auxiliar no indice secundario */
	Lista* liscurso; /* Armazena o curso e sua referencia */
	liscurso = lista_cria();
	Registro reg;
	int cont = 0, referencia;
	while(!feof(arq)){/* Enquanto houver registros */
		printf("%d\n", cont);
		ler_linha_arquivo(arq, &reg);
		/* Se o curso for diferente dos outros ja registrados*/
		if(verifica_curso_novo(liscurso, reg.curso)){
			liscurso = lista_insere(liscurso, reg.curso, cont);
			escreve_listainvertidaP(arqinv, reg); /* Escreve no arquivo de indice invertido */
		}else{
			referencia = lista_altera(liscurso, reg.curso, cont);
			escreve_listainvertida(arqinv, reg, referencia);
		}
		cont ++;
	}
	imprime_lista(liscurso, arqsec);
	free_lista(liscurso);
	fclose(arq);
	fclose(arqinv);
	fclose(arqsec);
}

long calcularRegistroArquivo(FILE* arquivo){
	long posicaoAtual = ftell(arquivo);
	long tamanho;
	fseek(arquivo, 0, SEEK_END);
	tamanho = ftell(arquivo);
	fseek(arquivo, posicaoAtual, SEEK_SET);
	return tamanho/TAM_REG;
}