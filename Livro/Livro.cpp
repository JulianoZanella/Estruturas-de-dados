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
	int* vetor_base_2;
	int* vetor_base_3;

	printf("Qual o tamanho do 1º vetor: ");
	scanf("%d", &tamanho);

	vetor_base_2 = (int*)malloc(sizeof(int) * tamanho);
	vetor_base_3 = (int*)malloc(sizeof(int) * tamanho * 2);

	printf("Vetor base 2: [");
	for (int i = 0; i < tamanho; i++)
	{
		vetor_base_2[i] = pow(2, i);
		printf("%d\t", vetor_base_2[i]);
	}
	printf("]\n");

	printf("Vetor base 3: [");
	for (int i = 0; i < tamanho * 2; i++)
	{
		vetor_base_3[i] = pow(3, i);
		printf("%d\t", vetor_base_3[i]);
	}
	printf("]\n");

	system("Pause");
	return 0;
}