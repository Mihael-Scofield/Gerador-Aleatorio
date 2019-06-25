// Mihael Scofield de Azevedo - 20182621

#include "lcrandom.h"
#include <stdio.h>
#define NUM 100

unsigned long enc_maior (unsigned long v[]){
	int aux = v[0];
	for (int i = 1; i < NUM; i++){ // Verificacao do maior.
		if (aux < v[i])
			aux = (v[i]); 
	}
	return aux;
}

int main(void){
	int i, j;
	unsigned long vet[NUM], maior, bla;

	lcrandom_parms(40692, 127, 10000000); // inicializa gerador de acordo com enunciado
	lcrandom_seed(0);
	
	for (i = 0; i < NUM; i++) // Zerando vetor de contagem dos valores.
		vet[i] = 0;
	for (i = 0; i < 1000000; i++){
		bla = lcrandom(); 
		vet[ ( (int)bla ) % 100]++; // Ja normalizo os numeros.	
	}

	// Busco maior para ter escala na impressão. 
	maior = (enc_maior(vet));

	// Gera historgrama
	printf ("   0   10    20   30   40   50   60   70   80   90   100\n"); // Cabeçalho.
	printf ("   +----+----+----+----+----+----+----+----+----+----+\n");
	for (i = 0; i < NUM; i++){ // Impressão fixa.
		printf ("%2d |", i);
		for (j = 0; j < (((vet[i]*100)/maior) / 2); j++){ // Regra de 3 para saber quantos '*' imprimir, em relacão com maior.
			printf ("*");
		}
		printf ("\n");
	}
	printf ("   +----+----+----+----+----+----+----+----+----+----+\n");
	return 0;
}