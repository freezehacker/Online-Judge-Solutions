/*
CREATE TABLE `Scores`(
    `Id` INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    `Score` DECIMAL(7,2) NOT NULL
);
INSERT INTO `Scores` VALUES (1, 3.50), (2, 3.65), (3, 4.00), (4, 3.85), (5, 4.00), (6, 3.65);
*/

SELECT S.Score, SR.Rank 
FROM `Scores` AS S LEFT OUTER JOIN (
    SELECT @rownum := @rownum + 1 AS Rank, Score
    FROM (SELECT @rownum := 0) AS b, 
         (SELECT DISTINCT `Score` FROM `Scores` ORDER BY `Score` DESC) AS DistinctScores
) AS SR 
ON S.Score=SR.Score
ORDER BY S.Score DESC;
