#include <stdio.h>
#define MAXN 1000
int udf_strlen(char* str){
    int i;
    
    for(i = 0; *(str + i) != '\0'; i++);
    return i;
}

int main(){
    char str[MAXN];
    scanf("%s", str);
    //str = "sdfsdfdsfasdfsd2342343tref*&^";
    printf("%d\n", udf_strlen(str));

    return 0;
}