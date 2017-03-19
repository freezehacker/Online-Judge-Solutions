/**
* This answer results in "TLE" or "WA", in the last case.
* Can anyone tell me why?
*/

//#include <iostream>
#include <cstdio>   // scanf, printf
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

struct Node {
    char ch;
    int nextAddr;
};

const int MAX_ADDRESS_NUM = 1e5;
const int CASE_NUM = 1;
Node node[MAX_ADDRESS_NUM]; // Mapping: address(int) --> value(Node).


int main() {
    /*ifstream cin("in.txt");*/
    //freopen("in.txt", "r", stdin);


    int numOfCase = CASE_NUM;
    while (numOfCase--) {

        // Input:
        int headAddr1, headAddr2;
        int numOfNode;
        /*cin >> headAddr1 >> headAddr2 >> numOfNode;*/
        scanf("%d %d %d", &headAddr1, &headAddr2, &numOfNode);
        for (int i = 0; i < numOfNode; ++i) {
            int curAddr, nextAddr;
            char ch;
            /*cin >> curAddr >> ch >> nextAddr;*/
            scanf("%d %c %d", &curAddr, &ch, &nextAddr);    // Mind scanf here!

            node[curAddr].ch = ch;
            node[curAddr].nextAddr = nextAddr;
        }


        // Build 2 strings:
        string str1, str2;

        int tmpAddr1 = headAddr1;
        while (tmpAddr1 != -1) {
            str1 += node[tmpAddr1].ch;
            tmpAddr1 = node[tmpAddr1].nextAddr;
        }

        int tmpAddr2 = headAddr2;
        while (tmpAddr2 != -1) {
            str2 += node[tmpAddr2].ch;
            tmpAddr2 = node[tmpAddr2].nextAddr;
        }

        vector<int> addrList1;  // Store the address of str1.
        tmpAddr1 = headAddr1;
        while (tmpAddr1 != -1) {
            addrList1.push_back( tmpAddr1 );
            tmpAddr1 = node[tmpAddr1].nextAddr;
        }


        // Find address of the first letter of common suffix:
        int firstLetterIndex = -1;
        for (int i = str1.size() - 1, j = str2.size() - 1; i >= 0 && j >= 0; --i, --j) {
            if (str1[i] != str2[j]) {
                break;
            } else {
                firstLetterIndex = i;
            }
        }

        if (firstLetterIndex == -1) {
            /*cout << -1 << endl;*/
            printf("-1\n");
        } else {
            /*cout << setfill('0') << setw(5) << addrList1.at( firstLetterIndex ) << endl;*/
            printf("%05d\n", addrList1.at( firstLetterIndex ));
        }
    }

    return 0;
}
