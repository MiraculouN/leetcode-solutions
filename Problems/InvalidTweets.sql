/*
 * @lc app=leetcode id=1936199979 lang=mysql
 *
 * InvalidTweets
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

# Write your MySQL query statement below

SELECT tweet_id from Tweets
where length(content) > 15