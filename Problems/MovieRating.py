/*
 * @lc app=leetcode id=1988972249 lang=mssql
 *
 * MovieRating
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

/* Write your T-SQL query statement below */

With Rank AS(
    SELECT U.user_id , U.name as name,  COUNT(M.movie_id) as cnt,
    ROW_NUMBER() OVER( ORDER BY COUNT(M.movie_id) desc, U.name) as rnk
    FROM Users U JOIN MovieRating M
    ON U.user_id = M.user_id
    GROUP BY U.user_id, U.name
), 
Highest AS(
    SELECT AVG(1.0 * M2.rating) as avg, M1.movie_id , M1.title,
    ROW_NUMBER() OVER(ORDER BY AVG(1.0 * M2.rating) desc, M1.title ) as rnk
    FROM Movies M1 JOIN MovieRating M2
    ON M1.movie_id = M2.movie_id AND FORMAT(M2.created_at, 'yyyy-MM')='2020-02'
    GROUP BY M1.movie_id, M1.title
), 
H AS(
    SELECT title FROM Highest WHERE rnk = 1
),
R AS(
    SELECT name from Rank WHERE rnk =1
)

SELECT name as results FROM R
UNION ALL
SELECT * FROM H
AS result