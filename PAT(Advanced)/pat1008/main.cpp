#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
	//ifstream cin("in");
	int n;
	cin >> n;
	int result = 0;
	int curFloor = 0;	// Start from floor 0.
	for (int i = 0; i < n; ++i) {
		int floor;
		cin >> floor;
		if (floor > curFloor) {
			result += (floor - curFloor) * 6;
		} else {
			result += (curFloor - floor) * 4;
		}
		result += 5;
		curFloor = floor;
	}
	cout << result << endl;

	return 0;
}