/*
 * @lc app=leetcode id=1989781059 lang=mssql
 *
 * FindUsersWithValidEMails
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

/* Write your T-SQL query statement below */


SELECT * FROM Users 
WHERE mail COLLATE Latin1_General_CS_AS like '[a-zA-Z]%@leetcode.com' 
AND mail COLLATE Latin1_General_CS_AS not like '%[^A-Za-z0-9._-]%@leetcode.com'
