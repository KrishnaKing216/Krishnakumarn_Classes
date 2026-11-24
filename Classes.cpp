/*
Nandan Krishnakumar
Classes - Galbraith C++/Data Structures
11/22/26 11:34 PM
Citations: Student List project used for main file (Classes.cpp), Used ClaudeAI to debug on 11/22/26
*/
#include <iostream>
#include <vector>
#include <cstring>
#include "Movie.h"
#include "Video_Game.h"
#include "Music.h"

using namespace std;

void addMedia(vector<Media*> &vect); //Function Prototypes
void searchMediaList(vector<Media*> &vect);
void deleteMedia(vector<Media*> &vect);
char* getValidString();
char* getValidMedia();
int getValidInt();
float getValidRating();
bool titleOrYearInDatabase(vector<Media*> &vect, char* name = NULL, int year = -1);

int main()
{
  vector<Media*> mediaList; //initializing the vector of Media pointers
  char action[7] = "ADD"; //variable to keep track of what the user would like to do
  cout << "Welcome to your media database! Here you can keep track of all desired media by "
	  "adding media, deleting media, and seeing which media you have already recorded. Let's add a media to get started!" << endl;
  do //do...while loop to run the program. Starts with adding a new media first by default.
  {
    if (strcmp(action, "ADD") == 0)
    {
      addMedia(mediaList);
    }
    else if (strcmp(action, "SEARCH") == 0)
    {
      searchMediaList(mediaList);
    }
    else if (strcmp(action, "DELETE") == 0)
    {
      deleteMedia(mediaList);
    }
    else
    {
      cout << "INVALID COMMAND\nVALID COMMANDS: ADD, SEARCH, DELETE, AND QUIT" << endl;
    }

    cout << "WHAT WOULD YOU LIKE TO DO?" << endl;
    cin.get(action, 7);
    if (cin.fail())
    {
      cin.clear();
      action[0] = '\0';
    }
    else if (cin.peek() != '\n') //This block was given by ClaudeAI to handle extra characters in the buffer if the user entered something longer than 6 chars in cin (this comment was from Student List)
    {
      action[0] = '\0';
    }
	cin.ignore(1000, '\n');
  } while (strcmp(action, "QUIT") !=0);
  for (vector<Media*>::iterator it = mediaList.begin(); it != mediaList.end(); it++) //deleting all the heap addresses at the end to clean up memory
  {
    delete (*it);
  }
  return 0;
}

void addMedia(vector<Media*> &vect) //asks the user for a media type, then prompts for that type's fields (title, year, publisher/director/artist, rating, duration). Creates the matching Music, Movie, or videoGame object on the heap and appends its pointer to the vector. The temporary strings from getValidString are deleted afterwards because the media objects keep their own copies.
{
  
  char* mType = getValidMedia();
  Media* newMedia;
  if (strcmp(mType, "Music") == 0)
  {
    cout << "Enter the song title: ";
    char* title = getValidString();
    cout << "Enter the year the song was released: ";
    int year = getValidInt();
    cout << "Enter the song's publisher: ";
    char* publisher = getValidString();
    cout << "Enter the song artist: ";
    char* artist = getValidString();
    cout << "Enter the song duration (in minutes): ";
    int time = getValidInt();
    newMedia = new Music(year, title, publisher, artist, time);
    vect.push_back(newMedia);
    delete[] title;
    delete[] publisher;
    delete[] artist;
  }
  else if (strcmp(mType, "Movie") == 0)
  {
    cout << "Enter the movie title: ";
    char* title = getValidString();
    cout << "Enter the year the movie was released: ";
    int year = getValidInt();
    cout << "Enter the movie's director: ";
    char* director = getValidString();
    cout << "Enter the movie rating: ";
    float rating = getValidRating();
    cout << "Enter the duration (in minutes): ";
    int time = getValidInt();
    newMedia = new Movie(year, title, director, rating, time);
    vect.push_back(newMedia);
    delete[] title;
    delete[] director;
  }
  else
  {
    cout << "Enter the video game title: ";
    char* title = getValidString();
    cout << "Enter the year the video game was released: ";
    int year = getValidInt();
    cout << "Enter the video game's publisher: ";
    char* publisher = getValidString();
    cout << "Enter the video game rating: ";
    float rating = getValidRating();
    newMedia = new videoGame(year, title, publisher, rating);
    vect.push_back(newMedia);
    delete[] title;
    delete[] publisher;
  }
  cout << "Media Added" << endl;
  delete[] mType;
}

void searchMediaList(vector<Media*> &vect) //goes through all the media pointers in the vector, dereferences them, and prints their attributes

{
  int mediaNum = 1;
  cout << "SEARCH MEDIA DATABASE: " << endl;
  char decision;
  cout << "Would you like to search by title (t) or year (y)?: ";
  cin >> decision;
  cin.ignore(1000, '\n');
  if (decision == 't')
  {
    cout << "Enter the title of the media you wish to find: ";
    char* title = getValidString();
    if (titleOrYearInDatabase(vect, title))
    {
      cout << "The following media had the title '" << title << "': " << endl;
      for (vector<Media*>::iterator it = vect.begin(); it != vect.end(); it++)
      {
	if (strcmp(title, (*it)->getName()) == 0)
	{
	  cout << mediaNum << ":" << endl;
	  (*it)->printAttributes();
	  mediaNum++;
	}
      }
    }
    else
    {
      cout << "No stored media associated with that title! Please try again!" << endl;
    }
    delete[] title;
  }
  else if (decision == 'y')
  {
    cout << "Enter the year of the media you wish to find: ";
    int year = getValidInt();
    if (titleOrYearInDatabase(vect, NULL, year))
    {
      cout << "The following media were released in the year " << year << ": " << endl;
      for (vector<Media*>::iterator it = vect.begin(); it != vect.end(); it++)
      {
	if ((*it)->getYear() == year)
	{
	  cout << mediaNum << ":" << endl;
	  (*it)->printAttributes();
	  mediaNum++;
	}
      }
    }
    else
    {
      cout << "No stored media associated with that year! Please try again!" << endl;
    }
  }
  else
  {
    cout << "Invalid decision! Please try again!" << endl;
    return;
  }
}

