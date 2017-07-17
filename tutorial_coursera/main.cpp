#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int N;
	cin >> N;
	string s1, s2;
	map<char, int> m1, m2;
	for(int i = 0; i < N; i++) {
		cin >> s1 >> s2;
		for(char s : s1) {
			m1[s]++;
		}
		for(char s : s2) {
			m2[s]++;
		}
		if(m1 == m2) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		m1.clear();
		m2.clear();
	}
	return 0;
}

