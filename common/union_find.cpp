#include <iostream>
#include <fstream>
using namespace std;

const int MAX_N = 1001;
int root[MAX_N];

void init_union_set()  {
	for (int i = 0; i < MAX_N; ++i) {
		root[i] = i;	// Initialized to -1 or itself.
	}
}

// While
int get_root_v1(int x) {
	int xx = x;
	while (root[x] != x) {
		x = root[x];
	}
	// Compress path.
	return root[xx] = x;
}

// Recursive
int get_root_v2(int x) {
	if (root[x] == x) {
		return root[x];
	} else {
		return root[x] = get_root_v2(root[x]);
	}
}

bool is_same_root(int x, int y) {
	int xx = get_root(x);
	int yy = get_root(y);
	return xx == yy;
}

void union_set(int x, int y) {
	int xx = get_root(x);
	int yy = get_root(y);
	if (xx != yy) {
		root[xx] = yy;	// Or, root[xx] = yy ?
	}
}


int main() {

}
