#include <iostream>
#include <fstream>
#include <cstring>  // memset
#include <iomanip>  // setw, setfill
using namespace std;

const int MAX_ADDRESS_NUM = 1E5;
const int CASE_NUM = 1;
namespace my {
int next[MAX_ADDRESS_NUM];  // Store the next node's address.
}
bool existed[MAX_ADDRESS_NUM];


int main() {
    ifstream cin("in.txt");

    int t = CASE_NUM;
    while (t--) {
        memset(existed, false, sizeof(existed));

        int headAddress1, headAddress2;
        int numOfLetter;
        cin >> headAddress1 >> headAddress2 >> numOfLetter;
        for (int i = 0; i < numOfLetter; ++i) {
            int currentAddress, nextAddress;
            char ch;
            cin >> currentAddress >> ch >> nextAddress;

            my::next[currentAddress] = nextAddress;
        }


        // Mark by str1
        int tmpAddress = headAddress1;
        while (tmpAddress != -1) {
            existed[tmpAddress] = true;
            tmpAddress = my::next[tmpAddress];
        }

        // Find str2's first letter that was marked.
        int result = -1;
        tmpAddress = headAddress2;
        while (tmpAddress != -1) {
            if (existed[tmpAddress]) {
                result = tmpAddress;
                break;
            } else {
                tmpAddress = my::next[tmpAddress];
            }
        }

        if (result == -1) {
            cout << result << endl;
        } else {
            cout << setw(5) << setfill('0') << result << endl;
        }
    }

    return 0;
}