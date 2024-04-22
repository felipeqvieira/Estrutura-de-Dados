#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* inicializa_fila(){

  Fila *f = malloc(sizeof(Fila));

  f->tam = 0;
  f->inicio = NULL;
  f->fim = NULL;

  return f;

}

void insere_fila(Fila *f, int valor){

  No *novo = malloc(sizeof(No));

  novo->dado = valor;
  
  if (f->inicio == NULL){
    f->inicio = novo;
    f->fim = novo;
  } else {
    f->fim->prox = novo;
    f->fim = novo;
  }

  f->tam++;

}

void remove_fila(Fila *f, int valor){

  if (f->inicio == NULL){
    printf("Pilha Vazia!\n");
    return;
  }

  No *aux = f->inicio;

  f->inicio = f->inicio->prox;

  free(aux);

  f->tam--;

}

void printa_fila(Fila *f){

  No *aux = f->inicio;

  while (aux != NULL){
    printf("%d ", aux->dado);
    aux = aux->prox;
  }

  printf("\n");

}