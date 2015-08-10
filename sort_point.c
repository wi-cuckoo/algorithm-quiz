/*
 * We all konw insert sorting. and this is to sort point(x,y)
 * along with the direction of X axis
 * see http://wi-cuckoo.github.io/algorithm/sortpoint.html
 * coded by louis wei
 * in Wuhan-337 prison.
 */
#include <stdio.h>

struct point
{
	int x;
	int y;
};

int main (void)
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

		while (temp >= 0 && input[temp].x >= key.x)
		{
			if (input[temp].x == key.x)
			{
				while (temp >= 0 && input[temp].y >= key.y)
				{
					if (input[temp].y == key.y)
					{
						count++; break;
					}
					
					input[temp+1] = input[temp];
					temp--;	
				}
				input[temp+1] = key;
				break;
				
			}
			input[temp+1] = input[temp];
			temp--;
		}

		input[temp+1] = key;
	}
		
	if (count != 4) //if not 4 different point, wrong obviously 
		return 0;  
	else
		return 1;

}	

