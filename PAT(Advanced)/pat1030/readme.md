## 题意：
从多条最短路中选择费用最少的一条，并打印出来。

## 思路：

实际上与题目1018  
https://github.com/freezehacker/Online-Judge-Solutions/tree/master/PAT(Advanced)/pat1018_PublicBikeManagement  
一样的：  
* 从多条最短路中，用DFS遍历，选择最少的一条。  
* 依然，多条路径用vector<int>表示来表示可能的多个前驱点。  

PS：这次使用了结构体来表示每一个城市，感觉更OOP一点：
```c++
struct Node {
    int dist;           // 到出发点的距离
    bool visited;       // 是否已遍历
    vector<int> lastNodeIndexes;    // 前驱点
} cityList[MAX_POINT_NUM];  // MAX_POINT_NUM是最大的城市数目
```
