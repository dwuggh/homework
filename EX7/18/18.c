#include <stdio.h>
#include <string.h>
#define MAXN 2048
//#define func1

#ifdef func1
void print(char s[], int len){
    printf("%s\n", s);
}

#endif

#ifndef func1
void print(char s[], int len){
    int i = 0;
    for(i = 0; i < len; i++){
        if((s[i] >= 65 && s[i] < 90)||(s[i] >= 97 && s[i] < 122)) putchar(s[i] + 1);
        else if(s[i] == 90) putchar(65);
        else if(s[i] == 122) putchar(97);
        else putchar(s[i]);
    }
}

#endif

int main(){
    char s[MAXN] = {0};
    scanf("%s", s);
    //s = "asfddsafzAZ";
    print(s, strlen(s));
    return 0;
}