#define _CRT_SECURE_NO_WARNINGS //Para remover avisos do scanf no Visual Studio (Retirar no Dev-C++)
/*
* Author: Juliano Zanella
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAXV 8

typedef struct str_no {
	int id;
	struct str_no* proximo;
}str_no;

str_no grafo[MAXV];
//Variáveis 
int destino, origem, vertices = 0;
int custo = 0;
int* custos = NULL;

//Prototipação
void buscaEmProfundidade(struct str_no g[], int inicio, int alvo);
void menu_mostrar(void);
void criar_grafo();
void adiciona_aresta_ao_grafo(str_no* grafo, int origem, int destino);
void desenhar_grafo();
void buscar();

int main(int argc, char** argv) {
	int opt = -1;
	//Laço principal do menu   
	do {
		//Desenha o menu na tela     
		menu_mostrar();
		scanf("%d", &opt);
		switch (opt) {
		case 1:
			criar_grafo();
			break;
		case 2:
			desenhar_grafo();
			system("pause");
			break;
		case 3:
			buscar();
			break;
		}
	} while (opt != 0);

	return 0;
}

void criar_grafo() {
	printf("\nInforme a quantidade de vertices:");
	scanf("%d", &vertices);
	//Preenchendo o grafo com os vertices.
	for (int i = 0; i < vertices; i++)
	{
		str_no* novoNo = (str_no*)malloc(sizeof(str_no));
		novoNo->id = i + 1;
		novoNo->proximo = NULL;
		grafo[i] = *novoNo;
		free(novoNo);
	}

	do {
		desenhar_grafo();
		printf("Informe as arestas:\n");
		do {
			printf("Origem (entre 1 e %d ou '0' para sair): ", vertices);
			scanf("%d", &origem);
		} while (origem < 0 || origem > vertices);
		if (origem) {
			do {
				printf("Destino (entre 1 e %d, menos %d): ", vertices, origem);
				scanf("%d", &destino);
			} while (destino < 1 || destino > vertices || destino == origem);
			adiciona_aresta_ao_grafo(grafo, origem, destino);
			adiciona_aresta_ao_grafo(grafo, destino, origem);
		}
	} while (origem);

}

void adiciona_aresta_ao_grafo(str_no* grafo, int origem, int destino) {

	str_no* lista = &grafo[origem - 1];
	while (lista->proximo != NULL)
	{
		lista = lista->proximo;
	}
	str_no* novoNo = (str_no*)malloc(sizeof(str_no));
	novoNo->id = destino;
	novoNo->proximo = NULL;
	lista->proximo = novoNo;
}

void desenhar_grafo() {
	if (vertices == 0) {
		printf("Grafo nao inicializado!");
		return;
	}
	for (int i = 0; i < vertices; i++)
	{
		printf("[%d] - ", grafo[i].id);
		str_no* lista = &grafo[i];
		while (lista->proximo != NULL) {			
			lista = lista->proximo;
			printf("%d-", lista->id);
		}
		printf("\n");
	}
}

//Desenha o menu na tela 
void menu_mostrar(void) {
	system("cls");
	printf("Algoritmos de Busca\n");
	printf("Opcoes:\n");
	printf("\t 1 - Adicionar um Grafo\n");
	printf("\t 2 - Exibir Grafo\n");
	printf("\t 3 - Busca em Profundidade\n");
	printf("\t 0 - Sair do programa\n");
	printf("Opcao: ");
}

void buscar() {
	if (vertices == 0) {
		printf("Crie um grafo!");
		system("pause");
		return;
	}
	int inicio, alvo;
	system("cls");
	printf("Informe o inicio do grafo:");
	scanf("%d", &inicio);
	printf("Informe o alvo da busca:");
	scanf("%d", &alvo);
	buscaEmProfundidade(grafo, inicio, alvo);
	system("pause");
}

void buscaEmProfundidade(struct str_no g[], int inicio, int alvo) {
	int pilha[MAXV]; //pilha
	bool visitado[MAXV]; //nós visitados 
	int indice = 0; //índice do topo da pilha 
	bool achou = false; //flag de controle (não visitados) 
	int corrente = inicio;
	struct str_no* ptr;
	int i;
	printf("=-=-=-= Busca em Profundidade =-=-=-=\n");
	//Marcando os nós como ‘não visitados’. 
	for (i = 0; i < MAXV; i++) {
		visitado[i] = false;
	}
	while (true) {
		//Nó corrente não visitado? Marque como visitado.
		//Empilhe o nó corrente. 
		if (!visitado[corrente]) {
			printf("VISITANDO: %d. \n", corrente);
			if (corrente == alvo) {
				printf("Alvo encontrado!\n\n\n");
				return;
			}
			visitado[corrente] = true;
			pilha[indice] = corrente;
			indice++;
		}
		//Buscando por nós adjacentes, não visitados.  
		achou = false;
		for (ptr = g[corrente].proximo; ptr != NULL; ptr = ptr->proximo) {
			if (!visitado[ptr->id]) {
				achou = true;
				break;
			}
		}
		if (achou) {
			//Atualizando o nó corrente.   
			corrente = ptr->id;
		}
		else {
			//Não há vértices adjacentes não visitados.  
			//Tentando desempilhar o vértice do topo.
			indice--;
			if (indice == -1) {
				//Não há mais vértices não visitados.
				printf("Encerrando a busca. \n");
				break;
			}
			corrente = pilha[indice];
		}
	}
	return;
}