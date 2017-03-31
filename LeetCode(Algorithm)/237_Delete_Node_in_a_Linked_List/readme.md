## 题意

给定一个链表中的某个节点，我们要做的就是把这个节点从链表中移除。



## 思路

首先看函数原型：
```c++
void deleteNode(ListNode* node);
```
参数类型为ListNode*，从ListNode*层面上来说是按“值”传递。所以，目前我们只知道要删除的节点（记为B），不知道它的前一个节点（记为A），因此没有办法去实现A.next = B.next然后再删掉B这样的逻辑的。  
既然我们没法删除B、控制A，那么我们变换一下思路，换作删除C。比如有链表：
```
7(A) -> 9(B) -> 3(C) -> 2(D)
现在想要删除9(B)，变成：7(A) -> 3(C) -> 2(D)。
```
入参node是指向B的一个地址。做法是：  
把B.value设成C.value即3，B.next设成C.next即指向D。这样一来，B就可以代替C，C就是没有用的节点了：
```
7 -> 9(B) ---> 2
              /
            3(C)
```
所以，这时候可以把C节点delete掉，就可以了。



## 更多思考

根据以上思路，不难得出代码为：
```c++
void deleteNode(ListNode* node) {
	ListNode* toDelete = node->next;

	/* 
	*  调用ListNode的赋值。没有提供，所以简单地调用每个成员的赋值。
	*  等价于：
	*    node->val = toDelete->val; 
	*    node->next = toDelete->next;
	*/
	*node = *toDelete;

	delete toDelete;
}
```
以上是C++代码，如果换成是java，则：
```java
public class Solution {
    public void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }
}
```
其中那两句不能换成：
```
node = node.next;
```
为什么呢？  
首先，在java中，一切对象实际上都是指针，所以函数的入参node是个指针，这里同样是“值传递”。  
然后，如果写成: node = node.next，实际上改变的是函数内的局部指针node的指向，对外部没有任何影响，所以单链表没有发生任何变化。  
而为什么C++代码中的：*node = *node->next，又是正确的写法呢？  
因为这两种写法表达的，并不是同一个意思。取地址之后，得到的是对象本身（不再是指针），通过赋值，就改变了节点本身了，所以也改变了单链表。  
**PS：之所以提出这个，是因为想多点思考指针、值传递这些重要而易让人出错的概念。**