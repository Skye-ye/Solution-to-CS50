select name from movies, stars, people
   ...> where movies.id = stars.movie_id
   ...> and stars.person_id = people.id
   ...> and title = 'Toy Story';