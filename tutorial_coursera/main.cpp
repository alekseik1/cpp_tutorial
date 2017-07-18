#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool has(const vector<string>& v, string el) {
	if(std::find(v.begin(), v.end(), el) != v.end())
		return true;
	else
		return false;
}

int main() {
	int Q;
	string command;
	map<string, vector<string>> stops_for_bus;
	vector<string> crutch;	
	cin >> Q;
	for(int i = 0; i < Q; i++) {
		cin >> command;
		if(command == "NEW_BUS") {
			int n;
			string stop;
			string bus;
			cin >> bus >> n;
			crutch.push_back(bus);	// Топовый костыль: в отдельную очередь запихнем порядок ввода автобусов. И зачем авторы задания просят это делать?
			vector<string> route;
			for(int j = 0; j < n; j++) {
				cin >> stop;
				route.push_back(stop);
			}
			stops_for_bus[bus] = route;
			route.clear();
		} else if(command == "BUSES_FOR_STOP") {
			string stop; cin >> stop;
			vector<string> tmp_buses;
			
            		for(auto bus_i : crutch) {
                    		if(has(stops_for_bus[bus_i], stop)) {
                        		tmp_buses.push_back(bus_i);
                    		}
            		}

			/*for(auto bus_and_route : stops_for_bus) {
				if(has(bus_and_route.second, stop)) {	// Если автобус проезжает через остановку
					tmp_buses.push_back(bus_and_route.first);
				}
			}*/
			if(tmp_buses.size() == 0) {
				cout << "No stop" << endl;
				continue;
			} else {
				for(auto i : tmp_buses) {
					cout << i << " ";
				}
				cout << endl;
			}
		} else if(command == "STOPS_FOR_BUS") {	// Написал после стакана вина. Не спрашивайте, как. Тееперь и работает
			string bus; cin >> bus;		// TODO: тут надо выводить в порядке, в котором они были занесены. Ужас!
			bool fl = true;
			if(stops_for_bus.count(bus) == 0) {
				cout << "No bus";
				cout << endl;
				continue;
			}
			for(auto stop : stops_for_bus[bus]) {
				cout << "Stop " << stop << ": ";
				for(auto bus_i : crutch) {
					if(has(stops_for_bus[bus_i], stop) && bus_i != bus) {
						cout << bus_i << " ";
						fl = false;
					}
				}
				if(fl) {
					cout << "no interchange";
				}
				fl = true;
				cout << endl;
			}
			fl = true;
		} else if(command == "ALL_BUSES") {	// Тут все правильно.
			if(stops_for_bus.size() == 0) {
				cout << "No buses" << endl;
				continue;
			} else {
				for(auto m : stops_for_bus) {
					cout << "Bus " << m.first << ": ";
					for(auto k : m.second) {
						cout << k << " ";
					}
					cout << endl;
				}
			}
		}
	}
	return 0;
}

