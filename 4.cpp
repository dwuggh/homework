#include <stdio.h>
#include <math.h>
#define ERROR 1e-8

double f(double x){
    int re = 2*x*x*x-4*x*x+3*x-6;
    return re;
}

double f_tan(double x){
    return 6*x*x-8*x+3;
}

int main(){
    double x = 1.5;
    
    while (abs(f(x)) > ERROR)
    {
        printf("%lf\n",f(x));
        x = x - f(x)/f_tan(x);
    }
    printf("%lf\n",x);

    return 0;
}