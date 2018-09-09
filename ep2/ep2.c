#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Estrutura utilizada para coordenar e aramazenar os vertices
typedef struct {
	int i;
	int j;
	int tamPal[2];
	int idxPal[2];	
}vertice;

// Estrututa utilizada na pilha
typedef struct{
	int vertice;
	int lado;
}par;

// Funçao para contar tamanho da palavra
int TamanhoPalavra(char *str){
	int tamanho = 0;
		while (str[tamanho] != '\0'){
			tamanho++;
		}
	return tamanho;
}

void setarTamanhos(vertice *ver, char **tab, int m, int n){

	int t = 0;	
	int di = ver->i;
	while (++di < m){
		if (tab[di][ver->j] == '*') break;
		t++;
	}
	printf("valor 0 t: %d\n", t);
	ver->tamPal[0] = t;

	t = 0;
	int dj = ver->j;
	while (++dj < n){
		if (tab[ver->i][dj] == '*') break; 
		t++;
	}
	printf("valor 1 t: %d\n", t);
	ver->tamPal[1] = t;

}

int main(){
	int i, j, m, n;

	while (scanf("%d %d", &m, &n) && !(m == 0 && n == 0)){
		// m - linha , n - col
		// Definindo a matrix que representara o tabuleiro
		char **tab;
		tab = malloc(m * sizeof(char *));
		for (i = 0; i < m; i++)
			tab[i] = malloc(n * sizeof(char));

		// Definindo array que contera o vertices
		vertice *v;
		v = malloc(m * n * sizeof(vertice));

		printf("Tabuleiro: \n");

		int ipt, nVertices = 0;

		// Lendo o tabuleiro
		for (i = 0; i < m; i++){
			for (j = 0; j < n; j++){
				tab[i][j] = '#'; // Inicializando tabuleiro, '#' representa vazio
				scanf("%d", &ipt);
				if (ipt == -1){
					// Inicializando um vertice
					tab[i][j] = '*';
					v[nVertices].i = i;
					v[nVertices].j = j;
					v[nVertices].idxPal[0] = -1;
					v[nVertices].idxPal[1] = -1;
					nVertices++;
				}
			}
		}

		printf("Palavra: \n");

		// Lendo a lista de palavras
		int nPal;
		scanf("%d", &nPal);
		char **pal;
		pal = malloc(nPal * sizeof(char*));
		for (i = 0; i < nPal; i++){
			pal[i] = malloc(100 * sizeof(char));
			scanf("%s", pal[i]);
		}

		// Setando o numero maximo que uma palavra pode ter para cada vertice
		for (i = 0; i < nVertices; i++)
			setarTamanhos(&v[i], tab, m, n);

		int palAtual = 0;
		while (palAtual != nPal){
			// fazer backtracking agr

			/*
				ir percorrendo toda a lista de palavras de palavras e ir tentando encaixar ela
				nos vertices, colocando na pilha o vertice que ela esta e em qual lado (precisarei
				de um nested while pra isso). Ademais, vou precisar de funcoes para checar se eu posso
				colocar a palavra em determinada linha/coluna (se nao colisao com outras palavras) e 
				outra funçao para montar o tabuleiro, ou seja, ela vai preencher o tab com as palvras
				a cada vez que eu consiga inserir uma palavra ou a cada vez que eu tiver que dar um 
				backestep. E a unica variavel que eu vou alterar no vertice vai ser a idxPal, definindo-a
				como -1 se nao houver nenhuma palavra ali, usando essas informaçoes na funcao de montagem
				do tabuleiro.
			*/
		}


	}
	return 0;
}