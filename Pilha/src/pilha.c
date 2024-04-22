#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha *criaPilha(int tam){
    
  Pilha *p = malloc(sizeof(Pilha));
  p->topo = 0;
  p->tam = tam;
  p->data = malloc(sizeof(int) * tam);

  return p; 

}

void push(Pilha *p, int x){

  if (p->topo == p->tam){
    printf("Pilha cheia\n");
    return;
  }

  p->data[p->topo] = x;
  p->topo++;

}

int pop(Pilha *p){

  if (p->topo == 0){
    printf("Pilha vazia\n");
    return 0;
  }
  
  int valor = p->data[p->topo];
  p->topo--;

  return valor;

}

int retorna_tamanho(Pilha *p){
  return p->topo;
}

void printa_pilha(Pilha *p){

  for (int i = 0; i < p->topo; i++){
    printf("%d ", p->data[i]);
  }

  printf("\n");

}