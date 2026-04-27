/*
 * @lc app=leetcode id=1989544707 lang=mssql
 *
 * FriendRequestsIiWhoHasTheMostFriends
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

/* Write your T-SQL query statement below */

With Requester As(
    SELECT R1.requester_id as id , COUNT(R1.accepter_id) as num
    FROM RequestAccepted R1 
    GROUP BY R1.requester_id
), 
Accepter AS(
    SELECT accepter_id as id, COUNT(requester_id) as num
    FROM RequestAccepted
    GROUP BY accepter_id 
),
Rank AS(
    SELECT COALESCE(R.id, A.id) as id , COALESCE(R.num,0) + COALESCE(A.num,0) as num
    FROM Requester R FULL OUTER JOIN Accepter A
    ON R.id = A.id
    
)
--SELECT * FROM Requester
--SELECT * FROM Accepter

SELECT  top(1) id,  num FROM Rank
ORDER BY num desc


