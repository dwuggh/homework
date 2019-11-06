#include <stdio.h>
#define print(a) my_print(a, 80)
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
void insert_b2a(int *a, int *b, int size_a, int size_b){
    int max_a = size_a/sizeof(int);
    int max_b = size_b/sizeof(int);
    int i,j,k;
    for(i = 0; i < max_b; i++){
        for(j = 0; j < max_a + i; j++){
            if(a[j] <= b[i] && a[j+1] >= b[i]){
                //如果b[i]在a[j]和a[j+1]中间，则插入到a[j+1]
                for(k = max_a + i; k > j+1; k--){
                    a[k] = a[k-1];
                }
                a[j+1] = b[i];
                break;
            }
            //如果b[i]为a中最大值，则一插到底
            else if(j == max_a-1) a[max_a + i] = b[i];
        }
    }
}
void my_print(int *a, int size){
    int i;
    for(i = 0; i < size/sizeof(int); i++){
        printf("%d ",*(a+i));
    }
    putchar('\n');
    return ;
}
int main(){

    int a[20]={5,4,3,2,1,7,9,3,3,4,0}, b[10]={1,2,3,4,5};
    //a[20] = {5,4,3,2,1,7,9,3,3,4};
    int i=0, j=0;
    
    /*
    for(i=0;i<20;i++){
        scanf("%d", a+i);
    }
    for(i=0;i<20;i++){
        scanf("%d", b+i);
    }
    */
    print(a);
    bubble(a, sizeof(a)/2);//仅用前半空间，后半空间留给b数组用于插入
    print(a);
    insert_b2a(a, b, sizeof(a)/2, sizeof(b));
    print(a);
    return 0;
}