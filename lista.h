#ifndef LISTA_H
#define LISTA_H

#include "cliente.h"
#include <stdbool.h>

typedef struct no_lista {
    Cliente* cliente;
    struct no_lista* prox;
} NoLista;

typedef struct lista {
    NoLista* inicio;
    NoLista* fim;
} Lista;

Lista* criar_lista();
void inserirNaLista(Lista* lista, Cliente* cliente);
bool vazia(Lista* lista);
void imprimir_lista(Lista* lista);

#endif