// 1116. Come on! Let's C
#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <fstream>
using namespace std;

// 1 <= n <= 10000
bool isPrimeNumber(int n) {
	if (n == 1) return false;
	if (n == 2) return true;

	int limit = 1 + sqrt(n);
	for (int i = 2; i <= limit; ++i) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}


int main() {
	//ifstream cin("pat1116.in");

	int totalNum, queryNum;
	map<string, int> rank;
	map<string, bool> isChecked;
	string name;


	cin >> totalNum;
	for (int i = 0; i < totalNum; ++i) {
		cin >> name;
		rank[name] = i + 1;	// Give it a rank.
	}

	cin >> queryNum;
	for (int i = 0; i < queryNum; ++i) {
		cin >> name;

		cout << name << ": ";
		if ( isChecked.count(name) == 1 ) {	// If has been checked
			cout << "Checked";
		} else if ( rank.count(name) == 0 ) {	// If not existed
			cout << "Are you kidding?";
		} else if ( rank[name] == 1 ) {	// If rank the first
			cout << "Mystery Award";
		} else if ( isPrimeNumber( rank[name] ) ) {	// If the rank's a prime
			cout << "Minion";
		} else {	// other cases
			cout << "Chocolate";
		}
		cout << endl;

		if ( rank.count(name) == 1 ) {
			isChecked[name] = true;	// Mark that it has been checked.
		}
	}

	return 0;
}
