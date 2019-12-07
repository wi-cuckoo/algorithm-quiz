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
        printf("%c: %.2f%%\n", i+'a', letter[i]*100.0/total);
        
    return 0;
}
