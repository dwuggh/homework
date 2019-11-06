#include <stdio.h>

int main(){
    int c;
    int letter = 0, space = 0, tabs = 0, line_break = 0, others = 0;
    while (c = getchar())
    {
        if((c >= 0x0041 && c <= 0x005a) || (c >= 0x0061 && c <= 0x007a)) letter ++;
        else if(c == 0x0020) space ++;
        else if(c == 0x0009) tabs ++;
        else if(c == 0x000d) line_break ++;
        else others ++;
    }
    printf("letters:%d\tspaces:%d\ttabs:%d\nline breaks:%d\tothers:%d\n",letter, space, tabs, line_break, others);
    return 0;
    
}