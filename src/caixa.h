#ifndef CAIXA_H
#define CAIXA_H

#define MAX_CAIXAS 5

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fila.h"
#include "lista.h"

typedef struct caixa {
    int id;
    bool estado; // 0 - fechado; 1 - aberto  
    Fila* fila;  
    Lista* clientes_atendidos;    
} Caixa;

Caixa* criar_caixa(int id);
void abrir_caixa(Caixa** caixas);
void fechar_caixa(Caixa** caixas);
void imprimir_filas(Caixa** caixas);
void imprimir_caixas(Caixa** caixas);
void cadastrar_cliente(Caixa** caixas);
bool tem_caixa_aberto(Caixa** caixas);
void atender_cliente(Caixa** caixas);
void realocar_clientes(Caixa** caixas, int idCaixa);
int contar_caixas_abertos(Caixa** caixas);
void imprimir_clientes_atendidos(Caixa** caixas);

#endif