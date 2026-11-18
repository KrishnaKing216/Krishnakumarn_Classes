#include "Media.h"
#include <cstring>

using namespace std;

Media::Media(int years, char* name)
{
  year = years;
  strcpy(title, name);
}

char* Media::getName()
{
  return title
}

int Media::getYear()
{
  return year;
}
