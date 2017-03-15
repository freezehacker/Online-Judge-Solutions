// 1004. Counting Leaves (30)
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;


struct Node {
	int number;
	int level;

	Node(int n, int l) : number(n), level(l) {}

	friend ostream& operator<<(ostream& out, const Node& node) {
		out << "Node[" << node.number << ", " << node.level << "]";
		return out;
	}
};


const int MAX_NODE_NUM = 100;
const int CASE_NUM = 1;
bool pedigree[MAX_NODE_NUM][MAX_NODE_NUM];


bool isLeafNode(int node) {
	for (int i = 1; i < MAX_NODE_NUM; ++i) {
		if (pedigree[node][i]) {
			return false;
		}
	}
	return true;
}


void bfs() {
	queue<Node> Q;
	vector<int> results;
	bool visited[MAX_NODE_NUM];
	memset(visited, false, sizeof(visited));

	// Start from root node '01'.
	Q.push(Node(1, 0));
	visited[1] = true;
	int lastLevel = 0;
	int sum = 0;
	while (!Q.empty()) {
		Node curNode = Q.front();
		Q.pop();

		// If it's a leaf node, then count it.
		if (isLeafNode(curNode.number)) {
			if (curNode.level == lastLevel) {
				++sum;
			} else {
				results.push_back(sum);
				sum = 1;	// Reset the counter.
			}
		} else {	// If it's a non-leaf one...

			if (curNode.level != lastLevel) {
				results.push_back(sum);
			}

			// Add its sons to the queue.
			for (int i = 1; i < MAX_NODE_NUM; ++i) {
				if (pedigree[curNode.number][i]) {
					Node newNode(i, curNode.level + 1);
					Q.push(newNode);
				}
			}
		}
		lastLevel = curNode.level;
	}
	results.push_back(sum);

	// Print the results.
	for (int i = 0, len = results.size(); i < len; ++i) {
		if (i == len - 1) {
			cout << results[i] << endl;
		} else {
			cout << results[i] << " ";
		}
	}
}


int main() {
	ifstream cin("in");

	int numOfCases = CASE_NUM;
	while (numOfCases--) {
		memset(pedigree, false, sizeof(pedigree));

		int numOfNode, numOfNonLeafNode;
		cin >> numOfNode >> numOfNonLeafNode;
		for (int i = 0; i < numOfNonLeafNode; ++i) {
			int parent, numOfSon;
			cin >> parent >> numOfSon;
			for (int j = 0; j < numOfSon; ++j) {
				int son;
				cin >> son;
				pedigree[parent][son] = true;
			}
		}

		bfs();
	}

	return 0;
}
