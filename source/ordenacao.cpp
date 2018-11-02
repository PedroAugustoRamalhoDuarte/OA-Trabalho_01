#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "intercalacao.cpp"


void ordena_indice_primario(FILE *arq){
	char aux[30], indice[30];
	int i =0, j, k, w, aux2;
	Registro reg[100];
	while (!feof(arq)){
		/* Captura o indice primario */
		fscanf(arq, "%s", indice); // Lê o indice primário
		strcpy(reg[i].chave, indice); // Atribui o indice primário à um vetor de struct
		fscanf(arq, "%s", aux); // Pega a referência
		reg[i].ref = atoi(aux);
	    printf("%s\t", reg[i].chave);
	    printf("%d\n", reg[i].ref);
	    fgetc(arq); /* Pegar o espaço que sobra */
	    i++;

	}
	for(j = 1; j < i; j++){
        for (k = 0; k < i-1; k++){
            if(strcmp(reg[k].chave,reg[k+1].chave) > 0){
            		//Ordenando as chaves
                	strcpy(aux,reg[k].chave);
                 	strcpy(reg[k].chave,reg[k+1].chave);
                 	strcpy(reg[k+1].chave,aux);

                 	// Ordenando as referências
                 	aux2 = reg[k].ref;
                 	reg[k].ref = reg[k+1].ref;
                 	reg[k+1].ref = aux2;
                 }                               
           	}      
        }
    printf("\nOrdenado\n");
    for(w = 0; w < i; w++){
    	printf("%s\t", reg[w].chave);
	    printf("%d\n", reg[w].ref);

    }
}
int main(){
	FILE *arq1 = fopen("testeordenacao.txt", "r");
	ordena_indice_primario(arq1);


}
