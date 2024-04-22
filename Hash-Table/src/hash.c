#include "hash.h"

int h1 (int k){
  return k % m;
}

int h2 (int k){
  float h2 = floor(k*0.9);
  h2 = m * (k*0.9 - h2);

  return floor(h2);
}

void inserir(int t1[], int t2[], int valor){

  int valorh1 = h1(valor);
 
  if (t1[valorh1] == -1 || t1[valorh1] == 999){
  
    t1[valorh1] = valor;

  } else {

    t2[h2(t1[valorh1])] = t1[valorh1];
    t1[valorh1] = valor;

  }
}

void remover(int t1[], int t2[], int valor){

  int valorh1 = h1(valor);
  int valorh2 = h2(valor);

  if(t2[valorh2] == valor)
    t2[valorh2] = -1;
  else if (t1[valorh1] == valor)
    t1[valorh1] = 999;

}

int valor_minimo(int v[]){

  int indice = 0; 
  int minimo = 999;

  for(int i = 0; i < 2*m; i++)
    if(v[i] != -1 && v[i] < minimo){
      minimo = v[i];
      indice = i;
    }

  v[indice] = -1;

  return indice;

}

void imprimir(int t1[], int t2[]){

  int v[m*2];

  int indice = 0;
  int i = 0;

  for(i = 0; i < m; i++){
    v[indice] = t1[i];
    indice++;
  }

  for(i = 0; i < m; i++){
    v[indice] = t2[i];
    indice++;
  }

  int qtd = 0;

  for(i = 0; i < 2*m; i++){
    if (v[i] != -1 && v[i] != 999)
      qtd++;
  }

  int numero = 0;
  int minimo = 0;

  while (numero < qtd){

    minimo = valor_minimo(v);

    if(minimo >= 11 && minimo != 999){
      printf("%d,T2,%d\n", t2[minimo-11], minimo - 11);
      numero++;
    }
    else if (minimo != 999){
      printf("%d,T1,%d\n", t1[minimo], minimo);
      numero++;
    }
  }

  return;
}