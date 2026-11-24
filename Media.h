#ifndef MEDIA_H
#define MEDIA_H
//header for Parent Media Class. Contains the constructor, getter methods for protected variables, and defines protected variables. Contains header guard
class Media
{
 public:
  Media(int years, char* name);
  char* getName();
  int getYear();
  virtual ~Media();
  virtual void printAttributes();
 protected:
  char* title;
  int year;
};

#endif
