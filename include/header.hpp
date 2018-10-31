#ifndef HEADER_H
#define HEADER_H
#include <string>

typedef struct registro{
	char* nome;
	char turma;
	char curso;
	int op;
	char* matric;
	int chave;
	char* info;
}Registro;

int merge(char*  arquivo1, char*  arquivo2);

void ler_linha_arquivo(FILE* arq, Registro* reg);

void escreve_arquivo(FILE* arq, Registro* reg);
#endif // HEADER_H