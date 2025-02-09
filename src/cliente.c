#include "cliente.h"

Cliente* criar_cliente(char* nome, long cpf, int prioridade, int qtd_produtos) {
    Cliente* cliente = (Cliente*) malloc(sizeof(Cliente));
    if (cliente == NULL) {
        printf("Erro ao alocar memória para o cliente.\n");
        exit(1);
    }
    strcpy(cliente->nome, nome);
    cliente->cpf = cpf;
    cliente->prioridade = prioridade;
    cliente->qtd_produtos = qtd_produtos;
    return cliente;
}