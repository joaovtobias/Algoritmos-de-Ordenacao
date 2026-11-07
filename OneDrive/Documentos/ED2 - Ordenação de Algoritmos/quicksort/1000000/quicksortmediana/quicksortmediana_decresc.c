#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int *a, int *b, long long int *trocas) {
    int temp = *a;
    *a = *b;
    *b = temp;
    (*trocas)++;
}


int medianaDeTres(int *vet, int inicio, int fim, long long int *comparacoes, long long int *trocas) {
    int meio = inicio + (fim - inicio) / 2;

    
    (*comparacoes)++;
    if (vet[inicio] > vet[meio]) trocar(&vet[inicio], &vet[meio], trocas);
    
    (*comparacoes)++;
    if (vet[inicio] > vet[fim]) trocar(&vet[inicio], &vet[fim], trocas);
    
    (*comparacoes)++;
    if (vet[meio] > vet[fim]) trocar(&vet[meio], &vet[fim], trocas);

    
    trocar(&vet[meio], &vet[inicio], trocas);
    return inicio;
}

int particionarMediana(int *vet, int inicio, int fim, long long int *comparacoes, long long int *trocas) {
  
    medianaDeTres(vet, inicio, fim, comparacoes, trocas);
    
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

void quicksortMediana(int *vet, int inicio, int fim, long long int *comparacoes, long long int *trocas) {
    if (inicio < fim) {
        int meio = particionarMediana(vet, inicio, fim, comparacoes, trocas);

        quicksortMediana(vet, inicio, meio - 1, comparacoes, trocas);

        quicksortMediana(vet, meio + 1, fim, comparacoes, trocas);
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

    int tam = 1000000; 
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

    quicksortMediana(vet, 0, tam - 1, &comparacoes, &trocas);

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