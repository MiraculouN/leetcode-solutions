/*
 * @lc app=leetcode id=1936206387 lang=mssql
 *
 * ReplaceEmployeeIdWithTheUniqueIdentifier
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

/* Write your T-SQL query statement below */




SELECT unique_id , name from 
EmployeeUNI right join Employees
on EmployeeUNI.id = Employees.id