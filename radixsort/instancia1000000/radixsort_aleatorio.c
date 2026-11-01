#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int getMax(int *vetor, int n, long long int *comparacoes) {
    int max = vetor[0];
    for (int i = 1; i < n; i++) {
        (*comparacoes)++;
        if (vetor[i] > max) {
            max = vetor[i];
        }
    }
    return max;
}

void countSort(int *vetor, int n, int exp, long long int *trocas) {
    int output[n]; 
    int count[10] = {0}; 
    int i;

    // Conta a ocorrência dos dígitos
    for (i = 0; i < n; i++) {
        count[(vetor[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (i = n - 1; i >= 0; i--) {
        int digito = (vetor[i] / exp) % 10;
        output[count[digito] - 1] = vetor[i];
        count[digito]--;
        
        (*trocas)++; 
    }

    for (i = 0; i < n; i++) {
        vetor[i] = output[i];
        
        (*trocas)++;
    }
}
void radixSort(int *vetor, int n, long long int *comparacoes, long long int *trocas) {
    int max = getMax(vetor, n, comparacoes);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(vetor, n, exp, trocas);
    }
}

int main(int argc, char *argv[]) {

    int vet[1000000]; 
    if(argc < 2){
        printf("Forma correta: %s <caminho_relativo_instancias>",argv[0]);
    }

    FILE *instancia = fopen(argv[1],"r");
    if(instancia != NULL){
        int i = 0;

        while(i<1000000 && fscanf(instancia,"%d",&vet[i])==1){
            i++;
        }
    }
    int tam = sizeof(vet)/sizeof(vet[0]);
    long long int comparacoes = 0;
    long long int trocas = 0;
  
    clock_t inicio = clock();
    
    radixSort(vet,tam,&comparacoes,&trocas);

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