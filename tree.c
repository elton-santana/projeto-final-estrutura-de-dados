#include <stdlib.h>
#include <stdio.h>

struct Posicao
{
    int linha;
    int coluna;
    struct Posicao *cima;
    struct Posicao *baixo;
    struct Posicao *direita;
    struct Posicao *esquerda;
};

enum Direcao {cima, baixo, direita, esquerda};

struct Posicao *root = NULL;

void insert(struct Posicao *posicao, struct Posicao *posicaoAnterior, int linha, int coluna, enum Direcao direcao)
{
    posicao = (struct Posicao *)malloc(sizeof(struct Posicao));
    posicao->linha = linha;
    posicao->coluna = coluna;
    posicao->cima = NULL;
    posicao->esquerda = NULL;
    posicao->direita = NULL;
    posicao->baixo = NULL;

    switch(direcao)
    {
    case cima:
    posicaoAnterior->cima = posicao;
    break;
    case baixo:
    posicaoAnterior->baixo = posicao;
    break;
    case direita:
    posicaoAnterior->direita = posicao;
    break;
    case esquerda:
    posicaoAnterior->esquerda = posicao;
    break;
    }
}

int search(struct Node *node, int info)
{
    if (node != NULL)
    {
        if (info == node->info)
        {
            return 1;
        }
        else if (info < node->info)
        {
            return search(node->left, info);
        }
        else
        {
            return search(node->right, info);
        }
    }
    else
    {
        return 0;
    }
}

void orderList(struct Node *node)
{
    if (node != NULL)
    {
        orderList(node->left);
        printf("%d ", node->info);
        orderList(node->right);
    }
}

void listPreOrder(struct Node *node)
{
    if (node != NULL)
    {
        printf("%d ", node->info);
        listPreOrder(node->left);
        listPreOrder(node->right);
    }
}

void listPostOrder(struct Node *node)
{
    if (node != NULL)
    {
        listPostOrder(node->left);
        listPostOrder(node->right);
        printf("%d ", node->info);
    }
}

void blankSpace(int amount)
{
    for (int i; i <= amount; i++)
    {
        printf(" ");
    }
}

int maxHeight(struct Node *node)
{
    if (node == NULL)
        return -1;
    else
    {
        int leftHeight = maxHeight(node->left);
        int rightHeight = maxHeight(node->right);

        if (leftHeight > rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}

void showNodes(struct Node *node)
{
    if (node != NULL)
    {
        int height = maxHeight(node);
        for (int i = 0; i <= height; i++)
        {
            printf("  ");
        }
        printf("\n nivel: %d ", height);
        printf("%d ", node->info);
        showNodes(node->left);
        showNodes(node->right);
    }
}

void height()
{
    printf("-----------------------------------------");
    printf("\n");
    printf("Altura: %d", maxHeight(root));
    printf("\n");
    printf("-----------------------------------------");
    printf("\n");
}

void prettyPrint()
{
    printf("-----------------------------------------");
    printf("\n");
    printf(" Pretty print \n \n");
    showNodes(root);
    printf("\n");
    printf("-----------------------------------------");
    printf("\n");
}

int main(int argc, char const *argv[])
{
    // 6, 2, 8, 1, 4, 3
    height();
    prettyPrint();

    insert(&root, 6);
    orderList(root);
    printf("\n");

    height();
    prettyPrint();

    insert(&root, 2);
    orderList(root);
    printf("\n");

    height();
    prettyPrint();

    insert(&root, 8);
    orderList(root);
    printf("\n");

    height();
    prettyPrint();

    insert(&root, 1);
    orderList(root);
    printf("\n");

    insert(&root, 4);
    orderList(root);
    printf("\n");

    insert(&root, 3);
    orderList(root);
    printf("\n");

    listPreOrder(root);
    printf("\n");

    listPostOrder(root);
    printf("\n");

    printf("%d \n", search(root, 2));
    printf("%d \n", search(root, 3));

    height();

    prettyPrint();

    return 0;
}