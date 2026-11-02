#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int buscaBinaria(int *vet, int item, int inicio, int fim, long long int *comparacoes) {
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        (*comparacoes)++;
        
        if (item == vet[meio]) {
            return meio + 1; 
        } else if (item > vet[meio]) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return inicio;
}

void binaryInsertionSort(int *vet, int n, long long int *comparacoes, long long int *trocas) {
    int i, j, item, posicao;
    
    for (i = 1; i < n; i++) {
        item = vet[i];
        
        
        posicao = buscaBinaria(vet, item, 0, i - 1, comparacoes);
        
        
        for (j = i - 1; j >= posicao; j--) {
            vet[j + 1] = vet[j];
            (*trocas)++;
        }
        
        
        vet[posicao] = item;
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
    long long int comparacoes = 0;
    long long int trocas = 0;
  
    clock_t inicio = clock();
    
    binaryInsertionSort(vet, tam, &comparacoes, &trocas);

    clock_t fim = clock();

    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo de execucao: %f segundos\n", tempo_gasto);

    printf("Comparacoes = %lld\n", comparacoes);

    printf("Trocas = %lld\n", trocas);

    FILE *arquivo = fopen("saida_decresc.txt", "w");
    if (arquivo != NULL) {
        for (int i = 0; i < tam; i++) {
            fprintf(arquivo, "%d\n", vet[i]);
        }

        fprintf(arquivo, "Comp:%lld Trocas:%lld Tempo:%lf\n", comparacoes, trocas, tempo_gasto);
        fclose(arquivo);
    }

    return 0;
}