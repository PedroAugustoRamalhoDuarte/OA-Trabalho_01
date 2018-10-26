#define CATCH_CONFIG_MAIN
#include "../include/catch.hpp"
#include "../include/header.hpp"

TEST_CASE("merge"){
	static string1 = "lista1.txt"
	static string2 = "lista2.txt"
	REQUIRE(merge(string1, string2))
}