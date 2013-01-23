#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

#define MAX	8000
#define LL	long long
#define LIMIT	50000000
bool composite[MAX + 1];
vector<int> primes;
set<int> unique;		// Can be eliminated if we do careful counting 

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

	for (int i = 0; i < primes.size(); i++)
	{
		LL x = primes[i];
		if (x * x >= LIMIT)
			break;
		for (int j = 0; j < primes.size(); j++)
		{
			LL y = primes[j];
			if (x * x + y * y * y  >= LIMIT)
				break;
			for (int k = 0; k < primes.size(); k++)
			{
				LL z = primes[k];
				if (x * x + y * y * y + z * z * z * z >= LIMIT)
					break;
				unique.insert(x * x + y * y * y + z * z * z * z);
			}
		}
	}
	cout << unique.size() << endl;
	return 0;
}
