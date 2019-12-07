#include <stdio.h>

#define IN 0
#define OUT 1

// 以每行一个单词的形式打印其输出

int main(int argc, char const *argv[])
{
    int c, stat;
    while (c != EOF)
    {
        c = getchar();
        if (c != ' ' && c != '\t' && c != '\n')
        {
            stat = IN;
            putchar(c);
        } else if (stat == IN)
        {
            putchar('\n');
            stat = OUT;
        }
    }    
    return 0;
}
