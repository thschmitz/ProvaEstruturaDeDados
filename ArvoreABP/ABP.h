typedef struct TNodoA{
   int info;
   struct TNodoA *esq;
   struct TNodoA *dir;
} pNodoA;

pNodoA* InsereArvore(pNodoA *a, int ch);
void imprimeElementos(pNodoA *a);
void imprimeElementosOrdemCrescente(pNodoA *a);
void consultABP(pNodoA *a, int chave);