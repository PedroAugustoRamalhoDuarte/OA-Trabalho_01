cmake_minimum_required(VERSION 3.12)
project(Trabalho_01)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)
include_directories(lib)
include_directories(source)

add_executable(Trabalho_01
        include/catch.hpp
        include/header.hpp
        lib/lista1.txt
        lib/lista2.txt
        source/obj/indicesec.o
        source/obj/intercalacao.o
        source/obj/teste_inter.o
        source/func.c
        source/indicesec.cpp
        source/intercalacao.cpp
        source/lista1.txt
        source/lista12.txt
        source/lista2.txt
        source/main.c
        source/makefile
        source/teste_inter.cpp
        instrucao.txt
        README.md
        separacao.txt
        trabalho-oa-1_2018-2.pdf include/lista.h source/lista.cpp)
