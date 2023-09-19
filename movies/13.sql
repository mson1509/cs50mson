SELECT
    name
FROM
    movies, stars, people
WHERE
    movies.id = stars.movie_id
    AND people.id = stars.people_id
    AND title IN kevin_movies;