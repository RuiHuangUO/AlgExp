#pragma once
#include <list>
#include <string>
#include <map>
#include <vector>
using namespace std;

class MyGraph
{
public:
	MyGraph();
	~MyGraph();

	static list<string> getTopoOrder(vector<pair<string, string>> & dep);
};

