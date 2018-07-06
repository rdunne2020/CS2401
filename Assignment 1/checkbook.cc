/**********************************************
Rory Dunne
9-15-2017
Checkbook program
rd288116@ohio.edu
***********************************************/

#include <cstdlib>
#include "checkbook.h"
using namespace std;

   void Checkbook::load_from_file(istream& ins)
   {

     ins >> balance;

     while (!ins.eof())
     {
       book[index].write_check(ins);
       index++;
       while (ins.peek() == '\n' || ins.peek() == '\r' ) {ins.ignore();}
     }

   }

   void Checkbook::deposit(double& a)
   {
     if (a < 0)
     {
       cout << "Invalid input." << endl;
       exit(EXIT_FAILURE);
     }
      balance+=a;


   }

   void Checkbook::write_check(istream& ins) //works properly now
   {

          book[index].write_check(ins);
          // for(int i = 0; i < index; i++)
          // {
          //   cout << "Index: " << index << endl;
          //   cout << "book[index]: " << book[index].get_num() << endl;
          //   cout << "book[i]: " << book[i].get_num() << endl;
          // }
          cout << book[5].get_num() << endl;
          cout << book[6].get_num() << endl;
          cout << book[7].get_num() << endl;
          cout << book[8].get_num() << endl;
          bool num_test = dupe_cknum();
          cout << num_test << endl;
          while(num_test == false)
          {
            int new_cknum = 0;
            cout << "Cannot have duplicate check numbers, please re-input: ";
            cin >> new_cknum;
            book[index].set_cknum(new_cknum);
            num_test = dupe_cknum();
          }
          balance -= book[index].get_amount();
          index++;
   }

   double Checkbook::get_balance()const
   {
    return balance;
    cout << "\n";
   }

   void Checkbook::show_all(std::ostream& outs)const
   {
     while(index < 1)
     {
       cout << "You don't have any checks written yet" << endl;
       break;
     }
     while (index > 0)
     {
       for (int i = 0; i < index; i++) //this needs to go from 0 to index ijit
       {
         book[i].output(outs);
       }
       break;
     }
   }

   void Checkbook::remove(int n)//now it works
   {
     bool in_list;
     for (int j = 0; j < index; j++)
     {
       if(book[j].get_num() == n)
       {
         cout << "Removing...\n";
         in_list = true;
         break;
       }
       else
       {
         in_list = false;
       }
     }

     for (int i = 0; i < index; i++)
     {
       if(book[i].get_num() == n)
       {
          while(i < index)
          {
          book[i] = book[i+1]; //changed book[n] to book[i]
          ++i;
          }
       }
     }
     if(in_list == true)
     index--;
     else
     cout <<"Number not in list, or list is empty\n";
   }

   void Checkbook::number_sort()
   {
     Check tcheck; //temporary check for swapping

      for(int i = 0; i < index-1; i++)
      {
        cout << book[i].get_num() << ": book[i]" <<  endl;
        for (int j = 0; j < index-1; j++)
        {
          //cout << book[j].get_num() << ": book[j]" << endl;
          if (book[i].get_num() > book[j].get_num())
          {
            tcheck = book[i];
            book[i] = book[j];
            book[j] = tcheck;
          }
        }
      }
   }

   void Checkbook::payto_sort()
   {
    Check tcheck; //temporary check for swapping
    for(size_t i = 0; i < index - 1; ++i)
    {
      for(size_t j = 0; j < index - i - 1; ++j)
      {
        if (book[j].get_payto() < book[j+1].get_payto())
        {
          tcheck = book[j];
          book[j] = book[j+1];
          book[j+1] = tcheck;
        }
      }
    }
   }

   void Checkbook::date_sort()
   {
     Check tcheck; //temporary check for swapping
      for (size_t i = 0; i < index - 1; ++i)
      {
        for (size_t j = 0; j < index - i - 1; ++j)
        {
          if(book[j].get_date().get_year() < book[j+1].get_date().get_year() )
          {
          tcheck = book[j];
          book[j] = book[j+1];
          book[j+1] = tcheck;
          }
          else if(book[j].get_date().get_year() == book[j+1].get_date().get_year())
            {
              if(book[j].get_date().get_month() < book[j+1].get_date().get_year())
              {
                tcheck = book[j];
                book[j] = book[j+1];
                book[j+1] = tcheck;
              }
                else if(book[j].get_date().get_month() == book[j+1].get_date().get_month())
                {
                    if (book[j].get_date().get_day() < book[j+1].get_date().get_day())
                    {
                      tcheck = book[j];
                      book[j] = book[j+1];
                      book[j+1] = tcheck;
                    }
                }
            }
        }
      }
   }

   void Checkbook::show(const std::string& p)const
   {
     for(int i = 0; i < index; ++i)
     {
       if(book[i].get_payto() == p)
       {
         cout << book[i];
       }
     }
   }

   double Checkbook::average()const //works
   {
    double average_num;
    for (int i = 0; i < index; i++)
    {
      average_num += book[i].get_amount();
    }
    average_num/=index;
    return average_num;
   }

   void Checkbook::save(std::ostream& outs)const
   {
     for (size_t i = 0; i < index; ++i)
     book[i].output(outs);
   }

   bool Checkbook::dupe_cknum() //need a second for adding new ones as the array
                                //increases when you add it and index-1 won't reach it
   {
     for(int i = 0; i < index-1; i++)//needs to be index -1 or it will
                                     //be book[0] because all the other
                                    //blank spaces in book are 0's
     {
       if(book[index-1].get_num()==book[i].get_num())
       {
         return false;
       }
     }
     return true;
   }
