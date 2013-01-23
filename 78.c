#include <stdio.h>
#include <math.h>

#define MOD_MAX 	1000000
#define MAX		100000
#define T(N)	((N * (3 * N - 1)) / 2)

int dp_p[MAX];

/* The idea is to use Euler's pentagonal number theorem and apply it for find P(n) 
 * p(k) = p(k − 1) + p(k − 2) − p(k − 5) − p(k − 7) + p(k − 12) + p(k − 15) − p(k − 22) − ...
 * where p(0) is taken to equal 1, p(k) is zero for negative k, and the sum is taken over all generalized pentagonal numbers
 */

int p(int n)
{
	int	limit, t1_n, t2_n, p_n = 0, i, mod, term;
	
	if (n == 1 || n == 0)
		return 1;
	term = 1;
	for (i = 1; ; i++, term += 2)
	{
		t1_n = T(i);
		t2_n = T((-1 * i));
		mod = term % 4;
		if (mod == 1 || mod == 2)
		{
			if (n - t1_n >= 0)
				p_n = (p_n % MOD_MAX + dp_p[n - t1_n] % MOD_MAX) % MOD_MAX;
			else
				break;
			if (n - t2_n >= 0)
				p_n = (p_n % MOD_MAX + dp_p[n - t2_n] % MOD_MAX) % MOD_MAX;
			else
				break;
		}
		else
		{
			if (n - t1_n >= 0)
				p_n = (p_n % MOD_MAX - dp_p[n - t1_n] % MOD_MAX) % MOD_MAX;
			else
				break;
			if (n - t2_n >= 0)
				p_n = (p_n % MOD_MAX - dp_p[n - t2_n] % MOD_MAX) % MOD_MAX;
			else
				break;
		}
	}
	return p_n;
}

int main()
{
	int	n, i;

	for (i = 0; i < MAX; i++)
	{
		dp_p[i] = p(i);
		if (dp_p[i] == 0)
			break;
	}
	printf("%d\n", i);
	return 0;
}
