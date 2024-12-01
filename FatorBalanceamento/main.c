#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ABP.h"

int main()
{
    pNodoA* arvoreA = NULL;
    pNodoA* arvoreB = NULL;
    pNodoA* arvoreC = NULL;
    pNodoA* arvoreD = NULL;

    int valoresA[] = {12, 8, 20, 4, 10, 18, 26, 2, 6, 9, 11, 14, 19, 22, 28};
    int valoresB[] = {12, 8, 20, 4, 10, 18, 26, 2, 6, 9, 11, 14, 19, 22};
    int valoresC[] = {12, 8, 20, 4, 10, 18, 2, 6, 11, 14, 19};
    int valoresD[] = {12, 20, 18, 14, 19};

    for (int i = 0; i < 15; i++) arvoreA = insereArvore(arvoreA, valoresA[i]);
    for (int i = 0; i < 14; i++) arvoreB = insereArvore(arvoreB, valoresB[i]);
    for (int i = 0; i < 11; i++) arvoreC = insereArvore(arvoreC, valoresC[i]);
    for (int i = 0; i < 5; i++) arvoreD = insereArvore(arvoreD, valoresD[i]);

    printf("Arvore A:\n");
    imprimir(arvoreA);
    printf("Fator A: %d\n\n", abs(fatorBalanceamento(arvoreA)));

    printf("Arvore B:\n");
    imprimir(arvoreB);
    printf("Fator B: %d\n\n", abs(fatorBalanceamento(arvoreB)));

    printf("Arvore C:\n");
    imprimir(arvoreC);
    printf("Fator C: %d\n\n", abs(fatorBalanceamento(arvoreC)));

    printf("Arvore D:\n");
    imprimir(arvoreD);
    printf("Fator D: %d\n\n", abs(fatorBalanceamento(arvoreD)));
    return 0;
}