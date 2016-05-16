// Lab 5a, TestEmployee.cpp
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;

#include "Date.h"

#include "Employee.h"

int main()
{
  Date birth(11,23,1995);
  Date hire(02, 21, 2015);
  Employee a("Sohaib","Syed",birth,hire);

  //test the obecjt
  cout << "Testing the print Function. It should printout the info of the canidate and his hire date"<<endl;
  a.print();
  cout << endl <<endl;
  {
	//copying the employee object
	const Employee copy = a;

	cout<<"Testing the copy of object A that was just printed. Results should be the same"<<endl;
	copy.print();
	cout << endl;
  }

}
