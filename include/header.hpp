#ifndef HEADER_H
#define HEADER_H

class Registro{
	string nome;
	char turma;
	char curso;
	int op;
	int matric;
}

int merge(string arquivo1, string arquivo2);

void Ler_lista(FILE* arq, Registro reg);

void escreve_arquivo(FILE* arq, Registro reg);
#endif // HEADER_H