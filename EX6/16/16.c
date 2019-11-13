#include <stdio.h>
#define MAXN 100
void transfer_scale(int n, int num){
    int a;
    int i = 0;
    int digital[MAXN] = {0};
    while(num > 0){
        a = num%n;
        num = num/n;
        digital[i] = a;
        i++;
    }
    printf("%d-decimal:\t",n);
    while(i > 0){
        i--;
        if(digital[i] >= 10){
            int ascii = digital[i] + 97 -10;
            printf("%c", ascii);
        }
        else{
            printf("%d", digital[i]);
        }
    }
        
    
}


int main(){

    int n, num;
    printf("input n&num:");
    scanf("%d%d", &n, &num);
    if(n < 0 || num < 0){
        printf("invalid input.\n");
        return 0;
    }
    transfer_scale(n, num);
    return 0;
}