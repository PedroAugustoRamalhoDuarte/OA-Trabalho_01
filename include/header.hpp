#ifndef HEADER_H
#define HEADER_H
#include <string>

class Registro{
	public:
		char* nome;
		char turma;
		char curso;
		int op;
		int matric;
		int chave;
};

int merge(char*  arquivo1, char*  arquivo2);

void Ler_lista(FILE* arq, Registro reg);

void escreve_arquivo(FILE* arq, Registro reg);
#endif // HEADER_H