#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int has(const vector<set<string>>& v, const set<string>& el) {
	for(unsigned i = 0; i < v.size(); i++) {
		if(v[i] == el) {
			return i;
		}
	}
	return -1;
}

int main() {
	int Q;
	cin >> Q;
	vector<set<string>> routes;
	set<string> curr;
	string tmp;
	for(int j = 0; j < Q; j++) {
		int n; cin >> n;
		for(int i = 0; i < n; i++ ) {
			cin >> tmp;
			curr.insert(tmp);
		}
		int t = has(routes, curr);
		if(t == -1) {
			routes.push_back(curr);
			cout << "New bus " << routes.size();
			curr.clear();
		} else {
			cout << "Already exists for " << t+1;
			curr.clear();
		}
		cout << endl;
	}
	return 0;
}

