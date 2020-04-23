#define _CRT_SECURE_NO_WARNINGS //Para remover avisos do scanf no Visual Studio (Retirar no Dev-C++)
/*
* Author: Juliano Zanella
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

#define tamanho 5

struct tfila {
	int dados[tamanho];
	int inicio;
	int fim;
};

struct tfila fila;
int opcao;

void fila_entrar();
void fila_sair();
void fila_mostrar();
void show_menu();

int main() {
	setlocale(LC_ALL, "Portuguese");
	opcao = 1;
	fila.inicio = 0;
	fila.fim = 0;
	while (opcao != 0) {
		system("cls");
		fila_mostrar();
		show_menu();
		scanf("%d", &opcao);
		switch (opcao) {
		case 1:
			fila_entrar();
			break;
		case 2:
			fila_sair();
			break;
		}
	}

	return 0;
}

void fila_entrar() {
	if (fila.fim == tamanho) {
		printf("\nA fila está cheia!\n");
		system("pause");
	}
	else {
		printf("\nDigite o valor a ser inserido: ");
		scanf("%d", &fila.dados[fila.fim]);
		fila.fim++;
	}
}

void fila_sair() {
	if (fila.inicio == fila.fim) {
		printf("\nA fila está vazia!\n");
		system("pause");
	}
	else {
		for (int i = 0; i < tamanho; i++)
		{
			fila.dados[i] = fila.dados[i + 1];//Por incrivel que pareca nao da erro acessando a posicao 5.
		}
		fila.dados[fila.fim] = 0;
		fila.fim--;
	}
}

void fila_mostrar() {
	printf("[ ");
	for (int i = 0; i < tamanho; i++) {
		printf("%d\t", fila.dados[i]);
	}
	printf("]\n\n");
}

void show_menu() {
	printf("\nEscolha uma opção:\n");
	printf("1 - Incluir na Fila\n");
	printf("2 - Excluir da Fila\n");
	printf("0 - Sair\n\n");
}