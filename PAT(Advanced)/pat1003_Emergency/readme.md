## 题意

根据给定的图，计算最短路径的数目，以及最大的点权重之和。
    
    
## 拓展
常见的此类最短路径（SP）的题目可以求：
* 最小的边权重之和，也就是最短路径的值
* 最短路径的条数
* 其中点权重的最大值
* 打印路径  

本题目属于（3）
    
    
## 思路

因为是求：条数、最大点权重和，那么可以为每个点多设2个数组，分别是：
```c++
    int pathCount[N];
    int pointWeightSum[N];
```
之后可以运用Dijkstra算法来explore。进行“松弛”操作时分两种情况：  

* 如果找到更短的边，即需要松弛（比如中间点下标为mid）：首先dist（到原点的距离）是需要更新的，pathCount也要更新为mid的pathCount：
```c++
    dist[i] = dist[mid] + graph[mid][i];
    pathCount[i] = pathCount[mid]; // 因为直接改选这条路，所以路径数目是直接修改的
    pointWeightSum[i] = pointWeightSum[mid] + pointWeight[i];
```
* 如果是遇到相同边权和的情况，不需要松弛，但是这时候也要进行pathCount等的累加：
```c++
    pathCount[i] = pathCount[i] + pathCount[mid]; // 路径数是多种选择的叠加
    pointWeightSum[i] = max(pointWeightSum[i], pointWeightSum[mid] + pointWeight[i]); // 选择更大的那个
```
