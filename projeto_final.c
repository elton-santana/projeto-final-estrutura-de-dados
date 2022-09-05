#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 

struct Posicao
{
	int linha;
	int coluna;
};

struct Rato
{
	struct Posicao *posicao_atual;
	struct Posicao *norte;
	struct Posicao *sul;
	struct Posicao *leste;
	struct Posicao *oeste;
	char direitaDoRato;
};

void printInfoRato(struct Rato *rato)
{
	printf("posicao_atual->linha: %d\n", rato->posicao_atual->linha);
	printf("posicao_atual->coluna: %d\n", rato->posicao_atual->coluna);
	printf("norte->linha: %d\n", rato->norte->linha);
	printf("norte->coluna: %d\n", rato->norte->coluna);
	printf("sul->linha: %d\n", rato->sul->linha);
	printf("sul->coluna: %d\n", rato->sul->coluna);
	printf("leste->linha: %d\n", rato->leste->linha);
	printf("leste->coluna: %d\n", rato->leste->coluna);
	printf("oeste->linha: %d\n", rato->oeste->linha);
	printf("oeste->coluna: %d\n", rato->oeste->coluna);
	printf("direita do rato: %c\n", rato->direitaDoRato);
}

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

void printMatriz(int qtdDePassos, struct Posicao *posicaoRato, int numeroDeLinhas, int numeroDeColunas, char matriz[numeroDeLinhas][numeroDeColunas])
{
	int linhas = numeroDeLinhas;
	int colunas = numeroDeColunas;
	printf("Ciclo número: %d \n", qtdDePassos);
	for (int i = 0; i < linhas; i++)
	{
		for (int j = 0; j < colunas; j++)
		{
			if ((posicaoRato != NULL) && (i == posicaoRato->linha) && (j == posicaoRato->coluna))
			{
				printf("o");
			}
			else
			{
				printf("%c", matriz[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
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

void setarInfoRato(struct Rato *rato, struct Posicao *posicaoRato)
{
	int linha = posicaoRato->linha;
	int coluna = posicaoRato->coluna;

	rato->posicao_atual = posicaoRato;

	struct Posicao *posicaoNorte = (struct Posicao *)malloc(sizeof(struct Posicao));
	*posicaoNorte = *posicaoRato;
	rato->norte = posicaoNorte;
	rato->norte->linha--;

	struct Posicao *posicaoSul = (struct Posicao *)malloc(sizeof(struct Posicao));
	*posicaoSul = *posicaoRato;
	rato->sul = posicaoSul;
	rato->sul->linha++;

	struct Posicao *posicaoOeste = (struct Posicao *)malloc(sizeof(struct Posicao));
	*posicaoOeste = *posicaoRato;
	rato->oeste = posicaoOeste;
	rato->oeste->coluna--;

	struct Posicao *posicaoLeste = (struct Posicao *)malloc(sizeof(struct Posicao));
	*posicaoLeste = *posicaoRato;
	rato->leste = posicaoLeste;
	rato->leste->coluna++;
}

void setarDireitaInicialDoRato(struct Rato *rato, int numeroDeLinhas, int numeroDeColunas)
{
	struct Posicao *posicaoRato = (struct Posicao *)malloc(sizeof(struct Posicao));
	posicaoRato = rato->posicao_atual;

	if (posicaoRato->linha == 0)
	{
		rato->direitaDoRato = 'o';
	}
	else if (posicaoRato->linha == numeroDeLinhas - 1)
	{
		rato->direitaDoRato = 'l';
	}
	else if (posicaoRato->coluna == 0)
	{
		rato->direitaDoRato = 's';
	}
	else if (posicaoRato->coluna == numeroDeColunas - 1)
	{
		rato->direitaDoRato = 'n';
	}
}

void iniciar(struct Rato *rato, int numeroDeLinhas, int numeroDeColunas, char matriz[numeroDeLinhas][numeroDeColunas])
{
	int linhas = numeroDeLinhas;
	int colunas = numeroDeColunas;

	struct Posicao *posicaoInicial = (struct Posicao *)malloc(sizeof(struct Posicao));

	for (int l = 0; l < linhas; l++)
	{
		for (int c = 0; c < colunas; c++)
		{
			if (matriz[l][c] == '@')
			{
				posicaoInicial->linha = l;
				posicaoInicial->coluna = c;
				setarInfoRato(rato, posicaoInicial);
				setarDireitaInicialDoRato(rato, numeroDeLinhas, numeroDeColunas);
				printMatriz(1, posicaoInicial, numeroDeLinhas, numeroDeColunas, matriz);
				return;
			}
		}
	}
}

void percorrerLabirinto(struct Rato *rato, int numeroDeLinhas, int numeroDeColunas, char matriz[numeroDeLinhas][numeroDeColunas])
{
	int qtdeDecisoes = 0;
	int qtdeDeAcessos = 1;
	int qtdDePassos = 1;

	int fim = 0;

	char casaAtual = matriz[rato->posicao_atual->linha][rato->posicao_atual->coluna];
	char leste = matriz[rato->leste->linha][rato->leste->coluna];
	char norte = matriz[rato->norte->linha][rato->norte->coluna];
	char oeste = matriz[rato->oeste->linha][rato->oeste->coluna];
	char sul = matriz[rato->sul->linha][rato->sul->coluna];
	char posicaoFim;
	char direitaDoRato = rato->direitaDoRato;
	char caminhoPreferido = direitaDoRato;
	printf("%c", caminhoPreferido);

	while (!fim)
	{	
		if (norte == '$')
		{
			fim = 1;
			posicaoFim = norte;
			qtdDePassos++;
			rato->posicao_atual->linha--;
			printMatriz(qtdDePassos, rato->posicao_atual, numeroDeLinhas, numeroDeColunas, matriz);
			printf("fim!");
		}
		else if (oeste == '$')
		{
			fim = 1;
			qtdDePassos++;
			rato->posicao_atual->coluna--;
			printMatriz(qtdDePassos, rato->posicao_atual, numeroDeLinhas, numeroDeColunas, matriz);
			printf("fim!");
		}
		else if (sul == '$')
		{
			fim = 1;
			qtdDePassos++;
			rato->posicao_atual->linha++;
			printMatriz(qtdDePassos, rato->posicao_atual, numeroDeLinhas, numeroDeColunas, matriz);
			printf("fim!");
		}
		else if (leste == '$')
		{
			fim = 1;
			qtdDePassos++;
			rato->posicao_atual->coluna++;
			printMatriz(qtdDePassos, rato->posicao_atual, numeroDeLinhas, numeroDeColunas, matriz);
			printf("fim!");
		}

		if (caminhoPreferido == 'n')
		{
			if (norte != '#')
			{
				qtdDePassos++;
				rato->posicao_atual->linha--;
				rato->direitaDoRato = 'l';
				caminhoPreferido = rato->direitaDoRato;
				setarInfoRato(rato, rato->posicao_atual);
				leste = matriz[rato->leste->linha][rato->leste->coluna];
				norte = matriz[rato->norte->linha][rato->norte->coluna];
				oeste = matriz[rato->oeste->linha][rato->oeste->coluna];
				sul = matriz[rato->sul->linha][rato->sul->coluna];
				printMatriz(qtdDePassos, rato->posicao_atual, numeroDeLinhas, numeroDeColunas, matriz);
			}
			else
			{
				caminhoPreferido = 'o';
			}
		}
		else if (caminhoPreferido == 'o')
		{
			if (oeste != '#')
			{
				qtdDePassos++;
				rato->posicao_atual->coluna--;
				rato->direitaDoRato = 'n';
				caminhoPreferido = rato->direitaDoRato;
				setarInfoRato(rato, rato->posicao_atual);
				leste = matriz[rato->leste->linha][rato->leste->coluna];
				norte = matriz[rato->norte->linha][rato->norte->coluna];
				oeste = matriz[rato->oeste->linha][rato->oeste->coluna];
				sul = matriz[rato->sul->linha][rato->sul->coluna];
				printMatriz(qtdDePassos, rato->posicao_atual, numeroDeLinhas, numeroDeColunas, matriz);
			}
			else
			{
				caminhoPreferido = 's';
			}
		}
		else if (caminhoPreferido == 's')
		{
			if (sul != '#')
			{
				qtdDePassos++;
				rato->posicao_atual->linha++;
				rato->direitaDoRato = 'o';
				caminhoPreferido = rato->direitaDoRato;
				setarInfoRato(rato, rato->posicao_atual);
				leste = matriz[rato->leste->linha][rato->leste->coluna];
				norte = matriz[rato->norte->linha][rato->norte->coluna];
				oeste = matriz[rato->oeste->linha][rato->oeste->coluna];
				sul = matriz[rato->sul->linha][rato->sul->coluna];
				printMatriz(qtdDePassos, rato->posicao_atual, numeroDeLinhas, numeroDeColunas, matriz);
			}
			else
			{
				caminhoPreferido = 'l';
			}
		}
		else if (caminhoPreferido == 'l')
		{
			if (leste != '#')
			{

				qtdDePassos++;
				rato->posicao_atual->coluna++;
				rato->direitaDoRato = 's';
				caminhoPreferido = rato->direitaDoRato;
				setarInfoRato(rato, rato->posicao_atual);
				leste = matriz[rato->leste->linha][rato->leste->coluna];
				norte = matriz[rato->norte->linha][rato->norte->coluna];
				oeste = matriz[rato->oeste->linha][rato->oeste->coluna];
				sul = matriz[rato->sul->linha][rato->sul->coluna];
				printMatriz(qtdDePassos, rato->posicao_atual, numeroDeLinhas, numeroDeColunas, matriz);
			}
			else
			{
				caminhoPreferido = 'n';
			}
		}
		usleep(500000);
	}
}

int main(int argc, char *argv[])
{
	printf("Rato vai andar sobre o labirinto do arquivo: %s \n", argv[1]);
	char *nomeDoArquivo = argv[1];

	int numeroDeLinhas = 0;
	int numeroDeColunas = 0;

	numeroDeLinhasEColunas(nomeDoArquivo, &numeroDeColunas, &numeroDeLinhas);

	char matriz[numeroDeLinhas][numeroDeColunas];

	preencherMatriz(nomeDoArquivo, numeroDeLinhas, numeroDeColunas, matriz);

	struct Rato *rato = (struct Rato *)malloc(sizeof(struct Rato));

	iniciar(rato, numeroDeLinhas, numeroDeColunas, matriz);

	percorrerLabirinto(rato, numeroDeLinhas, numeroDeColunas, matriz);

	return 0;
}
