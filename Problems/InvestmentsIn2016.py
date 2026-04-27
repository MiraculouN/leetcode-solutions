/*
 * @lc app=leetcode id=1989766120 lang=mssql
 *
 * InvestmentsIn2016
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

/* Write your T-SQL query statement below */

WITH Loc AS(
    SELECT lat, lon , SUM(pid) as pid FROM Insurance
    GROUP BY lat, lon
    HAVING COUNT(pid)=1
), Tiv AS(
    SELECT distinct I1.tiv_2015 as t
    FROM Insurance I1 JOIN Insurance I2
    ON I1.pid <> I2.pid AND I1.tiv_2015 = I2.tiv_2015
)

SELECT ROUND(SUM(tiv_2016),2) as tiv_2016
FROM Insurance I JOIN Loc L
ON  L.pid = I.pid
AND 
    tiv_2015 in (SELECT t FROM Tiv)
