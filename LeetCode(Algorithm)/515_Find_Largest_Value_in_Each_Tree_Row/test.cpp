#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

const int NULL_NODE = -1;   // Which means no node here.


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class BTree {
public:
    BTree(): __root(NULL) {}

    ~BTree() {
        __destroy(__root);  // Remember to release the heap memory!
    }

    void buildFromFullLevelOrder(const vector<int> &fullLevelOrder) {
        // Destroy current tree
        __destroy(__root);


        // Create root
        int idx = 0;
        if (idx < fullLevelOrder.size()) {
            if (fullLevelOrder[idx] != NULL_NODE) {
                __root = new TreeNode(fullLevelOrder[idx++]);
            }
        }
        queue<TreeNode*> nodes;
        nodes.push( __root );

        // bfs
        while (!nodes.empty()) {
            TreeNode* curNode = nodes.front();
            nodes.pop();

            if (idx < fullLevelOrder.size()) {
                // add left child
                int leftChildValue = fullLevelOrder[idx++];
                if (leftChildValue != NULL_NODE) {
                    curNode->left = new TreeNode(leftChildValue);
                    nodes.push(curNode->left);
                }
            }
            
            if (idx < fullLevelOrder.size()) {
                // add right child
                int rightChildValue = fullLevelOrder[idx++];
                if (rightChildValue != NULL_NODE) {
                    curNode->right = new TreeNode(rightChildValue);
                    nodes.push(curNode->right);
                }
            }
            
        }
    }

    vector<int> levelTraverse() const {
        vector<int> levelOrder;

        queue<TreeNode*> nodes;
        nodes.push(__root);
        while (!nodes.empty()) {
            // current
            TreeNode* curNode = nodes.front();
            nodes.pop();
            levelOrder.push_back(curNode->val);

            // next
            if (curNode->left) {
                nodes.push(curNode->left);
            }
            if (curNode->right) {
                nodes.push(curNode->right);
            }
        }

        return levelOrder;
    }

    vector<int> fullLevelTraverse() const {
        vector<int> levelOrder;

        queue<TreeNode*> nodes;
        nodes.push(__root);
        while (!nodes.empty()) {
            // current
            TreeNode* curNode = nodes.front();
            nodes.pop();
            if (curNode) {
                levelOrder.push_back(curNode->val);
            } else {
                levelOrder.push_back(NULL_NODE);
            }

            // next
            if (curNode) {
                nodes.push(curNode->left);
                nodes.push(curNode->right);
            }
        }

        return levelOrder;
    }

private:
    TreeNode* __root;

private:
    void __destroy(TreeNode* &root) {
        if (root) {
            __destroy(root->right);
            __destroy(root->left);
            delete root;
            root = NULL;
        }
    }


public:
    vector<int> _largestValues() {
        return largestValues(__root);
    }

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


void printVector(const vector<int> &V) {
    for (int i = 0, size = V.size(); i < size; ++i) {
        cout << V[i];
        if (i == size - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
}


int main() {
    BTree tree;
    int arr[] = {1,3,2,5,3,NULL_NODE,9};
    tree.buildFromFullLevelOrder( vector<int>(arr, arr + 7) );   // [1,3,2,5,3,null,9]

    printVector( tree._largestValues() );

    return -0;
}