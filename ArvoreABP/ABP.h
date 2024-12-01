typedef struct TNodoA{
   int info;
   struct TNodoA *esq;
   struct TNodoA *dir;
} pNodoA;

pNodoA* InsereArvore(pNodoA *a, int ch);
void imprimeElementos(pNodoA *a);
void imprimeElementosOrdemCrescente(pNodoA *a);
int consultaABP(pNodoA *a, int chave);
pNodoA* insereNodo(pNodoA *a, int chave);
pNodoA* achaMaiorValor(pNodoA *a);
pNodoA* achaMenorValor(pNodoA *a);
pNodoA* deleteNode(pNodoA *a, int chave);
void imprimeNivel(pNodoA *a, int k);
int acharNivelNodo(pNodoA *a, int valor);
int lowestCommonAncestor(pNodoA *a, int valor01, int valor02);
int estritamenteBinaria(pNodoA *a);
int repeticoes(pNodoA *a, int valor);
int altura(pNodoA *a);