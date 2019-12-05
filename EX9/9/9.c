#include <stdio.h>
#include <stdlib.h>

typedef struct stu{
    int num;
    char name[16];
    char sex;
    int age;
    double grade;
    struct stu* next;
}Stu, *PStu;

#define NEW(PP) (PP=(PStu)malloc(sizeof(Stu)))
#define TEST(PP) if(NEW(PP) == NULL) { printf("memory error\n"); return; }

int pesudo_random(int i){
    i = i + 12323;
    i = i * 43534;
    i = i ^ 21331;
    return i%100;
}
PStu create(int n){
    int i;
    PStu current, first;
    TEST(first);
    current = first;
    first -> grade = pesudo_random(1);
    first -> num = 1;
    for(i = 2; i <= n; i++){
        TEST(current -> next);
        current = current -> next;
        current -> grade = pesudo_random(i);
        current -> num = i;
        //don't care about the rest
    }
    current -> next = NULL;
    return first;
}

void switch_node(PStu front, PStu back, PStu first){
    PStu p = back -> next;
    PStu front_prev, back_prev;
    for(front_prev = first; front_prev -> next != front; front_prev = front_prev -> next);
    for(back_prev = first; back_prev -> next != back; back_prev = back_prev -> next);
    if(front -> next == back){
        front_prev -> next = back;
        front -> next = back -> next;
        back -> next = front;
        
    }
    else{
        front_prev -> next = back_prev -> next;
        back -> next = front -> next;
        back_prev -> next = front;
        front ->next = p;
        
    }
    p = front;
    front = back;
    back = p;
}

int main(){
    int i, n;
    //scanf("%d", &n);
    n = 7;
    for(i = 1; i <= n; i++){
        printf("%3d",pesudo_random(i));
    }
    putchar('\n');
    PStu pesudo_first, first, p1;
    first = create(n);
    TEST(pesudo_first);
    pesudo_first -> grade = 200;
    pesudo_first -> num = 0;
    pesudo_first -> next = first;
    
    i = 0;
    for(p1 = first; p1 -> next != NULL; p1 = p1 -> next){
        PStu p2;
        PStu max = p1, q = p1;
        i++;
        for(p2 = p1 -> next; p2 != NULL; p2 = p2 -> next){
            if(max -> grade < p2 -> grade){
                max = p2;
            }
        }
        if(max != p1){
            switch_node(p1, max, pesudo_first);
        }
        int j = 0;
        p1 = pesudo_first;
        for(j = 0; j < i; j++) p1 = p1 -> next;
        for(q = pesudo_first -> next; q != NULL; q = q -> next){
            //printf("%3.0lf", q -> grade);
        }
    }
    
    
    
   //switch_node(first, first -> next -> next -> next, pesudo_first);
    for(p1 = pesudo_first -> next; p1 != NULL; p1 = p1 -> next){
        printf("%3lf\n", p1 -> grade);
    }

    return 0;
}