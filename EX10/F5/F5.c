#include <stdio.h>


int main(){
    int letter_u[26] = {0}, letter_l[26] = {0};
    FILE *fp;
    if((fp = fopen("/home/dwuggh/code/homework/EX10/F5/a.txt","r")) == 0){
        printf("error: cannot open file\n");
    }
    char c = fgetc(fp);
    while(c != EOF){
        if(c >= 65 && c <= 90) letter_u[c-65]++;
        if(c >= 97 && c <= 122) letter_l[c-97]++;
        c = fgetc(fp);
    }
    int i;
    for(i = 0; i < 26; i++){
        printf("%c: %d\t%c: %d\n", 65 + i, letter_u[i], 97 + i, letter_l[i]);
    }
    fclose(fp);
    return 0;
}