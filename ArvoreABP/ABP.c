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

pNodoA* insereNodo(pNodoA *a, int chave) {
    if(a == NULL) {
        pNodoA* novoNodo = (pNodoA*) malloc(sizeof(pNodoA));
        novoNodo->info = chave;
        novoNodo->dir = NULL;
        novoNodo->esq = NULL;

        a = novoNodo;
    } else {
        if(chave < a->info) {
            insereNodo(a->esq, chave);
        } else {
            insereNodo(a->dir, chave);
        }
    }

    return a;
}


pNodoA* achaMaiorValor(pNodoA *a){
    if (a == NULL) {
        printf("A árvore está vazia.\n");
        return NULL;
    }

    if(a->dir == NULL){
        printf("Maior valor: %d", a->info);
        return a;
    }


    return achaMaiorValor(a->dir);
}

pNodoA* deleteNode(pNodoA *a, int chave) {
    if (a == NULL) {
        printf("Nenhum nodo foi deletado!\n");
        return NULL;
    }

    if (chave < a->info) {
        // Procure o nó na subárvore esquerda
        a->esq = deleteNode(a->esq, chave);
    } else if (chave > a->info) {
        // Procure o nó na subárvore direita
        a->dir = deleteNode(a->dir, chave);
    } else {
        // Nó encontrado
        if (a->esq == NULL && a->dir == NULL) {
            // Caso 1: Nó folha
            free(a);
            return NULL;
        } else if (a->esq == NULL) {
            // Caso 2: Apenas filho direito
            pNodoA *temp = a->dir;
            free(a);
            return temp;
        } else if (a->dir == NULL) {
            // Caso 2: Apenas filho esquerdo
            pNodoA *temp = a->esq;
            free(a);
            return temp;
        } else {
            // Caso 3: Dois filhos
            // Encontre o menor valor da subárvore direita (sucessor)
            pNodoA *temp = achaMenorValor(a->dir);
            a->info = temp->info; // Substitua o valor do nó atual
            a->dir = deleteNode(a->dir, temp->info); // Remova o sucessor
        }
    }

    return a; // Retorne o nó atualizado
}

// Função auxiliar para encontrar o menor valor
pNodoA* achaMenorValor(pNodoA *a) {
    while (a->esq != NULL) {
        a = a->esq;
    }
    return a;
}

int count2 = 0; // Variável global para rastrear o nível atual.

void imprimeNivel(pNodoA *a, int k) {
    if (a != NULL) {
        // Incrementa o contador antes de visitar o nó atual.
        count2++;

        // Se estamos no nível desejado, imprime o valor.
        if (count2 == k) {
            printf("%d ", a->info);
        }

        // Percorre a subárvore direita.
        imprimeNivel(a->dir, k);

        // Percorre a subárvore esquerda.
        imprimeNivel(a->esq, k);

        // Ao sair do nó, decrementa o contador.
        count2--;
    }
}

int lowestCommonAncestor(pNodoA *a, int valor01, int valor02) {
    if(a!=NULL) {
        if(valor01 > a->info && valor02 > a->info) {
            lowestCommonAncestor(a->dir, valor01, valor02);
        } else if(valor01 < a->info && valor02 < a->info) {
            lowestCommonAncestor(a->esq, valor01, valor02);
        } else {
            return a->info;
        }

    }
}

int estritamenteBinaria(pNodoA *a) {
    if(a==NULL){
        return 1;
    }

    if((a->dir != NULL && a->esq != NULL) || (a->dir == NULL && a->esq == NULL)) {
        return estritamenteBinaria(a->dir) && estritamenteBinaria(a->esq);
    } else {
        return 0;
    }

}

int repeticoes(pNodoA *a, int valor) {
    if(a==NULL) {
        return 0;
    }
    int qtd=0;
    if(valor == a->info) {
        qtd=1;
    }

    return qtd+repeticoes(a->esq, valor) + repeticoes(a->dir, valor);
}

int altura(pNodoA *a) {
    if(a==NULL){
        return 0;
    }

    return 1 + (altura(a->dir) > altura(a->esq)? altura(a->dir) : altura(a->esq));
}

int acharNivelNodo(pNodoA *a, int valor) {
    if(a == NULL) {
        return 0;
    }
    
    if(valor < a->info) {
        return 1 + acharNivelNodo(a->esq, valor);
    } else if(valor > a->info) {
        return 1 + acharNivelNodo(a->dir, valor);
    } else {
        return 1;
    }
}