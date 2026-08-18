# Write your MySQL query statement below
Select eu.unique_id, e.name
From Employees e
Left Join EmployeeUNI eu
On eu.id = e.id;