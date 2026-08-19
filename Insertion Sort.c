#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para preencher o vetor com números aleatórios
void preencherAleatorio(long long int vetor[], int tamanho) {
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 200000; // Intervalo de 0 a 999 para facilitar a visualização
    }
}

// Função para preencher o vetor em ordem crescente
void preencherCrescente(long long int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i;
    }
}

// Função para preencher o vetor em ordem decrescente
void preencherDecrescente(long long int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - i;
    }
}

// Função para trocar dois elementos de posição em um vetor
void trocar(long long int *a, long long int *b) {
    long long int temp = *a;
    *a = *b;
    *b = temp;
}

// Função que implementa o algoritmo Insertion Sort
void insertionSort(long long int vetor[], long long int tamanho, long long int *comparacoes, long long int *trocas) {
    for (long long int i = 1; i < tamanho; i++) {
        long long int chave = vetor[i];
        long long int j = i - 1;
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
            (*trocas)++;
            (*comparacoes)++;
        }
        vetor[j + 1] = chave;
    }
    // No final, a quantidade de comparações será o número de elementos - 1
    (*comparacoes) = tamanho - 1;
}

int main() {
    int tamanho, opcao;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    long long int vetor[tamanho];
    long long int comparacoes = 0, trocas = 0;
    printf("Escolha a ordem do vetor:\n");
    printf("1. Crescente\n");
    printf("2. Decrescente\n");
    printf("3. Aleatorio\n");
    scanf("%d", &opcao);
    switch(opcao) {
        case 1:
            preencherCrescente(vetor, tamanho);
            break;
        case 2:
            preencherDecrescente(vetor, tamanho);
            break;
        case 3:
            preencherAleatorio(vetor, tamanho);
            break;
        default:
            printf("Opcao invalida!\n");
            return 1;
    }
    clock_t inicio = clock();
    insertionSort(vetor, tamanho, &comparacoes, &trocas);
    clock_t fim = clock();
    double tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("\n");
    printf("Tempo de execucao: %.6f segundos\n", tempo_execucao);
    printf("Numero de comparacoes: %lld\n", comparacoes);
    printf("Numero de trocas: %lld\n", trocas);
    return 0;
}
