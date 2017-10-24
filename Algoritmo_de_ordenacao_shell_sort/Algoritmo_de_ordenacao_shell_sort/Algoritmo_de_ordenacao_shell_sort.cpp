#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#pragma warning (disable:4996)

typedef struct Fabricante
{
	char nome[50];
	char nacionalidade[50];
	int ano;
}Fabricante;

void insertionSortAdaptado(Fabricante *vetor, int n, int f, int h)
{
	Fabricante valor;
	int k, j;
	for (int i = f + h; i < n; i = i + h)
	{
		valor = vetor[i];
		k = f;
		j = i - h;
		while ((j >= f) && (k == f))
		{
			//Ordena pelo nome
			if (strcmp(valor.nome, vetor[j].nome) == 0)
			{
				if (strcmp(valor.nacionalidade, vetor[j].nacionalidade) == 0)
				{
					if (valor.ano < vetor[j].ano)
					{
						strcpy(vetor[j + h].nome, vetor[j].nome);
						strcpy(vetor[j + h].nacionalidade, vetor[j].nacionalidade);
						vetor[j + h].ano = vetor[j].ano;
						j = j - h;
					}
					else
					{
						k = j + h;
					}
				}
				else if (strcmp(valor.nacionalidade, vetor[j].nacionalidade) == -1)
				{
					strcpy(vetor[j + h].nome, vetor[j].nome);
					strcpy(vetor[j + h].nacionalidade, vetor[j].nacionalidade);
					vetor[j + h].ano = vetor[j].ano;
					j = j - h;
				}
				else {
					k = j + h;
				}
			}
			else if (strcmp(valor.nome, vetor[j].nome) == -1)
			{
				strcpy(vetor[j + h].nome, vetor[j].nome);
				strcpy(vetor[j + h].nacionalidade, vetor[j].nacionalidade);
				vetor[j + h].ano = vetor[j].ano;
				j = j - h;
			}
			else {
				k = j + h;

			}

		}
		vetor[k] = valor;
	}
}

void escreveVetor(Fabricante *vetor, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("vet[%d]\n Nome: %s\n Nacionalidade: %s\n Ano: %d\n\n\n", i, vetor[i].nome, vetor[i].nacionalidade, vetor[i].ano);
	}
	printf("\n\n");
}

void shellSort(Fabricante *vetor, int n, int np)
{
	int h;
	for (int p = np; p > 0; p--)
	{
		h = (int)pow(2.0, (int)p - 1);
		for (int j = 0; j < h; j++)
		
			insertionSortAdaptado(vetor, n, j, h);
	}
}


int main()
{
	Fabricante  vetor[6];

	strcpy(vetor[0].nome, "Fiat");
	strcpy(vetor[0].nacionalidade, "Brasil");
	vetor[0].ano = 2000;

	strcpy(vetor[1].nome, "Fiat");
	strcpy(vetor[1].nacionalidade, "Brasil");
	vetor[1].ano = 1999;

	strcpy(vetor[2].nome, "Fox");
	strcpy(vetor[2].nacionalidade, "Colombia");
	vetor[2].ano = 1998;

	strcpy(vetor[3].nome, "Toyota");
	strcpy(vetor[3].nacionalidade, "Japao");
	vetor[3].ano = 1997;

	strcpy(vetor[4].nome, "Wolskwagen");
	strcpy(vetor[4].nacionalidade, "Coreia");
	vetor[4].ano = 1996;

	strcpy(vetor[5].nome, "Mazda");
	strcpy(vetor[5].nacionalidade, "Paraguai");
	vetor[5].ano = 1995;

	shellSort(vetor, 6, 3);
	escreveVetor(vetor, 6);
	system("pause");
    return 0;
}
