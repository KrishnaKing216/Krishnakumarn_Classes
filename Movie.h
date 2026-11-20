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
  void printAttributes();
 private:
  char* director;
  float rating;
  int duration;
};

#endif
