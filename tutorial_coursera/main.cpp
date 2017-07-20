#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

using namespace std;

int main() {
	int N; cin >> N;
	vector<int> num;
	for(int i = 0; i < N; i++) {
		int k; cin >> k;
		num.push_back(k);
	}
	sort(begin(num), end(num), [](int a, int b) {
		return(abs(a) < abs(b));
	});
	for(auto& e : num) {
		cout << e << " ";
	}
	return 0;
}
