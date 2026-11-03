#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSortBucket(int arr[], int n, long long int *comparacoes, long long int *trocas) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0) {
            (*comparacoes)++;
            if (arr[j] > temp) {
                arr[j + 1] = arr[j];
                (*trocas)++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = temp;
        (*trocas)++;
    }
}

void bucketSort(int vetor[], int n, long long int *comparacoes, long long int *trocas) {
    if (n <= 0) return;

    int max = vetor[0];
    int min = vetor[0];
    for (int i = 1; i < n; i++) {
        (*comparacoes)++;
        if (vetor[i] > max) {
            max = vetor[i];
        } else {
            (*comparacoes)++;
            if (vetor[i] < min) {
                min = vetor[i];
            }
        }
    }

    int num_buckets = n;
    int *bucket_counts = (int *)calloc(num_buckets, sizeof(int));
    int *bucket_capacities = (int *)malloc(num_buckets * sizeof(int));
    int **buckets = (int **)malloc(num_buckets * sizeof(int *));

    for (int i = 0; i < num_buckets; i++) {
        bucket_capacities[i] = 2;
        buckets[i] = (int *)malloc(bucket_capacities[i] * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        int idx = 0;
        if (max != min) {
            idx = (int)(((long long)(vetor[i] - min) * (num_buckets - 1)) / (max - min));
        }
        if (bucket_counts[idx] >= bucket_capacities[idx]) {
            bucket_capacities[idx] *= 2;
            buckets[idx] = (int *)realloc(buckets[idx], bucket_capacities[idx] * sizeof(int));
        }
        buckets[idx][bucket_counts[idx]] = vetor[i];
        bucket_counts[idx]++;
        (*trocas)++;
    }

    for (int i = 0; i < num_buckets; i++) {
        if (bucket_counts[i] > 1) {
            insertionSortBucket(buckets[i], bucket_counts[i], comparacoes, trocas);
        }
    }

    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < bucket_counts[i]; j++) {
            vetor[index++] = buckets[i][j];
            (*trocas)++;
        }
        free(buckets[i]);
    }
    free(buckets);
    free(bucket_capacities);
    free(bucket_counts);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Forma correta: %s <caminho_relativo_instancias>\n", argv[0]);
        return 1;
    }

    FILE *instancia = fopen(argv[1], "r");
    if (instancia == NULL) {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    int tam = 10000;
    int *vet = (int *)malloc(tam * sizeof(int));
    int i = 0;
    while (i < tam && fscanf(instancia, "%d", &vet[i]) == 1) {
        i++;
    }
    fclose(instancia);

    long long int comparacoes = 0;
    long long int trocas = 0;

    clock_t inicio = clock();
    bucketSort(vet, tam, &comparacoes, &trocas);
    clock_t fim = clock();

    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo de execucao: %f segundos\n", tempo_gasto);
    printf("Comparacoes = %lld\n", comparacoes);
    printf("Trocas = %lld\n", trocas);

    FILE *arquivo = fopen("saida_decrescente.txt", "w");
    if (arquivo != NULL) {
        for (int k = 0; k < tam; k++) {
            fprintf(arquivo, "%d\n", vet[k]);
        }
        fprintf(arquivo, "Comp:%lld Trocas:%lld Tempo:%lf\n", comparacoes, trocas, tempo_gasto);
        fclose(arquivo);
    }

    free(vet);
    return 0;
}
