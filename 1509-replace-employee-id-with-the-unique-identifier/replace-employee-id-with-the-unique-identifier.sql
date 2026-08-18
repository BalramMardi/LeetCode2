-- Write your PostgreSQL query statement below
select eni.unique_id, e.name
from Employees as e
Left join EmployeeUNI as eni
on eni.id = e.id