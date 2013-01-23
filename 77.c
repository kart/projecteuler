#include <stdio.h>

#define MAX	5000	/* from the problem statement */

int dp[MAX + 1][MAX + 1];

int* seive(int n, int print)
{
	int	*seivearr, i, j;

	seivearr = malloc(n * sizeof(int));
	memset(seivearr, 0, sizeof(int) * n);
	seivearr[1] = -1;
	for (i = 2; i * i <= n; i++)
	{
		if (seivearr[i])
			continue;
		for (j = 2 * i; j < n; j += i)
			seivearr[j] = 1;
		seivearr[i] = 0;
	}
	if (print)
	{
		for (i = 2; i < n; i++)
			if (!seivearr[i])
				printf("%d\n", i);
	}
	return seivearr;
}


int main()
{
	int	i, j, k, n, d, s, ans;
	int	*seivearr;

	seivearr = seive(MAX + 1, 0);
	scanf("%d", &n);
	for (i = 2; i <= n; i++)
	{
		if (!seivearr[i])
			dp[i][i] = 1;
		for (j = 2; i - j >= j; j++)
		{
			if (seivearr[j])
				continue;
			d = i - j;
			s = 0;
			for (k = j; k <= d; k++)
				s += dp[d][k];
			dp[i][j] = s;
		}
	}
	for (i = 2; i <= n; i++)
		ans += dp[n][i];
	printf("%d\n", ans);
	return 0;
}
