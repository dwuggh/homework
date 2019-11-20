#include <stdio.h>

void num2str(int n){
    if(n >= 10) {
        num2str(n/10);
        putchar(n%10 + 48);
    }
    else putchar(n +48);
}

int main(){
    //int n = 1062323432;
    int n;
    scanf("%d", &n);
    num2str(n);
    return 0;
}