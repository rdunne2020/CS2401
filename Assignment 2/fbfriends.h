 /*****************************************************
   This class is a container that holds Friends of the
   class Friend. It uses an internal iterator to give the
   application the ability to order the container as well
   as access to the elements in the container.
   Because it uses dynamic memory it needs to have the Big3.
   John Dolan		Spring 2014	Ohio University
*********************************************************/
#ifndef FBFRIENDS_H
#define FBFRIENDS_H

#include<iostream>
#include<string>
#include<fstream>
#include "friend.h"

class FBFriends{
    public:
	FBFriends() //Constructor
  {
  used = 0;
  current_index = 0;
  capacity = 5;
  data = new Friend[capacity] ;

  }

	//The functions known as the Big 3
	~FBFriends(); //Destructor
	FBFriends(const FBFriends& other); //Copy Constructor
	void operator = (const FBFriends& other); //Overloaded Assignment Operator

	// Functions for the internal aiterator
	void start();
	void advance();
	bool is_item();
	Friend current();
	void remove_current();
	void insert(const Friend& f);
	void attach(const Friend& f);
	void show_all(std::ostream& outs)const;
	void bday_sort();
	Friend find_friend(const std::string& name)const;
	bool is_friend(const Friend& f) const;
	void load(std::istream& ins);
	void save(std::ostream& outs);

    private:
	void resize(); // increases the capacity of the container by 5 (done)
	Friend* data;
	int used;
	int capacity;
	int current_index;
};

#endif
