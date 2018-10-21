#include<stdio.h>
#include<stdlib.h>

void rebaixa(int v[], int n, int i)
{
	int pai = i, filho = 2*i + 1;

	while (filho < n){
		if (filho + 1 < n && v[filho+1] > v[filho]) // Getting bigger one
			filho++;

		if (v[filho] < v[pai])
			break;

		else {
			int aux = v[pai];
			v[pai] = v[filho];
			v[filho] = aux;

			pai = filho;
			filho = 2*pai + 1;
		}
	}
}

void heapfica(int v[], int n)
{
	for (int i = (n-2)/2; i >= 0; i--)
		rebaixa(v, n, i);
}

void heapS(int v[], int n)
{
	heapfica(v, n);

	for (int i = n-1; i > 0; i--){ // Bottom-up
		int aux = v[0];
		v[0] = v[i];
		v[i] = aux;

		rebaixa(v, i, 0);
	}
}

int main(){

	int v[] = {5, 3, 34, 4, 8, 2, 86, 0, 1000};

	heapS(v, 9);

	for (int i = 0; i < 9; i++)
		printf("%d ", v[i]);

	printf("\n\a");
}