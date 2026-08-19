#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shellSort(int *vetor, int tamanho, long long int *comparacoes, int *trocas) {
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
            (*comparacoes)++;
            while (proximo > salto - 1 && valor <= vetor[proximo - salto]) {
                vetor[proximo] = vetor[proximo - salto];
                proximo = proximo - salto;
                (*comparacoes)++;
                (*trocas)++;
            }
            vetor[proximo] = valor;
        }
        salto = salto / 3;
    }
}

int main() {
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    // Criando vetor em ordem crescente
    int vetor[tamanho];
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = i + 1;
    }

    clock_t inicio = clock(); // Registra o tempo de início

    long long int comparacoes = 0;
    int trocas = 0;

    shellSort(vetor, tamanho, &comparacoes, &trocas);

    clock_t fim = clock(); // Registra o tempo de fim
    double tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC ; // Calcula o tempo de execução em segundos

    printf("\n\nNumero de comparacoes: %lld", comparacoes);
    printf("\nNumero de trocas: %d", trocas);
    printf("\nTempo de execucao: %.2f segundos\n", tempo_execucao);

    return 0;
}
