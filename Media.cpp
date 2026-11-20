#include <iostream>
#include "Media.h"
#include <cstring>

using namespace std;

Media::Media(int years, char* name)
{
  year = years;
  title = new char[strlen(name) + 1]; //Received this instruction on how to create an array of unfixed size to copy into based on the size of the input argument from claude. Carried over in all children
  strcpy(title, name);
}

char* Media::getName()
{
  return title;
}

int Media::getYear()
{
  return year;
}

Media::~Media()
{
  delete[] title;
}

void Media::printAttributes()
{
  cout << "Title: " << title << endl;
  cout << "Year Released: " << year << endl;
}
