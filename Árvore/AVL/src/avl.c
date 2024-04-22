#include "avl.h"

No *cria_no(int x){

  No *novo = malloc(sizeof(No));

  if (! novo){
    perror("Erro de alocacao de memoria!\n");
    exit(1);
  }

  novo->numero = x;
  novo->altura = 0;
  novo->esq = NULL;
  novo->dir = NULL;

  return novo;

}

int retorna_maior(int x, int y){

  if(x > y)
    return x;
  else
    return y;

}

int altura_no (No *no){

  if(! no)
    return -1;
  else
    return no->altura;

}

int fator_de_balanceamento(No *no){

  if (no)
    return (altura_no(no->esq) - altura_no(no->dir));

  return 0;

}

No *rotacao_esquerda(No *x){

  No *a, *b;

  a = x->dir;
  b = a->esq;

  a->esq = x;
  x->dir = b;

  x->altura = retorna_maior(altura_no(x->esq), altura_no(x->dir)) + 1;
  a->altura = retorna_maior(altura_no(a->esq), altura_no(a->dir)) + 1;

  return a;

}

No *rotacao_direita(No *x){

  No *a, *b;

  a = x->esq;
  b = a->dir;

  a->dir = x;
  x->esq = b;

  x->altura = retorna_maior(altura_no(x->esq), altura_no(x->dir)) + 1; 
  a->altura = retorna_maior(altura_no(a->esq), altura_no(a->dir)) + 1;

  return a;

}

No *rotacao_esquerda_direita(No *x){

  x->esq = rotacao_esquerda(x->esq);
  return rotacao_direita(x);

}

No *rotacao_direita_esquerda(No *x){

  x->dir = rotacao_direita(x->dir);
  return rotacao_esquerda(x);

}

No *balancear(No *raiz){

  int fb = fator_de_balanceamento(raiz);

  if (fb > 1 && fator_de_balanceamento(raiz->esq) >= 0)
    raiz = rotacao_direita(raiz);

  else if (fb < -1 && fator_de_balanceamento(raiz->dir) <= 0)
    raiz = rotacao_esquerda(raiz);

  else if (fb < -1 && fator_de_balanceamento(raiz->dir) > 0)
    raiz = rotacao_direita_esquerda(raiz);

  else if (fb > 1 && fator_de_balanceamento(raiz->esq) < 0)
    raiz = rotacao_esquerda_direita(raiz);

  return raiz;

}

No *inserir(No *raiz, int x){

  if (! raiz)
    return cria_no(x);
  
  if(x < raiz->numero)
    raiz->esq = inserir(raiz->esq, x);
  else if (x > raiz->numero)
    raiz->dir = inserir(raiz->dir, x);

  raiz->altura = retorna_maior(altura_no(raiz->esq), altura_no(raiz->dir)) + 1;

  raiz = balancear(raiz);

  return raiz;

}

No *remover(No *raiz, int valor){

  if (! raiz){
    perror("Raiz não encontrada!\n");
    return NULL;
  }

  if(raiz->numero == valor){

    if(! raiz->esq && ! raiz->dir){
      free(raiz);
      return NULL;
    }

    if(raiz->esq && raiz->dir){
      
      No *aux = raiz->esq;

      while(aux->dir)
        aux = aux->dir;

      raiz->numero = aux->numero;
      aux->numero = valor;

      raiz->esq = remover(raiz->esq, valor);

      return raiz;
    }
    else{

      No *aux;

      if(raiz->esq)
        aux = raiz->esq;
      else
        aux = raiz->dir;

      free(raiz);

      return aux;

    }

  } else {
    
    if(valor < raiz->numero)
      raiz->esq = remover(raiz->esq, valor);
    else
      raiz->dir = remover(raiz->dir, valor);
  }

  raiz->altura = retorna_maior(altura_no(raiz->esq), altura_no(raiz->dir)) + 1;

  raiz = balancear(raiz);

  return raiz;

}

void imprimir(No *raiz, int nivel){

  if(raiz){
    imprimir(raiz->esq, nivel+1);

    printf("%d,%d\n", raiz->numero, nivel);

    imprimir(raiz->dir, nivel+1);
  }

}

No *remove_avl(No *raiz){

  if(raiz){
    remove_avl(raiz->esq);
    remove_avl(raiz->dir);
    free(raiz);
  }

  return NULL;

}