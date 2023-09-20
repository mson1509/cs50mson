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
-- Step 3: Find the license plate of the thief at the bakery according to witness 1
CREATE TEMPORARY TABLE
  thief_license_plates
AS
SELECT
  license_plate
FROM
  bakery_security_logs
WHERE
  activity = 'exit'
  AND year = 2021
  AND month = 7
  AND day = 28
  AND hour = 10
  AND minute > 5
  AND minute < 25;
-- Step 4: Find the account number of the thief according to witness 2
CREATE TEMPORARY TABLE
  thief_account_numbers
AS
SELECT
  account_number
FROM
  atm_transactions
WHERE
  year = 2021
  AND month = 7
  AND day = 28
  AND atm_location = 'Leggett Street'
  AND transaction_type = 'withdraw';
-- Step 5: Find the airpot the thief gonna go to tommorow according to witness 3
SELECT
  airports.abbreviation, airports.full_name, airports.city, flights.id, flights.hour, flights.minute
FROM
  flights
JOIN
  airports ON airports.id = flights.destination_airport_id
WHERE
  year = 2021
  AND month = 7
  AND day = 29
  AND flights.origin_airport_id =
  (
    SELECT
      id
    FROM
      airports
    WHERE
      city = 'Fiftyville'
  )
ORDER BY hour, minute
LIMIT 1;
-- Step 6: Find the passport number of the thief from his flight_id
