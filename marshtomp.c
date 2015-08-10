/*
 * From hihocoder, see http://hihocoder.com/problemset/problem/1082
 * about operating string
 * coded by louis wei
 * in Wuhan-337 prison
 */

#include <stdio.h>
#include <string.h>

int check (int i, char s[])
{
	char test1[] = "rshtomp";
	char test2[] = "RSHTOMP";

	for (int j=0; j < 7; j++)
	{
		if (test1[j] == s[i+j] || test2[j] == s[i+j])
			continue;
		else 
			return 1;
	}

	return 0;
}

void replace (char str[])
{
	char repl[] = "fjxmlhx00";
	int i = 0;

	while (str[i] != '\0' )
	{
		if (str[i] == 'M' || str[i] == 'm' )
		{
			if (str[i+1] == 'A' || str[i+1] == 'a')
			{
				if (!check(i+2, str))
				{
					int k = 0;
					while (k < 9)
						str[i++] = repl[k++];
				}
				else
				{
					i++; continue;
				}
			}
			else
			{
				i++; continue;
			}
		}
		else 
		{
			i++; continue;
		}
	}

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '0') 
		{
			i++;
			continue;
		}
		printf ("%c", str[i++]);
	}

}

int main (void)
{
	char instr[1024][200];

	int count = 0;
	while (fgets (instr[count], 200, stdin)) count++;

	int i = 0;
	while (i < count)
	{
		char str[100];
		strcpy (str, instr[i++]);
//		printf ("%s", str);
		replace (str);	
	}

	return 0;
}
