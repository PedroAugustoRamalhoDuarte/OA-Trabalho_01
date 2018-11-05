#ifndef HEADER_H
#define HEADER_H


#define TAM_REG 63


#include "lista.h"

typedef struct registro{
	char nome[50];
	char turma;
	char curso[8];
	int op;
	char matric[7];
	char chave[30];
}Registro;
/* Funções universais */
void ler_linha_arquivo(FILE* arq, Registro* reg);

/* Interface */
void visualizar();

void incluir();

void excluir();

void alterar();

int verifica_matricula(int matricula);

void excluir_registro(char nomearquivo[20], int matricula, long ref);

int verifica_nome(char nome[50]);

long existe_matricula(int matricula, FILE* arq);

void insere_registro(char nomearq[20],Registro* reg);

Registro get_nome(Registro reg);

Registro get_matricula(Registro reg, FILE* arquivo);

Registro get_curso(Registro reg);

Registro get_op(Registro reg);

Registro get_turma(Registro reg);

Registro entrada_alterar(Registro reg);
int is_num(char numero[10], int max_len);
/* Arquivo Secundario */
int verifica_curso_novo(Lista* liscurso, char curso[8]);

void escreve_listainvertidaP(FILE* arqinv, Registro reg);

void escreve_listainvertida(FILE* arqinv, Registro reg, int referencia);

void gera_lista_invertida(const char* nomearq);

long calcularRegistroArquivo(FILE* arquivo);

/* Arquivo Primario */
int  printa_indice_invertido(FILE* arqindice, Registro reg, int ref);

void cria_indice_primario(FILE *arq, const char* nomelista);

/* Merge */
void get_chave(Registro* reg);

int merge(char*  arquivo1, char*  arquivo2);

void escreve_arquivo(FILE* arq, Registro* reg);

#endif // HEADER_H