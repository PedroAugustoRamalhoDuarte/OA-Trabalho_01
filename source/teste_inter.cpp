#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"
#include "../include/header.hpp"

char string1[30] = "lista1.txt";
char string2[30] = "lista2.txt";

TEST_CASE("merge"){
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