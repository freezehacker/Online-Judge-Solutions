#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

const int CASE_NUM = 1;

string reformat(int n) {
	stack<char> digits;
	int counter = 0;
	int number = n > 0 ? n : -n;

	// Special case : 0
	if (number == 0) {
		return "0";
	}

	while (number > 0) {
		digits.push(number % 10 + '0');
		number /= 10;
		++counter;
		if (counter % 3 == 0 && number > 0) {
			digits.push(',');
		}
	}
	if (n < 0) {
		digits.push('-');
	}

	string result("");
	while (digits.empty() == false) {
		char ch = digits.top();
		digits.pop();
		result.push_back(ch);
	}
	return result;
}


int main(int argc, char const *argv[]) {
	//ifstream cin("in");

	int numOfCases = CASE_NUM;
	while (numOfCases--) {
		int a, b;
		cin >> a >> b;
		cout << reformat(a + b) << endl;
	}

	return 0;
}