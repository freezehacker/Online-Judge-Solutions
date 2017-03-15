// To restore the tree or not, that's a question.
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;


struct Node {
	int element;
	Node* left;
	Node* right;

	Node() {
		element = -1;
		left = right = NULL;
	}

	Node(int e, Node* l = NULL, Node* r = NULL) {
		this->element = e;
		this->left = l;
		this->right = r;
	}
};


class BTree {
public:
	BTree() {
		root = NULL;
	}

	BTree(Node* node) {
		root = node;
	}

	~BTree() {
		clear(root);
	}

	// AKA "level-order traversal".
	vector<int> bfs() const {
		Node* tmp = root;
		vector<int> resultList;
		queue<Node*> Q;
		Q.push(tmp);
		while (!Q.empty()) {
			Node* curNode = Q.front();
			Q.pop();

			// current
			resultList.push_back(curNode->element);

			// next
			if (curNode->left != NULL) {
				Q.push(curNode->left);
			}
			if (curNode->right != NULL) {
				Q.push(curNode->right);
			}
		}
		return resultList;
	}

private:
	Node* root;

	void clear(Node* root) {
		if (root == NULL) return;
		clear(root->left);
		clear(root->right);
		delete root;
	}
};


const int CASE_NUM = 1;
const int MAX_NODE_NUM = 30;
int nodenum;
int postOrder[MAX_NODE_NUM], inOrder[MAX_NODE_NUM];


Node* buildTree(int postLeft, int postRight, int inLeft, int inRight) {
	if (inRight <= inLeft || postRight <= postLeft) return NULL;

	int rootElement = postOrder[postRight - 1];
	Node* ret = new Node(rootElement);
	int pos;
	for (int i = inLeft; i < inRight; ++i) {
		if (rootElement == inOrder[i]) {
			pos = i;
			break;
		}
	}
	int leftCount = pos - inLeft;
	int rightCount = inRight - pos;

	ret->left = buildTree(postLeft, postLeft + leftCount, inLeft, pos);
	ret->right = buildTree(postLeft + leftCount, postRight - 1, pos + 1, inRight);

	return ret;
}


int main() {
	//ifstream cin("in");

	int casenum = CASE_NUM;
	while (casenum--) {
		// Input 2 arrays of orders.
		cin >> nodenum;
		for (int i = 0; i < nodenum; ++i) {
			cin >> postOrder[i];
		}
		for (int i = 0; i < nodenum; ++i) {
			cin >> inOrder[i];
		}

		// Restore the tree.
		Node* root = buildTree(0, nodenum, 0, nodenum);
		BTree* bTree = new BTree(root);

		// Output the result.
		vector<int> levelOrder = bTree->bfs();
		for (int i = 0, len = levelOrder.size(); i < len; ++i) {
			cout << levelOrder[i];
			if (i == len - 1) {
				cout << endl;
			} else {
				cout << ' ';
			}
		}
	}

	return 0;
}
