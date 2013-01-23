#include <iostream>
#include <cmath>

using namespace std;

double manhattan(int p, int q, int r, int s)
{
	return sqrt(1. * (p - r) * (p - r) + (q - s) * (q - s));
}

int manhattan2(int p, int q, int r, int s)
{
	return (p - r) * (p - r) + (q - s) * (q - s);
}

bool right_triangle(int p1, int q1, int p2, int q2)
{
	if (p1 == 0 && q1 == 0 || p2 == 0 && q2 == 0)
		return false;
	if (p1 == p2 && q1 == q2)
		return false;
	double A = manhattan(p1, q1, 0, 0);
	double B = manhattan(p2, q2, 0, 0);
	double C = manhattan(p1, q1, p2, q2);
	if (A + B < C || A + C < B || B + C < A)
		return false;
	int A2 = manhattan2(p1, q1, 0, 0);
	int B2 = manhattan2(p2, q2, 0, 0);
	int C2 = manhattan2(p1, q1, p2, q2);
	if (A2 + B2 == C2 || A2 + C2 == B2 || B2 + C2 == A2)
		return true;
	return false;
}

int PE091()
{
	int			count = 0;

	for (int p1 = 0; p1 <= 50; p1++)
		for (int p2 = 0; p2 <= 50; p2++)
			for (int q1 = 0; q1 <= 50; q1++)
				for (int q2 = 0; q2 <= 50; q2++)
					if (right_triangle(p1, q1, p2, q2))
						count++;
	cout << count / 2 << endl;
	return 0;
}