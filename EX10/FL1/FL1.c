#include <stdio.h>
#define FIRSTPRIME 2
#define MAXIMUN 100

int thisbit(int n){
    int k, w;
    k = (n - FIRSTPRIME) % 16;
    w = 1;
    w = w << k;
    return w;
}

int main(){
    int i, leftin, range, rangemod16, factor, multiple, temp, k=1;
    unsigned sieve[MAXIMUN];
    printf("range=");
    scanf("%d", &range);
    leftin = range - FIRSTPRIME + 1;
    rangemod16 = leftin/16 + 1;
    for(i = 0; i < rangemod16; i++){
        sieve[i] = 0xffffffff;
    }
    factor = FIRSTPRIME - 1;
    do{
        factor ++;
        i = (factor - FIRSTPRIME)/16;
        if(sieve[i] & thisbit(factor)){
            printf("%5d%c", factor, (k++ % 10)?' ':'\n');
            multiple = 1;
            while(factor*multiple <= range){
                temp = factor*multiple;
                i = (temp - FIRSTPRIME)/16;
                if(sieve[i] & thisbit(temp)){
                    sieve[i] = sieve[i] ^ thisbit(temp);
                    leftin--;
                }
                multiple += 1;
            }
        }
    }while(leftin);
    return 0;
}