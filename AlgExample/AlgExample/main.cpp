#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <iostream>
#include <string>
#include <sstream>
#include "StringTools.h"
using namespace std;

void main() {
	string s("abcabyabxabcabcaby");
	string x("abcaby");
	size_t ret = CStringTools::RobinKarp(s, x);
}