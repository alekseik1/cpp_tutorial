#include <iostream>
#include <sstream>
#include <exception>
using namespace std;

void EnsureEqual(const string& left, const string& right) {
  if(left != right) {
    stringstream ss;
    ss << left << " != " << right;
    throw runtime_error(ss.str());
  }
}

int main() {
  EnsureEqual("a", "a");
  try {
    EnsureEqual("a", "b");
  } catch(exception& e) {
    cout << e.what() << endl;
  }
  return 0;
}
