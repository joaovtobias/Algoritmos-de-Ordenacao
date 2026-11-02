#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionsort(int *vet, int n, int *comparacoes, int *trocas) {
    int i, j, aux;
    
    for (i = 1; i < n; i++) {
        aux = vet[i]; 
        j = i - 1;
        
        
        while (j >= 0 && ( (*comparacoes)++, vet[j] > aux )) {
            vet[j + 1] = vet[j];
            (*trocas)++;
            j--;
        }
        
        if(j != i + 1){
        vet[j + 1] = aux;
        }
    }
}

int main(int argc, char *argv[]) {
    int vet[1000000]; 

   if(argc < 2){
        printf("Forma correta: %s <caminho_relativo_instancias>",argv[0]);
    }

    FILE *instancia = fopen(argv[1], "r");

    if(instancia != NULL){
        int i = 0;
        while(i < 1000000 && fscanf(instancia, "%d", &vet[i]) == 1){
            i++;
        }
        fclose(instancia);
    } else {
        printf("Erro ao abrir o arquivo de instancia.\n");
        return 1;
    }
    
    int tam = 1000000;
    int comparacoes = 0;
    int trocas = 0;
  
    clock_t inicio = clock();
    
    insertionsort(vet, tam, &comparacoes, &trocas);

    clock_t fim = clock();

    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo de execucao: %f segundos\n", tempo_gasto);


    printf("Comparacoes = %d\n", comparacoes);

    printf("Trocas = %d\n", trocas);


    FILE *arquivo = fopen("saida_aleatorio.txt","w");

    if (arquivo != NULL) {
        for(int i = 0; i < tam; i++){
            fprintf(arquivo, "%d\n", vet[i]);
        }

        fprintf(arquivo, "Comp:%d Trocas:%d Tempo:%lf\n", comparacoes, trocas, tempo_gasto);

        fclose(arquivo);
    }

    return 0;
}