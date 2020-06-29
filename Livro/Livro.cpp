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
#define HASH 10

struct noh {
	int dado;
	noh* proximo;
};

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
void troca(int* a, int* b);
int bubbleSort(int vec[]);
int selectionSort(int vec[]);
int insertionSort(int vec[]);
int shellSort(int vec[]);
int mergeSort(int vec[], int tam, int qtd);
void junta(int vec[], int tam);
int quickSort(int vec[], int left, int right, int qtd);
int particiona(int vec[], int left, int right);
int heapifica(int vec[], int tam, int i);
int constroiHeap(int vec[], int tam);
int heapSort(int vec[], int tam);
void buscarValor(int opt);
void exibirResultadoBusca(int posicao);
int buscaSequencial(int vec[], int arg, int tam);
int buscaIndexada(int vec[], int arg, int tam);
void mostrarEsforco(int qtd);
int buscaBinaria(int vec[], int arg, int tam);
int buscaInterpol(int vec[], int arg, int tam);
int buscaHash(int vec[], int arg, int tam);
int hash(int valor);
void inserirNaHash(noh* lista, int valor);
int buscarNaHash(noh* lista, int valor);

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
		case 3:
			lista_limpar();
			qtd = bubbleSort(ordenado);
			break;
		case 4:
			lista_limpar();
			qtd = selectionSort(ordenado);
			break;
		case 5:
			lista_limpar();
			qtd = insertionSort(ordenado);
			break;
		case 6:
			lista_limpar();
			qtd = shellSort(ordenado);
			break;
		case 7:
			lista_limpar();
			qtd = mergeSort(ordenado, tamanho, qtd);
			break;
		case 8:
			lista_limpar();
			qtd = quickSort(ordenado, 0, tamanho - 1, qtd);
			break;
		case 9:
			lista_limpar();
			qtd = heapSort(ordenado, tamanho);
			break;
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
			buscarValor(opt);
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

	printf("-----Ordenacao-----\n");
	printf("3 - BubbleSort\n");
	printf("4 - SelectionSort\n");
	printf("5 - InsertionSort\n");
	printf("6 - ShellSort\n");
	printf("7 - MergeSort\n");
	printf("8 - QuickSort\n");
	printf("9 - HeapSort\n");

	printf("-----Busca-----\n");
	printf("10 - Busca Sequencial\n");
	printf("11 - Busca Sequencial Indexada\n");
	printf("12 - Busca Binaria\n");
	printf("13 - Busca por Interpolacao\n");
	printf("14 - Busca por Tabela de Dispersao/Hash\n");

	printf("\n0 - Sair...\n\n");
	printf("Opcao: ");
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

