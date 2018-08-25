#include <stdio.h>
#include <stdlib.h>

// Variavel global que ira ser a memoria.
long long int *passos;

int collatz (long long int n){

	/*  Funçao que faz uso de recursao e momorizaçao para calcular o numero de 
		passos para um numero n tender a 1 na conjectura de Collatz, retorando 
		este valor.																*/

	// Base da recursao.
	if (n == 1) return passos[n];

	// Uso da momerizaçao.
	if (n < 1000000	) if (passos[n] != -1) return (passos[n]);

	// Calculo recursivo do numero de passos.
	int p;
	if (n%2 == 0) p = collatz(n/2) + 1;
	else p = collatz(n*3 + 1) + 1;

	// Caso seja possivel, memoriza o numero de passos.
	if (n < 1000000) passos[n] = p;  

	return p;
}

int main(){	
	// Definindo um limite de 1000003 para a array de memorizaçao.
	passos = malloc(1000003 * sizeof(long long int));

	// Inicializando valores na array.
	for (long long int i = 0; i < 1000003; i++) passos[i] = -1;

	// Recebendo intervalo no qual sera calculada a conjectura.
	long long int ini, fim;
	scanf("%Li%Li", &ini, &fim);

	// Definindo base.
	passos[1] = 0;

	// Imprimindo o resultado para cada elemento do intervalo.
	for (long long int n = ini; n <= fim; n++){
		printf("%d\n", collatz(n));
	}

	// Liberando memoria 
	free(passos);

	return 0;
}