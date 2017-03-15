#include <iostream>
#include <string>
#include <stack>
#include <fstream>
using namespace std;

const int CASE_NUM = 1;

string reverse(const string &s) {
	string ret;
	for (int i = s.size() - 1; i >= 0; --i) {
		ret += s[i];
	}
	return ret;
}

string add(string s1, string s2) {
	int carry = 0;
	string ret;

	// Align the digits.
	while (s1.size() < s2.size()) s1 = "0" + s1;
	while (s1.size() > s2.size()) s2 = "0" + s2;

	// Add by every digit, with a carry.
	int len = s1.size();
	stack<int> reversedAnswer;
	for (int i = len - 1; i >= 0; --i) {
		int temp = s1[i] - '0' + s2[i] - '0' + carry;
		carry = temp / 10;
		reversedAnswer.push( temp % 10 );
	}
	if (carry) {
		reversedAnswer.push( carry );
	}
	while (reversedAnswer.empty() == false) {
		ret += reversedAnswer.top() + '0';
		reversedAnswer.pop();
	}

	return ret;
}

bool isPalindromic(const string &s) {
	int len = s.size();
	int midIndex = len / 2;
	for (int i = 0; i < midIndex; ++i) {
		if (s[i] != s[len - 1 - i]) {
			return false;
		}
	}
	return true;
}


int main() {
	//ifstream cin("in");

	int casenum = CASE_NUM;
	while (casenum--) {
		string src;
		int maxStep;
		cin >> src >> maxStep;
		
		int i = 0;
		while (i < maxStep) {
			if (isPalindromic(src)) {
				break;
			}
			src = add( src, reverse(src) );	// Iteratively.
			++i;
		}

		cout << src << endl << i << endl;
	}
	return 0;
}
