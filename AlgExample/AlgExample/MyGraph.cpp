#include "MyGraph.h"
#include <set>
#include <vector>



MyGraph::MyGraph()
{
}


MyGraph::~MyGraph()
{
}

list<string> MyGraph::getTopoOrder(vector<pair<string, string>> & dep)
{
	map<string, int> depcnt;
	map<string, list<string>> follow;
	set<string> noindeg;
	auto pd = dep.begin();
	while (pd != dep.end()) {
		auto prec = depcnt.find(pd->second);
		if (prec == depcnt.end()) {
			depcnt[pd->second] = 1;
		}
		else {
			prec->second++;
		}
		noindeg.erase(pd->second);
		if (depcnt.find(pd->first) == depcnt.end()) {
			noindeg.insert(pd->first);
		}
		follow[pd->first].push_back(pd->second);
		++pd;
	}
	list<std::string> res;
	while (!noindeg.empty()) {
		string prer = *noindeg.begin();
		res.push_back(prer);
		noindeg.erase(noindeg.begin());
		auto pf = follow.find(prer);
		if (pf != follow.end()) {
			auto pff = pf->second.begin();
			while (pff != pf->second.end()) {
				depcnt[*pff]--;
				if (depcnt[*pff] == 0) {
					noindeg.insert(*pff);
					depcnt.erase(*pff);
				}
				++pff;
			}
		}
	}
	return res;
}
