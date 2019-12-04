#include <stdio.h>
#include <string.h>
typedef struct book_info{
    char num[20];
    char name[50];
    char author[100];
    char pub[100];
    int price;
}Book_info;

int main(){
    Book_info book[10];
    int i;
    for(i = 0; i < 10; i++) memset((void*)&book[i], 0, sizeof(Book_info));
    for(i = 0; i < 10; i++){
        printf("book name: ");
        scanf("%s", book[i].name);
        printf("author: ");
        scanf("%s", book[i].author);
        printf("ISBN: ");
        scanf("%s", book[i].num);
        printf("publisher: ");
        scanf("%s", book[i].pub);
        printf("price: ");
        scanf("%d", &book[i].price);
    }
    int avg = 0;
    for(i = 0; i < 10; i++){
        if(book[i].price < 0) {
            printf("invalid input\n");
            return 0;
        }
    }
    for(i = 0; i < 10; i++){
        avg = avg + book[i].price;
    }
    
    printf("%f\n", (float)avg/10);
}