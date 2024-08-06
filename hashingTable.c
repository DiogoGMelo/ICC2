/* 
Raphael Monteiro Consoni Bonaccorsi  nUSP:12563366 
Diogo Gianezi de Melo                nUSP:12563522
Matheus Rodrigues dos Santos         nUSP: 11212866
*/

#include <stdlib.h>
#include <stdio.h>

int insert(int *V, int M, int e); // insert(*V vetor a se inserir, M tamanho do vetor, e valor a se inserir)
int removeElement(int *V, int M, int e);
int search(int *V, int M, int e);

int main() {
    int M, N, D, B; // M = capacidade da tabela, N = número de inserções, D = número de remoções, B = número de buscas
    scanf("%d", &M);
    int *V;
    V = malloc(M * sizeof(int)); // Aloca espaço para o vetor


    for (int i = 0; i < M; i++) { // Seta todos os valores do vetor como -1
        V[i] = -1;
    }

    scanf("%d", &N);
    for (int i = 0; i < N; i++) { // Lê os valores e insere na tabela
        int e;
        scanf("%d", &e);
        insert(V, M, e);
    }

    scanf("%d", &D);
    for (int i = 0; i < D; i++) { // Lê os valores e remove
        int e;
        scanf("%d", &e);
        removeElement(V, M, e);
    }

    scanf("%d", &B);
    for (int i = 0; i < B; i++) { // Lê e pesquisa os valores
        int e;
        scanf("%d", &e);
        printf("%d ", search(V, M, e));
    }

    return 0;
}

int insert(int *V, int M, int e) { // Inserção com estratégia linear de sondagem, hasheando pelo módulo da capacidade
    int aux = search(V, M, e);
    if (aux != -1) { // Checa se o valor já esta no array
        return -1;
    }

    int mod = e % M;
    for (int i = mod; i < M; i++) {
        if (V[i] == -1) {
            V[i] = e;
            return 0;
        }
        if (i == M - 1 && mod != 0) { // Caso chegue no final do array, tente a primeira posição
            i = -1;
        }
        if (i == mod - 1) { // Caso de uma volta completa no array e não ache espaço, retorne erro (prevenir loop)
            return -1;
        }
    }
    return -1;
}

int removeElement(int *V, int M, int e) {
    int id = search(V, M, e);
    if (id == -1) {
        return 0;
    }
    V[id] = -1;
    return 0;
}

int search(int *V, int M, int e) { // Retorna -1 se não encontrar ou o índice caso encontre
    int mod = e % M;
    for (int i = mod; i < M; i++) {
        if (V[i] == e) {
            return i;
        }
        if (i == M - 1 && mod != 0) { // Caso chegue no final do array, tente a primeira posição
            i = -1;
        }
        if (i == mod - 1) { // Caso de uma volta completa no array e não ache espaço, retorne erro (prevenir loop)
            return -1;
        }
    }
    return -1;
}
