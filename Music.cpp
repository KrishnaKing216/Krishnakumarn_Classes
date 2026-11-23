#include <iostream>
#include <cstring>
#include "Music.h"

using namespace std;

Music::Music(int years, char* name, char* publish, char* performer, int time):Media(years, name)
{
  duration = time;
  publisher = new char[strlen(publish) + 1];
  artist = new char[strlen(performer) + 1];
  strcpy(publisher, publish);
  strcpy(artist, performer);
}

char* Music::getPublisher()
{
  return publisher;
}

char* Music::getArtist()
{
  return artist;
}

int Music::getDuration()
{
  return duration;
}

Music::~Music()
{
  delete[] publisher;
  delete[] artist;
}

void Music::printAttributes()
{
  cout << "Media Type: Music" << endl;
  Media::printAttributes();
  cout << "Duration: " << duration << endl;
  cout << "Artist(s): " << artist << endl;
}

