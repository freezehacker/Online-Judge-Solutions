#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int a, l;
        a = l = 0;
        
        for ( int i = 0, size = s.size(); i < size; ++i ) {
            if ( s[i] == 'A' ) {
                ++a;
            }

            if ( s[i] == 'L') {
                if ( i == 0 || s[i-1] != 'L' ) {
                    l = 1;
                } else {
                    ++l;
                }
            }
            
            if ( a > 1 || l > 2 ) return false;
        }

        return true;
    }
};


int main() {
    return 0;
}