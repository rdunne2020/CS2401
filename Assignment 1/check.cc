/**********************************************
Rory Dunne
9-15-2017
Checkbook program
rd288116@ohio.edu
***********************************************/

#include "check.h"
using namespace std;
//Constructor
  Check::Check(Date d, string p, int num,double amt){
	checknum = num;
	date = d;
	payto = p;
	amount = amt;
	}

  void Check::set_amount (double& amnt)
  {
    amount = amnt;
  }
  void Check::set_cknum (int& cknum)
  {
    checknum = cknum;
  }
  void Check::set_name (string& payt)
  {
    payto = payt;
  }
  void Check::set_date(Date& dat)
  {
    date = dat;
  }

/*********************************************
write_check takes an istream argument, then it
checks to see if the user is reading in a file
or inputting it themself. Depending on what that
result is it either asks the user for their input
or reads the data in itself.
*********************************************/

    void Check::write_check(istream& ins)
    {
        if (&ins == &cin)
          {

          cout << "Input the check number: " << endl;
          ins >> checknum;

          cout << "Input the date: " << endl;
          ins >> date;

          if (ins.peek() == '\n' || ins.peek() == '\r' ) {ins.ignore();}

          cout << "Input who you are paying the check to: " << endl;
          getline(ins, payto);

          cout << "Input the amount for the check: " << endl;
          ins >> amount;
          }

        else
          {
            
          ins >> checknum;
          ins >> date;
          if (ins.peek() == '\n' || ins.peek() == '\r' ) {ins.ignore();}
          getline (ins, payto);
          ins >> amount;

          }


    	}
/*********************************************
output reads all the inputs received and writes
them to a screen, or a file
*********************************************/
    void Check::output(std::ostream& outs)const{

          outs << checknum << std::endl;
          outs << date << std::endl;
          outs << payto << std::endl;
          outs << amount << std::endl;
          outs << std::endl;
	}

ostream& operator << (ostream& outs, const Check& c){
        c.output(outs);
        return outs;
}

istream& operator >> (istream& ins, Check& c){
        c.write_check(ins);
        return ins;
}
