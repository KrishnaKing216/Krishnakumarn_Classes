#include <cstring>
#include "Music.h"

using namespace std;

Music::Music(int years, char* name, char* publish, int time):Media(years, name)
{
  duration = time;
  strcpy(artist, publish);
}

char* Music::getArtist()
{
  return artist
}

int Music::getDuration()
{
  return duration;
}
