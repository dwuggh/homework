//似乎筛法算质数表更快，但直接硬上更直观，反正就500个数
#include <stdio.h>
#include <math.h>
//写bool还要单加一个库，太麻烦不用了（逃
int is_prime(int p){
    int re = 1;
    if(p ==2 ) return 1;
    for(int i = 2; i <= (int)sqrt(p); i++){
        if( p % i == 0 ) {
            re = 0;
            break;
        }
    }
    return re;
}



int main(){

    int a[10] = {0};
    int count = 0;
    int tenprime = 0;
    for(int i = 499; i > 0; i -= 2){
        if(is_prime(i)){
            a[count] = i;
            count ++;
            if(count == 9) {
                tenprime = 1;
                break;
            }
        }
    }
    if(tenprime){
        int sum = a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7] + a[8] + a[9];
        printf("the ten top primes are:\n");
        printf("%d+%d+%d+%d+%d+%d+%d+%d+%d+%d = %d\n",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9],sum);
    }
    else{
        printf("there is no ten primes under 500\n");
    }

    return 0;
}