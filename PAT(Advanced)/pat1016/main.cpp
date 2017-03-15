#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

const int CASE_NUM = 1;
int cost[24];


struct Record {
	string custName;
	string timestamp;
	string state;

	Record() {}

	Record(string c, string t, string s) {
		custName = c;
		timestamp = t;
		state = s;
	}

	string getMonthStr() const {
		return timestamp.substr(0, 2);
	}
};

bool cmpRecord(const Record &r1, const Record &r2) {
	return r1.custName < r2.custName
		|| (r1.custName == r2.custName && r1.timestamp < r2.timestamp);
}


struct BillItem {
	string startTime;
	string endTime;
	int minute;
	double cost;

	BillItem() {}

	BillItem(string s, string e, int m, double c) {
		startTime = s;
		endTime = e;
		minute = m;
		cost = c;
	}

	friend ostream& operator<<(ostream& out, const BillItem &bi) {
		out << bi.startTime << " " << bi.endTime << " " << bi.minute << " $" << bi.cost;
		return out;
	}
};

struct MonthlyBill {
	string custName;
	string month;
	vector<BillItem> items;
	double totalAmount;

	MonthlyBill() {}

	MonthlyBill(string c, string m) {
		custName = c;
		month = m;
	}

	void addItem(BillItem item) {
		items.push_back(item);
		totalAmount += item.cost;
	}

	bool shouldPrint() const {
		return items.size() > 0;
	}

	friend ostream& operator<<(ostream& out, const MonthlyBill &mb) {
		if (mb.items.size() == 0) {
			// do nothing.
		} else {
			out << mb.custName << " " << mb.month << endl;
			for (int i = 0, len = mb.items.size(); i < len; ++i) {
				out << mb.items[i] << endl;
			}
			out << "Total amount: $" << mb.totalAmount;
		}
		return out;
	}
};


int recordNum;
vector<Record> recordList;


void initCase() {
	recordList.clear();
}

int stringToInt(const string &s) {
	int ret = 0;
	for (int i = 0, siz = s.size(); i < siz; ++i) {
		ret = ret * 10 + (s[i] - '0');
	}
	return ret;
}

int calMinute(const string &startTime, const string &endTime) {
	//01:06:01
	//02:05:01
	int startMinutes = stringToInt(startTime.substr(0, 2)) * 24 * 60 
					+ stringToInt(startTime.substr(3, 2)) * 60 
					+ stringToInt(startTime.substr(6, 2));
	int endMinutes = stringToInt(endTime.substr(0, 2)) * 24 * 60 
					+ stringToInt(endTime.substr(3, 2)) * 60 
					+ stringToInt(endTime.substr(6, 2));
	return endMinutes - startMinutes;
}

double calCost(const string &startTime, const string &endTime) {
	//01:06:01
	//02:05:01

	int startDay = stringToInt(startTime.substr(0, 2));
	int startHour = stringToInt(startTime.substr(3, 2));
	int startMinute = stringToInt(startTime.substr(6, 2));
	int offsetToSub = cost[startHour] * startMinute;

	int endDay = stringToInt(endTime.substr(0, 2));
	int endHour = stringToInt(endTime.substr(3, 2));
	int endMinute = stringToInt(endTime.substr(6, 2));
	int offsetToAdd = cost[endHour] * endMinute;

	double ret = 0;

	// calculate hours
	int s = startDay * 24 + startHour;
	int e = endDay * 24 + endHour;
	for (; s < e; ++s) {
		ret += cost[s % 24] * 60;
	}

	return (ret - offsetToSub + offsetToAdd) / 100;
}

BillItem calBillItem(const Record &r1, const Record &r2) {
	string startTime = r1.timestamp.substr(3);
	string endTime = r2.timestamp.substr(3);
	int minute = calMinute(startTime, endTime);
	int monthIndex = stringToInt(r1.timestamp.substr(0, 2));
	double curCost = calCost(startTime, endTime);
	
	BillItem ret = BillItem(startTime, endTime, minute, curCost);
	return ret;
}


int main() {
	//ifstream cin("in2");

	int caseNum = CASE_NUM;
	cout << fixed << setprecision(2);
	while (caseNum--) {
		initCase();

		for (int i = 0; i < 24; ++i) {
			cin >> cost[i];
		}
		cin >> recordNum;
		for (int i = 0; i < recordNum; ++i) {
			Record record;
			cin >> record.custName >> record.timestamp >> record.state;
			recordList.push_back(record);
		}


		sort(recordList.begin(), recordList.end(), cmpRecord);


		MonthlyBill currentMonthlyBill;
		int len = recordList.size();
		for (int i = 0; i < len - 1; ++i) {
			// Fetch 2 records every time, and try to match them.
			const Record &record1 = recordList[i];
			const Record &record2 = recordList[i + 1];

			if (currentMonthlyBill.custName != record1.custName 
				|| currentMonthlyBill.month != record1.getMonthStr()) {
				if (currentMonthlyBill.shouldPrint()) {
					cout << currentMonthlyBill << endl;
				}
				// Update
				currentMonthlyBill = MonthlyBill(record1.custName, record1.getMonthStr());
			}

			if (record1.custName == record2.custName 
				&& record1.state == "on-line" && record2.state == "off-line") {	// If match
				BillItem billItem = calBillItem(record1, record2);
				currentMonthlyBill.addItem(billItem);
				++i;
			}
		}
		if (currentMonthlyBill.shouldPrint()) {
			cout << currentMonthlyBill << endl;
		}

	}

	return 0;
}
