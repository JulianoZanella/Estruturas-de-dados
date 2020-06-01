#define _CRT_SECURE_NO_WARNINGS //Para remover avisos do scanf no Visual Studio (Retirar no Dev-C++)
/*
* Author: Juliano Zanella
*/
#include <stdio.h>
#include <stdlib.h>

//Constantes 
#define tamanho 100
#define E 0
#define D 1
#define R -1

//Variáveis 
char arvore[tamanho];
int opt = -1;
char pai, no;
int lado;
int fim = 0;

//Prototipação 
void arvore_insere(int pai, char dado, int lado);
int arvore_procura(char dado);
void menu_mostrar(void);

//Função principal 
int main(void) {
	int temp;
	do {
		menu_mostrar();
		scanf("%d", &opt);
		fflush(stdin);
		switch (opt) {
		case 1:
			printf("\nDigite o valor do PAI: ");
			scanf("%c", &pai);
			scanf("%c", &pai);
			fflush(stdin);
			printf("Digite o valor do NO: ");
			scanf("%c", &no);
			scanf("%c", &no);
			fflush(stdin);
			printf("Digite o lado da subarvore (E=%d/D=%d/R=%d): ", E, D, R);
			scanf("%d", &lado);
			fflush(stdin);
			temp = arvore_procura(pai);
			arvore_insere(temp, no, lado);
			break;
		case 2:
			printf("Digite o valor do NO: ");
			scanf("%c", &no);
			scanf("%c", &no);
			fflush(stdin);
			temp = arvore_procura(no);
			printf("No %c\nFilho Esquerda: %c\nFilho Direita: %c\n\n",
				arvore[temp],
				arvore[(2 * temp) + 1],
				arvore[(2 * temp) + 2]);
			system("pause");
			break;
		}
	} while (opt != 0);
	system("pause");
	return(0);
}

//Inserir nó 
void arvore_insere(int pai, char dado, int lado) {
	int p = 0;
	switch (lado)
	{
	case E:
		p = (2 * pai) + 1;
		break;
	case D:
		p = (2 * pai) + 2;
		break;
	case R:
		p = 0;
		break;
	}
	arvore[p] = dado;
	fim = p + 1;
}

//Procura nó 
int arvore_procura(char dado) {
	if (fim != 0) {
		for (int i = 0; i < fim; i++) {
			if (arvore[i] == dado) {
				return (i);
			}
		}
	}
	else {
		return (0);
	}
}

//Desenha o menu na tela 
void menu_mostrar(void) {
	system("cls");
	for (int i = 0; i < fim + 1; i++) {
		printf("| %c ", arvore[i]);
	}
	printf("\n1 - Inserir um NO na arvore");
	printf("\n2 - Pesquisar um NO na arvore");
	printf("\n0 - Sair...\n\n");
}