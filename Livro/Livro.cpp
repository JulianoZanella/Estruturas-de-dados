#define _CRT_SECURE_NO_WARNINGS //Para remover avisos do scanf no Visual Studio (Retirar no Dev-C++)
/*
* Author: Juliano Zanella
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

#define tamanho 5

struct tpilha {
	int dados[tamanho];
	int inicio;
	int fim;
};

struct tpilha pilha;
int opcao;

void pilha_push();
void pilha_pop();
void pilha_show();
void show_menu();

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	opcao = 1;
	pilha.inicio = 0;
	pilha.fim = 0;
	while (opcao != 0) {
		system("cls");
		pilha_show();
		show_menu();
		scanf("%d", &opcao);
		switch (opcao) {
		case 1:
			pilha_push();
			break;
		case 2:
			pilha_pop();
			break;
		}
	}

	return 0;
}

void pilha_push() {
	if (pilha.fim == tamanho) {
		printf("\nA pilha está cheia!\n");
		system("pause");
	}
	else {
		printf("\nDigite o valor a ser empilhado: ");
		scanf("%d", &pilha.dados[pilha.fim]);
		pilha.fim++;
	}
}

void pilha_pop() {
	if (pilha.inicio == pilha.fim) {
		printf("\nA pilha está vazia!\n");
		system("pause");
	}
	else {
		pilha.dados[pilha.fim - 1] = 0;
		pilha.fim--;
	}
}

void pilha_show() {
	printf("[ ");
	for (int i = 0; i < tamanho; i++) {
		printf("%d\t", pilha.dados[i]);
	}
	printf("]\n\n");
}

void show_menu() {
	printf("\nEscolha uma opção:\n");
	printf("1 - Empilhar\n");
	printf("2 - Desempilhar\n");
	printf("0 - Sair\n\n");
}