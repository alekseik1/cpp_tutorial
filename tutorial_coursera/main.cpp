#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main() {
	int Q; cin >> Q;
	map<string, set<string>> syn_pairs;
	for(int asd = 0; asd < Q; asd++) {
		string command; cin >> command;
		if(command == "ADD") {
			string w1, w2; cin >> w1 >> w2;
			syn_pairs[w1].insert(w2);
			syn_pairs[w2].insert(w1);
		} else if(command == "COUNT") {
			string w; cin >> w;
			cout << syn_pairs[w].size() << endl;
		} else if(command == "CHECK") {
			string w1, w2; cin >> w1 >> w2;
			if(syn_pairs[w1].count(w2) > 0) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}
