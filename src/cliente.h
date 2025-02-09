#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente {
    char nome[100];
    long cpf;
    int prioridade; // 1 - prioridade mais alta; 2 - prioridade média; 3 - prioridade baixa
    int qtd_produtos;
} Cliente;

Cliente* criar_cliente(char* nome, long cpf, int prioridade, int qtd_produtos);

#endif
