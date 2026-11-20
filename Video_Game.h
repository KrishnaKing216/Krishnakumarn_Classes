#ifndef VIDEO_GAME_H
#define VIDEO_GAME_H

#include "Media.h"

class videoGame : public Media
{
 public:
  videoGame(int years, char* name, char* publish, int rating);
  char* getPublisher();
  int getRating();
  ~videoGame();
  void printAttributes();
 private:
  char* publisher;
  int rating;
};

#endif
