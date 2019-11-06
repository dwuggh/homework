#include <cstdio>
#include <iostream>

using namespace std;

class Student{
    public:
        char stu_num[20];
        float print_num_and_avg_score(){
            float avg = (float)( (scoreA + scoreB + scoreC)/3 );
            printf("%s:\t%f\n", stu_num, avg);
            return avg;
        }
        void get_inf(){
            cin >> stu_num >> scoreA >> scoreB >> scoreC;
            while (scoreA < 0 || scoreB < 0 || scoreC < 0)//somewhat checking the input
            {//should have checked the input data type, but I was too lazy as ever...
                cout << "invalid score" << endl;
                cin >> stu_num >> scoreA >> scoreB >> scoreC;
            }
            
        }
    private://Who would want his score to be public??
        int scoreA;
        int scoreB;
        int scoreC;
}student[50];

int main(){
    for(int i = 0; i < 50; i++){
        student[i].get_inf();
    }
    int min=0, max = 0;
    for(int i = 0; i < 50; i++){
        int avg = student[i].print_num_and_avg_score();
        min = avg < min ? i : min;
        max = avg > max ? i : max;
    }
    cout << "worst: " << endl;
    student[min].get_inf();
    cout << "best: " << endl;
    student[max].get_inf();
    return 0;
}