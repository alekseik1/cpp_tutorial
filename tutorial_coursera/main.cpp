#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool IsPalindrom(string s) {
	string s1 = s;
	std::reverse(s.begin(), s.end());
	if (s1 == s)
		return true;
	return false;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
	vector<string> res;
	for (auto c : words) {
		if (IsPalindrom(c) && c.size() >= minLength) {
			res.push_back(c);
		}
	}
	return res;
}
