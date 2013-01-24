#include <math.h>

int is_pandigital(long long t)
{
	int found[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, i;

	while (0 != t)
	{
		int d = t % 10;
		if (found[d]) return 0;
		found[d] = 1;
		t /= 10;
	}
	for (i = 1; i <= 9; i++)
		if (!found[i])
			return 0;
	return 1;
}
// Answer = 329468
int main()
{
	long double	log10_root5 = log10l(sqrtl(5.0));
	long double	phi = (1 + sqrtl(5.0)) / 2.0;
	long double	log10_phi = log10l(phi);
	long double	digits, fract;
	long long	f1 = 1, f2 = 1, t, last9 = 1000000000, res;
	int		i;
	
	for (i = 3; 300000; i++)
	{
		long long t = (f1 + f2) % last9;
		if (is_pandigital(t))
		{
			digits = i * log10_phi - log10_root5;
			fract = digits - floorl(digits);
			res = (long long)(powl(10, fract) * 100000000);
			if (is_pandigital(res))
			{
				printf("%d\n", i);
				break;
			}
		}
		f1 = f2;
		f2 = t;
	}
	return 0;
}
