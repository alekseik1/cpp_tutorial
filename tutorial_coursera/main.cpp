#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int has(const vector<vector<string>>& v, const vector<string>& el) {
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
	vector<vector<string>> routes;
	vector<string> curr;
	string tmp;
	for(int j = 0; j < Q; j++) {
		int n; cin >> n;
		for(int i = 0; i < n; i++ ) {
			cin >> tmp;
			curr.push_back(tmp);
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

