/*
 * @lc app=leetcode id=1936198814 lang=mysql
 *
 * ArticleViewsI
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

# Write your MySQL query statement below

SELECT distinct author_id as id from Views 
where author_id = viewer_id
order by author_id