#include <iostream>
#include <fstream>
#include <set>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

const int MAX_N = 10001;
const int CASE_NUM = 1;
vector<int> edges[MAX_N];
bool isVisited[MAX_N];
int number[MAX_N];
int nodeNum;
int father[MAX_N];

struct Node {
	int step;
	int n;

	Node() {}
	Node(int n, int step) : n(n), step(step) {}
};

void init() {
	for (int i = 0; i < MAX_N; ++i) {
		father[i] = i;
	}
}

int getRoot(int x) {
	if (father[x] == x) {
		return x;
	} else {
		return father[x] = getRoot(father[x]);
	}
}

void setUnion(int x, int y) {
	int xx = getRoot(x);
	int yy = getRoot(y);
	if (xx != yy) {
		father[xx] = yy;
	}
}

int bfs(int n) {
	queue<Node> Q;
	Q.push(Node(n, 1));
	isVisited[n] = true;
	int maxLength = -1;
	while (!Q.empty()) {
		Node curNode = Q.front();
		Q.pop();
		maxLength = max(maxLength, curNode.step);
		for (int i = 0, len = edges[curNode.n].size(); i < len; ++i) {
			const int adjacentNode = edges[curNode.n].at(i);
			if (!isVisited[adjacentNode]) {
				Q.push(Node(adjacentNode, curNode.step + 1));
				isVisited[adjacentNode] = true;
			}
		}
	}
	return maxLength;
}


int main() {
	//ifstream cin("in");

	int caseNum = CASE_NUM;
	while (caseNum--) {
		cin >> nodeNum;

		init();

		for (int i = 1; i < nodeNum; ++i) {
			int a, b;
			cin >> a >> b;
			edges[a].push_back(b);
			edges[b].push_back(a);
			setUnion(a, b);
		}

		set<int> roots;
		for (int i = 1; i <= nodeNum; ++i) {
			roots.insert(getRoot(i));
		}
		int rootNum = roots.size();
		if (rootNum != 1) {
			cout << "Error: " << rootNum << " components" << endl;
			continue;
		}

		int maxLength = -1;
		for (int i = 1; i <= nodeNum; ++i) {
			memset(isVisited, false, sizeof(isVisited));
			number[i] = bfs(i);
			maxLength = max(maxLength, number[i]);
		}

		for (int i = 1; i <= nodeNum; ++i) {
			if (number[i] == maxLength) {
				cout << i << endl;
			}
		}
	}
	return 0;
}
