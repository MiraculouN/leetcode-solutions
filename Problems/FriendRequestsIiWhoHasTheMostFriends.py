/*
 * @lc app=leetcode id=1989551494 lang=mssql
 *
 * FriendRequestsIiWhoHasTheMostFriends
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

/* Write your T-SQL query statement below */

WITH Union_table AS(
    SELECT requester_id as id FROM RequestAccepted
    UNION ALL
    SELECT accepter_id FROM RequestAccepted
)

SELECT  top(1) id, COUNT(id) as num
FROM Union_table
GROUP BY id
ORDER BY COUNT(id) desc
