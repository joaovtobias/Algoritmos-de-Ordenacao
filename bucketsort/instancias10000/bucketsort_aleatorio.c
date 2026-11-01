#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSortBucket(int arr[], int n,long long int *comparacoes,long long int *trocas) {
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

void bucketSort(int vetor[],int n,long long int *comparacoes,long long int *trocas) {
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
    int buckets[num_buckets][n];
    int bucket_counts[num_buckets];

    for (int i = 0; i < num_buckets; i++) {
        bucket_counts[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int idx = 0;
        if (max != min) {
            idx = (vetor[i] - min) * (num_buckets - 1) / (max - min);
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
    }
}

int main(int argc, char *argv[]) {

    int vet[10000]; 
    if(argc < 2){
        printf("Forma correta: %s <caminho_relativo_instancias>",argv[0]);
    }

    FILE *instancia = fopen(argv[1],"r");
    if(instancia != NULL){
        int i = 0;

        while(i<10000 && fscanf(instancia,"%d",&vet[i])==1){
            i++;
        }
    }
    int tam = sizeof(vet)/sizeof(vet[0]);
    long long int comparacoes = 0;
    long long int trocas = 0;
  
    clock_t inicio = clock();
    
    bucketSort(vet,tam,&comparacoes,&trocas);

    clock_t fim = clock();


    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo de execucao: %f segundos\n", tempo_gasto);


    printf("Comparacoes = %lld",comparacoes);

    FILE *arquivo = fopen("saida_aleatorio.txt","w");
    if (arquivo != NULL) {
        for(int i = 0; i < tam; i++){
            fprintf(arquivo,"%d\n",vet[i]);
        }

        fprintf(arquivo,"Comp:%lld Trocas:%lld Tempo:%lf\n",comparacoes,trocas,tempo_gasto);
        fclose(arquivo);
    }

    return 0;

}