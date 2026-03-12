/*
 * @lc app=leetcode id=1946083894 lang=mssql
 *
 * PercentageOfUsersAttendedAContest
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

/* Write your T-SQL query statement below */

SELECT contest_id , round((1.0 * COUNT(U.user_id)/(SELECT COUNT(*) from Users) )* 100,2) as percentage
from Register R, Users U
where R.user_id = U.user_id
GROUP BY contest_id
ORDER BY percentage desc , contest_id