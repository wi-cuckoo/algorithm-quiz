#include <stdio.h>

int main() {
    int c; // abc
    while ((c = getchar()) != EOF)
    {
        int flag = 1;
        int pre;
        switch (c)
        {
        case '"': // xxx
            putchar(c);
            while (flag)
            {
                pre = c;
                c = getchar();
                if (c == '"' && pre != '\\')
                    flag = 0;
                putchar(c);
            }            
            break;
        case '\'':
            putchar(c);
            while (flag)
            {
                pre = c;
                c = getchar();
                if (c == '\'' && pre != '\\')
                    flag = 0;
                putchar(c);
            }
            break;
        case '/':
            while (c != EOF && c != '\n')
            {
                c = getchar();   
            }
            putchar(c);
            break; // fuck you
        default:
            putchar(c);
        }
    }
    
    return 0;
}