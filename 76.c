#include <stdio.h>

/* Classical integer partition of N. 2 dimensional DP. */

int dp[101][101];

int main()
{
	int	i, j, k, n, d, s, ans;

	scanf("%d", &n);
	dp[1][1] = 1;
	for (i = 2; i <= n; i++)
	{
		dp[i][i] = 1;
		for (j = 1; i - j >= j; j++)
		{
			d = i - j;
			s = 0;
			for (k = j; k <= d; k++)
				s += dp[d][k];
			dp[i][j] = s;
		}
	}
	for (i = 1; i <= n; i++)
		ans += dp[n][i];
	printf("%d, %d\n", ans, ans - 1);
	return 0;
}
