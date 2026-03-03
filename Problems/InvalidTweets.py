/*
 * @lc app=leetcode id=1936200446 lang=mssql
 *
 * InvalidTweets
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

/* Write your T-SQL query statement below */


select tweet_id from Tweets 
where len(content) > 15