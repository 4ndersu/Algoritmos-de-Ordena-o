#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int comparisons = 0;
long long int swaps = 0;

void swap(long long int* a, long long int* b) {
    if (*a != *b) {
        long long int t = *a;
        *a = *b;
        *b = t;
        swaps++;
    }
}

int partition(long long int arr[], int low, int high) {
    long long int pivot = arr[low]; // Alterando para o primeiro elemento como pivô
    int i = low;

    for (int j = low + 1; j <= high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[i]); // Colocando o pivô em sua posição correta
    return i;
}

void quickSort(long long int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    long long int arr[n];
    for(int i = 0; i < n; i++) {
        arr[i] = i;
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Tempo de execução: %f segundos\n", cpu_time_used);
    printf("Número de comparações: %lld\n", comparisons);
    printf("Número de trocas: %lld\n", swaps);

    return 0;
}