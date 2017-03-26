// Author:
// https://leetcode.com/derekhh/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void fooLeaves(TreeNode* root, vector<int>& ans) {
        if (root) {
            fooLeaves(root -> left, ans);
            if (root -> left == NULL && root -> right == NULL) {
                ans.push_back(root -> val);
            }
            fooLeaves(root -> right, ans);
        }
    }
    
    void fooBoundaryLeft(TreeNode* root, vector<int>& ans) {
        if (root) {
            if (root -> left) {
                ans.push_back(root -> val);
                fooBoundaryLeft(root -> left, ans);
            } else if (root -> right) {
                ans.push_back(root -> val);
                fooBoundaryLeft(root -> right, ans);
            }
        }
    }
    
    void fooBoundaryRight(TreeNode* root, vector<int>& ans) {
        if (root) {
            if (root -> right) {
                fooBoundaryRight(root -> right, ans);
                ans.push_back(root -> val);
            } else if (root -> left) {
                fooBoundaryRight(root -> left, ans);
                ans.push_back(root -> val);
            }
        }
    }
    
    void fooBoundary(TreeNode* root, vector<int>& ans) {
        if (root) {
            ans.push_back(root -> val);
            fooBoundaryLeft(root -> left, ans);
            fooLeaves(root -> left, ans);
            fooLeaves(root -> right, ans);
            fooBoundaryRight(root -> right, ans);
        }
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans;
        fooBoundary(root, ans);
        return ans;
    }
};