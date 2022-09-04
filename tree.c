// #include <stdlib.h>
// #include <stdio.h>

// struct Posicao
// {
//     int linha;
//     int coluna;
//     struct Posicao *norte;
//     struct Posicao *sul;
//     struct Posicao *leste;
//     struct Posicao *oeste;
// };

// enum Direcao {norte, sul, leste, oeste};

// struct Posicao *root = NULL;

// void insert(struct Posicao *posicao, struct Posicao *posicaoAnterior, int linha, int coluna, enum Direcao direcao)
// {
//     posicao = (struct Posicao *)malloc(sizeof(struct Posicao));
//     posicao->linha = linha;
//     posicao->coluna = coluna;
//     posicao->norte = NULL;
//     posicao->oeste = NULL;
//     posicao->leste = NULL;
//     posicao->sul = NULL;

//     switch(direcao)
//     {
//     case norte:
//     posicaoAnterior->norte = posicao;
//     break;
//     case sul:
//     posicaoAnterior->sul = posicao;
//     break;
//     case leste:
//     posicaoAnterior->leste = posicao;
//     break;
//     case oeste:
//     posicaoAnterior->oeste = posicao;
//     break;
//     }
// }

// int search(struct Posicao *posicao, int linha, int coluna)
// {
//     if (posicao != NULL)
//     {
//         if (linha == posicao->linha && linha == posicao->coluna)
//         {
//             return 1;
//         }
//         else
//         {
//             return search(posicao->norte, linha, coluna);
//             return search(posicao->sul, linha, coluna);
//             return search(posicao->leste, linha, coluna);
//             return search(posicao->oeste, linha, coluna);
//         }
//     }
//     else
//     {
//         return 0;
//     }
// }

// void orderList(struct Posicao *posicao)
// {
//     if (posicao != NULL)
//     {
//         orderList(posicao->left);
//         printf("%d ", posicao->info);
//         orderList(posicao->right);
//     }
// }

// void listPreOrder(struct Posicao *posicao)
// {
//     if (posicao != NULL)
//     {
//         printf("%d ", posicao->info);
//         listPreOrder(posicao->left);
//         listPreOrder(posicao->right);
//     }
// }

// void listPostOrder(struct Posicao *posicao)
// {
//     if (posicao != NULL)
//     {
//         listPostOrder(posicao->left);
//         listPostOrder(posicao->right);
//         printf("%d ", posicao->info);
//     }
// }

// void blankSpace(int amount)
// {
//     for (int i; i <= amount; i++)
//     {
//         printf(" ");
//     }
// }

// int maxHeight(struct Posicao *posicao)
// {
//     if (posicao == NULL)
//         return -1;
//     else
//     {
//         int leftHeight = maxHeight(posicao->left);
//         int rightHeight = maxHeight(posicao->right);

//         if (leftHeight > rightHeight)
//             return (leftHeight + 1);
//         else
//             return (rightHeight + 1);
//     }
// }

// void showNodes(struct Posicao *posicao)
// {
//     if (posicao != NULL)
//     {
//         int height = maxHeight(posicao);
//         for (int i = 0; i <= height; i++)
//         {
//             printf("  ");
//         }
//         printf("\n nivel: %d ", height);
//         printf("%d ", posicao->info);
//         showNodes(posicao->left);
//         showNodes(posicao->right);
//     }
// }

// void height()
// {
//     printf("-----------------------------------------");
//     printf("\n");
//     printf("Altura: %d", maxHeight(root));
//     printf("\n");
//     printf("-----------------------------------------");
//     printf("\n");
// }

// void prettyPrint()
// {
//     printf("-----------------------------------------");
//     printf("\n");
//     printf(" Pretty print \n \n");
//     showNodes(root);
//     printf("\n");
//     printf("-----------------------------------------");
//     printf("\n");
// }

// int main(int argc, char const *argv[])
// {
//     // 6, 2, 8, 1, 4, 3
//     height();
//     prettyPrint();

//     insert(&root, 6);
//     orderList(root);
//     printf("\n");

//     height();
//     prettyPrint();

//     insert(&root, 2);
//     orderList(root);
//     printf("\n");

//     height();
//     prettyPrint();

//     insert(&root, 8);
//     orderList(root);
//     printf("\n");

//     height();
//     prettyPrint();

//     insert(&root, 1);
//     orderList(root);
//     printf("\n");

//     insert(&root, 4);
//     orderList(root);
//     printf("\n");

//     insert(&root, 3);
//     orderList(root);
//     printf("\n");

//     listPreOrder(root);
//     printf("\n");

//     listPostOrder(root);
//     printf("\n");

//     printf("%d \n", search(root, 2));
//     printf("%d \n", search(root, 3));

//     height();

//     prettyPrint();

//     return 0;
// }