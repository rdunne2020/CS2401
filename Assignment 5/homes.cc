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

using namespace std;

void Puma::input(istream& ins)
{
  if (&cin == &ins)
  {
    cout << "Do you live in the underbrush? (1 for yes, 0 for no)" << endl;
    ins >> underbrush;

    if (underbrush == true)
    {
    cout << "How many trees do you want?" << endl;
    ins >> trees;
    }

    else if (underbrush == false)
    {
    cout << "Is it rocky where you live? (1 for yes, 0 for no)" << endl;
    ins >> rocky;

    if (rocky == true)
    {
      cout << "How many rocks do you want?" << endl;
      ins >> rocks;
    }

    }

    if (underbrush == false && rocky == false)
    {
    cout << "Where do you live then?" << endl;
    ins.ignore();
    getline(ins, other_hab);
    }

  }

  else
  {
    ins >> underbrush;

    if (underbrush == true)
    {
    ins >> trees;
    }

    else if (underbrush == false)
    {
    ins >> rocky;
     if (rocky == true)
     {
     ins >> rocks;
     }
    }

    if (underbrush == false && rocky == false)
    {
    ins.ignore();
    getline(ins, other_hab);
    }
  }
}
void Puma::output(ostream& outs)
{
  if (&cout == &outs)
  {
    if (underbrush == true)
    {
      outs << "Your puma lives in the underbrush with "
      << trees << " trees" << endl;
    }

    else if (rocky == true)
    {
    outs << "Your puma lives in a rocky area with "
    << rocks << " rocks" << endl;
    }

    else if (underbrush == false && rocky == false)
    {
      outs << "You live in" << other_hab << endl;
    }
  }
  //////////////////////////For File Output///////////////////
  else
  {
    outs << "1" << endl; //the code

    outs << underbrush << endl;

    if (underbrush == true)
    {
    outs << trees << endl;
    }

    else if (underbrush == false)
    {
    outs << rocky << endl;
     if (rocky == true)
     {
     outs <<  rocks << endl;
     }
    }

    if (underbrush == false && rocky == false)
    {
    outs << other_hab << endl;
    }
  }
}

////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

void Falcon::input(istream& ins)
{
  if(&cin == &ins)
  {
    cout << "Does your falcon live on a building?(Input 1 for yes and 0 for no)";
    ins >> on_building;
      if(on_building == true)
      {
        cout << "What building do you want to live on?";
        ins.ignore();
        getline(ins, what_building);
      }

    cout << "How many eggs do you want in your nest?";
    ins >> eggs;

    cout << "How high up are you building your nest";
    ins >> how_high;
  }
  else
  {
    ins >> on_building;
      if(on_building == true)
      {
        ins.ignore();
        getline(ins, what_building);
      }

    ins >> eggs;

    ins >> how_high;
  }
}
void Falcon::output(ostream& outs)
{
  if(&cout == & outs)
  {
    if(on_building == true)
    {
     outs << "Your falcon lives on the " << what_building << " building ";
     outs << "with " << eggs << " eggs and it is " << how_high
     << " feet tall." << endl;
    }
    else
    {
      outs << "Your falcon lives on a mountain that is " << how_high << " feet tall"
      << " with " << eggs << " eggs." << endl;
    }
  }
  //////////////////////////For File Output///////////////////
  else
  {
    outs << "2" << endl;
    outs << on_building << endl;
      if(on_building == true)
      {
        outs << what_building << endl;
      }

    outs << eggs << endl;

    outs << how_high << endl;
  }
}

//////////////////////////////////////////////////
//////////////////////////////////////////////////

