#ifndef MOVIE_H
#define MOVIE_H

#include "Media.h"

class Movie : public Media
{
 public:
  Movie(int years, char* name, char* publish, int rate, int time);
  char* getDirector();
  int getDuration();
  int getRating();
  ~Movie();
 private:
  char* director;
  int rating;
  int duration;
};

#endif
