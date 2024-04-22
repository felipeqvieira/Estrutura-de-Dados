#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 15

/* Definindo estrutura pro nó */
typedef struct no{

  int numero;

  struct no *esq;

  struct no *dir;

  int altura;

}No;

/* Função que cria um nó, recebe o valor do nó e retorna seu endereço */
No *cria_no(int x);

/* Função que recebe dois valores e retorna o maior */
int retorna_maior(int x, int y);

/* Função que retorna a altura do nó */
int altura_no(No *no);

/* Função que retorna o fator de balanceamento do nó */
int fator_de_balanceamento (No *no);

/* Rotação para a esquerda */
No* rotacao_esquerda(No *x);

/* Rotação para a direita */
No* rotacao_direita(No *x);

/* Rotacao dupla (esquerda direita) */
No* rotacao_esquerda_direita(No *x);

/* Rotacao dupla (direita esquerda) */
No* rotacao_direita_esquerda(No *x);

/* Função que balanceia a árvore após uma modificação na mesma, recebe o nó desbalanceado e retorna uma nova raiz */
No* balancear(No *raiz);

/* Recebe uma raiz e um valor e cria um novo nó com base nos dados recebidos, retorna o endereço do nó ou uma nova raiz */
No* inserir (No *raiz, int x);

/* Remove um nó da árvore e retorna a raiz para balanceamento */
No* remover(No *raiz, int valor);

/* Função que imprime a árvore */
void imprimir(No *raiz, int nivel);

/* Função que dá free na árvore */
No *remove_avl(No *raiz);