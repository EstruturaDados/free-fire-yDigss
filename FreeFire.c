#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COMPONENTES 20
#define MAX_NOME 30
#define MAX_TIPO 20

struct Componente{
    char nome[MAX_NOME];
    char tipo[MAX_TIPO];
    int prioridade;
};

void listarItens(struct Componente componentes[], int totalComponentes){
    printf("\n=====================================================\n");
    printf("                PLANO DE FUGA - CODIGO DA ILHA             \n");
    printf("=====================================================\n");

    if(totalComponentes == 0){
        printf("\nNenhum Componente cadastrado!\n");
        return;
    }

    printf("\nComponentes Cadastrados: %d/%d\n\n", totalComponentes, MAX_COMPONENTES);

    printf("%-15s | %-15s | %-10s\n",
        "NOME",
        "TIPO",
        "PRIORIDADE");

    printf("-----------------------------------------------------\n");

    for(int i = 0; i < totalComponentes; i++){
        printf("%-15s | %-15s | %-10d\n",
            componentes[i].nome,
            componentes[i].tipo,
            componentes[i].prioridade);
    }

    printf("=====================================================\n");
}

void inserirItem(struct Componente componentes[], int *totalComponentes){
    if(*totalComponentes >= MAX_COMPONENTES){
        printf("\nMochila cheia!\n");
        return;
    }

    printf("\nNome do item: ");
    scanf("%s", componentes[*totalComponentes].nome);

    printf("Tipo do item: ");
    scanf("%s", componentes[*totalComponentes].tipo);

    printf("Prioridade (1 a 10): ");
    scanf("%d", &componentes[*totalComponentes].prioridade);

    (*totalComponentes)++;

    printf("\nItem adicionado com sucesso!\n");
}

void removerItem(struct Componente componentes[], int *totalComponentes){
    char nomeRemover[MAX_NOME];

    printf("\nDigite o nome do componente para remover: ");
    scanf("%s", nomeRemover);

    for(int i = 0; i < *totalComponentes; i++){

        if(strcmp(componentes[i].nome, nomeRemover) == 0){

            for(int j = i; j < *totalComponentes - 1; j++){
                componentes[j] = componentes[j + 1];
            }

            (*totalComponentes)--;

            printf("\nComponente removido com sucesso!\n");
            return;
        }
    }

    printf("\nComponente nao encontrado!\n");
}

void buscarItem(struct Componente componentes[], int totalComponentes){

    char nomeBusca[MAX_NOME];
    int comparacoes = 0;

    printf("\nDigite o nome do componente: ");
    scanf("%s", nomeBusca);

    for(int i = 0; i < totalComponentes; i++){

        comparacoes++;

        if(strcmp(componentes[i].nome, nomeBusca) == 0){

            printf("\n======= COMPONENTE ENCONTRADO =======\n");

            printf("Nome: %s\n", componentes[i].nome);
            printf("Tipo: %s\n", componentes[i].tipo);
            printf("Prioridade: %d\n", componentes[i].prioridade);

            printf("\nComparacoes realizadas: %d\n", comparacoes);

            return;
        }
    }

    printf("\nComponente %s nao encontrado!\n", nomeBusca);
    printf("Comparacoes realizadas: %d\n", comparacoes);
}

void bubbleSortNome(struct Componente componentes[], int totalComponentes){

    clock_t inicio, fim;
    inicio = clock();

    struct Componente temp;
    int comparacoes = 0;

    for(int i = 0; i < totalComponentes - 1; i++){

        for(int j = 0; j < totalComponentes - 1 - i; j++){

            comparacoes++;

            if(strcmp(componentes[j].nome, componentes[j + 1].nome) > 0){

                temp = componentes[j];
                componentes[j] = componentes[j + 1];
                componentes[j + 1] = temp;
            }
        }
    }

    fim = clock();

    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("\nComponentes ordenados por Nome!\n");
    printf("Comparacoes realizadas: %d\n", comparacoes);
    printf("Tempo de execucao: %.6f segundos\n", tempo);
}

