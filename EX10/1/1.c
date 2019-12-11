
#include <stdio.h>

int getbits(int value, int n1, int n2){
    int c1 = 1, c2 = 1;
    c1 = (c1 << (16 - n1 + 1)) - 1;
    c2 = (c2 << (16 - n2)) - 1;
    int c = c1 - c2;
    return (value & c) >> (16 - n2);
}

int main(){
    int a = 0101675;
    printf("%d\n", getbits(a, 5, 8));//should be 3
    return 0;
}