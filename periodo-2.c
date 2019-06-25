// Mihael Scofield de Azevedo - 20182621

#include "lcrandom.h"
#include <stdio.h>

int main(void){
	int i;
	unsigned long neo, rd, periodo;

	lcrandom_parms (1103515245, 12345, 1073741824); // inicializa gerador de acordo com enunciado
	lcrandom_seed (0);

	i = 0;
	neo = 0;
	rd = 0;
	periodo = 0;

	/* Escolhendo um numero no meio do periodo */
	for (i = 0; i < 1103414134; i += 1){
		lcrandom(); // Apenas caminho pelos meus numeros, e paro em algum aleatorio.
	}
	neo = lcrandom(); // Temos o escolhido.

	/* Comparacao dos demais numeros com o escolhido */
	i = 0; // Reseto meu auxilio.
	while (i == 0){ // Enquanto nao encontrar.
		rd = lcrandom();
		if (neo == rd){ // A verdadeira comparacao.
			i = 1; // Encontrou.
			printf("O periodo eh: %ld\n", periodo);
		}
		else{
			periodo += 1;
		}
	}
}