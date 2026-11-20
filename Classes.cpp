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
char* getValidName(int order);
int getValidID();
float getValidGPA();

int main()
{
  vector<Media*> mediaList; //initializing the vector of Media pointers
  char action[7] = "ADD"; //variable to keep track of what the user would like to do
  cout << "Welcome to media list! Here you can keep track of all desired media, "
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
  Media* newMedia
  char* first = getValidName(1);
  char* last = getValidName(2);
  int studentID = getValidID();
  float gpa = getValidGPA();

  strcpy(newStudent->firstName, first);
  strcpy(newStudent->lastName, last);
  newStudent->id = studentID;
  newStudent->GPA = gpa;

  vect.push_back(newStudent);
  cout << "New Student Added!" << endl;
  delete[] first; //Preventing memory leaks
  delete[] last;
}

void printStudentList(vector<Media*> &vect) //goes through all the student pointers in the vector, dereferences them, and prints their attributes
{
  int studentNum = 1;
  for (vector<Media*>::iterator it = vect.begin(); it != vect.end(); it++)
  {
    cout << "Student " << studentNum << ":" << endl;
    cout << "First Name: " << (*it)->firstName << endl;
    cout << "Last Name: " << (*it)->lastName << endl;
    cout << "ID: " << (*it)->id << endl;
    cout << "GPA: " << fixed << setprecision(2) << (*it)->GPA << endl;
    cout << endl;
    studentNum++;
  }
}

void deleteStudent(vector<Media*> &vect) //Deletes the student with the given ID. Tells the user that the ID was not in the system if a student doesn't have that ID number
{
  int deleteID = getValidID();
  for (vector<Media*>::iterator it = vect.begin(); it != vect.end(); it++)
  {
    if ((*it)->id == deleteID)
    {
      delete(*it);
      vect.erase(it);
      cout << "Student deleted!" << endl;
      return;
    }
  }
  cout << "ID number not in system." << endl;
}

char* ge
tValidString() //Function to create a char array that holds either the first or last name of the student (depending on the order) and returns a pointer to the char array. Clears input stream of any extra characters for future inputs and handles all memory leaks if a failbit is triggered or the input is taken successfully
{
  while (true)
  {
    char* name;
    name = new char[81];
    cin.getline(name, 81);
    if (cin.fail())
    {
        cout << "Enter a valid name" << endl;
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

int getValidID() //Gets ID numbers (as ints) from the user and handles all cin failbits, as well as clearing the input stream for future inputs
{
  while (true)
  {
    int ID;
    cout << "What is the student's ID number?: " << endl;
    cin >> ID;
    if (cin.fail())
    {
        cout << "Enter an ID number" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        continue;
    }
	cin.ignore(1000,'\n');
    return ID;
  }
}

float getValidRating() //Gets GPA numbers (as floats) from the user and handles all cin failbits, as well as clearing the input stream for future inputs
{
  while (true)
  {
    float rate;
    cout << "What is the rating?: " << endl;
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
    return grades;
  }      
}
