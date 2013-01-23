#include <iostream>
#include <algorithm>
#include <hash_set>
#include <set>
#include <cassert>

using namespace std;

#define MAX		1000000

int		sumdivs[MAX + 1];
int		memo_cycle[MAX + 1];
int		minx = MAX * 2;

hash_set<int> path;

int sumdiv(int N)
{
	int		sum = 1;
	if (N == 1 || N == 0)
		return 0;
	for (int i = 2; i * i <= N; i++)
		if (N % i == 0)
			sum += N / i == i ? i : i + N / i;
	return sum;
}

int chain(int N, int start, bool init)
{
	if (N > MAX || N == 0)
		return -1;
	if (N == start && !init)
		return 0;
	init = false;
	if (path.find(N) != path.end() || memo_cycle[N] != -1)
		return -1;
	minx = min(minx, N);
	path.insert(N);
	int x = chain(sumdivs[N], start, init);
	if (x == -1)
		return -1;
	return memo_cycle[N] = 1 + x;
}

int PE095()
{
	int				overall_min = MAX * 2, max_cycle = -1;
	
	for (int i = 0; i <= MAX; i++)
	{
		sumdivs[i] = sumdiv(i);
		memo_cycle[i] = -1;
	}
	for (int i = 1; i <= MAX; i++)
	{
		int			cycle, ch;

		path.clear();
		minx = MAX * 2;
		if (-1 == (cycle = chain(i, i, true)))
			continue;
		if (cycle > max_cycle)
		{
			max_cycle = cycle;
			overall_min = minx;
		} else if (cycle == max_cycle)
			overall_min = min(overall_min, minx);
	}
	cout << "Max cycle = " << max_cycle << "; Min element = " << overall_min << endl;
	return 0;
}