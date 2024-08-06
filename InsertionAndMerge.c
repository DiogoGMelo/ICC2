#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 1
#define NAO_EXISTE -1
#define JA_EXISTE -2
#define INVALIDO -3
#define CHEIA -4
#define VAZIA -5

void insertion(int v[], int n, int *comparacoes, int *trocas) {
    int c = 0;
    int t = 0;
    for (int i = 1; i < n; i++) {
        int p = v[i];
        int j = i - 1;
        t++;
        while (j >= 0) {
            c++;
            if (v[j] > p) {
                v[j + 1] = v[j];
                j--;
                t++;
            } else {
                break;
            }
        }

        v[j + 1] = p;
        t++;
    }
    *comparacoes = c;
    *trocas = t;
    printf("I %d %d %d",n,t,c);
}

void mergesort(int a[], int c, int f, int *p, int *co, int *t) {
    int trocas = 0;
    int compa = 0;

    if (c >= f) {
        return;
    }

    int meio;
    meio = (c + f) / 2;
    mergesort(a, c, meio, p, co, t);
    mergesort(a, meio + 1, f, p, co, t);

    int j = 0;
    int I1 = c;
    int I2 = meio + 1;

    while (I1 <= meio && I2 <= f) {
        if (a[I1] <= a[I2]) {
            p[j] = a[I1];
            I1++;
        } else {
            p[j] = a[I2];
            I2++;
        }
        j++;
        trocas++;
        compa++;
    }

    while (I1 <= meio) {
        p[j] = a[I1];
        I1++;
        j++;
        trocas++;
    }

    while (I2 <= f) {
        p[j] = a[I2];
        I2++;
        j++;
        trocas++;
    }

    j = 0;
    for (int i = c; i <= f; i++) {
        a[i] = p[j];
        j++;
        trocas++;
    }

    *co += compa;
    *t += trocas;
}

int main() {
    int Q, j, i;
    scanf("%d", &Q);
    if (Q <= 0) {
        return 1;
    }

    int **v = malloc(Q * sizeof(int *));
    int *N = malloc(Q * sizeof(int));
    for (i = 0; i < Q; i++) {
        scanf("%d", &N[i]);
        if (N[i] <= 0) {
            return INVALIDO;
        }
        v[i] = malloc(N[i] * sizeof(int));
    }

    for (i = 0; i < Q; i++) {
        for (int j = 0; j < N[i]; j++) {
            scanf("%d", &v[i][j]);
        }
    }

    int total_compa = 0;
    int total_trocas = 0;

    for (i = 0; i < Q; i++) {

        int *temp = malloc(N[i] * sizeof(int));
        for (int j = 0; j < N[i]; j++) {
            temp[j] = v[i][j];
        }

        insertion(temp, N[i], &total_compa, &total_trocas);
        printf("\n");

        free(temp);


        int compa = 0;
        int trocas = 0;
        int *p = malloc(N[i] * sizeof(int));

        mergesort(v[i], 0, N[i] - 1, p, &compa, &trocas);

        total_compa += compa;
        total_trocas += trocas;

        printf("M %d %d %d\n", N[i], trocas, compa);

        free(p);
    }

    for (i = 0; i < Q; i++) {
        free(v[i]);
    }
    free(v);
    free(N);

    return 0;
}
