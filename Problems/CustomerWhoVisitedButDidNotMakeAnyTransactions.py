/*
 * @lc app=leetcode id=1937203256 lang=mssql
 *
 * CustomerWhoVisitedButDidNotMakeAnyTransactions
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

/* Write your T-SQL query statement below */

SELECT customer_id, COUNT(visit_id) as count_no_trans from Visits
where visit_id not in (SELECT visit_id from Transactions )
group by customer_id;