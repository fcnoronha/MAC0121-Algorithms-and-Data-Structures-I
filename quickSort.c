#include<stdio.h>
#include<stdlib.h>

int separa(int v[], int ini, int fim) // Sedgwick method
{
	int i = ini-1, j, pivo = v[fim-1];

	for (j = ini; j < fim; j++){
		if (v[j] <= pivo){
			i++;
			int aux = v[i];
			v[i] = v[j];
			v[j] = aux;
		}
	}

	return i;
}

void quickS(int v[], int ini, int fim)
{
	int pivo;
	if (fim - ini >= 2){
		pivo = separa(v, ini, fim);
		quickS(v, ini, pivo);
		quickS(v, pivo+1, fim);
	}
}


int main(){

	int v[] = {5, 3, 34, 4, 8, 2, 86, 0, 1000};

	quickS(v, 0, 9);

	for (int i = 0; i < 9; i++)
		printf("%d ", v[i]);

	printf("\n\a");
}