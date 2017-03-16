#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    string id;
    string name;
    short score;

    Student() {}
    Student(string id, string name, short score) : id(id), name(name), score(score) {}

    friend ostream& operator<<(ostream& out, const Student &student) {
        out << student.id << " " << student.name << " " << student.score;
        return out;
    }
};

bool cmpId(const Student &s1, const Student &s2) {
    return s1.id < s2.id;
}

bool cmpName(const Student &s1, const Student &s2) {
    return s1.name < s2.name
        || (s1.name == s2.name && s1.id < s2.id);   // Equal name, then sort by id.
}

bool cmpScore(const Student &s1, const Student &s2) {
    return s1.score < s2.score
        || (s1.score == s2.score && s1.id < s2.id);   // Equal score, then sort by id.
}


int main() {
//    ifstream cin("in.txt");

    int studentNum, sortType;
    cin >> studentNum >> sortType;

    vector<Student> students;

    for (int i = 0; i < studentNum; ++i) {
        Student student;
        cin >> student.id >> student.name >> student.score;
        students.push_back( student );
    }

    switch (sortType) {
    case 1:
        sort(students.begin(), students.end(), cmpId);
        break;
    case 2:
        sort(students.begin(), students.end(), cmpName);
        break;
    case 3:
        sort(students.begin(), students.end(), cmpScore);
        break;
    default:
        break;
    }

    for (int i = 0, length = students.size(); i < length; ++i) {
        cout << students.at(i) << endl;
    }

    return 0;
}
