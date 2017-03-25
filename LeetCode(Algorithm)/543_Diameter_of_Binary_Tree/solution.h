/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**Input
[4,-7,-3,null,null,-9,-3,9,-7,-4,null,6,null,-6,
-6,null,null,0,6,5,null,9,null,null,-1,-4,null,null,null,-2]
*/

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int ret = -1;
        __dfs(root, ret);
        return ret;
    }
private:
    void __dfs(TreeNode* root, int &maxDiameter) {
        if (root) {
            int diameter = __getHeight(root->left) + __getHeight(root->right);
            maxDiameter = __getMax( maxDiameter, diameter );
            __dfs(root->left, maxDiameter);
            __dfs(root->right, maxDiameter);
        } else {
            maxDiameter = __getMax( maxDiameter, 0 );
        }
    }

    int __getHeight(TreeNode* root) const {
        if (!root) return 0;
        return 1 + __getMax( __getHeight(root->left), __getHeight(root->right) );
    }

    int __getMax(int a, int b) const {
        return a > b ? a : b;
    }
};
