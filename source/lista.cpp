#include <lista.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Lista* lista_cria(){
    return NULL;
}

int lista_is_empty(Lista* lis){
    if(lis == NULL){
        return 1;
    }else{
        return 0;
    }
}

Lista* lista_insere(Lista* lis, char curso[8]){
    Lista* novo= (Lista*) malloc(sizeof(Lista));
    strcpy(novo->curso, curso);
    novo->prox=lis;
    return novo;
}

int is_in_lista(Lista* lis, char curso[8]){
    /* Se a lista estiver vazia */
    if(lista_is_empty(lis)){
        return 0;
    }
    Lista* aux = lis;
    while(aux != NULL){
        if(strcmp(lis->curso, curso) == 0){
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

void free_lista(Lista* lis){
    Lista* p = lis;
    while(p != NULL){
        Lista* t = p->prox;
        free(p);
        p = t;
    }
}