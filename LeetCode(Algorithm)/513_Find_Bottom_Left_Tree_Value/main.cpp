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
    int findBottomLeftValue(TreeNode* root) {
        queue<LevelNode> levelNodes;
        levelNodes.push( LevelNode( root, 0 ) );
        int result = -1;
        int level = -1;
        while ( !levelNodes.empty() ) {
            LevelNode thisNode = levelNodes.front();
            levelNodes.pop();

            if (thisNode.level > level) {
                result = thisNode.node->val;
                level = thisNode.level;
            }

            if (thisNode.node->left) {
                levelNodes.push( LevelNode( thisNode.node->left, thisNode.level + 1 ) );
            }
            if (thisNode.node->right) {
                levelNodes.push( LevelNode( thisNode.node->right, thisNode.level + 1 ) );
            }
        }
        return result;
    }
private:
    struct LevelNode {
        int level;
        TreeNode* node;
        LevelNode(TreeNode* node, int level) : node(node), level(level) {}
    };
};
