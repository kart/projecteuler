#include <stdio.h>

int a[100][100];

/* Vanila dynamic programming - Also solves problem 67 */

int main()
{
	int		n, i, j, max = -1;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{	
		memset(&a[i], 0, n);
		for (j = 0; j <= i; j++)
			scanf("%d", &a[i][j]);
	}
	for (i = 1; i < n; i++)
		a[i][0] += a[i - 1][0];
	for (i = 1; i < n; i++)
		for (j = 1; j <= i; j++)
			a[i][j] += (a[i-1][j] > a[i-1][j-1] ? a[i-1][j] : a[i-1][j-1]);
	for (i = 0; i < n; i++)
		max = max < a[n - 1][i] ? a[n - 1][i] : max;
	printf("\nmax = %d\n", max);

	return 0;
}
