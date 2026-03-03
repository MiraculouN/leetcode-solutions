/*
 * @lc app=leetcode id=1936193998 lang=mssql
 *
 * RecyclableAndLowFatProducts
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

/* Write your T-SQL query statement below */

SELECT product_id from Products 
where low_fats = 'Y' and recyclable = 'Y';