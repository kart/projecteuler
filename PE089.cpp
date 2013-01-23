#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <fstream>

using namespace std;

string one_digit_roman[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

map<string, int> mapping;

int get_mapping(char ch)
{
	switch(ch)
	{
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case 'C':
		return 100;
	case 'D':
		return 500;
	case 'M':
		return 1000;
	}
	return -1;
}

int roman2dec(string roman)
{
	int			dec = 0;

	for (int idx = 0; idx < roman.length(); idx++)
	{
		char ch = roman[idx];
		int val = get_mapping(ch);
		bool next_avail = idx + 1 < roman.length();
		int nextval = next_avail ? get_mapping(roman[idx + 1]) : 0;
		switch (ch)
		{
		case 'I':
			if (next_avail && (roman[idx + 1] == 'V' || roman[idx + 1] == 'X'))
			{
				dec += (nextval - val);
				idx++;
				break;
			}
		case 'X':
			if (next_avail && (roman[idx + 1] == 'L' || roman[idx + 1] == 'C'))
			{
				dec += (nextval - val);
				idx++;
				break;
			}
		case 'C':
			if (next_avail && (roman[idx + 1] == 'D' || roman[idx + 1] == 'M'))
			{
				dec += (nextval - val);
				idx++;
				break;
			}
		default:
			dec += val;
		}
	}
	return dec;
}

string dec2roman(int N)
{
	if (N >= 1000)
		return "M" + dec2roman(N - 1000);
	else if (N >= 900)
		return "CM" + dec2roman(N - 900);
	else if (N >= 500)
		return "D" + dec2roman(N - 500);
	else if (N >= 400)
		return "CD" + dec2roman(N - 400);
	else if (N >= 100)
		return "C" + dec2roman(N - 100);
	else if (N >= 90)
		return "XC" + dec2roman(N - 90);
	else if (N >= 50)
		return "L" + dec2roman(N - 50);
	else if (N >= 40)
		return "XL" + dec2roman(N - 40);
	else if (N >= 10)
		return "X" + dec2roman(N - 10);
	else
		return one_digit_roman[N];
	assert(false);
	return "";
}

int PE089()
{
	int			ans = 0;
	ifstream	fs;

	fs.open("C:\\Users\\Karthik\\roman.txt", ifstream::in);

	while (fs.good())
	{
		string	s, reduced_roman = "";
		getline(fs, s);
		int N = roman2dec(s);
		reduced_roman = dec2roman(N);
		assert(s.length() >= reduced_roman.length());
		ans += s.length() - reduced_roman.length();
	}
	cout << ans << endl;
	fs.close();
	return 0;
}