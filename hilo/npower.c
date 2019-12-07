/*
 * It's to solve x^n, of course the size of value should be limited
 * because of the type of varibles.
 * coded by louiswei
 * in Wuhan-337 prison
 */

#include <stdio.h>

int main(void)
{
	int n;
	long long x;
	int i = 0;
	int a[6];

	scanf ("%d %d", &x, &n);

	while (n != 1)
	{
		if (n%2 == 0)
			a[i] = 0;
		else
			a[i] = 1;
		n /= 2;
		i++;
	}

	int init = x;
	while (i--)
	{
		x *= x;
		if (a[i] == 0)
			continue;
		else
			x *= init;
	}

	printf ("%lld", x);

	return 0;
}
