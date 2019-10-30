#include <stdio.h>

int main(){

    int n = 0;
    //scanf("%d",&n);
    n = 4;
    int r = 2*n - 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= r; j++){
            if(j >= n-i+1 && j <= n+i-1) putchar('*');
            else putchar(' ');
        }
        putchar('\n');
    }
    for(int i = n-1; i >= 1; i--){
        for(int j = 1; j <= r; j++){
            if(j >= n-i+1 && j <= n+i-1) putchar('*');
            else putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}