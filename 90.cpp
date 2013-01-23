#include <iostream>
#include <cassert>

using namespace std;

int powers[] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};

int bit_count(int N)
{
	int		count = 0;

	while (N != 0)
	{
		count += (N % 2 == 1);
		N /= 2;
	}
	return count;
}

int can_form(int N, int A[], int B[])
{
	int		units, tens;

	units = N % 10;
	tens = N / 10;
	if ((9 == units) || (6 == units)) units = -1;
	if ((9 == tens) || (6 == tens)) tens = -1;
	assert(!((units == -1) && (tens == -1)));
	if ((units != -1) && (tens != -1))
		return (A[tens] && B[units]) || (B[tens] && A[units]);
	else if (units == -1)
		return (A[tens] && (B[9] || B[6])) || (B[tens] && (A[9] || A[6]));
	else	// tens == -1
		return ((A[9] || A[6]) && B[units]) || ((B[9] || B[6]) && A[units]);
		
}

int ok(int A, int B)
{
	int	a[10], b[10];

	for (int i = 0; i < 10; i++)
	{
		a[i] = (1 << i) & A;
		b[i] = (1 << i) & B;
	}
	for (int i = 1; i <= 9; i++)
		if (!can_form(powers[i], a, b))
			return 0;
	return 1;
}

// Ans = 1217
int main()
{
	int		i, j, count = 0;

	for (i = 1; i <= 1024; i++)
	{
		if (6 != bit_count(i))
			continue;
		for (j = 1; j <= 1024; j++)
		{
			if (6 != bit_count(j))
				continue;
			if (ok(i, j))
				count++;
		}
	}
	cout << count / 2 << endl;
}
