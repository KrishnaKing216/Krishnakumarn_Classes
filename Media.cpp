#include <ostream>
#include "Media.h"
#include <cstring>

class Media
{
  Media::Media(int years, char* name)
  {
    year = years;
    strcpy(title, name);
  }
}
