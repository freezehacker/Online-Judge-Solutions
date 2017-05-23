#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        this->answer = "";

        string cur;
        dfs( strs, 0, cur );

        return this->answer;
    }

    void dfs(const vector<string> &strList, int idx, string cur) {
        if ( idx >= strList.size() ) {
            int times = cur.size();
            while ( times-- ) {
                cur = getNext( cur );
                if ( cur > this->answer ) {
                    this->answer = cur;
                }
            }
            return;
        }

        dfs( strList, idx + 1, cur + strList[idx] );
        dfs( strList, idx + 1, cur + getReverse( strList[idx] ) );
    }

    string getNext(string s) {
        return s.substr( 1 ) + s[0];
    }

    string getReverse(string s) {
        string ret;
        for ( int i = s.size() - 1; i >= 0; --i ) {
            ret += s[i];
        }
        return ret;
    }

private:
    string answer;
};


int main() {

    return 0;
}
