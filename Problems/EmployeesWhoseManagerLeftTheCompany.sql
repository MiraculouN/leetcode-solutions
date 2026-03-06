/*
 * @lc app=leetcode id=1940282245 lang=mysql
 *
 * EmployeesWhoseManagerLeftTheCompany
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

# Write your MySQL query statement below

SELECT employee_id from Employees 
where salary < 30000 and
manager_id not in (SELECT employee_id from Employees)
order by employee_id