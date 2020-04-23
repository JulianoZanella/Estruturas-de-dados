#define _CRT_SECURE_NO_WARNINGS //Para remover avisos do scanf no Visual Studio (Retirar no Dev-C++)
/*
* Author: Juliano Zanella
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int xi;
int* ptr_xi;

void imprimir();

int main()
{
	setlocale(LC_ALL, "Portuguese");

	xi = 10;
	ptr_xi = &xi;
	imprimir();

	xi = 20;
	imprimir();

	*ptr_xi = 30;
	imprimir();

	return 0;
}

void imprimir() {
	printf("Valor de xi = %d \n", xi);
	printf("Valor de &xi = %p \n", &xi);
	printf("Valor de ptr_xi = %p \n", ptr_xi);
	printf("Valor de *ptr_xi = %d \n", *ptr_xi);
	system("Pause");
}
