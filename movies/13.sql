SELECT
    name
FROM
    kevin_movies, stars, people
WHERE
    kevin_movies.id = stars.movie_id
    AND people.id = stars.people_id
    AND name != 'Kevin Bacon'
    AND title IN
    (
        SELECT
            title
        FROM
            movies, stars, people
        WHERE
            movies.id = stars.movie_id
            AND people.id = stars.people_id
            AND name = 'Kevin Bacon'
            AND birth = 1958
        AS kevin_movies
    );