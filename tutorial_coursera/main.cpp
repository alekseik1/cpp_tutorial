#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <locale>

using namespace std;

int main() {
	int N; cin >> N;
	vector<string> v;
	for(int i = 0; i < N; i++) {
		string tmp; cin >> tmp;
		v.push_back(tmp);
	}
	sort(begin(v), end(v), [](string a, string b) {
		for(char& c : a) {
			c = tolower(c);
		}
		for(char& c : b) {
			c = tolower(c);
		}
		return a < b;
	});
	for(auto& k : v) {
		cout << k << " ";
	}
	return 0;
}
