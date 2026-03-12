/*
 * @lc app=leetcode id=1944519416 lang=mssql
 *
 * StudentsAndExaminations
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

/* Write your T-SQL query statement below */


SELECT
    S.student_id, 
    S.student_name,
    U.subject_name ,
    COUNT(E.student_id) as attended_exams
from Students S cross join Subjects U 
left join Examinations E
    on E.student_id = S.student_id and U.subject_name = E.subject_name
group by S.student_id, S.student_name, U.subject_name
order by S.student_id , U.subject_name



