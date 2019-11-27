#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000
char* udf_strcpy(char* str, int m){
    static char re[1000];
    int i;
    for(i = 0;*(str + i) != '\0'; i++);
    if(i < m) {
        re[0] = '\0';
        return re;
    }
    else
    {
        for(i = m-1; *(str + i) != '\0'; i++)
            *(re+i-m+1) = *(str + i);
    }
    return re;
    
}

int main(){
    char str[MAXN];
    int m = 0;
    scanf("%s", str);
    scanf("%d", &m);
    //printf("%c%c", str[0], str[1]);
    printf("%s\n", udf_strcpy(str, m));
    return 0;

}