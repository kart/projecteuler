#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* seive(int n, int print)
{
	int	*seivearr, i, j;

	seivearr = malloc(n * sizeof(int));
	memset(seivearr, 0, sizeof(int) * n);
	seivearr[1] = -1;
	for (i = 2; i * i <= n; i++)
	{
		if (seivearr[i])
			continue;
		for (j = 2 * i; j < n; j += i)
			seivearr[j] = 1;
		seivearr[i] = 0;
	}
	if (print)
	{
		for (i = 2; i < n; i++)
			if (!seivearr[i])
				printf("%d\n", i);
	}
	return seivearr;
}

int is_circular_prime(int n, int *seivearr)
{
	int		i, j, nd, cnt;
	char		str[16], t;

	sprintf(str, "%d", n);
	nd = strlen(str);
	cnt = 1;
	for (i = 0; i < nd - 1; i++)
	{
		t = str[0];
		for (j = 0; j < nd - 1; j++)
			str[j] = str[j + 1];
		str[j] = t;
		n = atoi(str);
		if (!seivearr[n])
			cnt++;
	}
	if (cnt == nd)
		return 1;
	return 0;

}

int main()
{
	int	n, *seivearr, i, count = 0;

	scanf("%d", &n);
	seivearr = seive(n, 0);
	for (i = 2; i < n; i++)
		if (!seivearr[i] && is_circular_prime(i, seivearr))
			count++;
	printf("%d\n", count);
	return 0;
}
