#ifndef TRABALHO_01_LISTA_H
#define TRABALHO_01_LISTA_H


typedef struct lista{
    //Definicao da Lista
    char curso[8];
    struct lista *prox;
}Lista;

Lista* lista_cria();

int lista_is_empty(Lista* lis);

Lista* lista_insere(Lista* lis, char curso[8]);

int is_in_lista(Lista* lis, char curso[8]);

void free_lista(Lista* lis);

#endif //TRABALHO_01_LISTA_H
