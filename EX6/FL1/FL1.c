#include <stdio.h>

int main(){
    int fun1(int x[], char y[]);
    static int a[6] = {10,20,30,40,50}, i;
    static char b[6] = "USTC";
    fun1(a, b);
    printf("\na: ");
    for(i = 0; i < 6; i++){
        printf("(%x)%-4d", &a[i],a[i]);
    }
    printf("\nb: ");
    for(i = 0; i < 6; i++){
        printf("(%x)%-4c", &b[i],b[i]);
    }
    printf("\na: ");
    for(i = 0; i < 6; i++){
        printf("(%x)%-4d", &b[i],b[i]);
    }
    printf("\nstring: %s\n", b);
    return 0;
}

int fun1(int x[], char y[]){
    int i;
    printf("\nx: ");
    for(i = 0; i < 6; i++){
        printf("(%x)%-4d", &x[i],x[i]);
    }
    printf("\ny: ");
    for(i = 0; i < 6; i++){
        printf("(%x)%-4c", &y[i],y[i]);
    }
    printf("\ny: ");
    for(i = 0; i < 6; i++){
        printf("(%x)%-4d", &y[i],y[i]);
    }
    printf("\nstring: %s\n",y);
    x[5] = x[0] + x[1] + x[2] + x[3] + x[4];
    return 0;
}