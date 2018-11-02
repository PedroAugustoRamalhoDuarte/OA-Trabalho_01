#ifndef HEADER_H
#define HEADER_H


#define TAM_REG 63

#include "lista.h"

typedef struct registro{
	char nome[50];
	char turma;
	char curso[8];
	int op;
	int matric;
	int chave;
	char* info;
}Registro;

/* Arquivo Secundario */
int verifica_curso_novo(Lista* liscurso, char curso[8]);

void escreve_seckey(FILE* arqsec, Registro reg, int cont);

void escreve_listainvertida(FILE* arqinv, Registro reg);

void muda_seckey(FILE* arqsec, Registro reg);

void lista_invertida(const char* nomearq);

long calcularRegistroArquivo(FILE* arquivo);

/* Merge */
int merge(char*  arquivo1, char*  arquivo2);

void ler_linha_arquivo(FILE* arq, Registro* reg);

void escreve_arquivo(FILE* arq, Registro* reg);

#endif // HEADER_H