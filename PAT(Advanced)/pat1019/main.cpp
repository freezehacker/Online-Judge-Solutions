#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define CASE_NUM 1

vector<int> reverseBigNumber;

// Number in every digit is within an INT range.
bool isPalindromic(int n, int base) {

    do {
        reverseBigNumber.push_back( n % base );
        n /= base;
    } while (n);

    int length = reverseBigNumber.size();

    for (int i = length / 2 - 1; i >= 0; --i) {
        if (reverseBigNumber[i] != reverseBigNumber[length - 1 - i]) {
            return false;
        }
    }

    return true;
}


int main() {
    //ifstream cin("in");

    int caseNum = CASE_NUM;

    while (caseNum--) {
        reverseBigNumber.clear();

        int n, base;
        cin >> n >> base;

        if ( isPalindromic(n, base) ) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }

        for (int i = reverseBigNumber.size() - 1; i >= 0; --i) {
            if (i != reverseBigNumber.size() - 1) {
                cout << " ";
            }
            cout << reverseBigNumber[i];
        }

        cout << endl;
    }

    return 0;
}
