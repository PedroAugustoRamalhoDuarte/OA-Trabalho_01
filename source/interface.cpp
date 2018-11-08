#include<stdio.h>
#include<../include/header.hpp>
#include<ctype.h>
#include <stdlib.h>
#include <string.h>
<<<<<<< HEAD
void visualizar(){
    int arq,i=0;
    FILE* arquivo;
    system("clear");
    printf("Visualisar:\n");
    while(1){
        printf("Escolha qual arquivo deseja-se visualizar:\n1 - Arquivo1\n2 - Arquivo2\n3 - Merge\n");
        scanf("%d", &arq);
        if (arq == 1){
            arquivo = fopen("lista1.txt", "r");
            break;
        }
        else if(arq == 2){
            arquivo = fopen("lista2.txt", "r");
            break;
        }else if(arq == 3){
            arquivo = fopen("lista12.txt", "r");
            break;
        }
    }
    Registro reg;
    int contador = 0;
    long max_reg = calcularRegistroArquivo(arquivo);
    while(!feof(arquivo)){
        ler_linha_arquivo(arquivo, &reg);
        printf("%s %-40s %d  %-8s %c \n", reg.matric,reg.nome,reg.op,reg.curso,reg.turma);
        contador ++;
        if(max_reg == contador){
            break;
        }
    }
    getc(stdin);/* esperar o cara digitar */
}

=======
>>>>>>> parent of 9ffaae0... Alterar brabissimo
void incluir(){
	int arq;
	FILE* arquivo;
	char nomearquivo[20];
	system("clear");
	printf("Inclusao:\n");
	while(1){
		printf("Escolha em qual arquivo deseja incluir:\n1 - Arquivo1\n2 - Arquivo2\n");
		scanf("%d", &arq);
		if (arq == 1){
		    strcpy(nomearquivo, "lista1.txt");
			arquivo = fopen("lista1.txt", "w");
			break;
		}
		else if(arq == 2){
            strcpy(nomearquivo, "lista2.txt");
			arquivo = fopen("lista2.txt", "w");
			break;
		}
	}
	/* Captura a informacao do registro */
    Registro reg;
    reg = get_matricula(reg, arquivo);
	reg = get_nome(reg);
	reg = get_op(reg);
    reg = get_turma(reg);
    reg = get_curso(reg);
    printf("%s %-40s %d  %-8s %c \n", reg.matric,reg.nome,reg.op,reg.curso,reg.turma);
	fclose(arquivo);
	/* Insere o registro na lista */
	insere_registro(nomearquivo, &reg);
}

Registro get_nome(Registro reg){
    printf("Digite o nome do aluno: ");
    setbuf(stdin, 0);
    scanf("%[^\n]s", reg.nome);
    fflush(stdin);
    printf("%s\n", reg.nome);
    return reg;
}

Registro get_matricula(Registro reg, FILE* arq){
    int cont=6;
    char aux;
    printf("Digite a matricula do aluno: ");
    // Garantindo que a matricula contenha somente números
    do {
        if (cont != 6){
            printf("Valor invalido, digite uma matricula de 6 numeros: ");
        }
        setbuf(stdin, 0);
        scanf("%[^\n]s", reg.matric);
        fflush(stdin);
        //fgets(reg.matric, 7, stdin);
        while(isalpha(reg.matric[0]) || isalpha(reg.matric[1]) || isalpha(reg.matric[2]) || isalpha(reg.matric[3]) ||
              isalpha(reg.matric[4]) || isalpha(reg.matric[5])) {
            printf("Valor invalido, digite apenas numeros: ");
            scanf("%s", reg.matric);
        }
        cont = strlen(reg.matric);

    } while(cont != 6);

    printf("%s\n", reg.matric);
    return reg;
}

Registro get_curso(Registro reg){
    strcpy(reg.curso,"WC");
    do {
        if (!isupper(reg.curso[0]) || !isupper(reg.curso[1])){
            printf("O curso deve conter todas as letras maiusculas! Digite novamente: ");
        }
        printf("Digite o curso: ");
        setbuf(stdin, 0);
        scanf("%c%c", &reg.curso[0],&reg.curso[1]);
        fflush(stdin);
    } while(!isupper(reg.curso[0]) || !isupper(reg.curso[1]));
    printf("%s\n", reg.curso);
    return reg;
}

