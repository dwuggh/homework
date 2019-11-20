#include <stdio.h>

#define Swap(x, y) \
    double t;\
    (t) = (x);\
    (x) = (y);\
    (y) = (t);

int main(){
    double x, y;
    scanf("%lf%lf", &x, &y);
    Swap(x, y);
    printf("%lf  %lf", x, y);
    return 0;
}