#include <iostream>
#include <vector>

using namespace std;

#define SEIVE_MAX	100000
#define DEN			94744LL
#define NUM			15499LL			

bool composite[SEIVE_MAX + 1];
vector<int> primes;

void seive()
{
	int				i;

	for (i = 2; i * i <= SEIVE_MAX; i++)
	{
		if (composite[i]) continue;
		for (int j = i + i; j <= SEIVE_MAX; j += i)
			composite[j] = true;
		primes.push_back(i);
	}
	for (; i <= SEIVE_MAX; i++)
		if (!composite[i])
			primes.push_back(i);
}

/* We know : phi(N) = N * [(Pa - 1)/Pa * (Pb - 1)/Pb * ... * (Pk - 1)]; We want to find an N such that phi(N) / (N - 1) < (15499 / 94744)
 * If we rearrange the equation, we get something like this :
 * {[(Pa - 1) * (Pb - 1) * ... (Pk - 1)] / (N - 1)} * [N / (Pa * Pb * ... Pk)] < (15499 / 94744)
 *		--> Here, Pa, Pb, ... Pk are the distinct prime factors of N.
 * One way, to find a coarse upper bound is to start multiplying the first few primes until the LHS of the above expression
 * becomes < than 15499 / 94744. Such an N turned out to be 6469693230 whose prime factorization 
 * is 2 * 3 * 5 * 7 * 11 * 13 * 17 * 19 * 23 * 27.
 * Also, the lower bound turned out to be 223092870 whose prime factorization is : 2 * 3 * 5 * 7 * 11 * 13 * 17 * 19
 * One way to start searching for smaller values greater than the lower bound is to assume that N has the prime factor 2 
 * raised to some k. In other words, N = 2^k * 3 * 5 * ... . Of course, if we get unlucky, we have to then start with 3^k
 * and so on. But, when I plugged in N = 2^3 * 3 * 5 * ... * 23, N was less than the upper bound and still satisfied the
 * equation.
 */

int PE243()
{
	long long		N = 4, num = 1;

	seive();
	cout << "2 * 2 * ";
	for (int i = 0; i < primes.size(); i++)
	{
		long long p = (long long) primes[i];
		N *= p;
		num *= (p - 1);
		cout << p;
		if (num * DEN * 4 < (N - 1) * NUM)
			break;
		cout << " * ";
	}
	cout << " = " << N << endl;
	return 0;
}