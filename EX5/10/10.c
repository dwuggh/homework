#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define print(a) my_print(a, 200)
void my_print(int *a, int size){
    int i;
    for(i = 0; i < size/sizeof(int); i++){
        printf("%d ",*(a+i));
    }
    putchar('\n');
    return ;
}
void swap(int *a, int *b){
    *a = (*a)^(*b);
    *b = (*a)^(*b);
    *a = (*a)^(*b);
    return ;
}
void bubble_sort(int *a, int size){
    int i, j;
    int max = size/sizeof(int);
    for(i = max-1; i >= 0; i--){
        for(j = i; j < max-1; j++){
            if(a[j] > a[j+1]) swap(a+j, a+j+1);
        }
    }
    return ;
}
void insert_sort(int *a, int size){
    int max = size/sizeof(int);
    int i, j, temp;
    for(i = 1; i < max; i++){
        temp = a[i];
        for(j = i-1; j >= 0 && temp < a[j]; j--){
            a[j+1] = a[j];
        }
        a[j+1] = temp;
    }
}
void select_sort(int *a, int size){
    int i, j, temp;
    int max = size/sizeof(int);
    for(i = 0; i < max; i++){
        int min = i;
        for(j = i+1; j < max; j++){
            if(a[j] < a[min]) swap(a+j, a+min);
        }
    }
}
int main(){

    int i=0;
    srand((unsigned int)time(NULL));
    int a[50];
    for(i = 0; i < 50; i++) a[i] = rand();
    int bubble[50], insert[50], select[50];
    memcpy(bubble, a, sizeof(a));
    memcpy(insert, a, sizeof(a));
    memcpy(select, a, sizeof(a));
    bubble_sort(bubble, sizeof(bubble));
    insert_sort(insert, sizeof(insert));
    select_sort(select, sizeof(select));
    print(a);
    printf("bubble:\n");
    print(bubble);
    printf("insert:\n");
    print(insert);
    printf("select:\n");
    print(select);
    return 0;
}