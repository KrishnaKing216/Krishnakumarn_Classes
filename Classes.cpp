/*
Nandan Krishnakumar
Student List - Galbraith C++/Data Structures
10/16/26 6:34 PM
Citations: https://cplusplus.com/reference/cstring/, Used ClaudeAI to debug on 10/16/26
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>
#include "Movie.h"
#include "Video_Game.h"
#include "Music.h"

using namespace std;

void addStudent(vector<Media*> &vect); //Function Prototypes
void printStudentList(vector<Media*> &vect);
void deleteStudent(vector<Media*> &vect);
char* getValidString();
char* getValidMedia();
int getValidInt();
float getValidRating();

int main()
{
  vector<Media*> mediaList; //initializing the vector of Media pointers
  char action[7] = "ADD"; //variable to keep track of what the user would like to do
  cout << "Welcome to your media database! Here you can keep track of all desired media, "
	  "add media, delete media, and see which media you have already recorded. Let's add a media to get started!" << endl;
  char* name = new char[13];
  strcpy(name, "Interstellar");
  char* publish = new char[18];
  strcpy(publish, "Christopher Nolan");
  float rating = 10.0f;
  int year = 2014;
  int time = 169;
  Media* m;
  m = new Movie(year, name, publish, rating, time);
  m->printAttributes();
  delete m;
  /*
  do //do...while loop to run the program. Starts with adding a student first by default.
  {
    if (strcmp(action, "ADD") == 0)
    {
      addStudent(studentList);
    }
    else if (strcmp(action, "PRINT") == 0)
    {
      printStudentList(studentList);
    }
    else if (strcmp(action, "DELETE") == 0)
    {
      deleteStudent(studentList);
    }
    else
    {
      cout << "INVALID COMMAND\nVALID COMMANDS: ADD, PRINT, DELETE, AND QUIT" << endl;
    }

    cout << "WHAT WOULD YOU LIKE TO DO?" << endl;
    cin.get(action, 7);
    if (cin.fail())
    {
      cin.clear();
      action[0] = '\0';
    }
	else if (cin.peek() != '\n') //This block was given by ClaudeAI to handle extra characters in the buffer if the user entered something longer than 6 chars in cin.
	{
		action[0] = '\0';
	}
	cin.ignore(1000, '\n');
  } while (strcmp(action, "QUIT") !=0);
  for (vector<Media*>::iterator it = mediaList.begin(); it != mediaList.end(); it++) //deleting all the heap addresses at the end to clean up memory
  {
	  delete (*it);
	  }*/
  return 0;
}

void addStudent(vector<Media*> &vect) //takes the inputs for name (first and last), student id, and student gpa from the user, adds them to a new student created in the heap with a pointer, which is then appended to the vector. This one was tough. ClaudeAI helped me debug and figure out that strcpy can't coppy the address one pointer is pointer is pointing to into another, even if they are the same data type pointer. Sorry Mr. Galbraith, I found out the hard way :(. Looks like we were wrong about that. I should have caught it because you said it  internally dereferences.
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
    cout << "Enter the duration duration (in minutes): ";
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
}

void searchMediaList(vector<Media*> &vect) //goes through all the student pointers in the vector, dereferences them, and prints their attributes
{
  int mediaNum = 1;
  cout << "SEARCH MEDIA DATABASE: " << endl;
  char decision;
  cout << "Would you like to search by title (t) or year (y)?: ";
  cin >> decision;
  if (decision == 't')
  {
    cout << "Enter the title of the media you wish to find: ";
    char* title = getValidString();
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
    delete[] title;
  }
  else if (decision == 'y')
  {
    cout << "Enter the year of the media you wish to find: ";
    int year = getValidInt();
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
    cout << "Invalid decision! Please try again!" << endl;
    return;
  }
}

void deleteMedia(vector<Media*> &vect) //Deletes the student with the given ID. Tells the user that the ID was not in the system if a student doesn't have that ID number
{
  int mediaNum = 0;
  vector<int> indexList;
  vector<Media*> ptrList;
  cout << "DELETE FROM MEDIA DATABASE: " << endl;
  char decision;
  cout << "Would you like to search by title (t) or year (y)?: ";
  cin >> decision;
  char del;
  if (decision == 't')
  {
    cout << "Enter the title of the media you wish to delete: ";
    char* title = getValidString();
    for (vector<Media*>::iterator it = vect.begin(); it != vect.end();)
    {
      if (strcmp(title, (*it)->getName()) == 0)
      {
	cout << "Would you like to delete '" << (*it)->getName() << "'? (y/n): ";
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
    delete[] title;
  }
  else if (decision == 'y')
  {
    cout << "Enter the year of the media you wish to delete: ";
    int year = getValidInt();
    cout << "The following media were released in the year " << year << ": " << endl;
    for (vector<Media*>::iterator it = vect.begin(); it != vect.end();)
    {
      if ((*it)->getYear() == year)
      {
	cout << "Would you like to delete '" << (*it)->getName() << "'? (y/n): ";
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
    cout << "Invalid decision! Please try again!" << endl;
    return;
  }
}

char* getValidString() //Function to create a char array that holds either the first or last name of the student (depending on the order) and returns a pointer to the char array. Clears input stream of any extra characters for future inputs and handles all memory leaks if a failbit is triggered or the input is taken successfully
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
    cin.clear();
    cin.ignore(1000, '\n');
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

int getValidInt() //Gets ID numbers (as ints) from the user and handles all cin failbits, as well as clearing the input stream for future inputs
{
  while (true)
  {
    int num;
    cin >> num;
    if (cin.fail())
    {
        cout << "Enter an ID number" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        continue;
    }
    cin.ignore(1000,'\n');
    return num;
  }
}

float getValidRating() //Gets GPA numbers (as floats) from the user and handles all cin failbits, as well as clearing the input stream for future inputs
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
    else if((rate > 10.0f) || (rate < 0.0f))
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
