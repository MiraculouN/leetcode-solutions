/*
 * @lc app=leetcode id=1940299290 lang=mssql
 *
 * RisingTemperature
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

/* Write your T-SQL query statement below */


SELECT W1.id as Id from 
Weather W1 , Weather W2 
where W1.temperature > W2.temperature and datediff(day,W2.recordDate, W1.recordDate) =1