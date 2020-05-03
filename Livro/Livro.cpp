#define _CRT_SECURE_NO_WARNINGS //Para remover avisos do scanf no Visual Studio (Retirar no Dev-C++)
/*
* Author: Juliano Zanella
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define maximo 10

int tamanho = 0;
int grafo[maximo];
int ma[maximo][maximo];
int opcao = 5;

int informar_valor(const char* frase, int min, int max);
void grafo_desenhar();
void grafo_desenhar_matriz();
void menu_mostrar();
void grafo_inserir();
void grafo_remover();

int main() {
	setlocale(LC_ALL, "Portuguese");
	tamanho = informar_valor("Escolha a quantidade de vértices do grafo, entre %d e %d: ", 1, maximo);
	for (int i = 0; i < tamanho; i++)
	{
		grafo[i] = i + 1;
	}
	do
	{
		system("cls");
		grafo_desenhar();
		grafo_desenhar_matriz();
		menu_mostrar();
		scanf("%d", &opcao);
		switch (opcao) {
		case 1:
			grafo_inserir();
			break;
		case 2:
			grafo_remover();
			break;
		case 0:
			break;
		default:
			printf("Opção inválida!\n");
			system("pause");
				break;
		}

	} while (opcao != 0);
	system("pause");
	return 0;
}

int informar_valor(const char* frase, int min, int max) {
	int valor = -1;
	do
	{
		printf(frase, min, max);
		scanf("%d", &valor);

	} while (valor < min || valor > max);
	return valor;
}

void grafo_desenhar() {
	printf("Grafo: ");
	for (int i = 0; i < tamanho; i++)
	{
		printf("%d\t", grafo[i]);
	}
	printf("\n");
}

void grafo_desenhar_matriz() {
	printf("Matriz de vértices:\n");
	for (int i = 0; i < tamanho; i++)
	{
		printf("%d", i + 1);
		for (int j = 0; j < tamanho; j++)
		{
			printf("\t%d", ma[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void menu_mostrar() {
	printf("\n\nEscolha uma opção:\n");
	printf("1 - Inserir aresta\n");
	printf("2 - Remover aresta\n");
	printf("0 - Sair\n\n");
}

void grafo_inserir() {
	int num1 = informar_valor("Escolha o vértice de origem, entre %d e %d: ", 1, tamanho);
	int num2 = informar_valor("Escolha o vértice de destino, entre %d e %d: ", 1, tamanho);
	num1--;
	num2--;
	ma[num1][num2] = 1;
	ma[num2][num1] = 1;
}

void grafo_remover() {
	int num1 = informar_valor("Escolha o vértice de origem, entre %d e %d: ", 1, tamanho);
	int num2 = informar_valor("Escolha o vértice de destino, entre %d e %d: ", 1, tamanho);
	num1--;
	num2--;
	ma[num1][num2] = 0;
	ma[num2][num1] = 0;
}

