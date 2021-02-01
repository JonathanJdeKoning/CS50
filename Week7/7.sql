select title, rating from movies join ratings on movies.id = ratings.movie_id where year = 2010 ORDER BY rating DESC, title ASC
