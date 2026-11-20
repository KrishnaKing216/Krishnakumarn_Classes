#ifndef MUSIC_H
#define MUSIC_H

#include "Media.h"

class Music : public Media
{
 public:
  Music(int years, char* name, char* publish, int time);
  char* getPublisher();
  int getRating();
  ~Music();
  void printAttributes();
 private:
  char* artist;
  int duration;
};

#endif
