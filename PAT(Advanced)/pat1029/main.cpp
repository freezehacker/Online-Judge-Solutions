#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

typedef long int lint;


int main() {
    //ifstream cin("in.txt");

    queue<lint> arr1;
    queue<lint> arr2;

    int num1;
    cin >> num1;
    for (int i = 0; i < num1; ++i) {
        lint tmp;
        cin >> tmp;
        arr1.push(tmp);
    }

    int num2;
    cin >> num2;
    for (int i = 0; i < num2; ++i) {
        lint tmp;
        cin >> tmp;
        arr2.push(tmp);
    }


    int idx = -1, midIdx = (num1 + num2 + 1) / 2 - 1;;
    lint answer = -1;
    bool isFound = false;

    // Check both arrays
    while (!arr1.empty() && !arr2.empty() && !isFound) {
        lint tmp;
        if (arr1.front() < arr2.front()) {
            tmp = arr1.front();
            arr1.pop();
        } else {
            tmp = arr2.front();
            arr2.pop();
        }

        idx++;
        if (idx == midIdx) {
            answer = tmp;
            isFound = true;
            break;
        }
    }

    // Check array 1
    while (!isFound && !arr1.empty()) {
        lint tmp = arr1.front();
        arr1.pop();
        ++idx;
        if (idx == midIdx) {
            answer = tmp;
            isFound = true;
            break;
        }
    }

    // Check array 2
    while (!isFound && !arr2.empty()) {
        lint tmp = arr2.front();
        arr2.pop();
        ++idx;
        if (idx == midIdx) {
            answer = tmp;
            isFound = true;
            break;
        }
    }

    cout << answer << endl;
    return 0;
}
