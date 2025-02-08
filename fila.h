#ifndef FILA_H
#define FILA_H

#include "cliente.h"
#include <stdbool.h>

typedef struct no_fila {
    Cliente* cliente;
    struct no_fila* prox;
} NoFila;

typedef struct fila {
    NoFila* inicio;
    NoFila* fim;
    int tamanho;
} Fila;

Fila* criar_fila();
void inserir(Fila* fila, Cliente* cliente);
Cliente* remover(Fila* fila);
void imprimir_fila(Fila* fila);
bool fila_vazia (Fila* fila);

#endif

