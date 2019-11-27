#include <stdio.h>
#include <math.h>
#define gap 0.00001

double Integrade(double func(double), double low, double up){
    double x = low, sum = 0;
    while (x <= up)
    {
        sum += func(x)*gap;
        x += gap;
    }
    return sum;
}

int main(){
    printf("sin: %lf\n", Integrade(sin, 0, 1));
    printf("cos: %lf\n", Integrade(cos, -1, 1));
    printf("e^x: %lf\n", Integrade(exp, 0, 2));
    return 0;
}