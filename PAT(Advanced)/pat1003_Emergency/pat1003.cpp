// Dijkstra
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAXN = 501;
const int INF = 0x3f3f3f3f;
int graph[MAXN][MAXN], dist[MAXN];
bool visited[MAXN];
int path_count[MAXN];	// answer 1
int point_weight[MAXN], point_weight_sum[MAXN];	// answer 2
int start, cityNum;

void init() {
	memset(visited, false, sizeof(visited));
	memset(dist, 0x3f, sizeof(dist));
	for (int i = 0; i < MAXN; ++i) {
		for (int j = 0; j < MAXN; ++j) {
			graph[i][j] = INF;
		}
	}
	for (int i = 0; i < MAXN; ++i) {
		path_count[i] = 1;
	}
}

void dijkstra() {
	// Initialization for the starting point.
	for (int i = 0; i < cityNum; ++i) {
		dist[i] = graph[start][i];
		if (dist[i] != INF && i != start) {
			point_weight_sum[i] += point_weight[start];
		}
	}
	visited[start] = true;


	int loop = cityNum - 1;
	while (loop--) {
		int minIndex = -1;
		int minValue = INF;
		for (int i = 0; i < cityNum; ++i) {
			if (!visited[i]) {
				if (dist[i] < minValue) {
					minValue = dist[i];
					minIndex = i;
				}
			}
		}

		if (minIndex == -1) break;

		visited[minIndex] = true;	// Mark it already visited.
		for (int j = 0; j < cityNum; ++j) {
			if (!visited[j]) {
				if (minValue + graph[minIndex][j] < dist[j]) {

					dist[j] = minValue + graph[minIndex][j];
					path_count[j] = path_count[minIndex];
					point_weight_sum[j] = point_weight_sum[minIndex] + point_weight[j];

				} else if (minValue + graph[minIndex][j] == dist[j]) {	// Important case!

					path_count[j] += path_count[minIndex];
					if (point_weight_sum[minIndex] + point_weight[j] > point_weight_sum[j]) {
						point_weight_sum[j] = point_weight_sum[minIndex] + point_weight[j];
					}

				}
			}
		}
	}
}


int main() {

	//ifstream cin("pat1003.in");

	init();

	int roadNum, end;
	cin >> cityNum >> roadNum >> start >> end;
	for (int i = 0; i < cityNum; ++i) {
		cin >> point_weight[i];
		point_weight_sum[i] = point_weight[i];
	}
	for (int i = 0; i < roadNum; ++i) {
		int from, to, length;
		cin >> from >> to >> length;
		graph[from][to] = graph[to][from] = length;
	}

	dijkstra();

	cout << path_count[end] << " " << point_weight_sum[end] << endl;

	return 0;
}
