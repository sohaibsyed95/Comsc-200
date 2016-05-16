// Lab 3a, Test.cpp
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include "SalesPerson.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::ios;

int main()
{
  //Sohaib Syed, Test.cpp
  cout << "Lab 3a, Test.cpp\n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: CodeBlocks\n";
  cout << "Compiler(s) used: CodeBlocks\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  SalesPerson salesPerson;

   //Prompts user to enter certain infp
  cout<< "Please enter the information for 12 months of sales" << endl;
  cout<< "Use this information: 700 500 300 200 100 600 800 900 400 200 300 100"<<endl;
  salesPerson.getSalesFromUser();

  cout<< "The expected total is $5100" << endl;
  salesPerson.printAnnualSales();

  //Changes some values and then prints ita gain
  salesPerson.setSales(1,900);
  salesPerson.setSales(2,700);
  cout<<"The values for months 1 and 2 have been increased by 200 the new expected value is $5500"<<endl;
  cout<<"The new total is: " <<endl;
  salesPerson.printAnnualSales();
  // object copy testing, with assignment UPON declaration
  {
    //Prints a copy
    SalesPerson copy = salesPerson;
    cout<< "The values have been copied and the expected copy value is: ";
    copy.printAnnualSales();
    cout<<endl;
  }

  // object copy testing, with assignment AFTER declaration
  {
    SalesPerson copy; copy = salesPerson;
    //...use getters to confirm that copy's contents match salesPerson's
    cout<<"The values have been copied and the expected copy value is: ";
    copy.printAnnualSales();
    cout<<endl;

  }
}
