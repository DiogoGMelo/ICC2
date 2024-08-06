#include <stdio.h>
#include <stdlib.h>
// Diogo Gianezi de Melo - 12563522
// Raphael Monteiro Consoni Bonaccorsi - 12563366
// Matheus Rodrigues dos Santos - 11212866

int compara(const void *a,const void *b){
    return (*(int*)a - *(int*)b);
} 

int main(){
    int N,K;

    scanf("%d",&N);
    int vetor[N];
    for(int i = 0;i<N;i++){
        scanf("%d",&vetor[i]);
    }

    qsort(vetor, N, sizeof(int), compara);

    scanf("%d",&K);
    for(int i = 0;i<K;i++){
        int e;
        scanf("%d",&e);

        int *resultado = (int *)bsearch(&e, vetor, N, sizeof(int), compara);

        if(resultado != NULL){
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
    return 0;
}
