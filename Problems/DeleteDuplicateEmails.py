/*
 * @lc app=leetcode id=1989425681 lang=mssql
 *
 * DeleteDuplicateEmails
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

/* Write your T-SQL query statement below */
WITH Dup AS(
    SELECT email FROM Person
    GROUP BY email
    HAVING COUNT(email)>1
)
, First_id AS(
    SELECT MIN(id) as id
    FROM Person 
    WHERE email in (SELECT email from Dup)
    GROUP BY email
)

DELETE FROM Person
WHERE id not in (SELECT id FROM First_id) AND email in (SELECT email FROM Dup)