#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"

struct tReturn {
    int *vet;
    int tam;
    double trocas;
    double comps;
};

tReturn* alocatReturn(){
    tReturn *rep = malloc(sizeof(tReturn));
    return rep;
}

tReturn* leArquivo(tReturn *rep, char *nomeArquivo){
    int tam, teste, erro = 0;

    FILE *arq;
    arq = fopen(nomeArquivo, "r");

    if(arq == NULL) {
        erro = 1;
        printf("Erro ao ler arquivo.");
    }

    teste = fscanf(arq, "%d", &tam);
    if(teste != 1){
        erro = 2;
    }

    int *vet = malloc(tam*sizeof(int));

    for(int i=0; i<tam; i++){
        teste = fscanf(arq, "%d", &vet[i]);
        if(teste != 1){
            erro = 2;
        }
    }

    rep->tam = tam;
    rep->vet = vet;
    rep->comps = 0;
    rep->trocas = 0;

    fclose(arq);

    return rep;
}

int *getVet(tReturn *rep){
    return rep->vet;
}

int getTam(tReturn *rep){
    return rep->tam;
}

double getTrocas(tReturn *rep){
    return rep->trocas;
}

double getComps(tReturn *rep){
    return rep->comps;
}

void bolha(tReturn *rep){
    int aux;

    for(int i=0; i<rep->tam; i++){
        for(int j=1; j<rep->tam; j++){
            rep->comps++;
            if(rep->vet[j] < rep->vet[j-1]){
                rep->trocas++;
                aux = rep->vet[j-1];
                rep->vet[j-1] = rep->vet[j];
                rep->vet[j] = aux;
            }
        }
    }
}

void bolhaInteligente(tReturn *rep){
    int aux, ctrl;

    for(int i=0; i<rep->tam; i++){
        ctrl = 0;
        for(int j=1; j<rep->tam; j++){
            rep->comps++;
            if(rep->vet[j] < rep->vet[j-1]){
                rep->trocas++;
                aux = rep->vet[j-1];
                rep->vet[j-1] = rep->vet[j];
                rep->vet[j] = aux;
                ctrl = 1;
            }
        }
        if(ctrl == 0){
            return;
        }
    }
}

void selecao(tReturn *rep){
    int marcador = 0, menor, aux;

    while (marcador < rep->tam-1){
        menor = marcador + 1;

        for(int i=marcador+1; i<rep->tam; i++){
            rep->comps++;
            if(rep->vet[i]<rep->vet[menor]){
                menor = i;
            }
        }

        rep->comps++;
        if(rep->vet[menor] < rep->vet[marcador]){
            rep->trocas++;
            aux = rep->vet[menor];
            rep->vet[menor] = rep->vet[marcador];
            rep->vet[marcador] = aux;
        }

        marcador++;
    }
}

void insercao(tReturn *rep) {
    int i, j, key;

    for (i = 1; i < rep->tam; i++) {
        key = rep->vet[i];
        j = i - 1;
        (rep->comps)++;
        while (j >= 0 && rep->vet[j] > key) {
            rep->vet[j + 1] = rep->vet[j];
            j -= 1;
            (rep->trocas)++;
            (rep->comps)++;
        }
        rep->vet[j + 1] = key;
        (rep->trocas)++;
    }
}

void mergeSort(tReturn *rep, int inicio, int fim){
    int meio;

    if(inicio < fim){
        meio = (inicio + fim)/2;
        mergeSort(rep, inicio, meio);
        mergeSort(rep, meio+1, fim);
        merge(rep, inicio, meio, fim);
    }
}

void merge(tReturn *rep, int inicio, int meio, int fim){
    int marcadorV1 = inicio;
    int marcadorV2 = meio+1;
    int vetAux[(fim-inicio)+1];
    int i = 0;

    while ((marcadorV1 <= meio) && (marcadorV2 <= fim)){
        (rep->comps)++;
        if(rep->vet[marcadorV1] < rep->vet[marcadorV2]){
            vetAux[i] = rep->vet[marcadorV1];
            marcadorV1++;
        }else{
            vetAux[i] = rep->vet[marcadorV2];
            marcadorV2++;
        }
        i++;
    }

    //copia o resto do vetor 1 e o resto do vetor 2 para o vetor auxiliar
    while (marcadorV1 <= meio){
        (rep->trocas)++;
        vetAux[i] = rep->vet[marcadorV1];
        marcadorV1++;
        i++;
    }
    while (marcadorV2 <= fim){
        (rep->trocas)++;
        vetAux[i] = rep->vet[marcadorV2];
        marcadorV2++;
        i++;
    }

    //copia o vetor auxiliar para o vetor original
    for (i = 0; i <= fim-inicio; i++){
        (rep->trocas)++;
        rep->vet[inicio+i] = vetAux[i];
    }
}

