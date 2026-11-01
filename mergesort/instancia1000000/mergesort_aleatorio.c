#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intercalar(int *vet,int ini,int meio, int fim, long long int *comparacoes,long long int *trocas){
    int i,j,k,n1 = meio - ini + 1;
    int n2 = fim - meio;

    int *esquerda = malloc(n1 * sizeof(int));
    int *direita = malloc(n2 * sizeof(int));

    for(i = 0; i < n1; i++)
        esquerda[i] = vet[ini + i];
    for(j = 0; j < n2; j++)
        direita[j] = vet[meio + 1 + j];

    i = 0, j = 0, k = ini;
    while(i < n1 && j < n2){
        (*comparacoes)++;
        if(esquerda[i] <= direita[j])
            vet[k++] = esquerda[i++];
        else
            vet[k++] = direita[j++];
        (*trocas)++;
    }

    while(i < n1){
        vet[k++] = esquerda[i++];
        (*trocas)++;
    }
    while(j < n2){
        vet[k++] = direita[j++];
        (*trocas)++;
    }

    free(esquerda);
    free(direita);
}

void mergeSort(int *vet,int ini, int fim, long long int *comparacoes, long long int *trocas){
    if(ini < fim){
        int meio = ini + (fim - ini) / 2 ;
        mergeSort(vet,ini,meio,comparacoes,trocas);
        mergeSort(vet,meio + 1,fim,comparacoes,trocas);
        intercalar(vet,ini,meio,fim,comparacoes,trocas);
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
    
    mergeSort(vet,0,tam-1,&comparacoes,&trocas);

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