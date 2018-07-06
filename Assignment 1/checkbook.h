/**********************************************
Rory Dunne
9-15-2017
Checkbook program
rd288116@ohio.edu
***********************************************/

#ifndef CHECKBOOK
#define CHECKBOOK

#include "check.h"
#include "date.h"
#include<string>

class Checkbook{
  public:

	Checkbook(std::string owner = "No One", double bal = 0,  int ind = 0)
  {
    balance = bal;
    index = ind;
    user = owner;
  }
  void load_from_file(std::istream& ins);
	void deposit(double& a);
	void write_check(std::istream& ins);
	double get_balance()const;
	void show_all(std::ostream& outs)const;
	void remove(int n);
	void number_sort();
	void payto_sort();
	void date_sort();
	void show(const std::string& p)const;
	double average()const;
	void save(std::ostream& outs)const;
  bool dupe_cknum();

  private:
  static const size_t SIZE = 200;
  Check book[SIZE];
  std::string user;
  size_t index; //keeps track of how full the array is.
  double balance; //keeps track of the amount in the checking acc.

};

#endif
