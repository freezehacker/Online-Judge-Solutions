#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string numStr = std::to_string( n );
        sort( numStr.begin(), numStr.end() );
        do {

            int curNum = string2Int( numStr );
            if ( curNum > n ) {
                return curNum;
            }

        } while ( next_permutation( numStr.begin(), numStr.end() ) );

        return -1;  // -1 when not available.
    }

    int string2Int(string s) {
        int ret = 0;
        for ( int i = 0, size = s.size(); i < size; ++i ) {
            ret = ret * 10 + (s[i] - '0');
        }
        return ret;
    }
};


int main(int argc, char const *argv[]) {
    /* code */
    return 0;
}