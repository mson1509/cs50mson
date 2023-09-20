-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Step 1: Find the report of the CS50 Duck theft
SELECT
  description
FROM
  crime_scene_reports
WHERE
  year = 2021
  AND month = 7
  AND day = 28
  AND street = 'Humphrey Street';

-- Step 2: Find the name and transcript of the 3 witnesses
SELECT
  name,
  transcript
FROM
  interviews
WHERE
  year = 2021
  AND month = 7
  AND day = 28
  AND transcript LIKE '%thief%';

-- Step 3: Find the license plate of the thief at the bakery according to witness 1
CREATE TEMPORARY TABLE thief_license_plates AS
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

SELECT * FROM thief_license_plates;

-- Step 4: Find the account number of the thief according to witness 2
CREATE TEMPORARY TABLE thief_account_numbers AS
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

SELECT * FROM thief_account_numbers;

-- Step 5: Find the airpot the thief gonna go to tommorow according to witness 3
CREATE TEMPORARY TABLE thief_flight AS
SELECT
  airports.abbreviation,
  airports.full_name,
  airports.city,
  flights.id
FROM
  flights
  JOIN airports ON airports.id = flights.destination_airport_id
WHERE
  year = 2021
  AND month = 7
  AND day = 29
  AND flights.origin_airport_id = (
    SELECT
      id
    FROM
      airports
    WHERE
      city = 'Fiftyville'
  )
ORDER BY
  hour,
  minute
LIMIT
  1;

-- Step 6: Find the passport number of the thief from his flight_id
CREATE TEMPORARY TABLE thief_passport_numbers AS
SELECT
  passport_number
FROM
  passengers
  JOIN thief_flight ON passengers.flight_id = thief_flight.id;

SELECT * FROM thief_passport_numbers;

--Step 7: Find the thief id from his bank account
CREATE TEMPORARY TABLE thief_ids AS
SELECT
  person_id
FROM
  bank_accounts
WHERE
  account_number IN thief_account_numbers;

SELECT * FROM thief_ids;

--Step 8: Find the thief name and phone number by 3 tables: thief_license_plates, thief_passport_numbers, thief_ids
CREATE TEMPORARY TABLE final_suspects AS
SELECT
  people.name,
  people.phone_number
FROM
  people
  JOIN thief_license_plates ON thief_license_plates.license_plate = people.license_plate
  JOIN thief_passport_numbers ON thief_passport_numbers.passport_number = people.passport_number
  JOIN thief_ids ON thief_ids.person_id = people.id;

SELECT * FROM final_suspects;

--Step 9: Find the call that the thief made according to witness 3
CREATE TEMPORARY TABLE criminal_call AS
SELECT
  phone_calls.caller,
  phone_calls.receiver
FROM
  phone_calls,
  final_suspects
WHERE
  phone_calls.caller = final_suspects.phone_number
  AND year = 2021
  AND month = 7
  AND day = 28
  AND duration < 60;

SELECT * FROM criminal_call;

--Step 10: Find the thief as the caller and the accomplice as the receiver
SELECT
  people.name AS thief
FROM
  people,
  criminal_call
WHERE
  people.phone_number = criminal_call.caller;

SELECT
  people.name AS accomplice
FROM
  people,
  criminal_call
WHERE
  people.phone_number = criminal_call.receiver;