#include<stdio.h>

int main(){
	char op;
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

			break;

			/* Remover */	
			case 2:
			break;

			/* Visualizar */
			case 3:
			break;

			/* Condição de saida*/
			case 9:
			printf("Finalizado");
			return 0;

		}
	}
}