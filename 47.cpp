#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

#define MAX	200000

int* seive(int n)
{
	int	*seivearr, i, j;

	seivearr = (int *)malloc(n * sizeof(int));
	memset(seivearr, 0, sizeof(int) * n);
	for (i = 2; i * i <= n; i++)
	{
		if (seivearr[i])
			continue;
		for (j = 2 * i; j < n; j += i)
			seivearr[j] = 1;
		seivearr[i] = 0;
	}
	return seivearr;
}

int distinct_primes(int n, int *seivearr)
{
	int count = 0, cn = n;
	
	if (!seivearr[n]) return 0;
	for (int st = 2; n > 1; st++)
	{
		if (seivearr[st]) continue;
		count += (0 == n % st);
		while (n % st == 0)
			n /= st;
		if (count > 4)
			return 0;
	}
	return count;
}

int main()
{
	int		*seivearr;

	seivearr = seive(MAX);
	for (int i = 208; ; i += 4)
	{
		int dist = distinct_primes(i, seivearr);
		if (dist == 4)
		{
			int prev = -1;
			int count = 1;
			for (int j = i - 4; j <= i + 4; j++)
			{
				dist = distinct_primes(j, seivearr);
				if (dist == 4 && dist == prev)
					count++;
				else
					count = 1;
				prev = dist;
				if (count == 4)
				{
					cout << j - 3 << ", " << j << endl;
					return 0;
				}
			}
		}
	}
	free(seivearr);
	return 0;
}
