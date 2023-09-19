SELECT
    name
FROM
    movies, stars, people
WHERE
    movies.id = stars.movie_id
    AND people.id = stars.person_id
    AND name != 'Kevin Bacon'
    AND title IN
    (
        SELECT
            title
        FROM
            movies, stars, people
        WHERE
            movies.id = stars.movie_id
            AND people.id = stars.person_id
            AND name = 'Kevin Bacon'
            AND birth = 1958
    );