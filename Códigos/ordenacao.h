#ifndef ORDENACAO_1_ORDENACAO_H
#define ORDENACAO_1_ORDENACAO_H

typedef struct tReturn tReturn;

tReturn* alocatReturn();
//Aloca memória para tReturn

tReturn* leArquivo(tReturn *rep, char *nomeArquivo);
//Faz a leitura do arquivo e inicializa as variáveis de tReturn

int *getVet(tReturn *rep);
//Retorna o vetor

int getTam(tReturn *rep);
//Retorna o tamanho do vetor

double getTrocas(tReturn *rep);
//Retorna o número de trocas feitas no vetor durante a ordenação

double getComps(tReturn *rep);
//Retorna o número de comparações feitas entre as chaves do vetor

void bolha(tReturn *rep);
//Ordenação por Bolha

void bolhaInteligente(tReturn *rep);
//Ordenação por Bolha Inteligente

void selecao(tReturn *rep);
//Ordenação por Seleção

void insercao(tReturn *rep);
//Ordenação por Inserção

void mergeSort(tReturn *rep, int inicio, int fim);
//Ordenação por MergeSort

void merge(tReturn *rep, int inicio, int meio, int fim);
//Concatenação do MergeSort

void quickSort(tReturn *rep, int inicio, int fim);
//Ordenação pelo algoritmo QuickSort

int particiona(tReturn *rep, int inicio, int fim);
//Particionamento do QuickSort

void dualPivotQuickSort(tReturn *rep, int inicio, int fim);
//Ordenação por Dual-Pivot QuickSort

int particionaDual(tReturn *rep, int inicio, int fim, int *pivEsq);
//Particionamento do Dual-Pivot QuickSort

int buscaBinaria(tReturn *rep, int inicio, int fim, int valor);
//Implementação da busca binária em um vetor ordenado

int buscaLinear(tReturn *rep, int num);
//Busca linear em um vetor (ordenado ou não)

int salvaOrdenado(char *nomeArquivo, int *vet, int tam);
//Salva o vetor ordenado em um arquivo

int salvaMetricas(char *nomeArquivo, double tempo, double trocas, double comps);
//Salva as métricas da ordenação de um vetor

int salvaBusca(char *nomeArquivo, double tempoLinear, double compsLinear, double tempoBinaria, double compsBinaria);
//Salva as métricas de busca em um vetor

int geraAleatorios(char *nomeArquivo, int qtd);
//Gera n números aleatórios e salva em um arquivo

int geraCrescente(char *nomeArquivo, int qtd);
//Gera n números ordenado de forma crescente e salva em um arquivo

int geraDecrescente(char *nomeArquivo, int qtd);
//Gera n números ordenados de forma decrescente e salva em um arquivo

#endif