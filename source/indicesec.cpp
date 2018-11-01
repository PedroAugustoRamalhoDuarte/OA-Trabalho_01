#include<list>
#include<stdio.h>
#include "../include/header.hpp"

void lista_invertida(const char* nomearq){
	FILE* arq = fopen(nomearq, "r");
	/* Arquivo com numero de 0 a 9 */
	char nomeinv[30] = "listainv ";
	for (int i = 0; i < 30; ++i) {
		if ('0' <= nomearq[i] <= '9') {
			/* Coloca o numero do arquivo invertido */
			nomeinv[8] = nomearq[i];
			break;
		}
	} 
	FILE* arqinv = fopen(nomeinv, "w+");
	Registro reg;
	while(!feof(arq)){/* Enquanto houver registros */
		ler_linha_arquivo(arq, &reg);
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