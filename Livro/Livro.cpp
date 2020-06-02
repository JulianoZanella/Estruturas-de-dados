#define _CRT_SECURE_NO_WARNINGS //Para remover avisos do scanf no Visual Studio (Retirar no Dev-C++)
/*
* Author: Juliano Zanella
*/
#include <stdio.h>
#include <stdlib.h>

struct No
{
	char dado;
	No* pai;
	No* esquerdo;
	No* direito;
};