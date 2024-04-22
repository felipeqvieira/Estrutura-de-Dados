#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct Node {
    void* data;
    struct Node* prox;
} Node;

// Definição da estrutura da lista
typedef struct {
    int tam;
    Node* inicio;
    Node* fim;
} Lista;

// Função para inicializar a lista
Lista* inicializa_lista() {
    Lista* l = malloc(sizeof(Lista));
    l->tam = 0;
    l->inicio = NULL;
    l->fim = NULL;
    return l;
}

// Função para criar um novo nó
Node* cria_no(void* valor) {
    Node* novo = malloc(sizeof(Node));
    novo->data = valor;
    novo->prox = NULL;
    return novo;
}

// Função para inserir um nó no início da lista
Lista* insereInicio(Lista* l, void* valor) {
    Node* novo = cria_no(valor);
    if (l->inicio == NULL) {
        l->inicio = l->fim = novo;
    } else {
        novo->prox = l->inicio;
        l->inicio = novo;
    }
    l->tam++;
    return l;
}

// Função para remover o nó do início da lista
Lista* removeInicio(Lista* l) {
    if (l->inicio == NULL) {
        printf("Lista Vazia!\n");
        return l;
    }

    Node* aux = l->inicio;
    l->inicio = l->inicio->prox;

    free(aux->data); // Liberar a memória associada aos dados
    free(aux);       // Liberar a memória do nó

    l->tam--;

    return l;
}

// Função para liberar a memória da lista
void libera_lista(Lista* l) {
    while (l->inicio != NULL) {
        removeInicio(l);
    }
    free(l);
}

// Exemplo de uso
int main() {
    Lista* myList = inicializa_lista();

    int* value1 = malloc(sizeof(int));
    *value1 = 3;
    insereInicio(myList, value1);

    double* value2 = malloc(sizeof(double));
    *value2 = 2.5;
    insereInicio(myList, value2);

    // Printa a lista (considerando que você saiba o tipo de dados)
    Node* current = myList->inicio;
    while (current != NULL) {
        if (current->data != NULL) {
            if (current->data == value1) {
                printf("%d ", *((int*)current->data));
            } else if (current->data == value2) {
                printf("%f ", *((double*)current->data));
            }
        }
        current = current->prox;
    }
    printf("\n");

    // Libera a memória da lista
    libera_lista(myList);

    return 0;
}
