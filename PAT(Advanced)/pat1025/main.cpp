#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Record {
	// Inherent attributes
	string id;
	int score;
	int locNo;

	// Generated attributes (by sorting)
	int rank;
	int locRank;

	/*Record() {}*/

	Record(string id, int score, int locNo) 
			: id(id), score(score), locNo(locNo) {}

	friend ostream& operator<<(ostream& out, const Record &record) {
		out << record.id << " " << record.rank << " " << record.locNo << " " << record.locRank;
		return out;
	}
};

bool compareRecord(Record* const r1, Record* const r2) {
	return r1->score > r2->score
		|| (r1->score == r2->score && r1->id < r2->id);
}


int main() {
	//ifstream cin("in");
	//ofstream cout("my_answer");

	vector<Record*> recordList;	// Global rank list.
	int locationNumber;
	cin >> locationNumber;
	for (int curLocation = 1; curLocation <= locationNumber; ++curLocation) {
		vector<Record*> localRecordList;	// Local rank list.

		int testeeNumber;
		cin >> testeeNumber;
		for (int i = 0; i < testeeNumber; ++i) {
			string id;
			int score;
			cin >> id >> score;

			Record* newRecord = new Record(id, score, curLocation);

			recordList.push_back(newRecord);
			localRecordList.push_back(newRecord);
		}

		
		// Sort
		sort(localRecordList.begin(), localRecordList.end(), compareRecord);
		// Get the local ranks.
		if (localRecordList.size() > 0) {
			localRecordList[0]->locRank = 1;
		}
		for (int i = 1, len = testeeNumber; i < len; ++i) {
			if (localRecordList[i]->score == localRecordList[i - 1]->score) {
				localRecordList[i]->locRank = localRecordList[i - 1]->locRank;	// Same score, same rank.
			} else {
				localRecordList[i]->locRank = i + 1;
			}
		}
	}

	// Rank globally.
	sort(recordList.begin(), recordList.end(), compareRecord);
	// And get the global ranks.
	int len = recordList.size();
	if (len > 0) {
		recordList[0]->rank = 1;
	}
	for (int i = 1; i < len; ++i) {
		if (recordList[i]->score == recordList[i - 1]->score) {
			recordList[i]->rank = recordList[i - 1]->rank;
		} else {
			recordList[i]->rank = i + 1;
		}
	}


	// Output
	cout << len << endl;
	for (int i = 0; i < len; ++i) {
		cout << *recordList[i] << endl;
	}


	// Release the heap memory.
	for (int i = 0; i < len; ++i) {
		delete recordList[i];
	}

	return 0;
}
