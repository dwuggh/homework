#include <stdio.h>

int main(){

    int n = 9;
    for(int i = 1; i <= 9; i++){
        printf("%d  ",i);
        for (int j = 1; j <= i; j++)
        {
            printf("%d  ",i*j);
            
        }
        putchar('\n');
    }

    return 0;
}