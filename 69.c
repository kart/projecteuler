#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define ONE_MILLION	1000000 // From the problem statement 

// The below implementation relies on the following result.
// if N is prime, PHI(N) = 1. Else, N can be written as product
// of at least 2 numbers. Call it m1, m2. Now,
// PHI(N) = PHI(m1) * PHI(m2) * (d / PHI(d)) where d is gcd(m1, m2)
// Note, that m1, m2, d are all less than N and hence their PHI values
// would have been already computed. This implementation takes around
// 0.6 seconds.  However, there is a much better implementation. I'll
// Code it separately.

int phi_n[ONE_MILLION];

int* seive(int n, int print)
{
	int	*seivearr, i, j;

	seivearr = malloc(n * sizeof(int));
	memset(seivearr, 0, sizeof(int) * n);
	seivearr[1] = -1;
	for (i = 2; i * i <= n; i++)
	{
		if (seivearr[i])
			continue;
		for (j = 2 * i; j < n; j += i)
			seivearr[j] = 1;
		seivearr[i] = 0;
	}
	if (print)
	{
		for (i = 2; i < n; i++)
			if (!seivearr[i])
				printf("%d\n", i);
	}
	return seivearr;
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
	int	n, *seivearr, i, j, k, d, maxv;
	float	maxi = -1.0, ratio;

	seivearr = seive(ONE_MILLION, 0);
	phi_n[1] = 1;
	for (i = 2; i < ONE_MILLION; i++)
	{
		if (!seivearr[i])
			phi_n[i] = i - 1;
		else
		{
			for (j = 2; j * j <= i; j++)
			{
				if (!seivearr[j] && (0 == i % j))
				{
					k = i / j;
					assert(k < i && j < i);
					d = gcd(j, k);
					phi_n[i] = (phi_n[k] * phi_n[j] * d) / phi_n[d];
					ratio = (i * 1.0) / (phi_n[i] * 1.0);
					if (maxi < ratio)
					{
						maxi = ratio;
						maxv = i;
					}
					break;
				}
			}
		}
	}
	printf("%d/%d = %f is the maximum\n", maxv, phi_n[maxv], maxi); 
	return 0;
}
