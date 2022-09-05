# Estratégia de Resolução

## Matriz

O primeiro passo é transformar o conteudo do arquivo num vetor de vetores para ficar mais fácil percorre-lo.

Por exemplo para um arquivo com esse conteudo:
```
####$#
@****#
#*##*#
#****#
######
```

Transformamos em:

```
[['#','#','#','#','$','#'],
['@','*','*','*','*','#']
['#','*','#','#','*','#']
['#','*','*','*','*','#']
['#','#','#','#','#','#']]
```

para percorrermos com indices `matriz[x][y]` sendo que x é a linha e y é a coluna.

## Como o rato anda?

`Ele sempre prefere ir para direita`

Como assim?

1. Ele vai até o ponto de partida.
2. Ele calcula qual a direita dele.
    * se ele veio do norte, a usa direita é o oeste.
    * se ele veio do sul, a usa direita é o leste.
    * se ele veio do oeste, a usa direita é o sul.
    * se ele veio do leste, a usa direita é o norte.
3. Se a direita for um passo possível, vamos a direita.
4. Se a frente for um passo possível, vamos a frente.
5. Se a esquerda for um passo possível, vamos a esquerda.
6. Se atrás for um passo possível, vamos atrás.
7. voltamos ao passo 2.

