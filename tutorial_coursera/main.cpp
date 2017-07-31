#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct Specialization {
  string name;
  explicit Specialization(string s) {
    name = s;
  }
};

struct Course {
  string name;
  explicit Course(string c) {
    name = c;
  }
};

struct Week {
  string name;
  explicit Week(string w) {
    name = w;
  }
};

struct LectureTitle {
  string specialization;
  string course;
  string week;

  LectureTitle(Specialization s, Course c, Week w) {
    specialization = s.name;
    course = c.name;
    week = w.name;
  }
};
