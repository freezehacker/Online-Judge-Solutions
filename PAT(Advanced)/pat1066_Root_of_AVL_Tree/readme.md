## 题意

给定一系列节点，按顺序插入来构造一棵AVL树，求它的root的value。

## 思路

关键是AVL树的维护。这里只涉及到AVL树的：
* 插入
所以关键是insert之后的4种旋转方式来维护AVL。