Registro get_op(Registro reg){
    printf("Digite a OP:");
    setbuf(stdin, 0);
    scanf("%d", &reg.op);
    printf("%d\n", reg.op);
    return reg;
}

Registro get_turma(Registro reg){
    strcpy(&reg.turma,"P");
    do {
        printf("Digite a turma: ");
        setbuf(stdin, 0);
        scanf("%c", &reg.turma);
        if (islower(reg.turma)){
            printf("A letra da turma deve ser em letra maiuscula! Digite novamente: ");
        }
    } while(islower(reg.turma));
    printf("%c\n", reg.turma);
    return reg;

}
void alterar(){
    int op = -1;
    do{
        printf("Voce deseja alterar o arquivo com:\n0 - mudanca de chave primaria\n 1 - sem mudanca de chave primaria");
        scanf("%d", &op);
    }while (op == 0 || op == 1);
    switch (op){
        case 0:
            /* Com mudanca de chave primaria */
            return;
        case 1:
            /* Sem mudanca de chave primaria */
            return;
        default:
            printf("ERRO\n");
            return;
    }
}

void excluir(){
    system("clear");
    int arq;
    char nomearquivo[20];
    //Escolhe de qual arquivo o usuario deseja remover
    while(1){
        printf("Escolha em qual arquivo deseja excluir:\n1 - Arquivo1\n2 - Arquivo2\n");
        scanf("%d", &arq);
        if (arq == 1){
            strcpy(nomearquivo,"lista1.txt");
            break;
        }
        else if(arq == 2){
            strcpy(nomearquivo,"lista2.txt");
            break;
        }
    }

    int matricula, ref = -1;
    FILE* arquivo = fopen(nomearquivo, "r");
    //Analisa a matricula de entrada
    do{
        system("clear");
        printf("Digite a matricula do aluno:");
        scanf("%d", &matricula);
        ref = existe_matricula(matricula, arquivo);
    }while(verifica_matricula(matricula) && ref != -1);
    fclose(arquivo);

    // excluir_registro(nomearquivo, matricula);

}

/* ***********************************************************************
 * Função Existe_matricula
 *
 * Entrada:
 *  -matricula: matricula na qual va ser pesquisada
 *  -arq: ponteiro do arquivo no qual sera pesquisado se esxiste a matricula
 * Retorno:
 *  -referencia: Se existir retorna o endereço
 *  - -1: Se nao encontrou
 *
 ***************************************************************************/
long existe_matricula(int matricula, FILE* arq){
    Registro reg;
    long posicaoAtual = ftell(arq);
    long cont = 0;
    while(!feof(arq)){
        ler_linha_arquivo(arq, &reg);
        if(atoi(reg.matric) == matricula){
            return cont * TAM_REG;
        }
        cont++;
    }
    fseek(arq, posicaoAtual, SEEK_SET); /* Volta o ponteiro do arquivo para onde estava */
    return -1;
}

/***********************************************
 * Função Exclui Registro
 * @details A função atribui um * para o registro no arquivo principal.
 * @param nomearquivo: Nome do arquivo ter conehcimento de qual lista retirar
 * @param matricula: Matricula do qual sera retirado
 * @param ref: referencia do aluno no arquivo principal
 *
 * @return void
 */
void excluir_registro(char nomearquivo[20], int matricula, long ref){
    FILE* arq = fopen(nomearquivo, "r+");
    Registro reg;
    /* Excluindo no arquivo principal */
    fseek(arq, ref, SEEK_SET);
    //ler_linha_arquivo(arq, &reg);/* Captura informação do registro para usar depois */
    //fseek(arq, ref, SEEK_SET);
    char remove[2] = "*";
    fprintf(arq,"%-62s\n", remove);


    fclose(arq);
}

int verifica_matricula(int matricula){

}

