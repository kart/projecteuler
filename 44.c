#include <stdio.h>
#include <math.h>
#include <assert.h>

#define MAX		10001
#define IS_SQUARE(Y)	(sqrt(Y) == (int)(sqrt(Y)))

long long pent[MAX];

int is_pent(long long n)
{
	long long	y;

	y = 24 * n + 1;
	if (IS_SQUARE(y) && (0 == ((int)sqrt(y) + 1) % 6))
		return 1;
	return 0;
}

int main()
{
	int		i, j;
	long long	sum, d, pj, pk, max_pent, min;

	for (i = 1; i < MAX; i++)
		pent[i] = i * (3 * i - 1) / 2;
	
	assert(is_pent(pent[2])); /* to verify if is_pent function works */

	max_pent = pent[MAX - 1];
	for (i = 1; i < MAX; i++)
	{
		for (j = 1; j < MAX; j++)
		{
			sum = pent[i] + pent[j];
			if (sum % 2 == 0)
			{
				pk = sum / 2;
				if (is_pent(pk))
				{
					d = pent[i] < pent[j] ? pent[i] : pent[j];
					pj = pk - d;
					if (pj == 0 || !is_pent(pj))
						continue;
					printf("Pk = %lld, Pj = %lld\n", pk, pj);
					printf("d = %lld\n", d);
					return 0;
				}
			}
		}
	}
	printf("FAILURE!!");
	return -1;
}
