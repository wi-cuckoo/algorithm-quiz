#include <stdio.h>

struct chnum
{
	char c;
	int	 n;
};

struct chnum *col (int l, char s[])
{
	int i, j = 0;
	int len = l;
	struct chnum cn[len];

	cn[0].c = s[0];
	cn[0].n = 1;

	for (i=1; i<len; i++)
	{
		char t = s[i];

		if (t != s[i-1])
		{
			j++;
			cn[j].c = s[i];
			cn[j].n = 1;
		}
		else
			cn[j].n++;
	}

	if (j < len - 1)
	{
		cn[++j].c = ' ';
	}

	return cn;
}

int check (struct chnum *cn, int len)
{
	for (int i=1; i<=len-2; i++)
	{
		if ((cn->c + 1 == (cn+1)->c
			&& (cn+1)->c + 1 == (cn+2)->c)
			&& (cn->n >= (cn+1)->n
			&& (cn+1)->n <= (cn+2)->n)
		   )
			return 0;
		else if (cn->c == ' ')
			break;
		else 
			cn++;
	}

	return 1;
}

int main ()
{
	int num;
	
	scanf ("%d", &num);

	int ret[num];
	for (int i=0; i<num; i++)
	{
		int len;
		scanf ("%d", &len);

		char str[len + 1];
		scanf ("%s", str);

		struct chnum *cn = col (len, str);

		if (check (cn, len) == 0)
			ret[i] = 1;
		else 
			ret[i] = 0;
	}

	for (int i=0; i< num; i++)
	{
		if (ret[i])
			printf ("YES\n");
		else 
			printf ("NO\n");
	}

	return 0;
}
