## 题意

给定一棵树，求每一层的最大值。

## 思路

显然就是一个BFS可以解决的问题。注意这里需要记录层数level，相同level的节点就比较出一个最大值。