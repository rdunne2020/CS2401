/***********************************************
Rory Dunne
Project 5, Animal Homes
11/18/2017
CS2401
************************************************/
#include "homes.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <list>
using namespace std;

int main()
{
  ifstream ins;
  ofstream outs;
  string username;
  int code;
  char animal;

  cout << "What is your name?" << endl;
  getline(cin, username);
  username += ".txt";

  ins.open(username.c_str());
    if(ins.fail())
    {
      cerr << "This name is not in our records" << endl;
    }

  Homes* tmp;
  list <Homes*> homes;
  /***********************************************
   For Loading in the file
  ************************************************/
  if(!ins.fail())
  {
    while(ins >> code)
    {
      switch(code)
      {
        case 1:
        {
        tmp = new Puma;
        tmp -> input(ins);
        homes.push_back(tmp);
        }
        break;

        case 2:
        {
        tmp = new Falcon;
        tmp -> input(ins);
        homes.push_back(tmp);
        }
        break;

        case 3:
        {
        tmp = new Anglerfish;
        tmp -> input(ins);
        homes.push_back(tmp);
        }
        break;

        case 4:
        {
        tmp = new Tauntaun;
        tmp -> input(ins);
        homes.push_back(tmp);
        }
        break;

        case 5:
        {
        tmp = new Chinchilla;
        tmp -> input(ins);
        homes.push_back(tmp);
        }
        break;

        default: ins.ignore();
      }
    }
  }

  cout << "Input the animal you want to make a home for. Press O to output";
  cin >> animal;
  /***********************************************
  For Inputting animals manually
  ************************************************/
while(animal != 'Z')
{
 switch(animal)
  {
    case 'p': //for allowing both upper and lowecase inputs
    case 'P':
    {
    tmp = new Puma;
    tmp -> input(cin);
    homes.push_back(tmp);
    }
    break;

    case 'f':
    case 'F':
    {
    tmp = new Falcon;
    tmp -> input(cin);
    homes.push_back(tmp);
    }
    break;

    case 'a':
    case 'A':
    {
    tmp = new Anglerfish;
    tmp -> input(cin);
    homes.push_back(tmp);
    }
    break;

    case 't':
    case 'T':
    {
    tmp = new Tauntaun;
    tmp -> input(cin);
    homes.push_back(tmp);
    }
    break;

    case 'c':
    case 'C':
    {
    tmp = new Chinchilla;
    tmp -> input(cin);
    homes.push_back(tmp);
    }
    break;

    case 'O':
    {
    list <Homes*>::iterator it;
    it = homes.begin();
      while(it != homes.end())
      {
        (*it)->output(cout);
        ++it;
      }
    }
    break;

    default: cout << "That's not an animal." << endl;
  }
  cout << "Enter antoher animal. Enter 'Z' to exit" << endl;
  cin >> animal;
}
/***********************************************
Default output to a file when closing
************************************************/
outs.open(username.c_str());
list <Homes*>::iterator it;
it = homes.begin();
  while(it != homes.end())
  {
    (*it)->output(outs);
    ++it;
  }

  return 0;
}