void buscarBinariaVetor(struct Componente componentes[], int totalComponentes){

    char nomeBusca[MAX_NOME];

    printf("\nDigite o nome do componente: ");
    scanf("%s", nomeBusca);

    int inicio = 0;
    int fim = totalComponentes - 1;
    int comparacoes = 0;

    while(inicio <= fim){

        int meio = (inicio + fim) / 2;

        comparacoes++;

        int resultado = strcmp(nomeBusca, componentes[meio].nome);

        if(resultado == 0){

            printf("\n======= COMPONENTE ENCONTRADO =======\n");

            printf("Nome: %s\n", componentes[meio].nome);
            printf("Tipo: %s\n", componentes[meio].tipo);
            printf("Prioridade: %d\n", componentes[meio].prioridade);

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

    printf("\nComponente nao encontrado!\n");
    printf("Comparacoes realizadas: %d\n", comparacoes);
}

void insertionSortTipo(struct Componente componentes[], int totalComponentes){

    clock_t inicio, fim;
    inicio = clock();

    int comparacoes = 0;

    for(int i = 1; i < totalComponentes; i++){

        struct Componente chave = componentes[i];
        int j = i - 1;

        while(j >= 0 && strcmp(componentes[j].tipo, chave.tipo) > 0){

            comparacoes++;

            componentes[j + 1] = componentes[j];
            j--;
        }

        if(j >= 0){
            comparacoes++;
        }

        componentes[j + 1] = chave;
    }

    fim = clock();

    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("\nComponentes ordenados por Tipo!\n");
    printf("Comparacoes realizadas: %d\n", comparacoes);
    printf("Tempo de execucao: %.6f segundos\n", tempo);
}

void selectionSortPrioridade(struct Componente componentes[], int totalComponentes){
    
    clock_t inicio, fim;
    inicio = clock();

    int comparacoes = 0;

    for(int i = 0; i < totalComponentes - 1; i++){
        int menor = i;

        for(int j = i + 1; j < totalComponentes; j++){
            comparacoes ++;

            if(componentes[j].prioridade < componentes[menor].prioridade){
                menor = j;
            }
        }
        if(menor != i){
            struct Componente temp = componentes[i];
            componentes[i] = componentes[menor];
            componentes[menor] = temp;
        }
    }

    fim = clock();

    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("\nComponentes Ordenados por Prioridade!\n");
    printf("Comparacoes realizadas: %d\n", comparacoes);
    printf("Tempo de execucao %.6f segundos\n", tempo);
}

int main(){

    struct Componente componente[MAX_COMPONENTES];

    int totalComponentes = 0;
    int opcao;
    int opcaoOrdenacao;
    int vetorOrdenado = 0;

    while(1){

        printf("\n=====================================\n");
        printf("   PLANO DE FUGA - CODIGO DA ILHA\n");
        printf("=====================================\n");

        printf("\nComponentes Cadastrados: %d/%d\n", totalComponentes, MAX_COMPONENTES);

        printf("\n1. Adicionar Componente");
        printf("\n2. Remover Componente");
        printf("\n3. Buscar Componente");
        printf("\n4. Listar Componentes");
        printf("\n5. Ordenar Componentes");
        printf("\n6. Busca Binaria por Nome");
        printf("\n0. Ativar Torre de Fuga\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){

            case 1:
                inserirItem(componente, &totalComponentes);
                break;

            case 2:
                removerItem(componente, &totalComponentes);
                break;

            case 3:
                buscarItem(componente, totalComponentes);
                break;

            case 4:
                listarItens(componente, totalComponentes);
                break;

            case 5:
                printf("\n=====================================\n");
                printf("   ESTRATEGIA DE ORGANIZACAO\n");
                printf("=====================================\n");

                printf("\n1. Ordenar por Nome (Buble Sort): ");
                printf("\n2. Ordenar por Tipo (Insertion Sort): ");
                printf("\n3. Ordenar por Prioridade (Selection Sort): ");
                printf("\n4. Cancelar");

                printf("\nEscolha uma opcao: ");
                scanf("%d", &opcaoOrdenacao);

                switch(opcaoOrdenacao){

                    case 1:
                        bubbleSortNome(componente, totalComponentes);
                        vetorOrdenado = 1;
                        break;

                    case 2:
                        insertionSortTipo(componente, totalComponentes);
                        vetorOrdenado = 0;
                        break;

                    case 3:
                        selectionSortPrioridade(componente, totalComponentes);
                        vetorOrdenado = 0;
                        break;

                    case 4:
                        printf("\nOperacao cancelada.\n");
                        break;

                    default:
                        printf("\nOpcao invalida!\n");
                }
                break;

            case 6:
                if(!vetorOrdenado){
                    printf("\nPrimeiro ordene os componentes por Nome!\n");
                    break;
                }

                buscarBinariaVetor(componente, totalComponentes);
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