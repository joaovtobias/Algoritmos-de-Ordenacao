#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int *a, int *b, long long int *trocas) {
    int temp = *a;
    *a = *b;
    *b = temp;
    (*trocas)++;
}

int particionarInicio(int *vet, int inicio, int fim, long long int *comparacoes, long long int *trocas) {
    int pivo = vet[inicio];
    int i = inicio + 1;
    int j = fim;

    while (1) {
        while (i <= fim) {
            (*comparacoes)++;
            if (vet[i] < pivo) {
                i++;
            } else {
                break;
            }
        }

        while (j > inicio) {
            (*comparacoes)++;
            if (vet[j] > pivo) {
                j--;
            } else {
                break;
            }
        }

        if (i >= j) {
            break;
        }

        trocar(&vet[i], &vet[j], trocas);
        i++;
        j--;
    }

    trocar(&vet[inicio], &vet[j], trocas);

    return j;
}

void quicksortInicio(int *vet, int inicio, int fim, long long int *comparacoes, long long int *trocas) {
    if (inicio < fim) {
        int meio = particionarInicio(vet, inicio, fim, comparacoes, trocas);

        quicksortInicio(vet, inicio, meio - 1, comparacoes, trocas);

        quicksortInicio(vet, meio + 1, fim, comparacoes, trocas);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Forma correta: %s <caminho_relativo_instancias>\n", argv[0]);
        return 1;
    }

    FILE *instancia = fopen(argv[1], "r");
    if (instancia == NULL) {
        printf("Erro ao abrir o arquivo de instancia.\n");
        return 1;
    }


    int tam = 10000; 
    int *vet = (int *)malloc(tam * sizeof(int));
    if (vet == NULL) {
        printf("Erro de alocacao de memoria.\n");
        fclose(instancia);
        return 1;
    }

    int i = 0;
    while (i < tam && fscanf(instancia, "%d", &vet[i]) == 1) {
        i++;
    }
    fclose(instancia);
    tam = i; 

    long long int comparacoes = 0;
    long long int trocas = 0;

    clock_t inicio = clock();

    quicksortInicio(vet, 0, tam - 1, &comparacoes, &trocas);

    clock_t fim = clock();

    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo de execucao: %f segundos\n", tempo_gasto);
    printf("Comparacoes = %lld\n", comparacoes);
    printf("Trocas = %lld\n", trocas);

    FILE *arquivo = fopen("saida_decresc.txt", "w");

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