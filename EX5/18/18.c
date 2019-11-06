#include <stdio.h>
#define MAXN 10000
void print(int *a, int size){
    int i;
    for(i = 0; i < size; i++){
        printf("%d ",*(a+i));
    }
    putchar('\n');
    return ;
}
int main(){
    int i, j, max;
    max = 10;
    int fib[MAXN] = {1};
    for(i = 0; i < max; i++){
        
        for(j = i; j > 0; j--){
            fib[j] = fib[j-1]+fib[j];
        }
        print(fib, i+1);
    }
    return 0;
}