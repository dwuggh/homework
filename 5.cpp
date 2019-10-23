#include <stdio.h>
#include <math.h>
#define ERROR 1e-8

double f(double x){
    int re = 2*x*x*x-4*x*x+3*x-6;
    return re;
}

int main(){
    double a = -10;
    double b = 10;
    double c = 0;
    while ( abs(f(c)) > ERROR )
    {
        c = (a+b)/2;
        f(c) >= 0 ? b = c : a = c;
    }
    printf("%lf\n",c);
    return 0;
    

}