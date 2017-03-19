## 题意

给定两个链表的节点，找出公共子链表中第一个节点的地址。  
需要注意的是，要根据给定的链表的地址来判断是不是“公共”，而不是根据字母是否相同，也就是说输入的单词的每个字母，在这道题中是完全没有作用的。  
比如题目给定的图片：“being”和loading”。  
虽然从单词上说，都有后缀“ing”，但是如果我给定的链表是：
```
   b--e--i--n--------
                     \
                      g
                     /
   l--o--a--d--i--n--
```
那公有后缀就是g，答案就是g，而不是ing中的i了。所以说，还是要看输入节点的地址。  

还有个需要注意的地方，因为题目的输入隐式决定了是个单链表，也就是说
 > 单链表决定了每个节点的后继点有且只有一个，所以，公共子链表有且只有一个，并且出现在链表的末端。  

所以，以下这个例子是不会出现的：（“begging”和“reading”）
```
    b-   g--g---
      \ /       \
       e         i--n--g
      / \       /
    r-   -a--d--
```
因为节点“e”有两个后继点，这与输入不相符，所以不考虑这种情况。


## 思路

理解清楚题意之后，就可以考虑数据结构了，因为只有地址是有用的，我们不必自定义一个链表结构体了，只需要建立一个int数组来存储每个节点的后继点的address就可以了：
```c++
   int next[100000];
    // 比如next[10000]=18080表示，当前node的地址为10000,下一个node地址是18080
```
然后找公共子链表的第一个地址就可以了。