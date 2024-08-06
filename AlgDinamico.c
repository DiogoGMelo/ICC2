#include <stdio.h>
#include <stdlib.h>
// Diogo Gianezi de Melo - 12563522
// Matheus Rodrigues dos Santos - 11212866

typedef struct {
    int rows;
    int cols;
    int **friendship;
} CityMap;

int maxFriendsHelper(int *memo, CityMap city, int block) {
    if (memo[block] != -1) {
        return memo[block];
    }

    if (block == (city.rows * city.cols - 1)) {
        return 0; // último nó não tem amigos adicionais
    }

    int maxRight = 0;
    int maxDown = 0;

    if ((block % city.cols) != (city.cols - 1)) {
        maxRight = city.friendship[block][block + 1] + maxFriendsHelper(memo, city, block + 1);
    }

    if (block < (city.rows * city.cols - city.cols)) {
        maxDown = city.friendship[block][block + city.cols] + maxFriendsHelper(memo, city, block + city.cols);
    }

    int result = (maxDown > maxRight) ? maxDown : maxRight;
    memo[block] = result;
    
    return result;
}

int maxFriends(CityMap city) {
    int *memo = (int *)malloc(sizeof(int) * (city.rows * city.cols + 1));

    for (int i = 0; i <= city.rows * city.cols; i++) {
        memo[i] = -1;
    }

    int result = maxFriendsHelper(memo, city, 0);
    free(memo);

    return result;
}

void freeCityMap(CityMap city) {
    for (int i = 0; i < city.rows; i++) {
        free(city.friendship[i]);
    }
    free(city.friendship);
}

int main() {
    CityMap city;
    
    scanf("%d", &city.rows);
    scanf("%d", &city.cols);

    city.friendship = (int **)malloc(sizeof(int *) * city.rows * city.cols);
    
    for (int i = 0; i < city.rows * city.cols; i++) {
        city.friendship[i] = (int *)malloc(sizeof(int) * city.rows * city.cols);
    }

    

    for (int i = 0; i < (city.rows - 1) * city.cols + (city.cols - 1) * city.rows; i++) {
        int from, to, friends;
        scanf("%d %d %d", &from, &to, &friends);
        city.friendship[from][to] = friends;
    }

    int result = maxFriends(city);
    printf("%d", result);

    freeCityMap(city);

    return 0;
}
