// Union Find
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <set>
#include <map>
using namespace std;


struct Road {
	int left, right;

	Road(int l, int r) : left(l), right(r) {}
};


const int CASE_NUM = 1;
const int MAX_N = 1001;
int father[MAX_N];
bool existed[MAX_N];
vector<Road> roads;
int numOfCities;
map<int, int> answerMap;


int getRoot(int x) {
	if (father[x] != x) {
		father[x] = getRoot(father[x]);	// Compress path.
	}
	return father[x];
}

bool isSameUnion(int x, int y) {
	return getRoot(x) == getRoot(y);
}

void setUnion(int x, int y) {
	int xx = getRoot(x);
	int yy = getRoot(y);
	if (xx != yy) {
		father[xx] = yy;
	}
}

int getNumOfUnions() {
	set<int> fatherSets;
	for (int i = 1; i <= numOfCities; ++i) {
		if (existed[i]) {
			fatherSets.insert(getRoot(i));
		}
	}
	return fatherSets.size();
}

void solve(int except) {
	if (answerMap.count(except) != 0) {	// Cache shot!
		cout << answerMap[except] << endl;
		return;
	}


	memset(existed, false, sizeof(existed));
	for (int i = 1; i <= numOfCities; ++i) {
		father[i] = i;
		existed[i] = true;
	}
	existed[except] = false;

	for (int i = roads.size() - 1; i >= 0; --i) {
		int left = roads.at(i).left;
		int right = roads.at(i).right;
		if (left != except && right != except) {
			setUnion(left, right);
		}
	}

	int answer = getNumOfUnions() - 1;
	answerMap[except] = answer;	// Cache this answer.
	cout << answer << endl;
}


int main() {
	//ifstream cin("in");

	int numOfCases = CASE_NUM;
	while (numOfCases--) {
		roads.clear();
		answerMap.clear();

		int numOfRoads, numOfChecks;
		cin >> numOfCities >> numOfRoads >> numOfChecks;

		
		for (int i = 0; i < numOfRoads; ++i) {
			int a, b;
			cin >> a >> b;
			roads.push_back( Road(a, b) );
		}

		for (int i = 0; i < numOfChecks; ++i) {
			int toDelete;
			cin >> toDelete;

			solve(toDelete);
		}

	}
	return 0;
}
