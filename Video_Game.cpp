#include <cstring>
#include "Video_Game.h"

using namespace std;

Video_Game::videoGame(int years, char* name, char* publish, float rate):Media(years, name)
{
  rating = rate;
  publisher = new char[strlen(publish) + 1];
  strcpy(publisher, publish);
}

char* Video_Game::getPublisher()
{
  return publisher
}

float Video_Game::getRating()
{
  return rating;
}

Video_Game::~videoGame()
{
  delete[] publisher;
}
