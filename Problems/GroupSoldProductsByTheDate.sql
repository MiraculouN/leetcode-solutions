/*
 * @lc app=leetcode id=1989767636 lang=mysql
 *
 * GroupSoldProductsByTheDate
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

# Write your MySQL query statement below

SELECT sell_date , COUNT(DISTINCT product) as num_sold,
    GROUP_CONCAT(DISTINCT product ORDER BY product ) as products
FROM Activities 
GROUP BY sell_date
ORDER BY sell_date