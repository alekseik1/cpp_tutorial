#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	vector<int> r;
	cin >> n;
	while (n != 0) {
		r.push_back(n%2);
		n /= 2;
	}
	for (int i = r.size()-1; i >= 0; --i) {
		cout << r[i];
	}
	return 0;
}
