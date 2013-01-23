#include <iostream>
#include <set>
#include <cassert>

using namespace std;

#define MAX	4000000
#define REQMAX	1000000
int memo[MAX];

set<int> path;

int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int recurse(int n)
{
	int	sum = 0, ans = 0;
	
	assert(n < MAX);
	if (path.find(n) != path.end())
		return 0;
	path.insert(n);
	if (memo[n])
		return memo[n];
	while (n != 0)
	{
		sum += fact[n % 10];
		n /= 10;
	}
	memo[n] = 1 + recurse(sum);
	path.erase(n);
	return memo[n];
}	

int main()
{
	int		n, count =  0;

	for (int i = 1; i < MAX / 4; i++)
	{
		path.clear();
		int cycle = recurse(i);
		if (cycle == 60)
			count++;
	}
	cout << count << endl;
	return 0;
}
