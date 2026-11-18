#include <cstring>
#include "Video_Game.h"

using namespace std;

Video_Game::videoGame(int years, char* name, char* publish, int rate):Media(years, name)
{
  rating = rate;
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