void quickSort(tReturn *rep, int inicio, int fim) {
    int posPivo;

    if(inicio < fim){
        posPivo = particiona(rep, inicio, fim);
        quickSort(rep, inicio, posPivo-1);
        quickSort(rep, posPivo+1, fim);
    }
}

int particiona(tReturn *rep, int inicio, int fim) {
    int pivo = rep->vet[inicio];
    int pos = inicio, aux;

    for(int i=inicio+1; i<=fim; i++){
        (rep->comps)++;
        if(rep->vet[i] < pivo){
            pos++;
            if(i != pos){
                (rep->trocas)++;
                aux = rep->vet[i];
                rep->vet[i] = rep->vet[pos];
                rep->vet[pos] = aux;
            }
        }
    }

    rep->trocas++;
    aux = rep->vet[inicio];
    rep->vet[inicio] = rep->vet[pos];
    rep->vet[pos] = aux;

    return pos;
}

void dualPivotQuickSort(tReturn *rep, int inicio, int fim){
    if(inicio < fim){
        int pivoEsq, pivoDir;
        pivoDir = particionaDual(rep, inicio, fim, &pivoEsq);
        dualPivotQuickSort(rep, inicio, pivoEsq - 1);
        dualPivotQuickSort(rep, pivoEsq + 1, pivoDir - 1);
        dualPivotQuickSort(rep, pivoDir + 1, fim);
    }
}

int particionaDual(tReturn *rep, int inicio, int fim, int *pivEsq){
    int aux;
    //Verifica se o primeiro elemento e maior que o ultimo, se sim, trocam de lugar
    rep->comps++;
    if(rep->vet[inicio] > rep->vet[fim]) {
        (rep->trocas)++;
        aux = rep->vet[inicio];
        rep->vet[inicio] = rep->vet[fim];
        rep->vet[fim] = aux;
    }

    int k = inicio + 1;

    int i = inicio + 1;
    int j = fim - 1;

    //Pivo Esquerdo e Pivo Direito recebem posicao inicio e posicao fim respectivamente
    int pE = rep->vet[inicio], pD = rep->vet[fim];

    for(i; i <= j; i++){    //Se elementos sao menores que o pivo esquerdo
        (rep->comps)++;
        if(rep->vet[i] < pE){
            (rep->trocas)++;
            aux = rep->vet[i];
            rep->vet[i] = rep->vet[k];
            rep->vet[k] = aux;
            k++;
        }
            //Se elementos sao maiores ou iguais ao pivo direito
        else if(rep->vet[i] >= pD){
            while(rep->vet[j] > pD && i < j){
                j--;
                (rep->comps)++;
            }
            (rep->trocas)++;
            aux = rep->vet[i];
            rep->vet[i] = rep->vet[j];
            rep->vet[j] = aux;
            j--;
            (rep->comps)++;
            if(rep->vet[i] < pE){
                (rep->trocas)++;
                aux = rep->vet[i];
                rep->vet[i] = rep->vet[k];
                rep->vet[k] = aux;
                k++;
            }
        }
    }
    k--;
    j++;

    //Coloca os pivos nas suas devidas posicoes
    (rep->trocas)++;
    aux = rep->vet[inicio];
    rep->vet[inicio] = rep->vet[k];
    rep->vet[k] = aux;

    (rep->trocas)++;
    aux = rep->vet[fim];
    rep->vet[fim] = rep->vet[j];
    rep->vet[j] = aux;

    //retorna os indices dos Pivos
    *pivEsq = k;
    return j;
}

