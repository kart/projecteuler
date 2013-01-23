#include <stdio.h>

#define MAX	1000000
#define P	3LL
#define Q	7LL
#define LL	long long

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main()
{
	LL		best_p = 0, best_q = MAX, d;

	for (d = MAX; d >= 2; d--)
	{
		LL p = (P * d) / Q;
		LL q = d;
		int cd = gcd(p, d);
		p = p / cd;
		q = d / cd;
		if (p * best_q > q * best_p && p != P && q != Q)
		{
			best_p = p;
			best_q = q;
		}
	}
	printf("Fraction before %lld/%lld is %lld/%lld\n", P, Q, best_p, best_q);
	return 0;
}
