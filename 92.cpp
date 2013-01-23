#include <iostream>

using namespace std;

#define MAX	800
#define REQMAX	10000000
int memo[MAX];

int square[] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};

int recurse(int n)
{
	int	sum = 0, ans = 0;
	
	if (n == 1 || n == 89)
		return n;
	if (n < MAX && memo[n])
		return memo[n];
	while (n != 0)
	{
		sum += square[n % 10];
		n /= 10;
	}
	ans = recurse(sum);
	if (ans < MAX)
		memo[n] = ans;
	return ans;
}	

int main()
{
	int		n, count =  0;

	for (int i = 1; i < REQMAX; i++)
		if (89 == recurse(i))
			count++;
	cout << count << endl;
	return 0;
}
