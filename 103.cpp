#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <fstream>
#include <iterator>
#include <sstream>
#include <set>
#include <algorithm>

#define	MAX	12
using namespace std;

int rule2(vector<int> &numbers)
{
	int		n = numbers.size();
	int		sum1 = numbers[0], sum2 = 0;

	for (int i = 1; i <= n / 2; i++)
	{
		sum1 += numbers[i];
		sum2 += numbers[n - i];
		if (sum1 <= sum2)
		{
			// cout << "Rule 2 FAILs at " << i << endl;
			return 0;
		}
	}
	return 1;
}

int sum_ones(vector<int> &v, int n)
{
	int	sum = 0;
	int	sz = v.size();

	for (int j = sz - 1; j >= 0; j--)
	{
		sum += (n % 2 == 1) ? v[j] : 0;
		n = n >> 1;
	}
	return sum;
}
int rule1(vector<int> &v)
{
	int		n = v.size();
	vector<int>	subset_sums((1 << n) + 1);

	for (int i = 1; i < (1 << n); i++)
		subset_sums[i] = sum_ones(v, i);
	for (int i = 1; i < (1 << n); i++)
		for (int j = 1; j < (1 << n); j++)
		{
			if (i & j) continue;
			if (subset_sums[i] == subset_sums[j])
			{
				// cout << "Rule 1 FAILs with i = " << i << " and j = " << j << endl;
				return 0;
			}
		}
	return 1;
}

int special_subset_sum(vector<int> &old_v)
{
	int		sum_of_v = 0;
	vector<int> 	v;

	v.reserve(old_v.size());
	copy(old_v.begin(), old_v.end(), back_inserter(v));
	sort(v.begin(), v.end());
	if (!rule2(v) || !rule1(v))
		return 0;
	for (int i = 0; i < v.size(); i++)
		sum_of_v += v[i];
	return sum_of_v;
}

int sum(vector<int> &v)
{
	int ssum = 0;

	for (int i = 0; i < v.size(); i++)
		ssum += v[i];
	return ssum;
}

void recurse(vector<int> &v, int depth, int limit, int init_sum)
{
	if (depth >= limit)
	{
		if (sum(v) < init_sum && special_subset_sum(v))
		{
			for (int i = 0; i < v.size(); i++)
				cout << v[i] << " ";
			cout << "==> " << sum(v) << endl;
		}
		return;
	}
	for (int i = -4; i <= 4; i++)
	{
		if (depth != 0 && (v[depth] + i < v[depth - 1]))
			continue;
		v[depth] += i;
		recurse(v, depth + 1, limit, init_sum);
		v[depth] -= i;
	}
}

// Turns out for this one, the solution is infact the input vector. The below solution doesn't prove it. But, couldn't find
// a match in -4 to +4 range.
int main()
{
	int			final_ans;
	string			line;
	vector< vector<int> >	all_integers;
	vector<int>		v;
	int			source[] = {20, 31, 38, 39, 40, 42, 45};

	for (int i = 0; i < sizeof(source)/sizeof(source[0]); i++)
		v.push_back(source[i]);
	cout << "Init sum = " << sum(v) << endl;
	recurse(v, 0, v.size(), sum(v));
	return 0;
}
