/*// Restore a binary tree.
// Codeup link: http://codeup.cn/problem.php?cid=100001103&pid=2
#include <iostream>
//#include <vector>
#include <fstream>	// ifstream (for testing)
#include <cstring>	// memset
using namespace std;

struct Node;
void pre_order_traverse(Node* tree);
void post_order_traverse(Node* tree);

typedef struct Node {
public:
	int element;
	Node* left, *right;


	Node() : left(NULL), right(NULL) {}

	Node(int ele, Node* l = NULL, Node* r = NULL) : element(ele), left(l), right(r) {}

	void preTraverse()  {
		pre_order_traverse(this);
	}

	void postTraverse()  {
		post_order_traverse(this);
	}
} Node, *BTree;


const int MAX_NODE_NUM = 30;
const int CASE_NUM = 1;
int levelOrder[MAX_NODE_NUM], inOrder[MAX_NODE_NUM], nodenum;
bool isPreFirst = true, isPostFirst = true;	// Control the first output in the recursion.
bool isVisited[MAX_NODE_NUM + 1];


void pre_order_traverse(Node* tree) {	// (Const method)
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


void post_order_traverse(Node* tree) {	// (Const method)
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


// (Non-const method, so use a reference, or use a returned value.)
void createTree(Node* &generatedTree, int inLeft, int inRight) {

	if (inRight <= inLeft) return;

	// Find the first that hasn't been visited
	int element = -1;
	for (int i = 0; i < nodenum; ++i) {
		int elementBFS = levelOrder[i];
		if (!isVisited[elementBFS]) {
			isVisited[elementBFS] = true;
			generatedTree = new Node(elementBFS);
			element = elementBFS;
		}
	}
	if (element == -1) return;

	
	// Find it in the IN ORDER
	int idx = -1;
	for (int i = 0; i < nodenum; ++i) {
		if (inOrder[i] == element) {
			idx = i;
			break;
		}
	}

	createTree(generatedTree->left, inLeft, idx);
	createTree(generatedTree->right, idx + 1, inRight);
}


// (Non-const method, so use a reference.)
void destroyTree(Node* &tree) {
	// Must destroy a tree in POST ORDER!
	if (tree != NULL) {
		destroyTree(tree->left);
		destroyTree(tree->right);
		delete tree;
	}
}


void init() {
	isPostFirst = isPreFirst = true;
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

		Node* tree = NULL;
		createTree(tree, 0, nodenum);

		tree->preTraverse();
		cout << endl;
		tree->postTraverse();
		cout << endl;

		destroyTree(tree);	// Release the heap memory!
	}

	return 0;
}
*/