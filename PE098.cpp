#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cassert>
#include <hash_set>

using namespace std;

map<string, vector<string> > anagrams;
map<long long, vector<long long> > int_anagrams;
hash_set<string> squares;
hash_set<char> used;

#define MAX			999999999

string convert2string(long long N)
{
	stringstream ss;
	ss << N;
	return ss.str();
}

string string_signature(string word)
{
	vector<char>	v;
	string			s = "";

	for (int i = 0; i < word.length(); i++)
		v.push_back(word[i]);
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		s += v[i];
	return s;
}

bool replace_all(string &s1, string &s2, char c1, char c2)
{
	assert(s1.length() == s2.length());
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] == c1)
			s1[i] = c2;
		if (s2[i] == c1)
			s2[i] = c2;
	}
	return true;
}

string		square_anagram(string s1, string s2)
{
	int			len = s1.length(), i;
	string		ret;

	for (i = 0; i < len; i++)
		if ((s1[i] >= 'A' && s1[i] <= 'Z'))
			break;
	if (i == len)
	{
		if (squares.find(s1) != squares.end() && squares.find(s2) != squares.end())
		{
			if (s1 > s2)
				return s1;
			return s2;
		}
		return "";
	}
	for (char c = '9'; c >= (i == 0 ? '1' : '0'); c--)
	{
		char save = s1[i];
		if (used.find(c) != used.end())
			continue;
		replace_all(s1, s2, s1[i], c);
		used.insert(c);
		if ((ret = square_anagram(s1, s2)) != "")
			return ret;
		used.erase(c);
		replace_all(s1, s2, c, save);
	}
	return "";
}

int PE098()
{
	ifstream	fs;
	string		line;
	int			count = 0;

	fs.open("C:\\Users\\Karthik\\words2.txt", ifstream::in);
	getline(fs, line);
	istringstream ss(line);

	while (ss)
	{
		string		word, sig;
		if (!getline(ss, word, ','))
			break;
		sig = string_signature(word);
		if (anagrams.find(sig) != anagrams.end())
			anagrams[sig].push_back(word);
		else
		{
			vector<string> v(1, word);
			anagrams[sig] = v;
		}
	}
	for (long long i = 1; i * i <= MAX; i++)
		squares.insert(convert2string(i * i));
	for (map<string, vector<string> >::iterator it = anagrams.begin(); it != anagrams.end(); it++)
	{
		vector<string>		v = (*it).second;
		string				ret;

		if (v.size() == 2 && v[0].length() >= 4)
		{
			used.clear();
			if ("" != (ret = square_anagram(v[0], v[1])))
				cout << v[0] << "; " << v[1] << " == > " << ret << endl;
		}
	}
	fs.close();
	return 0;
}