#include <stdio.h>
#include <stdlib.h>
#define NEW(PP) (PP=(PITEM)malloc(sizeof(ITEM)))
#define TEST(PP) if(NEW(PP) == NULL) { printf("memory error\n"); return; }

typedef struct item {
    int val;
    struct item *next;
}ITEM, *PITEM;

PITEM create(int n){
    int i;
    PITEM current, first;
    TEST(first);
    current = first;
    first->val = 1;
    for(i = 2; i<= n; i++){
        TEST(current->next);
        current = current -> next;
        current->val = i;
    }
    current -> next = NULL;
    return first;
}

void del(int m, PITEM first){
    PITEM prev, current;
    prev = first;
    current = first;
    for(;current != NULL; prev = current, current = current->next){
        if(current -> val % m == 0){
            prev -> next = current ->next;
            free(current);
            current = prev;
        }
    }
}

void print(PITEM first){
    PITEM current;
    for(current = first; current != NULL; current = current -> next){
        printf("%4d", current -> val);
    }
    putchar('\n');
}

int main(){
    int i, n;
    PITEM current, first, prev;
    printf("enter n: ");
    scanf("%d", &n);
    printf("\n");
    if(n < 0){
        printf("\nenter error!\n");
        return 0;
    }
    /*
    TEST(first);
    current = first;
    first->val = 1;
    for(i = 2; i<= n; i++){
        TEST(current->next);
        current = current -> next;
        current->val = i;
    }
    current -> next = NULL;
    prev = first;
    current = first;
*/

    first = create(n);
    print(first);
    del(3, first);
    print(first);
    del(5, first);
    print(first);
    del(7, first);
    print(first);
    del(11, first);
    print(first);
    return 0;
}