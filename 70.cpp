#include <iostream>

#define MAX 12000
#define P1	1
#define Q1	3
#define P2	1
#define Q2	2

typedef long long		LL;

using namespace std;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int coprime(int n, int limit)
{	/* # of numbers less than or equal to 'limit' and coprime to n */
	if (limit == 0)
		return 0;
	int		ret = 1; /* 1 is always coprime to n */
	for (int i = 2; i <= limit; i++)
		if (gcd(n, i) == 1)
			ret++;
	return ret;
}

int main()
{
	int		ans = -1, limit, count1 = 0, count2 = 0;
	
	for (int i = MAX; i >= 2; i--)
	{
		count1 += coprime(i, i / Q2);
		count2 += coprime(i, i / Q1);
	}
	cout << "Number of numbers <= " << P1 << "/" << Q1 << " = " << count2 << endl;
	cout << "Number of numbers <= " << P2 << "/" << Q2 << " = " << count1 << endl;
	cout << "Answer = " << count1 - count2 - 1 << endl;
	return 0;
}

