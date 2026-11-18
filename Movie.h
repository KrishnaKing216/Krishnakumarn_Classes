#ifndef MOVIE_H
#define MOVIE_H

#include "Media.h"

class Movie : public Media
{
 public:
  Movie(int years, char* name, char* publish, int rate, int time);
  virtual char* getDirector();
  virtual int getDuration();
  virtual int getRating();
 private:
  char director[16];
  int rating;
  int duration;
};

#endif
