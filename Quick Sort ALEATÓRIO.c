#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int num_comparacoes = 0;
long long int num_trocas = 0;

// Função para trocar dois elementos em um vetor
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para encontrar o pivô e particionar o vetor
int particionar(int vetor[], int inicio, int fim) {
    int pivo = vetor[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        num_comparacoes++;
        if (vetor[j] < pivo) {
            i++;
            trocar(&vetor[i], &vetor[j]);
            num_trocas++; // Incrementando o número de trocas aqui
        }
    }
    trocar(&vetor[i + 1], &vetor[fim]);
    num_trocas++; // Incrementando o número de trocas quando o pivô é colocado em sua posição final
    return (i + 1);
}

// Função principal do Quick Sort
void quickSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int p = particionar(vetor, inicio, fim);
        quickSort(vetor, inicio, p - 1);
        quickSort(vetor, p + 1, fim);
    }
}

int main() {
    long long int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%lld", &tamanho);

    // Alocando memória para o vetor
    int *vetor = (int *)malloc(tamanho * sizeof(int));

    // Preenchendo o vetor com números aleatórios entre 0 e 99999
    srand(time(NULL));
    for (long long int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100000; // Gera um número aleatório entre 0 e 99999
    }

    // Registrando o tempo de início
    clock_t inicio = clock();

    // Ordenando o vetor usando o Quick Sort
    quickSort(vetor, 0, tamanho - 1);

    // Registrando o tempo de término e calculando o tempo de execução
    clock_t fim = clock();
    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    // Exibindo o tempo de execução, número de comparações e trocas
    printf("Tempo de execucao: %f segundos\n", tempo_execucao);
    printf("Numero de comparacoes: %lld\n", num_comparacoes);
    printf("Numero de trocas: %lld\n", num_trocas);

    // Liberando a memória alocada para o vetor
    free(vetor);

    return 0;
}