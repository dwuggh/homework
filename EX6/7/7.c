#include <stdio.h>
#include <stdlib.h>
#define NUM 2
struct student
{
    int wu_da_ai_hao[5];
    
}stu[NUM];

float man_shen_da_han(int i)//average score of specific student
{
    int j, re = 0;
    for(j = 0; j < 5; j++) re = re + stu[i].wu_da_ai_hao[j];
    return (float)re/5;
}
float da_chang_ci_shen(int i)//average score for specific habit
{
    int j, re = 0;
    for(j = 0; j < NUM; j++) re = re + stu[j].wu_da_ai_hao[i];
    return (float)re/NUM;
}
void princess_ayitubie(){//highest score(s)
    int max = 0;
    int i, j;
    for(i = 0; i < NUM; i++){
        for(j = 0; j < 5; j++){
            max = max > stu[i].wu_da_ai_hao[j] ? max : stu[i].wu_da_ai_hao[j];
        }
    }
    printf("highest score: %d\n", max);
    for(i = 0; i < NUM; i++){
        for(j = 0; j < 5; j++){
            if(max == stu[i].wu_da_ai_hao[j]){
                printf("student: %d\tcourse: %d\n", i+1, j+1);
            }
        }
    }
}

float qu_ni_de_ba(){//vaiance of mean scores
    int i;
    float a = 0, b = 0;
    for(i = 0; i< NUM; i++){
        a = a + man_shen_da_han(i) * man_shen_da_han(i);
        b = b + man_shen_da_han(i);
    }
    float sigma = a/NUM - (b/NUM)*(b/NUM);
    return sigma;
}

void chouyan_hejiu_tangtou(){//initialization
    int i, j;
    for(i = 0; i< NUM; i++){
        for(j = 0; j < 5; j++){
            scanf("%d",&stu[i].wu_da_ai_hao[j]);
        }
    }
    for(i = 0; i< NUM; i++){
        for(j = 0; j < 5; j++){
            if(stu[i].wu_da_ai_hao[j] < 0){
                printf("invalid score on student %d course %d\n", i+1, j+1);
                exit(0);
            }
        }
    }
}

int main(){
    chouyan_hejiu_tangtou();
    
    int i, j;
    for(i = 0; i < NUM; i++){
        printf("student %d :\t%f\n", i + 1, man_shen_da_han(i));
    }
    for(i = 0; i < 5; i++){
        printf("course %d :\t%f\n", i + 1, da_chang_ci_shen(i));
    }
    princess_ayitubie();
    printf("variance:\t%f", qu_ni_de_ba());
    return 0;
}