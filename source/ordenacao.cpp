#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <../include/header.hpp>


/* Se flag != -1, ordena crescrente
* Se flag == -1 ordena descrecente*/
Registro* bubble_sort(Registro* reg, int flag, int tam){
    Registro aux;
    int j, k;
    for(j = 1; j < tam; j++){
        for (k = 0; k < tam - 1; k++){
            if(flag != - 1){
                /* Ordem Crescente */
                if(strcmp(reg[k].chave,reg[k+1].chave) > 0){
                    //Ordenando as chaves
                    aux = reg[k];
                    reg[k] = reg[k + 1];
                    reg[k + 1] = aux;
                }
            }else{
                /* Ordena Decrescente */
                if(strcmp(reg[k].chave,reg[k+1].chave) < 0){
                    //Ordenando as chaves
                    aux = reg[k];
                    reg[k] = reg[k + 1];
                    reg[k + 1] = aux;
                }
            }
        }
    }
}

void ordena_arquivo(FILE* arq, int flag){
	int tam = calcularRegistroArquivo(arq);
	Registro *reg;
	reg = bubble_sort(reg, flag, tam);
	for(int i = 0; i < tam; i++){
		escreve_arquivo(arq, &reg[i]);
	}
	fclose(arq);
}
