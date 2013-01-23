#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdlib>

#undef min
using namespace	std;

#define min(A, B)	(A) < (B) ? (A) : (B)
#define ORIG		0x0
#define FROM_UP		0x1
#define FROM_DOWN	0x2
#define FROM_RIGHT	0x3
#define INF		1 << 30
#define MAX		80

int arr[MAX + 1] [MAX + 1];
int dp[MAX + 1] [MAX + 1];
int temp[MAX + 1];

int main()
{
	int		ans = INF;

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
		{
			cin >> arr[i][j];
			dp[i][j] = arr[i][j];
		}
	for (int col = 1; col < MAX; col++)
	{
		for (int row = 0; row < MAX; row++)
			dp[row][col] += dp[row][col - 1];
		for (int row = 0; row < MAX; row++)
		{
			int t = INF, sum;
			for (int r = 0; r < row; r++)
			{
				sum = dp[r][col];
				for (int s = r + 1; s < row; s++)
					sum += arr[s][col];
				t = min(t, sum);
			}
			for (int r = MAX - 1; r > row; r--)
			{
				sum = dp[r][col];
				for (int s = r - 1; s > row; s--)
					sum += arr[s][col];
				t = min(t, sum);
			}
			temp[row] = min(dp[row][col], t + arr[row][col]);
		}
		for (int row = 0; row < MAX; row++)
			dp[row][col] = temp[row];
	}
	for (int row = 0; row < MAX; row++)
		ans = min(ans, dp[row][MAX - 1]);
	cout << ans << endl;
	return 0;
	
}
