#include "caixa.h"

int main(){
    int opcao;
    int idCaixa;
    Caixa* caixas[MAX_CAIXAS];
    for(int i = 0; i < MAX_CAIXAS; i++){
        caixas[i] = criar_caixa(i+1);
    }

    return 0;
    do{
        printf("\n----------------- Supermercado CEFET-MG ----------------- \n\n");
        printf("Selecione uma opção:\n");
        printf("1 - Cadastrar um cliente\n");
        printf("2 - Atender um cliente\n");
        printf("3 - Abrir um caixa\n");
        printf("4 - Fechar um caixa\n");
        printf("5 - Imprimir clientes em espera\n");
        printf("6 - Imprimir caixas\n");
        printf("0 - Sair\n\n");
        printf("---------------------------------------------------------\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        printf("---------------------------------------------------------\n\n");

        switch(opcao){
            case 1:
                printf("* Cadastrar um cliente *\n"); 
                cadastrar_cliente(caixas);       
                break;
            case 2:
                printf("* Atender um cliente *\n");
                break;
            case 3:
                printf("* Abrir caixa *\n");
                printf("Digite o ID do caixa: ");
                scanf("%d", &idCaixa);
                if(idCaixa < 1 || idCaixa > MAX_CAIXAS){
                    printf("Caixa inválido\n");
                    break;
                }
                if(caixas[idCaixa-1]->estado == 1){
                    printf("Caixa já está aberto\n");
                    break;
                }
                abrir_caixa(caixas[idCaixa-1]);
                break;
            case 4:
                printf("* Fechar um caixa *\n");
                printf("Digite o ID do caixa: ");
                scanf("%d", &idCaixa);
                if(idCaixa < 1 || idCaixa > MAX_CAIXAS){
                    printf("Caixa inválido\n");
                    break;
                }
                if(caixas[idCaixa-1]->estado == 0){
                    printf("Caixa já está fechado\n");
                    break;
                }
                fechar_caixa(caixas[idCaixa-1]);
                break;
            case 5:
                printf("*Imprimir clientes em espera*\n");
                imprimir_filas(caixas);
                break;
            case 6:
                printf("*Imprimir caixas*\n");
                imprimir_caixas(caixas);
                break;
            case 0:
                printf("Finalizando programa...\n");
                break;
            default:
                printf("Opção inválida\n");
                break;
        }


    }while(opcao != 0);




    return 0;
}