/************************************************************************
	This class contains the name for the student plus a head node for a
  linked list
		Rory  Dunne	CS2401		10/15/17
************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "node.h"
#include "course.h"

#ifndef COLLEGE_H
#define COLLEGE_H

class College{

  public:
    College(std::string s) //constructor
    {
      name = s;
      head = NULL;
    }

//---------------------------------------------//

    //BIG3
////////////////////////////////////////
    ~College(); //Destructor
////////////////////////////////////////
    College(const College& other); //Copy Constructor
////////////////////////////////////////
    College operator = (const College& other); //Assignment Operator

//---------------------------------------------//

    void add(course c);
    void display(std::ostream& outs);
    void remove(std::string s);
    int hours();
    double gpa();
    void load(std::istream& ins);
    void save(std::ostream& outs);

  private:
    std::string name;
    node* head;

};

#endif
