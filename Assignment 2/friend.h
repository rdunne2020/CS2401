/************************************************
   This is the header file for a class called Friend.
   It holds the information about a single Facebook
   friend, just their name and birthday. It uses a class
   called Date for the storage of the birthday. The member
   functions are just accessors and input/output functions.
       John Dolan	Spring 2014	Ohio University
***********************************************************/
#ifndef FRIEND_H
#define FRIEND_H
#include<iostream>
#include<string>
#include<algorithm>
#include "date.h"

class Friend{
    public:

	Friend() //Constructor
  {
  name = "No name";
  }

	std::string get_name()const
  {
    return name;
  }

	Date get_bday()const
  {
    return bday;
  }
	bool operator == (const Friend& other)const;

	bool operator != (const Friend& other)const;

	void input(std::istream& ins);
	void output(std::ostream& outs)const;

    private:

	std::string name;
	Date bday;
};

std::istream& operator >>(std::istream& ins,Friend& f);

std::ostream& operator <<(std::ostream& outs,const Friend& f);

#endif
