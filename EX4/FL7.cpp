#include <stdio.h>
#define M 10
#define N 10

void saddle_point(int a[], int m, int n){
    int k = 0, kk, d, p, t;
    for(int i = 0; i < m; i++){
        d = a[i*N];
        for(int j = 0; j < n; j++){
            t = i*N + j;
            if(a[t] < d){
                d = a[t]; k = j;
            }
        }
        for(int j = k; j < n; j++){
            t = i*N + j;
            if(a[t] == d){
                p = a[t];
                for(kk = 0; kk < m; kk++){
                    t = kk*N + j;
                    if(a[t] > p) p = a[t];
                }
                if(d == p) printf("saddle point:%5d%5d\n",i,j);
            }
        }
    }

}


int main(){
    int i, j, k, m, n, a[M][N];
    printf("enter m,n:");
    scanf("%d%d",&m, &n);
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            scanf("%d",&a[i][j]);
        }
    }
    saddle_point(*a, m, n);
    return 0;
}