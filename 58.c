#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int is_prime(int n)
{
	int		i;

	if (n == 1)
		return 0;
	if (n < 4)
		return 1;
	if (n % 2 == 0)
		return 0;
	if (n < 9)
		return 1;
	if (n % 3 == 0)
		return 0;
	for (i = 5; i * i < n; i += 6)
	{
		if (n % i == 0)
			return 0;
		if (n % (i + 2) == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int	n, *seivearr, i, j, p_count = 0, count = 0, ne, nw, sw, se;
	float	ratio;

	count = 1;
	p_count = 0;
	for (i = 3; i < 100000; i += 2)
	{
		ne = i * i - 3 * i + 3;
		nw = ne + (i - 1);
		sw = nw + (i - 1);
		/* No need to calculate the SW number as it is anyways a square and hence is NOT prime */
		p_count += is_prime(ne);
		p_count += is_prime(nw);
		p_count += is_prime(sw);
		count += 4;
		ratio = (p_count * 1.0) / (count * 1.0);
		if (ratio < 0.1)
		{
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}
