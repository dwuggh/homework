#include <stdio.h>
#include <stdlib.h>

typedef struct stu{
    //int num;
    //char name[16];
    //char sex;
    //int age;
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
    first->grade = pesudo_random(1);
    for(i = 2; i<= n; i++){
        TEST(current -> next);
        current = current -> next;
        current->grade = pesudo_random(i);
        //don't care about the rest
    }
    current -> next = NULL;
    return first;
}

void switch_node(PStu front, PStu back, PStu back_prev){
    PStu p1 = front -> next;
    front -> next = back;
    PStu p2 = back -> next;
    //PStu p2 = back_prev;
    
    back -> next = p1;
    back_prev -> next = p2;
    //p1 -> next = p2;
}

int main(){
    int i, n;
    //scanf("%d", &n);
    n = 5;
    for(i = 1; i <= n; i++){
        printf("%3d",pesudo_random(i));
    }
    putchar('\n');
    PStu pesudo_first, first, current, s, q, prev;
    first = create(n);
    TEST(pesudo_first);
    pesudo_first -> grade = 200;
    pesudo_first -> next = first;
    current = first;
    prev = pesudo_first;
    /*
    for(;current -> next != NULL; prev = current, current = current -> next){
        PStu current2, prev2 = current;
        for(current2 = current -> next; current2 -> next != NULL; prev2 = current2, current2 = current2 -> next){
            if(current -> grade < current2 -> grade){
                switch_node(prev, current2, prev2);
            }
        }
    }
    */
    for(current = first->next; current->next!=NULL; current = current->next){
        s = current;
        for(q = current->next;q!=NULL;q = q->next){
            if(q->grade < s->grade){
                s = q;
            }
        }
        if(s != current){
            int temp;
            temp = s->grade;
            s->grade = current->grade;
            current->grade = s->grade;
            //其他元素也可类似交换
        }
    }
    
   //switch_node(first, first ->next->next, first->next);
    for(current = first, prev = pesudo_first; current != NULL; prev = current, current = current -> next){
        printf("%3lf\n", current -> grade);
    }
    return 0;
}