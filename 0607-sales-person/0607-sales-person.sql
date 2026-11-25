# Write your MySQL query statement below
-- Select the names of salespersons whose IDs are not in the list of IDs
-- associated with any order for the company named 'RED'
SELECT name
FROM SalesPerson
WHERE sales_id NOT IN (
    -- Find all sales_id values linked to orders placed with company 'RED'
    SELECT o.sales_id
    FROM Orders o
    JOIN Company c
        ON o.com_id = c.com_id
    WHERE c.name = 'RED'
);