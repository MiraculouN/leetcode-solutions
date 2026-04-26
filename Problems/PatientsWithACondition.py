/*
 * @lc app=leetcode id=1988570163 lang=mssql
 *
 * PatientsWithACondition
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

/* Write your T-SQL query statement below */

SELECT patient_id, patient_name, conditions 
FROM Patients
WHERE conditions like '% DIAB1%' OR conditions like 'DIAB1%' 
