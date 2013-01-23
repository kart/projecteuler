#include <stdio.h>
#include <assert.h>

int qu[1001];
int seen[1001];
int rem[1001];

/* TODO - Needs to be revamped for brevity.. too many unnecessary stuff */

int cycle(int n)
{
	int	num = 1, count = 0, i, q, r, c;

	num *= 10;
	while (num < n)
	{
		num *= 10;
		qu[count++] = 0;
	}
	for (i = 1; i <= n; i++)
	{
		q = num / n;
		r = num % n;
		qu[count] = q;
		rem[count] = r;
		if ((r == 0) || seen[r])
			break;
		seen[r] = 1;
		num = r * 10;
		count++;
		while (num < n)
		{
			num *= 10;
			qu[count++] = 0;
		}
	}
	c = 0;
	if (r != 0)
	{
		for (i = 0; i < count; i++)
			if (rem[i] == r)
				break;
		assert(i <= count);
		c = count - i;
	}
	printf("%d == 0.", n);
	for (i = 0; i <= count; i++)
		printf("%d", qu[i]);
	printf("; cycle = %d\n", c);
	return c;
}

int main()
{
	int	n, i, x, max = -1, maxi;

	scanf("%d", &n);
	for (i = 2; i <= n; i++)
	{
		memset(rem, 0, sizeof(int) * 1000);
		memset(qu, 0, sizeof(int) * 1000);
		memset(seen, 0, sizeof(int) * 1000);
		x = cycle(i);
		if (max < x)
		{
			max = x;
			maxi = i;
		}
	}
	printf("MAX CYCLE = %d for %d\n", max, maxi);
	return 0;
}
