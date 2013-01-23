#include <stdio.h>

#define MAX	50
#define NUM 	100
#define SIZE	1000000

char a[MAX], c[SIZE];
int start;

void add()
{
	int	cend, carry, i, t, save;

	cend = SIZE - 1;
	carry = 0;
	for (i = MAX - 1; i >= 0; i--, cend--)
	{
		t = (a[i] - '0') + (c[cend] - '0') + carry;
		c[cend] = (t % 10) + '0';
		carry = t / 10;
	}
	while (carry)
	{
		
		t = carry + (c[cend] - '0');
		c[cend] = (t % 10) + '0';
		carry = t / 10;
		cend--;
	}
	while ('0' != c[cend] || cend > start)
		cend--;
	start = cend + 1;
}

int main()
{
	int 		i;
	
	memset(&c[0], (int)('0'), SIZE);
	start = SIZE - MAX;
	for (i = 0; i < NUM; i++)
	{
		scanf("%s", a);
		add();
		printf("%d = %s\n", i + 1, &c[start]);
	}
	return 0;
}
