#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

struct Customer {
	int arrivingMoment;
	int processingTime;

	Customer() {}

	Customer(string arrive, int processMinute) {
		int hour = (arrive[0] - '0') * 10 + (arrive[1] - '0');
		int minute = (arrive[3] - '0') * 10 + (arrive[4] - '0');
		int second = (arrive[6] - '0') * 10 + (arrive[7] - '0');
		this->arrivingMoment = hour * 3600 + minute * 60 + second;
		this->processingTime = processMinute * 60;
	}
};

bool cmp(const Customer &c1, const Customer &c2) {
	return c1.arrivingMoment < c2.arrivingMoment;
}

const int MAX_WINDOW_NUM = 100;
const int MAX_INT_VALUE = 0x3f3f3f3f;
int windows[MAX_WINDOW_NUM];	// Value: serving moment(in seconds).


int main() {
	//ifstream cin("in");

	int numOfCustomer, numOfWindow;
	cin >> numOfCustomer >> numOfWindow;
	vector<Customer> customers;
	for (int i = 0; i < numOfCustomer; ++i) {
		string s;
		int a;
		cin >> s >> a;
		if (s >= "17:00:01") {	// No service for this customer.
			continue;
		}
		customers.push_back( Customer(s, a) );
	}

	sort(customers.begin(), customers.end(), cmp);

	for (int i = 0; i < numOfWindow; ++i) {
		windows[i] = 8 * 3600;
	}

	// Calculate everyone's waiting time, and sum them up.
	double waitingTimeInSeconds = 0.0;
	int actualNumOfCustomer = customers.size();
	for (int i = 0; i < actualNumOfCustomer; ++i) {
		const Customer &customer = customers[i];

		// Find the soonest window.
		int soonIndex = -1;
		int soonValue = MAX_INT_VALUE;
		for (int j = 0; j < numOfWindow; ++j) {
			if (windows[j] < soonValue) {
				soonValue = windows[j];
				soonIndex = j;
			}
		}

		
		if (windows[soonIndex] > customer.arrivingMoment) {
			// If customer arrives early, then he/she will wait.
			waitingTimeInSeconds += windows[soonIndex] - customer.arrivingMoment;
		} else {
			// Or the window will wait for a customer.
			windows[soonIndex] = customer.arrivingMoment;
		}
		windows[soonIndex] += customer.processingTime;
	}

	cout << fixed << setprecision(1);
	cout << waitingTimeInSeconds / actualNumOfCustomer / 60 << endl;

	return 0;
}
