#include <stdio.h>
#include <stdlib.h>
#include "ABP.h"

int main() {
    int contador = 0;
    pNodoA *raiz = NULL;

    // Inserindo elementos na árvore
    raiz = InsereArvore(raiz, 8);
    raiz = InsereArvore(raiz, 4);
    raiz = InsereArvore(raiz, 9);
    raiz = InsereArvore(raiz, 2);
    raiz = InsereArvore(raiz, 6);
    raiz = InsereArvore(raiz, 1);

    // Imprimindo elementos da árvore
    printf("Elementos da árvore em pré-ordem:\n");
    imprimeElementos(raiz);

    imprimeElementosOrdemCrescente(raiz);

    return 0;
}