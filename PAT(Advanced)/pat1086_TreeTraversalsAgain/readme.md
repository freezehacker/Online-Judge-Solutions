## 题意
    题目的意思有点绕，就是，它给出一个栈操作序列（S），告诉你这个S推出的序列I是某棵树的中序序列，要我们输出它的后序序列。
    
## 思路
    根据题目意思，给定S、I，我们可以确定一棵树，然后进行后序遍历。
    
    关键在于这棵树怎么确定。以往做过的题目，都是给定inOrder和[postOrder、levelOrder、preOrder]其中的一个，最后确定一棵树，而这道题只是给了栈序列S，告诉我们S的输出就是inOrder，所以关键就在于这个S。它是有规律的。
    
    我们不妨逐语句分析S，把每一句对应到给出的图片后，可以知道其实这也可以是一个递归建树的过程：**按照前序建树，Push就是建立节点，Pop就是建立NULL。**
    
    比如示例：
    
    Push 1：建立当前根节点，值为1
    Push 2：在1基础上，建立左子树，值为2
    Push 3：在2基础上，建立左子树，值是3
    Pop：在3基础上，左子树为NULL
    Pop:在3基础上，右子树也为NULL
    Push 4：（在3的递归结束，回到第2那层）在2基础上，建立右子树，为4
    ……
    
    其实可以当作是“找规律”，因为是对照着S和那棵树，自然就想出来了……