#include <stdio.h>
#include <stdlib.h>
#define udf_strcpy(s, t) udf_strcpy_size(s, t, 256) 
char *udf_strcpy_size(char *s,const char *t, int size_s){
    int max = 0;
    int i;
    for(max = 0; t[max] != '\0'; max++);
    if(size_s < max) {
        printf("fatal error: out of range\n");
        exit(1);
    }
    char *s1 = s;
    for(i = 0; i< max; i++){
        *(s+i) = *(t+i);
    }
    
    return s1;
}

int main(){

    char s[] = "sdfsad";
    char t[] = "sdfdfsdfsdf";
    printf("%s\n",s);
    udf_strcpy(s,t);
    printf("%s",s);

    return 0;
}