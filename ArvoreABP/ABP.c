#include <stdio.h>
#include <stdlib.h>
#include "ABP.h"

pNodoA *InsereArvore(pNodoA *a, int ch)
{
    if (a == NULL)
    {
        a = (pNodoA *)malloc(sizeof(pNodoA));
        a->info = ch;
        a->esq = NULL;
        a->dir = NULL;
    }
    else if (ch < a->info)
        a->esq = InsereArvore(a->esq, ch);
    else
        a->dir = InsereArvore(a->dir, ch);
    return a;
}

void imprimeElementos(pNodoA *a) {
    static int contador = 0;
    if(a != NULL) {
        contador++;
        for(int i = 0; i<contador; i++) {
            printf("=");
        }
        printf("%d\n", a->info);

        imprimeElementos(a->esq);
        imprimeElementos(a->dir);

        contador--;
    }
}

void imprimeElementosOrdemCrescente(pNodoA *a) {
    if(a!=NULL) {
        imprimeElementosOrdemCrescente(a->esq);
        printf("%d\n", a->info);
        imprimeElementosOrdemCrescente(a->dir);
    }
    
}

int consultaABP(pNodoA *a, int chave) {
    if(a!=NULL){
        if(a->info == chave) {
            return 1;
        } else if(a->info > chave) {
            consultaABP(a->esq, chave);
        } else {
            consultaABP(a->dir, chave);
        }

        return NULL;
    }
}