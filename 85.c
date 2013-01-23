#include <stdio.h>

#define TRIANGULAR(N)	((N * (N + 1)) / 2)
#define MAX		2000000
#define ABS(X)		((X) < 0 ? -1 * (X) : (X))

int main()
{
	int		i, j, d = 12000, min_i, min_j, count = 0;

	for (i = 50; i >= 1; i--)
	{
		for (j = 50; j <= 100; j++)
		{
			int x = (TRIANGULAR(i) * TRIANGULAR(j));
			if (x > MAX + 10000)
				break;
			count++;
			if (ABS(x - MAX) < d)
			{
				min_i = i;
				min_j = j;
				d = ABS(x - MAX);
			}
		}
	}
	printf("%d, %d, %d\n", min_i, min_j, TRIANGULAR(min_i) * TRIANGULAR(min_j));
	printf("%d\n", count);
}
