## 题意

求第二高（second highest）的薪水。

## 思路

有两种方法：
* 排序之后取第2个
```sql
SELECT (
  SELECT DISTINCT(`Salary`) 
  FROM `Employee` 
  ORDER BY `Salary` DESC 
  LIMIT 1 OFFSET 1
) AS `SecondHighestSalary`;
```
注意，这里是先对结果进行DISTINCT，再LIMIT+OFFSET挑选。
为了不存在的情况可以返回null，有个trick就是再包一层select，还可以顺便起alias。如果没有外面那个select，会返回empty set即结果为空。

* 排除掉max之后，再选max就是原来的第二max了
```sql
SELECT MAX(`Salary`) AS `SecondHighestSalary` 
FROM `Employee` 
WHERE `Salary` != ( SELECT MAX(`Salary`) FROM `Employee` );
```
如果不存在，会返回null，也满足题目的要求。
