#ifndef VIDEO_GAME_H
#define VIDEO_GAME_H
//header for the videoGame child class (inherits publicly from Media). Contains the constructor, getter methods for the private variables, the destructor, and the overridden printAttributes. Contains header guard
#include "Media.h"

class videoGame : public Media
{
 public:
  videoGame(int years, char* name, char* publish, float rating);
  char* getPublisher();
  float getRating();
  ~videoGame();
  void printAttributes();
 private:
  char* publisher;
  float rating;
};

#endif
