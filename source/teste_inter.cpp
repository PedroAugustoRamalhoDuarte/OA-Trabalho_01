#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"
#include "../include/header.hpp"

TEST_CASE("merge"){
	char* string1 = "lista1.txt";
	char* string2 = "lista2.txt";
	REQUIRE(merge(string1, string2));
}