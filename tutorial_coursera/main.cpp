#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;


int main() {
    ifstream input("input.txt");
    if(input) {
        string line;
        int N, M;
        input >> N >> M;
        getline(input, line); // Ох уж эта каретка :)
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M-1; ++j) {
                getline(input, line, ',');
                //cout << line << endl;
                cout << setw(10) << line << ' ';
            }
            getline(input, line);
            //cout << line << endl;
            cout << setw(10) << line << endl;
        }
    }
	return 0;
}

/*
int main() {
    vector<string> names = {"a", "b", "c"};
    vector<double> values = {5, 0.01, 0.000005};

    for (const auto& n : names) {
    cout << setw(10) << n << ' ';
    }
}
*/
