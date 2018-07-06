#include "friend.h"

using namespace std;

bool Friend::operator == (const Friend& other) const
{
  return name == other.get_name() && bday == other.get_bday();
}

bool Friend::operator != (const Friend& other) const
{
  return name != other.get_name() || bday != other.get_bday();
}

void Friend::input(istream& ins)
{
  if (&ins == &cin)
  {
    cout << "Input your friend's name: " << endl;

    if(ins.peek() == '\r' || ins.peek() == '\n')
    {
      ins.ignore();
    }

    getline (ins, name);

    cout << "Input your friend's birthday: " << endl;
    ins >> bday;
  }

  else
  {
    if(ins.peek() == '\r' || ins.peek() == '\n')
    {
      ins.ignore();
    }

    getline(ins, name);
    ins >> bday;
  }
}

void Friend::output (ostream& outs)const
{
  outs << name << endl;
  outs << bday << endl;
}

istream& operator>> (istream& ins, Friend& f)
{
  f.input(ins);
  return ins;
}

ostream& operator<< (ostream& outs, const Friend& f)
{
  f.output(outs);
  return outs;
}
