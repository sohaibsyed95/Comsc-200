// Lab 5a, Employee.h
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using std::string;

#include "Date.h"

class Employee
{
  public:
    Employee( const string &, const string &, const Date &, const Date &);
    void print() const;
    ~Employee();
  private:
    string firstName;
    string lastName;
    const Date birthDate;
    const Date hireDate;
};

#endif // EMPLOYEE_H_INCLUDED
