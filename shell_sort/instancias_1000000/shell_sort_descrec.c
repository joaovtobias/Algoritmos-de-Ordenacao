#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shellsort(int *vet,int tam,long long int *comp,long long int *trocas){
    int gap,copia,i,j;

    for(gap = tam/2; gap > 0; gap /= 2){

        for(i = gap; i < tam; i++){
        copia = vet[i];

        for(j = i; j >= gap; j -= gap){
            (*comp)++;
            if(vet[j - gap] > copia){
                vet[j] = vet[j - gap];
                (*trocas)++;
            }
            else{
                break;
            }
        }
        vet[j] = copia;
        (*trocas)++;
        }
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
    
    shellsort(vet,tam,&comparacoes,&trocas);

    clock_t fim = clock();


    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo de execucao: %f segundos\n", tempo_gasto);


    printf("Comparacoes = %lld",comparacoes);

    FILE *arquivo = fopen("saida_decrescente.txt","w");
    if (arquivo != NULL) {
        for(int i = 0; i < tam; i++){
            fprintf(arquivo,"%d\n",vet[i]);
        }

        fprintf(arquivo,"Comp:%lld Trocas:%lld Tempo:%lf\n",comparacoes,trocas,tempo_gasto);
        fclose(arquivo);
    }

    return 0;

}