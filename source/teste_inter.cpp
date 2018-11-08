#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"
#include "../include/header.hpp"
#include "../include/lista.h"

char string1[30] = "lista1.txt";
char string2[30] = "lista2.txt";
/*TEST_CASE("get_chave"){
	Registro reg;
	strcpy(reg.nome, "Pedro Augusto Ramalho");
	strcpy(reg.matric, "024312");
	get_chave(&reg);
	REQUIRE(strcmp(reg.chave, "024312Pedro") == 0 );

}
TEST_CASE("Merge"){
	REQUIRE(merge(string1, string2));
}
TEST_CASE("Calcula Registro Arquivo"){
	FILE* arq = fopen(string1, "r");
	REQUIRE(calcularRegistroArquivo(arq) == 19);
	fclose(arq);
	FILE* arq1 = fopen(string2, "r");
	REQUIRE(calcularRegistroArquivo(arq1) == 22);
	fclose(arq1);
}

TEST_CASE("Verifica_curso_novo"){
	Lista* cursos;
	cursos = lista_cria();
	char cursoec[8] = "EC";
	char cursocc[8] = "CC";
	REQUIRE(verifica_curso_novo(cursos, cursoec) == 1);
	cursos = lista_insere(cursos, cursoec, 0);
	REQUIRE(verifica_curso_novo(cursos, cursoec) == 0);
	REQUIRE(verifica_curso_novo(cursos, cursocc) == 1);

}

TEST_CASE("Gera lista invertida "){
    gera_lista_invertida(string1);
    gera_lista_invertida(string2);
}

TEST_CASE("Gera indiceprimario"){
    FILE* arq = fopen(string1, "r");
    FILE* arq1 = fopen(string2, "r");
    cria_indice_primario(arq, "indicelista1.ind");
    cria_indice_primario(arq1, "indicelista2.ind");
    fclose(arq);
}

TEST_CASE("Existe registro"){
    int matricula = 24312;
    int matriculafalsa = 012211;
    FILE* arq = fopen(string1, "r");
    REQUIRE(existe_matricula(matricula, arq) == 0);
    REQUIRE(existe_matricula(matriculafalsa, arq) == -1);
    fclose(arq);
}*/

TEST_CASE("Inserir Registro"){
	Registro reg;
	strcpy(reg.matric, "071231");
	strcpy(reg.nome, "Pedro Augusto");
	strcpy(reg.curso, "EC");
	reg.op = 32;
	reg.turma = 'A';

	insere_registro(string1, &reg);
}
/*
TEST_CASE("Excluir Registro"){
    excluir_registro(string1, 024312, 0);
}*/
/*TEST_CASE("Interface inserir"){
	incluir();
}*/
