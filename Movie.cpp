#include <cstring>
#include "Movie.h"

using namespace std;

Movie::Movie(int years, char* name, char* publish, float rate, int time):Media(years, name)
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

float Movie::getRating()
{
  return rating
}

Movie::~Movie()
{
  delete[] director;
}
