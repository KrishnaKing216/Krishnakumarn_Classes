#ifndef VIDEO_GAME_H
#define VIDEO_GAME_H

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
