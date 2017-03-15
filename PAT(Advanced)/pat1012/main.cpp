#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


struct Student {
	int id;
	int cScore;	// C
	int mScore;	// Math
	int eScore;	// English
	int aScore;	// Average, by calculating

	Student() {}

	Student(int i, int c, int m, int e) {
		id = i;
		cScore = c;
		mScore = m;
		eScore = e;
		aScore = (cScore + mScore + eScore) / 3;
		//aScore = (int)((cScore + mScore + eScore) / 3.0 + 0.5);
	}

	~Student() {}
};

struct Result {
	int grade;
	char subject;

	Result() {
		grade = -1;
		subject = '-';
	}

	Result(int g, char s) {
		grade = g;
		subject = s;
	}

	friend ostream& operator<<(ostream& out, const Result& result) {
		out << result.grade << " " << result.subject;
		return out;
	}
};

/*bool compareByC(const Student* &a, const Student* &b) {
	return a->cScore > b->cScore;
}

bool compareByM(const Student* &a, const Student* &b) {
	return a->mScore > b->mScore;
}

bool compareByE(const Student* &a, const Student* &b) {
	return a->eScore > b->eScore;
}

bool compareByA(const Student* &a, const Student* &b) {
	return a->aScore > b->aScore;
}*/

bool compareByC(Student *a, Student *b) {
	return a->cScore > b->cScore;
}

bool compareByM(Student *a, Student *b) {
	return a->mScore > b->mScore;
}

bool compareByE(Student *a, Student *b) {
	return a->eScore > b->eScore;
}

bool compareByA(Student *a, Student *b) {
	return a->aScore > b->aScore;
}


const int CASE_NUM = 1;
const int MAX_N = 2001;
vector<Student*> studentListByC;
vector<Student*> studentListByM;
vector<Student*> studentListByE;
vector<Student*> studentListByA;


// A > C > M > E
Result getResult(int id) {
	int grade;
	char subject;

	int counter;
	int lastScore;

	for (int i = 0, len = studentListByA.size(); i < len; ++i) {
		const Student* student = studentListByA.at(i);

		if (i == 0) {
			counter = 1;
			lastScore = student->aScore;
		} else {
			if (student->aScore < lastScore) {
				++counter;
			}
		}

		if (id == student->id) {
			grade = counter;	// Note: grade is not always equal to i+1.
			subject = 'A';
			break;
		}

		lastScore = student->aScore;
	}

	for (int i = 0, len = studentListByC.size(); i < len; ++i) {
		const Student* student = studentListByC.at(i);
		
		if (i == 0) {
			counter = 1;
			lastScore = student->cScore;
		} else {
			if (student->cScore < lastScore) {
				++counter;
			}
		}

		if (id == student->id) {
			if (counter < grade) {
				grade = counter;
				subject = 'C';
			}
			break;
		}

		lastScore = student->cScore;
	}

	for (int i = 0, len = studentListByM.size(); i < len; ++i) {
		const Student* student = studentListByM.at(i);
		
		if (i == 0) {
			counter = 1;
			lastScore = student->mScore;
		} else {
			if (student->mScore < lastScore) {
				++counter;
			}
		}

		if (id == student->id) {
			if (counter < grade) {
				grade = counter;
				subject = 'M';
			}
			break;
		}

		lastScore = student->mScore;
	}

	for (int i = 0, len = studentListByE.size(); i < len; ++i) {
		const Student* student = studentListByE.at(i);
		
		if (i == 0) {
			counter = 1;
			lastScore = student->eScore;
		} else {
			if (student->eScore < lastScore) {
				++counter;
			}
		}

		if (id == student->id) {
			if (counter < grade) {
				grade = counter;
				subject = 'E';
			}
			break;
		}

		lastScore = student->eScore;
	}

	return Result(grade, subject);
}


void init() {
	studentListByA.clear();
	studentListByC.clear();
	studentListByM.clear();
	studentListByE.clear();
}



int main() {
	//ifstream cin("in");

	int numOfCases = CASE_NUM;
	while (numOfCases--) {
		init();

		int numOfStudents;
		cin >> numOfStudents;
		int numOfQueries;
		cin >> numOfQueries;

		vector<int> ids;

		for (int i = 0; i < numOfStudents; ++i) {
			int id, c, m, e;
			cin >> id >> c >> m >> e;

			Student* student = new Student(id, c, m, e);	// Note: heap memory, remember to release it later!
			ids.push_back(id);

			// To save memory, just save the address(pointer).
			studentListByC.push_back(student);
			studentListByM.push_back(student);
			studentListByE.push_back(student);
			studentListByA.push_back(student);
		}

		sort(studentListByC.begin(), studentListByC.end(), compareByC);
		sort(studentListByE.begin(), studentListByE.end(), compareByE);
		sort(studentListByA.begin(), studentListByA.end(), compareByA);
		sort(studentListByM.begin(), studentListByM.end(), compareByM);

		// Get the best rank for every student.
		// Priority: A > C > M > E.
		map<int, Result> results;
		for (int i = 0, len = ids.size(); i < len; ++i) {
			int curId = ids.at(i);
			results[curId] = getResult(curId);
		}

		/*for (map<int,Result>::iterator iter = results.begin(); iter != results.end(); ++iter) {
			cout << iter->first << ":" << iter->second << endl;
		}*/


		// Response to queries
		for (int i = 0; i < numOfQueries; ++i) {
			int id;
			cin >> id;
			if (results.count(id) == 0) {
				cout << "N/A" << endl;
			} else {
				cout << results[id] << endl;
			}
		}


		// Release the heap memory we apply
		for (int i = 0, len = studentListByC.size(); i < len; ++i) {
			delete studentListByC.at(i);
		}
	}

	return 0;
}
