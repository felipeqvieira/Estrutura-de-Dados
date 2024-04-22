typedef struct pilha {
    int topo;
    int tam;
    int *data;
} Pilha;

Pilha *criaPilha(int tam);
void push(Pilha *p, int x);
int pop(Pilha *p);
int retorna_tamanho(Pilha *p);