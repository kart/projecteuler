#include <stdio.h>
#include <assert.h>

#define NUM_DIGITS(N)	(N < 100 ? 2 : 3)

int units[] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4};
int teens[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
int tens[] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};


int recurse(int n)
{
	int	nd, u, t, h, r;

	if (n < 10)
		return units[n];
	if (n >= 10 && n <= 19)
		return teens[n];
	nd = NUM_DIGITS(n);
	if (nd == 2)
	{
		u = n % 10;
		t = (n / 10) * 10;
		if (u == 0)
			return tens[t / 10];
		else
			return tens[t / 10] + units[u];
	}
	assert(nd == 3);
	h = n / 100;
	r = n % 100;
	if (r == 0)
		return units[h] + (sizeof("hundred") - 1);
	return units[h] + (sizeof("hundred") - 1) + (sizeof("and") - 1) + recurse(r);
}

int main()
{
	int		i, sum;

	sum = 0;
	for (i = 1; i < 1000; i++)
		sum += recurse(i);
	sum = sum + (sizeof("onethousand") - 1);
	printf("%d\n", sum);
}
