## 题意

给定一个单链表，把位置为奇数的节点放在前面，把偶数的放后面。

## 思路

* 本来觉得，遍历一次，把奇数位的节点的值记录下来，然后再遍历一次记录偶数节点的值。构造一个新的单链表返回。最简单的思路，但是空间复杂度需要O(n)，所以不符合题意。
  
所以，只能通过移动next指针来调整位置了：  
比如现在是：
```
7 -> 9 -> 3 -> 2 -> 4
```
那么，我们可以通过变成：[7->3->4]、[9->2]这两个链表，然后再merge。  
然而这两个链表不是先后生成，而是同步生成的。因为如果是先生成[7->3->4]，那么这时候剩下的节点（9和2）就没有任何指针指向了，发生了内存泄漏。  
所以，我们要同时建立维护两个指针，在我的代码中是odd和even。比如一开始odd指向7，even指向9，那么可以一直循环以下过程直到原单链表结尾：
```
even.next是3，那么把odd连到3，再让odd往前移到3。
然后，odd.next是2，同理even连到2，even前进。
然后，even.next是4，odd连到4，并且前进。
发现已经到链表结尾，结束这个过程。
```
现在把两个链表merge，就得到了我们想要的结果。  
PS：更多的细节与坑，可以参考我的代码。