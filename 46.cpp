#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

vector<int> primes;

#define MAX	50000

bool is_square(int n)
{
	double x = sqrt(n * 1.);

	return ceil(x) == floor(x);
}

int* seive(int n)
{
	int	*seivearr, i, j;

	seivearr = (int *)malloc(n * sizeof(int));
	memset(seivearr, 0, sizeof(int) * n);
	for (i = 2; i * i <= n; i++)
	{
		if (seivearr[i])
			continue;
		primes.push_back(i);
		for (j = 2 * i; j < n; j += i)
			seivearr[j] = 1;
		seivearr[i] = 0;
	}
	for (; i < n; i++)
		if (!seivearr[i])
			primes.push_back(i);
	return seivearr;
}

int main()
{
	int		i, *seivearr;

	seivearr = seive(MAX);
	for (int i = 3; i < MAX; i += 2)
	{
		if (!seivearr[i]) continue;
		int j;
		for (j = 0; j < primes.size(); j++)
			if (primes[j] < i && is_square((i - primes[j]) >> 1))
				break;
		if (j == primes.size())
		{
			cout << i << endl;
			break;
		}
	}
	free(seivearr);
	return 0;
}
