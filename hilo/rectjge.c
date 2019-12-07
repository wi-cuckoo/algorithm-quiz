#include <stdio.h>

struct point
{
	int x;
	int y;
};

struct point sub (struct point p1, struct point p2)
{
	p1.x = p2.x - p1.x;
	p1.y = p2.y - p2.y;

	return p2;
}

int vector_mul (struct point v1, struct point v2)
{
	int re = 0;

	re = v1.x*v2.x + v1.y*v2.y;

	return re;
}

int check (struct point input[])
{
	input[1] = sub (input[2], input[0]);
	input[3] = sub (input[4], input[0]);
	input[5] = sub (input[2], input[6]);
	input[7] = sub (input[4], input[6]);
		
	if (vector_mul (input[1], input[3]) ||
		vector_mul (input[1], input[5]) ||
		vector_mul (input[7], input[3]))
		return 0;
	else 
		return 1;

}

int sort_point(void);

int main (void)
{
	int num;
	int i = 0;

	scanf ("%d", &num);

	int ret[num];

	while (i < num)
	{
		ret[i++] = sort_point();	
	}
	
	for (i=0; i < num; i++)
	{
		if (ret[i])
			printf ("YES\n");
		else
			printf ("NO\n");
	}
	 
	return 0;
}


int sort_point (void)
{
	struct	point	input[8];
	int		j = 0;

	for (int k=0; k<4; k++)
	{
		int x1, x2, y1, y2;	
		scanf ("%d%d%d%d", &x1, &y1, &x2, &y2);
		input[j].x = x1;
		input[j++].y = y1;
		
		input[j].x = x2;
		input[j++].y = y2;

	}
	
	int count = 0;				//count if point repeats.

	for (j=1; j<8; j++)
	{
		struct	point key = input[j];
		int		temp = j-1;

		while (temp >= 0 && input[temp].x >= key.x
				&& input[temp].y >= key.y)
		{
			if (input[temp].y == key.y)
			{
				count++; input[temp+1] = key;
				break;
			}
			input[temp+1] = input[temp];
			temp--;
		}

		input[temp+1] = key;
	}
		
	if (count != 4) //if not 4 different point, wrong obviously 
	{
		return 0;  
	}
		
	if (check (input))
		return 1;
	else
		return 0;

}	

