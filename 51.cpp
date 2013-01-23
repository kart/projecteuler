#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <map>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

map<int,bool> primes;

#define DIGITS(N)	((int)ceil(log10(N)))

int is_prime(int n)
{
	int		i;

	if (primes.find(n) != primes.end())
		return 1;
	if (n == 1)
		return 0;
	if (n < 4)
		return 1;
	if (n % 2 == 0)
		return 0;
	if (n < 9)
		return 1;
	if (n % 3 == 0)
		return 0;
	for (i = 5; i * i <= n; i += 6)
	{
		if (n % i == 0)
			return 0;
		if (n % (i + 2) == 0)
			return 0;
	}
	primes[n] = true;
	return 1;
}

int arr2int(vector<int> arr)
{
	int	ret = 0;

	for (int i = 0; i < arr.size(); i++)
		ret = ret * 10 + arr[i];
	return ret;
}

bool exists(int n, vector<int> intarr, int pos1, int pos2, int pos3)
{
	vector<int>	copyarr = intarr;
	set<int>	unique;

	if (intarr[pos1] != intarr[pos2] || intarr[pos2] != intarr[pos3])
		return false;
	unique.insert(n);
	for (int digit = 0; digit <= 9; digit++)
	{
		if (pos1 == 0 && digit == 0)
			continue;
		if (pos3 == intarr.size() - 1 && (digit % 2 == 0 || digit == 5))
			continue;
		copyarr[pos1] = copyarr[pos2] = copyarr[pos3] = digit;
		int x = arr2int(copyarr);
		if (is_prime(x))
			unique.insert(x);
		if (unique.size() == 8)
			return true;
	}
	return false;
}

bool solve(int n, int ndigits)
{
	vector<int>	intarr(ndigits);
	int		cn = n;
	
	int		idx = ndigits - 1;
	while (cn != 0)
	{
		intarr[idx--] = cn % 10;
		cn /= 10;
	}
	for (int i = 0; i < ndigits; i++)
		for (int j = i + 1; j < ndigits; j++)
			for (int k = i + 1; k < ndigits; k++)
				if (exists(n, intarr, i, j, k))
					return true;
	return false;
}

int main()
{
	for (int i = 56003; ; i++)
	{
		if (is_prime(i) && solve(i, DIGITS(i)))
		{
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}
