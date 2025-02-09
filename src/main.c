#include "caixa.h"

int main(){
    int opcao;
    Caixa* caixas[MAX_CAIXAS];
    for(int i = 0; i < MAX_CAIXAS; i++){
        caixas[i] = criar_caixa(i+1);
    }
    do{
        printf("\n----------------- Supermercado CEFET-MG ----------------- \n\n");
        printf("Selecione uma opção:\n");
        printf("1 - Cadastrar um cliente\n");
        printf("2 - Atender um cliente\n");
        printf("3 - Abrir um caixa\n");
        printf("4 - Fechar um caixa\n");
        printf("5 - Imprimir clientes em espera\n");
        printf("6 - Imprimir caixas\n");
        printf("7 - Histórico de clientes atendidos\n");
        printf("0 - Sair\n\n");
        printf("---------------------------------------------------------\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        printf("---------------------------------------------------------\n\n");

        switch(opcao){
            case 1:
                printf("* Cadastrar um cliente *\n\n"); 
                cadastrar_cliente(caixas);       
                break;
            case 2:
                printf("* Atender um cliente *\n\n");
                atender_cliente(caixas);
                break;
            case 3:
                printf("* Abrir caixa *\n\n");
                abrir_caixa(caixas);
                break;
            case 4:
                printf("* Fechar um caixa *\n\n");
                fechar_caixa(caixas);
                break;
            case 5:
                printf("*Imprimir clientes em espera*\n\n");
                imprimir_filas(caixas);
                break;
            case 6:
                printf("*Imprimir caixas*\n");
                imprimir_caixas(caixas);
                break;
            case 7:
                printf("*Histórico de clientes atendidos*\n");
                imprimir_clientes_atendidos(caixas);
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