int buscaBinaria(tReturn *rep, int inicio, int fim, int valor){
    int meio = (inicio + fim) / 2;

    (rep->comps)++;
    if(inicio > fim){
        return -1;
    }
    (rep->comps)++;
    if(rep->vet[meio] == valor){
        return meio;
    }
    (rep->comps)++;
    if(rep->vet[meio] < valor){
        buscaBinaria(rep, meio + 1, fim, valor);
    }else{
        buscaBinaria(rep, inicio, meio - 1, valor);
    }
}

int buscaLinear(tReturn *rep, int num){
    for(int i = 0; i < rep->tam; i++){
        (rep->comps)++;
        if(rep->vet[i]==num){
            return i;
        }
    }

    return -1;
}

int salvaOrdenado(char *nomeArquivo, int *vet, int tam){
    FILE *arq;
    arq = fopen(nomeArquivo, "w");

    for (int i=0; i<tam; i++){
        fprintf(arq, "%d\n", vet[i]);
    }

    fclose(arq);

    if(arq==NULL){
        return 1;
    }else{
        return 0;
    }
}

int salvaMetricas(char *nomeArquivo, double tempo, double trocas, double comps){
    FILE *arq;
    arq = fopen(nomeArquivo, "w");

    fprintf(arq, "\nNúmero de comparações de chaves: %.0f\n", comps);
    printf("\nNúmero de comparações de chaves: %.0f\n", comps);
    fprintf(arq, "Número de cópias de registros (trocas): %.0f\n", trocas);
    printf("Número de cópias de registros (trocas): %.0f\n", trocas);
    fprintf(arq, "Tempo de execução (ciclos de clock): %.0lf\n", tempo);
    printf("Tempo de execução (ciclos de clock): %.0lf\n", tempo);

    fclose(arq);

    if(arq==NULL){
        return 1;
    }else{
        return 0;
    }
}

int salvaBusca(char *nomeArquivo, double tempoLinear, double compsLinear, double tempoBinaria, double compsBinaria){
    FILE *arq;
    arq = fopen(nomeArquivo, "w");

    fprintf(arq, "\nBusca Linear:\n");
    printf("\nBusca Linear:\n");
    fprintf(arq, "Número de comparações de chaves: %.0f\n", compsLinear);
    printf("Número de comparações de chaves: %.0f\n", compsLinear);
    fprintf(arq, "Tempo de execução (ciclos de clock): %.0lf\n", tempoLinear);
    printf("Tempo de execução (ciclos de clock): %.0lf\n", tempoLinear);

    fprintf(arq, "\nBusca Binária:\n");
    printf("\nBusca Binária:\n");
    fprintf(arq, "Número de comparações de chaves: %.0f\n", compsBinaria);
    printf("Número de comparações de chaves: %.0f\n", compsBinaria);
    fprintf(arq, "Tempo de  (ciclos de clock): %.0lf", tempoBinaria);
    printf("Tempo de execução (ciclos de clock): %.0lf", tempoBinaria);

    fclose(arq);

    if(arq==NULL){
        return 1;
    }else{
        return 0;
    }
}

int geraAleatorios(char *nomeArquivo, int qtd){
    srand(time(NULL));

    FILE *arq;
    arq = fopen(nomeArquivo, "w");

    fprintf(arq, "%d\n", qtd);

    for (int i=0; i<qtd; i++){
        fprintf(arq, "%d\n", rand()%qtd);
    }

    if(arq==NULL){
        return 1;
    }else{
        fclose(arq);
        return 0;
    }
}

int geraCrescente(char *nomeArquivo, int qtd){
    FILE *arq;
    arq = fopen(nomeArquivo, "w");

    fprintf(arq, "%d\n", qtd);

    for (int i=0; i<qtd; i++){
        fprintf(arq, "%d\n", i);
    }

    if(arq==NULL){
        return 1;
    }else{
        fclose(arq);
        return 0;
    }
}

int geraDecrescente(char *nomeArquivo, int qtd){
    FILE *arq;
    arq = fopen(nomeArquivo, "w");

    fprintf(arq, "%d\n", qtd);

    for (int i=qtd; i>0; i--){
        fprintf(arq, "%d\n", i);
    }

    if(arq==NULL){
        return 1;
    }else{
        fclose(arq);
        return 0;
    }
}