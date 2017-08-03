#include <iostream>
#include <exception>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

string WRONG_FORMAT = "wrong_date_format";
string WRONG_DAY = "wrong_day";
string WRONG_MONTH = "wrong_month";

class Date {
public:

    Date() {
        year = 1970;
        month = 1;
        day = 1;
    }

    Date(const int& year1,  const int& month1, const int& day1) {
        if (!(month1 > 0 && month1 <= 12)) {
            //  Неправильная дата
            month = month1;
            throw runtime_error(WRONG_MONTH);
        } else if ( !(day1 > 0 && day1 <= 31)) {
            //  Неправильная дата
            day = day1;
            throw runtime_error(WRONG_DAY);
        } else {
            year = year1;
            month = month1;
            day = day1;
        }
    }

	int getDay() const {
		return day;
	}

	void setDay(int day) {
		this->day = day;
	}

	int getMonth() const {
		return month;
	}

	void setMonth(int month) {
		this->month = month;
	}

	int getYear() const {
		return year;
	}

	void setYear(int year) {
		this->year = year;
	}

private:
  int day, month, year;
};

bool operator<(const Date& lhs, const Date& rhs) {
	if(rhs.getYear() > lhs.getYear()) {
		return true;
	} else if(rhs.getYear() < lhs.getYear()) {
		return false;
	} else {
		if(rhs.getMonth() > lhs.getMonth()) {
			return true;
		} else if(rhs.getMonth() < lhs.getMonth()) {
			return false;
		} else {
			if(rhs.getDay() > lhs.getDay()) {
				return true;
			} else if(rhs.getDay() < lhs.getDay()) {
				return false;
			}
		}
	}
	// Unreachable code, but who knows...
	return false;
}

bool operator>(const Date& a, const Date& b) {
	return !(a < b);
}

bool operator==(const Date& a, const Date& b) {
	return (a.getDay() == b.getDay()) && (a.getMonth() == b.getMonth()) && (a.getYear() == b.getYear());
}

ostream& operator<<(ostream& stream, const Date& date) {
	stream << setfill('0') << setw(4) << date.getYear() << '-' \
			<< setfill('0') << setw(2) << date.getMonth() << '-' \
			<< setfill('0') << setw(2) << date.getDay();
	return stream;
}

istream& operator>>(istream& stream, Date& date) {
	int year, month, day;
	string full_str;
	stream >> full_str;
	istringstream ss(full_str);
	ss >> year;
	if(ss.peek() != '-') {
		cout << "Wrong date format: " << full_str << endl;
		throw runtime_error(WRONG_FORMAT);
	}
	ss.ignore(1);
	ss >> month;
	if(ss.peek() != '-') {
		cout << "Wrong date format: " << full_str << endl;
		throw runtime_error(WRONG_FORMAT);
	}
	ss.ignore(1);
	ss >> day;
	try {
		date = {year, month, day};
	} catch(exception& e) {
		if(e.what() == WRONG_MONTH) {
			cout << "Month value is invalid: " << month << endl;
		} else if(e.what() == WRONG_DAY) {
			cout << "Day value is invalid: " << day << endl;
		}
		throw e;
	}
	return stream;
}

class Database {
public:

	void AddEvent(const Date& date, const string& event) {
		events_on_date[date].insert(event);
	}

	bool DeleteEvent(const Date& date, const string& event) {
		if(events_on_date.count(date) == 0) {	// Дата не найдена
			cout << "Event not found" << endl;
			return false;
		}
		if(events_on_date[date].count(event) == 0) {	// Событие не найдено
			cout << "Event not found" << endl;
			return false;
		}
		events_on_date[date].erase(event);
		cout << "Deleted successfully" << endl;
		return true;
	}

	int DeleteDate(const Date& date) {
		int N = events_on_date[date].size();
		events_on_date.erase(date);
		cout << "Deleted " << N << " events" << endl;
		return N;
	}

	vector<string> Find(const Date& date) const {
		vector<string> res;
		try {
			for(const string& event : events_on_date.at(date)) {
				cout << event << endl;
				res.push_back(event);
			}
		} catch(exception& e) {}
		return res;
	}

	void Print() const {
	  for(auto& i : events_on_date) {
		  for(auto& s : i.second) {
			  cout << i.first << ' ' << s << endl;
		  }
	  }
	}

private:
	map<Date, set<string>> events_on_date;
};

// Возвращает из строки вектор с разделенными словами (костыльно, но другого способа не нашел)
vector<string> parseArgs(const string& s) {
	  istringstream ss(s);
	  vector<string> args;
	  do {
		  string tmp;
		  ss >> tmp;
		  args.push_back(tmp);
	  } while(ss);
	  args.pop_back();
	  return args;
}

int main() {
  Database db;

  string command;
  while (getline(cin, command)) {

	  if(command.size() == 0) {
		  continue;
	  }

	  vector<string> args = parseArgs(command);

	  if(args.front() == "Print") {
		  db.Print();
	  } else if(args.front() == "Add") {
		  if(args.size() != 3) {	// Если парередали меньше 3 аргументов - игнорируем (мало ли)
			  continue;
		  }
		  istringstream ss(args[1]);
		  Date d;

		  try {
			  ss >> d;	// Здесь может вылезти ошибка, при этом программа аварийно завершится. Нас так устраивает
		  } catch(exception& e) {
			  // TODO: Добавьте сюда обработчик ошибки
		  }

		  db.AddEvent(d, args[2]);
	  } else if(args.front() == "Find") {
		  if(args.size() != 2) {	// Если передали меньше 2 аргументов - игнорируем (мало ли)
			  continue;
		  }
		  istringstream ss(args[1]);
		  Date d;
		  try {
			  ss >> d;	// Здесь может вылезти ошибка, при этом программа аварийно завершится. Нас так устраивает
		  } catch(exception& e) {
			  // TODO: Добавьте сюда обработчик ошибки
			  return 0;
		  }

		  db.Find(d);
	  } else if(args.front() == "Del") {
		  if(args.size() == 2) {	// Удаляем за дату
			  istringstream ss(args[1]);
			  Date d;

			  try {
				  ss >> d;	// Здесь может вылезти ошибка, при этом программа аварийно завершится. Нас так устраивает
			  } catch(exception& e) {
				  // TODO: Добавьте сюда обработчик ошибки
				  return 0;
			  }

			  db.DeleteDate(d);
		  } else if(args.size() == 3) {	// Удаляем за дату событие с именем
			  istringstream ss(args[1]);
			  Date d;

			  try {
				  ss >> d;	// Здесь может вылезти ошибка, при этом программа аварийно завершится. Нас так устраивает
			  } catch(exception& e) {
				  // TODO: Добавьте сюда обработчик ошибки
				  return 0;
			  }

			  db.DeleteEvent(d, args[2]);
		  }
	  } else {	// Неизвестная команда
		  cout << "Unknown command: " << args.front() << endl;
		  return 0;
	  }
  }
  //db.Print();
  return 0;
}
