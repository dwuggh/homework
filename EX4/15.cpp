#include <stdio.h>

#define MAXN 1E6

int primes[100000] = {0};

void Gen_Primes(){
    primes[0] = 2;
    int count = 1;
    int i;
    for(i = 3; i < MAXN; i = i+2){
        int flag = 0;
        for(int j = 0; primes[j] != 0 && primes[j] < i; j++){
            if(i%primes[j] == 0){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            primes[count] = i;
            //printf("%d\t",i);
            count++;
        }
    }
}

int is_prime(int a){
    int flag = 0;
    int i;
    for(i = 0; primes[i] != 0 && primes[i] <= a; i++){
        if(primes[i] == a){
            flag = 1;
            break;
        }
    }
    return flag;
}

void Goldbach(int n){
    int i;
    for(i = 6; i <= n; i = i + 2){
        for(int j = 0; primes[j] != 0 && primes[j] < i; j++){
            if( is_prime(i-primes[j]) ){
                printf("%d=%d+%d\n",i,primes[j],i-primes[j]);
                break;
            }
        }
    }
}

int main(){
    int n = 0;
    scanf("%d",&n);
    Gen_Primes();
    Goldbach(n);
    return 0;
}