void insere_registro(char nomearq[20],Registro* reg) {
    FILE* arq = fopen(nomearq, "r+");
    Registro aux;
    long posicaoAtual;
    char c; /* Guarda o primeiro termo da linha */
    /* Percorre  ate achar um asterisco */
    while(!feof(arq)){
        posicaoAtual = ftell(arq);
        c = fgetc(arq);/* Captura o primeiro char da linha */
        printf("%c", c);
        ler_linha_arquivo(arq, &aux);
        if( c == '*'){ /* Se encontrar o asterisco */
            fseek(arq, posicaoAtual, SEEK_SET);
            escreve_arquivo(arq, reg);/* Escreve o registro */
            break;
        }
    }
    escreve_arquivo(arq, reg);/* Se não achar um *, escreve no final */
<<<<<<< HEAD
}

Registro get_nome(Registro reg){
    printf("Digite o nome do aluno: ");
    setbuf(stdin, 0);
    scanf("%[^\n]s", reg.nome);
    fflush(stdin);
    printf("%s\n", reg.nome);
    return reg;
}

Registro get_matricula(Registro reg, FILE* arq){
    int cont=6;
    char aux;
    printf("Digite a matricula do aluno: ");
    // Garantindo que a matricula contenha somente números
    do {
        if (cont != 6){
            printf("Valor invalido, digite uma matricula de 6 numeros: ");
        }
        setbuf(stdin, 0);
        scanf("%[^\n]s", reg.matric);
        fflush(stdin);
        //fgets(reg.matric, 7, stdin);
        while(isalpha(reg.matric[0]) || isalpha(reg.matric[1]) || isalpha(reg.matric[2]) || isalpha(reg.matric[3]) ||
              isalpha(reg.matric[4]) || isalpha(reg.matric[5])) {
            printf("Valor invalido, digite apenas numeros: ");
            scanf("%s", reg.matric);
        }
        cont = strlen(reg.matric);

    } while(cont != 6);

    printf("%s\n", reg.matric);
    return reg;
}

Registro get_curso(Registro reg){
    strcpy(reg.curso,"WC");
    do {
        if (!isupper(reg.curso[0]) || !isupper(reg.curso[1])){
            printf("O curso deve conter todas as letras maiusculas! Digite novamente: ");
        }
        printf("Digite o curso: ");
        setbuf(stdin, 0);
        scanf("%s", reg.curso);
        fflush(stdin);
    } while(!isupper(reg.curso[0]) || !isupper(reg.curso[1]));
    printf("%s\n", reg.curso);
    return reg;
}

Registro get_op(Registro reg){
    printf("Digite a OP:");
    setbuf(stdin, 0);
    scanf("%d", &reg.op);
    printf("%d\n", reg.op);
    return reg;
}

Registro get_turma(Registro reg){
    strcpy(&reg.turma,"P");
    do {
        printf("Digite a turma: ");
        setbuf(stdin, 0);
        scanf("%s", &reg.turma);
        if (islower(reg.turma)){
            printf("A letra da turma deve ser em letra maiuscula! Digite novamente: ");
        }
    } while(islower(reg.turma));
    printf("%c\n", reg.turma);
    return reg;

}

Registro entrada_alterar(Registro reg){
    int opcao;
    /* Nome */
    printf("Deseja alterar o nome?\n1 - Sim\n0 - Nao\n");
    scanf("%d", &opcao);
    if(opcao == 1)
        reg = get_nome(reg);

    /* OP */
    printf("Deseja alterar a op?\n1 - Sim\n0 - Nao\n");
    scanf("%d", &opcao);
    if(opcao == 1)
        reg = get_op(reg);

    /* Curso*/
    printf("Deseja alterar o Curso ?\n1 - Sim\n0 - Nao\n");
    scanf("%d", &opcao);
    if(opcao == 1)
        reg = get_curso(reg);

    /* Turma  */
    printf("Deseja alterar a turma?\n1 - Sim\n0 - Nao\n");
    scanf("%d", &opcao);
    if(opcao == 1)
        reg = get_turma(reg);
    return reg;
=======
>>>>>>> parent of 9ffaae0... Alterar brabissimo
}