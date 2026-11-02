#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int *vet, int n, long long *comparacoes, long long *trocas) {
    int i, j, min_idx, aux;
    
    for (i = 0; i < n - 1; i++) {
        min_idx = i; 
        
        for (j = i + 1; j < n; j++) {
            (*comparacoes)++;
            if (vet[j] < vet[min_idx]) {
                min_idx = j; 
            }
        }
        
        
        if (min_idx != i) {
            aux = vet[i];
            vet[i] = vet[min_idx];
            vet[min_idx] = aux;
            (*trocas)++;
        }
    }
}

int main(int argc, char *argv[]) {
    int vet[1000000]; 

    if(argc < 2){
        printf("Forma correta: %s <caminho_relativo_instancias>",argv[0]);
    }

    FILE *instancia = fopen(argv[1], "r");
    
    if (instancia != NULL) {
        int i = 0;
        while (i < 1000000 && fscanf(instancia, "%d", &vet[i]) == 1) {
            i++;
        }
        fclose(instancia);
    } else {
        printf("Erro ao abrir o arquivo de instancia.\n");
        return 1;
    }
    
    int tam = 1000000;
    long long comparacoes = 0;
    long long trocas = 0;
  
    clock_t inicio = clock();
    
    selectionSort(vet, tam, &comparacoes, &trocas);

    clock_t fim = clock();

    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo de execucao: %f segundos\n", tempo_gasto);

    printf("Comparacoes = %lld\n", comparacoes);
    
    printf("Trocas = %lld\n", trocas);

    FILE *arquivo = fopen("saida_aleatorio.txt", "w");
    if (arquivo != NULL) {
        for (int i = 0; i < tam; i++) {
            fprintf(arquivo, "%d\n", vet[i]);
        }

        fprintf(arquivo, "Comp:%lld Trocas:%lld Tempo:%lf\n", comparacoes, trocas, tempo_gasto);
        fclose(arquivo);
    }

    return 0;
}