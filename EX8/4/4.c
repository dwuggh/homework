/*              ?????????
             ???          ?? 
          ???               ??
        ??                    ??
      ??                      ??
                               ??
                               ??
                              ??
                            ??
                          ??
                        ??
                      ??
                    ??
                   ??
                   ??
                   ??

                   
                   ??
                   ??
*/

//I have no idea what I should do...
#include <stdio.h>
#include <stdlib.h>
//#define MAXN 1000
int main(){
    int n;
    scanf("%d", &n);
    int i;
    int *a = malloc(sizeof(int[n]));
    for(i = 0; i < n; i++){
        scanf("%d", a+i);
    }
    for(i = 0; i < n; i++){
        printf("%d ", *(a + n -i - 1));
    }
    return 0;
}

