#include<stdio.h>
#include<stdlib.h>
#include<string>
#include "intercalacao.cpp"

int  printa_indice_invertido(FILE* arqindice, Registro reg, int ref){
	int i=0, num;
	fprintf(arqindice, "%d%d",0,reg.matric);
	// Pega o nome até encontrar um espaço
	while (reg.nome[i] != ' '){
		fprintf(arqindice, "%c", reg.nome[i] );
		i++;
	}
	// Definindo quantos espaços em branco devemos inserir para completar 30 caracteres
	if (ref < 10) num = 28;
	if (ref > 10 && ref < 99) num = 27;
	if (ref > 99) num = 26;

	// Inserindo espaços em branco para completar 30 caracteres
	while((i+6) < num){
		fprintf(arqindice, " ");
		i++;
	}
	if (ref < 10)
	fprintf(arqindice, " %d\n", ref-1 ); // Iniciando no indice 0
	else
	fprintf(arqindice, " %d\n", ref ); 
	
	// Aumentando a referência de acordo com os registros de 30 bits
	ref +=62;
	return ref;	
}

void cria_indice_primario(FILE *arq, const char* nomelista){
	FILE *arqindice = fopen(nomelista, "w+");
	Registro reg;
	int ref = 1;
	while(!feof(arq)){
		ler_linha_arquivo(arq, &reg);
		// Referencia criada para somar a quantidade de bits das linhas
		ref = printa_indice_invertido(arqindice, reg, ref);
	}
}


/*------------------------------------------TESTE--------------------------------------------------*/
int main(){
	FILE *arq1 = fopen("lista1.txt", "r");
	FILE *arq2 = fopen("lista2.txt", "r");
	cria_indice_primario(arq1, "indicelista1.ind");
	cria_indice_primario(arq2, "indicelista2.ind");

}