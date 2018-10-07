#include<stdio.h>
#include<stdlib.h>

int elementoMaximal(int *v, int c, int n){
	
	// Retorna o indice do elemento maximal encontrado a partir de um começo 'c'
	int max = c;
	for (; c < n; c++)
		if (v[c] > v[max])
			max = c;

	return max;
}

void felipe(int *v, int c, int n){
	// Funçao que flipa a lista a partir de um indice

	printf("%d ", c);

	int aux;
	n--; // Para ajustar
	// Fazendo swapping de elementos
	while (c < n){
		aux = v[c];
		v[c] = v[n];
		v[n] = aux;
		c++; n--;
	}
}

int main(){

	int n, *d, i;
	// Recebendo o numero de elementos do vetor a ser ordenado
	scanf("%d", &n);

	d = malloc(n * sizeof(int));

	// Recebendo elementos do vetor
	for (i = 0; i < n; i++)
		scanf("%d", &d[i]);

	// Iterando em cada elemento do vetor, a fim de realizar a ordenaçao
	for (i = 0; i < n; i++){

		// Pegando o elemento maximal a partir da minha posiçao no vetor
		int maximal = elementoMaximal(d, i, n);

		// Se o elemento maximal for o atual, pulo para a proxima posiçao
		if (maximal == i) continue;

		// Caso o elemento maximal ja nao seja o ultimo, flipo o vetor naquele ponto
		if (maximal != n-1)
			felipe(d, maximal, n);

		// Flipo o vetor novamente, trazendo o ultimo elemento para a minha posiçao
		felipe(d, i, n);
	}

	printf("\n");

	// Liberando a memoria
	free(d);

	return 0;
}