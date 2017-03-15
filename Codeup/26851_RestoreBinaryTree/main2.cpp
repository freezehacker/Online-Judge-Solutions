// Restore a binary tree.
// Codeup link: http://codeup.cn/problem.php?cid=100001103&pid=2
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


struct Node {
	int element;
	Node* left, *right;

	Node() : left(NULL), right(NULL) {}

	Node(int ele, Node* l = NULL, Node* r = NULL) : element(ele), left(l), right(r) {}
};


class BTree {
public:
	BTree(Node* root = NULL) {
		this->root = root;
		isPreFirst = isPostFirst = true;
	}

	~BTree() {
		destroy_tree(root);
	}

	void preTraverse()  {
		pre_order_traverse(root);
	}

	void postTraverse()  {
		post_order_traverse(root);
	}

private:
	Node* root;
	bool isPreFirst;
	bool isPostFirst;
	

	void pre_order_traverse(Node* tree) {
		if (tree == NULL) return;

		if (isPreFirst) {
			isPreFirst = false;
			cout << tree->element;
		} else {
			cout << " " << tree->element;
		}

		pre_order_traverse(tree->left);
		pre_order_traverse(tree->right);
	}

	void post_order_traverse(Node* tree) {
		if (tree != NULL) {
			post_order_traverse(tree->left);
			post_order_traverse(tree->right);

			if (isPostFirst) {
				isPostFirst = false;
				cout << tree->element;
			} else {
				cout << " " << tree->element;
			}
		}
	}

	void destroy_tree(Node* &tree) {
		// Must destroy a tree in POST ORDER!
		if (tree != NULL) {
			destroy_tree(tree->left);
			destroy_tree(tree->right);
			delete tree;
		}
	}
};


const int MAX_NODE_NUM = 30;
const int CASE_NUM = 1;
int levelOrder[MAX_NODE_NUM], inOrder[MAX_NODE_NUM], nodenum;
bool isVisited[MAX_NODE_NUM + 1];


void createTree(Node* &generatedTree, int inLeft, int inRight) {
	if (inRight <= inLeft) return;

	// Find the first that hasn't been visited
	int idx = -1;
	bool breakAll = false;
	for (int i = 0; i < nodenum && !breakAll; ++i) if (!isVisited[levelOrder[i]]) {
		// Make sure it's in the given range of IN ORDER.
		for (int j = inLeft; j < inRight && !breakAll; ++j) {
			if (inOrder[j] == levelOrder[i]) {
				idx = j;
				isVisited[levelOrder[i]] = true;
				generatedTree = new Node(levelOrder[i]);

				breakAll = true;
				break;
			}
		}	
	}

	createTree(generatedTree->left, inLeft, idx);
	createTree(generatedTree->right, idx + 1, inRight);
}


void init() {
	//isPostFirst = isPreFirst = true;
	memset(isVisited, false, sizeof(isVisited));
}


int main() {
	ifstream cin("in");

	int casenum = CASE_NUM;
	while (casenum--) {

		cin >> nodenum;
		init();
		for (int i = 0; i < nodenum; ++i) {
			cin >> levelOrder[i];
		}
		for (int i = 0; i < nodenum; ++i) {
			cin >> inOrder[i];
		}


		Node* root = NULL;
		createTree(root, 0, nodenum);
		BTree* tree = new BTree(root);


		tree->preTraverse();
		cout << endl;
		tree->postTraverse();
		cout << endl;

		delete tree;
	}

	return 0;
}
