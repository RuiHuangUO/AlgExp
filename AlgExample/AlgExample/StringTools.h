#pragma once
#include <string>
#include <vector>
using namespace std;
class CStringTools
{
public:
	CStringTools();
	~CStringTools();
	vector<string> mySplit(const string & s, const string & delim);
	vector<string> mySplit(const string & s, char delim);
	static size_t RobinKarp(const string & s, const string & x);
	static size_t findPatternKMP(const string & s, const string & x);
};

