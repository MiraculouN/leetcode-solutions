/*
 * @lc app=leetcode id=1940248470 lang=mysql
 *
 * NotBoringMovies
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

# Write your MySQL query statement below

Select * from Cinema 
where id&1 = 1 and description <> "boring"
order by rating desc