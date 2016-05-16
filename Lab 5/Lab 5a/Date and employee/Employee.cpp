// Lab 5a, Employee.cpp
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;

#include "Employee.h"

#include "Date.h"

Employee::Employee(const string &first, const string &last, const Date &dateOfBirth, const Date &dateOfHire): firstName(first),lastName(last),birthDate(dateOfBirth),hireDate(dateOfHire)
{
  cout << "Employee object constructor: " << firstName << ' ' << lastName << endl;
}

void Employee::print() const
{
  cout << lastName << ", " << firstName << "  Hired: ";
  hireDate.print();
  cout << " Birthday: ";
  birthDate.print();
  cout << endl;
}

Employee::~Employee()
{
  cout << "Employee object destructor: " << lastName << ", " << firstName << endl;
}

