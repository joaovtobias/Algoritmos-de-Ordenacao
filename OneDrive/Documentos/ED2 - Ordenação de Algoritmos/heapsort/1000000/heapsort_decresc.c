#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void heapify(int *vet, int n, int i, long long int *comparacoes, long long int *trocas) {
    int maior = i;          
    int esquerda = 2 * i + 1; 
    int direita = 2 * i + 2;  

   
    if (esquerda < n) {
        (*comparacoes)++;
        if (vet[esquerda] > vet[maior]) {
            maior = esquerda;
        }
    }

    
    if (direita < n) {
        (*comparacoes)++;
        if (vet[direita] > vet[maior]) {
            maior = direita;
        }
    }

    
    if (maior != i) {
        int aux = vet[i];
        vet[i] = vet[maior];
        vet[maior] = aux;
        (*trocas)++;

        heapify(vet, n, maior, comparacoes, trocas);
    }
}

void heapSort(int *vet, int n, long long int *comparacoes, long long int *trocas) {
    
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(vet, n, i, comparacoes, trocas);
    }

   
    for (int i = n - 1; i > 0; i--) {
   
        int aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        (*trocas)++;

      
        heapify(vet, i, 0, comparacoes, trocas);
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
    
    heapSort(vet, tam, &comparacoes, &trocas);

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