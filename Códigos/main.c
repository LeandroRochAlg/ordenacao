#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char nomeArquivo[30], metricas[50], ordenado[50];
    tReturn *rep;
    rep = alocatReturn();
    double tempo;
    int num=0, op, tam = 10, ret, pos;
    srand(time(NULL));
    clock_t inicio, fim;

    printf("ALGORITMOS DE ORDENAÇÃO\n");
    while(1){
        printf("\n1 - Gerar arquivo");
        printf("\n2 - Ordenar");
        printf("\n3 - Buscar");
        printf("\n4 - Sair");
        printf("\nDigite o número correspondente a operação desejada: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                tam = 0;
                while(tam <= 10) {
                    printf("\nDigite o tamanho do vetor, escolha um tamanho maior que 10: ");
                    scanf("%d", &tam);
                }

                printf("\nDigite o nome do arquivo a ser gerado, terminando com .txt: ");
                scanf(" %s", nomeArquivo);

                printf("\nEscolha o tipo de vetor:");
                printf("\n1 - Ordenado crescente");
                printf("\n2 - Ordenado decrescente");
                printf("\n3 - Aleatório\n");
                scanf("%d", &op);

                switch (op) {
                    case 1:
                        ret = geraCrescente(nomeArquivo, tam);
                        if(ret == 0){
                            printf("\nArquivo criado com sucesso!");
                        }else{
                            printf("\nErro ao criar arquivo.");
                        }
                        break;
                    case 2:
                        ret = geraDecrescente(nomeArquivo, tam);
                        if(ret == 0){
                            printf("\nArquivo criado com sucesso!");
                        }else{
                            printf("\nErro ao criar arquivo.");
                        }
                        break;
                    case 3:
                        ret = geraAleatorios(nomeArquivo, tam);
                        if(ret == 0){
                            printf("\nArquivo criado com sucesso!");
                        }else{
                            printf("\nErro ao criar arquivo.");
                        }
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                printf("\nDigite o nome do arquivo a ser ordenado, terminando com .txt: ");
                scanf(" %s", nomeArquivo);

                printf("\nEscolha o métdodo de ordenação:");
                printf("\n1 - Bolha");
                printf("\n2 - Bolha Inteligente");
                printf("\n3 - Seleção");
                printf("\n4 - Inserção");
                printf("\n5 - MergeSort");
                printf("\n6 - QuickSort");
                printf("\n7 - Dual-Pivot QuickSort\n");
                scanf("%d", &op);

                switch (op) {
                    case 1:
                        rep = leArquivo(rep, nomeArquivo);
                        inicio = clock();
                        bolha(rep);
                        fim = clock();
                        tempo = (double)(fim - inicio);
                        strcpy(metricas, "metricas_bolha_");
                        strcat(metricas, nomeArquivo);
                        strcpy(ordenado, nomeArquivo);
                        strcat(ordenado, "_ordenado.txt");
                        salvaOrdenado(ordenado, getVet(rep), getTam(rep));
                        salvaMetricas(metricas, tempo, getTrocas(rep), getComps(rep));

                        break;

                    case 2:
                        rep = leArquivo(rep, nomeArquivo);
                        inicio = clock();
                        bolhaInteligente(rep);
                        fim = clock();
                        tempo = (double)(fim - inicio);
                        strcpy(metricas, "metricas_bolhaInteligente_");
                        strcat(metricas, nomeArquivo);
                        strcpy(ordenado, nomeArquivo);
                        strcat(ordenado, "_ordenado.txt");
                        salvaOrdenado(ordenado, getVet(rep), getTam(rep));
                        salvaMetricas(metricas, tempo, getTrocas(rep), getComps(rep));

                        break;

                    case 3:
                        rep = leArquivo(rep, nomeArquivo);
                        inicio = clock();
                        selecao(rep);
                        fim = clock();
                        tempo = (double)(fim - inicio);
                        strcpy(metricas, "metricas_selecao_");
                        strcat(metricas, nomeArquivo);
                        strcpy(ordenado, nomeArquivo);
                        strcat(ordenado, "_ordenado.txt");
                        salvaOrdenado(ordenado, getVet(rep), getTam(rep));
                        salvaMetricas(metricas, tempo, getTrocas(rep), getComps(rep));

                        break;

                    case 4:
                        rep = leArquivo(rep, nomeArquivo);
                        inicio = clock();
                        insercao(rep);
                        fim = clock();
                        tempo = (double)(fim - inicio);
                        strcpy(metricas, "metricas_insercao_");
                        strcat(metricas, nomeArquivo);
                        strcpy(ordenado, nomeArquivo);
                        strcat(ordenado, "_ordenado.txt");
                        salvaOrdenado(ordenado, getVet(rep), getTam(rep));
                        salvaMetricas(metricas, tempo, getTrocas(rep), getComps(rep));

                        break;

                    case 5:
                        rep = leArquivo(rep, nomeArquivo);
                        inicio = clock();
                        mergeSort(rep, 0, getTam(rep) - 1);
                        fim = clock();
                        tempo = (double)(fim - inicio);
                        strcpy(metricas, "metricas_merge_");
                        strcat(metricas, nomeArquivo);
                        strcpy(ordenado, nomeArquivo);
                        strcat(ordenado, "_ordenado.txt");
                        salvaOrdenado(ordenado, getVet(rep), getTam(rep));
                        salvaMetricas(metricas, tempo, getTrocas(rep), getComps(rep));

                        break;

                    case 6:
                        rep = leArquivo(rep, nomeArquivo);
                        inicio = clock();
                        quickSort(rep, 0, getTam(rep) - 1);
                        fim = clock();
                        tempo = (double)(fim - inicio);
                        strcpy(metricas, "metricas_quick_");
                        strcat(metricas, nomeArquivo);
                        strcpy(ordenado, nomeArquivo);
                        strcat(ordenado, "_ordenado.txt");
                        salvaOrdenado(ordenado, getVet(rep), getTam(rep));
                        salvaMetricas(metricas, tempo, getTrocas(rep), getComps(rep));

                        break;

                    case 7:
                        rep = leArquivo(rep, nomeArquivo);
                        inicio = clock();
                        dualPivotQuickSort(rep, 0, getTam(rep) - 1);
                        fim = clock();
                        tempo = (double)(fim - inicio);
                        strcpy(metricas, "metricas_dualPivotQuick_");
                        strcat(metricas, nomeArquivo);
                        strcpy(ordenado, nomeArquivo);
                        strcat(ordenado, "_ordenado.txt");
                        salvaOrdenado(ordenado, getVet(rep), getTam(rep));
                        salvaMetricas(metricas, tempo, getTrocas(rep), getComps(rep));

                        break;

                    default:
                        break;
                }
                break;
            case 3:
                printf("\nDigite o nome do arquivo a ser buscado, terminando com .txt: ");
                scanf(" %s", nomeArquivo);

                printf("\nEscolha o método de busca:");
                printf("\n1 - Busca linear");
                printf("\n2 - Busca binária (ordena utilizando o algoritmo Dual-Pivot QuickSort)\n");
                scanf("%d", &op);

                if(op==2){
                    rep = leArquivo(rep, nomeArquivo);
                    dualPivotQuickSort(rep, 0, getTam(rep)-1);
                }

                printf("\nDigite o valor a ser buscado (se for menor que 0 a busca encerra): ");
                scanf("%d", &num);
                while(num>=0) {
                    switch (op) {
                        case 1:
                            pos = buscaLinear(rep, num);
                            if(pos==-1){
                                printf("\nNúmero não encontrado.\n");
                            }else{
                                printf("\nNúmero encontrado na posição %d do vetor.\n", pos);
                            }
                            break;
                        case 2:
                            pos = buscaBinaria(rep, 0, getTam(rep)-1, num);
                            if(pos==-1){
                                printf("\nNúmero não encontrado.\n");
                            }else{
                                printf("\nNúmero encontrado na posição %d do vetor ordenado.\n", pos);
                            }
                            break;
                        default:
                            break;
                    }
                    printf("\nDigite o valor a ser buscado (se for menor que 0 a busca encerra): ");
                    scanf("%d", &num);
                }
                break;
            case 4:
                printf("\nEncerrando programa...");
                free(rep);
                return 0;
        }
    }
}