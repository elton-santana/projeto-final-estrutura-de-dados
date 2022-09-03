#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void numeroDeLinhasEColunas(FILE *arquivo, int *numeroDeColunas, int *numeroDeLinhas)
{
	char caracter;
	char quebraDeLinha = '\n';
	int auxQtdeColuna = 0;
	int auxQtdeLinha = 1;

	while (fread(&caracter, sizeof(char), 1, arquivo))
	{
		if (caracter == quebraDeLinha)
			auxQtdeLinha++;
		if (auxQtdeLinha == 1)
			auxQtdeColuna++;
	}
	*numeroDeColunas = auxQtdeColuna;
	*numeroDeLinhas = auxQtdeLinha;
}

void printMatriz(int numeroDeLinhas, int numeroDeColunas, char matriz[numeroDeLinhas][numeroDeColunas])
{
	int linhas = numeroDeLinhas;
	int colunas = numeroDeColunas;
	printf("Matriz:\n");
	for (int i = 0; i < linhas; i++)
	{
		for (int j = 0; j < colunas; j++)
		{
			printf("%c ", matriz[i][j]);
		}
		printf("\n");
	}

	
}

void preencherMatriz(FILE *arquivo, char **matriz, int numeroDeLinhas, int numeroDeColunas)
{
	char c, letra = '\n';
	int linha = 0;
	int coluna = 0;
	while (fread(&c, sizeof(char), 1, arquivo))
	{
		matriz[linha][coluna] = c;
		coluna++;
		if (coluna == numeroDeColunas - 1)
			linha++;
		coluna = 0;

		printf("%c", c);
	}
}

int main()
{
	FILE *arquivo;
	char caracter;

	arquivo = fopen("input2.txt", "r");

	if (NULL == arquivo)
	{
		printf("Arquivo não pode ser aberto \n");
	}

	int numeroDeLinhas = 0;
	int numeroDeColunas = 0;

	numeroDeLinhasEColunas(arquivo, &numeroDeColunas, &numeroDeLinhas);

	printf("\nColunas: %i\n", numeroDeColunas);
	printf("\nLinhas: %i\n", numeroDeLinhas);

	char matriz[numeroDeLinhas][numeroDeColunas];

	// preencherMatriz(arquivo, matriz, numeroDeLinhas, numeroDeColunas);

	for (int i = 0; i < numeroDeLinhas; i++)
	{
		for (int j = 0; j < numeroDeColunas; j++)
		{
			matriz[i][j] = '#';
		}
	}

	printMatriz(numeroDeLinhas, numeroDeColunas, matriz);

	fclose(arquivo);

	return 0;
}
