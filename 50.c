#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define ONE_MILLION	1000000 // From the problem statement 
#define MAX 		80000	// Based on the number of primes less than one million
int cumulative[MAX];

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

int main()
{
	int	n, *seivearr, i, j, count = 0, limit, maxi = -1, maxv, sum;

	scanf("%d", &n);
	seivearr = seive(n, 0);
	cumulative[count++] = 0;
	for (i = 2; i < n; i++)
		if (!seivearr[i])
			cumulative[count++] = i;
	// Find the cumulative sum of all the primes below one million. At some point the sum will
	// exceed one million. We need not go beyond that point. Fortunately, for this problem the
	// limit sum exceeds a million within the first 600 primes or so
	for (i = 1; i < count; i++)
	{
		cumulative[i] += cumulative[i - 1];
		if (cumulative[i] >= ONE_MILLION)
			break;
	}
	limit = i;
	// The idea now is that the sum of N consecutive primes starting from i is given by
	// cumulative[i + N] - cumulative[i - 1]. Just keep a running count of the max N
	// Since the 'limit' is small (600 or so), the n^2 algorithm runs reasonable fast
	for (i = 1; i < limit; i++)
	{
		for (j = i; j < limit; j++)
		{
			sum = cumulative[j] - cumulative[i - 1];
			assert(sum < ONE_MILLION);
			if (!seivearr[sum])
			{	/* sum is prime */
				if (maxi < (j - i + 1))
				{
					maxi = j - i + 1;
					maxv = sum;
				}
			}
		}
	}
	printf("%d, %d\n", maxi, maxv);
	return 0;
}
