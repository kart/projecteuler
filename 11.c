#include <stdio.h>
#include <assert.h>

int	a[26][26];
int	dirx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int	diry[] = {0, 0, 1, -1, -1, -1, 1, 1};


int prod(int i, int j, int dx, int dy, int n)
{
	int	p, k, curx, cury;

	p = a[i][j];
	curx = i;
	cury = j;
	for (k = 0; k < n - 1; k++)
	{
		curx += dx;
		cury += dy;
		assert(curx >= 0 && cury >= 0 && curx < 26 && cury < 26);
		p *= a[curx][cury];
	}
	return p;
}

int main()
{
	int	i, j, p, max = -1, k, maxi, maxj;

	for (i = 0; i < 26; i++)
		for (j = 0; j < 26; j++)
			a[i][j] = 1;
	
	for (i = 3; i < 23; i++)
		for (j = 3; j < 23; j++)
			scanf("%d", &a[i][j]);
	
	for (i = 3; i < 23; i++)
	{
		for (j = 3; j < 23; j++)
		{
			for (k = 0; k < 8; k++)
			{
				p = prod(i, j, dirx[k], diry[k], 4);
				if (max < p)
				{
					max = p;
					maxi = i;
					maxj = j;
				}
			}
		}
	}
	printf("%d\n", max);
	printf("%d,%d\n", maxi, maxj);
	return 0;
}
