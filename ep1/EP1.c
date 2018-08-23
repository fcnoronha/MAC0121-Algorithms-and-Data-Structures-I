#include <stdio.h>
#include <stdlib.h>

long long int collatz (long long int n, long long int *P){

	/*  Funçao que faz uso de recursao e momorizaçao para calcular o numero de 
		passos para um numero n tender a 1 na conjectura de Collatz, retorando 
		este valor.																*/

	// Calcula de maneira interativa caso o numero seja maior que 10000000, no 
	// caso, maior que o numero de posiçoes que podem ser armazenado na memoria.
	long long int r = 0;
	while(n >= 1000000){
		if (n%2 == 0) n = n/2; 
		else n = n*3 + 1;
		r++;
	}

	// Uso da momerizaçao e base da recursao.
	if (P[n] != 0 || n == 1) return P[n];

	// Calculo recursivo do numero de passos, sendo que a posiçao n da array passos
	// armazena o numero de passos necessarios para o elemento n tender a 1. 
	if (n%2 == 0) P[n] = collatz(n/2, P) + 1 + r;
	else P[n] = collatz(3*n + 1, P) + 1 + r;

	return P[n];
}

int main(){	
	// Variavel usada para armazenar resultados de calculos anteriores
	long long int *passos;
	passos = malloc(1000000 * sizeof(long long int));

	// Recebendo intervalo no qual sera calculada a conjectura.
	long long int ini, fim;
	scanf("%Li%Li", &ini, &fim);

	// Definindo base de resultados.
	passos[1] = 0;
	passos[0] = 1;

	// Imprimindo o resultado para cada elemento do intervalo.
	for (long long int n = ini; n <= fim; n++){
		printf("%Li\n", collatz(n, passos));
	}

	// Liberando memoria 
	free(passos);

	return 0;
}