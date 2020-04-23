#define _CRT_SECURE_NO_WARNINGS //Para remover avisos do scanf no Visual Studio (Retirar no Dev-C++)
/*
* Author: Juliano Zanella
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");

	int tamanho;
	int* vetor;
	printf("Escolha o tamanho do vetor: ");
	scanf("%d", &tamanho);
	vetor = (int*)malloc(sizeof(int) * tamanho);
	for (int i = 0; i < tamanho; i++)
	{
		vetor[i] = pow(2, i);
		printf("Posição %d: %d\n", i, vetor[i]);
	}

	system("Pause");
	return 0;
}