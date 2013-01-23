#include <iostream>
#include <vector>
#include <algorithm>

#define MAX		1000000
typedef long long		LL;

using namespace std;

int phi[MAX + 1];
int hi[MAX + 1];
int low[MAX + 1];

int main()
{
	LL ans = 0;
	
	for (int i = 2; i <= MAX; i++)
	{
		if (!low[i])
		{
			int j = 1;
			while (1)
			{
				if (LL(j) * LL(i) > LL(MAX + 1))
					break;
				j *= i;
				for (int k = j; k <= MAX; k += j)
				{
					hi[k] = j;
					low[k] = i;
				}
			}
		}
	}
	phi[1] = 1;
	for (int i = 2; i <= MAX; i++)
	{
		phi[i] = phi[i / hi[i]] * ((hi[i] / low[i]) * (low[i] - 1));
		ans += phi[i];
	}
	cout << ans << endl;
	return 0;
}
