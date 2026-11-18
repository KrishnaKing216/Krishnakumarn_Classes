#ifndef MEDIA_H
#define MEDIA_H

class Media
{
 public:
  Media(int years, char* name);
  virtual char* getName();
  virtual int getYear();
 protected:
  char title[16];
  int year;
};

#endif
