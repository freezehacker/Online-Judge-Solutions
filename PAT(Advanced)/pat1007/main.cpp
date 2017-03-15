// DP
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

const int MAXN = 1E5;
const int CASE_NUM = 1;
int arr[MAXN], n;
int dp[MAXN];


void DP() {
	memset(dp, 0, sizeof(dp));

	dp[0] = arr[0];
	int maxValue = arr[0], maxLeft = arr[0], maxRight = arr[0];
	int tmpValue, tmpLeft, tmpRight;

	for (int i = 1; i < n; ++i) {
		int tmpValue = arr[i] + dp[i - 1];
		if (tmpValue < arr[i]) {
			tmpLeft = tmpRight = arr[i];
			dp[i] = arr[i];
		} else {
			dp[i] = tmpValue;
			tmpRight = arr[i];
		}

		// In the meantime find the max.
		if (maxValue < dp[i]) {
			maxValue = dp[i];
			maxLeft = tmpLeft;
			maxRight = tmpRight;
		}
	}

	cout << maxValue << " " << maxLeft << " " << maxRight << endl;
}


// Return true, if all element in the array is negative.
bool isAllNegative() {
	for (int i = 0 ;i < n; ++i) {
		if (arr[i] >= 0) {
			return false;
		}
	}
	return true;
}


int main() {
	//ifstream cin("in");

	int numOfCases = CASE_NUM;
	while (numOfCases--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		// Special case(all is negative)
		if ( isAllNegative() ) {
			cout << 0 << " " << arr[0] << " " << arr[n - 1] << endl;
			continue;
		}

		DP();
	}

	return 0;
}