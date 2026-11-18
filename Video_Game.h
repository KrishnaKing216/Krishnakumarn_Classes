#ifndef VIDEO_GAME_H
#define VIDEO_GAME_H

#include "Media.h"

class videoGame : public Media
{
 public:
  videoGame(int years, char* name, char* publish, int rating);
  virtual char* getPublisher();
  virtual int getRating();
 private:
  char publisher[16];
  int rating;
};

#endif
