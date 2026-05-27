#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX_ITENS 10
#define MAX_NOME 30
#define MAX_TIPO 20

struct Item{
    char nome[MAX_NOME];
    char tipo[MAX_TIPO];
    int quantidade;
};

void listarItens(struct Item mochila[], int totalItens){
    printf("\n=====================================================\n");
    printf("                MOCHILA DE SOBREVIVENCIA             \n");
    printf("=====================================================\n");

    if(totalItens == 0){
        printf("\nMochila vazia!\n");
        return;
    }

    printf("\nItens na mochila: %d/%d\n\n", totalItens, MAX_ITENS);

    printf("%-15s | %-15s | %-10s\n",
        "NOME",
        "TIPO",
        "QUANTIDADE");

    printf("-----------------------------------------------------\n");

    for(int i = 0; i < totalItens; i++){
        printf("%-15s | %-15s | %-10d\n",
            mochila[i].nome,
            mochila[i].tipo,
            mochila[i].quantidade);
    }

    printf("=====================================================\n");
}

void inserirItem(struct Item mochila[], int *totalItens){
    if(*totalItens >= MAX_ITENS){
        printf("\nMochila cheia!\n");
        return;
    }

    printf("\nNome do item: ");
    scanf("%s", mochila[*totalItens].nome);

    printf("Tipo do item: ");
    scanf("%s", mochila[*totalItens].tipo);

    printf("Quantidade: ");
    scanf("%d", &mochila[*totalItens].quantidade);

    (*totalItens)++;

    printf("\nItem adicionado com sucesso!\n");
}

void removerItem(struct Item mochila[], int *totalItens){
    char nomeRemover[MAX_NOME];

    printf("\nDigite o nome do item para remover: ");
    scanf("%s", nomeRemover);

    for(int i = 0; i < *totalItens; i++){
        if(strcmp(mochila[i].nome, nomeRemover) == 0){
            for(int j = i; j < *totalItens - 1; j++){
                mochila[j] = mochila[j + 1];
            }
            (*totalItens)--;
            printf("\nItem removido com sucesso!\n");
            return;
        }
    }
    printf("\nItem nao encontrado!\n");
}

void buscarItem(struct Item mochila[], int totalItens){

    char nomeBusca[MAX_NOME];

    printf("\nDigite o nome do item: ");
    scanf("%s", nomeBusca);

    for(int i = 0; i < totalItens; i++){

        if(strcmp(mochila[i].nome, nomeBusca) == 0){
            printf("\n======= ITEM ENCONTRADO =======\n");

            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            printf("Nome: %s\n", mochila[i].nome);

            return;
        }
    }

    printf("\nItem nao encontrado!\n");

}

int main(){

    struct Item mochila[MAX_ITENS];

    int totalItens = 0;

    int opcao;

    while(1){
        printf("\n=====================================\n");
        printf("   MOCHILA DE SOBREVIVENCIA\n");
        printf("=====================================\n");

        printf("\n1. Adicionar Item");
        printf("\n2. Remover Item");
        printf("\n3. Buscar Item");
        printf("\n4. Listar Itens");
        printf("\n0. Sair");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                inserirItem(mochila, &totalItens);
                break;

            case 2:
                removerItem(mochila, &totalItens);
                break;

            case 3:
                buscarItem(mochila, totalItens);
                break;
            
            case 4:
                listarItens(mochila, totalItens);
                break;
            
            case 0:
                printf("\nSaindo do sistema...\n");
                return 0;

            default:
            printf("\nOpcao invalida!\n");
        }
    }

    return 0;

}