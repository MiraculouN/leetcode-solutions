/*
 * @lc app=leetcode id=1937156171 lang=mssql
 *
 * CustomerWhoVisitedButDidNotMakeAnyTransactions
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

/* Write your T-SQL query statement below */

SELECT  customer_id , COUNT(V.visit_id) as count_no_trans 
from Visits V left join Transactions T
on V.visit_id = T.visit_id
where T.transaction_id is NULL
group by customer_id
