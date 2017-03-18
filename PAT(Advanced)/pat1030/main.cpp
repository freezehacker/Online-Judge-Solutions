#include <iostream>
#include <fstream>
#include <cstring>  // memset
#include <vector>
#include <cmath>    // min
using namespace std;

const int MAX_POINT_NUM = 500;
const int INF = 0x3f3f3f3f;

// 'distance' conflicts...
namespace my_namespace {
    int distance[MAX_POINT_NUM][MAX_POINT_NUM];
};
int cost[MAX_POINT_NUM][MAX_POINT_NUM];
int numOfCity, numOfRoad, startIndex, endIndex;
int resultCost = -1;
vector<int> resultPath;

struct Node {
    int dist;
    bool visited;
    vector<int> lastNodeIndexes;
} cityList[MAX_POINT_NUM];


void reset() {
    resultCost = INF;
    resultPath.clear();

    memset(my_namespace::distance, 0x3f, sizeof(my_namespace::distance));
    //memset(cost, 0x3f, sizeof(cost));
    for (int i = 0; i < numOfCity; ++i) {
        cityList[i].dist = INF;
        cityList[i].visited = false;
        cityList[i].lastNodeIndexes.clear();
    }
}


void dijkstra() {
    // Initialize some points, connected DIRECTEDLY to the start point.
    for (int i = 0; i < numOfCity; ++i) {
        if (my_namespace::distance[startIndex][i] != INF) {
            cityList[i].dist = my_namespace::distance[startIndex][i];
            cityList[i].lastNodeIndexes.push_back(startIndex);
        }
    }

    // Initialize the start point.
    cityList[startIndex].visited = true;


    // Begin looping
    int maxNumOfLoop = numOfCity - 1;
    while (maxNumOfLoop--) {
        int minIndex = -1;
        int minDist = INF;
        for (int i = 0; i < numOfCity; ++i) {
            if (!cityList[i].visited && cityList[i].dist < minDist) {
                minDist = cityList[i].dist;
                minIndex = i;
            }
        }

        if (minIndex == -1) {
            // Not found, which means the loop can break now.
            break;
        }

        cityList[minIndex].visited = true;
        for (int i = 0; i < numOfCity; ++i) {
            if (!cityList[i].visited) {
                if (minDist + my_namespace::distance[minIndex][i] < cityList[i].dist) { // A better road.

                    cityList[i].dist = minDist + my_namespace::distance[minIndex][i];

                    cityList[i].lastNodeIndexes.clear();
                    cityList[i].lastNodeIndexes.push_back(minIndex);

                } else if (minDist + my_namespace::distance[minIndex][i] == cityList[i].dist) { // An equivalent road.

                    cityList[i].lastNodeIndexes.push_back(minIndex);

                }
            }
        }
    }
}


void dfs(int currentIndex, int sum, vector<int> &path) {
    if (currentIndex == startIndex) {
        if (sum < resultCost) {
            resultCost = sum;
            resultPath = path;
        }
        return;
    }

    const vector<int> &last = cityList[currentIndex].lastNodeIndexes;
    for (int i = 0, len = last.size(); i < len; ++i) {
        path.push_back(last[i]);
        dfs(last[i], sum + cost[currentIndex][last[i]], path);

        // Backtrack.
        path.pop_back();
    }
}


int main() {
    //ifstream cin("in.txt");

    cin >> numOfCity >> numOfRoad >> startIndex >> endIndex;

    reset();

    for (int i = 0; i < numOfRoad; ++i) {
        int a, b, dis, cos;
        cin >> a >> b >> dis >> cos;

        my_namespace::distance[a][b] = my_namespace::distance[b][a] = dis;
        cost[a][b] = cost[b][a] = cos;
    }

    dijkstra();

    vector<int> path;
    path.push_back(endIndex);
    dfs(endIndex, 0, path);

    for (int i = resultPath.size() - 1; i >= 0; --i) {
        cout << resultPath[i] << " ";
    }
    cout << cityList[endIndex].dist << " " << resultCost << endl;

    return 0;
}
