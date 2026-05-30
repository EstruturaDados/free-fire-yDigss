#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int comparacoes = 0;

    printf("\nDigite o nome do item: ");
    scanf("%s", nomeBusca);

    for(int i = 0; i < totalItens; i++){

        comparacoes++;

        if(strcmp(mochila[i].nome, nomeBusca) == 0){

            printf("\n======= ITEM ENCONTRADO =======\n");

            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);

            printf("\nComparacoes realizadas: %d\n", comparacoes);

            return;
        }
    }

    printf("\nItem %s nao encontrado!\n", nomeBusca);
    printf("Comparacoes realizadas: %d\n", comparacoes);
}

void ordenarVetor(struct Item mochila[], int totalItens){

    struct Item temp;

    for(int i = 0; i < totalItens - 1; i++){

        for(int j = 0; j < totalItens - 1 - i; j++){

            if(strcmp(mochila[j].nome, mochila[j + 1].nome) > 0){

                temp = mochila[j];
                mochila[j] = mochila[j + 1];
                mochila[j + 1] = temp;
            }
        }
    }

    printf("\nItens ordenados com sucesso!\n");
}

void buscarBinariaVetor(struct Item mochila[], int totalItens){

    char nomeBusca[MAX_NOME];

    printf("\nDigite o nome do item: ");
    scanf("%s", nomeBusca);

    int inicio = 0;
    int fim = totalItens - 1;
    int comparacoes = 0;

    while(inicio <= fim){

        int meio = (inicio + fim) / 2;

        comparacoes++;

        int resultado = strcmp(nomeBusca, mochila[meio].nome);

        if(resultado == 0){

            printf("\n======= ITEM ENCONTRADO =======\n");

            printf("Nome: %s\n", mochila[meio].nome);
            printf("Tipo: %s\n", mochila[meio].tipo);
            printf("Quantidade: %d\n", mochila[meio].quantidade);

            printf("\nComparacoes realizadas: %d\n", comparacoes);

            return;
        }

        if(resultado > 0){
            inicio = meio + 1;
        }
        else{
            fim = meio - 1;
        }
    }

    printf("\nItem nao encontrado!\n");
    printf("Comparacoes realizadas: %d\n", comparacoes);
}

int main(){

    struct Item mochila[MAX_ITENS];

    int totalItens = 0;
    int opcao;

    while(1){

        printf("\n=====================================\n");
        printf("   MOCHILA DE SOBREVIVENCIA\n");
        printf("=====================================\n");

        printf("\nItens na mochila: %d/%d\n", totalItens, MAX_ITENS);

        printf("\n1. Adicionar Item");
        printf("\n2. Remover Item");
        printf("\n3. Busca Sequencial");
        printf("\n4. Listar Itens");
        printf("\n5. Ordenar Itens");
        printf("\n6. Busca Binaria");
        printf("\n0. Sair\n");

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

            case 5:
                ordenarVetor(mochila, totalItens);
                break;

            case 6:
                buscarBinariaVetor(mochila, totalItens);
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