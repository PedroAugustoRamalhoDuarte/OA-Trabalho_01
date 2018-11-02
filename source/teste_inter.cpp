#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"
#include "../include/header.hpp"
#include "../include/lista.h"

char string1[30] = "lista1.txt";
char string2[30] = "lista2.txt";

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
	cursos = lista_insere(cursos, cursoec);
	REQUIRE(verifica_curso_novo(cursos, cursoec) == 0);
	REQUIRE(verifica_curso_novo(cursos, cursocc) == 1);

}