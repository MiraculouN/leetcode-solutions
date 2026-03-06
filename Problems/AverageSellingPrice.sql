/*
 * @lc app=leetcode id=1940274452 lang=mysql
 *
 * AverageSellingPrice
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

# Write your MySQL query statement below



SELECT P.product_id, 
ROUND(IFNULL(SUM(U.units*P.price) / (SUM(U.units)),0),2)as 'average_price'
from Prices P left join UnitsSold U
on U.product_id = P.product_id and U.purchase_date between P.start_date AND  P.end_date
group by P.product_id