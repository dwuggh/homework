#include <stdio.h>
#define A(x) x*x


int main(){
    int a = 0;
    while(a<6)
    printf("%d\t%d\n",a,A(a++));
    return 0;
}