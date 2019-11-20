#include <stdio.h>
#include <string.h>
typedef struct
{
    int count_cap_letters[26];
    int count_low_letters[26];
    int count_numbers[10];
    int count_spaces;
    int count_others;
}Count;
Count result;

void stats(int c){
    
    int i;
    
    if(c >= 65 && c <= 90) result.count_cap_letters[c - 65] ++;
    else if(c >= 97 && c <= 122) result.count_low_letters[c - 97] ++;
    else if(c >= 48 && c <= 57) result.count_numbers[c - 48] ++;
    else if(c == 32) result.count_spaces ++;
    else result.count_others ++;

}

void print_stats(Count result){
    int i;
    for(i = 0; i < 26; i++) printf("%c  ", i + 65);
    putchar('\n');
    for(i = 0; i < 26; i++) printf("%d  ", result.count_cap_letters[i]);
    putchar('\n');
    for(i = 0; i < 26; i++) printf("%c  ", i + 97);
    putchar('\n');
    for(i = 0; i < 26; i++) printf("%d  ", result.count_low_letters[i]);
    putchar('\n');
    for(i = 0; i < 10; i++) printf("%c  ", i + 48);
    printf("SP  others");
    putchar('\n');
    for(i = 0; i < 10; i++) printf("%d  ", result.count_numbers[i]);
    printf("%d    %d", result.count_spaces, result.count_others);
    putchar('\n');
}

int main(){
    memset(&result, 0, sizeof(Count));
    int c;
    while(c = getchar()){
        if(c == '\n') break;
        stats(c);
    }
    
    print_stats(result);
    //printf("%d",1);
    return 0;
}