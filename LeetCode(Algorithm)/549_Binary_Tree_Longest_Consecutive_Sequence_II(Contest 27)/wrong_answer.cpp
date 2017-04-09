#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <cmath>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        vector<int> in;
        bool inc = true;
        int maxCount = 0;
        inOrder( root, in, inc, maxCount );

        int size = in.size();
        maxCount = max( size, maxCount );   // One last time to get max.
        return maxCount;
    }

    void inOrder(TreeNode* root, vector<int> &order, bool &inc, int &maxCount) {
        if ( root ) {
            inOrder( root->left, order, inc, maxCount );

            if ( order.size() == 0 ) {
                order.push_back( root->val );
            } else if ( order.size() == 1 && 1 == abs( order[order.size() - 1] - root->val ) ) {
                inc = root->val > order[order.size() - 1];
                order.push_back( root->val );
            } else if ( (inc && root->val - order[order.size()-1] == 1) || (!inc && order[order.size()-1] - root->val == 1) ) {
                order.push_back( root->val );
            } else {
                if ( order.size() > maxCount ) {
                    maxCount = order.size();  // Get max.
                }
                //printVector( order );
                order.clear();
                order.push_back( root->val );
            }

            inOrder( root->right, order, inc, maxCount );
        }
    }

    void printVector(const vector<int> &V) {
        cout << "vector: ";
        for (int i = 0; i < V.size(); ++i) {
            cout << "," << V[i];
        }
        cout << endl;
    }
};


int main(int argc, char const *argv[]) {
    
    return 0;
}