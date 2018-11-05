#ifndef TRABALHO_01_LISTA_H
#define TRABALHO_01_LISTA_H

#include <stdio.h>

typedef struct lista{
    //Definicao da Lista
    char curso[8];
    int ref;
    struct lista *prox;
}Lista;
/* Cria uma lista vazia */
Lista* lista_cria();

/* Verifica se a lista esta vazia
 *
 * Retorna:
 * 1 - Se estiver vazia
 * 0 - Se nâo estiver vazia
 * */
int lista_is_empty(Lista* lis);

/* Insere na lista um curso novo */
Lista* lista_insere(Lista* lis, char curso[8], int ref);

/*  Altera a referencia do curso */
int lista_altera(Lista* lis,char curso[8], int novaref);

/* verifica se existe o curso ja na lista */
int is_in_lista(Lista* lis, char curso[8]);

/* Imprime a lista no arquivo de secundary key */
void imprime_lista(Lista* lis,FILE* arq);

/* retorna o tamanho da lista */
int lista_tam(Lista* lis);

/* libera o espaço de memoria da lista */
void free_lista(Lista* lis);

#endif //TRABALHO_01_LISTA_H
