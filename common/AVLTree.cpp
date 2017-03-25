#include <iostream>
#include <fstream>
#include <cmath>    // max
#include <queue>    // bfs(level traverse)
#include <vector>
using namespace std;

struct Node {
    int element;
    Node* left;
    Node* right;
    int height;
    int count;  // In case of duplicate.

    Node(int e, Node* l=NULL, Node* r=NULL): element(e), left(l), right(r) {
        height = 0;
        count = 0;
    }
};

class AVLTree {
public:
    AVLTree() : __root(NULL) {}

    ~AVLTree() {
        destroy(__root);
    }

    void insert(int newElement) {
        __insert(__root, newElement);
    }

    void inOrder() const {
        cout << "in-order: ";
        __inOrder(__root);
        cout << endl;
    }

    void levelOrder() const {
        cout << "level-order: ";
        __levelOrder(__root);
        cout << endl;
    }

    void getInOrder(vector<int> &V) {
        __getInOrder(__root, V);
    }

    int height() const {
        return __height(__root);
    }

private:
    Node* __root;

    void __leftRotation(Node* &root) {
        Node* k1 = root->left;
        root->left = k1->right;
        k1->right = root;

        // Update the height of k1 and root
        k1->height = 1 + max( __height(k1->left), __height(k1->right) );
        root->height = 1 + max( __height(root->left), __height(root->right) );

        // Finally k1 becomes the root!
        root = k1;
    }

    void __rightRotation(Node* &root) {
        Node* k2 = root->right;
        root->right = k2->left;
        k2->left = root;

        k2->height = 1 + max( __height(k2->left), __height(k2->right) );
        root->height = 1 + max( __height(root->left), __height(root->right) );

        root = k2;
    }

    void __leftRightRotation(Node* &root) {
        __rightRotation(root->left);
        __leftRotation(root);
    }

    void __rightLeftRotation(Node* &root) {
        __leftRotation(root->right);
        __rightRotation(root);
    }

    void __insert(Node* &tree, int newElement) {
        if (!tree) {
            tree = new Node(newElement);
        } else {
            if (newElement < tree->element) {
                __insert(tree->left, newElement);   // recursive insertion
                if ( __height(tree->left) - __height(tree->right) >= 2 ) {  // if lose balance
                    if (newElement < tree->left->element) { // left
                        __leftRotation(tree);
                    } else {                                // left-right
                        __leftRightRotation(tree);
                    }
                }
            } else if (newElement > tree->element) {
                __insert(tree->right, newElement);
                if ( __height(tree->right) - __height(tree->left) >= 2 ) {
                    if (newElement > tree->right->element) {
                        __rightRotation(tree);
                    } else {
                        __rightLeftRotation(tree);
                    }
                }
            } else {
                ++(tree->count);
            }
        }

        // Update the height of the new root
        tree->height = 1 + max( __height(tree->left), __height(tree->right) );
    }

    void __insert_v2(Node* &tree, int newElement) {
        if (!tree) {
            tree = new Node(newElement);
        } else if (newElement < tree->element) {
            __insert_v2(tree->left, newElement);
        } else if (newElement == tree->element) {
            tree->count += 1;
        } else {
            __insert_v2(tree->right, newElement);
        }
    }

    void __inOrder(Node* root) const {
        if (root) {
            __inOrder(root->left);
            cout << " " << root->element;
            __inOrder(root->right);
        }
    }

    int __height(Node* root) const {
        if (!root)
            return 0;
        else
            return root->height;
    }

    void destroy(Node* &tree) {
        if (tree) {
            destroy(tree->left);
            destroy(tree->right);
            delete tree;
            tree = NULL;
        }
    }

    void __getInOrder(Node* tree, vector<int> &V) const {
        __getInOrder(tree->left, V);
        V.push_back(tree->element);
        __getInOrder(tree->right, V);
    }

    void __levelOrder(Node* tree) const {
        queue<Node*> Q;
        Q.push(tree);

        while (!Q.empty()) {
            Node* curNode = Q.front();
            Q.pop();
            if (curNode) {
                cout << " " << curNode->element;
            } else {
                cout << " -1";
            }

            if (curNode) {
                Q.push(curNode->left);
                Q.push(curNode->right);
            }
        }
    }
};


int main() {
    AVLTree tree;

    //vector<int> tmpVector;

    tree.insert(7);
    tree.inOrder();
    tree.levelOrder();
    cout << "Height: " << tree.height() << endl;

    tree.insert(9);
    tree.inOrder();
    tree.levelOrder();
    cout << "Height: " << tree.height() << endl;

    tree.insert(10);
    tree.inOrder();
    tree.levelOrder();
    cout << "Height: " << tree.height() << endl;

    tree.insert(12);
    tree.inOrder();
    tree.levelOrder();
    cout << "Height: " << tree.height() << endl;

    cout << endl;

    tree.insert(100);
    tree.inOrder();
    tree.levelOrder();
    cout << "Height: " << tree.height() << endl;

    tree.insert(-1);
    tree.inOrder();
    tree.levelOrder();
    cout << "Height: " << tree.height() << endl;


    return 0;
}
