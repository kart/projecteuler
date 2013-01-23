#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numdiv(int n)
{
	int	powers[1000], i, cnt = 0, pcnt = 0, ans;

	memset(powers, 0, sizeof(int)*1000);
	for (i = 2; n > 1; i++)
	{
		cnt = 0;
		while (n && (n % i == 0))
		{
			n /= i;
			cnt++;
		}
		if (cnt)
			powers[pcnt++] = cnt;
	}
	ans = 1;
	for (i = 0; i < pcnt; i++)
		ans *= (powers[i] + 1);
	return ans;
}

int main()
{
	int		i, ans = 0, nd;
	long long	n;
	
	for (i = 10; i < 20001; i++)
	{
		n = ((i * (i + 1)) / 2);
		nd = numdiv(n);
		if (nd > 500)
		{
			ans = i;
			break;
		}
	}
	if (ans)
		printf("%d = %d\n", ans, nd);
	else
		printf("Ooops");
	return 0;
}
