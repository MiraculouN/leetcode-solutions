/*
 * @lc app=leetcode id=1940311975 lang=mssql
 *
 * AverageTimeOfProcessPerMachine
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

/* Write your T-SQL query statement below */

SELECT A1.machine_id , round(SUM(A1.timestamp - A2.timestamp)/COUNT(DISTINCT A1.process_id ),3) as processing_time
from Activity A1, Activity A2
where A1.machine_id = A2.machine_id and A1.process_id = A2.process_id and A1.timestamp >= A2.timestamp
Group by A1.machine_id