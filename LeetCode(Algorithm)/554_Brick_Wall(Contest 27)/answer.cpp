#include <iostream>
#include <fstream>
#include <map>
#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int, int> count;

        int height = wall.size();
        for ( int i = 0; i < height; ++i ) {
            int cnt = wall[i].size();

            int width = 0;
            for ( int j = 0; j < cnt - 1; ++j ) {
                width += wall[i][j];
                ++count[ width ];
            }
        }

        int maxCross = 0;
        int maxKey = -1;
        map<int, int>::iterator iter = count.begin();
        for ( ; iter != count.end(); ++iter ) {
            if ( maxCross < iter->second ) {
                maxCross = iter->second;
                maxKey = iter->first;
            }
            //cout << iter->first << ", " << iter->second << endl;
        }

        int answer = height - maxCross;
        return answer;
    }
};


int main() {
    
    return 0;
}