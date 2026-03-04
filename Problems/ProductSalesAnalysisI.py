/*
 * @lc app=leetcode id=1936210536 lang=mssql
 *
 * ProductSalesAnalysisI
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

/* Write your T-SQL query statement below */

SELECT Product.product_name, Sales.year, Sales.price from Product, Sales
where Product.product_id = Sales.product_id