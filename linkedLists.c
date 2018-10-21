#include<stdio.h>
#include<stdlib.h>

struct celula {
	int info;
	struct celula *prox;
};

typedef struct celula *apontador;

// Printing
void imprimeLista(apontador inicio){
	apontador p = inicio;
	while (p != NULL){
		printf("%d\n", p->info);
		p = p->prox;
	}
}

// Searching
apontador busca(apontador inicio, int x){
	apontador p;
	for (p = inicio; p != NULL && p->info != x; p = p->prox);
	return p;
}

// Inserting in the beggining
apontador insereIni(apontador inicio, int x){
	apontador novo = malloc(sizeof(struct celula));
	novo->info = x;
	novo->prox = inicio;

	return novo;
}

// Inserting in the end
apontador insereFIm(apontador inicio, int x){
	apontador novo;
	if (inicio == NULL){
		novo = malloc(sizeof(struct celula));
		novo->info = x;
		novo->prox = NULL;
		return novo;
	}

	inicio->prox = insereFIm(inicio->prox, x);
	return inicio;
}

// Removing element recursively
apontador removeRec(apontador inicio, int x){
	apontador aux;

	if (inicio == NULL)
		return inicio;

	if (inicio->info == x){
		aux = inicio;
		inicio = inicio->prox;
		free(aux);
		return inicio;
	}

	inicio->prox = removeRec(inicio->prox, x);
	return inicio;
}

// "Intercalating" two ordered lists
apontador intercala(apontador p, apontador q){
	
	apontador inicio, ult;
	inicio = ult = NULL;

	while (p != NULL && q != NULL){
		if (p->info < q->info){
			if (ult == NULL) 
				inicio = ult = p;
			else {
				ult->prox = p;
				ult = p;
			}
			p = p->prox;
		}
		else {
			if (ult == NULL) 
				inicio = ult = q;
			else {
				ult->prox = q;
				ult = q;
			}
			q = q->prox;
		}
	}

	if (p == NULL){
		if (ult == NULL) 
			inicio = q;
		else 
			ult->prox = q;
	}


	if (p == NULL){
		if (ult == NULL) 
			inicio = p;
		else 
			ult->prox = p;
	}

	return inicio;
}