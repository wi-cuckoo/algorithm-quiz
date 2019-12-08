#include <stdio.h>

int main(int argc, char const *argv[])
{
    int letter[26];
    for (int i = 0; i < 26; i++) letter[i] = 0;
    int c, total;
    while ((c = getchar()) != EOF)
    {
        int is_letter = 1;
        if (c >= 'a' && c <= 'z')
            ++letter[c-'a'];
        else if (c >= 'A' && c <= 'Z')
            ++letter[c-'A'];
        else
            is_letter = 0;
        if (is_letter)
            ++total;
    }
    for (int i = 0; i < 26; i++)
    {
        int idx = i;
        printf("%c: ", idx+'A');
        int num = letter[idx];
        // 此处需要获得显示设备宽度，以确定 100% 的显示长度不超出一行范围
        for (int j = 0; j < num*1000/total; j++)
            putchar('>');
        printf(" %.2f%%\n", letter[idx]*100.0/total);
    }
    return 0;
}
