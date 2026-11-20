#include <iostream>
#include <cstring>
#include "Music.h"

using namespace std;

Music::Music(int years, char* name, char* publish, int time):Media(years, name)
{
  duration = time;
  artist = new char[strlen(publish) + 1];
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

Music::~Music()
{
  delete[] artist;
}

void Music::printAttributes()
{
  cout << "Media Type: Music" << endl;
  Super.printAttributes();
  cout << "Duration: " << duration << endl;
  cout << "Artist(s): " << artist << endl;
}

