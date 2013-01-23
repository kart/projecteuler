#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

#define MAX	200000
#define LL	long long
#define LIMIT	1000
bool composite[MAX + 1];
vector<int> primes;

void seive(int n)
{
	int	i, j;

	for (i = 2; i * i <= n; i++)
	{
		if (composite[i])
			continue;
		for (j = 2 * i; j <= n; j += i)
			composite[j] = 1;
		primes.push_back(i);
	}
	for (; i <= n; i++)
		if (!composite[i])
			primes.push_back(i);
}

int main()
{
	seive(MAX);
	for (int N = 1000; N < MAX; N++)
	{
		if (!composite[N])
			continue;
		// Compute number of divsiors of N squared
		int numdiv = 1, cn = N;
		for (int i = 0; 1 != cn && i < primes.size(); i++)
		{
			int	count = 0;
			while (cn % primes[i] == 0)
			{
				cn /= primes[i];
				count++;
			}
			numdiv *= (count * 2 + 1);
		}
		int ans = (numdiv + 1) / 2;
		if (ans > LIMIT)
		{
			cout << N << endl;
			break;
		}
	}
	return 0;
}
