#include <stdio.h>
#include <string.h>

int kmp (int len_ori, int len_mod, char ori[], char mod[])
{
	int		NEXT[len_mod+1];
	int		p = 1, q = 0;
	int		count = 0;

	NEXT[0] = -1;
	NEXT[1] = 0;

	while (p < len_mod)
	{
		if (mod[p] == mod[q])
			NEXT[++p] = ++q;
		else
		{
			if ((q = NEXT[q]) == -1)
				NEXT[++p] = ++q;
		}
	}

	p = 0; q = 0;
	
	while (p < len_ori)
	{
		if (ori[p] == mod[q])
		{
			if (q == len_mod-1)
			{
				count++;
				q = NEXT[q];
			}
			p++; q++;
		}
		else 
		{
			if ((q = NEXT[q]) == -1) 
			{
				p++; q++;
				continue;
			}
		}
	}
	
	return count;
}
int main(void)
{
	char	_ori[1000000];
	char	_mod[10000];
	int		num;
	int		len_mod, len_ori;

	scanf ("%d\n", &num);

	int		ret[num];
	int		i = 0;
		
	while (i < num)
	{
		
/*		fgets (_mod, 10000, stdin);
		fflush (stdin);
		fgets (_ori, 1000000, stdin);
*/
		gets (_mod);
		gets (_ori);

		len_mod = strlen (_mod);
		len_ori = strlen (_ori);
		char	mod[len_mod];
		char	ori[len_ori];
		
		strncpy (mod, _mod, len_mod);
		strncpy (ori, _ori, len_ori);

		ret[i++] = kmp (len_ori, len_mod, ori, mod);
	}
	
	i = 0;
	while (i < num)
		printf ("%d\n", ret[i++]);

	return 0;
}
