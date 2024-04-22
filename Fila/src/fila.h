typedef struct no{

  int dado;
  struct no *prox;

}No;

typedef struct fila{
  
  int tam;
  No *inicio;
  No *fim;

}Fila;

Fila* inicializa_fila();
void insere_fila(Fila *f, int valor);
void remove_fila(Fila *f, int valor);
void printa_fila(Fila *f);
