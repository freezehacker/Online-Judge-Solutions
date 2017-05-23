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
    int countNodes(TreeNode* root) {
        if ( !root ) return 0;

        TreeNode* l = root;
        int lHeight = 0;
        for ( ; l; l = l->left ) ++lHeight;

        TreeNode* r = root;
        int rHeight = 0;
        for ( ; r; r = r->right ) ++rHeight;

        if ( lHeight == rHeight ) {
            return pow( 2, lHeight ) - 1;   // Iterative(which actually lessens time cost)
        } else {
            return 1 + countNodes( root->left ) + countNodes( root->right );    // Recursive
        }
    }
};


int main() {
    return 0;
}