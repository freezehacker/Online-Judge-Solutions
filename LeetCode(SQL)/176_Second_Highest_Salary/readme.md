## 题意

求第二高（second highest）的薪水。

## 思路

有两种方法：
* 排序之后取第2个
```sql
SELECT `Salary` 
FROM `Employee` 
ORDER BY `Salary` DESC  
LIMIT 1 OFFSET 1;
```
但是，不存在的时候，会返回empty set，也就是空。不满足题意。  

* 排除掉max之后，再选max就是原来的第二max了
```sql
SELECT MAX(`Salary`) AS `SecondHighestSalary` 
FROM `Employee` 
WHERE `Salary` != ( SELECT MAX(`Salary`) FROM `Employee` );
```
如果不存在，会返回null，满足题目的要求。
