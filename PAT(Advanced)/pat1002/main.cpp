#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;


const int CASE_NUM = 1;
const int MAXN = 1002;
bool exists[MAXN];
double coe[MAXN];


double oneDecimal(double n) {
	//return (int)(n * 10) / 10.0;
	return n;
}

void init() {
	for (int i = 0; i < MAXN; ++i) {
		coe[i] = 0;
	}
	memset(exists, false, sizeof(exists));
}


int main() {
	ifstream cin("in");

	cout << fixed << setprecision(1);

	int numOfCases = CASE_NUM;
	while (numOfCases--) {
		init();

		int count = 0;
		int maxIndex = -1;

		int k1;
		cin >> k1;
		for (int i = 0; i < k1; ++i) {
			int n;
			double a;
			cin >> n >> a;
			coe[n] += oneDecimal(a);
			maxIndex = max(maxIndex, n);
			if (!exists[n]) {
				++count;
				exists[n] = true;
			}
		}

		int k2;
		cin >> k2;
		for (int i = 0; i < k2; ++i) {
			int n;
			double a;
			cin >> n >> a;
			coe[n] += oneDecimal(a);
			maxIndex = max(maxIndex, n);
			if (!exists[n]) {
				++count;
				exists[n] = true;
			}
		}
		
		// .......What the hell
		for (int i = maxIndex; i >= 0; --i) {
			if (fabs(coe[i]) < 1e-6) {
				--count;
				exists[i] = false;
			}
		}


		// Output
		cout << count;
		if (count > 0) {
			for (int i = maxIndex; i >= 0; --i) {
				if (exists[i]) {
					cout << " " << i << " " << coe[i];
				}
			}
		}
		cout << endl;
	}

	return 0;
}
