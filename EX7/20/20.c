//I've learned some electrodynamics, and I'm a bit frightened of this...
//obiously this formula of L_n(x) is wrong. 
#include <stdio.h>

double Lengendre(double x, int n){
    if(n == 0) return 1;
    else if(n == 1) return x;
    else if(n < 0) return -1;
    else return ((2*n - 1)*x - Lengendre(x, n - 1) - (n - 1) * Lengendre(x, n-2))/n; 
}

int main(){
    int n;
    double x;
    printf("input x&n: ");
    scanf("%lf%d", &x, &n);
    double re = Lengendre(x, n);
    if(re == -1) printf("invalid input\n");
    else printf("%lf", re);
    return 0;
}