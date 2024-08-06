#include <stdio.h>
#include <stdlib.h>
int trocar(int a,int b){
    int aux;
    aux=a;
    a=b;
    b=aux;
}
void heapify(int a[],int p,int u){
        int f=2+p+1;
        if(f<=u){
            if(f+1<=u){
                if(a[f+1]>a[f]){
                    f++;
                }
            }
        }
        if (a[f]>a[p]){
            trocar(&a[f],&a[f]);
            heapify(&a,&f,&u);
        }
    }
void heapsort(int a[],int n){
    for(int i = n-1;i>=0;i++){
        heapify(&a,&i,&n-1);
    }
    for(int j = n-1;j>=0;j--){
        trocar(&a[0],&a[j]);
        heapify(&a,0,&j-1);
    }
}
int main()
{

    int n;
    scanf("%d",&n);
    int v[n];
    for (int i = 0;i<n;i++){
        scanf("%d",&v[i]);
    }
    heapsort(&v[n],&n);
    for(int i = 0;i<n;i++){
        printf("%d ",v[i]);
    }


}

