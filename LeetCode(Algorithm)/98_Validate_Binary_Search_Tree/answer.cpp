#include <iostream>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if ( !root ) return true;

        this->terminal = false;

        int minVal;
        int maxVal;
        dfs( root, minVal, maxVal );

        return !( this->terminal );
    }

    void dfs(TreeNode* root, int &minVal, int &maxVal) {
        if ( root ) {
            minVal = maxVal = root->val;

            if ( root->left ) {
                int m1 = minVal, m2 = maxVal;
                dfs( root->left, m1, m2 );
                if ( m2 >= root->val ) {
                    terminal = true;
                    return;
                }
                minVal = min( minVal, m1 );
                maxVal = max( maxVal, m2 );
            }

            if ( root->right ) {
                int m1 = minVal, m2 = maxVal;
                dfs( root->right, m1, m2 );
                if ( m1 <= root->val ) {
                    terminal = true;
                    return;
                }
                minVal = min( minVal, m1 );
                maxVal = max( maxVal, m2 );
            }
        }
    }

private:
    bool terminal;
};


int main(int argc, char const *argv[]) {
    
    return 0;
}