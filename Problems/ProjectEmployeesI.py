/*
 * @lc app=leetcode id=1946074979 lang=mssql
 *
 * ProjectEmployeesI
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

/* Write your T-SQL query statement below */

SELECT project_id, round(1.0 * SUM(experience_years)/COUNT(E.employee_id),2) as average_years
from Project P, Employee E
where P.employee_id = E.employee_id
group by project_id