// Lab 8b, ElevatorSimulation1, Floor.cpp
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include "Array.h"

#include <sstream>
using std::istringstream;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
	istringstream sin;

	sin.str("1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17");

	int val;
	sin >> val;
	cout << val<< '\n';

	cout << "Sin printed out and it: ";
	cout << sin.str() << '\n';
	cout << endl;
}
