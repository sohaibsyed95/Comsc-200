// Lab 4a, Test.cpp
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include "Time.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::ios;

int main()
{
  Time t(12, 45, 30);

  //prints out the values
  cout << "getSecond : " << t.getSecond() << endl;
  cout << "getMin : " << t.getMinute() << endl;
  cout << "getHour : " << t.getHour() << endl<<endl;

  //prints out the times
  cout << "The current time is according to standard : ";
  t.printStandard();
  cout<<endl<<endl;

  cout << "The current time in universal is : ";
  t.printUniversal();
  cout << endl<<endl;

  //changes the times and prints the values
  cout << "Changing hours to 10, min to 10, sec to 10\n\n";
  t.setHour(10);
  t.setMinute(10);
  t.setSecond(10);

  cout << "New Values are " <<endl;
  cout << "getSecond : " << t.getSecond() << endl;
  cout << "getMin : " << t.getMinute() << endl;
  cout << "getHour : " << t.getHour() << endl << endl;

  cout <<"\nDoes a copy upon declaration and prints out info"<<endl;
  const Time copy = t;
  copy.printStandard();
  cout<<endl;
  copy.printUniversal();

  cout<<"\n\nDoes a copy after declaration"<<endl;
  Time copy2;
  copy2 = t;
  copy2.printStandard();
  cout<<endl;
  copy2.printUniversal();
  cout <<endl;
}
