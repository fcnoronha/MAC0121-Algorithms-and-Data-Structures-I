#include<stdio.h>
#include<stdlib.h>

void intercala(int v[], int ini, int meio, int fim){
	
	int *aux = malloc((fim - ini) * sizeof(int));
	int i = ini, j = meio, k = 0;

	while (i < meio && j < fim){
		if (v[i] < v[j])
			aux[k++] = v[i++];
		else 
			aux[k++] = v[j++];
	}

	while (i < meio)
		aux[k++] = v[i++];

	while (j < fim)
		aux[k++] = v[j++];

	for (int i = ini, k = 0; i < fim; i++, k++)
		v[i] = aux[k];

	free(aux);
}

void mergeS(int v[], int ini, int fim)
{
	if (ini < fim-1){
		int meio = (fim + ini)/2;
		mergeS(v, ini, meio);
		mergeS(v, meio, fim);
		intercala(v, ini, meio, fim);
	}
}


int main(){

	int v[] = {5, 3, 34, 4, 8, 2, 86, 0};

	mergeS(v, 0, 8);

	for (int i = 0; i < 8; i++)
		printf("%d ", v[i]);

	printf("\n\a");
}