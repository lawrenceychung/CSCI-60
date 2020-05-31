#include <iostream>
#include <string>
using namespace std;

class Movie
{
public:
    Movie(string movie_name, string movie_rating, float movie_earnings)
    {
        name = movie_name;
        rating = movie_rating;
        earnings = movie_earnings;
    }
    Movie()
    {
        name = "unknowned";
        rating = "G";
        earnings = 0;
    }
    // pre condition - nothing
    string get_name()
    {
      return name;
    }
    // post condition - returns the name

    // pre condition - nothing
    string get_rating()
    {
      return rating;
    }
    // post condition - returns the rating

    // pre condition - nothing
    float get_earnings()
    {
        return earnings;
    }
    // post condition - returns the earnings from a movie

    // pre condition - nothing
    void set_name(string movie_name)
    {
        name = movie_name;
    }
    //post condition - sets the movie name as name

    // pre condition - nothing
    void set_rating(string movie_rating)
    {
        rating = movie_rating;
    }
    //post condition - sets the movie rating as rating

    // pre condition - nothing
    void set_earnings(float movie_earnings)
    {
        earnings = movie_earnings;
    }
    //post condition - sets the movie earnings as earnigns

    //pre condition - takes in the number of people for a specific viewing of the movie
    void MovieShowing(int n)
    {
        earnings += n * 12;
    }
    //post condition - updates the earnings with this showing of the movie_earnings

    //pre condiiton - takes in a Movie class variable
    Movie MergeMovie(Movie m)
    {
        if (name == m.get_name())
        {
            Movie combined;
            combined.name = name + " combined";
            if (rating == "R" || m.rating == "R")
            {
                combined.rating = "R";
            }
            else if (rating == "PG-13" || m.rating == "PG-13")
            {
                combined.rating = "PG-13";
            }
            else if (rating == "PG" || m.rating == "PG")
            {
                combined.rating = "PG";
            }
            else
            {
                combined.rating = "G";
            }

            combined.earnings += earnings + m.get_earnings();

            return combined;
        }
        else
        {
            Movie not_combined ("Could not combine", "N/A", 0);
            return not_combined;
        }
    }
    //post condition - if the variable pass through has the same name as another variable of class Movie, then it will combine its ratings and earnings, and return another variable of class Movie with the combined values
private:
    string name;
    string rating;
    float earnings;
};

int main()
{
    Movie A ("Iron Man", "PG", 100000);
    Movie B ("Iron Man", "PG-13", 100000);
    Movie C;

    A.MovieShowing(25);

    Movie D = C.MergeMovie(B);

    cout<< D.get_name() << endl;
    cout<< D.get_rating() << endl;
    cout<< D.get_earnings() << endl;

    return 0;
}
