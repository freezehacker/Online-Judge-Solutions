#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <cstdlib>
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
    string _serialize() {
        return serialize(__root);
    }

    void _deserialize(string data) {
        __root = deserialize(data);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // Special case.
        if (!root) {
            return "[]";
        }

        // BFS
        vector<string> tmpResult;
        queue<TreeNode*> nodes;
        nodes.push( root );
        while ( !nodes.empty() ) {
            TreeNode* node = nodes.front();
            nodes.pop();

            if (node == NULL) {
                tmpResult.push_back( "null" );
                continue;
            }
            tmpResult.push_back( std::to_string( node->val ) );
            nodes.push( node->left );
            nodes.push( node->right );
        }

        // Remove the 'null's at the end.
        while ( tmpResult.at( tmpResult.size() - 1 ) == "null" ) {
            tmpResult.pop_back();
        }

        // Translate into string type.
        string result;
        result += "[";
        for (int i = 0, size = tmpResult.size(); i < size; ++i) {
            if (i != 0) {
                result += ",";
            }
            result += tmpResult.at( i );
        }
        result += "]";
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // Special case.
        if (data == "[]") {
            return NULL;
        }

        vector<string> strings = split( data.substr( 1, data.size() - 1 ), ',' );
        int k = 0;

        // Create the root.
        TreeNode* root = new TreeNode( atoi( strings[k++].c_str() ) );
        queue<TreeNode*> nodes;
        nodes.push( root );

        // BFS
        while ( !nodes.empty() ) {
            TreeNode* node = nodes.front();
            nodes.pop();

            if ( k < strings.size() ) {
                if ( strings[k] != "null" ) {
                    node->left = new TreeNode( atoi( strings[k].c_str() ) );
                    nodes.push( node->left );
                }
                k++;
            }

            if ( k < strings.size() ) {
                if ( strings[k] != "null" ) {
                    node->right = new TreeNode( atoi( strings[k].c_str() ) );
                    nodes.push( node->right );
                }
                k++;
            }
        }

        // Return the root.
        return root;
    }

    vector<string> split(string s, char delim) {
        vector<string> ret;
        string curString;
        for (int i = 0, size = s.size(); i < size; ++i) {
            if ( s[i] != delim ) {
                curString.push_back( s[i] );
            } else {
                ret.push_back( curString );
                curString = "";
            }
        }
        ret.push_back( curString );
        return ret;
    }
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
    string data = "[1,2,3,null,null,4,5]";
    tree._deserialize(data);
    cout << tree._serialize() << endl;

    return 0;
}