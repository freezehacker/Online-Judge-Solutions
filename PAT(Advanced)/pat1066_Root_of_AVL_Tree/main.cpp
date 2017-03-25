#define DEBUG_MODE 0
#define CASE_NUM 1

#include <iostream>
#include <fstream>
using namespace std;

typedef int ElementType;    // Sorry that I'm too lazy to use template.

class AVLTree {
public:
    AVLTree(): __root(NULL) {}

    ~AVLTree() {
        __destroy(__root);
    }

    void insert(ElementType newElement) {
        __insert(__root, newElement);
    }

    ElementType getRoot() const {
        return __root->element;
    }

private:
    struct Node {
        ElementType element;
        int count;
        int height;
        Node* left, *right;

        Node(ElementType e, Node* l=NULL, Node* r=NULL)
        : element(e), left(l), right(r) {
            count = 1;
            //height = 1;
        }
    };

    Node* __root;

private:
    void __destroy(Node* &tree) {
        if (tree) {
            __destroy(tree->left);
            __destroy(tree->right);
            delete tree;
            tree = NULL;
        }
    }

    int __height(Node* tree) const {    // Deal with height of 'NULL'.
        if (tree == NULL) {
            return 0;
        }
        return tree->height;
    }

    void __insert(Node* &root, ElementType newElement) {
        if (!root) {
            root = new Node(newElement);
        } else {
            if (newElement < root->element) {

                __insert(root->left, newElement);

                if ( __height(root->left) - __height(root->right) >= 2 ) {
                    if (newElement < root->left->element) { // left left
                        __leftRotate(root);
                    } else {    // left right
                        __leftRightRotate(root);
                    }
                }

            } else if (newElement > root->element) {

                __insert(root->right, newElement);

                if ( __height(root->right) - __height(root->left) >= 2 ) {
                    if (newElement > root->right->element) {    // right right
                        __rightRotate(root);
                    } else {    // right left
                        __rightLeftRotate(root);
                    }
                }

            } else {

                root->count += 1;   // Repeated element.

            }
        }

        // Update height (from leaf to the root, by recursion).
        root->height = 1 + max( __height(root->left), __height(root->right) );
    }

    void __leftRotate(Node* &root) {
        Node* k1 = root->left;
        root->left = k1->right;
        k1->right = root;

        root->height = 1 + max( __height(root->left), __height(root->right) );
        k1->height = 1 + max( __height(k1->left), __height(k1->right) );

        root = k1;
    }

    void __rightRotate(Node* &root) {
        Node* k2 = root->right;
        root->right = k2->left;
        k2->left = root;

        root->height = 1 + max( __height(root->left), __height(root->right) );
        k2->height = 1 + max( __height(k2->left), __height(k2->right) );

        root = k2;
    }

    void __leftRightRotate(Node* &root) {
        __rightRotate(root->left);
        __leftRotate(root);
    }

    void __rightLeftRotate(Node* &root) {
        __leftRotate(root->right);
        __rightRotate(root);
    }
};


int main() {

#if DEBUG_MODE == 1
    ifstream cin("in.txt");
#endif

    int t = CASE_NUM;

    while (t--) {

        int num;
        cin >> num;

        AVLTree tree;

        for (int i = 0; i < num; ++i) {
            int x;
            cin >> x;
            tree.insert(x);
        }

        cout << tree.getRoot() << endl;

    }

    return 0;
}
