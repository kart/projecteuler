#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* This is probably the most crappiest seive ever.. I don't even know how this works.. need to write a 
 * seive with proper loop invariants and such
 */

int	seive(int n, int ith)
{
	int		*s, start, c, cnt = 1;

	s = malloc(sizeof(int) * (n + 1));
	memset(s, 0, sizeof(int) * (n + 1));
	if (s)
	{
		start = 2;
		while (cnt <= ith)
		{
			while ((start <= n) && s[start])
				start++;
			if (start > n)
				break;
			c = 0;
			while (1)
			{
				c += start;
				if (c > n)
					break;
				s[c] = 1;
			}
			cnt++;
		}
		printf("%d\n", start);
	} else
	{
		printf("Out of memory...\n");
		return -1;
	}
	return 0;
}

int main()
{
	int	n, ith;

	scanf("%d %d", &n, &ith);
	seive(n, ith); /* prints the ith prime; assumes n is sufficiently large to accomodate ith prime */
	return 0;
}
