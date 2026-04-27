/*
 * @lc app=leetcode id=1989769958 lang=mssql
 *
 * GroupSoldProductsByTheDate
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

/* Write your T-SQL query statement below */

WITH Unique_products AS(
    SELECT DISTINCT sell_date,  product FROM Activities
)

SELECT sell_date , COUNT( product) as num_sold,
    STRING_AGG( product,',') WITHIN GROUP (ORDER BY product ) as products
FROM Unique_products 
GROUP BY sell_date
ORDER BY sell_date