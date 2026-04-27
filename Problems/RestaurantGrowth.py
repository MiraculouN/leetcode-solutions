/*
 * @lc app=leetcode id=1989407278 lang=mssql
 *
 * RestaurantGrowth
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

/* Write your T-SQL query statement below */

WITH Tot AS(
    SELECT SUM(amount) as amount , visited_on
    FROM Customer 
    GROUP BY  visited_on
)


SELECT DATEADD(DAY, 6, C1.visited_on) as visited_on,
SUM(C2.amount) as amount, ROUND(1.0 * SUM(C2.amount)/7.0,2) as average_amount
FROM Tot C1 JOIN Tot C2
ON 
DATEDIFF(DAY , C1.visited_on , C2.visited_on) <= 6
   AND 
C2.visited_on >= C1.visited_on
   AND
DATEADD(DAY, 6, C1.visited_on) <= (SELECT MAX(visited_on) FROM Customer)

GROUP BY C1.visited_on
ORDER BY C1.visited_on
