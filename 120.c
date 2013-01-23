#include <stdio.h>

#define MAX	1000	/* From the problem statement */

/* Neat problem - just expand the numerator - (a - 1)^n + (a + 1)^n. The pattern that will emerge is 
 * (a) If 'n' is even, the expansion will have ((c1)a^n + (c2)a^(n-2) + (c3)a^(n-4) + ... a^2 + 2).
 *	where c1, c2, c3.. cn are all the coefficents of the binomial expansion. But, since this is
 *	divided by a^2, all the terms with the even powers will leave a remainder 0 and we will be left
 *	out with just '2'. So, for even n (n >= 2), the maximum reminder is just 2.
 * (b) If 'n' is odd, the expansion will have ((c1)a^n + (c2)a^(n-2) + (c3)a^(n-4) + ... 2na). Since this
 * 	is divided by a^2, all the terms with odd powers except 2na will leave a remainder 0 and we will
 *	be left with just '2na'. So, for odd n (n >= 1), the maximum reminder is '[2na / a^2]' where [] is
 *	the floor function.
 */

int main()
{
	int	a, n, r_max;
	long	sigma_r_max = 0;

	for (a = 3; a <= MAX; a++)
	{
		r_max = (2 * a) * (((a * a) - 1) / (2 * a));
		r_max = r_max > 2 ? r_max : 2;
		sigma_r_max += r_max;
		
	}
	printf("%ld\n", sigma_r_max);
	return 0;
}
