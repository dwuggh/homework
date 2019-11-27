#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000

//no need of this function
void transpose(int *a, int n){
    int i, j;
    int *temp = malloc(sizeof(int[n][n]));
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            *(temp + j*4 + i) = *(a + i*4 + j);
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            *(a + i*4 + j) = *(temp + i*4 + j);
        }
    }
}

void print(int* a, int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d  ", *(a + j*4 +i));
        }
        putchar('\n');
    }
}

int main(){
    int n;
    n = 4;
    //imitate a 2-D array
    int *a = malloc(sizeof(int[n][n]));
    //printf("%d", sizeof(int[n][n]));
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", a + i*4 + j);
        }
    }
    //transpose(a, n);
    print(a, n);
    return 0;
}