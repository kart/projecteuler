#include <stdio.h>

#define MAX	1000000
#define P1	1LL
#define Q1	3LL
#define P2	1LL
#define Q2	2LL
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
		if ((p == P1 && q == Q1) || (p == P2 && q == Q2))
			continue;
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
