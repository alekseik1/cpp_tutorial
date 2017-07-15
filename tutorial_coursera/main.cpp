#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void PrintVector(const vector<int>& v) {
	int i = 0;
	for (auto s : v) {
		cout << i << ": " << s << endl;
		++i;
	}
}

int main() {
	int Q;
	int curr_man = 0;
	cin >> Q;
	vector<int> worry;
	vector<int> queue;
	for (int i = 0; i < Q; ++i) {
		string op;
		int k;
		cin >> op;
		if (op != "WORRY_COUNT") {
			cin >> k;
			if (op == "COME") {
				if (k > 0) {
					for (int j = 0; j < k; j++) {
						queue.push_back(curr_man);
						++curr_man;
					}
				} else if (k < 0) {
					for (int j = 0; j < -k; j++) {
						for(int gav = 0; gav < worry.size(); gav++) {
							if (queue.back() == worry[gav]) {
								worry.erase(worry.begin() + gav);
							}
						}
						queue.pop_back();
						--curr_man;
					}
				}
			} else if (op == "WORRY") {
				worry.push_back(queue[k]);
			} else if (op == "QUIET") {
				auto pos = std::find(worry.begin(), worry.end(), k);
				worry.erase(pos);
			}
		} else {
			cout << worry.size() << endl;
			continue;
		}
	}
	return 0;
}

