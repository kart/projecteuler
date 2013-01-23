#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long seive(int n)
{
	int		*s, start, c, cnt = 0;
	long long	sum = 0;

	s = malloc(sizeof(int) * (n + 1));
	memset(s, 0, sizeof(int) * (n + 1));
	if (s)
	{
		start = 2;
		sum = 0;
		while (1)
		{
			while ((start <= n) && s[start])
				start++;
			if (start > n)
				break;
			sum += start;
			c = 0;
			while (1)
			{
				c += start;
				if (c > n)
					break;
				s[c] = 1;
			}
			cnt++;
		}
	} else
	{
		printf("Out of memory...\n");
		return -1;
	}
	printf("Number of Primes less than or equal to %d = %d\n", n, cnt);
	return sum;
}

int main()
{
	int	n;

	scanf("%d", &n);
	printf("%lld\n", seive(n));
	return 0;
}
