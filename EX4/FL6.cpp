#include <stdio.h>
#include <math.h>
int main(){
    int i, iy1, iy2;
    char a[80], b[80];
    double x, y1, y2;
    for(i = 0; i < 80; i++){
        a[i] = ' ';b[i] = '*';
    }
    a[79] = '\0';b[79] = '\0';
    printf("%s\n",b);
    x = -3.1415926;
    while(x < 3.1415926){
        y1 = sin(x);
        y2 = x/3.0;
        iy1 = 40 + 38*y1;
        iy2 = 40 + 38*y2;
        a[iy1] = '*';
        a[iy2] = '$';
        a[40] = '.';
        printf("%s\n",a);
        a[iy1] = ' ';
        a[iy2] = ' ';
        x = x + 3.1415926/18;
    }
    printf("%s\n",b);
    return 0;
}