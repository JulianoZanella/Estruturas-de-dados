#define _CRT_SECURE_NO_WARNINGS //Para remover avisos do scanf no Visual Studio (Retirar no Dev-C++)
/*
* Author: Juliano Zanella
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");

	int* ptr;
	ptr = (int*)malloc(sizeof(int));
	printf("Endereço: %p\nValor: %d\n\n", ptr, *ptr);
	*ptr = 10;
	printf("Endereço: %p\nValor: %d\n\n", ptr, *ptr);

	return 0;
}