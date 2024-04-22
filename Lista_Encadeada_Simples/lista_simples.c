#include <stdio.h>
#include <stdlib.h>
#include "lista_simples.h"

Lista* inicializa_lista(){

  Lista *l = malloc(sizeof(Lista));

  l->tam = 0;
  l->inicio = NULL;
  l->fim = NULL;

  return l;

}

Lista* insereInicio(Lista *l, int valor){
  
    No *novo = malloc(sizeof(No));
  
    novo->dado = valor;
    novo->prox = NULL;
  
    if (l->inicio == NULL){
      l->inicio = novo;
      l->fim = novo;
    } else {
      novo->prox = l->inicio;
      l->inicio = novo;
    }
  
    l->tam++;
  
    return l;

}

Lista* insereFim(Lista *l, int valor){
  
    No *novo = malloc(sizeof(No));
  
    novo->dado = valor;
    novo->prox = NULL;
  
    if (l->inicio == NULL){
      l->inicio = novo;
      l->fim = novo;
    } else {
      l->fim->prox = novo;
      l->fim = novo;
    }
  
    l->tam++;
  
    return l;

}

Lista* inserePosicao(Lista *l, int valor, int posicao){

  if (posicao == 0 && posicao < l->tam-1){
    insereInicio(l, valor);
  } else if (posicao == l->tam-1){
    insereFim(l, valor);
  } else {

    No *novo = malloc(sizeof(No));

    novo->dado = valor;

    No *aux = l->inicio;

    for (int i = 0; i < posicao-1; i++){
      aux = aux->prox;
    }
    
    novo->prox = aux->prox;
    aux->prox = novo;
  }

  l->tam++;

  return l;

}

Lista* removeInicio(Lista *l){
  
  if (l->inicio == NULL){
    printf("Lista Vazia!\n");
    return l;
  }

  No *aux = l->inicio;

  l->inicio = l->inicio->prox;

  free(aux);

  l->tam--;

  return l;

}

Lista* removeFim(Lista *l){

  if (l->inicio == NULL){
    printf("Lista Vazia!\n");
    return l;
  }

  No *aux = l->inicio;

  while (aux->prox != l->fim){
    aux = aux->prox;
  }

  free(l->fim);

  l->fim = aux;
  l->fim->prox = NULL;

  l->tam--;

  return l;

}

Lista* removePosicao(Lista *l, int posicao){

  if (l->inicio == NULL){
    printf("Lista Vazia!\n");
    return l;
  }

  if (posicao == 0){
    l = removeInicio(l);
  } else if (posicao == l->tam - 1){
    l = removeFim(l);
  } else {

    No *aux = l->inicio;

    for (int i = 0; i < posicao-1; i++){
      aux = aux->prox;
    }

    No *aux2 = aux->prox;

    aux->prox = aux2->prox;

    free(aux2);

    l->tam--;

  }

  return l;

}

int buscaValor(Lista *l, int valor){

  No *aux = l->inicio;

  while (aux != NULL){

    if (aux->dado == valor)
      return 1;

    aux = aux->prox;
  }

  return 0;

}

void printa_lista(Lista *l){

  No *aux = l->inicio;

  while (aux != NULL){
    printf("%d ", aux->dado);
    aux = aux->prox;
  }

  printf("\n");

}

void libera_lista(Lista *l){

  while (l->inicio != NULL){
    removeInicio(l);
  }

  free(l);

}