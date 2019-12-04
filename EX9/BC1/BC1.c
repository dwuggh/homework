#include <stdlib.h>
#include <stdio.h>
#define NEW(PP) (PP=(Poly)malloc(sizeof(Pol)))
#define TEST(PP) if(NEW(PP) == NULL) { printf("memory error\n"); return; }
typedef struct Polygon{
    float x;
    float y;
    struct Polygon* next;
}Pol, *Poly;

Poly create(int n){
    int i;
    Poly current, first;
    TEST(first);
    current = first;
    scanf("%f%f", &first -> x, &first -> y);
    
    for(i = 2; i<= n; i++){
        TEST(current->next);
        current = current -> next;
        scanf("%f%f", &current -> x, &current -> y);
    }
    current -> next = NULL;
    return first;
}

float count_s(Poly p1, Poly p2, Poly p3){
    float x1 = p2 -> x - p1 -> x;
    float y1 = p2 -> y - p1 -> y;
    float x2 = p3 -> x - p1 -> x;
    float y2 = p3 -> y - p1 -> y;
    float re = (x1*y2 - x2*y1)/2;
    return re > 0 ? re : -re;
}
int main(){
    int n;
    scanf("%d", &n);
    if(n < 0){
        printf("invalid n\n");
        return 0;
    }
    Poly first, p1, p2;
    float s = 0;
    first = create(n);
    p1 = first ->next;
    p2 = p1 -> next;
    for(; p1 -> next != NULL; p1 = p2, p2 = p2 -> next){
        s += count_s(first, p1, p2);
    }
    printf("S=%f\n",s);
    return 0;
}