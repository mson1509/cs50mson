SELECT
  brad_movies.title
FROM
  (
    SELECT
      title
    FROM
      movies,
      stars,
      people
    WHERE
      movies.id = stars.movie_id
      AND people.id = stars.person_id
      AND name = 'Bradley Cooper'
  ) AS brad_movies
  INNER JOIN (
    SELECT
      title
    FROM
      movies,
      stars,
      people
    WHERE
      movies.id = stars.movie_id
      AND people.id = stars.person_id
      AND name = 'Jennifer Lawrence'
  ) AS jen_movies ON brad_movies.title = jen_movies.title;