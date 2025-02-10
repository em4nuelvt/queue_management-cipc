#include "fila.h"

Fila* criar_fila() {
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    if (fila == NULL) {
        printf("Erro ao alocar memória para a fila.\n");
        exit(1);
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

bool fila_vazia(Fila* fila) {
    return fila->inicio == NULL;
}

void inserir(Fila* fila, Cliente* cliente) { // a inserção deve ser feita de acordo com a prioridade
    NoFila* novo = (NoFila*) malloc(sizeof(NoFila));
    if (novo == NULL) {
        printf("Erro ao alocar memória para o nó da fila.\n");
        exit(1);
    }
    novo->cliente = cliente;
    novo->prox = NULL;
    if (fila_vazia(fila)) {//se vazia o início já é o novo nó
        fila->inicio = novo;
        fila->fim = novo;
        fila->tamanho++;
        return;
    }
    NoFila* aux = fila->inicio;        
    //se a prioridade do cliente for maior que a do primeiro da fila ja insere no inicio
    if (aux->cliente->prioridade > cliente->prioridade) { 
        novo->prox = aux;
        fila->inicio = novo;
        fila->tamanho++;
        return;
    }
    while(aux->prox != NULL && aux->prox->cliente->prioridade <= cliente->prioridade) { //enquanto não chegar no fim e a prioridade do cliente for menor ou igual a do aux
        aux = aux->prox;
    }
    novo->prox = aux->prox;
    aux->prox = novo;
    if (novo->prox == NULL) {
        fila->fim = novo;
    }
    fila->tamanho++;
    return;
}

Cliente* remover(Fila* fila) { //como é fila remove sempre o primeiro
    if (fila_vazia(fila)) {
        printf(" Fila vazia.\n");
        exit(1);
    }
    NoFila* aux = fila->inicio;
    fila->inicio = fila->inicio->prox;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    Cliente* cliente = aux->cliente;
    free(aux);
    fila->tamanho--;
    return cliente;
}

void imprimir_fila(Fila* fila) {
    NoFila* aux = fila->inicio;
    int contador = 1;
    while (aux != NULL) { // imprime a colocação na fila, o nome do cliente e a quantidade de produtos
        printf("%d -  %s(%d) - CPF: %ld - Quantidade de Produtos: %d", contador,aux->cliente->nome,aux->cliente->prioridade,aux->cliente->cpf, aux->cliente->qtd_produtos);
        printf("\n");
        aux = aux->prox;
        contador++;
    }
}