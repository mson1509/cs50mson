SELECT DISTINCT
    (people.name)
FROM
    people
JOIN stars
    ON people.id = stars.person_id
JOIN movies
    ON movies.id = stars.movie_id
WHERE
    people.name != 'Kevin Bacon'
    AND movies.title IN
    (
        SELECT
            movies.title
        FROM
            movies
        JOIN stars
            ON movies.id = stars.movie_id
        JOIN people
            ON people.id = stars.person_id
        AND people.name = 'Kevin Bacon'
        AND people.birth = 1958
    );