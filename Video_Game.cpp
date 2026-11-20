#include <iostream>
#include <cstring>
#include "Video_Game.h"

using namespace std;

videoGame::videoGame(int years, char* name, char* publish, float rate):Media(years, name)
{
  rating = rate;
  publisher = new char[strlen(publish) + 1];
  strcpy(publisher, publish);
}

char* videoGame::getPublisher()
{
  return publisher;
}

float videoGame::getRating()
{
  return rating;
}

videoGame::~videoGame()
{
  delete[] publisher;
}

void videoGame::printAttributes()
{
  cout << "Media Type: Video Game" << endl;
  Media::printAttributes();
  cout << "Rating (out of 10): " << rating << endl;
  cout << "Publisher: " << publisher << endl;
}
