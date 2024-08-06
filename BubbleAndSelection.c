#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void trocar(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}





void bolha (int *ordenar,int n){
   int i,last,sent;
   last=n-1;
   while(last>0){
        sent=-1;
        for(i=0;i<last;i++){
            printf("C %i %i\n", i, i + 1);
            if (ordenar[i]>ordenar[i+1]){
                printf("T %i %i\n", i, i + 1);
                trocar(&ordenar[i],&ordenar[i+1]);
                sent=i;
            }
        }
        last=sent;
        if (sent==-1){
            break;
        }
   }


    for(int i=0;i<n;i++){
            printf("%d ",ordenar[i]);
        }
}



void selecao(int *ordenar,int n){
    int i,mini,j,sent;
    for(i=0;i<n-1;i++){
        mini=i;
        sent=0;
        for(j=i+1;j<n;j++){
            printf("C %d %d\n",mini,j);
            if(ordenar[j]<ordenar[mini]){
                mini=j;
                sent=1;

            }
        }
        if (sent==1){
            printf("T %d %d \n",i,mini);
            trocar(&ordenar[i],&ordenar[mini]);
        }
    }


    for(int i=0;i<n;i++){
            printf("%d ",ordenar[i]);
        }

}

int main()
{
    int n;
    char modo[100];
    scanf("%s",&modo);
    scanf("%d",&n);
    int v[n];
    for (int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    if (strcmp(modo, "bolha") == 0) {
            bolha(v,n);
        }


    if (strcmp(modo, "selecao") == 0) {
                selecao(v,n);
            }

    else {
        return 1;
    }
    return 0;
}

