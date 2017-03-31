## 题意

在一个单链表中，删除值为val的所有节点。

## 思路

题目很简单，其实就是要我们实现Singly Linked List类的删除操作（节点值的等值删除）。  
比较优雅的做法，就是像Linus在采访中所说的“好代码”那样，其中使用了二重指针，可以把链表为空的case、一般case这两种情况完美地统一起来。
```c++
ListNode** indirect = &head;
// ...具体代码见源代码文件answer.cpp
```
