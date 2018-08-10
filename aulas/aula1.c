#include<stdio.h> // difiniçao global
#define PI 3.14159

int main()
{
	unsigned int x; // int so com valores positivos, com o dobro do espaço de int
	unsigned long long int y; // llint so com valores positivos

	scanf("%d", &x); // "%d" e o tipo de dado que vou ler, o "&" serve
									   // para indicar o endero da varivael x na memoria

	// %d - double, %ld - long double, %Ld long long double, %u - unsigned, %f - float

	float ff = PI;
	printf("%3.1f\n", ff); // Imprime 3 casas, com 1 depois da virgula
	printf("%5.1f\n", ff); // Imprime 5 casas, com 1 depois da virgula
	printf("%10.4f\n", ff);

	char c = 'a'; // Armazena inteiro que sera interpretado como caractere
	for (c = 1; c < 127; c++) printf("%d : %c\n", c, c);

	return 0; // finaliza aplicaçao
}
