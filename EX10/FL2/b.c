#include <stdio.h>
#define TLINE 10
#define LINEP 2
int main(int argc, char* argv[]){
    int flag = 1, page = 1, line = 1, i;
    char buff[100];
    FILE *fp;
    if(argc < 2){
        printf("\n No file name\n");
        return 0;
    }
    if((fp = fopen(argv[1], "r")) == 0){
        printf("\nCannot open file\n");
        return 0;
    }
    while(flag){
        for(i = 0; i < LINEP; i++) printf("\n");
        printf("%s\n", argv[1]);
        for(i = 0; i < TLINE; i++){
            if(fgets(buff, 80, fp) == 0) flag = 0;
            if(flag){
                printf("6d %s", line++, buff);
                if(buff[78] != 0) printf("\n");
            }
            else
            {
                for(i += 2; i < TLINE; i++) putchar('\n');
            }
        }
        
        printf("\n%65s%d.\n",". ", page++);
        for(i = 0; i < LINEP; i++) printf("\n");
    }
    return 0;
}