#include <stdio.h>
#include <assert.h>
#include <math.h>

int num[101];
#define MAX 100

/* This is a pretty neat problem. Thanks to Ivan for finding out a subtle bug in the logic. Have to tidy it up though */

int doit(int n)
{
	int	i, largest_power_of_n, p, j, k, count = 0, valid;

	p = 1;
	for (largest_power_of_n = 1; ; largest_power_of_n++)
	{
		p *= n;
		if (p > MAX)
			break;
	}
	largest_power_of_n--;
	for (i = 2; i <= largest_power_of_n * MAX; i++)
	{
		count++;
		if (i > MAX)
		{
			valid = 0;
			for (j = 2; j <= (int)sqrt(i); j++)
			{
				if (0 == i % j)
				{
					k = i / j;
					if ((j <= largest_power_of_n || k <= largest_power_of_n) && k <= MAX)
						valid = 1;
				}
			}
			if (0 == valid)
				count--;
		}
	}
	return count;
}

int main()
{
	int	i, ans, p, j;

	ans = 0;
	for (i = 2; i <= 100; i++)
	{
		if (num[i])
			continue;
		ans += doit(i);
		num[i] = 1;
		p = 1;
		for (j = 1; ; j++)
		{
			p *= i;
			if (p > MAX)
				break;
			num[p] = 1;
		}
	}
	printf("%d\n", ans);
}
