#include "StringTools.h"
#include <map>


CStringTools::CStringTools()
{
}


CStringTools::~CStringTools()
{
}


vector<string> CStringTools::mySplit(const string & s, const string & delim) {
	vector<string> res;
	int last = 0;
	int first = s.find(delim, last);
	while (first != -1) {
		res.push_back(s.substr(last, first - last));
		last = first + delim.size();
		first = s.find(delim, last);
	}
	res.push_back(s.substr(last, s.size() - last));
	return res;
}

vector<string> CStringTools::mySplit(const string & s, char delim) {
	vector<string> res;
	int last = 0;
	int first = s.find_first_of(delim, last);
	while (first != -1) {
		res.push_back(s.substr(last, first - last));
		last = first + 1;
		first = s.find_first_of(delim, last);
	}
	res.push_back(s.substr(last, s.size() - last));
	return res;
}

size_t CStringTools::RobinKarp(const string & s, const string & x)
{
	if (x.empty() || s.size() < x.size())
		return -1;
	unsigned char pattern = 0;
	unsigned char cmppattern = 0;
	for (int i = 0; i < x.size(); ++i) {
		pattern ^= x[i];
		cmppattern ^= s[i];
	}
	cmppattern ^= s[x.size() - 1];
	for (int i = 0; i <= s.size() - x.size(); ++i) {
		cmppattern ^= s[i + x.size() - 1];
		if (pattern == cmppattern) {
			int match = true;
			for (int j = 0; j < x.size(); ++j)
				if (s[i + j] != x[j])
					match = false;
			if (match)
				return i;
		}
		cmppattern ^= s[i];
	}
	return -1;
}

size_t CStringTools::findPatternKMP(const string & s, const string & x)
{
	if (x.empty() || s.size() < x.size())
		return -1;
	// get prefix
	vector<int> jump(x.size(), 0);
	int i = 1, j = 0;
	while (i < x.size()) {
		if (x[i] == x[j]) {
			jump[i] = j + 1;
			++j;
			++i;
		}
		else {
			if (j == 0)
				++i;
			else
				j = jump[j - 1];
		}
	}
	// match
	j = 0;
	i = 0;
	while (i < s.size()) {
		if (s[i] == x[j]) {
			++j;
			++i;
			if (j == x.size())
				return i - j;
		}
		else {
			if (j != 0) 
				j = jump[j - 1];
			else 
				++i;
		}
	}
	return -1;
}
