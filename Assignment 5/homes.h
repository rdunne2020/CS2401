/***********************************************
Rory Dunne
Project 5, Animal Homes
11/18/2017
CS2401
************************************************/
#ifndef HOMES_H
#define HOMES_H
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

class Homes{
public:

  virtual void input(istream& ins) = 0;
  virtual void output(ostream& outs) = 0;

private:

protected:

};

class Puma:public Homes{
public:
  Puma(){}
  void input(istream& ins);
  void output(ostream& outs);

private:
  bool underbrush; //pumas like a rocky area with underbrush
  bool rocky; //if they live in the rocks
  string other_hab; //if they don't live in an area with both of these
  int trees; //how many trees for the puma to hide behind
  int rocks;//how many rocks to hide behind
protected:
};

class Falcon:public Homes{
public:
  Falcon(){}
  void input(istream& ins);
  void output(ostream& outs);

private:
  bool on_building; //sometimes they nest on buildings
  string what_building; //what kind of building are they nesting on
  int eggs; //number of eggs in the nest
  int how_high; //for an overview and ability to dive on prey
protected:
};

class Anglerfish:public Homes{
public:
  Anglerfish(){}
  void input(istream& ins);
  void output(ostream& outs);

private:
  string ocean; //which ocean does it want to live in
  int feet_deep; //how many feet deep it wants to be (at least a mile)
  bool male; //if it's male it will latch to a female for the rest of its life
  double temp; //how cold is it down there
protected:
};

class Tauntaun:public Homes{
public:
  Tauntaun(){}
  void input(istream& ins);
  void output(ostream& outs);

private:
  bool rebel_base; //does it want to live at the rebel base
  double temperature; //they live in caves near the core of Hoth to keep the temperature up
  int caves_near; //they feed off of lichens from caves so there must be caves somewhat close to their home
protected:
};

class Chinchilla:public Homes{
public:
  Chinchilla(){}
  void input(istream& ins);
  void output(ostream& outs);

private:
  bool in_herd; //does it want to live with a herd
  bool burrow; //does it want to live in a burrow or crevice
  int rocks; //how many rocks it wants to live in between
  string desc_burrow; //desribe your burrow
protected:
};
#endif
