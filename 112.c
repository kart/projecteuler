#include <stdio.h>

int is_bouncy(int N)
{
	int		increasing = 1, decreasing = 1;
	int		units = N % 10;
	
	N /= 10;
	while (N != 0)
	{
		int	d = N % 10;

		if (increasing && (d > units))
			increasing = 0;
		if (decreasing && (d < units))
			decreasing = 0;
		units = d;
		N /= 10;
	}
	return !(increasing || decreasing);
}

int main()
{
	int		i, count = 0, n;
	double		percent;

	for (i = 100; ; i++)
	{
		count += is_bouncy(i);
		percent = 100 * ((1. * count) / (1. * i));
		if (percent >= 99.0f)
			break;
	}
	printf("%d; %f\n", i, percent);
	return 0;
}
