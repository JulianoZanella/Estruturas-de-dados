#define _CRT_SECURE_NO_WARNINGS //Para remover avisos do scanf no Visual Studio (Retirar no Dev-C++)
/*
* Author: Juliano Zanella
*/
//Bibliotecas
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

//Constantes 
#define tamanho 10

//Variáveis
int lista[tamanho];
int ordenado[tamanho];
int opt = -1;
int qtd;

//Prototipação 
void menu_mostrar(void);
void lista_mostrar(void);
void lista_gerar(void);
void lista_ler(void);
void lista_limpar(void);
void lista_mostrar_ordenado(void);

//Função Principal
int main(void) {
	srand(time(NULL));
	do {
		system("cls");
		lista_mostrar();
		lista_mostrar_ordenado();
		menu_mostrar();
		scanf("%d", &opt);
		switch (opt) {
		case 1:
			lista_gerar();
			break;
		case 2:
			lista_ler();
			break;
		}
	} while (opt != 0);
	system("pause");
	return(0);
}

//Mostra o conteúdo da lista 
void lista_mostrar(void) {
	printf("[  ");
	for (int i = 0; i < tamanho; i++) {
		printf("%d  ", lista[i]);
	}
	printf("]\n\n");
}

//Mostra o menu 
void menu_mostrar(void) {
	printf("1 - Gerar lista aleatoriamente\n");
	printf("2 - Criar lista manualmente\n");
	printf("0 - Sair...\n\n");
}

//Gera uma lista aleatória
void lista_gerar(void) {
	for (int i = 0; i < tamanho; i++) {
		lista[i] = rand() % 50;
	}
}

//Permite que o usuário entre com os valores da lista 
void lista_ler(void) {
	for (int i = 0; i < tamanho; i++) {
		system("cls");
		lista_mostrar();
		printf("\nDigite o valor para a posicao %d: ", i);
		scanf("%d", &lista[i]);
	}
}

//Preparar a lista para ordenação 
void lista_limpar(void) {
	for (int i = 0; i < tamanho; i++) {
		ordenado[i] = lista[i];
	}
}

//Mostra o conteúdo da lista ordenada 
void lista_mostrar_ordenado(void) {
	printf("[  ");
	for (int i = 0; i < tamanho; i++) {
		printf("%d  ", ordenado[i]);
	}
	printf("] Tempo = %d iteracoes\n\n", qtd);
}
