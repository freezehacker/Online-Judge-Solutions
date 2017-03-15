#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

typedef long long ULL;
const int CASE_NUM = 1;

ULL calNumber(const string &n, const ULL radix) {
	if (n == "0") return 0;
	if (n == "1") return 1;

	ULL result = 0;
	int len = n.size();
	ULL base = 1;
	for (int i = len - 1; i >= 0; --i) {
		const char &ch = n[i];
		if (ch >= '0' && ch <= '9') {
			result += base * (int)(ch - '0');
		} else if (ch >= 'a' && ch <= 'z') {
			result += base * (int)(ch - 'a' + 10);
		}
		base *= radix;
	}
	return result;
}

int getLowerBoundOfRadix(const string &n) {
	int ret = -1;
	for (int i = n.size() - 1; i >= 0; --i) {
		if (n[i] >= 'a' && n[i] <= 'z') {
			ret = max(ret, (int)(n[i] - 'a' + 10));
		} else if (n[i] >= '0' && n[i] <= '9') {
			ret = max(ret, (int)(n[i] - '0'));
		}
	}
	return max(2, ret + 1);
}


int main() {
	//ifstream cin("in");

	int numOfCases = CASE_NUM;
	while (numOfCases--) {
		string first, second;
		int tag;
		ULL radix;
		cin >> first >> second >> tag >> radix;

		// Special cases
		if (first == second) {
			if (first == "1") {
				cout << "2" << endl;
			} else {
				cout << radix << endl;
			}
			continue;
		}


		ULL number;
		string target;
		if (tag == 1) {
			number = calNumber(first, radix);
			target = second;
		} else if (tag == 2) {
			number = calNumber(second, radix);
			target = first;
		}

		// Find the answer
		ULL answer = getLowerBoundOfRadix(target);
		bool found;
		while (true) {
			ULL number2 = calNumber(target, answer);
			//cout << "number = " << number << ", number2 = " << number2 << endl;
			if (number2 == number) {
				found = true;
				break;
			} else if (number2 > number) {
				found = false;
				break;
			}

			// special case
			if (target == "0" || target == "1") {
				found = false;
				break;
			}

			++answer;
		}
		if (found) {
			cout << answer << endl;
		} else {
			cout << "Impossible" << endl;
		}
	}

	return 0;
}