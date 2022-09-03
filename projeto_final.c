#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void numeroDeLinhasEColunas(FILE *arquivo, int *numeroDeColunas, int *numeroDeLinhas) {
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

// Driver code
int main()
{
	FILE *arquivo;
	char caracter;

	// Opening file in reading mode
	arquivo = fopen("input2.txt", "r");

	if (NULL == arquivo)
	{
		printf("Arquivo não pode ser aberto \n");
	}

	int numeroDeLinhas = 0;   
	int numeroDeColunas = 0; 

    numeroDeLinhasEColunas(arquivo, &numeroDeColunas, &numeroDeLinhas);

	// while (fread(&caracter, sizeof(char), 1, arquivo))
	// {
	// 	if (numeroDeLinhas == 1)
	// 		numeroDeColunas++;
	// 	if (caracter == quebraDeLinha)
	// 	{
	// 		numeroDeLinhas++;
	// 	}
	// }

	printf("\nColunas: %i\n", numeroDeColunas);
	printf("\nLinhas: %i\n", numeroDeLinhas);

	char matrix[numeroDeLinhas][numeroDeColunas];

	for (int i = 0; i < numeroDeLinhas; i++)
	{
		for (int j = 0; j < numeroDeColunas; j++)
		{
			matrix[i][j] = '#';
		}
	}

	// while (fread(&caracter, sizeof(char), 1, arquivo))
	// {
	// 	if (numeroDeLinhas == 1)
	// 		numeroDeColunas++;
	// 	if (caracter == quebraDeLinha)
	// 	{
	// 		numeroDeLinhas++;
	// 	}
	// }

	printf("Matrix:\n");
	for (int i = 0; i < numeroDeLinhas; i++)
	{
		for (int j = 0; j < numeroDeColunas; j++)
		{
			printf("%c ", matrix[i][j]);
		}
		printf("\n");
	}

	fclose(arquivo);

	return 0;
}
