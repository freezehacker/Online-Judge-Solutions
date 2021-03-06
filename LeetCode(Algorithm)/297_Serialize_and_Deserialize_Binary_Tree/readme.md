## 题意

要求写两个函数：
* 把一棵二叉树序列化成一个字符串
* 把字符串反序列化成一棵二叉树

## 思路

这道题挺有趣的，序列化/反序列化，跟LeetCode测例的转化规则完全一样。  
首先说serialize，是根据树的每一层节点的值按顺序生成，比如：
```
        1
       / \
      2   5
     /   / \
    4   3   -8
```
那么serialize就是：[1, 2, 5, 4, null, 3, -8, null, null, null, null, null, null]，其中null表示那个节点为空。  
那么很明显，这个过程就是BFS。  
有个需要注意的地方就是，在这道题中，结尾的null不算入，所以要自行删除掉。  
  
然后，deserialize的思路是一样的，也是BFS。不一样的是，serial的BFS是遍历树的节点，而deserialize的BFS是建树。  
先从创建root开始，对于每一个从队列中取出来的节点node，从列表中往后拿两个值A和B（如果还有剩余），给node建立以A为值的左节点，给node建立以B为值的右节点，并且记得再推进queue中待以后遍历。这里要注意null的情况，就不用加入queue了。这样直到没有剩余，就构建完一棵树了。

