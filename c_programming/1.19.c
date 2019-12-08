#include <stdio.h>

#define MAX_LINE 1<<10

void reverse(char s[], int len) {
    int i;
    for (i = 0; i < len/2; i++)
    {
        char tmp = s[i];
        s[i] = s[len-1-i];
        s[len-1-i] = tmp;
    }
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

int main(int argc, char const *argv[])
{
    int len;
    char line[MAX_LINE];
    while ((len = readline(line, MAX_LINE)) > 0)
    {
        printf("[%d] %s", len, line);
        reverse(line, len-1);
        printf("[%d] %s", len, line);
    }
    return 0;
}
