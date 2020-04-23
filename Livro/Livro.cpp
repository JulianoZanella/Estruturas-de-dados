#define _CRT_SECURE_NO_WARNINGS //Para remover avisos do scanf no Visual Studio (Retirar no Dev-C++)
/*
* Author: Juliano Zanella
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tamanho 7

struct tlivro {
	int codigo;
	char nome_do_livro[70];
	char autor[50];
};

struct tpilha_de_livros {
	tlivro livros[tamanho];
	int inicio;
	int fim;
};

struct tpilha_de_livros pilha;
int opcao;

void empilhar();
void guardar();
void mostrar_livros();
void menu();

int main() {
	setlocale(LC_ALL, "Portuguese");
	opcao = 1;
	pilha.inicio = 0;
	pilha.fim = 0;
	while (opcao != 0) {
		system("cls");
		menu();
		scanf("%d", &opcao);
		switch (opcao) {
		case 1:
			empilhar();
			break;
		case 2:
			guardar();
			break;
		case 3:
			mostrar_livros();
			break;
		}
	}

	return 0;
}

void empilhar() {
	if (pilha.fim == tamanho) {
		printf("\nA mesa está cheia! Vai quebrar!\n");
		system("pause");
	}
	else {
		tlivro livro;
		printf("\nDigite o código do livro: ");
		scanf("%d", &livro.codigo);
		printf("\nDigite o nome do livro: ");
		scanf("%s", livro.nome_do_livro);
		printf("\nDigite o autor do livro: ");
		scanf("%s", livro.autor);
		pilha.livros[pilha.fim] = livro;
		pilha.fim++;
	}
}

void guardar() {
	if (pilha.inicio == pilha.fim) {
		printf("\nA mesa está vazia! Nenhum livro para guardar.\n");
		system("pause");
	}
	else {
		tlivro livroNulo = pilha.livros[pilha.fim];
		livroNulo.codigo = 0;
		pilha.livros[pilha.fim - 1] = livroNulo;
		pilha.fim--;
		printf("\nLivro guardado!\n");
		system("pause");
	}
}

void mostrar_livros() {
	if (pilha.fim == 0) {
		printf("Não há livros na mesa.");
	}
	else {
		printf("\nLivros\n\n");
		printf("Código\tNome\t\tAutor\n");
		for (int i = 0; i < tamanho; i++) {
			tlivro livro = pilha.livros[i];
			if (livro.codigo > 0) {
				printf("%d\t%s\t\t%s\n", livro.codigo, livro.nome_do_livro, livro.autor);
			}
		}
	}
	
	printf("\n\n");
	system("pause");
}

void menu() {
	printf("\nEscolha uma opção:\n");
	printf("1 - Empilhar livro\n");
	printf("2 - Guardar Livro\n");
	printf("3 - Exibir dados dos Livros à guardar\n");
	printf("0 - Sair\n\n");
}