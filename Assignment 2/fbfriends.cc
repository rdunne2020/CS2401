/************************************
Name: Rory Dunne
Project: Facebook Class
Date: 9/23/2016
Question on lines 17-20
*************************************/
#include "fbfriends.h"

using namespace std;

/************************************
BIG 3
************************************/

FBFriends::~FBFriends() //Destructor
{
  delete[] data; //Should be deleteing (deallocating) the allocated memory from data = new Friend[other];
}
FBFriends::FBFriends(const FBFriends& other) //Copy Constructor
{

  data = new Friend[other.capacity]; //data is pointing at allocated memory for a Friend array with other.capacity size
  used = other.used;
  capacity = other.capacity;
  current_index = other.current_index;

  copy(other.data, other.data + used, data); //when you copy all this to data, you're just changing what data (data gets changed in the line above) points at?
}
void FBFriends::operator = (const FBFriends& other) //Overloaded Assignment Operator
{
  cout << "You are calling on the overloaded assignment operator: " << endl;
  if (this == &other)
  {
    return;
  }
  else if (capacity != other.capacity)
  {
  delete[] data;

  data = new Friend[other.capacity]; // data is pointing at allocated memory for a Friend array with other.capacity size
  capacity = other.capacity;
  current_index = other.current_index;
  }
  used = other.used;
  copy(other.data, other.data + used, data);  //when you copy all this to data, you're just changing what data (data gets changed in the line above) points at?
}
/************************************
BIG 3 ^
************************************/

	// Functions for the internal iterator
	void FBFriends::start() //Starts everything, current should be called next to see where you are in the sequence.
  //sets current to the first input
  {
    current_index = 0;
  }

	void FBFriends::advance() //makes the iterator look at the next item in array
  {
    current_index++;
  }

	bool FBFriends::is_item()
  {
    return (current_index < used);
  }

	Friend FBFriends::current() //Returns the current number in the sequence
  {
      return data[current_index]; //Is this proper syntax for returning a pointer to an array?
  }

	void FBFriends::remove_current() //Removes the current number in the sequence by shifting everything after the current to the left, overwriting it
    //by doing used --
  {
    for (int i = current_index; i < used; i++)
    {
      data[i] = data[i+1];
    }
    used--;
  }

	void FBFriends::insert(const Friend& f) //why can't I declare an istream? Needs to check to see if there's a current friend in the array
                              //then it moves everything before current over and inserts the friend
  {
    if(used == capacity)//this will resize
    {
      resize();
    }

    for (int i = used; i >= current_index; i--)
    {
      data[i] = data[i-1];
    }
    used++;
    data[current_index] = f;
  }

	void FBFriends::attach(const Friend& f)
  {
    if(used == capacity)
    {
      resize();
    }

    for (int i = used; i > current_index; i--)
    {
      data[i] = data[i-1];
    }
    used++;
    data[current_index] = f;

  }
	void FBFriends::show_all(std::ostream& outs)const //question here
  {
    cout << "Your Friends: " << endl; //test
    //cout << data[used] << " test" << endl;
    for (int i = 0; i < used; i++)
    {
      outs << data[i];
    }
  }

	void FBFriends::bday_sort()
  {
     Friend tfriend; //temporary freind object for swapping
     for(int i = 0; i < used; i++)
     {
       for(int j = 0; j < used - i - 1; ++j)
       {
         if(data[j].get_bday() < data[j+1].get_bday())
         {
           tfriend = data[j];
           data[j] = data[j+1];
           data[j+1] = tfriend;
         }
       }
     }
   }

	Friend FBFriends::find_friend(const std::string& name)const //has to return something like a default friend
  {
    for (int i = 0; i < used; i++)
    {
      if (data[i].get_name() == name)
      {
        return data[i];
      }
    }
    Friend tmp; //returns default friend
    return tmp;
  }
	bool FBFriends::is_friend(const Friend& f) const
  {
    for (int i = 0; i < used; i++)
    {
      if(data[i] == f)
      {
        return true;
      }
    }
    return false;
  }

	void FBFriends::load(std::istream& ins) //terminating from a bad month thrown.
  {
    Friend tmp;
    while (ins.peek() == '\r' || ins.peek() == '\n') {ins.ignore();} //checking to make sure it's not skipping anything
    ins >> tmp; //start of sentinel loop
    while (!ins.eof())
    {
    if (used == capacity){resize();} //eventually data runs out of room and tries to make itself point at tmp with memory it doesn't have

    data[used] = tmp;
    used++;

    while (ins.peek() == '\r' || ins.peek() == '\n') {ins.ignore();} //checking to make sure it's not skipping anything
    ins >> tmp;
    }

  }

	void FBFriends::save(std::ostream& outs)
  {
    for (int i = 0; i < used; i ++)
    {
      outs << data[i];
    }
  }

  void FBFriends::resize()
  {
    Friend* tmp;
    tmp = new Friend[capacity+5];

      for (int i = 0; i < capacity; i++)
        {
        tmp[i] = data[i];
        }

      capacity += 5;
      delete[] data;
      data = tmp;
  }
