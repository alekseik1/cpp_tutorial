#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct delo {
	string name;
	int month;
	int day;
};

void AddDelo(vector<delo>& dela, string name, int month, int day) {
	dela.push_back({name, month, day});
}

void FinishMonth(vector<delo>& dela, int& curr_month) {
	if (curr_month == 12) {	// Январь
		curr_month = 1;
		return;
	}
	vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (days_in_month[curr_month] >= days_in_month[curr_month - 1]) {
		curr_month++;
		return;
	} else {
		for (auto& i : dela) {
			if (i.day > days_in_month[curr_month]) {
				i.day = days_in_month[curr_month];	// Все откладываем на последний день
			}
		}
		curr_month++;
	}
}

void DumpDay(vector<delo>& dela, int day) {
	int count = 0;
	for (delo i : dela) {
		if(i.day == day) {
			count++;
		}
	}
	if(count == 0) {
		cout << 0 << endl;
		return;
	}
	cout << count << " ";
	for (delo i : dela) {
		if(i.day == day) {
			cout << i.name << " ";
		}
	}
	cout << endl;
}

int main() {
	int Q;
	int curr_month = 1;
	cin >> Q;
	vector<delo> dela;
	string command;
	for (int i = 0; i < Q; i++) {
		cin >> command;
		if(command == "NEXT") {
			FinishMonth(dela, curr_month);
		} else if(command == "DUMP") {
			int day;
			cin >> day;
			DumpDay(dela, day);
		} else if(command == "ADD") {
			int day;
			string name;
			cin >> day >> name;
			AddDelo(dela, name, curr_month, day);
		}
	}
	return 0;
}

