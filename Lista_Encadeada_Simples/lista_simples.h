typedef struct no{

  struct no *prox;
  int dado;

}No;

typedef struct lista{

  No *inicio;
  No *fim;
  int tam;

}Lista;
