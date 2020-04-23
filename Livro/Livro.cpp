#define _CRT_SECURE_NO_WARNINGS //Para remover avisos do scanf no Visual Studio (Retirar no Dev-C++)
/*
* Author: Juliano Zanella
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

struct semaforo {
	char cor[50];
	int id;
};
semaforo a = { "vermelha", 1 };
semaforo b = { "amarela", 2 };
semaforo c = { "verde", 3 };
semaforo* ptr;



int main()
{
	setlocale(LC_ALL, "Portuguese");

	ptr = &a;

	printf("Semáforo: %d, cor: %s\n", (*ptr).id, (*ptr).cor);
	ptr++;
	printf("Semáforo: %d, cor: %s\n", (*ptr).id, (*ptr).cor);
	ptr++;
	printf("Semáforo: %d, cor: %s\n", (*ptr).id, (*ptr).cor);

	system("Pause");
	return 0;
}