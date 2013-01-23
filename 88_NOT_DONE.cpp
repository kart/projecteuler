#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define MAX	50000

bool composite[MAX + 1];

vector<int> primes;

void seive(int N)
{
	int		i;

	for (i = 2; i * i <= N; i++)
	{
		if (composite[i])
			continue;
		for (int j = i + i; j <= N; j += i)
			composite[j] = true;
		primes.push_back(i);
	}
	for (; i <= N; i++)
		if (!composite[i])
			primes.push_back(i);
	return;
}

void prime_factorize(int N, vector<pair<int, int> > &prime_factors, vector<int> &sum_factors)
{
	while (N != 1)
	{
		int	sum = 0;
		for (int i = 0; N != 1 && i < primes.size(); i++)
		{
			int	count = 0;
			while (N % primes[i] == 0)
			{
				count++;
				N /= primes[i];
			}
			if (count == 0) continue;
			prime_factors.push_back(make_pair(primes[i], count));
			sum += primes[i] * count;
		}
		sum_factors[i] = sum;
	}
}

int main()
{
	vector<vector<pair<int, int> > > prime_factors(MAX + 1);
	vector<int>			 sum_factors(MAX + 1);

	seive(MAX);
	for (int i = 2; i <= MAX; i++)
		prime_factorize(i, prime_factors[i], sum_factors);
	return 0;
}
