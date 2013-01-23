#include <stdio.h>
#include <math.h>
#define MAX 7

int nine_max[] = {9, 99, 999, 9999, 99999, 999999, 9999999};
int ten_max[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000};
int digits[] = {9, 189, 2889, 38889, 488889, 5888889, 68888889};

int main()
{
	int	i, n, nd, x, y, str[10], r, offset, beg_idx;

	scanf("%d", &n);
	for (i = 0; i < MAX - 1; i++)
		if (digits[i] <= n && n <= digits[i + 1])
			break;
	x = n - digits[i];
	nd = i + 1 + 1;
	y = (int)(ceil((x * 1.0) / nd)) + ten_max[i] - 1;
	beg_idx = 1 + (digits[i] + (y - ten_max[i]) * nd);
	offset = n - beg_idx + 1;
	while (y)
	{
		str[nd--] = y % 10;
		y = y / 10;
	}
	return 0;
}
