/*
 * @lc app=leetcode id=1936196357 lang=mysql
 *
 * BigCountries
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

# Write your MySQL query statement below

SELECT name , population , area from World
where area >= 3000000 or population >= 25000000