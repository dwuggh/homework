#include <stdio.h>

int f(int N);
int main(){
    int N = 0;
    scanf("%d", &N);
    int re = f(N);
    if(re == -1) printf("INVALID INPUT\n");
    else if (re >= 0)
    {
        /* code */
        printf("digital 1: %d\n", re);
    }
    return 0;
}
int f(int N){
    int a = N, b = 0;
    int re = 0;
    if(N < 0) return -1;
    while (a > 0)
    {
        b = a%10;
        a = a/10;
        if(b > 0) re ++;
        if(a%10==1) re = re + b;
        re =re + a;
    }
    return re;
    
}