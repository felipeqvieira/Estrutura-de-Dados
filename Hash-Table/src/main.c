#include "hash.h"

int main(){

  char escolha;
  char *escolha2;
  char buf[MAX];

  int valor;
  int *t1 = malloc(sizeof(int)*m);

  if(! t1){
    printf("Erro de alocacao de memoria\n");
    exit(1);
  }

  int *t2 = malloc(sizeof(int)*m);

  if(! t2){
    printf("Erro de alocacao de memoria\n");
    exit(1);
  }

  for(int i = 0; i < m; i++){
    t1[i] = -1;
    t2[i] = -1;
  }

  while(fgets(buf,MAX,stdin) != NULL){

    escolha = buf[0];

    escolha2 = malloc(sizeof(char)*(MAX-2));

    memcpy(escolha2, buf+2, MAX-2);

    valor = atoi(escolha2);

    if(escolha == 'i')
      inserir(t1,t2,valor);
    else if (escolha == 'r')
      remover(t1,t2,valor);

    free(escolha2);
  }

  imprimir(t1,t2);

  free(t1);
  free(t2);

  return 0;
}