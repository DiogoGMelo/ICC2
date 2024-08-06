#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Diogo Gianezi de Melo - 12563522
// Raphael Monteiro Consoni Bonaccorsi - 12563366
// Matheus Rodrigues dos Santos - 11212866

int overlap(char *r1, char *r2);
void combineReads(char *r1, char *r2, int overlap, char *readNew);
void removeMaxReads(char **reads, int m1, int m2, char *readNew, int N);

int overlap(char *r1, char *r2) {
    int a,b;
    int overlap = 0;
    a = strlen(r1);
    b = strlen(r2);


    if(r1[a - 1] == r2[0] && b == 1) {
        overlap = 1;
        return overlap;
    }

    if (strstr(r1, r2) != NULL) {
        overlap = b;
        return overlap;
    }

    if (r1[a - 1] == r2[0] && r1[a - 2] != r2[1]) {
        overlap = 1;
        return overlap;
    }
    
    int j = 0;
    for (int i = 0; i < a && j < b; i++) {
        if (r1[i] == r2[j]) {
            overlap++;
            j++;
        }
        else {
            i = i - overlap;
            overlap = 0;
            j = 0;
        }
    }
    return overlap;
}

void combineReads(char *r1, char *r2, int overlap, char *readNew) {
    if (overlap == 0) {
        strcpy(readNew,r1);
        strcat(readNew,r2);
    } 
    else if (overlap == strlen(r2)) {
        strcpy(readNew, r1);
    }
    else {
        strcpy(readNew,r1);
        for (int i = overlap; i < strlen(r2); i++) {
            int t = strlen(readNew);
            readNew[t] = r2[i];
            readNew[t + 1] = '\0';
        }
    }
}
void removeMaxReads(char **reads, int m1, int m2, char *readNew, int N) {

        for (int i = m1; i < N - 1; i++) {
            strcpy(reads[i], reads[i + 1]); 
        }
        int k;

        if (m1 < m2)
            k = 1;      
        else 
            k = 0;

        for (int i = m2 - k; i < N - 2; i++) { 
            strcpy(reads[i], reads[i + 1]);
        }

        for (int i = N - 2; i >= 1; i--) {
            strcpy(reads[i], reads[i - 1]);
        }
        strcpy(reads[0], readNew); 
}


int main() {

    char **reads;
    char *readNew;
    int N;
    int m1,m2,overlapmax = -1;
    int overlapcalc;

    readNew = (char *)malloc(200 * sizeof(char ));
    scanf("%d", &N);
    reads = (char **)malloc(N * sizeof(char *)); 
    for(int i = 0; i < N; i++) {

        reads[i] = malloc(200 * sizeof(char)); 
        scanf("%s", reads[i]);
    }
    while (N >= 2) {
         for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i != j) {

                    overlapcalc = overlap(reads[i], reads[j]);
                    if (overlapcalc > overlapmax) {
                        overlapmax = overlapcalc;
                        m1 = i;
                        m2 = j;
                    }
                }
            }
        }

    combineReads(reads[m1],reads[m2],overlapmax,readNew);
    if (N > 2) {
        removeMaxReads(reads,m1,m2,readNew,N);
    }
    N--;
    overlapmax = -1;
    }
    printf("%s", readNew); 
    for (int i = 0; i < N; i++) {
        free(reads[i]);
    }
    free(reads);
    return 0;
}
    
