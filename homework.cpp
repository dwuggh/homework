#include <stdio.h>
#include <string.h>
#include <math.h>


int main(){
    int a[11] = {0,1,0,0,0,0,0,0,0,0,0};
    int i,j;
    for(i = 1; i < 11; i++ ){
        for(j = 1; j <= i; j++) printf("%d ", a[j]);
        printf("\n");
        for(j = i+1; j > 0; j--){
            a[j] = a[j-1] + a[j];
        }

    }
    return 0;
}