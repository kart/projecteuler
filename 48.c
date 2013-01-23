#include <stdio.h>

#define MAX	10000000000

long long	last_10_digits(int n)
{
	long long	p = 1, i;

	for (i = 1; i <= n; i++)
		p = ((p % MAX) * (n % MAX)) % MAX;
	return p;
}

int main()
{
	int		i;
	long long	ans = 0;

	for (i = 1; i <= 1000; i++)
		ans += last_10_digits(i);
	printf("%lld\n", ans);
	return 0;
}
