/*
 * @lc app=leetcode id=1988960307 lang=mssql
 *
 * ExchangeSeats
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

/* Write your T-SQL query statement below */

SELECT S1.id, S2.student
FROM Seat S1 JOIN Seat S2
ON S1.id = 
    CASE
        WHEN S2.id%2 = 0 THEN S2.id -1
        WHEN S2.id%2 = 1 AND S2.id <> (SELECT MAX(id) FROM Seat) THEN S2.id +1
        WHEN S2.id%2 = 1 AND S2.id = (SELECT MAX(id) FROM Seat) AND S2.id = S1.id then S1.id
    END
ORDER BY S1.id
