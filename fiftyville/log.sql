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
-- Step 2: Find the name and transcript of the 3 witnesses
SELECT
    name, transcript
FROM
    interviews
WHERE
    year = 2021
    AND month = 7
    AND day = 28
    AND transcript LIKE '%thief%';
-- Step 3: