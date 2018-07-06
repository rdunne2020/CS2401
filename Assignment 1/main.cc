/***************************************************************
  Main.cc written by:	John Dolan		Ohio University EECS	September 2017
**********************************************************************/
/**********************************************
Rory Dunne
9-15-2017
Checkbook program
rd288116@ohio.edu
***********************************************/

#include<iostream>
#include<fstream>
#include<string>
#include "check.h"
#include "checkbook.h"
using namespace std;

/* This function shows the user the menu, asks them to enter their
choice and then returns the integer value of that choice. */
int menu();

int main(){
    Check tmp;
    ifstream ifs;
    ofstream ofs;
    string user,userfile;
    int choice;  // user menu choice
    double depamount;  // amount of a deposit
    int rmnum;      // Check number to be removed from checkbook
    string payto_find; // used in listing all checks to a certain entity

    cout<<"Please enter your user name (No spaces): ";
    cin>>user;
    Checkbook mychecks(user); // A checkbook constructed with this name
    userfile = user + ".txt";
    ifs.open(userfile.c_str());
    if(!ifs.fail())
    { // if no file this is first running for this user
	     mychecks.load_from_file(ifs);
	     ifs.close();
    }
  bool dupe_num = mychecks.dupe_cknum();
  cout << dupe_num << endl;
  while(dupe_num == false)
  {
    cout << "There are duplicate check numbers, re-input name or exit.\n";
    cin >> user;
    userfile = user + ".txt";
    ifs.open(userfile.c_str());
    if(!ifs.fail())
    { // if no file this is first running for this user
	  mychecks.load_from_file(ifs);
    dupe_num = mychecks.dupe_cknum();
	  ifs.close();
    }
  }
    do{
	choice = menu();
	switch(choice){
	    case 1: //DEPOSIT
		cout<<"Please enter amount of the deposit:$";
		cin>>depamount;
		mychecks.deposit(depamount);
		break;
	    case 2://WRITE_CHECK
		mychecks.write_check(cin);
	   	break;
	    case 3://GET BALANCE
		cout<<mychecks.get_balance();
		break;
	    case 4://SEE ALL CHECKS WRITTEN
		mychecks.show_all(cout);
		break;
	    case 5://REMOVE A CHECK BASED ON CHECKNUM
		cout<<"Enter the Check Number of the Check to be removed:";
		cin>>rmnum;
		mychecks.remove(rmnum);
		break;
	    case 6://SORT CHECKS BY THEIR NUMBER
		mychecks.number_sort();
		break;
	    case 7://SORT ALPHABETICALLY BY WHO THEY WERE WRITTEN TO
		mychecks.payto_sort();
		break;
	    case 8://SORT CHECKS BY THE DATE THEY WERE WRITTEN
		mychecks.date_sort();
		break;
	    case 9://FIND ALL CHECKS WRITTEN TO A CERTAIN PAYEE
		while(cin.peek()=='\n' || cin.peek() == '\r')
		    cin.ignore(); // clear out leftover newlines
		getline(cin,payto_find);
		mychecks.show(payto_find);
		break;
	    case 10://FIND THE AVERAGE OF ALL THE CHECKS WRITTEN
		cout<<mychecks.average();
		break;
	    case 0://BACK UP THE CHECKBOOK
		cout<<"Thank you for using the Checkbook program.\n";
		cout<<"All alterations to the checkbook will now be saved.\n";
		break;
	    default:
		cout<<"Not a valid choice. Please choose again. \n";
		break;
	} // bottom of the switch
    } while(choice != 0);

	ofs.open(userfile.c_str());
	if(!ofs.fail()){
	    mychecks.save(ofs);
	    ofs.close();
	}

return 0;
}

int menu(){
    int choice;
    cout << "\nYour Checkbook. Please choose from the following:\n";
    cout << "1) Make a deposit.\n";
    cout << "2) Write a check.\n";
    cout << "3) See the checkbook balance.\n";
    cout << "4) See a listing of all checks written.\n";
    cout << "5) Remove a check which has been cancelled.\n";
    cout << "6) Sort by Check Number.\n";
    cout << "7) Sort Alphabetically by Payto.\n";
    cout << "8) Sort by Date.\n";
    cout << "9) Find all checks written to a certain payee.\n";
    cout << "10) Find the average of all checks written.\n";
    cout << "0) Quit.\n";
    cin >> choice;
    return choice;

}
