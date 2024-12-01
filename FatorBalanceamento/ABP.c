#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ABP.h"

pNodoA* insereArvore(pNodoA *a, int valor) {
    if(a == NULL) {
        a = (pNodoA*) malloc(sizeof(pNodoA));
        a->info = valor;
        a->dir = NULL;
        a->esq = NULL;
    }

    if(valor > a->info) {
        a->dir = insereArvore(a->dir, valor);
    } else if(valor < a->info) {
        a->esq = insereArvore(a->esq, valor);
    }

    return a;
}

void imprimir(pNodoA* a) {
    if(a!=NULL) {
        printf("%d", a->info);

        imprimir(a->esq);
        imprimir(a->dir);
    }
}

int alturaNodo(pNodoA* a) {
    if(a==NULL){
        return 0;
    }

    return 1 + (alturaNodo(a->dir) > alturaNodo(a->esq) ? alturaNodo(a->dir) : alturaNodo(a->esq));
}

int fatorBalanceamento(pNodoA *a) {
    static int qtdBalanceamento = 0;
    if(a == NULL) {
        return 0;
    }

    if(abs(alturaNodo(a->esq) - alturaNodo(a->dir)) > qtdBalanceamento) {
        qtdBalanceamento = abs(alturaNodo(a->esq) - alturaNodo(a->dir));
    }

    fatorBalanceamento(a->dir);
    fatorBalanceamento(a->esq);

    return qtdBalanceamento;
}