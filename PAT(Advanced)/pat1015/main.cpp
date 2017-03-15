#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;


bool isPrime(int n) {
	if (n == 1) return false;
	if (n == 2 || n == 3) return true;
	int limit = sqrt(n) + 1;
	for (int i = 2; i <= limit; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}


int reverse(int n, int radix) {
	string nn;
	while (n) {
		nn += n % radix + '0';
		n /= radix;
	}

	// 'nn' is actually reversed.

	int result = 0;
	int base = 1;
	for (int i = nn.size() - 1; i >= 0; --i) {
		result += (nn[i] - '0') * base;
		base *= radix;
	}
	return result;
}


int main() {
	//ifstream cin("in");

	int number, radix;
	while (cin >> number) {
		if (number < 0) break;

		cin >> radix;
		//cout << number << endl;
		//cout << reverse(number, radix) << endl;
		if (isPrime(number) && isPrime(reverse(number, radix))) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}
