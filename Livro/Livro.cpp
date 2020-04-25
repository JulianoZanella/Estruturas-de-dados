#define _CRT_SECURE_NO_WARNINGS //Para remover avisos do scanf no Visual Studio (Retirar no Dev-C++)
/*
* Author: Juliano Zanella
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

#define tamanho 7


struct tcliente {
	char nome[100];
	time_t horario;
};

struct tfila {
	tcliente clientes[tamanho];
	int inicio;
	int fim;
};

struct tfila fila;
int opcao;

void entrar_na_fila();
void sair_da_fila();
void mostrar_clientes();
void menu();

int main() {
	setlocale(LC_ALL, "Portuguese");
	opcao = 1;
	fila.inicio = 0;
	fila.fim = 0;
	while (opcao != 0) {
		system("cls");
		menu();
		scanf("%d", &opcao);
		switch (opcao) {
		case 1:
			entrar_na_fila();
			break;
		case 2:
			sair_da_fila();
			break;
		case 3:
			mostrar_clientes();
			break;
		}
	}

	return 0;
}

void entrar_na_fila() {
	if (fila.fim == tamanho) {
		printf("\nNão há espaço disponível para atendimento!\n");
		system("pause");
	}
	else {
		tcliente cliente;
		printf("\nDigite o nome do cliente: ");
		scanf("%s", cliente.nome);
		cliente.horario = time(NULL);
		
		fila.clientes[fila.fim] = cliente;
		fila.fim++;
	}
}

void sair_da_fila() {
	if (fila.inicio == fila.fim) {
		printf("\nA mesa está vazia! Nenhum livro para guardar.\n");
		system("pause");
	}
	else {
		tcliente clienteNulo = { "", time(NULL) };
		fila.clientes[fila.inicio] = clienteNulo;
		for (int i = 0; i < tamanho; i++)
		{
			fila.clientes[i] = fila.clientes[i + 1];
		}
		fila.fim--;
		printf("\nCliente chamado!\n");
		system("pause");
	}
}

void mostrar_clientes() {
	if (fila.fim == 0) {
		printf("Não há mais clientes.");
	}
	else {
		printf("\nClientes\n\n");
		printf("Horário\t\t\t\tNome\n");
		for (int i = 0; i < tamanho; i++) {
			tcliente cliente = fila.clientes[i];
			if (strlen(cliente.nome) > 0) {
				printf("%s\t\t\t\t%s\n", ctime(&cliente.horario), cliente.nome);
			}				
		}
	}
	
	printf("\n\n");
	system("pause");
}

void menu() {
	printf("\nEscolha uma opção:\n");
	printf("1 - Entrar na fila\n");
	printf("2 - Chamar cliente\n");
	printf("3 - Exibir clientes esperando\n");
	printf("0 - Sair\n\n");
}