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
			cout << "Rule 2 FAILs at " << i << endl;
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
				cout << "Rule 1 FAILs with i = " << i << " and j = " << j << endl;
				return 0;
			}
		}
	return 1;
}

int special_subset_sum(vector<int> &v)
{
	int	sum_of_v = 0;

	sort(v.begin(), v.end());
	if (!rule2(v) || !rule1(v))
		return 0;
	for (int i = 0; i < v.size(); i++)
		sum_of_v += v[i];
	return sum_of_v;
}

// Ans = 73702
int main()
{
	int			final_ans;
	string			line;
	vector< vector<int> >	all_integers;

	while (getline(cin, line))
	{
		istringstream is(line);
		all_integers.push_back(vector<int>(istream_iterator<int>(is),
					istream_iterator<int>()));
	}
	final_ans = 0;
	for (int i = 0; i < all_integers.size(); i++)
	{
		cout << "Set# " << i + 1 << " ---> ";
		int ans = special_subset_sum(all_integers[i]);
		if (ans != 0)
		{
			cout << "PASS --> " << ans << endl;
			final_ans += ans;
		} else
			cout << "FAIL" << endl;
	}
	cout << "Final ans = " << final_ans << endl;
	return 0;
}
