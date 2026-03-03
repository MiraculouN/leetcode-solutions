/*
 * @lc app=leetcode id=1936195494 lang=mysql
 *
 * FindCustomerReferee
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

# Write your MySQL query statement below

SELECT name from Customer 
where referee_id <> 2 or referee_id is NULL