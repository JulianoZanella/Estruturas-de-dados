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

	int* ptr;
	ptr = (int*)malloc(sizeof(int));
	*ptr = 42;
	printf("Endereço: %p, valor: %d\n", ptr, *ptr);

	system("Pause");
	return 0;
}