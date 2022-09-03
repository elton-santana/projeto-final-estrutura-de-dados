#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void numeroDeLinhasEColunas(char *nomeDoArquivo, int *numeroDeColunas, int *numeroDeLinhas)
{
	FILE *arquivo;
	arquivo = fopen(nomeDoArquivo, "r");

	if (NULL == arquivo)
	{
		printf("Arquivo não pode ser aberto \n");
	}

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

	fclose(arquivo);
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

void printMatrizComRato(int posicaoRatoLinha, int posicaoRatoColuna, int numeroDeLinhas, int numeroDeColunas, char matriz[numeroDeLinhas][numeroDeColunas])
{
	int linhas = numeroDeLinhas;
	int colunas = numeroDeColunas;
	printf("Matriz:\n");
	for (int i = 0; i < linhas; i++)
	{
		for (int j = 0; j < colunas; j++)
		{
			if (i == )
			{
				*posicaoRatoLinha = i;
				*posicaoRatoColuna = j;
			}
			printf("%c ", matriz[i][j]);
		}
		printf("\n");
	}
}

void preencherMatriz(char *nomeDoArquivo, int numeroDeLinhas, int numeroDeColunas, char matriz[numeroDeLinhas][numeroDeColunas])
{
	FILE *arquivo;
	arquivo = fopen(nomeDoArquivo, "r");
	if (NULL == arquivo)
	{
		printf("Arquivo não pode ser aberto \n");
	}

	char caracter;
	char quebraDeLinha = '\n';
	int linha = 0;
	int coluna = 0;

	while (fread(&caracter, sizeof(char), 1, arquivo))
	{
		matriz[linha][coluna] = caracter;
		coluna++;
		if (caracter == quebraDeLinha)
		{
			linha++;
			coluna = 0;
		}
	}

	fclose(arquivo);
}

void irAteEntrada(int *posicaoRatoLinha, int *posicaoRatoColuna, int numeroDeLinhas, int numeroDeColunas, char matriz[numeroDeLinhas][numeroDeColunas])
{
	int linhas = numeroDeLinhas;
	int colunas = numeroDeColunas;
	printf("Matriz:\n");
	for (int i = 0; i < linhas; i++)
	{
		for (int j = 0; j < colunas; j++)
		{
			printf("%c ", matriz[i][j]);
			if (matriz[i][j] == '@')
			{
				*posicaoRatoLinha = i;
				*posicaoRatoColuna = j;
			}
		}
		printf("\n");
	}
}

int main()
{
	char *nomeDoArquivo = "input2.txt";

	int numeroDeLinhas = 0;
	int numeroDeColunas = 0;

	numeroDeLinhasEColunas(nomeDoArquivo, &numeroDeColunas, &numeroDeLinhas);

	char matriz[numeroDeLinhas][numeroDeColunas];

	preencherMatriz(nomeDoArquivo, numeroDeLinhas, numeroDeColunas, matriz);

	printMatriz(numeroDeLinhas, numeroDeColunas, matriz);

	int posicaoRatoLinha = 0;
	int posicaoRatoColuna = 0;

	irAteEntrada(&posicaoRatoLinha, &posicaoRatoColuna, numeroDeLinhas, numeroDeColunas, matriz);

	printf("%d , %d", posicaoRatoLinha, posicaoRatoColuna);

	return 0;
}
