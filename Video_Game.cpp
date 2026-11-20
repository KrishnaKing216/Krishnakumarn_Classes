#include <iostream>
#include <cstring>
#include "Video_Game.h"

using namespace std;

Video_Game::videoGame(int years, char* name, char* publish, int rate):Media(years, name)
{
  rating = rate;
  publisher = new char[strlen(publish) + 1];
  strcpy(publisher, publish);
}

char* Video_Game::getPublisher()
{
  return publisher
}

int Video_Game::getRating()
{
  return rating;
}

Video_Game::~videoGame()
{
  delete[] publisher;
}

void Music::printAttributes()
{
  cout << "Media Type: Video Game" << endl;
  Media::printAttributes();
  cout << "Rating (out of 10): " << rating << endl;
  cout << "Publisher: " << publisher << endl;
}
