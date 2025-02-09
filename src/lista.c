#include "lista.h"

Lista* criar_lista() {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    if (lista == NULL) {
        printf("Erro ao alocar memória para a lista.\n");
        exit(1);
    }
    lista->inicio = NULL;
    lista->fim = NULL;
    return lista;
}

bool vazia(Lista* lista) {
    return lista->inicio == NULL;
}

//insere elemento no final
void inserirNaLista(Lista* lista, Cliente* cliente) { 
    NoLista* novo = (NoLista*) malloc(sizeof(NoLista));
    if (novo == NULL) {
        printf("Erro ao alocar memória para o nó da lista.\n");
        exit(1);
    }
    novo->cliente = cliente;
    novo->prox = NULL;
    if (vazia(lista)) {
        lista->inicio = novo;
        lista->fim = novo;
        return;
    }
    lista->fim->prox = novo;
    lista->fim = novo;
}

void imprimir_lista(Lista* lista) {
    if (vazia(lista)) {
        printf("Lista vazia.\n");
        return;
    }
    NoLista* aux = lista->inicio;
    int contador = 1;
    while (aux != NULL) {
        printf("%d -  %s(%d) - Quantidade de Produtos: %d", contador,aux->cliente->nome,aux->cliente->prioridade, aux->cliente->qtd_produtos);
        printf("\n");
        contador++;
        aux = aux->prox;
    }
}