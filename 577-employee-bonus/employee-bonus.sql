-- Write your PostgreSQL query statement below
select name, bonus
from Employee as e
left join Bonus as b
on e.empId = b.empId
where bonus is NULL
    or bonus < 1000