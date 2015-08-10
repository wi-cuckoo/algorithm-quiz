/*
 * The question is in hihocoder
 * about it's description,
 * see http://hihocoder.com/problemset/problem/1051
 * coded by louis wei
 * in Wuhan-337 prison
 */
#include <stdio.h>

int maxday (int ,int, int day[]);
void output (int, int rel[]);

int main (void)
{
	int num, N, M;
	
	scanf ("%d", &num);
	
	int out[num];

	int k = 0;
	while (k < num)
	{
		scanf ("%d %d", &N, &M);

		int day[N];
		int i = 0;
		while ( i < N)
			scanf ("%d", &day[i++]);

		if (N < M)
		{
			out[k++] = 100;	
			continue;
		}
		else out[k++] = maxday (N, M, day);
	}	

	output (num, out);

	return 0;
}

int maxday (int n, int m, int day[])
{
	int max = day[m] - 1 ;
	int j = 0;
	while ((j+m+1) < n)
	{
		int temp = day[j+m+1] - day[j++] - 1;
		max = temp > max? temp: max;
	}

	return max;
}

void output (int num, int rel[])
{
	int i = 0;
	while (i < num)
		printf("%d\n", rel[i++]);
}
