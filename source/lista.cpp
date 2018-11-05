#include <lista.h>
#include <stdlib.h>
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

Lista* lista_insere(Lista* lis, char curso[8],int referencia){
    Lista* novo= (Lista*) malloc(sizeof(Lista));
    strcpy(novo->curso, curso);
    novo->prox=lis;
    novo->ref = referencia;
    return novo;
}
int lista_altera(Lista* lis, char curso[8], int novaref){
    Lista* aux = lis;
    int ref = -1;
    while(aux != NULL){
        if(strcmp(aux->curso, curso) == 0 ){
            ref = aux->ref;
            aux->ref = novaref;
        }
        aux = aux->prox;
    }
    return ref;
}


int is_in_lista(Lista* lis, char curso[8]){
    /* Se a lista estiver vazia */
    if(lista_is_empty(lis)){
        return 0;
    }
    Lista* aux = lis;
    while(aux != NULL){
        if(strcmp(aux->curso, curso) == 0){
            return 1;
        }
        aux = aux->prox;
    }
    return 0;
}

void imprime_lista(Lista* lis,FILE* arq){
    Lista* aux = lis;
    int tam = lista_tam(lis);
    char vetor[8][tam], aux1[8];
    int j,k,ref[tam], aux2;
    /* Preenchendo os vetores com informacao da lista para ordenar*/
    for(int i=0;i < tam; i++){
        strcpy(vetor[i], aux->curso);
        ref[i] = aux->ref;
        aux = aux->prox;
    }
    for(j = 1; j < tam; j++){
        for (k = 0; k < tam -1; k++){
            if(strcmp(vetor[k],vetor[k+1]) > 0){
                //Ordenando as chaves
                strcpy(aux1,vetor[k]);
                strcpy(vetor[k],vetor[k+1]);
                strcpy(vetor[k+1],aux1);

                // Ordenando as referências
                aux2 = ref[k];
                ref[k] = ref[k+1];
                ref[k+1] = aux2;
            }
        }
    }
    for(int i=0;i < tam; i++){
        fprintf(arq, "%-8s %d\n",vetor[i], ref[i]);
    }
}

int lista_tam(Lista* lis){
    Lista* aux = lis;
    int cont = 0;
    while(aux!= NULL){
        cont ++;
        aux = aux->prox;
    }
    return cont;
}
void free_lista(Lista* lis){
    Lista* p = lis;
    while(p != NULL){
        Lista* t = p->prox;
        free(p);
        p = t;
    }
}