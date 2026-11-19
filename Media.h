#ifndef MEDIA_H
#define MEDIA_H

class Media
{
 public:
  Media(int years, char* name);
  char* getName();
  int getYear();
  virtual ~Media();
 protected:
  char* title;
  int year;
};

#endif
