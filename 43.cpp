#include <iostream>
#include <algorithm>
using namespace std;



int has_property(int num[10])
{
	int	i, val;
	int	prime[] = {0, 2, 3, 5, 7, 11, 13, 17};
	for (i = 1; i <= 7; i++)
	{
		val = num[i]*100 + num[i + 1]*10 + num[i + 2];
		if (0 != val % prime[i])
			return 0;
	}
	return 1;
}

int main ()
{
 	int 		num[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, i;
	long long	sum;

	sort (num, num + 9);
	do
	{
		if (has_property(num))
		{
			for (i = 0; i < 10; i++)
				cout << num[i];
			cout << endl;
		}
	} while (next_permutation(num, num + 10));
	return 0;
}
