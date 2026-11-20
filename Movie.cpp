#include <iostream>
#include<cstring>
#include "Movie.h"

using namespace std;

Movie::Movie(int years, char* name, char* publish, int rate, int time):Media(years, name)
{
  duration = time;
  director = new char[strlen(publish) + 1];
  strcpy(director, publish);
  rating = rate;
}

char* Movie::getDirector()
{
  return director
}

int Movie::getDuration()
{
  return duration;
}

int Movie::getRating()
{
  return rating
}

Movie::~Movie()
{
  delete[] director;
}

void Movie::printAttributes()
{
  cout << "Media Type: Movie" << endl;
  Media::printAttributes();
  cout << "Duration: " << duration << endl;
  cout << "Director: " << director << endl;
  cout << "Rating (out of 10): " << rating << endl;
}
