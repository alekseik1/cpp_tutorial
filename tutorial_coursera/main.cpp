#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct Pair {
	string word;
	vector<string> nrs;

	bool hasNeighbour(string& nr) {
		for(auto& k : nrs) {
			if(nr == k) {
				return true;
			}
		}
		return false;
	}
};

int main() {
	int Q; cin >> Q;
	vector<Pair> syn_pairs;
	for(int asd = 0; asd < Q; asd++) {
		string command; cin >> command;
		if(command == "ADD") {
			string w1, w2; cin >> w1 >> w2;
			bool fl = true;
			for(Pair& p : syn_pairs) {
				if(p.word == w1) {	// Уже добавляем к слову в словаре
					p.nrs.push_back(w2);
					fl = false;
					break;
				}
			}
			if(fl) {	// Впервые встречаем слово, значит, для него делаем запись
				Pair tmp = {w1, {w2}};
				syn_pairs.push_back(tmp);
			}
			fl = true;
		} else if(command == "COUNT") {
			string w; cin >> w;
			int k = 0;
			for(Pair p : syn_pairs) {
				if(p.word == w || p.hasNeighbour(w)) {
					k++;
				}
			}
			cout << k << endl;
		} else if(command == "CHECK") {
			string w1, w2; cin >> w1 >> w2;
			bool fl = false;
			for(Pair p : syn_pairs) {
				if((p.word == w1 && p.hasNeighbour(w2)) || (p.word == w2 && p.hasNeighbour(w1))) {
					fl = true;
					break;
				}
			}
			if(fl) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}
