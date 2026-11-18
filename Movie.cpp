#include <cstring>
#include "Movie.h"

using namespace std;

Movie::Movie(int years, char* name, char* publish, int rate, int time):Media(years, name)
{
  duration = time;
  strcpy(diretor, publish);
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
