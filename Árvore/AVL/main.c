#include "avl.h"

int main(){

  char escolha;
  char *escolha2;
  char buf[MAX];

  int valor;

  No *raiz = NULL;

  while(fgets(buf,MAX,stdin) != NULL){

    escolha = buf[0];

    escolha2 = malloc(sizeof(char)*(MAX-2));

    memcpy(escolha2, buf+2, MAX-2);

    valor = atoi(escolha2);

    if (escolha == 'i'){
      raiz = inserir(raiz,valor);
    } else if(escolha == 'r'){
      raiz = remover(raiz,valor);
    }

    free(escolha2);

  }

  imprimir(raiz, 0);

  remove_avl(raiz);

  return 0;
  
}