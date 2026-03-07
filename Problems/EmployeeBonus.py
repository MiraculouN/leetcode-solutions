/*
 * @lc app=leetcode id=1940307271 lang=mssql
 *
 * EmployeeBonus
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

/* Write your T-SQL query statement below */

SELECT E.name, B.bonus from Employee E left join Bonus B
on E.empId = B.empId 
where B.bonus < 1000 or B.bonus is NULL