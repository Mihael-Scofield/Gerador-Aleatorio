// Mihael Scofield de Azevedo - 20182621

#include "lcrandom.h"

// declara as variáveis com escopo de visibilidade somente NESTE arquivo
static unsigned long a, c, m, x;

// calcula e devolve um valor pseudoaleatório
unsigned long lcrandom (){
   x = (((a * x) + c) % (int)m);
   return x; // Retorna valor do LCG
}

// define o valor inicial (semente) da sequência de aleatórios
// zero (0) por default
void lcrandom_seed (unsigned long s){
   x = s;
}

// informa o valor máximo que pode ser gerado (o mínimo é sempre zero)
unsigned long lcrandom_max (){
	m = (5);
	return m;
}

// modifica os parâmetros da equação do gerador; por default
// devem ser usados: A=40692, C=127 e M=10000000
void lcrandom_parms (unsigned long A, unsigned long C, unsigned long M){
	a = A; // Para se adaptar as diversas chamadas.
	c = C;
	m = M;
}