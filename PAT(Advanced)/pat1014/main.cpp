#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
using namespace std;

class Time {
public:
	int hour;
	int minute;

	Time() {}

	Time(int h, int m): hour(h), minute(m) {}

	Time(const Time &time) {
		this->hour = time.hour;
		this->minute = time.minute;
	}

	void passByMinutes(int minute) {
		if (!isValid()) return;

		int hour = minute / 60;
		minute %= 60;
		this->hour += hour;
		this->minute += minute;

		this->hour += this->minute / 60;
		this->minute %= 60;
	}

	bool isValid() const {
		return hour < 17;
	}

	int toMinutes() const {
		return this->minute + this->hour * 60;
	}

	string toString() const {
		string ret;

		if (hour < 10) {
			ret.push_back('0');
		}
		ret += intToString(hour);
		ret.push_back(':');
		if (minute < 10) {
			ret.push_back('0');
		}
		ret += intToString(minute);

		return ret;
	}

	friend ostream& operator<<(ostream &out, const Time &time) {
		out << time.toString();
		return out;
	}

private:
	string intToString(int i) const {
		if (i == 0) return "0";
		stack<int> reverseDigits;
		while (i) {
			reverseDigits.push(i % 10);
			i /= 10;
		}
		string ret;
		while (!reverseDigits.empty()) {
			ret.push_back( (char)(reverseDigits.top() + '0') );
			reverseDigits.pop();
		}
		return ret;
	}
};


struct Window {
	bool isAvailable;
	queue<int> waitingQueue;
	Time currentTime;
};


const int CASE_NUM = 1;
const int MAX_CLIENT_NUM = 1001;
const int INF = 0x3f3f3f3f;
int client[MAX_CLIENT_NUM];
vector<Window> windows;
map<int, string> answerMap;
int numOfWindow, capacity, numOfClient, numOfQuery;


void imitateProcess() {
	// Initialize the windows.
	for (int i = 0; i < numOfWindow; ++i) {
		Window window;
		window.isAvailable = true;
		window.currentTime = Time(8, 0);	// Time beginning from 08:00.
		windows.push_back(window);
	}

	// Initialize the clients.
	queue<int> clientQueue;
	for (int i = 0; i < numOfClient; ++i) {
		clientQueue.push(i);
	}
	

	// Fill some clients into the windows available in the beginning.
	int sum = min(capacity * numOfWindow, numOfClient);
	for (int i = 0; i < sum; ++i) {
		windows[i % numOfWindow].waitingQueue.push(i);
		clientQueue.pop();
	}

	while (true) {

		// Find the fastest window.
		int minIndex = -1;
		int minMinute = INF;
		for (int i = 0; i < numOfWindow; ++i) {
			Window& window = windows[i];
			if (window.isAvailable && !window.waitingQueue.empty()) {
				int clientNo = window.waitingQueue.front();
				int curMinute = window.currentTime.toMinutes() + client[clientNo];
				if (curMinute < minMinute) {
					minMinute = curMinute;
					minIndex = i;
				}
			}
		}

		// Loop until no further business can be processed.
		if (minIndex == -1) break;

		Window &window = windows[minIndex];
		int clientNo = window.waitingQueue.front();
		window.currentTime.passByMinutes(client[clientNo]);
		answerMap[clientNo] = window.currentTime.toString();	// Record the end time of this client.
		window.waitingQueue.pop();

		// This window may get off duty(after 17:00);
		if (!window.currentTime.isValid()) {
			window.isAvailable = false;
		}

		// If there're more clients, add the first one to this waiting queue.
		if (window.isAvailable && !clientQueue.empty()) {
			int nextClientNo = clientQueue.front();
			window.waitingQueue.push(nextClientNo);
			clientQueue.pop();
		}
	}
}


void init() {
	windows.clear();
	answerMap.clear();
}


int main() {
	//ifstream cin("in");

	int casenum = CASE_NUM;
	while (casenum--) {

		init();

		// Input.
		cin >> numOfWindow >> capacity >> numOfClient >> numOfQuery;
		for (int i = 0; i < numOfClient; ++i) {
			cin >> client[i];
		}

		// Imitate the whole queuing process.
		imitateProcess();

		// Output.
		for (int i = 0; i < numOfQuery; ++i) {
			int clientNo;
			cin >> clientNo;
			--clientNo;
			if (answerMap.count(clientNo) == 0) {
				cout << "Sorry" << endl;
			} else {
				cout << answerMap[clientNo] << endl;
			}
		}
	}

	return 0;
}
