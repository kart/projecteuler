#include <stdio.h>
#include <math.h>

int numdiv(int n)
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
	int	i, x, a[10001], sum = 0;
	
	memset(a, 0, 10000 * sizeof(int));
	for (i = 2; i < 10000; i++)
	{
		if (!a[i])
		{
			x = numdiv(i);
			if (i == numdiv(x) && (i != x))
			{
				printf("%d %d ",i, x);
				sum += (x + i);
				a[i] = a[x] = 1;
			}
		}
	}
	printf("\n%d\n", sum);
}