void Anglerfish::input(istream& ins)
{
  if(&cin == &ins)
  {
    cout << "Which ocean do you want to live in?" << endl;
    ins.ignore();
    getline(ins, ocean);

    cout << "Are you male?(Input 1 for yes and 0 for no)" << endl;
    ins >> male;

    if(male == false)
    {
      cout << "How deep are you?" << endl;
      ins >> feet_deep;
      cout << "What's the temperature like?" << endl;
      ins >> temp;
    }
  }
  else
  {
    ins.ignore();
    getline(ins, ocean);

    ins >> male;

    if(male == false)
    {
      ins >> feet_deep;
      ins >> temp;
    }
  }
}
void Anglerfish::output(ostream& outs)
{
  if(&cout == &outs)
  {
    outs << "Your anglerfish lives in the " << ocean << endl;
    if(male == true)
    {
      outs << "Your anglerfish is stuck to a female, you no longer have any choice.";
      cout << endl;
    }
    if(male == false)
    {
      outs << "Your anglerfish lives " << feet_deep << " feet deep and it is "
      << temp << " degrees." << endl;
    }
  }
  //////////////////////////For File Output///////////////////
  else
  {
    outs << "3" << endl;

    outs << ocean << endl;

    outs << male << endl;

    if(male == false)
    {
      outs << feet_deep << endl;
      outs << temp << endl;
    }
  }
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

void Tauntaun::input(istream& ins)
{
  if(&cin == &ins)
  {
      cout << "Do you want to live at the rebel base?(Input 1 for yes and 0 for no)" << endl;
      ins >> rebel_base;

      if(rebel_base == false)
      {
        cout << "How close is the nearest cave to eat?" << endl;
        ins >> caves_near;
        cout << "What is the temperature you want in the cave?" << endl;
        ins >> temperature;
      }
  }
  else
  {
    ins >> rebel_base;

    if(rebel_base == false)
    {
      ins >> caves_near;
      ins >> temperature;
    }
  }
}
void Tauntaun::output(ostream& outs)
{
  if(&cout == &outs)
  {
    if(rebel_base == true)
    {
      outs << "Your tauntaun lives in a rebel base, all your needs will be provided." << endl;
    }
    else
    {
      outs << "Your tauntaun lives in a cave with a temperature of " << temperature
      << " and near " << caves_near << " caves for food." << endl;
    }
  }
/////////////////////////For File Output///////////////////
  else
  {
    outs << "4" << endl;
    outs << rebel_base << endl;

    if(rebel_base == false)
    {
      outs <<  caves_near << endl;
      outs <<  temperature << endl;
    }
  }
}

/////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

void Chinchilla::input(istream& ins)
{
  if(&cin == &ins)
  {
    cout << "Do you want to live in a herd?(Input 1 for yes and 0 for no)" << endl;
    ins >> in_herd;

    cout << "Do you want to live in a burrow(Input 1 for yes and 0 for no)"
    << endl;
    ins >> burrow;

    cout << "How many rocks do you want to live between" << endl;
    ins >> rocks;

    if(burrow == true)
    {
    cout << "What is your burrow like?" << endl;
    ins.ignore();
    getline(ins, desc_burrow);
    }
  }
  else
  {
    ins >> in_herd;

    ins >> burrow;

    ins >> rocks;
    if(burrow == true)
    {
    ins.ignore();
    getline(ins, desc_burrow);
    }
  }
}
void Chinchilla::output(ostream& outs)
{
  if(&cout == &outs)
  {
    if(in_herd == true)
    {
      outs << "Your chinchilla is part of a herd ";
      if(burrow == true)
      {
        outs << "and your chinchilla lives in a " << desc_burrow << " burrow with "
        << rocks << " rocks surrounding it." << endl;
      }
      else if(burrow == false)
      {
        outs << "You live in a crevice with " << rocks
        << " rocks surrounding it." << endl;
      }
    }
    else if(in_herd == false)
    {
      outs << "Your chinchilla lives alone ";
      if(burrow == true)
      {
        outs << "and your chinchilla live in a " << desc_burrow << " burrow with "
        << rocks << " rocks surrounding it." << endl;
      }
      else if(burrow == false)
      {
        outs << "Your chinchilla lives in a crevice with " << rocks
        << " rocks surrounding it." << endl;
      }
    }
  }
  //////////////////////////For File Output///////////////////
  else
  {
      outs << "5" << endl;
      outs << in_herd << endl;

      outs << burrow << endl;

      outs << rocks << endl;
      if(burrow == true)
      {
      outs << desc_burrow << endl;
      }
  }
}
