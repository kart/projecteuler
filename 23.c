#include <stdio.h>
#include <assert.h>
#include <math.h>

#define MAX 	30000
#define MMAX	28123

/* This may not be the best idea, but works reasonably well. The basic idea is to find all the abundant numbers 
 * and store it in array a[]. Add every pair of abundant numbers and mark it as 'done' in another array b. Since
 * we know every number greater than 28123 are definitely abundant summable, we can ignore such sums. Whatever
 * numbers are left out in b[] are our candiates. Add them up.
 * This leaves us with one question - how to find the sum of proper divisors of a given number N. You can either find
 * each divisor and add them up OR prime factorize the number and use SIGMA(n) -- see Wikipedia or Wolfram
 */

int sumdiv(int n)
{
	int	i, cnt = 0, p = 1, ans;
	
	ans = -n;
	for (i = 2; n > 1; i++)
	{
		cnt = 0;
		while (n && (n % i == 0))
		{
			n /= i;
			cnt++;
		}
		if (cnt)
			p *= ((pow(i, cnt + 1) - 1) / (i - 1));
	}
	return ans + p;
}
int main()
{
	int n, a[MAX], b[MAX], count, i, sum = 0, j;
	
	memset(a, 0, MAX * sizeof(int));
	memset(b, 0, MAX * sizeof(int));
	count = 0;
	for (i = 12; i < MAX; i++)
		if (sumdiv(i) > i)
			a[count++] = i;
	for (i = 0; i < count; i++)
	{
		for (j = 0; j < count; j++)
		{
			sum = a[i] + a[j];
			if (sum < MAX)
				b[sum] = 1;
		}
	}
	sum = 0;
	for (i = 0; i <= MAX; i++)
	{
		assert(i <= MMAX || b[i]);
		if (!b[i])
			sum += i;
	}
	printf("%d\n", sum);
}
