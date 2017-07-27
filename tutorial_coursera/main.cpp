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

  string GetFullNameWithHistory(const int& year) {
	  string curr_name = "";
	  vector<string> name_stack;
	  for(auto& i : n_h) {
		  if(i.first <= year && i.second != curr_name) {
			  curr_name = i.second;
			  name_stack.push_back(i.second);
		  }
	  }	// Сделали текущее имя, ура!
	  string curr_surname = "";
	  vector<string> surname_stack;
	  for(auto& i : s_h) {
		  if(i.first <= year && i.second != curr_surname) {
			  curr_surname = i.second;
			  surname_stack.push_back(i.second);
		  }
	  }
	  string name_part = "";
	  if(curr_name.size() != 0) {
		  name_part = curr_name;
		  if(name_stack.size() > 0) {
			  checkTheFuckingListAndReverseIt(name_stack, curr_name);
			  //reverse(name_stack.begin(), name_stack.end());
		  }
		  if(name_stack.size() > 0) {
			  name_part += " (";
			  for(auto& s : name_stack) {
					  name_part += s;
				  if(s != name_stack.back()) {
					  name_part += ", ";
				  } else {
					  name_part += ") ";
				  }
			  }
		  } else {
			  name_part += " ";
		  }
	  }
	  string surname_part = "";
	  if(curr_surname.size() != 0) {
		  surname_part = curr_surname;
		  if(surname_stack.size() > 0) {
			  checkTheFuckingListAndReverseIt(surname_stack, curr_surname);
			  //reverse(surname_stack.begin(), surname_stack.end());
		  }
		  if(surname_stack.size() > 0) {
			  surname_part += " (";
			  for(unsigned j = 0; j < surname_stack.size(); j++) {
				  string s = surname_stack[j];
				  surname_part += s;
				  if(j != surname_stack.size() - 1) {
					  surname_part += ", ";
				  } else {
					  surname_part += ") ";
				  }
			  }
		  } else {
			  surname_part += " ";
		  }
	  }
	  if(name_part.size() == 0 && surname_part.size() == 0) {
		  return "Incognito";
	  } else if(name_part.size() == 0) {
		  return surname_part + "with unknown first name";
	  } else if(surname_part.size() == 0) {
		  return name_part + "with unknown last name";
	  } else {
		  string tmp = name_part + surname_part;
		  rtrim(tmp);
		  return tmp;
	  }
	  return "";
  }
private:
  static inline void rtrim(std::string &s) {
      s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
          return !std::isspace(ch);
      }).base(), s.end());
  }
  void checkTheFuckingListAndReverseIt(vector<string>& list, string& first_item) {
	  reverse(list.begin(), list.end());
	  if(first_item == list[0]) {
		  list.erase(list.begin());
	  }
	  if(list.size() == 0) {
		  return;
	  }
	  for(unsigned i = 0; i < list.size() - 1; i++) {
		  if(list[i] == list[i+1]) {
			  list.erase(list.begin() + i);
			  i--;
		  }
	  }
  }
  // приватные поля
  map<int, string> s_h;
  map<int, string> n_h;
};
