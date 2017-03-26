#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>  // memset
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        // Special case: when the tree has no even a node.
        if (!root) {
            vector<int> empty;
            return empty;
        }


        /* 1.DFS, to get all the leaf nodes. */
        vector<TreeNode*> leafNodes;
        if (!root->left) {  // If the whole tree has no left subtree..
            leafNodes.push_back(root);  // then the root itself is the left-most node.
        }

        dfs_leaf(root, leafNodes);  // Get all the (real) leaf nodes.

        if (!root->right) { // Also if the whole tree has no right subtree..
            leafNodes.push_back(root);  // then the root itself is the right-most node.
        }



        /* 2.DFS, to get the path of left boundary. */
        vector<TreeNode*> leftBoundary;
        dfsEnd = false;
        dfs(root, leafNodes[0], leftBoundary);  // Here, leafNodes[0] is the left-most node.

        /* 3.Also DFS, to get the path of right boundary. */
        vector<TreeNode*> rightBoundary;
        dfsEnd = false;
        dfs(root, leafNodes[leafNodes.size() - 1], rightBoundary); // Here, leafNodes[-1] is the right-most node.



        /* 4.Merge the result, and remove the duplicate ones. */
        vector<int> ret;
        for (int i = 0, len = leftBoundary.size(); i < len; ++i) {
            if ( !existed[ leftBoundary[i] ] ) {
                ret.push_back( leftBoundary[i]->val );
                existed[ leftBoundary[i] ] = true;
            }
        }
        for (int i = 0, len = leafNodes.size(); i < len; ++i) {
            if ( !existed[ leafNodes[i] ] ) {
                ret.push_back( leafNodes[i]->val );
                existed[ leafNodes[i] ] = true;
            }
        }
        for (int i = rightBoundary.size() - 1; i >= 0; --i) {
            if ( !existed[ rightBoundary[i] ] ) {
                ret.push_back( rightBoundary[i]->val );
                existed[ rightBoundary[i] ] = true;
            }
        }
        return ret;
    }

private:
    // Store the address, to mark which is visited.
    // (Because the val is not unique for each node.)
    map<TreeNode*, bool> existed;

    
    /**
    * Get the path from root to the target.
    */
    bool dfsEnd;    // The flag that controls the terminal of DFS.
    void dfs(TreeNode* root, TreeNode* target, vector<TreeNode*> &already) {
        if (root) {
            already.push_back(root);

            if (root == target) {
                dfsEnd = true;
                return;
            }

            if (!dfsEnd) {
                dfs(root->left, target, already);
            }
            if (!dfsEnd) {
                dfs(root->right, target, already);
            }

            // Backtrack
            if (!dfsEnd) {
                already.pop_back();
            }
        }
    }

    /**
    * Get all the leaf nodes.
    */
    void dfs_leaf(TreeNode *root, vector<TreeNode*> &leafValues) {
        if (root) {
            if (!root->left && !root->right) {  // If it's a boundary, then add it.
                leafValues.push_back(root);
            } else {
                dfs_leaf(root->left, leafValues);
                dfs_leaf(root->right, leafValues);
            }
        }
    }
};


int main() {

}
