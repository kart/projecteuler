#include <iostream>

using namespace std;

#define SUNDAY		0x0
#define TUESDAY		0x2

#define LEAP(YEAR)				(YEAR % 100 == 0 ? YEAR % 400 == 0 : YEAR % 4 == 0)
#define DAYS(MONTH, YEAR)			MONTH == 2 ? (LEAP(YEAR) ? 29 : 28) : days[MONTH]
#define FIRST_OF_NEXT_MONTH(N_DAYS, TODAY)	(N_DAYS == 28 ? TODAY : (TODAY + (N_DAYS % 29) + 1) % 7)

int	days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
	int		today = TUESDAY, count = 0, days_in_month;

	for (int year = 1901; year < 2001; year++)
	{
		for (int month = 1; month <= 12; month++)
		{
			days_in_month = DAYS(month, year);
			today = FIRST_OF_NEXT_MONTH(days_in_month, today);
			count += (today == SUNDAY);
		}
	}
	cout << count << endl;
}
