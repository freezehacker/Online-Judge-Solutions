#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <fstream>
using namespace std;

const int CASE_NUM = 1;

string getDouble(const string &src) {
	string dest;
	stack<char> reversedStr;
	int carry = 0;
	for (int i = src.size() - 1; i >= 0; --i) {
		int temp = (src[i] - '0') * 2 + carry;
		carry = temp / 10;
		reversedStr.push( (char)(temp % 10 + '0') );
	}
	if (carry) {	// The last carry.
		reversedStr.push( (char)(carry + '0') );
	}

	while (reversedStr.empty() == false) {
		dest += reversedStr.top();
		reversedStr.pop();
	}
	return dest;
}

bool isSameSeq(string s1, string s2) {
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	return s1 == s2;
}


int main() {
	//ifstream cin("in.txt");

	int casenum = CASE_NUM;
	while (casenum--) {
		string str;
		cin >> str;
		string doubleStr = getDouble(str);
		if (isSameSeq(str, doubleStr)) {
			cout << "Yes";
		} else {
			cout << "No";
		}
		cout << endl << doubleStr << endl;
	}

	return 0;
}
