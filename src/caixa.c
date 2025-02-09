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
    caixa->clientes_atendidos = criar_lista();
    return caixa;
}

void abrir_caixa(Caixa** caixas) {
    int idCaixa;
    printf("Digite o ID do caixa: ");
    scanf("%d", &idCaixa);
    if(idCaixa < 1 || idCaixa > MAX_CAIXAS){
        printf("Caixa inválido.\n");
        return;
    }
    if(caixas[idCaixa-1]->estado == 1){
        printf("Caixa já está aberto.\n");
        return;
    }
    caixas[idCaixa-1]->estado = 1;    
    printf("Caixa %d aberto.\n", idCaixa);
}

void fechar_caixa(Caixa** caixas) {
    if(!tem_caixa_aberto(caixas)) {
        printf("Nenhum caixa aberto.\n");
        return;
    }
    int idCaixa;
    //pegar id valido
    do{
        printf("Digite o ID do caixa: ");
        scanf("%d", &idCaixa);
        if(idCaixa < 1 || idCaixa > MAX_CAIXAS){
            printf("Caixa inválido.\n");
            continue;      
        }
        if(caixas[idCaixa-1]->estado == 0){
            printf("Caixa já está fechado.\n");
            continue;
        }
    }while (idCaixa < 1 || idCaixa > MAX_CAIXAS || caixas[idCaixa-1]->estado == 0);

    if(!fila_vazia(caixas[idCaixa-1]->fila)){ // só realoca se houver alguem na fila
        if(contar_caixas_abertos(caixas) < 2){
            printf("É preciso ter outro caixa aberto para realocar os clientes.\n");
            return;
        }
        realocar_clientes(caixas, idCaixa-1);    
    }

    caixas[idCaixa-1]->estado = 0;
    printf("Caixa %d fechado.\n", idCaixa);       
}

//imprime a situação  das filas de cada caixa
void imprimir_filas(Caixa** caixas) {
    for (int i = 0; i < MAX_CAIXAS; i++) {
        printf("Caixa %d: ", caixas[i]->id);
        if (fila_vazia(caixas[i]->fila)) {
            printf("Fila vazia.\n\n");
            continue;
        }
        printf("\n");
        imprimir_fila(caixas[i]->fila);
        printf("\n");
    }
}

//imprime o estado de cada caixa
void imprimir_caixas(Caixa** caixas) {
    for (int i = 0; i < MAX_CAIXAS; i++) {
        printf("Caixa %d: ", caixas[i]->id);
        caixas[i]->estado == 0 ? printf("Fechado\n") : printf("Aberto(%d clientes na fila)\n", caixas[i]->fila->tamanho);        
    }
    printf("\n");
}

// pega os dados do cliente para inserir em uma fila de um caixa
void cadastrar_cliente(Caixa** caixas) {
    if(!tem_caixa_aberto(caixas)) {
        printf("Nenhum caixa aberto.\n");
        return;
    }
    char nome[100];
    long cpf;
    int prioridade, qtd_produtos;
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", nome);
    printf("Digite o CPF do cliente: ");
    scanf("%ld", &cpf);
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
            printf("Caixa inválido.\n");  
            continue;      
        }
        if(caixas[idCaixa-1]->estado == 0) {
            printf("Caixa fechado.\n");
            continue;
        }
    } while (idCaixa < 1 || idCaixa > MAX_CAIXAS || caixas[idCaixa-1]->estado == 0);
    inserir(caixas[idCaixa-1]->fila, cliente);

}

//verifica se existe caixa aberto
bool tem_caixa_aberto(Caixa** caixas) {
    for (int i = 0; i < MAX_CAIXAS; i++) {
        if (caixas[i]->estado == 1) {            
            return true;
        }
    }
    return false;
}

//retorna o número de caixas abertos
int contar_caixas_abertos(Caixa** caixas) {
    int contador = 0;
    for (int i = 0; i < MAX_CAIXAS; i++) {
        if (caixas[i]->estado == 1) {            
            contador++;
        }
    }
    return contador;
}

//seleciona qual caixa removerá um cliente da fila
void atender_cliente(Caixa** caixas) {
    if(!tem_caixa_aberto(caixas)) {
        printf("Nenhum caixa aberto.\n");
        return;
    }
    int idCaixa;
    do{
        printf("Qual dos caixas fará o atendimento? ");
        scanf("%d", &idCaixa);
        if (idCaixa < 1 || idCaixa > MAX_CAIXAS) {
            printf("Caixa inválido.\n");        
        }
        if(caixas[idCaixa-1]->estado == 0) {
            printf("Caixa fechado.\n");
            return;
        }
    } while (idCaixa < 1 || idCaixa > MAX_CAIXAS || caixas[idCaixa-1]->estado == 0);
    if (fila_vazia(caixas[idCaixa-1]->fila)) {
        printf("Fila do caixa está vazia.\n");
        return;
    }
    Cliente* cliente = remover(caixas[idCaixa-1]->fila); //desenfileira
    inserirNaLista(caixas[idCaixa-1]->clientes_atendidos, cliente); //adiciona na lista de clientes atendidos
    printf("Cliente %s atendido\n", cliente->nome);    
}

void realocar_clientes(Caixa** caixas, int idCaixa) {    
    while (!fila_vazia(caixas[idCaixa]->fila)) {
        int idCaixaDestino;
        Cliente* cliente = remover(caixas[idCaixa]->fila);
        int menor = 10000;
        for(int i =0; i<MAX_CAIXAS;i++){
            if(i!=idCaixa && caixas[i]->estado == 1 && caixas[i]->fila->tamanho < menor){
                menor = caixas[i]->fila->tamanho;
                idCaixaDestino = i;
            }
        }
        inserir(caixas[idCaixaDestino]->fila, cliente);
        printf("Cliente %s realocado para o caixa %d.\n", cliente->nome, caixas[idCaixaDestino]->id);
    }
    
}

void imprimir_clientes_atendidos(Caixa** caixas) {
    for (int i = 0; i < MAX_CAIXAS; i++) {
        printf("Caixa %d: ", caixas[i]->id);
        if (vazia(caixas[i]->clientes_atendidos)) {
            printf("Nenhum cliente atendido\n\n");
            continue;
        }
        printf("\n");
        imprimir_lista(caixas[i]->clientes_atendidos);
        printf("\n");
    }
}

void liberar_estruturas(Caixa** caixas) {
    for (int i = 0; i < MAX_CAIXAS; i++) {
        NoFila* atual_fila = caixas[i]->fila->inicio;
        while (atual_fila != NULL) {
            NoFila* prox = atual_fila->prox;
            free(atual_fila->cliente);
            free(atual_fila);
            atual_fila = prox;
        }
        free(caixas[i]->fila);

        NoLista* atual_lista = caixas[i]->clientes_atendidos->inicio;
        while (atual_lista != NULL) {
            NoLista* prox = atual_lista->prox;
            free(atual_lista->cliente);
            free(atual_lista);
            atual_lista = prox;
        }
        free(caixas[i]->clientes_atendidos);
        free(caixas[i]);
    }
}