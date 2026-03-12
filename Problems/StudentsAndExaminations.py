/*
 * @lc app=leetcode id=1944517256 lang=mssql
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



























/*SELECT S.student_id, S.student_name, SS.subject_name ,COUNT(E.subject_name)
from Students S cross join Subjects SS cross join Examinations E
where S.student_id = E.student_id and E.subject_name = SS.subject_name
group by S.student_id
order by S.student_id, subject_name
*/














SELECT S.student_id, S.student_name , E.subject_name, COUNT(subject_name)as attended_exams
from Students S cross join Examinations E 
where E.student_id = S.student_id
GROUP BY
    S.student_id,
    S.student_name,
    E.subject_name
