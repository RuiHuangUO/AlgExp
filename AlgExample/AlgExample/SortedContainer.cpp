#include "SortedContainer.h"
#include <vector>
#include <map>
#include <set>
#include <assert.h>
using namespace std;



SortedContainer::SortedContainer()
{
	map<int, int> m;
	vector<pair<int,int>> v;
	v.emplace_back(3, 57);
	v.emplace_back(5, 46);
	v.emplace_back(7, 49);
	v.emplace_back(11, 18);
	m.insert(v.begin(), v.end());

	set<int> s;
	vector<int> vi;
	vi.emplace_back(3);
	vi.emplace_back(5);
	vi.emplace_back(7);
	vi.emplace_back(11);
	// vi: (2);(1);(1);(3)
	s.insert(vi.begin(), vi.end());
	// m: (1);(2);(3)

	multiset<int> ms;
	vector<int> vm;
	vm.emplace_back(3);
	vm.emplace_back(5);
	vm.emplace_back(7);
	vm.emplace_back(11);
	// vm: (2);(1);(1);(3)
	ms.insert(vi.begin(), vi.end());
	ms.insert(5);
	// ms: (1);(1);(2);(3)
	auto pp = next(ms.begin());
	auto pm = ms.lower_bound(5);
	assert(pp == pm);
	pm = next(pm);
	pm = next(pm);
	pm = ms.upper_bound(5);
	pm = ms.begin();
	pm = ms.lower_bound(6);
	pm = ms.begin();
	pm = ms.upper_bound(6);
}


SortedContainer::~SortedContainer()
{
}
