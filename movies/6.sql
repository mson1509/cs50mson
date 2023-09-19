SELECT
  AVG(rating)
FROM
  movies,
  ratings
WHERE
  movies.id = ratings.movie_id
  AND YEAR = '2012';