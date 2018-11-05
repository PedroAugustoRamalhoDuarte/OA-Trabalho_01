#include<stdio.h>
#include "../include/header.hpp"
int main(){
	char op;
	/* Gera as o indice primario */
    FILE *arq1 = fopen("lista1.txt", "r");
    FILE *arq2 = fopen("lista2.txt", "r");
    cria_indice_primario(arq1, "indicelista1.ind");
    cria_indice_primario(arq2, "indicelista2.ind");

    /* Gera os indices secundarios */
	gera_lista_invertida("lista1.txt");
	gera_lista_invertida("lista2.txt");
	fclose(arq1);
	fclose(arq2);

	while(1){
		printf("Digite a opção que deseja realizar:\n");
		printf("\t0 - Incluir\n\t1 - Atualizar\n\t2 - Remover\n\t3 - Visualizar\n\t9 - Sair");
		scanf("%c", &op);
		switch(op){
			/* Incluir */
			case 0:
				incluir();
				break;
			/* Atualizar */
			case 1:
				alterar();
				break;

			/* Remover */	
			case 2:
				excluir();
				break;

			/* Visualizar */
			case 3:
				break;

			/* Condição de saida*/
			case 9:
				/* Arrumar as parada */
				printf("Finalizado\n");
				return 0;

			default:
				printf("Digite um numero valido\n");
				break;

		}
	}
}