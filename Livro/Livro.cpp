#define _CRT_SECURE_NO_WARNINGS //Para remover avisos do scanf no Visual Studio (Retirar no Dev-C++)
/*
* Author: Juliano Zanella
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

struct noh {
	int dado;
	noh* proximo;
};

typedef noh* ptr_noh;
ptr_noh lista;
int op;

void menu_mostrar();
void menu_selecionar(int op);
void lista_mostrar(ptr_noh lista);
void lista_inserir(ptr_noh lista);
void lista_remover(ptr_noh lista);


int main() {
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	op = 1;
	lista = (ptr_noh)malloc(sizeof(noh));
	lista->dado = 0;
	lista->proximo = NULL;
	while (op != 0) {
		system("cls");
		menu_mostrar();
		scanf("%d", &op);
		menu_selecionar(op);
	}
	free(lista);
	system("pause");
	return 0;
}

void menu_mostrar() {
	lista_mostrar(lista);
	printf("\n\nEscolha uma opção:\n");
	printf("1 - Inserir no final da Lista\n");
	printf("2 - Remover da Lista\n");
	printf("0 - Sair\n\n");
}

void menu_selecionar(int op){
	switch (op){
	case 1:
		lista_inserir(lista);
		break;
	case 2:
		lista_remover(lista);
		break;
	default:
		break;
	}
}

void lista_mostrar(ptr_noh lista) {
	system("cls");
	while (lista->proximo != NULL) {
		printf("%d\t", lista->dado);
		lista = lista->proximo;
	}
	printf("%d", lista->dado);
}

void lista_inserir(ptr_noh lista) {
	while (lista->proximo != NULL) {
		lista = lista->proximo;
	}
	lista->proximo = (ptr_noh)malloc(sizeof(noh));
	lista = lista->proximo;
	lista->dado = rand() % 100;
	lista->proximo = NULL;
}

void lista_remover(ptr_noh lista) {
	int dado;
	ptr_noh atual = (ptr_noh)malloc(sizeof(noh));
	printf("\n\nEscolha qual valor remover:");
	scanf("%d", &dado);
	while (lista->dado != dado) {
		atual = lista;
		lista = lista->proximo;
	}
	if (lista->dado == dado) {
		atual->proximo = lista->proximo;
	}
}
