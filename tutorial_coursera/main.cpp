#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Person {
public:
  void ChangeFirstName(const int& year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
	  n_h[year] = first_name;
  }
  void ChangeLastName(const int& year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
	  s_h[year] = last_name;
  }
  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
	  string surname = "";
	  string name = "";
	  //sort(s_h.begin(), s_h.end());
	  for(auto& i : s_h) {
		  if(i.first <= year) {
			  surname = i.second;
		  }
	  }
	  //sort(n_h.begin(), n_h.end());
	  for(auto& i : n_h) {
		  if(i.first <= year) {
			  //cout << i.first << endl;
			  name = i.second;
		  }
	  }
	  if(name.size() == 0 && surname.size() == 0) {
		  return "Incognito";
	  } else if(name.size() == 0) {
		  return surname + " with unknown name";
	  } else if(surname.size() == 0) {
		  return name + " with unknown last name";
	  } else {
		  return name + " " + surname;
	  }
  }
private:
  // приватные поля
  map<int, string> s_h;
  map<int, string> n_h;
};

