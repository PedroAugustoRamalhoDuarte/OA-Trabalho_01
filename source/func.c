#include<stdio.h>
#include<header.hpp>
#include<ctype.h>

void incluir(){
	int arq;
	system("clear");
	printf("Inclusao:");
	while(1){
		printf("Escolha em qual arquivo deseja incluir:\n\t1 - Arquivo1\n\t2 - Arquivo2");
		scanf("%d", &arq);
		if (arq == 1){
			FILE* arquivo = fopen("lista1.txt", "w");
			break;
		}
		else if(arq == 2){
			FILE* arquivo = fopen("lista2.txt", "w");
			break;
		}
	}
    int aux = 6, cont=0, i=0;
    Registro reg;
    char aux2[6];


    printf("Digite o nome do aluno: ");
    fflush(stdin);
    fgets(reg.nome, sizeof(reg.nome), stdin);
    printf("%s", reg.nome);
    /*for(i=0; i< strlen(reg.nome); i++){
        reg.nome = toupper(reg.nome);
        if(!isupper(reg.nome)){
            printf("Valor invalido, para o nome digite apenas letras: ");
            fflush(stdin);
            fgets(reg.nome, sizeof(reg.nome), stdin);

        }
    }*/
    /*while(reg.nome[i] != '\0'){

        if(!isalpha(reg.nome[0])){
            printf("Valor invalido, digite apenas letras: ");
            fflush(stdin);
            fgets(reg.nome, sizeof(reg.nome), stdin);

        }
        if(!isalpha(reg.nome[i])){
            printf("Valor invalido, digite apenas letras: ");
            fflush(stdin);
            fgets(reg.nome, sizeof(reg.nome), stdin);
            i=0;
        }
        printf("%c\n", reg.nome[i]);
        i++;
    }
    printf("%s", reg.nome);
    i = 0;*/

    printf("Digite a matricula do aluno: ");
    // Garantindo que a matricula contenha somente números
    do {
        if (aux != 6){
            printf("Valor invalido, digite uma matricula de 6 numeros: ");
        }
        scanf(" %s", aux2);
        while(isalpha(aux2[0]) || isalpha(aux2[1]) || isalpha(aux2[2]) || isalpha(aux2[3]) || isalpha(aux2[4]) || isalpha(aux2[5])) {
            printf("Valor invalido, digite apenas numeros: ");
            scanf(" %s", aux2);
        }
        reg.matric = atoi(aux2);
        aux = reg.matric;
        cont = 0;
        // Garantindo que a matricula só tenha 6 números
        while (aux != 0){
            cont++;
            aux /= 10;
        }

    } while(cont != 6);

    printf("%d\n", reg.matric);
    strcpy(reg.curso,"WC");
    do {
        if (!isupper(reg.curso[0]) || !isupper(reg.curso[1])){
            printf("O curso deve conter todas as letras maiusculas! Digite novamente: ");
        }
        printf("Digite o curso: ");
        scanf(" %s", reg.curso);
    } while(!isupper(reg.curso[0]) || !isupper(reg.curso[1]));
    printf("%s\n", reg.curso);

    strcpy(&reg.turma,"P");
    do {
        printf("Digite a turma: ");
        scanf(" %c", &reg.turma);
        if (islower(reg.turma)){
            printf("A letra da turma deve ser em letra maiuscula! Digite novamente: ");
        }
    } while(islower(reg.turma));
    printf("%c\n", reg.turma);

    return reg;
}