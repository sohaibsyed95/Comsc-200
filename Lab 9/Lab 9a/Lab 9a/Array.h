// Lab 9a, Array Class Definition with overloaded operators, Array.h
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using std::istream;
using std::ostream;

class Array
{
  friend ostream &operator<<(ostream &, const Array &);
  friend istream &operator>>(istream &, Array &);

  public:
	Array(int = 10);  //default constructor
	Array(const Array &);  //copy constructor
	~Array();  // destructor
	int getSize() const;//return size
    const Array &operator=( const Array &);  //assignment operator
	bool operator==(const Array& ) const;  //  equality operator
	//inequality operator; returns oposite of == operator
	bool operator !=(const Array &right) const
	{
      return !(*this ==right);  // invokes Array::operator==
	}//end function operator !=
	//subscript operator for non const objects returns modifiable lvalue
    int &operator[](int);
    //subscript operator for const objects return rvalue
    int operator[](int) const;

  private:
    int size; // pointer-based array size
    int *ptr;  // pointer to first element of pointer based array
};  //end class Array

#endif
