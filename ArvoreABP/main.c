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
    achaMaiorValor(raiz);
    pNodoA* menorValor = achaMenorValor(raiz);
    printf("\nMenor valor: %d\n", menorValor->info);

    //deleteNode(raiz, 2);

    imprimeElementos(raiz);

    printf("\nImprimindo Nivel!\n");

    imprimeNivel(raiz, 2);

    int nivel = acharNivelNodo(raiz, 6);
    
    printf("\n%d\n", nivel);

    int valor = lowestCommonAncestor(raiz, 2, 6);
    printf("Lowest common ancestor");
    printf("\n%d\n", valor);


    int estrBinaria = estritamenteBinaria(raiz);
    printf("\n%d", estrBinaria);

    int repet = repeticoes(raiz, 2);
    printf("\n%d\n", repet);

    int alt = altura(raiz);
    printf("\n%d\n", alt);

    return 0;
}