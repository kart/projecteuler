#include <iostream>

using namespace std;

#define int8	long long
#define N		15
#define FACT	20922789888000LL		// (N + 1)!

int8 prob(int n)
{
	int		pos = N, blues = 0, count = 0;
	int8	ans = 1;

	while (n != 0)
	{
		if (0 == n % 2)
			ans *= pos;
		else
			blues++;
		n = n >> 1;
		pos--;
		count++;
	}
	while (count++ < N)
		ans *= pos--;
	return blues > N / 2 ? ans : 0LL;
}

int PE121()
{
	int8			tot_prob = 0;

	for (int i = 1; i < (1 << N); i++)
		tot_prob += prob(i);	
	
	cout << "Funding required = " << FACT / tot_prob << endl;
	return 0;
}