#include<stdio.h>
#include<stdlib.h>

void bubble(int v[], int n){
	int trocou = 1;

	for (int i = 1; i < n && trocou; i++){
		trocou = 0;
		for (int j = 0; j < n - 1; j++){
			if (v[j+1] < v[j]){
				int aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
				trocou = 1;
			}
		}
	}
}


int main(){

	int v[] = {5, 3, 34, 4, 8, 2, 86, 0};

	bubble(v, 8);

	for (int i = 0; i < 8; i++)
		printf("%d ", v[i]);

	printf("\n\a");
}