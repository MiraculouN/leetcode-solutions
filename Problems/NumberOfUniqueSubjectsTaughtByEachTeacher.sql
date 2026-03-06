/*
 * @lc app=leetcode id=1940287626 lang=mysql
 *
 * NumberOfUniqueSubjectsTaughtByEachTeacher
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

# Write your MySQL query statement below

SELECT T.teacher_id , COUNT(DISTINCT S.subject_id) as cnt
from Teacher T inner join Teacher S
on T.teacher_id = S.teacher_id
group by T.teacher_id