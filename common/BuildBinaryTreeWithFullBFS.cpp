/**
*
*  [Pre-order, post-order, level-order] with in-order can build a binary tree.
* 
*  "Full" any-order can also build a tree,
*     and actually the building process is very similar with the traversal process.
*
*  This demo is about "full level-order",
*    so full pre-order, full post-order, full in-order can also be deducted.
*
*/

#define DEBUG_MODE 1

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

const int NULL_NODE = -1;   // Which means no node here.

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
                __root = new Node(fullLevelOrder[idx++]);
            }
        }
        queue<Node*> nodes;
        nodes.push( __root );

        // bfs
        while (!nodes.empty()) {
            Node* curNode = nodes.front();
            nodes.pop();

            if (idx < fullLevelOrder.size()) {
                // add left child
                int leftChildValue = fullLevelOrder[idx++];
                if (leftChildValue != NULL_NODE) {
                    curNode->left = new Node(leftChildValue);
                    nodes.push(curNode->left);
                }
            }
            
            if (idx < fullLevelOrder.size()) {
                // add right child
                int rightChildValue = fullLevelOrder[idx++];
                if (rightChildValue != NULL_NODE) {
                    curNode->right = new Node(rightChildValue);
                    nodes.push(curNode->right);
                }
            }
            
        }
    }

    void inTraverse(vector<int> &inOrder) const {

    }

    void preTraverse(vector<int> &preOrder) const {

    }

    void postTraverse(vector<int> &postOrder) const {

    }

    void levelTraverse(vector<int> &levelOrder) const {
        queue<Node*> nodes;
        nodes.push(__root);
        while (!nodes.empty()) {
            // current
            Node* curNode = nodes.front();
            nodes.pop();
            levelOrder.push_back(curNode->value);

            // next
            if (curNode->left) {
                nodes.push(curNode->left);
            }
            if (curNode->right) {
                nodes.push(curNode->right);
            }
        }
    }

    void fullLevelTraverse(vector<int> &levelOrder) const {
        queue<Node*> nodes;
        nodes.push(__root);
        while (!nodes.empty()) {
            // current
            Node* curNode = nodes.front();
            nodes.pop();
            if (curNode) {
                levelOrder.push_back(curNode->value);
            } else {
                levelOrder.push_back(NULL_NODE);
            }

            // next
            if (curNode) {
                nodes.push(curNode->left);
                nodes.push(curNode->right);
            }
        }
    }

private:
    struct Node {
        int value;
        Node* left, *right;

        Node(int v, Node* l=NULL, Node* r=NULL): value(v), left(l), right(r) {}
    };

    Node* __root;

private:
    void __destroy(Node* &root) {
        if (root) {
            __destroy(root->right);
            __destroy(root->left);
            delete root;
            root = NULL;
        }
    }

    void __inTraverse(Node* root, vector<int> &inOrder) const {

    }

    void __preTraverse(Node* root, vector<int> &preOrder) const {

    }

    void __postTraverse(Node* root, vector<int> &postOrder) const {

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
#if DEBUG_MODE == 1
    ifstream cin("in.txt");
#endif

    int x;
    vector<int> seq;
    while (cin >> x) {
        seq.push_back(x);
    }

    cout << "Given full level-order sequence: " << endl;
    printVector(seq);

    // Build tree.
    BTree tree;
    tree.buildFromFullLevelOrder(seq);

    vector<int> levelOrder;
    tree.levelTraverse(levelOrder);
    cout << "Level traverse: " << endl;
    printVector(levelOrder);

    vector<int> fullLevelOrder;
    tree.fullLevelTraverse(fullLevelOrder);
    cout << "Full level traverse(should be the same as given one): " << endl;
    printVector(fullLevelOrder);


    return 0;
}
