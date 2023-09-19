-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Step 1: Find the report of the CS50 Duck theft
SELECT
  description
FROM
  crime_scene_reports
WHERE
  YEAR = 2021
  AND MONTH = 7
  AND DAY = 28
  AND street = 'Humphrey Street';
-- 2: