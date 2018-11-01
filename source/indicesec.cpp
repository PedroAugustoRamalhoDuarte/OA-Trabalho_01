/*
*
*
*
*
*
*
*
*
*/

void lista_invertida(const char* nomearq){
	FILE* arq = fopen(arq, "r");
	/* Arquivo com numero de 0 a 9 */
	char nomeinv[30] = "listainv ";
	for (int i = 0; i < 30; ++i) {
		if ('0' <= nomearq[i] <= '9') {
			/* Coloca o numero do arquivo invertido */
			nomeinv[8] = nomearq[i];
			break;
		}
	} 
	FILE* arqinv = fopen(arq, "w+");
	
}