#include <stdio.h>

#define MAX	10000000000

int main()
{
	long long		p = 1, i;

	for (i = 1; i <= 7830457; i++)
		p = ((p % MAX) * 2) % MAX;
	p = (28433 * p + 1) % MAX;
	printf("%lld\n", p);
	return 0;
}	
