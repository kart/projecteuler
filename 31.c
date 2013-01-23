#include <stdio.h>

/* This is just integer partition of N with a few exceptions. If you can do 76, you can do
 * this as well.
 */

long long int dp[201][201];
int den[] = {1,2,5,10,20,50,100,200};

int is_denomination(int n)
{
	int i;

	for (i = 0; i < 8; i++)
		if (den[i] == n)
			return 1;
	return 0;
}

int main()
{
	int		i, j, k, n, d;
	long long int	s, ans = 0;

	scanf("%d", &n);
	dp[1][1] = 1;
	for (i = 2; i <= n; i++)
	{
		if (is_denomination(i))
			dp[i][i] = 1;
		for (j = 1; i - j >= j; j++)
		{
			if (!is_denomination(j))
				continue;	
			d = i - j;
			s = 0;
			for (k = j; k <= d; k++)
				s += dp[d][k];
			dp[i][j] = s;
		}
	}
	for (i = 1; i <= n; i++)
		ans += dp[n][i];
	printf("%lld\n", ans, ans - 1);
	return 0;
}
