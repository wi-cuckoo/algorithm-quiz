/*
 * It's about enumeration, forcefully
 * And it's derived from http://hihocoder.com/problemset/problem/1094
 * Though my code not get passed the testing, with RE error,
 * I don't konw why, but I can ensure my way is right.
 * coded by louis wei
 * in Wuhan-337 prison
 */
#include <stdio.h>

void rotate_90 (char old[3][3])
{
	char new[3][3];

	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			new[2-j][2-i] = old[i][2-j];

	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			old[i][j] = new[i][j];

}

int valid (char t[3][3], char p[3][3])
{
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			if (t[i][j] != p[i][j])
				return 1;
	return 0;
}	

int check (char t[3][3], char p[3][3])
{
	for (int i=0; i<4; i++)
	{
		if (!valid (t, p))
			return 0;
		else
			rotate_90 (t);
	}

	return 1;
}

int main()
{
	int N, M;
	int ret[1000][2];
	int count = 0;

	scanf ("%d%d", &N, &M);

	char map[N][M];
	char pos[3][3];

	for (int i=0; i<N; i++)
	{
		scanf ("%s", map[i]);
	}

	for (int i=0; i<3; i++)
	{
		scanf ("%s", pos[i]);
	}
	
	for (int i=1; i<N-1; i++)
	{
		for (int k=1; k<M-1; k++)
		{
			// the following code check if the map[i][k] is Hi's position
			// if it is, store the i and k into ret[];
			if (pos[1][1] != map[i][k]) continue;
				
			char test[3][3];
			
			for (int j=0; j<3; j++)
				for (int a=0; a<3; a++)
					test[j][a] = map[i-1+j][k-1+a];

			if (!check (test, pos))
			{
				ret[count][0] = i+1;
				ret[count][1] = k+1;
				count++;
			}
		}
	}

	for (int i=0; i<count; i++)
		printf ("%d %d\n", ret[i][0], ret[i][1]);

	return 0;
}

