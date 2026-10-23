
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bubblesort(int *vet,int n,long long int *comparacoes,long long int *trocas){
    int i,j;
    
    for(i = 0; i < n; i++){

        for(j = 0; j < n - 1 - i; j++){
            (*comparacoes)++;
            if(vet[j] > vet[j + 1]){
                int temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
                (*trocas)++;
                
            }
        }
    }
}

int main() {

    int tam = 1000000;
    int *vet = (int *)malloc(tam * sizeof(int));

    FILE *instancia = fopen("..\\..\\instancias\\1000000_ordenado_decrescente.txt","r");
    if(instancia != NULL){
        int i = 0;

        while(i<1000000 && fscanf(instancia,"%d",&vet[i])==1){
            i++;
        }
    }
    long long int comparacoes = 0;
    long long int trocas = 0;
  
    clock_t inicio = clock();
    
    bubblesort(vet,tam,&comparacoes,&trocas);

    clock_t fim = clock();


    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo de execucao: %f segundos\n", tempo_gasto);


    printf("Comparacoes = %d",comparacoes);

    printf("Trocas = %d\n", trocas);

    FILE *arquivo = fopen("saida_decrescente.txt","a");
    if (arquivo != NULL) {
        for(int i = 0; i < tam; i++){
            fprintf(arquivo,"%d\n",vet[i]);
        }

        fprintf(arquivo,"Comp:%lld Trocas:%lld Tempo:%lf\n",comparacoes,trocas,tempo_gasto);
        fclose(arquivo);
    }
    free(vet);

    return 0;

}
