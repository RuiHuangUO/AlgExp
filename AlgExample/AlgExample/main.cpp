#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <iostream>
#include <string>
#include <sstream>
#include "StringTools.h"
#include "SortedContainer.h"
#include "MyBinaryTree.h"
#include "MyGraph.h"
#include <stack>
#include <set>
using namespace std;

vector<int> primeFactorization(int num) {
	vector<int> res;
	int start = 2;
	while (num > 1) {
		bool find = false;
		for (int i = start; i * i <= num; ++i) {
			if (num % i == 0) {
				start = i;
				res.push_back(i);
				num /= i;
				find = true;
				break;
			}
		}
		if (!find)
			break;
	}
	res.push_back(num);
	return res;
}

void main() {
	vector<int> ret = primeFactorization(3*3*3*3*3*3*3);
}