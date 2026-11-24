#ifndef MUSIC_H
#define MUSIC_H
//header for the Movie child class (inherits publicly from Media). Contains the constructor, getter methods for the private variables, the destructor, and the overridden printAttributes. Contains header guard
#include "Media.h"

class Music : public Media
{
 public:
  Music(int years, char* name, char* publish, char* performer, int time);
  char* getPublisher();
  char* getArtist();
  int getDuration();
  ~Music();
  void printAttributes();
 private:
  char* publisher;
  char* artist;
  int duration;
};

#endif
