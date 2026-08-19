#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shellSort(int *vetor, int tamanho, long long int *comparacoes, long long int *trocas) {
    int atual = 0;
    int proximo = 0;
    int valor = 0;
    int salto = 1;

    while (salto < tamanho) {
        salto = 3 * salto + 1;
    }
   
    while (salto > 0) {
        for (atual = salto; atual < tamanho; atual++) {
            valor = vetor[atual];
            proximo = atual;
            while (proximo > salto - 1 && valor < vetor[proximo - salto]) {
                vetor[proximo] = vetor[proximo - salto];
                proximo = proximo - salto;
                (*trocas)++;
            }
            (*comparacoes)++;
            vetor[proximo] = valor;
        }
        salto = salto / 3;
    }
}

int main() {
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    // Criando vetor com números aleatórios
    int vetor[tamanho];
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 30000;
    }

    clock_t inicio = clock();

    long long int comparacoes = 0;
    long long int trocas = 0;

    shellSort(vetor, tamanho, &comparacoes, &trocas);

    clock_t fim = clock();
    double tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC ;

    printf("\n\nNumero de comparacoes: %lld", comparacoes);
    printf("\nNumero de trocas: %lld", trocas);
    printf("\nTempo de execucao: %.2f segundos\n", tempo_execucao);

    return 0;
}
