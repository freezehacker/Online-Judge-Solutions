## 题意

按照分数从高到低排名，注意分数相同的rank也相同，而且rank总是连续的。

## 思路

* 先对Score列排序，并且取Distinct，然后加上行号列，得到SR
```sql
SELECT @rownum := @rownum + 1 AS Rank, Score
    FROM (SELECT @rownum := 0) AS b, 
         (SELECT DISTINCT `Score` FROM `Scores` ORDER BY `Score` DESC) AS DistinctScores
```
* 再把原来的Scores表与SR左外联，最后再按照Score列排序
```sql
SELECT S.Score, SR.Rank 
FROM `Scores` AS S LEFT OUTER JOIN SR 
ON S.Score=SR.Score
ORDER BY S.Score DESC;
```
