#include <stdio.h>

#define MAXN 1000

int primes[1000] = {0};

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

int reverse(int num){
    int a, b, i;
    int digital[100];
    for(i = 0; num > 0; i++){
        a = num % 10;
        num = num/10;
        digital[i] = a;
    }
    int re = 0;
    int j;
    for(j = 0; j < i; j++){
        re *= 10;
        re = re + digital[j];
        
    }
    return re;
}


void reverse_prime(){
    int i;
    for(i = 100; i < 1000; i++){
        if( is_prime(i) & is_prime(reverse(i)) ){
            printf("%d\n", i);
        }
    }
}

int main(){
    int n = 0;
    Gen_Primes();
    reverse_prime();
    return 0;
}