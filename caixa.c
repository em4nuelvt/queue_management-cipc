#include "caixa.h"

Caixa* criar_caixa(int id) {
    Caixa* caixa = (Caixa*) malloc(sizeof(Caixa));
    if (caixa == NULL) {
        printf("Erro ao alocar memória para o caixa.\n");
        exit(1);
    }
    caixa->id = id;
    caixa->estado = 0;
    caixa->fila = criar_fila();
    return caixa;
}

void abrir_caixa(Caixa* caixa) {
    caixa->estado = 1;
}

void fechar_caixa(Caixa* caixa) {
    caixa->estado = 0;
}

void imprimir_filas(Caixa** caixas) {
    for (int i = 0; i < MAX_CAIXAS; i++) {
        printf("Caixa %d: ", caixas[i]->id);
        if (fila_vazia(caixas[i]->fila)) {
            printf("Fila vazia\n");
            continue;
        }
        printf("\n");
        imprimir_fila(caixas[i]->fila);
        printf("\n");
    }
}

void imprimir_caixas(Caixa** caixas) {
    for (int i = 0; i < MAX_CAIXAS; i++) {
        printf("Caixa %d: ", caixas[i]->id);
        caixas[i]->estado == 0 ? printf("Fechado\n") : printf("Aberto\n");        
    }
    printf("\n");
}

void cadastrar_cliente(Caixa** caixas) {
    if(!tem_caixa_aberto(caixas)) {
        printf("Nenhum caixa aberto\n");
        return;
    }
    char nome[100];
    int cpf, prioridade, qtd_produtos;
    printf("Digite o nome do cliente: ");
    fgets(nome, 100, stdin);
    setbuf(stdin, 0);
    printf("Digite o CPF do cliente: ");
    scanf("%d", &cpf);
    printf("Digite a prioridade do cliente (1 - prioridade mais alta; 2 - prioridade média; 3 - prioridade baixa): ");
    scanf("%d", &prioridade);
    printf("Digite a quantidade de produtos do cliente: ");
    scanf("%d", &qtd_produtos);
    Cliente* cliente = criar_cliente(nome, cpf, prioridade, qtd_produtos);
    int idCaixa;
    do{
        printf("Em qual caixa o cliente será atendido? ");
        scanf("%d", &idCaixa);
        if (idCaixa < 1 || idCaixa > MAX_CAIXAS) {
            printf("Caixa inválido\n");        
        }
        if(caixas[idCaixa-1]->estado == 0) {
            printf("Caixa fechado\n");
        }
    } while (idCaixa < 1 || idCaixa > MAX_CAIXAS || caixas[idCaixa-1]->estado == 0);
    inserir(caixas[idCaixa-1]->fila, cliente);

}

bool tem_caixa_aberto(Caixa** caixas) {
    for (int i = 0; i < MAX_CAIXAS; i++) {
        if (caixas[i]->estado == 1) {            
            return true;
        }
    }
    return false;
}

void atender_cliente(Caixa** caixas) {
    if(!tem_caixa_aberto(caixas)) {
        printf("Nenhum caixa aberto\n");
        return;
    }
    int idCaixa;
    do{
        printf("Qual dos caixas fará o atendimento? ");
        scanf("%d", &idCaixa);
        if (idCaixa < 1 || idCaixa > MAX_CAIXAS) {
            printf("Caixa inválido\n");        
        }
        if(caixas[idCaixa-1]->estado == 0) {
            printf("Caixa fechado\n");
        }
    } while (idCaixa < 1 || idCaixa > MAX_CAIXAS || caixas[idCaixa-1]->estado == 0);
    if (fila_vazia(caixas[idCaixa-1]->fila)) {
        printf("Fila do caixa está vazia.\n");
        return;
    }
    Cliente* cliente = remover(caixas[idCaixa-1]->fila);
    printf("Cliente %s atendido\n", cliente->nome);
    free(cliente);
}