#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

#define CASE_NUM 1

struct Record {
	string __name;
	string __inTime;
	string __outTime;

	Record(const string& n, const string& i, const string& o) : __name(n), __inTime(i), __outTime(o) {}
};


int main() {
	//ifstream cin("in");

	int numOfCase = CASE_NUM;
	while (numOfCase--) {
		int numOfRecords;
		cin >> numOfRecords;

		vector<Record> records;
		string name, inTime, outTime;
		for (int i = 0; i < numOfRecords; ++i) {
			cin >> name >> inTime >> outTime;
			records.push_back( Record(name, inTime, outTime) );
		}

		// Find the max mnd min
		string minIn, minName;
		string maxOut, maxName;
		for (int i = 0; i < numOfRecords; ++i) {
			const Record &curRecord = records.at(i);
			if (i == 0) {
				minIn = curRecord.__inTime;
				maxOut = curRecord.__outTime;
				minName = maxName = curRecord.__name;
			} else {
				if (curRecord.__inTime < minIn) {
					minIn = curRecord.__inTime;
					minName = curRecord.__name;
				}
				if (curRecord.__outTime > maxOut) {
					maxOut = curRecord.__outTime;
					maxName = curRecord.__name;
				}
			}
		}

		cout << minName << ' ' << maxName << endl;
	}

	return 0;
}