void deleteMedia(vector<Media*> &vect) //searches by title or year like searchMediaList, then asks the user to confirm each match. Confirmed media are deleted (running the destructors) and erased from the vector. Tells the user if nothing matches.
{
  cout << "DELETE FROM MEDIA DATABASE: " << endl;
  char decision;
  cout << "Would you like to search by title (t) or year (y)?: ";
  cin >> decision;
  cin.ignore(1000, '\n');
  char del;
  if (decision == 't')
  {
    cout << "Enter the title of the media you wish to delete: ";
    char* title = getValidString();
    if (titleOrYearInDatabase(vect, title))
    {
      for (vector<Media*>::iterator it = vect.begin(); it != vect.end();)
      {
	if (strcmp(title, (*it)->getName()) == 0)
	{
	  cout << "Would you like to delete '" << (*it)->getName() << "'? (y/n): ";
	  cin >> del;
	  cin.ignore(1000, '\n');
	  if (del == 'y')
	  {
	    delete (*it);
	    it = vect.erase(it);
	    cout << "Deleted" << endl;
	  }
	  else
	  {
	    cout << "Not deleting '" << (*it)->getName() << "'" << endl;
	    it++;
	  }
	}
	else
	{
	  it++;
	}
      }
    }
    else
    {
      cout << "No stored media associated with that title! Please try again!" << endl;
    }
    delete[] title;
  }
  else if (decision == 'y')
  {
    cout << "Enter the year of the media you wish to delete: ";
    int year = getValidInt();
    if (titleOrYearInDatabase(vect, NULL, year))
    {
      for (vector<Media*>::iterator it = vect.begin(); it != vect.end();)
      {
	if ((*it)->getYear() == year)
	{
	  cout << "Would you like to delete '" << (*it)->getName() << "'? (y/n): ";
	  cin >> del;
	  cin.ignore(1000, '\n');
	  if (del == 'y')
	  {
	    delete (*it);
	    it = vect.erase(it);
	    cout << "Deleted" << endl;
	  }
	  else
	  {
	    it++;
	  }
	}
	else
	{
	  it++;
	}
      }
    }
    else
    {
      cout << "No stored media associated with that year! Please try again!" << endl;
    }
  }
  else
  {
    cout << "Invalid decision! Please try again!" << endl;
    return;
  }
}

char* getValidString() //Function to create a valid cstring and returns a pointer to the char array. Clears input stream of any extra characters for future inputs and handles all memory leaks if a failbit is triggered or the input is taken successfully
{
  while (true)
  {
    char* name;
    name = new char[81];
    cin.getline(name, 81);
    if (cin.fail())
    {
        cout << "Enter a valid string" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
	delete[] name; //Avoids memory leak... THANK GOD I CAUGHT THAT
        continue;
    }
    return name;
  }
}

char* getValidMedia()
{
  char* type = new char[11];
  while (true)
  {
    cout << "Which Media type would you like?: " << endl;
    cin.get(type, 11);
    if (cin.fail())
    {
        cout << "Enter a valid string" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        continue;
    }
    else if ((strcmp(type, "Video Game") != 0) && (strcmp(type, "Movie") != 0) && (strcmp(type, "Music") != 0))
    {
      cout << "Invalid Media type! Try again! Valid Media types: Movie, Video Game, Music" << endl;
      cin.ignore(1000, '\n');
      continue;
    }
    cin.ignore(1000, '\n');
    return type;
  }
}

int getValidInt() //Gets ints from the user and handles all cin failbits, as well as clearing the input stream for future inputs
{
  while (true)
  {
    int num;
    cin >> num;
    if (cin.fail())
    {
        cout << "Enter a valid number" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        continue;
    }
    cin.ignore(1000,'\n');
    return num;
  }
}

float getValidRating() //Gets rating numbers (as floats) from the user and handles all cin failbits, as well as clearing the input stream for future inputs
{
  while (true)
  {
    float rate;
    cin >> rate;
    if (cin.fail())
    {
	cout << "Enter a valid rating" << endl;
	cin.clear();
	cin.ignore(1000, '\n');
	continue;
    }
    else if((rate > 10.0f) || (rate < 1.0f))
    {
      cout << "Enter a valid rating between 1 and 10" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
      continue;
    }
    cin.ignore(1000,'\n');
    return rate;
  }      
}

bool titleOrYearInDatabase(vector<Media*> &vect, char* name, int year) //tells program if there is at least one instance of an object with a certain title or year in the database before printing out all instances. This helps to print the message in the case where there are no media objects in the database that match
{
  for (vector<Media*>::iterator it = vect.begin(); it != vect.end(); it++)
  {
    if (name != NULL)
    {
      if (strcmp((*it)->getName(), name) == 0)
      {
	  return true;
      }
    }
    if (year != -1)
    {
      if ((*it)->getYear() == year)
      {
	return true;
      }
    }
  }
  return false;
}
