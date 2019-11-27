#include <stdio.h>
typedef struct
{
    int count_cap_letters;
    int count_low_letters;
    int count_numbers;
    int count_spaces;
    int count_others;
}Count;
Count result;

void stats(int c){
    
    int i;
    
    if(c >= 65 && c <= 90) result.count_cap_letters ++;
    else if(c >= 97 && c <= 122) result.count_low_letters ++;
    else if(c >= 48 && c <= 57) result.count_numbers ++;
    else if(c == 32) result.count_spaces ++;
    else result.count_others ++;
}
void print_stats(Count result){
    printf("cap: %d\n", result.count_cap_letters);
    printf("low: %d\n", result.count_low_letters);
    printf("num: %d\n", result.count_numbers);
    printf("space: %d\nothers: %d", result.count_spaces, result.count_others);
    putchar('\n');
}
int main(){
    char c[1000];
    int i = 0;
    //强行用指针
    do{
        *(c+i) = getchar();
        stats(*(c+i));
        i++;
    }
    while (*(c+i-1) != '\n');
    print_stats(result);
    return 0;
    
}