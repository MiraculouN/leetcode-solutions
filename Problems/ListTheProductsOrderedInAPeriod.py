/*
 * @lc app=leetcode id=1989771711 lang=mssql
 *
 * ListTheProductsOrderedInAPeriod
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

/* Write your T-SQL query statement below */

SELECT P.product_name ,  SUM(O.unit) as unit
FROM Products P JOIN Orders O
ON P.product_id = O.product_id AND FORMAT(O.order_date, 'yyyy-MM')='2020-02'
GROUP BY P.product_name
HAVING SUM(O.unit)>=100;
