#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;


const string digit[10] = {"zero", "one", "two", "three", "four", 
					"five", "six", "seven", "eight", "nine"};


int main() {
	//ifstream cin("in");

	string numberString;
	int number = 0;
	cin >> numberString;

	// Increment every digit.
	for (int i = 0, len = numberString.size(); i < len; ++i) {
		number += (int)(numberString[i] - '0');
	}

	// Special case...
	if (number == 0) {
		cout << "zero" << endl;
		return 0;
	}

	// Parse every digit.
	stack<int> reverseDigit;
	while (number) {
		reverseDigit.push(number % 10);
		number /= 10;
	}

	// Output the results.
	while (!reverseDigit.empty()) {
		int n = reverseDigit.top();
		reverseDigit.pop();
		cout << digit[n];
		if (!reverseDigit.empty()) {
			cout << " ";
		} else {
			cout << endl;
		}
	}

	return 0;
}
