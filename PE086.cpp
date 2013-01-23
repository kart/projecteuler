#include <iostream>
#include <cmath>
#include <set>
#include <utility>

using namespace std;

typedef long long int8;

#define LIMIT	1000000

int is_square(int8 N)
{
	return ceil(sqrt(1. * N)) == floor(sqrt(1. * N));
}

int how_many(int a, int b)
{
	int			z;

	z = a / 2;
	if (z > b)
		return 0;
	else if (a - 1 > b)
		return z - (a - 1 - b);
	return z;
}

int PE086()
{
	int			count = 0, M = 1, j = 1, k = 1, ch;
	
	while (count < LIMIT)
	{
		k = M;
		for (j = 1; j <= 2 * M; j++)
			if (is_square(j * j + k * k))
					count += how_many(j, k);
		M++;
	}
	cout << M - 1 << " " << count << endl;
	return 0;
}