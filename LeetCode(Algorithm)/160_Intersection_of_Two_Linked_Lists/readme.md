## 题意

给定两个链表，求公共部分（公共子链表）的头指针。

这让我想起PAT Advanced的1032那道题：https://www.patest.cn/contests/pat-a-practise/1032  
不过还是有点区别：
* pat1032的输入是一系列的点，地址是一个int数来表示。可以理解为逻辑ListNode。
* 该题的输入是两个链表（的head指针），是“物理”ListNode。

## 思路

* space > O(n)的解法：  
跟pat那题的解法差不多，即遍历链表A把地址全部hash并且标记，然后遍历B，遇到第一个已标记的就OK。
* space == O(n)的解法：（太蠢没想到）  
准备两个指针p1、p2分别从A、B出发，遍历，当p1走完A时换作从B出发，当p2走完B时换作从A出发。最终，p1与p2相遇的时候，就是走到了公共部分的head，或者是表明没有公共部分。详见代码与其注释。

## 为什么？

我也不知道。  
这种p1p2俩指针循环走的做法，可以想起单链表的环判断的经典面试题：https://leetcode.com/problems/linked-list-cycle-ii/#/description  
不一样的是：
* 环的判断，是循环走同一个链表
* 而这道题，是循环走不同的链表  
那么，为什么策略是让p1走完了A，又要走B呢？因为A、B的长度不一定相等，但是如果让p1、p2两个指针去遍历A和B（p1遍历A与B，p2遍历B与A），即使是从不同的起点（p1是从A的head，p2是从B的head）出发，最终也会同时遍历完这9个节点。  
我们可以用两个例子去理解，一个是有公共部分，一个是没有公共部分。假设现在A有5个元素，B有4个元素：  
* 公共部分是后3个元素。如下：
```
(数字代表地址)

A：1 --> 2 --> 
              \
               3 --> 4 --> 5
              /
     B： 6 -->
```
一共有：5 + 4 = 9 个元素。  
如果让p1、p2这两个指针去遍历，即使是从不同的起点（p1是1，p2是6）出发，最终也会同时遍历完这9个节点。如果有公共部分，那么两个指针会在节点3就已经开始相遇，然后共同携手度过余生。   
* 假设A、B没有公共部分：
```
A: 1 --> 2 --> 3 --> 4 --> 5

B: 6 --> 7 --> 8 --> 9
```
那么按照上面的思路：遍历完9个节点之后，p1重新回到了1，p2重新回到了6，这时候，其实就可以判断，这两个链表没有公共部分了。  
  
## 一个trick
因为上面的思路，在处理没有公共部分的情况会有些麻烦，我们可以这样做：把链表尾巴的NULL也作为一个“ListNode”让指针去遍历。即：
```
A: 1 --> 2 --> 3 --> 4 --> 5 --> NULL

B: 6 --> 7 --> 8 --> 9 --> NULL
```
这样一来：
* 如果有公共部分，那么会在公共部分的第一个ListNode相遇，即有p1 == p2
* 如果不存在公共部分，那么会同时到达两个链表最后的NULL处，这时候也有p1 == p2( == NULL)

