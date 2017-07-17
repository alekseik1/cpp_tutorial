#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void ChangeCapital(map<string, string>& cc, string country, string capital) {
	if(cc.count(country) != 0) {
		if(cc[country] != capital) {
			cout << "Country " << country << " has changed its capital from "
					<< cc[country] << " to " << capital;
			cc[country] = capital;
		} else {
			cout << "Country " << country << " hasn't changed its capital";
		}
	} else {
		cout << "Introduce new country " << country << " with capital " << capital;
		cc[country] = capital;
	}
	cout << endl;
}

void Rename(map<string, string>& cc, string oldn, string newn) {
	if(cc.count(oldn) != 0 && cc.count(newn) == 0 && oldn != newn) {
		cout << "Country " << oldn << " with capital " << cc[oldn] << " has been renamed to " << newn;
		cc[newn] = cc[oldn];
		cc.erase(oldn);
	} else {
		cout << "Incorrect rename, skip";
	}
	cout << endl;
}

void About(map<string, string>& cc, string country) {
	if(cc.count(country) != 0) {
		cout << "Country " << country << " has capital " << cc[country];
	} else {
		cout << "Country " << country << " doesn't exist";
	}
	cout << endl;
}

void Dump(const map<string, string>& cc) {
	if(cc.size() != 0) {
		for(auto i : cc) {
			cout << i.first << "/" << i.second << " ";
		}
		cout << endl;
	} else {
		cout << "There are no countries in the world";
		cout << endl;
	}
}

int main() {
	int N;
	string command;
	map<string, string> cc;
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> command;
		if (command == "CHANGE_CAPITAL")
		{
			string country, capital;
			cin >> country >> capital;
			ChangeCapital(cc, country, capital);
		}
		else if(command == "RENAME")
		{
			string oldn, newn;
			cin >> oldn >> newn;
			Rename(cc, oldn, newn);
		}
		else if(command == "ABOUT")
		{
			string country;
			cin >> country;
			About(cc, country);
		}
		else if(command == "DUMP")
		{
			Dump(cc);
		}
	}
	return 0;
}

