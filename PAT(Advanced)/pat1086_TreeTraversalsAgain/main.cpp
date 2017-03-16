#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;

struct Node {
    int element;
    Node* left;
    Node* right;

    Node(int element = -1, Node* left = NULL, Node* right = NULL) 
        : element(element), left(left), right(right) {}
};

void postOrderTraverse(Node* tree, vector<int> &postOrder) {
    if (tree) {
        postOrderTraverse(tree->left, postOrder);
        postOrderTraverse(tree->right, postOrder);
        postOrder.push_back(tree->element);
    }
}

Node* createTree(queue<int> &commands) {
    int cur = commands.front();
    commands.pop();

    if (cur == 0) {
        return NULL;
    }

    Node* curNode = new Node(cur);

    if (!commands.empty()) {
        curNode->left = createTree(commands);
    }

    if (!commands.empty()) {
        curNode->right = createTree(commands);
    }

    return curNode;
}

void destroyTree(Node* &tree) {
    if (tree) {
        destroyTree(tree->left);
        destroyTree(tree->right);
        delete tree;
        tree = NULL;
    }
}


int main() {
    //ifstream cin("in.txt");

    int nodeNum;
    cin >> nodeNum;
    nodeNum *= 2;

    queue<int> commands;
    while (nodeNum--) {
        string op;
        cin >> op;
        if (op == "Push") {
            int nodeIndex;
            cin >> nodeIndex;
            commands.push(nodeIndex);  // Positive integer means element of a node.
        } else if (op == "Pop") {
            commands.push(0);  // "0" means null(not a node here).
        } 
    }

    Node* tree = createTree(commands);

    vector<int> resultList;
    postOrderTraverse(tree, resultList);

    for (int i = 0, len = resultList.size(); i < len; ++i) {
        cout << resultList[i];
        cout << (i == len - 1 ? "\n" : " ");
    }

    destroyTree(tree);

    return 0;
}
