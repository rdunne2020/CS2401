/***********************************************************************
	The implementation file for college.h, which is allowing changes to be
  made to a list of courses.
		Rory Dunne		CS2401		10-15-17
**************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include "college.h"
#include "course.h"
#include "node.h"

using namespace std;

//------------------------------------------------//
    //BIG3

College::~College()
{
  node* rmptr;

  while (head != NULL)
  {
    rmptr = head;
    head = head -> link();
    delete rmptr;
  }
  //head = NULL;
}

College::College(const College& other)
{
  if (other.head == NULL)
  {
      head = NULL;
  }

  else
  {
    node* sptr, *dptr/*where we're copying to*/;
    head = new node(other.head -> data());
    sptr = other.head -> link();
    dptr = head;
      while(sptr != NULL)
      {
        dptr /*-> link() */-> set_link(new node(sptr -> data()));
        dptr = dptr -> link();
        sptr = sptr -> link();
      }

  }

}

College College::operator = (const College& other)
{
  if (this == &other)
    {
      return *this;
    }

if (other.head == NULL)
{
    head = NULL;
}

else
{
  node* sptr, *dptr/*where we're copying to*/;
  head = new node(other.head -> data());
  sptr = other.head -> link();
  dptr = head;
    while(sptr != NULL)
    {
      dptr -> set_link(new node(sptr -> data()));
      dptr = dptr -> link();
      sptr = sptr -> link();
    }
  delete sptr;
}

}
//------------------------------------------------//

void College::add(course c)
{
  if (head == NULL)
  {
    head = new node;
    head -> set_data(c);
    head -> set_link(NULL);
  }

  else
  {
    node* tmp = head;
    while (tmp -> link() != NULL)
    {
      tmp = tmp -> link();
      if (tmp -> link() == NULL)
      {
        break;
      }

    }
    tmp -> set_link(new node);
    tmp = tmp -> link();
    tmp -> set_data(c);
    tmp -> set_link(NULL);
  }
}

void College::display(ostream& outs)
{
  node* cursor = head;
//compare addresses of cout and outs
  if (head == NULL)
  {
    cout << "There is no list\n";
  }

    while (cursor != NULL)
    {
      cout << cursor -> data();
      cout << endl;
      cursor = cursor -> link();
    }

}

void College::remove(string s)
{

  if (head == NULL) {return;}

  else if (head -> data().get_course_number() == s)
  {
    node* tmp;
    tmp = head;
    head = head -> link();
    delete tmp;
  }

  else
  {
    node* cursor = head -> link();
    node* prev = head;

    while (cursor != NULL && cursor -> data().get_course_number() != s)

      {
        prev = cursor;
        cursor = cursor -> link();
      }

    if (cursor != NULL)
    {
      prev -> set_link(cursor -> link());
      delete cursor;
    }

  }
}

int College::hours()
{
  node* cursor = head;
  int hours = 0;

    if (head == NULL)
    {
      cout << "There is no list yet." << endl;
    }

    while(cursor != NULL)
    {
      hours += cursor -> data().get_hours();
      cursor = cursor -> link();
    }

  return hours;
  //returns the hours (an int)
}

double College::gpa()
{
  node* cursor = head;
  double gpa = 0;
  double points = 0;
  int hours = 0;

  if (head == NULL)
  {
    cout << "There is no list yet." << endl;
  }

  while(cursor != NULL)
  {
      points += (cursor -> data().get_number_grade() *
      cursor -> data().get_hours());

      hours += cursor -> data().get_hours();

      cursor = cursor -> link();
  }

  gpa = points / hours;

  return gpa;
}

void College::load(istream& ins)
{
  course temp; //for loading in the college Object
  node* cursor;
  int i = 0;

  ins >> temp; //start of sentinel loop

  while (!ins.eof() /*i < 5*/)
  {
    while (ins.peek() == '\r' || ins.peek() == '\n') {ins.ignore();} //checking to make sure it's not skipping anything
    //why did this fix it ^?
    if (head == NULL)
    {
      head = new node;
      cursor = head;
      cursor -> set_data(temp);
    }
    else
    {
      cursor -> set_link(new node);
      cursor = cursor -> link();
      cursor -> set_data(temp);
    }

    ins >> temp;
    i++;
  }

}

void College::save(ostream& outs)
{
    node* cursor;
    cursor = head;

      if (head == NULL)
      {
        cout << "There is no list to save" << endl;
      }

          while (cursor != NULL)
          {
            outs << cursor -> data();
            outs << endl;
            cursor = cursor -> link();
          }
}
