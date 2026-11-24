#ifndef MOVIE_H
#define MOVIE_H
//header for the Movie child class (inherits publicly from Media). Contains the constructor, getter methods for the private variables, the destructor, and the overridden printAttributes. Contains header guard
#include "Media.h"

class Movie : public Media
{
 public:
  Movie(int years, char* name, char* publish, float rate, int time);
  char* getDirector();
  int getDuration();
  float getRating();
  ~Movie();
  void printAttributes();
 private:
  char* director;
  float rating;
  int duration;
};

#endif
