SELECT
    name
FROM
    movies, stars, people
WHERE
    movies.id = stars.movie_id
    AND people.id = stars.people_id
    AND name 