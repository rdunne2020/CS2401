/*******************************************
Rory Dunne
10/29/17
CS2401
Template list class declaration
********************************************/
#ifndef DLIST_H
#define DLIST_H
#include "dnode.h"
#include "node_iterator.h"
#include <string>
#include <cstdlib>

template <class T>
class dlist{
  public:

    dlist()
    {
      head = NULL;
      tail = NULL;
      listcount = 0;
    }

    /////////////////BIG3/////////////////////////
    dlist(const T& other); //Copy Constructor
    dlist operator = (const T& other); //Overloaded Assignment Operator
    ~dlist(); //Destructor
    /////////////////BIG3/////////////////////////

    //////////////////////Iterator////////////////
    typedef node_iterator<T> iterator;
    iterator begin(){return iterator(head);}
    iterator end(){return iterator();}
    iterator r_begin(){return iterator(tail);}
    iterator r_end(){return iterator();}
    void remove(iterator it);
    void insert_before(iterator& it, T item);
    void insert_after(iterator& it, T item);
    //////////////////////Iterator////////////////

    void front_insert(T item);
    void front_remove();
    void rear_insert(T item);
    void rear_remove();
    void show();
    void reverse_show();
    int size(){return listcount;}

  private:
    Dnode<T>* head;
    Dnode<T>* tail;
    int listcount;
};

#include "dlist.template"
#endif
