#include <stdio.h>

#define MAX_LINE 80 // 最大行长度

int readline(char s[], int limit);

int main(int argc, char const *argv[])
{
    int len;
    char line[MAX_LINE+2];
    while ((len = readline(line, MAX_LINE+2)) > 0)
        if (len <= MAX_LINE)
            printf("[%d] %s", len, line);
    
    return 0;
}

int readline(char s[], int limit) {
    int c, i;
    for (i = 0; i < limit-1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}
