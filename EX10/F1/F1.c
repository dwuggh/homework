#include <stdio.h>
#include <stdlib.h>

typedef struct student{
    char name[100];
    char num[100];
    float score1;
    float score2;
    float score3;
    float avg;
    struct Student* next;
    int sorted;
}Stu;

Stu* create(){
    Stu *head;
    head = (Stu*)malloc(sizeof(Stu));
    scanf("%s%s%f%f%f", &head->name, &head->num, &head->score1, &head->score2, &head->score3);
    head->avg = (head->score1 + head->score2 + head->score3)/3;
    head -> next = NULL;
    head -> sorted = 0;
    return head;
}

Stu* insert(Stu *p, int n){
    Stu *t = p;
    Stu *buff;
    int i = 0;
    while(i < n && t != NULL){
        t = t -> next;
        i++;
    }
    if(t != NULL){
        buff = (Stu*)malloc(sizeof(Stu));
        scanf("%s%s%f%f%f", &buff->name, &buff->num, &buff->score1, &buff->score2, &buff->score3);
        buff->avg = (buff->score1 + buff->score2 + buff->score3)/3;
        buff -> next = t -> next;
        t -> next = buff;
        buff ->sorted = 0;
    }
    return buff;
}

Stu* append(Stu* end){
    Stu *t = end;
    Stu *buff;
    if(t != NULL){
        buff = (Stu*)malloc(sizeof(Stu));
        scanf("%s%s%f%f%f", &buff->name, &buff->num, &buff->score1, &buff->score2, &buff->score3);
        buff->avg = (buff->score1 + buff->score2 + buff->score3)/3;
        t -> next = buff;
        buff -> next = NULL;
        buff -> sorted = 0;
    }
    return buff;
}

int main(){
    FILE* fp;
    Stu* head, *node, *node2, *end;
    
    int n;
    scanf("%d", &n);
    if(n <= 0) ;
    else if(n == 1) head = create();
    else{
        head = create();
        end = head;
        int i;
        for(i = 1; i < n; i++){
            end = append(end);
        }
    }
    fp = fopen("/home/dwuggh/code/homework/EX10/F1/stud_dat", "a+");
    Stu* min  = head;
    for(node = head; node != NULL; node = node -> next){
        for(node2 = head; node2 != NULL; node2 = node2 -> next){
            if((node2->avg > min->avg)&&node2->sorted == 0) {min=node2;}
        }
        min ->sorted = 1;
        for(min=head; min != NULL; min = min -> next){
            if(min->sorted == 0) break;
        }
        if(min==NULL) break;
        fprintf(fp, "%s\t%s\t%f\t%f\t%f\t%f\n", min->num, min->name, min->score1, min->score2, min->score3, min->avg);
    }
    fclose(fp);
    return 0;
}