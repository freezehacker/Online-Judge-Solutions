#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_VALUE = 101;
const int MIN_VALUE = -1;

struct Student {
    string name;
    char gender;
    string id;
    int score;
};


int main() {
    //ifstream cin("in.txt");

    int numOfStudent;
    cin >> numOfStudent;

    Student highestFemale;
    highestFemale.score = MIN_VALUE;

    Student lowestMale;
    lowestMale.score = MAX_VALUE;

    for (int i = 0; i < numOfStudent; ++i) {
        Student student;
        cin >> student.name >> student.gender >> student.id >> student.score;

        if (student.gender == 'M' && student.score < lowestMale.score) {
            lowestMale = student;
        }

        if (student.gender == 'F' && student.score > highestFemale.score) {
            highestFemale = student;
        }
    }


    // Output

    bool absent = false;

    if (highestFemale.score == MIN_VALUE) {
        cout << "Absent" << endl;
        absent = true;
    } else {
        cout << highestFemale.name << " " << highestFemale.id << endl;
    }

    if (lowestMale.score == MAX_VALUE) {
        cout << "Absent" << endl;
        absent = true;
    } else {
        cout << lowestMale.name << " " << lowestMale.id << endl;
    }

    if (absent) {
        cout << "NA" << endl;
    } else {
        cout << highestFemale.score - lowestMale.score << endl;
    }


    return 0;
}
