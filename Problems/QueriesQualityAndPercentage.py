/*
 * @lc app=leetcode id=1946508566 lang=mssql
 *
 * QueriesQualityAndPercentage
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

/* Write your T-SQL query statement below */

SELECT Q1.query_name, ROUND(1.0 * SUM(1.0 * Q1.rating/ Q1.position) /COUNT(Q1.query_name),2) as quality,
ROUND(1.0* (SELECT COUNT(*) from Queries Q2 where Q1.query_name = Q2.query_name and Q2.rating < 3) / (SELECT COUNT(*) from Queries Q2 where Q1.query_name = Q2.query_name)*100,2)
as poor_query_percentage
from Queries Q1
GROUP BY Q1.query_name