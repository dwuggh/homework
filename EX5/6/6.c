#include <stdio.h>
#define print(a) my_print(a, 60)

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
void bubble(int *a, int size){
    int i, j;
    int max = size/sizeof(int);
    for(i = max-1; i >= 0; i--){
        for(j = i; j < max-1; j++){
            if(a[j] > a[j+1]) swap(a+j, a+j+1);
        }
    }
    return ;
}
void result(int *a, int k){
    int i,j,m;
            for(i = k; a[i]==a[k];i--);
            for(j = k; a[j]==a[k];j++);
            i++;
            printf("index(s): ");
            for(;i < j; i++){
                printf("%d ",i);
            }
            putchar('\n');
}
int binsearch(int *a, int size, int target){
    int max = size/sizeof(int);
    int k = (1+max)/2;
    int flxg = 0;//flxg!
    while (k > 0)
    {
        if(target == a[k]){
            flxg = 1;
            result(a,k);
            break;
        }
        else if(target == a[k+1]){
            flxg = 1;
            result(a, k+1);
            break;
        }
        else if(target < a[k]){
            k = k/2;
            continue;
        }
        else if(target > a[k+1]){
            k = (k+max+1)/2;
            continue;
        }
    }
    if(flxg == 0) printf("%d is not in a\n", target);
    return flxg;
    
}
int main(){

    int a[15] = {6,3,4,2,57,4,-43,65,32,64,3,6,-56,2,2};
    int target = 0;
    scanf("%d",&target);
    bubble(a, sizeof(a));//无序数组没法二分查找
    binsearch(a, sizeof(a), target);

    return 0;
}