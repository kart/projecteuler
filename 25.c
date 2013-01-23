#include <stdio.h>
#include <math.h>

#define SQRT_5		sqrt(5)
#define SI		((1 + SQRT_5) / 2.)
#define LOG_SI		log10(SI)
#define LOG_5		log10(5)

int main()
{
	int		i;

	for (i = 1; ; i++)
		if ((ceil(i * LOG_SI - 0.5 * LOG_5)) >= 1000)
			break;
	printf("%d\n", i);
	return 0;
}