//Função genérica de troca de valores 
void troca(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

//Aplica o método do bubbleSort
int bubbleSort(int vec[]) {
	int qtd, i, j, tmp;
	qtd = 0;
	for (i = 0; i < tamanho - 1; i++) {
		for (j = i + 1; j < tamanho; j++) {
			if (vec[i] > vec[j]) {
				troca(&vec[i], &vec[j]);
			}       qtd++;
		}
	}
	return(qtd);
}

//Aplica o modo selectionSort  
int selectionSort(int vec[]) {
	int i, j, min, qtd = 0;
	for (i = 0; i < (tamanho - 1); i++) {
		min = i;
		for (j = (i + 1); j < tamanho; j++) {
			if (vec[j] < vec[min]) {
				min = j;
			}
			qtd++;
		}
		if (i != min) {
			troca(&vec[i], &vec[min]);
		}
	}
	return(qtd);
}

//Aplicando o insertionSort 
int insertionSort(int vec[]) {
	int i, j, qtd = 0;
	for (i = 1; i < tamanho; i++) {
		j = i;
		while ((vec[j] < vec[j - 1]) && (j != 0)) {
			troca(&vec[j], &vec[j - 1]);
			j--;
			qtd++;
		}
	}
	return(qtd);
}

//Aplica o shellSort 
int shellSort(int vec[]) {
	int i, j, valor, qtd = 0;
	int gap = 1;
	do {
		gap = 3 * gap + 1;
	} while (gap < tamanho);
	do {
		gap /= 3;
		for (i = gap; i < tamanho; i++) {
			valor = vec[i];
			j = i - gap;
			while (j >= 0 && valor < vec[j]) {
				vec[j + gap] = vec[j];
				j -= gap;
				qtd++;
			}
			vec[j + gap] = valor;
		}
	} while (gap > 1);
	return (qtd);
}

//Aplica o modo mergeSort
int mergeSort(int vec[], int tam, int qtd) {
	int meio;
	if (tam > 1) {
		meio = tam / 2;
		qtd = mergeSort(vec, meio, qtd);
		qtd = mergeSort(vec + meio, tam - meio, qtd);
		junta(vec, tam);
	}
	return (qtd + 1);
}

//Junta os pedaços num novo vetor ordenado 
void junta(int vec[], int tam) {
	int i, j, k;
	int meio;
	int* tmp;
	tmp = (int*)malloc(tam * sizeof(int));
	if (tmp == NULL) {
		exit(1);
	}
	meio = tam / 2;
	i = 0;
	j = meio;
	k = 0;
	while (i < meio && j < tam) {
		if (vec[i] < vec[j]) {
			tmp[k] = vec[i];
			++i;
		}
		else {
			tmp[k] = vec[j];
			++j;
		}
		++k;
	}
	if (i == meio) {
		while (j < tam) {
			tmp[k] = vec[j];
			++j;
			++k;
		}
	}
	else {
		while (i < meio) {
			tmp[k] = vec[i];
			++i;
			++k;
		}
	}
	for (i = 0; i < tam; ++i) {
		vec[i] = tmp[i];
	}
	free(tmp);
}

//Aplica o modo do quickSort 
int quickSort(int vec[], int left, int right, int qtd) {
	int r;
	if (right > left) {
		r = particiona(vec, left, right);
		qtd = quickSort(vec, left, r - 1, qtd);
		qtd = quickSort(vec, r + 1, right, qtd);
	}
	return (qtd + 1);
}
//Divide o vetor em pedaços menores 
int particiona(int vec[], int left, int right) {
	int i, j;
	i = left;
	for (j = left + 1; j <= right; ++j) {
		if (vec[j] < vec[left]) {
			++i;
			troca(&vec[i], &vec[j]);
		}
	}
	troca(&vec[left], &vec[i]);
	return i;
}

//Garante as propriedades de heap a um nó 
int heapifica(int vec[], int tam, int i) {
	int e, d, maior, qtd;
	qtd = 1;
	e = 2 * i + 1;
	d = 2 * i + 2;
	if (e < tam && vec[e] > vec[i]) {
		maior = e;
	}
	else {
		maior = i;
	}
	if (d < tam && vec[d] > vec[maior]) {
		maior = d;
	}
	if (maior != i) {
		troca(&vec[i], &vec[maior]);
		qtd += heapifica(vec, tam, maior);
	}
	return qtd;
}

//Transforma o vetor em uma heap 
int constroiHeap(int vec[], int tam) {
	int i, qtd; qtd = 0;
	for (i = tam / 2; i >= 0; i--) {
		qtd += heapifica(vec, tam, i);
	}
	return qtd;
}

//Ordena com base na estrutura heap 
int heapSort(int vec[], int tam) {
	int n, i, qtd;
	qtd = 0;
	qtd += constroiHeap(vec, tam);
	n = tam;
	for (i = tam - 1; i > 0; i--) {
		troca(&vec[0], &vec[i]);
		n--;
		qtd += heapifica(vec, n, 0);
	}
	return qtd;
}

void buscarValor(int opt) {
	printf("\n\nDigite o valor a ser procurado:");
	int valor, vetor;
	scanf("%d", &valor);
	printf("Em qual vetor (Original=0/Ordenado=1)?");
	scanf("%d", &vetor);
	int* vec;
	if (vetor == 0) {
		vec = lista;
	}
	else
	{
		vec = ordenado;
	}
	switch (opt)
	{
	case 10: exibirResultadoBusca(buscaSequencial(vec, valor, tamanho));
		break;
	case 11: exibirResultadoBusca(buscaIndexada(vec, valor, tamanho));
		break;
	case 12: exibirResultadoBusca(buscaBinaria(vec, valor, tamanho));
		break;
	case 13: exibirResultadoBusca(buscaInterpol(vec, valor, tamanho));
		break;
	case 14: exibirResultadoBusca(buscaHash(vec, valor, tamanho));
		break;
	}
}

void exibirResultadoBusca(int posicao) {
	if (posicao == -1) {
		printf("\nValor nao encontrado\n");
	}
	else
	{
		printf("\nValor encontrado na posicao [%d] do vetor.\n", posicao);
	}
	system("pause");
}

//Função de busca sequencial
int buscaSequencial(int vec[], int arg, int tam) {
	int i = 0, achou = -1;
	while (i < tam && achou == -1) {
		if (vec[i] == arg) {
			achou = i;
		}
		i++;
	}
	mostrarEsforco(i + 1);
	return achou;
}

//Função de Busca Sequencial Indexada por ordem ascendente
int buscaIndexada(int vec[], int arg, int tam) {
	lista_limpar();
	shellSort(vec);
	int i = 0, achou = -1;
	for (i = 0; i < tam; i++)
	{
		if (vec[i] == arg) {
			achou = i;
			break;
		}
		if (vec[i] > arg) break;
	}
	mostrarEsforco(i + 1);
	return achou;
}

void mostrarEsforco(int qtd) {
	printf("Esforco computacional: %d iteracoes", qtd);
}

//Função de Busca Binária 
int buscaBinaria(int vec[], int arg, int tam) {
	lista_limpar();
	shellSort(vec);
	int menor, maior, meio, i = 0, achou = -1;
	menor = 0;
	maior = tam - 1;
	while (menor <= maior) {
		meio = (menor + maior) / 2;
		if (arg == vec[meio]) {
			achou = meio;
			break;
		}
		if (arg < vec[meio]) {
			maior = meio - 1;
		}
		else {
			menor = meio + 1;
		}
		i++;
	}
	mostrarEsforco(i + 1);
	return achou;
}

//Função de busca por interpolação 
int buscaInterpol(int vec[], int arg, int tam) {
	int menor, maior, meio, achou, i = 0;
	menor = 0;
	maior = tam - 1;
	achou = -1;
	while ((menor <= maior) && (achou == -1)) {
		meio = menor + (maior - menor) * ((arg - vec[menor]) / (vec[maior] - vec[menor]));
		if (arg == vec[meio]) {
			achou = meio;
		}
		if (arg < vec[meio]) {
			maior = meio - 1;
		}
		else {
			menor = meio + 1;
		}
		i++;
	}
	mostrarEsforco(i + 1);
	return(achou);
}

//Função de busca por dispersão
int buscaHash(int vec[], int arg, int tam) {
	//Primeiro monta a tabela hash
	int i = 0;
	noh* vetorHash[HASH];
	for (i = 0; i < HASH; i++)
	{
		noh* lista;
		lista = (noh*)malloc(sizeof(noh));
		lista->dado = -1;
		lista->proximo = NULL;
		vetorHash[i] = lista;
	}
	//Depois insere dinamicamente
	for (i = 0; i < tam; i++)
	{
		int posicao = hash(vec[i]);
		inserirNaHash(vetorHash[posicao], vec[i]);
	}
	//para então buscar
	int posicao = hash(arg);
	printf("Valor se encontra na %d posicao na tabela de dispersao/n", posicao);
	int retorno = buscarNaHash(vetorHash[posicao], arg);
	//Dispose
	for (i = 0; i < HASH; i++)
	{
		free(vetorHash[i]);
	}
	return retorno;
}

//Função Hash
int hash(int valor) {
	return (valor * valor) % HASH;
}

void inserirNaHash(noh* lista, int valor) {
	if (lista->dado == -1) {
		lista->dado = valor;
	}
	else {

		while (lista->proximo != NULL) {
			lista = lista->proximo;
		}
		lista->proximo = (noh*)malloc(sizeof(noh));
		lista = lista->proximo;
		lista->dado = valor;
		lista->proximo = NULL;
	}
}

int buscarNaHash(noh* lista, int valor) {
	int achou = -1, i = 0;
	if (lista->dado != -1) {
		while (lista->proximo != NULL) {
			if (lista->dado == valor) {
				achou = i;
				break;
			}
			lista = lista->proximo;
			i++;
		}
		if (lista->dado == valor) achou = i;
	}
	mostrarEsforco(i + 1);
	return achou;
}