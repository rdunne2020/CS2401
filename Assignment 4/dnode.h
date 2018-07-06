/*******************************************
Rory Dunne
10/29/17
CS2401
Node Class
********************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#ifndef DNODE_H
#define DNODE_H

template <class T>
class Dnode{
 public:
   Dnode(T d, Dnode* p = NULL, Dnode* n = NULL)
   {
    datafield = d;
    previousptr = p;
    nextptr = n;
   }

  T data() {return datafield;}

 	Dnode *previous() {return previousptr;}

 	Dnode *next()  {return nextptr;}

 	void set_data(T d){datafield = d;}

 	void set_previous(Dnode * p){previousptr = p;}

 	void set_next(Dnode *n) {nextptr = n;}


 private:
  T datafield;
 	Dnode *nextptr;
 	Dnode *previousptr;

};

#endif
