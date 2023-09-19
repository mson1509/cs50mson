SELECT DISTINCT
  (name)
FROM
  people,
  movies,
  stars
WHERE
  movies.id = stars.movie_id
  AND stars.person_id = people.id
  AND YEAR = 2004
ORDER BY
  birth;