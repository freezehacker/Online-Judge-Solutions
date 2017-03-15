#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX_POINT_NUM = 501;

int graph[MAX_POINT_NUM][MAX_POINT_NUM];
int dist[MAX_POINT_NUM];
bool visit[MAX_POINT_NUM];
int weight[MAX_POINT_NUM];
vector<int> last[MAX_POINT_NUM];  // Record the path(may be more than 1).
int capacity, pointNum, destIdx, edgeNum;
int srcIdx = 0;  // Start from point 0.

vector<int> curPath;
vector<int> answerPath;
int answer;


void reset() {
  memset(graph, 0x3f, sizeof(graph));
  //memset(dist, 0x3f, sizeof(dist));
  memset(visit, false, sizeof(visit));
  for (int i = 0; i < MAX_POINT_NUM; ++i) {
    last[i].clear();
  }

  curPath.clear();
  answerPath.clear();
  answer = INF;
}


void dijkstra() {
  dist[srcIdx] = 0;
  visit[srcIdx] = true;
  for (int i = 1; i <= pointNum; ++i) {
    dist[i] = graph[srcIdx][i];
    if (dist[i] < INF) {
      last[i].push_back(srcIdx);
    }
  }

  int maxLoop = pointNum - 1 + 1;
  while (maxLoop--) {
    int minIndex = -1;
    int minValue = INF;
    for (int i = 1; i <= pointNum; ++i) {
      if (!visit[i] && dist[i] < minValue) {
        minValue = dist[i];
        minIndex = i;
      }
    }
    if (minIndex == -1) break;

    visit[minIndex] = true;  // Mark as visited.
    for (int i = 1; i <= pointNum; ++i) {
      if (!visit[i]) {
        if (minValue + graph[minIndex][i] < dist[i]) {
          // Just choose a shorter path.
          dist[i] = minValue + graph[minIndex][i];
          last[i].clear();
          last[i].push_back(minIndex);
        } else if (minValue + graph[minIndex][i] == dist[i]) {
          // Add as an alternative path.
          last[i].push_back(minIndex);
        }
      }
    }
  }
}


void dfs(int fromIdx) {
  if (fromIdx == srcIdx) {
    int sum = 0;
    int count = curPath.size();
    for (int i = 0; i < count - 1; ++i) { // Start point has no weight.
      sum += weight[ curPath[i] ];
    }
    int needToAdd = (capacity / 2) * (count - 1) - sum;
    if (abs(needToAdd) < abs(answer)) {
      // Update the answers.
      answer = needToAdd;
      answerPath = curPath;
    }
    return;
  }

  vector<int> &lastIdxList = last[fromIdx];
  for (vector<int>::iterator iter = lastIdxList.begin(); iter != lastIdxList.end(); ++iter) {
    const int idx = *iter;
    curPath.push_back(idx);
    dfs(idx);
    curPath.pop_back();  // Backtrack.
  }
}


void outputAnswers() {
  if (answer > 0) {
    cout << answer;
  } else {
    cout << 0;
  }
  cout << " ";
  for (int i = answerPath.size() - 1; i >= 0; --i) {
    cout << answerPath[i];
    if (i != 0) {
      cout << "->";
    }
  }
  cout << " ";
  if (answer > 0) {
    cout << 0;
  } else {
    cout << -answer;
  }
  cout << endl;
}


int main() {
  //ifstream cin("in");

  reset();

  cin >> capacity >> pointNum >> destIdx >> edgeNum;
  for (int i = 1; i <= pointNum; ++i) {
    cin >> weight[i];
  }
  for (int i = 0; i < edgeNum; ++i) {
    int a, b, len;
    cin >> a >> b >> len;
    graph[a][b] = graph[b][a] = len;
  }

  dijkstra();

  answer = INF;
  curPath.push_back(destIdx);
  dfs(destIdx);


  // Output
  outputAnswers();

  return 0;
}
