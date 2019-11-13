#include <stdio.h>

unsigned long long factorial(int n){
    if(n < 0) return 0;
    else if(n == 0) return 1;
    else{
        int i;
        unsigned long long re = 1;
        for(i = 2; i <= n; i++){
            re = re*i;
        }
        return re;
    }
} 
unsigned long long c_p_mn(int m, int n, int flag_c, int flag_p){
    if(m < 0 || n < 0) return 0;
    else if(m < n) return 0;
    else{
        unsigned long long p = factorial(m)/factorial(m - n);
        if(flag_c == 1){
            return p/factorial(n);
        }
        else if(flag_p == 1){
            return p;
        }
    }
}



int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    unsigned long long c = c_p_mn(m, n, 1, 0);
    unsigned long long p = c_p_mn(m, n, 0, 1);
    if(c == 0 || p == 0){
        printf("invalid input\n");
        return 0;
    }
    else printf("c: %llu\tp: %llu", c, p);
    return 0;
}