class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;

        if (!root) {
            return result;
        }

        queue<LevelNode> levelNodes;
        levelNodes.push( LevelNode(0, root) );
        int maxValue, lastLevel = 0;
        while (!levelNodes.empty()) {
            LevelNode curNode = levelNodes.front();
            levelNodes.pop();

            if (curNode.level == lastLevel) {
                if (curNode.level == 0) {
                    maxValue = curNode.node->val;
                } else {
                    maxValue = max(maxValue, curNode.node->val);
                }
            } else {
                result.push_back(maxValue);
                lastLevel = curNode.level;
                maxValue = curNode.node->val;
            }

            if (curNode.node->left) {
                levelNodes.push( LevelNode(curNode.level + 1, curNode.node->left) );
            }
            if (curNode.node->right) {
                levelNodes.push( LevelNode(curNode.level + 1, curNode.node->right) );
            }
        }
        // Don't miss the last-level max element.
        result.push_back(maxValue);

        return result;
    }
private:
    struct LevelNode {
        TreeNode* node;
        int level;

        LevelNode(int level, TreeNode* node=NULL): node(node), level(level) {}
    };
};