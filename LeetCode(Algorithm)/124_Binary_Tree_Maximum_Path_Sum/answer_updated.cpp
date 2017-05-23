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
    int maxPathSum(TreeNode* root) {
        this->mps = -2147483648;

        if ( !root ) return this->mps;

        getMaxSumOf( root );
        return this->mps;
    }

    int getMaxSumOf(TreeNode* root) {
        // Choose the left path to go...
        int l = root->val;
        if ( root->left ) {
            l += getMaxSumOf( root->left );
        }

        // Choose the right path...
        int r = root->val;
        if ( root->right ) {
            r += getMaxSumOf( root->right );
        }

        // Choose no way to go...
        int n = root->val;

        // Update the final result!!
        this->mps = max( this->mps, l + r - n );
        this->mps = max( this->mps, l );
        this->mps = max( this->mps, r );
        this->mps = max( this->mps, n );

        return max3(l, r, n);
    }

    int max3(int a, int b, int c) {
        return max( a, max( b, c ) );
    }

private:
    int mps;
};


int main() {
    return 0;
}