typedef struct s_NodoA {
    int info;
    struct s_NodoA *esq;
    struct s_NodoA *dir;
} pNodoA;


pNodoA* insereArvore(pNodoA *a, int valor);
void imprimir(pNodoA* a);
int alturaNodo(pNodoA* a);
int fatorBalanceamento(pNodoA *a);